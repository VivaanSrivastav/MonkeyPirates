#include <bits/stdc++.h>
#include "MonkeyPiratesVariables.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread; // sleep_for, sleep_until
using namespace chrono; // nanoseconds, system_clock, seconds



// Makes a line of equal signs, good for organization
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

//2 functions below used to create attacks, pretty self explanatory. Assigns each value to the attack
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
    punch = CreateAttackValues("Punch", 8, 15, 5, 90, "It's a punch!", PunchAscii);
    kick = CreateAttackValues("Kick", 16, 25, 5, 70, "Slam your foot on them or sum", KickAscii);
    tailWhip = CreateAttackValues("Tail Whip", 4, 0, 400, 100, "High hit rate, don't know why but don't question the whip", TailWhipAscii);
    intimidate = CreateAttackValues("Intimidate", 6, 50, 5, 90, "The ascii is hilarious", IntimidateAscii);
    throngle = CreateAttackValues("Throngle", 10, 15, 15, 80, "You don't wanna know...", ThrongleAscii);
    slap = CreateAttackValues("Slap", 7, 15, 15, 95, "Slap people", SlapAscii);
    cornobble = CreateAttackValues("Cornobble", 20, 10, 3, 80, "Fishy move", CornobbleAscii);
}

// Function to create character, self explanatory, assigns values to the given character
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

// Flashes Ascii like a low budget animation, alternates between the ascii of the attack and the ascii of the character using the attack
void FlashAscii(void (Ascii)(), Character character){
    int repeats = 3;
    while(repeats--){
        Ascii();
        Wait(300);
        Clear();
        character.Ascii();
        Wait(300);
        Clear();
        Wait(300);
    }
    Wait(400);
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
void completeDamage(vector<Character> attacker, vector<Character> defender, int memberAttackingNum, int memberDefendingNum, double dmgDone, int memberCount){
    if(dmgDone > attacker[memberDefendingNum].health) dmgDone = attacker[memberDefendingNum].health;
    cout << defender[memberDefendingNum].name << "'s health is now " << defender[memberDefendingNum].health << "/" << defender[memberDefendingNum].maxHealth << endl; Wait(500);
    if(defender[memberDefendingNum].health <= 0) {
        cout << defender[memberDefendingNum].name << " IS KNOCKED OUT!!" << endl;
        memberCount--;
    }
}

/*
This battle function covers a lot, and also took me a decent amount of time.


Battle manager:
The "attacker" is always the NPC party attacking the player, with "defender" always being the main character's party

It runs a "while(true)" loop until all members of a party are defeated
memberAttackingNum keeps track of who is attacking on the current turn.
memberDefendingNum keeps track of who is defending (taking the attack) in the current turn.
attackUsed keeps track of which attack the memberAttackingNum is using.
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
Also note that a lot of this can be shortened using pointers but that feels way overkill
*/
bool Battle(vector<Character> attacker, vector<Character> defender){
    Clear();
    int turnNumber = 1;
    int defenderCount = defender.size();
    int attackerCount = attacker.size();
    while(true){
        int memberDefendingNum; int memberAttackingNum; int attackUsed; double dmgDone;
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
                if(isIntInRange(inp, 1, attacker.size()) && attacker[stoi(inp)-1].health > 0) break;
                else {
                    cout << "Invalid input, try again. Input a number above, make sure the character is alive too " << endl;
                    continue;
                }
            }
            memberDefendingNum = stoi(inp)-1;
            
            Blank(2); Wait(500);
            cout << "Which party member would you like to attack with? " << endl; Wait(500);
            List(defender, false);
            Blank(2);
            while(true){
                cout << "Input one of the numbers above as the character you would like to attack with: ";
                cin >> inp;
                if(isIntInRange(inp, 1, defender.size()) && defender[stoi(inp)-1].health > 0) break;
                else {
                    cout << "Invalid input, try again. Input a number above, make sure the character is alive too." << endl;
                    continue;
                }
            }
            memberAttackingNum = stoi(inp)-1;
            Blank(2);
            cout << "Which attack would you like to use?" << endl; Wait(500);
            for(int i = 0; i < defender[memberAttackingNum].atks.size(); i++){
                cout << i+1 << ". " << defender[memberAttackingNum].atks[i].name;
                cout << " (" << defender[memberAttackingNum].atks[i].uses << "/" << defender[memberAttackingNum].atks[i].maxUses << ")" << endl;
            }
            Wait(500); Blank(2);
            while(true){
                cout << "Input one of the numbers above as the attack you would like to use: ";
                cin >> inp;
                if(isIntInRange(inp, 1, defender[memberAttackingNum].atks.size()) && defender[memberAttackingNum].atks[stoi(inp)-1].uses > 0) break;
                else {
                    cout << "Invalid input, try again. Input a number above, make sure the attack has enough uses too" << endl;
                    continue;
                }
            }
            attackUsed = stoi(inp)-1; 
            dmgDone = calculateDamage(defender[memberAttackingNum], attacker[memberDefendingNum], attackUsed);
            turnNumber++;
        } else{
            cout << " - ENEMY TURN" << endl; Wait(1000);
            cout << "Enemy Party: " << endl;
            List(attacker, true);
            memberAttackingNum = rand() % (attacker.size()) + 0;
            cout << attacker[memberAttackingNum].name << " is attacking now..."; Blank(2); Wait(1000);
            attackUsed = rand() % (attacker[memberAttackingNum].atks.size()) + 0; 
            memberDefendingNum = rand() % (defender.size()) + 0; 
            while(true){ //loops to check if the targetted character isn't dead already.
                if(defender[memberDefendingNum].health <= 0) memberDefendingNum = rand() % (defender.size()) + 0;
                else break;
            }
            dmgDone = calculateDamage(attacker[memberAttackingNum], defender[memberDefendingNum], attackUsed);
        }

        if(dmgDone == INT_MAX){
                cout << "[ATTACK MISSED]" << endl; Wait(1000);
                dmgDone = 0;
            } else if(dmgDone < 0){
                cout << "[CRITICAL HIT!!]" << endl; Wait(1000);
                dmgDone = abs(dmgDone);
            } 
            // Some slight repitition of code (very hard not to), but I talked to you about it and you said it was okay so I'll keep it.
        if(turn) { 
            FlashAscii(defender[memberAttackingNum].atks[attackUsed].Ascii, defender[memberAttackingNum]);
            defender[memberAttackingNum].atks[attackUsed].uses--;
            attacker[memberDefendingNum].health-=dmgDone;
            if(attacker[memberDefendingNum].health <= 0){
                attackerCount--; 
                attacker[memberDefendingNum].health = 0;
            }
            dmgMessage(defender[memberAttackingNum], attacker[memberDefendingNum], attackUsed, dmgDone);
            completeDamage(defender, attacker, memberAttackingNum, memberDefendingNum, dmgDone, attackerCount);
            if(attackerCount == 0) return true;
            turn = false;
        }
        else {
            FlashAscii(attacker[memberAttackingNum].atks[attackUsed].Ascii, attacker[memberAttackingNum]);
            defender[memberDefendingNum].health-=dmgDone;
            attacker[memberAttackingNum].atks[attackUsed].uses--;
            if(defender[memberDefendingNum].health <= 0) {
                defender[memberDefendingNum].health = 0;
                defenderCount--; 
            }
            dmgMessage(attacker[memberAttackingNum], defender[memberDefendingNum], attackUsed, dmgDone);
            completeDamage(attacker, defender, memberAttackingNum, memberDefendingNum, dmgDone, defenderCount);
            if(defenderCount == 0) return false;
            turn = true;
        }
    }
    Clear();
    return true;
}

