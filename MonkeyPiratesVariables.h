#ifndef Variables_H
#define Variables_H
#include <bits/stdc++.h>
using namespace std;


// Class for each character

class Attack {
    public:
        string name;
        double dmg;
        double critChance;
        int uses;
        int maxUses;
        double hitChance;
        void (*Sscii)();
};

class Character {
    public:
        string name;
        string description;
        double health;
        double maxHealth;
        double str;
        double def;
        double spd;
        vector<Attack> atks;
        void (*Ascii)();
};

class LastSave {
    vector<Character> par;
    int ship;
};

// Declare an external variable of type Character
extern vector<Character> party;
extern vector<vector<Character> > ship;
extern bool dev;

//Attack variables
extern Attack punch;
Attack punch;
extern Attack kick;
Attack kick;
extern Attack tailWhip;
Attack tailWhip;


vector<Character> party;
bool dev;
#endif
