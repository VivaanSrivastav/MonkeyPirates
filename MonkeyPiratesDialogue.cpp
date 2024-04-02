#include <bits/stdc++.h>
#include "MonkeyPiratesVariables.h"

using namespace std;

//Introductory sequence, most done her is getting the player's name and initializing their basic stats.
void IntroSequence(){
    Blank(2);
    IntroText(); Blank(1);  Wait(1000);
    cout << "By Vivaan Srivastav" << endl;
    IntroAscii(); Blank(3);  Wait(4000);
    Clear();
    Wait(2000);
    cout << "(Voices in front of you, you are unable to see)" << endl;
    cout << "Voice 1: Hey! Hey! Hey! Ok you're awake" << endl;  Wait(2500);
    cout << "Voice 2: No he's not, idiot" << endl;  Wait(2500);
    cout << "Voice 1: Ok I'll remove his blindfold look" << endl;  Wait(2000);
    cout << "(Your blindfold is removed)" << endl;  Wait(3000);
    Brack();
    Blank(2);  Wait(2500);
    cout << "Voice 2: I already knew that... I was testing you." << endl;  Wait(3000);
    cout << "Voice 1: What's your name chump?" << endl << "Type your name in one line: " << endl;

    string name;
    while(true) { // Getting name of player
        getline(cin, name);
        cout << endl;
        Wait(1000);
        if(name.length() > 20) cout << "Voice 1: TOO LONG! Give another name CHUMP" << endl << "Type your name in one line(<=20 characters): ";
        else break;
    }
    // Initializing player
    vector<Attack> playerAttacks;
    playerAttacks.push_back(punch); playerAttacks.push_back(kick); playerAttacks.push_back(tailWhip);
    Character player = CreateCharacter(name, "Lost", 100, 100, 20, 5, 10, playerAttacks, SittingMonkey);
    party.push_back(player);

    cout << "Voice 1: OK \"" << player.name << "\", if that really is your name CHUMP, my name is Brack" << endl;  Wait(3000);
    cout << "Voice 2: I won't give my name to such a lowly captured pirate, you have to earn it!" << endl;  Wait(3000);
    cout << "Brack: Smart move Harith! I should follow after you! Forget what my name was you pirate!" << endl;  Wait(3000);
    cout << "Harith: You idiot! Excuse us for a moment, please do not touch any suspiciously and conveniently placed sharp objects." << endl;  Wait(4000);
    cout << "(Harith drags Brack out the room, suprising considering he's half the size of him)" << endl;  Wait(3000);
    Blank(2);
    AngryHarith();  Wait(3000);
    cout << "(Door slams shut)" << endl;  Wait(2000);
    Door();
    Wait(2000); Clear();
}

// This is the "a" path to the IntroSequence2() function, where the user fights Brack
void IntroSequencePath1(){
        vector<Attack> brackAttacks;
        brackAttacks.push_back(punch); brackAttacks.push_back(kick);
        Character brackCharacter = CreateCharacter("Brack", "Lost", 60, 100, 30, 0, 0, brackAttacks, Brack);
        vector <Character> tempBrackParty; tempBrackParty.push_back(brackCharacter);
        //This battle is impossible to lose
        BattleTime();
        if(Battle(tempBrackParty, party)) BattleWon();
        Clear();
        Wait(3000);
        Blank(3);
        cout << "Brack: Maybe...I panicked too much. DONT HURT ME MORE PLEASE" << endl;  Wait(2000);
        cout << "You: I'm heading out" << endl;  Wait(2000);
        cout << "Brack: ..." << endl;  Wait(2000);
        cout << "Brack: TAKE ME WITH YOU" << endl;  Wait(2000);
        cout << "You: ???" << endl;  Wait(2000);
        cout << "Brack: I don't like it here...." << endl;  Wait(2000);
        BrackFace(); Blank(1);
        cout << "You: Fine. Let's find a way out" << endl; Wait(2000);
        cout << "NEW PARTY MEMBER: BRACK" << endl;
        brackCharacter = CreateCharacter("Brack", "Dumb", 80, 100, 30, 10, 5.5, brackAttacks, Brack);
        party.push_back(brackCharacter);
        Clear();
}

