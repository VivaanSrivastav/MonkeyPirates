#include <bits/stdc++.h>
#include "MonkeyPiratesVariables.h"

using namespace std;

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
    while(true) {
        getline(cin, name);
        cout << endl;
        Wait(1000);
        if(name.length() > 20) cout << "Voice 1: TOO LONG! Give another name CHUMP" << endl << "Type your name in one line(<=20 characters): ";
        else break;
    }
    Character player;

    player.name = name; player.health = 100; player.description = "You, lost and no memory"; player.str = 30; player.def = 10; player.spd = 10; player.maxHealth = 100;
    player.atks.push_back(punch); player.atks.push_back(tailWhip);
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

void IntroSequencePath1(){
        Character brackCharacter; brackCharacter.name = "Brack"; brackCharacter.health = 70; brackCharacter.str = 50; brackCharacter.spd = 0; brackCharacter.description = "Little stupid but has the right spirit, wants to sail the 7 seas"; brackCharacter.def = 5; brackCharacter.maxHealth = 100;
        brackCharacter.atks.push_back(punch); brackCharacter.atks.push_back(tailWhip);
        vector <Character> tempBrackParty; tempBrackParty.push_back(brackCharacter);
        BattleTime();
        if(Battle(tempBrackParty, party)) BattleWon();
        Clear();
        Wait(3000);
        Blank(3);
        cout << "NEW MOVE \"INTIMIDATE\" LEARNED FOR " << party[0].name << endl; Wait(1000);
        party[0].atks.push_back(intimidate);
        cout << "Brack: Maybe...I panicked too much. DONT HURT ME MORE PLEASE" << endl;  Wait(2000);
        cout << "You: I'm heading out" << endl;  Wait(2000);
        cout << "Brack: ..." << endl;  Wait(2000);
        cout << "Brack: TAKE ME WITH YOU" << endl;  Wait(2000);
        cout << "You: ???" << endl;  Wait(2000);
        cout << "Brack: I don't like it here...." << endl;  Wait(2000);
        BrackFace(); Blank(1);
        cout << "You: Fine. Let's find a way out" << endl;
        
}

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
            cout << "(You  Wait patiently, after a minute Brack comes back into the room alone)" << endl;  Wait(2000);
            cout << "Brack: I always hated that guy, he's moody but he'll calm down later" << endl;  Wait(2000);
            cout << "Brack: How did you end up here anyway?" << endl;  Wait(2000);
            cout << "You: I...don't remember" << endl;  Wait(2000);
            cout << "Brack: Playing dumb? Whatever. Eventually I'll figure it out" << endl;  Wait(2000);
            cout << "(You very much do not remember)" << endl;  Wait(2000);
            cout << "Brack: I always wanted to leave this place, this crew is mean" << endl;  Wait(2000);
            cout << "Brack: How about this, I break you out of those ropes, we beat up Marith and then take a small boat to escape!";  Wait(3000);
            BrackFace();  Wait(2500); Blank(1);
            cout << "(Brack uses his nails to cut the rope, you are free)" << endl;  Wait(2000);
            cout << "Brack: Here's a mirror to see what you look like" << endl;  Wait(2000);
            cout << "(Brack pulls out a mirror)" << endl;  Wait(2000);
            SittingMonkey();
            
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
        }
    }
}

