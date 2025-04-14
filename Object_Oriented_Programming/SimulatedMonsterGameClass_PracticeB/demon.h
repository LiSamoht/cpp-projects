/*
public:
    Demon();
pre: None
post : Initializes the Demon object to a demon with default strength and hitpoints.

Demon(int newStrength, int newHitpoints);
pre: None
post : Initializes the Demon object with the given strength and hitpoints.

int getDamage() const;
pre: The Demon object is properly initialized.
post : Returns the damage value calculated based on the Demon's strength.

string getSpecies() const;
pre: The Demon object is properly initialized.
post : Returns the species name of the Demon.
*/
#ifndef DEMON_H
#define DEMON_H
#include "creature.h"
using namespace std;
namespace cs_creature {
	class Demon : public Creature {
	public:
		Demon();
		Demon(int newStrength, int newHitpoints);
		int getDamage() const;
		string getSpecies() const;

	};
}

#endif