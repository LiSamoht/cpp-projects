
#include "creature.h"
using namespace std;

namespace cs_creature {

    Creature::Creature() {
        strength = 10;
        hitpoints = 10;
    }

    Creature::Creature(int newStrength, int newHitpoints) {
        strength = newStrength;
        hitpoints = newHitpoints;
    }


    // Accessor for strength
    int Creature::getStrength() const {
        return strength;
    }

    // Accessor for hitpoints
    int Creature::getHitpoints() const {
        return hitpoints;
    }

    // Mutator for strength
    void Creature::setStrength(int newStrength) {
        strength = newStrength;
    }

    // Mutator for hitpoints
    void Creature::setHitpoints(int newHitpoints) {
        hitpoints = newHitpoints;
    }

    string Creature::getSpecies() const {
        return "Creature";
    }

    // Get damage function
    int Creature::getDamage() const {
        int damage = (rand() % strength) + 1;
        return damage;
    }

}