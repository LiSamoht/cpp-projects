#pragma once
#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "demon.h"
using namespace std;

namespace cs_creature {
	class Cyberdemon : public Demon {
	public:
		Cyberdemon();
		Cyberdemon(int newStrength, int newHitpoints);
		string getSpecies() const;
	};
}

#endif
