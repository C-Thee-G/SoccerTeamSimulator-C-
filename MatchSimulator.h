#ifndef MATCHSIMULATOR_H
#define MATCHSIMULATOR_H

#include "Team.h"
#include <random>
#include <ctime>
#include <vector>
#include <thread> // For sleep/pausing the simulation
#include <chrono>

class MatchSimulator {
private:
    Team& homeTeam;
    Team& awayTeam;

public:
    MatchSimulator(Team& home, Team& away);

    struct MatchResult {
        int homeScore;
        int awayScore;
        std::string winner;
        std::string summary;
    };

    // --- NEW SIMULATION METHODS ---

    // This will handle the "Dots" moving into position
    void runFormationSimulation();

    // Helper to assign target coordinates to a team's players
    void assignFormationPositions(Team& team, bool isHomeSide);

    // --- EXISTING METHODS ---
    MatchResult simulateMatch();
    void displayMatchResult(const MatchResult& result);

private:
    int calculateTeamStrength(Team& team);
    int generateGoals(int strength, int opponentStrength, bool isHome);
};

#endif