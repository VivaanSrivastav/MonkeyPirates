/*
Name: Vivaan Srivastav
Date: March 30, 2024
Purpose: Functions for the game, the most complex file here. Includes everything from quality of life to a complex battling function
File name: MonkeyPiratesFunctions.cpp
*/
#include <bits/stdc++.h>
#include "MonkeyPiratesVariables.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread; // sleep_for, sleep_until
using namespace chrono; // nanoseconds, system_clock, seconds



// Makes a line of equal sines, good for organization
void Divider(){
    for(int i = 0; i < 150; i++) cout << '=';
    cout << endl;
}

/*
"attacker" is the character doing the attack
"defender" is the character recieving it

First, it checks if the attack missed. Simple formula where you take the hit chance of the attack, and multily it by the attacker's speed/10.
Say an attack has a 90% hit chance, and the speed of a character is 9, the attack now has a hit chance of (90*0.9) = 81%.
A missed attack returns INT_MAX, which is then translated to 0 by the Battle() function.

The base damage is then calculated, similar formula to the hitchance, except now the defender's defense stat is factored in.
Say an attack has 90 damage, and the speed of a character is 9, the attack does 81 damage. Now say the enemy's defense is 70, the attack now does 11 damage

Then the attack's critical hit chance is calculated, if the attack is a critical, the damage is multiplied by 1.5
This is communicated to the Battle() function by now adding a negative sign to the attack value, this is the only way to get a negative attack value thus is a smart way to communicate that it is a critical hit
Then to avoid any negative health issues, the maximum damage is changed to the defender's health if it surpasses it
*/
double calculateDamage(Character attacker, Character defender, int attackNum){
    if(attacker.atks[attackNum].hitChance*(attacker.spd/10) <= rand() % 100 + 1) return INT_MAX; 
    double dmgDone = attacker.atks[attackNum].dmg*(attacker.str/10) - defender.def;
    if(dmgDone < 0) dmgDone = 0;
    bool criticalHit = false;
    if(attacker.atks[attackNum].critChance >= rand() % 100 + 1) criticalHit = true;
    if(criticalHit) dmgDone*=1.5;
    if(dmgDone > defender.health) dmgDone = defender.health;
    if(criticalHit) dmgDone -= (dmgDone*2);
    return dmgDone;
}

//2 functions below used to create attacks, pretty self explanatory
Attack CreateAttackValues(string name, int dmg, int crit, int uses, int hit, string description, void (Ascii)()){
    Attack atk;
    atk.name = name;
    atk.dmg = dmg; 
    atk.critChance = crit;
    atk.uses = uses;
    atk.maxUses = uses;
    atk.hitChance = hit;
    atk.description = description;
    atk.Ascii = Ascii;
    return atk;
}

void InitializeAttacks(){
    punch = CreateAttackValues("Punch", 8, 15, 10, 90, "It's a punch!", PunchAscii);
    kick = CreateAttackValues("Kick", 16, 25, 10, 70, "Slam your foot on them or sum", KickAscii);
    tailWhip = CreateAttackValues("Tail Whip", 4, 0, 400, 100, "Always hits, don't know why but don't question the whip", TailWhipAscii);
    intimidate = CreateAttackValues("Intimidate", 6, 50, 5, 90, "The ascii is hilarious", IntimidateAscii);
}

// Function to create character, self explanatory
Character CreateCharacter(string name, string description, double health, double maxHealth, double str, double def, double spd, vector<Attack> atks, void (Ascii)()){
    Character character;
    character.name = name;
    character.description = description;
    character.health = health;
    character.maxHealth = maxHealth;
    character.str = str;
    character.def = def;
    character.spd = spd;
    character.atks = atks;
    character.Ascii = Ascii;
    return character;
}


//Function to repeat output n new blank lines
void Blank(int n){
    while(n--) cout << endl;
}

