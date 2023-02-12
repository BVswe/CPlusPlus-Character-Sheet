// C++ Character Sheet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "CRUD.h"
#include <iostream>
#include <sstream>
#include <tuple>

using namespace std;

bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

int main()
{
    while (true) {
        string choice;
        cout << "What would you like to do?" << endl;
        cout << "1. Create character" << endl;
        cout << "2. View character" << endl;
        cout << "3. Edit character" << endl;
        cout << "4. Delete character" << endl;
        getline(cin, choice);
        if (choice == "1") {
            string name;
            string level;
            map<string, string> spells, abilities;
            struct stat buffer;

            cout << "Please enter the character's name" << endl;
            getline(cin, name);

            //Check if character already exists (based on file name)
            while (stat(name.c_str(), &buffer) == 0) {
                cout << "Character name already exists. Please try again." << endl;
                getline(cin, name);
            }

            cout << "Please enter the character's level" << endl;
            getline(cin, level);

            //While the input is not an integer
            while (!isNumber(level))
            {
                cout << "Please enter a valid integer for the character's level" << endl;
                getline(cin, level);
            }

            while (true) {
                string tempName;
                string tempEffect;
                cout << "Please enter the character's spells. Enter \"done\" to finish the spell list." << endl;
                cout << "Spell Name: ";
                getline(cin, tempName);
                if (tempName == "done") {
                    break;
                }
                cout << "Spell Effect: ";
                getline(cin, tempEffect);
                if (tempEffect == "done") {
                    break;
                }
                spells.insert({ tempName, tempEffect });
            }

            while (true) {
                string tempName;
                string tempEffect;
                cout << "Please enter the character's abilities. Enter \"done\" to finish the spell list." << endl;
                cout << "Ability Name: ";
                getline(cin, tempName);
                if (tempName == "done") {
                    break;
                }
                cout << "Ability Effect: ";
                getline(cin, tempEffect);
                if (tempEffect == "done") {
                    break;
                }
                abilities.insert({ tempName, tempEffect });
            }

            createCharacter(name, stoi(level), spells, abilities);
        }
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
