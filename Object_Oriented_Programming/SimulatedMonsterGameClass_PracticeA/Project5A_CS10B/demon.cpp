#include "demon.h"
using namespace std;

namespace cs_creature {
	Demon::Demon() : Creature() {}
	Demon::Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {}
	string Demon::getSpecies() const {
		return "Demon";
	}
	int Demon::getDamage() const {
		int damage = Creature::getDamage();
		cout << "attacks for " << damage << " points!" << endl;
			if (rand() % 4 == 0) {
				damage = damage + 50;
				cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		}
			return damage;
	}
}