#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <cmath>

// 1. DELETE the #include "Player.h" from this file!

struct Position {
    double x, y;
};

class Player {
protected:
    std::string name;
    int number;
    int skill;
    Position currentPos;
    Position targetPos;
    double speed;

public:
    Player(std::string n, int num, int s); // Declaration only
    virtual ~Player() {}

    // Pure virtuals
    virtual void display() const = 0;
    virtual std::string getRole() const = 0;

    // Simulation Methods (Declarations)
    void setTargetPosition(double x, double y);
    Position getPosition() const;
    void update();

    // Standard Getters (Declarations)
    int getSkill() const;
    std::string getName() const;
    int getNumber() const;
    void setSkill(int s);

    // Operators (Declarations)
    bool operator>(const Player& other) const;
    bool operator<(const Player& other) const;
    bool operator==(const Player& other) const;

    static bool compareBySkill(const Player* a, const Player* b);
    static bool compareByName(const Player* a, const Player* b);
};

// --- Derived Classes (Declarations Only) ---

class Goalkeeper : public Player {
public:
    Goalkeeper(std::string n, int num, int s);
    void display() const override;
    std::string getRole() const override;
};

class Defender : public Player {
public:
    Defender(std::string n, int num, int s);
    void display() const override;
    std::string getRole() const override;
};

class Midfielder : public Player {
public:
    Midfielder(std::string n, int num, int s);
    void display() const override;
    std::string getRole() const override;
};

class Striker : public Player {
public:
    Striker(std::string n, int num, int s);
    void display() const override;
    std::string getRole() const override;
};

#endif