#pragma once
#include <string>
#include <fstream>
#include <unordered_map>
#include <stdio.h>

using namespace std;

//Create a character file
void createCharacter(string name, int level, unordered_map<string, string> spells, unordered_map<string, string> abilities);

//Read/Access a character's date
void accessCharacter(string name);

//Change name of character in file
void editName(string name);

//Change spells of character in file
void editSpells(unordered_map<string, string> spells);

//Change abilities of character in file
void editAbilities(unordered_map<string, string> abilities);

//Change level of character in file
void editLevel(int level);

//Delete a character's file
void deleteCharacter(string name);