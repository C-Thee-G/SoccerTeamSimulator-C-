#include "Player.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cmath>

// ===== Player Base Class Implementation =====
Player::Player(std::string n, int num, int s)
    : name(n), number(num), speed(1.5) {
    setSkill(s);
    // Simulation coordinates: Start at center of pitch
    currentPos = { 50.0, 50.0 };
    targetPos = { 50.0, 50.0 };
}

// --- Standard Getters (Fixes LNK2019 errors) ---
int Player::getSkill() const { return skill; }
std::string Player::getName() const { return name; }
int Player::getNumber() const { return number; }

void Player::setSkill(int s) {
    if (s < 0 || s > 100) {
        throw std::invalid_argument("ERROR: Skill must be between 0 and 100");
    }
    skill = s;
}

// --- Simulation Methods ---
void Player::setTargetPosition(double x, double y) {
    targetPos = { x, y };
}

Position Player::getPosition() const {
    return currentPos;
}

void Player::update() {
    // Basic linear movement toward the target coordinate
    if (std::abs(currentPos.x - targetPos.x) > 0.5) {
        currentPos.x += (currentPos.x < targetPos.x) ? speed : -speed;
    }
    if (std::abs(currentPos.y - targetPos.y) > 0.5) {
        currentPos.y += (currentPos.y < targetPos.y) ? speed : -speed;
    }
}

// --- Operator Overloading ---
bool Player::operator>(const Player& other) const { return this->skill > other.skill; }
bool Player::operator<(const Player& other) const { return this->skill < other.skill; }
bool Player::operator==(const Player& other) const { return this->skill == other.skill; }

bool Player::compareBySkill(const Player* a, const Player* b) {
    return a->getSkill() > b->getSkill();
}

bool Player::compareByName(const Player* a, const Player* b) {
    return a->getName() < b->getName();
}

// ===== Goalkeeper Implementation =====
Goalkeeper::Goalkeeper(std::string n, int num, int s) : Player(n, num, s) {}

void Goalkeeper::display() const {
    std::cout << "[GK]  " << std::left << std::setw(15) << name
        << " | #" << std::setw(2) << number
        << " | Skill: " << std::setw(3) << skill << std::endl;
}

std::string Goalkeeper::getRole() const { return "Goalkeeper"; }

// ===== Defender Implementation =====
Defender::Defender(std::string n, int num, int s) : Player(n, num, s) {}

void Defender::display() const {
    std::cout << "[DF]  " << std::left << std::setw(15) << name
        << " | #" << std::setw(2) << number
        << " | Skill: " << std::setw(3) << skill << std::endl;
}

std::string Defender::getRole() const { return "Defender"; }

// ===== Midfielder Implementation =====
Midfielder::Midfielder(std::string n, int num, int s) : Player(n, num, s) {}

void Midfielder::display() const {
    std::cout << "[MF]  " << std::left << std::setw(15) << name
        << " | #" << std::setw(2) << number
        << " | Skill: " << std::setw(3) << skill << std::endl;
}

std::string Midfielder::getRole() const { return "Midfielder"; }

// ===== Striker Implementation =====
Striker::Striker(std::string n, int num, int s) : Player(n, num, s) {}

void Striker::display() const {
    std::cout << "[ST]  " << std::left << std::setw(15) << name
        << " | #" << std::setw(2) << number
        << " | Skill: " << std::setw(3) << skill << std::endl;
}

std::string Striker::getRole() const { return "Striker"; }