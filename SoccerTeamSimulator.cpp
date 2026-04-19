#include "Player.h"
#include "Team.h"
#include "FormationStrategy.h"
#include "MatchSimulator.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Color codes for console output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

// Structure to hold team info for display
struct TeamInfo {
    Team* team;
    string managerName;
};

// Global storage for multiple teams
map<string, Team*> teams;
string currentTeamName;

// Function prototypes
void displayHeader();
void displayMainMenu();
void displayTeamManagementMenu();
void addTeamMenu();
void selectTeamMenu();
void addPlayerToTeam();
void displayCurrentTeamMenu();
void applyStrategyToTeam();
void sortTeamPlayers();
void searchTeamPlayers();
void simulateMatchBetweenTeams();
void listAllTeams();
void clearInputBuffer();
void createPrePopulatedTeams(); // NEW FUNCTION PROTOTYPE

int main() {
    displayHeader();

    // Create 3 pre-populated teams
    createPrePopulatedTeams();

    int choice;

    do {
        displayMainMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            cout << RED << "ERROR: Invalid input. Please enter a number (1-5)." << RESET << endl;
            continue;
        }

        try {
            switch (choice) {
            case 1:
                addTeamMenu();
                break;
            case 2:
                selectTeamMenu();
                if (!currentTeamName.empty() && teams.find(currentTeamName) != teams.end()) {
                    displayCurrentTeamMenu();
                }
                break;
            case 3:
                listAllTeams();
                break;
            case 4:
                simulateMatchBetweenTeams();
                break;
            case 5:
                cout << GREEN << "\nExiting Soccer Team Strategy Simulator..." << RESET << endl;
                cout << GREEN << "Thank you for playing!" << RESET << endl;
                break;
            default:
                cout << RED << "ERROR: Invalid choice. Please select 1-5." << RESET << endl;
            }
        }
        catch (const exception& e) {
            cout << RED << e.what() << RESET << endl;
        }

    } while (choice != 5);

    // Clean up memory
    for (auto& pair : teams) {
        delete pair.second;
    }
    teams.clear();

    return 0;
}

