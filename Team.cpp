#include "Team.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Color codes for console output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

Team::Team(string name, string manager)
    : teamName(name), managerName(manager), currentStrategy(nullptr) {
}

Team::~Team() {
    // Note: Players are deleted in main or Repository to avoid double deletion
}

void Team::addPlayer(Player* p) {
    if (players.getSize() >= MAX_PLAYERS) {
        throw runtime_error("Team is full! Maximum 11 players allowed.");
    }
    for (int i = 0; i < players.getSize(); i++) {
        if (players.get(i)->getNumber() == p->getNumber()) {
            throw runtime_error("Player with jersey number " + to_string(p->getNumber()) + " already exists!");
        }
    }
    players.add(p);
}

void Team::removePlayer(int number) {
    int index = -1;
    for (int i = 0; i < players.getSize(); i++) {
        if (players.get(i)->getNumber() == number) {
            index = i;
            break;
        }
    }
    if (index == -1) throw runtime_error("Player not found!");
    players.remove(index);
}

void Team::displayTeam() const {
    cout << "\n========================================";
    cout << "\nTEAM: " << teamName << " | MANAGER: " << managerName;
    cout << "\n========================================";
    if (players.getSize() == 0) {
        cout << RED << "\n  No players in team yet." << RESET << endl;
    }
    else {
        vector<Player*> allPlayers = players.getAll();
        for (Player* p : allPlayers) p->display();
    }
    cout << "\nAverage Skill: " << fixed << setprecision(1) << getAverageSkill();
    cout << "\n========================================\n";
}

void Team::setStrategy(FormationStrategy* s) {
    currentStrategy = s;
}

void Team::applyStrategy() const {
    if (currentStrategy == nullptr) throw runtime_error("No strategy set!");
    currentStrategy->apply();
}

int Team::getTotalSkill() const {
    int total = 0;
    vector<Player*> allPlayers = players.getAll();
    for (Player* p : allPlayers) total += p->getSkill();
    return total;
}

double Team::getAverageSkill() const {
    if (players.getSize() == 0) return 0.0;
    return static_cast<double>(getTotalSkill()) / players.getSize();
}

// --- SEARCH & SORT ---
Player* Team::findPlayerByName(const string& name) {
    int index = players.linearSearchByName(name);
    return (index != -1) ? players.get(index) : nullptr;
}

Player* Team::findPlayerByNumber(int number) {
    players.quickSortByNumber(0, players.getSize() - 1);
    int index = players.binarySearchByNumber(number);
    return (index != -1) ? players.get(index) : nullptr;
}

void Team::sortPlayersBySkill() { players.bubbleSortBySkill(); }
void Team::sortPlayersByNumber() { players.quickSortByNumber(0, players.getSize() - 1); }

bool Team::canFormTeam() const { return players.getSize() == MAX_PLAYERS; }

string Team::getRecommendedFormation() const {
    int gk = 0, df = 0, mf = 0, st = 0;
    vector<Player*> allPlayers = players.getAll();
    for (Player* p : allPlayers) {
        string role = p->getRole();
        if (role == "Goalkeeper") gk++;
        else if (role == "Defender") df++;
        else if (role == "Midfielder") mf++;
        else if (role == "Striker") st++;
    }
    if (df >= 4 && mf >= 4 && st >= 2) return "4-4-2";
    if (df >= 4 && mf >= 3 && st >= 3) return "4-3-3";
    if (df >= 3 && mf >= 5 && st >= 2) return "3-5-2";
    return "Balanced (4-4-2 recommended)";
}

// --- SIMULATION ACCESSORS (The bridge to MatchSimulator) ---

vector<Player*> Team::getAllPlayers() {
    return players.getAll();
}

FormationStrategy* Team::getStrategy() const {
    return currentStrategy;
}