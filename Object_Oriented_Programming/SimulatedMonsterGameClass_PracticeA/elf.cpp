#include "elf.h"
#include <iostream>

namespace cs_creature {
	Elf::Elf() : Creature() {}
	Elf::Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}
	
	string Elf::getSpecies() const {
		return "Elf";
	}
	int Elf::getDamage() const {
		int damage = Creature::getDamage();
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
		if ((rand() % 2) == 0) {
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage *= 2;
		}
		return damage;
	}
}