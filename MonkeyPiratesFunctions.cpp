#include <bits/stdc++.h>
#include "MonkeyPiratesVariables.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread; // sleep_for, sleep_until
using namespace chrono; // nanoseconds, system_clock, seconds

/*
Functions to save space/less clutter below
*/
void CreateAttackValues(Attack atk, string name, int dmg, int crit, int uses, int hit){
    atk.dmg = dmg; 
    atk.critChance = crit;
    atk.uses = uses;
    atk.hitChance = hit;
}

void InitializeAttacks(){
    CreateAttackValues(punch, "Punch", 4, 15, 50, 90);
    CreateAttackValues(kick,"Kick", 10, 25, 15, 60);
    CreateAttackValues(tailWhip, "Tail Whip", 2, 5, 3, 100);
}

int AverageDamage(Character car, Attack atk){
   int averageDmg;  
}

double calculateDamage(Character attacker, Character defender, int attackNum){
    if(attacker.atks[attackNum].hitChance < rand() % 100 + 1) return -1; // Incorporate speed
    bool criticalHit;
    if(attacker.atks[attackNum].critChance >= rand() % 100 + 1) criticalHit = true;
    double dmgDone = defender.def - attacker.atks[attackNum].dmg*(attacker.str/10);
    if(criticalHit) dmgDone*=1.5;
    if(criticalHit) dmgDone -= (dmgDone*2);
    if(dmgDone > defender.health) dmgDone = defender.health;
    return dmgDone;
}

//Function to repeat output n new blank lines
void Blank(int n){
    while(n--) cout << endl;
}

//Shortcut to sleep for n milliseconds
void Wait(int n){
    sleep_until(system_clock::now() + milliseconds(n));
}

void ClearLines(int numLines) {
    for (int i = 0; i < numLines; ++i) {
        std::cout << "\x1b[2K"; // Clear line
        std::cout << "\x1b[A"; // Move cursor up one line
    }
    Blank(1);
}

void Clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}

bool Battle(vector<Character> attacker, vector<Character> defender, vector <string> dialogueAttacker, vector<string> dialogueDefender, void (*asciiAttacker)(), void (*asciiDefender)(), int difficulty){
    if(dev){
        cout << "DEVELOPER MODE: CALCULATING TOP 3 BEST SOLUTIONS..." << endl; 
        auto startingTime = system_clock::now();
        vector<vector<string> > fastestSolutions;
        vector<int> orderedDamage;
    }
    int memberCount = defender.size();
    while(true){
        cout << "Your Party: " << endl;


        bool turn; // False means NPC party is attacking, true means it is the user's turn. The NPC party will always attack first (the "attacker").
        if(turn){

        } else{
            int memberAttacking = rand() % (attacker.size()-1) + 0;
            int attackUsed = rand() % (attacker[memberAttacking].atks.size()-1) + 0;
            int memberDefending = rand() % (defender.size()-1) + 0;
            double dmgDone = calculateDamage(attacker[memberAttacking], defender[memberDefending], attackUsed);
            if(dmgDone == -1){
                cout << "ATTACK MISSED" << endl;
            } else{
                if(dmgDone < 0){
                    cout << "CRITICAL HIT!!" << endl;
                    dmgDone = abs(dmgDone);
                } 
                cout << attacker[memberAttacking].atks[attackUsed].name << " did" << dmgDone << " damage " << "to " << defender[memberDefending].name << "!!" << endl;
            }
            turn = true;
        }
    }
    return true;
}