// FIXED: Creates 3 pre-populated teams with exactly 11 players each
void createPrePopulatedTeams() {
    cout << YELLOW << "\n========================================" << RESET << endl;
    cout << RED << "   CREATING 3 PRE-POPULATED TEAMS" << RESET << endl;
    cout << YELLOW<< "========================================" << RESET << endl;

    // ===== TEAM 1: FC Barcelona (4-3-3 Formation) - 11 players =====
    Team* barcelona = new Team("FC Barcelona", "Xavi Hernandez");

    // Goalkeeper (1)
    barcelona->addPlayer(new Goalkeeper("Marc-Andre ter Stegen", 1, 92));

    // Defenders (4)
    barcelona->addPlayer(new Defender("Jules Kounde", 23, 85));
    barcelona->addPlayer(new Defender("Ronald Araujo", 4, 87));
    barcelona->addPlayer(new Defender("Andreas Christensen", 15, 83));
    barcelona->addPlayer(new Defender("Alejandro Balde", 3, 84));

    // Midfielders (3)
    barcelona->addPlayer(new Midfielder("Frenkie de Jong", 21, 88));
    barcelona->addPlayer(new Midfielder("Pedri", 8, 89));
    barcelona->addPlayer(new Midfielder("Gavi", 6, 86));

    // Forwards (3)
    barcelona->addPlayer(new Striker("Robert Lewandowski", 9, 91));
    barcelona->addPlayer(new Striker("Raphinha", 11, 85));
    barcelona->addPlayer(new Striker("Ferran Torres", 7, 84));

    // Set formation
    barcelona->setStrategy(new FourThreeThree());
    teams["FC Barcelona"] = barcelona;

    cout << GREEN << "FC Barcelona" << RESET << " (Manager: Xavi Hernandez)" << endl;
    cout << "  - Formation: 4-3-3" << endl;
    cout << "  - Players: " << barcelona->getPlayerCount() << "/11" << endl;
    cout << "  - Total Skill: " << barcelona->getTotalSkill() << endl;
    cout << "  - Key Player: Robert Lewandowski (ST, 91 skill)" << endl << endl;

    // ===== TEAM 2: Real Madrid (4-4-2 Formation) - 11 players =====
    Team* madrid = new Team("Real Madrid", "Carlo Ancelotti");

    // Goalkeeper (1)
    madrid->addPlayer(new Goalkeeper("Thibaut Courtois", 1, 93));

    // Defenders (4)
    madrid->addPlayer(new Defender("Dani Carvajal", 2, 85));
    madrid->addPlayer(new Defender("Antonio Rudiger", 22, 88));
    madrid->addPlayer(new Defender("David Alaba", 4, 87));
    madrid->addPlayer(new Defender("Ferland Mendy", 23, 84));

    // Midfielders (4)
    madrid->addPlayer(new Midfielder("Luka Modric", 10, 90));
    madrid->addPlayer(new Midfielder("Toni Kroos", 8, 89));
    madrid->addPlayer(new Midfielder("Eduardo Camavinga", 12, 85));
    madrid->addPlayer(new Midfielder("Federico Valverde", 15, 88));

    // Forwards (2)
    madrid->addPlayer(new Striker("Vinicius Junior", 7, 90));
    madrid->addPlayer(new Striker("Jude Bellingham", 5, 91));  

    // Set formation
    madrid->setStrategy(new FourFourTwo());
    teams["Real Madrid"] = madrid;

    cout << GREEN << "✓ Real Madrid" << RESET << " (Manager: Carlo Ancelotti)" << endl;
    cout << "  - Formation: 4-4-2" << endl;
    cout << "  - Players: " << madrid->getPlayerCount() << "/11" << endl;
    cout << "  - Total Skill: " << madrid->getTotalSkill() << endl;
    cout << "  - Key Player: Thibaut Courtois (GK, 93 skill)" << endl << endl;

    // ===== TEAM 3: Manchester City (3-5-2 Formation) - 11 players =====
    Team* city = new Team("Manchester City", "Pep Guardiola");

    // Goalkeeper (1)
    city->addPlayer(new Goalkeeper("Ederson", 31, 90));

    // Defenders (3)
    city->addPlayer(new Defender("Kyle Walker", 2, 86));
    city->addPlayer(new Defender("Ruben Dias", 3, 89));
    city->addPlayer(new Defender("John Stones", 5, 87));

    // Midfielders (5)
    city->addPlayer(new Midfielder("Rodri", 16, 90));
    city->addPlayer(new Midfielder("Kevin De Bruyne", 17, 93));
    city->addPlayer(new Midfielder("Bernardo Silva", 20, 88));
    city->addPlayer(new Midfielder("Phil Foden", 47, 87));
    city->addPlayer(new Midfielder("Jack Grealish", 10, 85));

    // Forwards (2)
    city->addPlayer(new Striker("Erling Haaland", 9, 94));
    city->addPlayer(new Striker("Julian Alvarez", 19, 86));

    // Set formation
    city->setStrategy(new ThreeFiveTwo());
    teams["Manchester City"] = city;

    cout << GREEN << "Manchester City" << RESET << " (Manager: Pep Guardiola)" << endl;
    cout << "  - Formation: 3-5-2" << endl;
    cout << "  - Players: " << city->getPlayerCount() << "/11" << endl;
    cout << "  - Total Skill: " << city->getTotalSkill() << endl;
    cout << "  - Key Player: Erling Haaland (ST, 94 skill)" << endl << endl;

    cout << CYAN << "========================================" << RESET << endl;
    cout << GREEN << "All 3 teams created successfully!" << RESET << endl;
    cout << "Total teams available: " << teams.size() << endl;
    cout << CYAN << "========================================\n" << RESET << endl;
}
void displayHeader() {
    cout << CYAN;
    cout << "========================================" << endl;
    cout << "   SOCCER TEAM STRATEGY SIMULATOR" << endl;
    cout << "   Group F - APM11A1" << endl;
    cout << "========================================" << RESET << endl;
}

