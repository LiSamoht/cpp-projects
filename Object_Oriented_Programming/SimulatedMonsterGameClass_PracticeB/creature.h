/*
[The Creature class represents a generic creature in a battle arena.
It provides functionality for managing the creature's strength, hitpoints, and damage calculation.]

public:
    Creature();
    pre: None
    post: Initializes the Creature object to a Human with 10 strength and 10 hitpoints.

    Creature(int newStrength, int newHitpoints);
    pre: None
    post: Initializes the Creature object with the given strength and hitpoints.

    virtual int getDamage() const;
    pre: The Creature object is properly initialized.
    post: Returns the damage value calculated based on the Creature's strength.

    virtual string getSpecies() const = 0;
    pre: The Creature object is properly initialized.
    post: Returns the species name of the Creature.

    int getStrength() const;
    pre: The Creature object is properly initialized.
    post: Returns the strength value of the Creature.

    int getHitpoints() const;
    pre: The Creature object is properly initialized.
    post: Returns the hitpoints value of the Creature.

    void setStrength(int newStrength);
    pre: The Creature object is properly initialized.
    post: Sets the strength value of the Creature to the given value.

    void setHitpoints(int newHitPoints);
    pre: The Creature object is properly initialized.
    post: Sets the hitpoints value of the Creature to the given value.
*/
#pragma once
#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

namespace cs_creature {
    class Creature {
    private:
        int strength;           // how much damage this Creature inflicts
        int hitpoints;          // how much damage this Creature can sustain
    public:
        Creature();             // initialize to Human, 10 strength, 10 hitpoints
        Creature(int newStrength, int newHitpoints);
        virtual int getDamage() const;
        virtual string getSpecies() const = 0;
        int getStrength() const;
        int getHitpoints() const;
        void setStrength(int newStrength);
        void setHitpoints(int newHitPoints);   
    };
}
#endif


/*
Qs1: Redefining and Overriding were two concepts introduced in the context of inheritance and polymorphism.
Explain how these concepts were implemented in your project and provide specific examples.

A1: Redefining refers to defining a function in a derived class with the same name as a function in the base class,
but with a different implementation. In the project, the getDamage() function is redefined in each derived class
to provide specific damage calculation logic for that creature type. Overriding, on the other hand, is the
redefining of a virtual member function in a derived class to customize its behavior. In the project, the getSpecies()
function is a pure virtual function in the Creature class, and it is overridden in each derived class to return
the species name of that specific creature type.

Qs2: Explain the distinction in terms of implementation between getSpecies(), a pure virtual function and getDamage()
a virtual member functions.

A2: getSpecies() is a pure virtual function, meaning it is declared in the base class (Creature) but has no
implementation. It must be implemented in every derived class, or else the derived class will also be abstract.
getDamage(), on the other hand, is a virtual member function that is implemented in the base class but can be
redefined in derived classes to customize its behavior. This means that getDamage() has a default implementation
in the base class, but it can be overridden in derived classes to provide different functionality.

Qs3: Can we say that the creature class is an example of an abstract class? Why or why not? Explain.

A3: Yes, the Creature class is an example of an abstract class because it contains at least one pure virtual
function (getSpecies()), making it impossible to create instances of the Creature class directly. Instead,
the Creature class serves as a blueprint for other classes to inherit from and implement the pure virtual
functions, making it an abstract base class.

Qs4: Why do the derived classes not have any data members? Provide some examples of data members that could
be added to the derived classes in future.

A4: The derived classes in this project do not have any additional data members because they inherit the
data members (strength and hitpoints) from the Creature class. However, in future iterations of the project,
additional data members could be added to represent unique characteristics of each creature type. For example,
a derived class representing a mythical creature like a dragon could have a data member to indicate its fire
breathing ability or something?
*/