// This is the "b" path to the IntroSequence2() function, where the user fights Harith with Brack
void IntroSequencePath2(){
    cout << "(Harith enters the room)" << endl; Wait(2000);
    cout << "Harith: WHATS GOING ON HERE??" << endl; Wait(2000);
    vector<Attack> brackAttacks;
    brackAttacks.push_back(punch); brackAttacks.push_back(kick);
    Character brackCharacter = CreateCharacter("Brack", "Dumb", 80, 100, 30, 10, 5.5, brackAttacks, Brack);
    party.push_back(brackCharacter);
    vector<Attack> harithAttacks;
    harithAttacks.push_back(intimidate); 
    //Impossible to lose
    Character harithCharacter = CreateCharacter("Harith", "Meanie", 75, 100, 10, 0, 0, harithAttacks, AngryHarith);
    vector <Character> tempEnemyParty; tempEnemyParty.push_back(harithCharacter);
    BattleTime();
    if(Battle(tempEnemyParty, party)) BattleWon();
    cout << "(Harith passes out)" << endl; Wait(2000);
    cout << "You: OK let's leave" << endl; Wait(2000);
    cout << "Brack: I agree... " << endl; Wait(2000);
}

// Here the user selects which path to go down, at the end the result is the same, Brack joins.
void IntroSequence2(){
    Blank(2);
    
    cout << "(Your arms are tied but you feel a conveniently placed sharp screw near your hand)" << endl;  Wait(2500);
    cout << "You have 2 choices: " << endl;  Wait(2500);
    cout << "a. Do nothing and  Wait patiently" << endl;  Wait(2000);
    cout << "b. Use the screw to attempt the cut the rope that's holding you" << endl;  Wait(2000);  
    cout << "Input your decision (a or b): ";

    while(true){
        string inp; cin >> inp;
        for(int i = 0; i < inp.size(); i++) inp[i] = tolower(inp[i]);
        if(inp != "a" && inp != "b") {
            cout << endl << "Input only a or b: ";
            continue;
        }
        else if (inp == "a"){
            cout << "(You wait patiently, after a minute Brack comes back into the room alone)" << endl;  Wait(2000);
            cout << "Brack: I always hated that guy, he's moody but he'll calm down later" << endl;  Wait(2000);
            cout << "Brack: How did you end up here anyway?" << endl;  Wait(2000);
            cout << "You: I...don't remember" << endl;  Wait(2000);
            cout << "Brack: Playing dumb? Whatever. Eventually I'll figure it out" << endl;  Wait(2000);
            cout << "(You very much do not remember)" << endl;  Wait(2000);
            cout << "Brack: I always wanted to leave this place, this crew is mean" << endl;  Wait(2000);
            cout << "Brack: How about this, I break you out of those ropes, we beat up Harith and then escape!" << endl;  Wait(3000);
            BrackFace();  Wait(2500); Blank(1);
            cout << "(Brack uses his nails to cut the rope, you are free)" << endl;  Wait(2000);
            cout << "Brack: Here's a mirror to see what you look like" << endl;  Wait(2000);
            cout << "(Brack pulls out a mirror)" << endl;  Wait(2000);
            SittingMonkey();
            Blank(2);
            IntroSequencePath2();
            break;
        }
        else {
            cout << "(You use the screw to cut your restraints)" << endl;  Wait(2000);
            cout << "(You hear the door unlock)" << endl;  Wait(3000);
            cout << "(Brack is back)" << endl;
            BrackHead();  Wait(3000);
            Blank(1);
            cout << "Brack: HEY WHAT ARE YOU DOING PRISONER GUY LETS FIGHT" << endl;  Wait(2000);
            cout << "You:  Wait  Wait  Wait" << endl;  Wait(2500);
            cout << "Brack: AAAAAA" << endl;  Wait(2000);
            IntroSequencePath1();
            break;
        }
    }
    cout << "NEW MOVE \"INTIMIDATE\" LEARNED FOR " << party[0].name << endl; Wait(2000);
    cout << "NEW MOVE \"THRONGLE\" LEARNED FOR BRACK" << endl; Wait(1500);
    party[0].atks.push_back(intimidate);
    party[1].atks.push_back(throngle);
}

