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

int AverageDamage(Character car, Attack atk){
   int averageDmg;  
   return averageDmg;
}

double calculateDamage(Character attacker, Character defender, int attackNum){
    if(100 - attacker.atks[attackNum].hitChance*(attacker.spd/10) > rand() % 100 + 1) return INT_MAX; 
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

bool isIntInRange(string toCheck, int low, int high) {
  if (toCheck[0] == '-') {
    for (int i = 1; i < toCheck.size(); i++) {
      if (isdigit(toCheck[i]) == false) return false;
    }
  } else {
    for (char i : toCheck) {
      if (isdigit(i) == false) return false;  // Checks each character in the string to see if it is a digit, if it finds one that isn't, that means the string is not an integer and returns false
    }
  }
  if (stoi(toCheck) >= low && stoi(toCheck) <= high) return true;  // After confirming it is an integer, this checks if the integer is a valid number less than or equal to 50
  return false;
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


Attack CreateAttackValues(string name, int dmg, int crit, int uses, int hit){
    Attack atk;
    atk.name = name;
    atk.dmg = dmg; 
    atk.critChance = crit;
    atk.uses = uses;
    atk.maxUses = uses;
    atk.hitChance = hit;
    Blank(3);
    cout << "NAME " << atk.name;
    Blank(2);
    return atk;
}

void InitializeAttacks(){
    punch = CreateAttackValues("Punch", 4, 15, 50, 90);
    kick = CreateAttackValues("Kick", 10, 25, 15, 60);
    tailWhip = CreateAttackValues("Tail Whip", 2, 5, 3, 100);
}

void List(vector<Character> toList, bool listDead){
    for(int i = 0; i < toList.size(); i++){
            if(listDead == false && toList[i].health <= 0) continue;
            cout << i+1 << ". " << toList[i].name << " (" << toList[i].health << "/" << toList[i].maxHealth << " HP)" << endl;
        }   
}

void dmgMessage(Character attacker, Character defender, int atkUsed, double dmgDone){
    cout << attacker.atks[atkUsed].name << " from " << attacker.name << " did " << dmgDone << " damage to " << defender.name << endl;
}

bool Battle(vector<Character> attacker, vector<Character> defender, vector <string> dialogueAttacker, vector<string> dialogueDefender, void (*asciiAttacker)(), void (*asciiDefender)(), int difficulty){
    if(dev){ //Incomplete dev mode, planning to make it calculate the fastest ways to win the battle
        cout << "DEVELOPER MODE: CALCULATING TOP 3 BEST SOLUTIONS..." << endl; 
        auto startingTime = system_clock::now();
        vector<vector<string> > fastestSolutions;
        vector<int> orderedDamage;
    }
    int defenderCount = defender.size();
    int attackerCount = attacker.size();
    while(true){
        int memberDefending; int memberAttacking; int attackUsed; double dmgDone;
        Blank(2);

        bool turn; // False means NPC party is attacking, true means it is the user's turn. The NPC party will always attack first (the "attacker").
        if(turn){
            cout << "Your Party: " << endl;
            List(defender, true);
            Blank(2); Wait(2000);
            cout << "Which enemy would you like to attack? " << endl; Wait(2000);
            List(attacker, false);
            Blank(2);

            string inp; 
            while(true){
                cout << "Input one of the numbers above as the character you would like to attack: ";
                cin >> inp;
                if(isIntInRange(inp, 1, attacker.size())) break;
                else cout << "Invalid input, try again " << endl;
                if(attacker[stoi(inp)-1].health == 0) cout << "This guy's already defeated! Pick another one that's listed above!" << endl;
            }
            memberDefending = stoi(inp)-1;
            
            Blank(2); Wait(1000);
            cout << "Which party member would you like to attack with? " << endl; Wait(2000);
            List(defender, false);
            Blank(2);
            while(true){
                cout << "Input one of the numbers above as the character you would like to attack with: ";
                cin >> inp;
                if(isIntInRange(inp, 1, defender.size())) break;
                else cout << "Invalid input, try again " << endl;
                if(defender[stoi(inp)-1].health == 0) cout << "This guy's already defeated! Pick another one that's listed above!" << endl;
            }
            memberAttacking = stoi(inp)-1;
            Blank(2);
            cout << "Which attack would you like to use?" << endl; Wait(2000);
            for(int i = 0; i < defender[memberAttacking].atks.size(); i++){
                cout << i+1 << ". " << defender[memberAttacking].atks[i].name;
                cout << " (" << defender[memberAttacking].atks[i].uses << "/" << defender[memberAttacking].atks[i].maxUses << ")" << endl;
            }
            Wait(2000); Blank(2);
            while(true){
                cout << "Input one of the numbers above as the attack you would like to use: ";
                cin >> inp;
                if(isIntInRange(inp, 1, defender[memberAttacking].atks.size())) break;
                else cout << "Invalid input, try again " << endl;
                if(defender[memberAttacking].atks[stoi(inp)-1].uses == 0) cout << "You ran out of uses here... Pick another attack!" << endl;
            }
            attackUsed = stoi(inp)-1;
            dmgDone = calculateDamage(defender[memberAttacking], attacker[memberDefending], attackUsed);
        } else{
            cout << "ENEMY TURN" << endl; Wait(2000);
            cout << "Enemy Party: " << endl;
            List(attacker, true);
            memberAttacking = rand() % (attacker.size()) + 0;
            //cout << "MemAtt " << memberAttacking << endl;
            cout << attacker[memberAttacking].name << " is attacking now..." << endl; Wait(1500);
            attackUsed = rand() % (attacker[memberAttacking].atks.size()) + 0; // Need to make sure the attack has a valid number of uses, will add later
            //cout << "AttUse " << attackUsed << endl;
            memberDefending = rand() % (defender.size()) + 0;
            //cout << "MemDef " << memberDefending << endl;
            dmgDone = calculateDamage(attacker[memberAttacking], defender[memberDefending], attackUsed);
        }

        if(dmgDone == INT_MAX){
                cout << "ATTACK MISSED" << endl;
                dmgDone = 0;
            } else{
                if(dmgDone < 0){
                    cout << "CRITICAL HIT!!" << endl;
                    dmgDone = abs(dmgDone);
                } 
            }
        if(turn) {
            dmgMessage(defender[memberAttacking], attacker[memberDefending], attackUsed, dmgDone);
            if(dmgDone > attacker[memberDefending].health) dmgDone = attacker[memberDefending].health;
            attacker[memberDefending].health-=dmgDone;
            cout << attacker[memberDefending].name << " health is now " << attacker[memberDefending].health << "/" << attacker[memberDefending].maxHealth << endl;
            if(attacker[memberDefending].health == 0) {
                cout << attacker[memberDefending].name << " IS KNOCKED OUT!!" << endl;
                attackerCount--;
            }
            if(attackerCount == 0) return true;
            turn = false;
        }
        else {
            dmgMessage(attacker[memberAttacking], defender[memberDefending], attackUsed, dmgDone);
            if(dmgDone > defender[memberDefending].health) dmgDone = defender[memberDefending].health;
            defender[memberDefending].health-=dmgDone;
            cout << defender[memberDefending].name << " health is now " << defender[memberDefending].health << "/" << defender[memberDefending].maxHealth << endl;
            if(defender[memberDefending].health == 0){
                cout << defender[memberDefending].name << " IS KNOCKED OUT!!" << endl;
                defenderCount--; 
            }   
            if(defenderCount == 0) return false;
            turn = true;
        }
         
    }
    return true;
}