void displayMainMenu() {
    cout << YELLOW << "\n========== MAIN MENU ==========" << RESET << endl;
    cout << "1. Create New Team" << endl;
    cout << "2. Manage Team (Select Team)" << endl;
    cout << "3. List All Teams" << endl;
    cout << "4. Simulate Match (Team vs Team)" << endl;
    cout << "5. Exit" << endl;
    cout << YELLOW << "================================" << RESET << endl;
}

void displayTeamManagementMenu() {
    cout << YELLOW << "\n========== TEAM MANAGEMENT ==========" << RESET << endl;
    cout << "Current Team: " << CYAN << currentTeamName << RESET << endl;
    cout << "Manager: " << CYAN << teams[currentTeamName]->getManagerName() << RESET << endl;
    cout << "1. Add Player to Team" << endl;
    cout << "2. Display Team Roster" << endl;
    cout << "3. Apply Formation Strategy" << endl;
    cout << "4. Sort Team Players" << endl;
    cout << "5. Search for Player" << endl;
    cout << "6. Back to Main Menu" << endl;
    cout << YELLOW << "======================================" << RESET << endl;
}

void addTeamMenu() {
    string teamName;
    string managerName;

    cout << CYAN << "\n--- CREATE NEW TEAM ---" << RESET << endl;

    cin.ignore();
    cout << "Enter team name: ";
    getline(cin, teamName);

    // Check if team already exists
    if (teams.find(teamName) != teams.end()) {
        cout << RED << "ERROR: Team '" << teamName << "' already exists!" << RESET << endl;
        return;
    }

    cout << "Enter team manager name: ";
    getline(cin, managerName);

    if (managerName.empty()) {
        managerName = "Unassigned";
    }

    Team* newTeam = new Team(teamName, managerName);
    teams[teamName] = newTeam;

    cout << GREEN << "SUCCESS: Team '" << teamName << "' has been created!" << RESET << endl;
    cout << GREEN << "Manager: " << managerName << RESET << endl;
}

void selectTeamMenu() {
    if (teams.empty()) {
        cout << RED << "ERROR: No teams available. Please create a team first." << RESET << endl;
        return;
    }

    cout << CYAN << "\n--- SELECT TEAM ---" << RESET << endl;

    int index = 1;
    vector<string> teamNames;
    for (auto& pair : teams) {
        cout << index << ". " << pair.first;
        cout << " (Manager: " << pair.second->getManagerName() << ")";
        cout << " | Players: " << pair.second->getPlayerCount() << "/11" << endl;
        teamNames.push_back(pair.first);
        index++;
    }

    cout << "Enter choice (0 to cancel): ";
    int choice;
    cin >> choice;

    if (choice == 0) {
        return;
    }

    if (choice < 1 || choice > static_cast<int>(teamNames.size())) {
        cout << RED << "ERROR: Invalid team selection." << RESET << endl;
        return;
    }

    currentTeamName = teamNames[choice - 1];
    cout << GREEN << "SUCCESS: Now managing team '" << currentTeamName << "'" << RESET << endl;
    cout << GREEN << "Manager: " << teams[currentTeamName]->getManagerName() << RESET << endl;
}

