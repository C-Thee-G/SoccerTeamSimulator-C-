#include "FormationStrategy.h"

// 4-4-2 Map
std::vector<Position> FourFourTwo::getPositions() const {
    return {
        {5, 50},                                // GK
        {20, 20}, {20, 40}, {20, 60}, {20, 80}, // DEF
        {45, 20}, {45, 40}, {45, 60}, {45, 80}, // MID
        {75, 35}, {75, 65}                      // ST
    };
}
void FourFourTwo::apply() const { std::cout << "Applying 4-4-2: Balanced tactic.\n"; }

// 4-3-3 Map
std::vector<Position> FourThreeThree::getPositions() const {
    return {
        {5, 50},                                // GK
        {20, 20}, {20, 40}, {20, 60}, {20, 80}, // DEF
        {45, 25}, {45, 50}, {45, 75},           // MID
        {75, 20}, {75, 50}, {75, 80}            // ST
    };
}
void FourThreeThree::apply() const { std::cout << "Applying 4-3-3: Aggressive width.\n"; }

// 3-5-2 Map
std::vector<Position> ThreeFiveTwo::getPositions() const {
    return {
        {5, 50},                                // GK
        {20, 25}, {20, 50}, {20, 75},           // DEF
        {45, 10}, {45, 30}, {45, 50}, {45, 70}, {45, 90}, // MID
        {75, 35}, {75, 65}                      // ST
    };
}
void ThreeFiveTwo::apply() const { std::cout << "Applying 3-5-2: Midfield control.\n"; }