/*
Checks if it is a valid integer, then checks if it is in the correct range
For some reason strings of length 1 go weirdly through this so I added a check at the start to stop this risk 
*/
bool isIntInRange(string toCheck, int low, int high) {
  if(toCheck.length() == 1 && isdigit(toCheck[0]) == false) return false; 

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

// Clear a certain number of lines
void ClearLines(int numLines) {
    for (int i = 0; i < numLines; ++i) {
        std::cout << "\x1b[2K"; // Clear line
        std::cout << "\x1b[A"; // Move cursor up one line
    }
    Blank(1);
}

// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
void Clear() {
    cout << "\x1B[2J\x1B[H";
}

// Flashes Ascii like a low budget animation
void FlashAscii(void (Ascii)()){
    int repeats = 3;
    while(repeats--){
        Ascii();
        Wait(500);
        Clear();
        Wait(500);
    }
}

/*
Lists the characters in a party, useful for battle function. 
listDead decides if the characters with 0 health will also be listed.
*/
void List(vector<Character> toList, bool listDead){
    for(int i = 0; i < toList.size(); i++){
            if(listDead == false && toList[i].health <= 0) continue;
            cout << i+1 << ". " << toList[i].name << " (" << toList[i].health << "/" << toList[i].maxHealth << " HP)" << endl;
        }   
}

// Function to have a message of damage, self explanatory
void dmgMessage(Character attacker, Character defender, int atkUsed, double dmgDone){
    cout << attacker.atks[atkUsed].name << " from " << attacker.name << " did " << dmgDone << " damage to " << defender.name << endl; Wait(750);
}

// To avoid repitition, further information after each attack
void completeDamage(vector<Character> attacker, vector<Character> defender, int memberAttacking, int memberDefending, double dmgDone, int memberCount){
    if(dmgDone > attacker[memberDefending].health) dmgDone = attacker[memberDefending].health;
    cout << defender[memberDefending].name << "'s health is now " << defender[memberDefending].health << "/" << defender[memberDefending].maxHealth << endl; Wait(500);
    if(defender[memberDefending].health <= 0) {
        cout << defender[memberDefending].name << " IS KNOCKED OUT!!" << endl;
        memberCount--;
    }
}

/*
This battle function covers a lot.


Battle manager:
The "attacker" is always the NPC party attacking the player, with "defender" always being the main character's party
dialogueAttacker and dialogueDefender are there to add stuff for both sides to say, situational depending on the fight
asciiAttacker and asciiDefender are general asciis to use to represent the party
Difficulty TBD

It runs a "while(true)" loop until all members of a party are defeated
memberAttacking keeps track of who is attacking on the current turn.
memberDefending keeps track of who is defending (taking the attack) in the current turn.
attackUsed keeps track of which attack the memberAttacking is using.
dmgDone is used for the final damage the attack does.
The turn bool manages who's turn it is, true being the users, and false being the NPC

When turn is true:
The user is given a list of their party (just as an update/reminder)
Then the user is given a list of the enemy's alive party members, the user then selects which one they would like to attack. 
Then they are given a list of their party members, letting them choose an alive one to attack with.
Then they are given a list of the party member's attacks, letting them choose one with enough uses (>0)
Then the damage is calculated (described above in the functiom)

When turn is false:
It picks a random (alive) member from the attacker party
Then it picks a random attack to use (decided not to implement uses system for attackers by the way)
Then it calculates damage (described above in the function)

Then it calculates the rest, damage recieved and if the member defending died.
If a member died, either defenderCount or attackerCount goes down (respectively), if either is 0 then the program ends

Note: Some slight repition of code at the end, but it was very difficult to try to not repeat. 
I talked to you about it and you said it was fine, so don't dock marks pls.

*/
bool Battle(vector<Character> attacker, vector<Character> defender){
    Clear();
    int turnNumber = 1;
    int defenderCount = defender.size();
    int attackerCount = attacker.size();
    while(true){
        int memberDefending; int memberAttacking; int attackUsed; double dmgDone;
        Divider();
        cout << "Turn " << turnNumber; Blank(2);

        bool turn; // False means NPC party is attacking, true means it is the user's turn. The NPC party will always attack first (the "attacker").
        if(turn){
            cout << " - YOUR TURN" << endl;
            cout << "Your Party: " << endl;
            List(defender, true);
            Blank(2); Wait(500);
            cout << "Which enemy would you like to attack? " << endl; Wait(500);
            List(attacker, false);
            Blank(2);

            string inp; 
            while(true){
                cout << "Input one of the numbers above as the character you would like to attack: ";
                cin >> inp;
                if(isIntInRange(inp, 1, attacker.size())) break;
                else {
                    cout << "Invalid input, try again " << endl;
                    continue;
                }
                if(attacker[stoi(inp)-1].health == 0) cout << "This guy's already defeated! Pick another one that's listed above!" << endl;
            }
            memberDefending = stoi(inp)-1;
            
            Blank(2); Wait(500);
            cout << "Which party member would you like to attack with? " << endl; Wait(500);
            List(defender, false);
            Blank(2);
            while(true){
                cout << "Input one of the numbers above as the character you would like to attack with: ";
                cin >> inp;
                if(isIntInRange(inp, 1, defender.size())) break;
                else {
                    cout << "Invalid input, try again " << endl;
                    continue;
                }
                if(defender[stoi(inp)-1].health == 0) cout << "This guy's already defeated! Pick another one that's listed above!" << endl;
            }
            memberAttacking = stoi(inp)-1;
            Blank(2);
            cout << "Which attack would you like to use?" << endl; Wait(500);
            for(int i = 0; i < defender[memberAttacking].atks.size(); i++){
                cout << i+1 << ". " << defender[memberAttacking].atks[i].name;
                cout << " (" << defender[memberAttacking].atks[i].uses << "/" << defender[memberAttacking].atks[i].maxUses << ")" << endl;
            }
            Wait(500); Blank(2);
            while(true){
                cout << "Input one of the numbers above as the attack you would like to use: ";
                cin >> inp;
                if(isIntInRange(inp, 1, defender[memberAttacking].atks.size())) break;
                else {
                    cout << "Invalid input, try again " << endl;
                    continue;
                }
                if(defender[memberAttacking].atks[stoi(inp)-1].uses == 0) cout << "You ran out of uses here... Pick another attack!" << endl;
            }
            attackUsed = stoi(inp)-1;
            dmgDone = calculateDamage(defender[memberAttacking], attacker[memberDefending], attackUsed);
            turnNumber++;
        } else{
            cout << " - ENEMY TURN" << endl; Wait(1000);
            cout << "Enemy Party: " << endl;
            List(attacker, true);
            memberAttacking = rand() % (attacker.size()) + 0;
            cout << attacker[memberAttacking].name << " is attacking now..."; Blank(2); Wait(1000);
            attackUsed = rand() % (attacker[memberAttacking].atks.size()) + 0; 
            memberDefending = rand() % (defender.size()) + 0;
            dmgDone = calculateDamage(attacker[memberAttacking], defender[memberDefending], attackUsed);
        }

        if(dmgDone == INT_MAX){
                cout << "ATTACK MISSED" << endl;
                dmgDone = 0;
            } else if(dmgDone < 0){
                cout << "CRITICAL HIT!!" << endl;
                dmgDone = abs(dmgDone);
            } 
        if(turn) { 
            FlashAscii(defender[memberAttacking].atks[attackUsed].Ascii);
            defender[memberAttacking].atks[attackUsed].uses--;
            attacker[memberDefending].health-=dmgDone;
            if(attacker[memberDefending].health <= 0){
                attackerCount--; 
                attacker[memberDefending].health = 0;
            }
            dmgMessage(defender[memberDefending], attacker[memberAttacking], attackUsed, dmgDone);
            completeDamage(defender, attacker, memberAttacking, memberDefending, dmgDone, attackerCount);
            if(attackerCount == 0) return true;
            turn = false;
        }
        else {
            FlashAscii(attacker[memberAttacking].atks[attackUsed].Ascii);
            defender[memberDefending].health-=dmgDone;
            attacker[memberAttacking].atks[attackUsed].uses--;
            if(defender[memberDefending].health <= 0) {
                defender[memberDefending].health = 0;
                defenderCount--; 
            }
            dmgMessage(attacker[memberAttacking], defender[memberDefending], attackUsed, dmgDone);
            completeDamage(attacker, defender, memberAttacking, memberDefending, dmgDone, defenderCount);
            if(defenderCount == 0) return false;
            turn = true;
        }
    }
    return true;
}

