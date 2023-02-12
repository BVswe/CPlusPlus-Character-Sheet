#pragma once
#include <string>
#include <map>


using namespace std;

//Create a character file
void createCharacter(const string& name, int level, const map<string, string>& spells, const map<string, string>& abilities);

//Read/Access a character's date
void accessCharacter(const string& name);

//Change name of character in file
void editName(const string& name);

//Change spells of character in file
void editSpells(const map<string, string>& spells);

//Change abilities of character in file
void editAbilities(const map<string, string>& abilities);

//Change level of character in file
void editLevel(int level);

//Delete a character's file
void deleteCharacter(const string& name);

//Creating operator << between ostream and map
std::ostream& operator <<(ostream& os, const map<string, string>& m);