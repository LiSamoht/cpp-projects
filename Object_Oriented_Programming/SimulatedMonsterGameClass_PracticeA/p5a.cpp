//----------------------------------------------------------------------------------------
   // A SAMPLE CLIENT PROGRAM TO TEST INHERITANCE IMPLEMENTATION CONCEPTS DEMONSTRATED
   // client.cpp   
   //
#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include "balrog.h"
#include <ctime>
#include <iostream>

using namespace cs_creature;
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Human h1;
    Elf e1;
    Cyberdemon c1;
    Balrog b1;

    Human h(20, 30);
    Elf e(40, 50);
    Cyberdemon c(60, 70);
    Balrog b(80, 90);


    cout << "default Human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
    cout << "default Elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
    cout << "default Cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
    cout << "default Balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
    cout << "non-default Human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
    cout << "non-default Elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
    cout << "non-default Cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
    cout << "non-default Balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
    cout << endl << endl;

    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = h.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << c.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = c.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << b.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = b.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;
}


/*
default Human strength/hitpoints: 10/10
default Elf strength/hitpoints: 10/10
default Cyberdemon strength/hitpoints: 10/10
default Balrog strength/hitpoints: 10/10
non-default Human strength/hitpoints: 20/30
non-default Elf strength/hitpoints: 40/50
non-default Cyberdemon strength/hitpoints: 60/70
non-default Balrog strength/hitpoints: 80/90


Examples of Human damage:
The Human attacks for 6 points!
 Total damage = 6

The Human attacks for 15 points!
 Total damage = 15

The Human attacks for 4 points!
 Total damage = 4

The Human attacks for 5 points!
 Total damage = 5

The Human attacks for 1 points!
 Total damage = 1

The Human attacks for 5 points!
 Total damage = 5

The Human attacks for 11 points!
 Total damage = 11

The Human attacks for 17 points!
 Total damage = 17

The Human attacks for 16 points!
 Total damage = 16

The Human attacks for 1 points!
 Total damage = 1


Examples of Elf damage:
The Elf attacks for 27 points!
 Total damage = 27

The Elf attacks for 12 points!
Magical attack inflicts 12 additional damage points!
 Total damage = 24

The Elf attacks for 17 points!
Magical attack inflicts 17 additional damage points!
 Total damage = 34

The Elf attacks for 22 points!
Magical attack inflicts 22 additional damage points!
 Total damage = 44

The Elf attacks for 1 points!
Magical attack inflicts 1 additional damage points!
 Total damage = 2

The Elf attacks for 19 points!
Magical attack inflicts 19 additional damage points!
 Total damage = 38

The Elf attacks for 39 points!
 Total damage = 39

The Elf attacks for 39 points!
 Total damage = 39

The Elf attacks for 17 points!
Magical attack inflicts 17 additional damage points!
 Total damage = 34

The Elf attacks for 30 points!
Magical attack inflicts 30 additional damage points!
 Total damage = 60


Examples of Cyberdemon damage:
The Cyberdemon attacks for 9 points!
 Total damage = 9

The Cyberdemon attacks for 11 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 61

The Cyberdemon attacks for 4 points!
 Total damage = 4

The Cyberdemon attacks for 36 points!
 Total damage = 36

The Cyberdemon attacks for 37 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 87

The Cyberdemon attacks for 38 points!
 Total damage = 38

The Cyberdemon attacks for 10 points!
 Total damage = 10

The Cyberdemon attacks for 11 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 61

The Cyberdemon attacks for 52 points!
 Total damage = 52

The Cyberdemon attacks for 42 points!
 Total damage = 42


Examples of Balrog damage:
The Balrog attacks for 1 points!
Balrog speed attack inflicts 54 additional damage points!
 Total damage = 55

The Balrog attacks for 49 points!
Balrog speed attack inflicts 22 additional damage points!
 Total damage = 71

The Balrog attacks for 33 points!
Balrog speed attack inflicts 10 additional damage points!
 Total damage = 43

The Balrog attacks for 59 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 9 additional damage points!
 Total damage = 118

The Balrog attacks for 30 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 32 additional damage points!
 Total damage = 112

The Balrog attacks for 14 points!
Balrog speed attack inflicts 42 additional damage points!
 Total damage = 56

The Balrog attacks for 13 points!
Balrog speed attack inflicts 80 additional damage points!
 Total damage = 93

The Balrog attacks for 30 points!
Balrog speed attack inflicts 23 additional damage points!
 Total damage = 53

The Balrog attacks for 54 points!
Balrog speed attack inflicts 53 additional damage points!
 Total damage = 107

The Balrog attacks for 7 points!
Balrog speed attack inflicts 13 additional damage points!
 Total damage = 20




*/