void addPlayerToTeam() {
    if (currentTeamName.empty()) {
        cout << RED << "ERROR: No team selected. Please select a team first." << RESET << endl;
        return;
    }

    Team* currentTeam = teams[currentTeamName];

    if (currentTeam->isFull()) {
        cout << RED << "ERROR: Team '" << currentTeamName << "' is full! Maximum 11 players allowed." << RESET << endl;
        return;
    }

    string name;
    int number, skill, roleChoice;

    cout << CYAN << "\n--- ADD NEW PLAYER TO " << currentTeamName << " ---" << RESET << endl;
    cout << "Team Manager: " << currentTeam->getManagerName() << endl;

    cin.ignore();
    cout << "Enter player name: ";
    getline(cin, name);

    cout << "Enter jersey number (1-99): ";
    cin >> number;

    if (number < 1 || number > 99) {
        cout << RED << "ERROR: Jersey number must be between 1 and 99." << RESET << endl;
        return;
    }

    cout << "Enter skill rating (0-100): ";
    cin >> skill;

    if (skill < 0 || skill > 100) {
        cout << RED << "ERROR: Skill must be between 0 and 100." << RESET << endl;
        return;
    }

    cout << "\nSelect position:" << endl;
    cout << "1. Goalkeeper" << endl;
    cout << "2. Defender" << endl;
    cout << "3. Midfielder" << endl;
    cout << "4. Striker" << endl;
    cout << "Choice: ";
    cin >> roleChoice;

    Player* newPlayer = nullptr;

    try {
        switch (roleChoice) {
        case 1:
            newPlayer = new Goalkeeper(name, number, skill);
            break;
        case 2:
            newPlayer = new Defender(name, number, skill);
            break;
        case 3:
            newPlayer = new Midfielder(name, number, skill);
            break;
        case 4:
            newPlayer = new Striker(name, number, skill);
            break;
        default:
            cout << RED << "ERROR: Invalid position choice." << RESET << endl;
            return;
        }

        currentTeam->addPlayer(newPlayer);
        cout << GREEN << "SUCCESS: " << name << " (#" << number << ") added to " << currentTeamName << "!" << RESET << endl;
        cout << GREEN << "Team Manager: " << currentTeam->getManagerName() << " approved the signing." << RESET << endl;

    }
    catch (const exception& e) {
        delete newPlayer;
        throw;
    }
}

void displayCurrentTeamMenu() {
    Team* currentTeam = teams[currentTeamName];
    int choice;

    do {
        displayTeamManagementMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            cout << RED << "ERROR: Invalid input." << RESET << endl;
            continue;
        }

        try {
            switch (choice) {
            case 1:
                addPlayerToTeam();
                break;
            case 2:
                currentTeam->displayTeam();
                break;
            case 3:
                applyStrategyToTeam();
                break;
            case 4:
                sortTeamPlayers();
                break;
            case 5:
                searchTeamPlayers();
                break;
            case 6:
                cout << GREEN << "Returning to main menu..." << RESET << endl;
                break;
            default:
                cout << RED << "ERROR: Invalid choice." << RESET << endl;
            }
        }
        catch (const exception& e) {
            cout << RED << e.what() << RESET << endl;
        }

    } while (choice != 6);
}

void applyStrategyToTeam() {
    if (currentTeamName.empty()) {
        cout << RED << "ERROR: No team selected." << RESET << endl;
        return;
    }

    Team* currentTeam = teams[currentTeamName];

    if (currentTeam->getPlayerCount() < 7) {
        cout << RED << "ERROR: Need at least 7 players to apply a formation!" << RESET << endl;
        return;
    }

    int stratChoice;
    FormationStrategy* strategy = nullptr;

    cout << CYAN << "\n--- SELECT FORMATION FOR " << currentTeamName << " ---" << RESET << endl;
    cout << "Team Manager: " << currentTeam->getManagerName() << " is making tactical decision." << endl;
    cout << "1. 4-4-2 (Balanced)" << endl;
    cout << "2. 4-3-3 (Attacking)" << endl;
    cout << "3. 3-5-2 (Possession)" << endl;
    cout << "Choice: ";
    cin >> stratChoice;

    switch (stratChoice) {
    case 1:
        strategy = new FourFourTwo();
        break;
    case 2:
        strategy = new FourThreeThree();
        break;
    case 3:
        strategy = new ThreeFiveTwo();
        break;
    default:
        cout << RED << "ERROR: Invalid formation choice." << RESET << endl;
        return;
    }

    currentTeam->setStrategy(strategy);
    currentTeam->applyStrategy();

    cout << GREEN << "SUCCESS: Formation applied to " << currentTeamName << "!" << RESET << endl;
    cout << GREEN << "Manager " << currentTeam->getManagerName() << " has set the team's formation." << RESET << endl;

    // Display recommendation
    cout << "\nRecommended formation based on squad: " << currentTeam->getRecommendedFormation() << endl;

    delete strategy;
}

