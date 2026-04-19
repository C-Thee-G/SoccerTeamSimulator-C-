#include "MatchSimulator.h"
#include <iostream>
#include <thread>
#include <chrono>

MatchSimulator::MatchSimulator(Team& home, Team& away)
    : homeTeam(home), awayTeam(away) {
}

void MatchSimulator::assignFormationPositions(Team& team, bool isHomeSide) {
    auto players = team.getAllPlayers();
    auto strategy = team.getStrategy();

    if (!strategy || players.empty()) return;

    std::vector<Position> coords = strategy->getPositions();

    for (size_t i = 0; i < players.size() && i < coords.size(); ++i) {
        double finalX = coords[i].x;
        double finalY = coords[i].y;

        // Flip X-axis for the away team so they face the home team
        if (!isHomeSide) {
            finalX = 100 - finalX;
        }
        players[i]->setTargetPosition(finalX, finalY);
    }
}

void MatchSimulator::runFormationSimulation() {
    assignFormationPositions(homeTeam, true);
    assignFormationPositions(awayTeam, false);

    std::cout << "\n[SIMULATION] Players moving into tactical positions...\n";

    // Run for 50 frames to let the "dots" reach their targets
    for (int frame = 0; frame < 50; ++frame) {
        for (auto p : homeTeam.getAllPlayers()) p->update();
        for (auto p : awayTeam.getAllPlayers()) p->update();

        // Simple visual feedback
        if (frame % 5 == 0) std::cout << ">" << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    std::cout << " Ready!\n";
}

MatchSimulator::MatchResult MatchSimulator::simulateMatch() {
    MatchResult result;
    int homeStrength = calculateTeamStrength(homeTeam);
    int awayStrength = calculateTeamStrength(awayTeam);

    // Basic goal generation logic
    result.homeScore = generateGoals(homeStrength, awayStrength, true);
    result.awayScore = generateGoals(awayStrength, homeStrength, false);

    if (result.homeScore > result.awayScore) result.winner = homeTeam.getTeamName();
    else if (result.awayScore > result.homeScore) result.winner = awayTeam.getTeamName();
    else result.winner = "Draw";

    result.summary = "Match concluded between " + homeTeam.getTeamName() + " and " + awayTeam.getTeamName();
    return result;
}

void MatchSimulator::displayMatchResult(const MatchResult& result) {
    std::cout << "\nFinal Score: " << homeTeam.getTeamName() << " " << result.homeScore
        << " - " << result.awayScore << " " << awayTeam.getTeamName() << "\n";
}

int MatchSimulator::calculateTeamStrength(Team& team) {
    return team.getTotalSkill();
}

int MatchSimulator::generateGoals(int strength, int opponentStrength, bool isHome) {
    int maxGoals = (strength / 100) + (isHome ? 1 : 0);
    return rand() % (maxGoals + 1);
}