// Here the user meets Ricky and Marty, first the ProductRiddle() is called for the riddle, then they have a battle, with the twins being iniitialized.
void Task2(){
    Clear();
    cout << "(You and Brack travel to another room)" << endl; Wait(2000);
    cout << "Brack: CRAP! It's Ricky and Marty! Those twins don't let you by if you don't answer their dumb riddle!" << endl; Wait(2000);
    cout << "Ricky: Well well well Brack!" << endl; Wait(2000);
    cout << "Marty: And... I don't know who" << endl; Wait(2000);
    cout << "Ricky: Here's our riddle for today! Marty will give you 5 numbers and you must tell us the product of them combined!" << endl; Wait(4000);
    cout << "Marty: Let's go!" << endl; Wait(2000);
    ProductRiddle();
    Clear(); Wait(2000);
    cout << "Ricky: Now that I think about it... who is that other guy, Brack?" << endl; Wait(2000);
    cout << "Marty: Hmmm" << endl; Wait(2000);
    cout << "Ricky: GET THEM, THAT'S THE PRISONER! BRACK YOU TRAITOR" << endl; Wait(2000);
    vector<Character> saveParty = party; // Saves the current state, so if the following battle is lost, the user can restart as if nothing happened
    while(true){
        party = saveParty;
        vector<Attack> TwinAttacks;
        vector<Character> tempBattleVector;
        TwinAttacks.push_back(intimidate); TwinAttacks.push_back(slap);  TwinAttacks.push_back(throngle); TwinAttacks.push_back(kick);
        Character RickyCharacter = CreateCharacter("Ricky", "Twin 1", 70, 70, 20, 8, 8, TwinAttacks, Ricky); // Initializing values
        Character MartyCharacter = CreateCharacter("Marty", "Twin 2", 70, 70, 30, 5, 8, TwinAttacks, Marty); 
        tempBattleVector.push_back(RickyCharacter); tempBattleVector.push_back(MartyCharacter);
        if(Battle(tempBattleVector, party)) {
            BattleWon();
            break;
        }
        BattleLost();
        cout << "Restarting battle... Win this time you loser" << endl; Wait(2000); // If they lose, the loop continues
    }
    cout << "(Ricky passes out)" << endl; Wait(2000);
    vector<Attack> TwinAttacks;
    TwinAttacks.push_back(intimidate); TwinAttacks.push_back(slap);  TwinAttacks.push_back(throngle); TwinAttacks.push_back(kick);
    Character MartyCharacter = CreateCharacter("Marty", "Twin 2", 70, 70, 20, 5, 8, TwinAttacks, Marty);
    cout << "Marty: WAIT WAIT" << endl; Wait(2000);
    cout << "Brack: What??" << endl; Wait(2000);
    cout << "Marty: Can I know what's going on?" << endl; Wait(2000);
    cout << "You: We're escaping" << endl; Wait(2000);
    cout << "Marty: Can I come with...?" << endl; Wait(2000);
    cout << "Brack: ..." << endl; Wait(2000);
    cout << "You: Ok.. Sure" << endl; Wait(2000);
    cout << "All 3 of you leave the current room and head towards the escape boats" << endl;
}

// Final sequence with Barto's test to see if the user can spot the fake. It calls "OddOneOutRiddle", when the user wins then the game ends.
void Task3(){
    Clear();
    cout << "All 3 of you go to the spare boat lounge" << endl; Wait(2000);
    cout << "Brack: OH NO" << endl; Wait(2000);
    cout << "Marty: It's Barto and his goons... They usually hang here watching the boats. " << endl; Wait(3000);
    cout << "You: Who?" << endl; Wait(2000);
    cout << "Barto: HEY HEY HEY YOU GUYS BRACK AND MARTY" << endl;
    cout << "Brack: Ruh oh" << endl; Wait(2000);
    cout << "Barto: Looks like you guys can't spot that guy you're walking with! He's not a part of our crew!" << endl; Wait(3000);
    cout << "Brack: Yes he is, he's new!!" << endl; Wait(2000);
    cout << "Barto: If you're so good at spotting fakes, look at my 4 goons line up! Tell me which one looks off!" << endl; Wait(3000);
    cout << "Instructions: Look at the grid and point out which character is the odd one out, in the form of a grid coordinate" << endl; Wait(4000);
    cout << "1 1" << endl << "2 1" << endl << "In the above example, the correct answer would be \"12\", as it is in row 1, column 2" << endl; Wait(6000);
    Clear();
    OddOneOutRiddle();
    Clear();

    cout << "Barto: Seems I misunderstood, you may pass..." << endl; Wait(2000);
    Barto(); Wait(2000);
    cout << "You, Brack, and Marty decide to take a boat and sail away... THE END" << endl; Wait(2000);
}


