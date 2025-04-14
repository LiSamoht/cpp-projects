/*
[Class Invariant:]
The class invariant for the Creature class ensures that the object maintains valid state throughout its lifetime.
1. The strength member variable represents how much damage the creature inflicts and must be non-negative.
2. The hitpoints member variable represents how much damage the creature can sustain and must be non-negative.
3. All member functions operate correctly assuming valid object state, i.e., strength and hitpoints are within valid ranges.

[Function Implementations:]
Creature::Creature()
pre: None
post: Initializes a Creature object with default strength and hitpoints of 10.

Creature::Creature(int newStrength, int newHitpoints)
pre: None
post: Initializes a Creature object with the given strength (newStrength) and hitpoints (newHitpoints).

int Creature::getStrength() const
pre: The Creature object is properly initialized.
post: Returns the strength of the Creature.

int Creature::getHitpoints() const
pre: The Creature object is properly initialized.
post: Returns the hitpoints of the Creature.

void Creature::setStrength(int newStrength)
pre: The Creature object is properly initialized.
post: Sets the strength of the Creature to the specified value (newStrength).

void Creature::setHitpoints(int newHitpoints)
pre: The Creature object is properly initialized.
post: Sets the hitpoints of the Creature to the specified value (newHitpoints).

int Creature::getDamage() const
pre: The Creature object is properly initialized.
post: Returns the damage inflicted by the Creature in a random range based on its strength. Also, prints a message indicating the attack.
*/
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

    int Creature::getDamage() const {
        int damage = (rand() % strength) + 1;
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }

}