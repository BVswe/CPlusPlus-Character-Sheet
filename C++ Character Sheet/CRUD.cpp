#include "CRUD.h"
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;

//Create a character file
void createCharacter(const string& name, int level, const map<string, string>& spells, const map<string, string>& abilities) {
	//Create character's file
	ofstream character(name + ".txt");
	character << level << endl;
	character << spells << endl;
	character << abilities << endl;
	cout << "Character created successfully!";
}

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

//Check if character already exists
bool characterExists(const string& name);

//Creating operator << between ostream and map (key:value||key:value...)
std::ostream& operator <<(ostream& os, const map<string, string>& m) {
	for (const auto& p : m) {
		os << p.first << ":";
		os << p.second << "|";
	}
	return os;
}