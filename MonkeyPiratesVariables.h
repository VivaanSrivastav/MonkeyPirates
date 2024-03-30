/*
Name: Vivaan Srivastav
Date: March 30, 2024
Purpose: Holds the variables/objects for the game
File name: MonkeyPiratesAscii.cpp
*/

#ifndef Variables_H
#define Variables_H
#include <bits/stdc++.h>
using namespace std;


// Class for each attack, names are self explanatory
class Attack {
    public:
        string name;
        double dmg; // damage
        double critChance;
        int uses;
        int maxUses;
        double hitChance;
        string description;
        void (*Ascii)();
};

// Class for each character, names are self explanatory
class Character {
    public:
        string name;
        string description;
        double health;
        double maxHealth;
        double str; // strength
        double def; // defense
        double spd; // speed
        vector<Attack> atks;
        void (*Ascii)();
};

// party vector for holding the main party
extern vector<Character> party;
vector<Character> party;


//Attack variables
extern Attack punch;
extern Attack kick;
extern Attack tailWhip;
extern Attack slap;
extern Attack throngle;
extern Attack intimidate;
extern Attack cornobble; // Real word btw
Attack punch;
Attack kick;
Attack tailWhip;
Attack slap;
Attack throngle;
Attack intimidate;

#endif
