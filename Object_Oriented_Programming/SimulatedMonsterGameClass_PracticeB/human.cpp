#include "human.h"
#include <iostream>
using namespace std;
namespace cs_creature {
	Human::Human() : Creature() {}
	Human::Human(int newStrength, int newHitPoints) : Creature(newStrength, newHitPoints) {}
	string Human::getSpecies() const {
		return "Human";
    }
}