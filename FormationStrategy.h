#ifndef FORMATIONSTRATEGY_H
#define FORMATIONSTRATEGY_H

#include <string>
#include <vector>
#include "Player.h"

class FormationStrategy {
public:
    virtual ~FormationStrategy() {}
    virtual void apply() const = 0;
    virtual std::string getName() const = 0;
    virtual std::vector<Position> getPositions() const = 0;

    virtual int getDefenders() const = 0;
    virtual int getMidfielders() const = 0;
    virtual int getForwards() const = 0;
};

class FourFourTwo : public FormationStrategy {
public:
    void apply() const override;
    std::string getName() const override { return "4-4-2"; }
    std::vector<Position> getPositions() const override;
    int getDefenders() const override { return 4; }
    int getMidfielders() const override { return 4; }
    int getForwards() const override { return 2; }
};

class FourThreeThree : public FormationStrategy {
public:
    void apply() const override;
    std::string getName() const override { return "4-3-3"; }
    std::vector<Position> getPositions() const override;
    int getDefenders() const override { return 4; }
    int getMidfielders() const override { return 3; }
    int getForwards() const override { return 3; }
};

class ThreeFiveTwo : public FormationStrategy {
public:
    void apply() const override;
    std::string getName() const override { return "3-5-2"; }
    std::vector<Position> getPositions() const override;
    int getDefenders() const override { return 3; }
    int getMidfielders() const override { return 5; }
    int getForwards() const override { return 2; }
};

#endif