void sortTeamPlayers() {
    if (currentTeamName.empty()) {
        cout << RED << "ERROR: No team selected." << RESET << endl;
        return;
    }

    Team* currentTeam = teams[currentTeamName];

    if (currentTeam->getPlayerCount() == 0) {
        cout << RED << "ERROR: No players in team to sort." << RESET << endl;
        return;
    }

    int sortChoice;
    cout << "\nSort players by:" << endl;
    cout << "1. Skill (highest first) - Bubble Sort O(n^2)" << endl;
    cout << "2. Jersey Number - Quick Sort O(n log n)" << endl;
    cout << "Choice: ";
    cin >> sortChoice;

    if (sortChoice == 1) {
        currentTeam->sortPlayersBySkill();
        cout << GREEN << "Team sorted by skill rating using BUBBLE SORT!" << RESET << endl;
        cout << GREEN << "Manager " << currentTeam->getManagerName() << " requested skill-based sorting." << RESET << endl;
    }
    else if (sortChoice == 2) {
        currentTeam->sortPlayersByNumber();
        cout << GREEN << "Team sorted by jersey number using QUICK SORT!" << RESET << endl;
        cout << GREEN << "Manager " << currentTeam->getManagerName() << " requested number-based sorting." << RESET << endl;
    }
    else {
        cout << RED << "ERROR: Invalid choice." << RESET << endl;
        return;
    }

    currentTeam->displayTeam();
}

void searchTeamPlayers() {
    if (currentTeamName.empty()) {
        cout << RED << "ERROR: No team selected." << RESET << endl;
        return;
    }

    Team* currentTeam = teams[currentTeamName];

    if (currentTeam->getPlayerCount() == 0) {
        cout << RED << "ERROR: No players in team to search." << RESET << endl;
        return;
    }

    int searchChoice;
    cout << "\nSearch for player:" << endl;
    cout << "1. By Name (Linear Search - O(n))" << endl;
    cout << "2. By Jersey Number (Binary Search - O(log n))" << endl;
    cout << "Choice: ";
    cin >> searchChoice;
    cin.ignore();

    if (searchChoice == 1) {
        string searchName;
        cout << "Enter name to search: ";
        getline(cin, searchName);

        Player* found = currentTeam->findPlayerByName(searchName);
        if (found) {
            cout << GREEN << "Player found using LINEAR SEARCH: " << RESET;
            found->display();
        }
        else {
            cout << RED << "Player not found!" << RESET << endl;
        }
    }
    else if (searchChoice == 2) {
        int searchNumber;
        cout << "Enter jersey number: ";
        cin >> searchNumber;

        Player* found = currentTeam->findPlayerByNumber(searchNumber);
        if (found) {
            cout << GREEN << "Player found using BINARY SEARCH: " << RESET;
            found->display();
        }
        else {
            cout << RED << "Player not found!" << RESET << endl;
        }
    }
    else {
        cout << RED << "ERROR: Invalid choice." << RESET << endl;
    }
}

void listAllTeams() {
    if (teams.empty()) {
        cout << RED << "No teams have been created yet." << RESET << endl;
        return;
    }

    cout << CYAN << "\n========== ALL TEAMS ==========" << RESET << endl;
    int teamCount = 1;
    for (auto& pair : teams) {
        Team* team = pair.second;
        cout << teamCount << ". Team: " << pair.first << endl;
        cout << "   Manager: " << team->getManagerName() << endl;
        cout << "   Players: " << team->getPlayerCount() << "/11" << endl;
        cout << "   Total Skill: " << team->getTotalSkill() << endl;
        cout << "   Average Skill: " << team->getAverageSkill() << endl;

        // Show formation if set
        if (team->getStrategy() != nullptr) {
            cout << "   Formation: " << team->getStrategy()->getName() << endl;
        }
        else {
            cout << "   Formation: Not set" << endl;
        }

        cout << "   Can Play Match: " << (team->getPlayerCount() >= 7 ? "Yes" : "No (need 7+ players)") << endl;
        cout << "   Full Squad: " << (team->isFull() ? "Yes" : "No") << endl;
        cout << "----------------------------------------" << endl;
        teamCount++;
    }
}

