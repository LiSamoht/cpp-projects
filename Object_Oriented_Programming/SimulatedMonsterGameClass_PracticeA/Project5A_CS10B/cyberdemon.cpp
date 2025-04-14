#include "cyberdemon.h"
using namespace std;
namespace cs_creature {
	Cyberdemon::Cyberdemon() : Demon() {}
	Cyberdemon::Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {}
	string Cyberdemon::getSpecies() const {
		return "Cyberdemon";
	}
	int Cyberdemon::getDamage() const{
		cout << "The Cyberdemon ";
		int damage = Demon::getDamage();
		return damage;
	}
}