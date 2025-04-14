#pragma once
#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

namespace cs_creature {
    class Creature {
    private:
        int strength;           // how much damage this Creature inflicts
        int hitpoints;          // how much damage this Creature can sustain
    public:
        Creature();             // initialize to Human, 10 strength, 10 hitpoints
        Creature(int newStrength, int newHitpoints);
        int getDamage() const;
        string getSpecies() const;
        int getStrength() const;
        int getHitpoints() const;
        void setStrength(int newStrength);
        void setHitpoints(int newHitPoints);
    // also include appropriate accessors and mutators    
    };
}
#endif