void simulateMatchBetweenTeams() {
    if (teams.size() < 2) {
        cout << RED << "ERROR: Need at least 2 teams to simulate a match!" << RESET << endl;
        return;
    }

    cout << CYAN << "\n--- SIMULATE MATCH ---" << RESET << endl;

    // Display available teams
    int index = 1;
    vector<string> teamNames;
    for (auto& pair : teams) {
        cout << index << ". " << pair.first;
        cout << " (Manager: " << pair.second->getManagerName() << ")";
        cout << " | Players: " << pair.second->getPlayerCount() << "/11";
        string status = (pair.second->getPlayerCount() >= 7) ? "READY" : "NOT READY";
        cout << " | " << status << endl;
        teamNames.push_back(pair.first);
        index++;
    }

    // Select home team
    cout << "\nSelect HOME team (0 to cancel): ";
    int homeChoice;
    cin >> homeChoice;

    if (homeChoice == 0) return;

    if (homeChoice < 1 || homeChoice > static_cast<int>(teamNames.size())) {
        cout << RED << "ERROR: Invalid team selection." << RESET << endl;
        return;
    }

    string homeTeamName = teamNames[homeChoice - 1];
    Team* homeTeam = teams[homeTeamName];

    // Select away team
    cout << "Select AWAY team (0 to cancel): ";
    int awayChoice;
    cin >> awayChoice;

    if (awayChoice == 0) return;

    if (awayChoice < 1 || awayChoice > static_cast<int>(teamNames.size())) {
        cout << RED << "ERROR: Invalid team selection." << RESET << endl;
        return;
    }

    string awayTeamName = teamNames[awayChoice - 1];
    Team* awayTeam = teams[awayTeamName];

    // Check if teams have enough players
    if (homeTeam->getPlayerCount() < 7) {
        cout << RED << "ERROR: " << homeTeamName << " needs at least 7 players to play a match!" << RESET << endl;
        cout << "Current players: " << homeTeam->getPlayerCount() << "/11" << endl;
        return;
    }

    if (awayTeam->getPlayerCount() < 7) {
        cout << RED << "ERROR: " << awayTeamName << " needs at least 7 players to play a match!" << RESET << endl;
        cout << "Current players: " << awayTeam->getPlayerCount() << "/11" << endl;
        return;
    }

    cout << "\n" << CYAN << "========================================" << RESET << endl;
    cout << CYAN << "MATCH: " << homeTeamName << " vs " << awayTeamName << RESET << endl;
    cout << "Home Manager: " << homeTeam->getManagerName() << endl;
    cout << "Away Manager: " << awayTeam->getManagerName() << endl;
    cout << CYAN << "========================================" << RESET << endl;

    MatchSimulator simulator(*homeTeam, *awayTeam);
    MatchSimulator::MatchResult result = simulator.simulateMatch();
    simulator.displayMatchResult(result);

    // Add manager commentary
    if (result.winner == homeTeamName) {
        cout << GREEN << "Manager " << homeTeam->getManagerName() << ": 'Great performance from the team!'" << RESET << endl;
        cout << RED << "Manager " << awayTeam->getManagerName() << ": 'We need to improve for next match.'" << RESET << endl;
    }
    else if (result.winner == awayTeamName) {
        cout << GREEN << "Manager " << awayTeam->getManagerName() << ": 'Excellent result away from home!'" << RESET << endl;
        cout << RED << "Manager " << homeTeam->getManagerName() << ": 'Disappointing loss at home.'" << RESET << endl;
    }
    else {
        cout << YELLOW << "Both managers: 'A fair result, we'll take the point.'" << RESET << endl;
    }
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}