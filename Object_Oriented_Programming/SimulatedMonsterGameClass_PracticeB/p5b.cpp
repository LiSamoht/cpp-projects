/*
This program simulates a battle arena tournament among four different types of creatures: Elf, Balrog, Human, and Cyberdemon. Each creature has its own 
strength and hitpoints. The program initializes instances of these creatures with specific attributes and stores them in an array. The tournament proceeds 
in rounds, with each round pitting the current champion against a new contender. The battles are resolved using the battleArena function, which calculates
damage inflicted by each creature until one of them is defeated. The doBattle function manages the outcome of each battle, determining the winner and 
updating the champion accordingly. If there is a tie where both creatures are defeated, the program selects the next living creature as the champion. 
The tournament continues until all creatures have battled, and the last remaining champion is declared the winner.
*/
#include "human.h"
#include "elf.h"
#include "balrog.h"
#include "cyberdemon.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
using namespace cs_creature;

const int NUM_CREATURES = 4;

//possible functions to develop algorithms
void battleArena(Creature& Creature1, Creature& Creature2);
void doBattle(Creature& champion, Creature& contender);

int main()
{
	srand((time(0)));


	Elf e(24, 50);
	Balrog b(10, 50);
	Human h(100, 50);
	Cyberdemon c(50, 50);

	//data structure to store objects as elements or use your own implementation
	Creature* creatures[] = { &b, &e, &c, &h };
	Creature* champion = creatures[0];
	int nextContender = 1;

	do {
		cout << "**********************************\n";
		cout << "BattleArena battle#" << nextContender << endl;
		cout << "**********************************\n";

		doBattle(*champion, *creatures[nextContender]);

		if (champion->getHitpoints() <= 0 && creatures[nextContender]->getHitpoints() <= 0) {
			// If there's a tie, consider the next living creature as the champion
			cout << "Tie! Both creatures are defeated. ";
			if (nextContender == NUM_CREATURES - 1) {
				cout << "All creatures defeated...no champion! \n\n";
			}
			else {
				cout << creatures[nextContender + 1]->getSpecies() << " is the new champion!\n\n";
			}
			champion = creatures[nextContender + 1];
			nextContender += 2;
		}
		else {
			++nextContender;
		}

	} while (nextContender < NUM_CREATURES);
	return 0;
}

void battleArena(Creature& Creature1, Creature& Creature2) {
	do {
		int damage1 = Creature1.getDamage();
		int damage2 = Creature2.getDamage();

		int newhitpoints2 = Creature2.getHitpoints() - damage1;
		int newhitpoints1 = Creature1.getHitpoints() - damage2;

		Creature2.setHitpoints(newhitpoints2);
		Creature1.setHitpoints(newhitpoints1);
	} while (Creature1.getHitpoints() > 0 && Creature2.getHitpoints() > 0);

}

void doBattle(Creature& champion, Creature& contender) {
	int OrigChampHp = champion.getHitpoints();
	int OrigContenderHp = contender.getHitpoints();
	battleArena(champion, contender);
	
	if (champion.getHitpoints() <= 0 && contender.getHitpoints() > 0) {
		champion = contender;
		cout <<  champion.getSpecies() << " wins!" << endl << endl << endl;
		champion.setHitpoints(OrigContenderHp);
	}
	else if (contender.getHitpoints() <= 0 && champion.getHitpoints() > 0) {
		cout << champion.getSpecies() << " wins!" << endl << endl << endl;
		champion.setHitpoints(OrigChampHp);
	}
}

/*
SAMPLE RUNS:
RUN 1:
**********************************
BattleArena battle#1
**********************************
The Balrog attacks for 4 points!
Balrog speed attack inflicts 7 additional damage points!
The Elf attacks for 22 points!
Magical attack inflicts 22 additional damage points!
The Balrog attacks for 9 points!
Balrog speed attack inflicts 1 additional damage points!
The Elf attacks for 3 points!
Magical attack inflicts 3 additional damage points!
Balrog wins!


**********************************
BattleArena battle#2
**********************************
The Balrog attacks for 7 points!
Balrog speed attack inflicts 20 additional damage points!
The Cyberdemon attacks for 19 points!
The Balrog attacks for 8 points!
Balrog speed attack inflicts 14 additional damage points!
The Cyberdemon attacks for 25 points!
Demonic attack inflicts 50 additional damage points!
Balrog wins!


**********************************
BattleArena battle#3
**********************************
The Balrog attacks for 14 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 24 additional damage points!
The Human attacks for 46 points!
Balrog wins!

RUN 2:
**********************************
BattleArena battle#1
**********************************
The Balrog attacks for 10 points!
Balrog speed attack inflicts 10 additional damage points!
The Elf attacks for 9 points!
The Balrog attacks for 6 points!
Balrog speed attack inflicts 8 additional damage points!
The Elf attacks for 5 points!
Magical attack inflicts 5 additional damage points!
The Balrog attacks for 4 points!
Balrog speed attack inflicts 6 additional damage points!
The Elf attacks for 21 points!
The Balrog attacks for 6 points!
Balrog speed attack inflicts 5 additional damage points!
The Elf attacks for 8 points!
Magical attack inflicts 8 additional damage points!
Tie! Both creatures are defeated. Cyberdemon is the new champion!

**********************************
BattleArena battle#3
**********************************
The Cyberdemon attacks for 9 points!
The Human attacks for 24 points!
The Cyberdemon attacks for 18 points!
The Human attacks for 75 points!
Cyberdemon wins!

Run 3:
**********************************
BattleArena battle#1
**********************************
The Balrog attacks for 3 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 6 additional damage points!
The Elf attacks for 2 points!
Balrog wins!


**********************************
BattleArena battle#2
**********************************
The Balrog attacks for 5 points!
Balrog speed attack inflicts 1 additional damage points!
The Cyberdemon attacks for 14 points!
The Balrog attacks for 2 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 7 additional damage points!
The Cyberdemon attacks for 7 points!
Demonic attack inflicts 50 additional damage points!
Tie! Both creatures are defeated. Human is the new champion!


Run 4:
**********************************
BattleArena battle#1
**********************************
The Balrog attacks for 5 points!
Balrog speed attack inflicts 6 additional damage points!
The Elf attacks for 1 points!
Magical attack inflicts 1 additional damage points!
The Balrog attacks for 9 points!
Balrog speed attack inflicts 5 additional damage points!
The Elf attacks for 4 points!
The Balrog attacks for 4 points!
Balrog speed attack inflicts 3 additional damage points!
The Elf attacks for 1 points!
Magical attack inflicts 1 additional damage points!
The Balrog attacks for 8 points!
Balrog speed attack inflicts 10 additional damage points!
The Elf attacks for 8 points!
Balrog wins!


**********************************
BattleArena battle#2
**********************************
The Balrog attacks for 1 points!
Balrog speed attack inflicts 9 additional damage points!
The Cyberdemon attacks for 45 points!
The Balrog attacks for 10 points!
Balrog speed attack inflicts 4 additional damage points!
The Cyberdemon attacks for 33 points!
Balrog wins!


**********************************
BattleArena battle#3
**********************************
The Balrog attacks for 12 points!
Balrog speed attack inflicts 26 additional damage points!
The Human attacks for 48 points!
The Balrog attacks for 2 points!
Balrog speed attack inflicts 46 additional damage points!
The Human attacks for 76 points!
Tie! Both creatures are defeated. All creatures defeated...no champion!
*/