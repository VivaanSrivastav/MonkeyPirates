/*
Name: Vivaan Srivastav
Date: March 30, 2024
Purpose: Main file for the game, runs functions from the MonkeyPiratesDialogue.cpp file. 
This is a game where you play a captured pirate, and decide you need to escape.
File name: MonkeyPirates.cpp
*/

#include <bits/stdc++.h>
#include "MonkeyPiratesAttackAscii.cpp"
#include "MonkeyPiratesVariables.h"
#include "MonkeyPiratesFunctions.cpp"
#include "MonkeyPiratesAscii.cpp"
#include "MonkeyPiratesDialogue.cpp"

using namespace std;

int main(){
    InitializeAttacks(); // Makes all the attacks

    while(true){
        // Task 1, first battles
        IntroSequence();    
        IntroSequence2();
    
        // Task 2, second battle with Ricky and Marty
        Task2();
        // Task 3, final task with Barto
        Task3();
        // Asking input to play again, if they do then it resets the party.
        cout << "Play again? (input y or n)" << endl;
        bool playAgain;
        while (true)
        {
            string input; cin >> input;
            if(input == "y") {
                cout << "Restarting.... " << endl;
                Clear();
                playAgain = true;
                break;
            } else if(input == "n") {
                cout << "Cya!" << endl;
                break;
            } else cout << "Invalid input! Input y or n:" << endl;
        }
        if(playAgain) party.clear();
        else break;
    }
}