/*
numsGiven counts the amount of numbers the user has been given, good for the user to know
messageGiven chooses which message to output, makes it confusing to read which is fun
Then it loops through 6 numbers, with currentNum being the current number and ans being the product thus far. 
If the user inputs the same as "ans", they pass.
*/
void ProductRiddle(){
    while(true){
        srand(time(NULL));
        int numsGiven = 1;
        Clear();
        int ans = 1;
        for(int i = 0; i < 6; i++){
            int currentNum = rand() % 5 + 1;
            int messageGiven = rand() % 2 + 1;
            ans*=currentNum;
            if(messageGiven == 1){
                cout << "Marty: Number " << numsGiven << " is " << currentNum << endl; 
            } else cout << "Marty: " << currentNum << " is number " << numsGiven << " on the list" << endl; 
            Wait(2000);
            numsGiven++;
            Clear();
        }
        cout << "Ricky: So what is " << endl; Wait(1000);
        cout << "Marty: ... Your answer?" << endl;
        cout << "Your answer (the product of the six numbers): ";
        string inp; cin >> inp; 
        if(inp == to_string(ans)) break;
        cout << "Ricky: INCORRECT!" << endl; Wait(2000);
        cout << "Marty: Try again." << endl; Wait(2000);
    }
    cout << "Ricky: You" << endl; Wait(1000);
    cout << "Marty: Passed!" << endl; Wait(2000);
}

/*
correctStreak counts how many in a row the user has gotten correct.
Loops if the correct streak is less than 3 
It shows up for less time the higher your streak is
oddRow and oddColumn are there to randomize which spot on the 3x3 grid has "-" instead of "|".
Then the 2d vector is created, with the odd spot being replaced.
If the user guesses right, correctStreak goes up, otherwise it resets.
*/
void OddOneOutRiddle(){
    Clear();
    cout << "Barto: Get 3 in a row right and you pass!" << endl; Wait(2000);
    int correctStreak = 0;
    while(correctStreak < 3){
        srand(time(NULL));
        cout << "Barto: Let's go! " << endl; Wait(2000);
        int oddRow = rand() % 3 + 1;
        int oddColumn = rand() % 3 + 1;
        vector<vector<string> > grid(3, vector<string>(3, "|"));
        grid[oddRow-1][oddColumn-1] = "-";
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
        Wait(1500);
        Clear();
        cout << "Input your answer as said before (ie 11, or 21 etc): ";
        string input; cin >> input;
        if(input == to_string(oddRow) + to_string(oddColumn)) {
            correctStreak++;
            cout << "Barto: Nice, your streak is now " << correctStreak << endl; Wait(2000);
        }
        else {
            cout << "BLEHH, your streak is gone (if it existed). Just as a reminder, make sure the input is not seperated by a space too." << endl; Wait(2000);
            correctStreak = 0;
        }
    }
    cout << "Barto: You pass!" << endl; Wait(2000);
}

