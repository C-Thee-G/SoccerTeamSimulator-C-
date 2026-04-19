#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include "FormationStrategy.h"
#include "PlayerRepository.h"
#include <vector>
#include <string>

class Team {
private:
    std::string teamName;
    std::string managerName;
    PlayerRepository<Player> players;
    FormationStrategy* currentStrategy;
    static const int MAX_PLAYERS = 11;

public:
    Team(std::string name, std::string manager);
    ~Team();

    // Standard Getters
    std::string getTeamName() const { return teamName; }
    std::string getManagerName() const { return managerName; }

    // --- SIMULATION ACCESSORS ---
    std::vector<Player*> getAllPlayers();      // Declaration
    FormationStrategy* getStrategy() const;   // Declaration

    // --- EXISTING METHODS ---
    void addPlayer(Player* p);
    void removePlayer(int number);
    void displayTeam() const;
    void setStrategy(FormationStrategy* s);
    void applyStrategy() const;
    int getTotalSkill() const;
    double getAverageSkill() const;
    int getPlayerCount() const { return players.getSize(); }
    bool isFull() const { return players.getSize() >= MAX_PLAYERS; }

    Player* findPlayerByName(const std::string& name);
    Player* findPlayerByNumber(int number);
    void sortPlayersBySkill();
    void sortPlayersByNumber();

    bool canFormTeam() const;
    std::string getRecommendedFormation() const;
};

#endif