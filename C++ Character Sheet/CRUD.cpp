#include "CRUD.h"
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>
#include <iostream>
#include <sstream>
#include <filesystem>

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
void accessCharacter(const string& name) {
	string line;
	ifstream character(name + ".txt");

	cout << "Name: " << name << endl;
	getline(character, line);
	cout << "Level: " << line << endl;
	getline(character, line);
	cout << endl;
	cout << "Spell: Description" << endl;
	stringstream ss(line);
	while (ss) {
		string temp;
		char skip;
		getline(ss, temp, ':');
		if (temp == "") {
			break;
		}
		cout << temp << ": ";
		getline(ss, temp, '|');
		cout << temp << endl;
	}
	cout << endl;
	getline(character, line);
	cout << "Ability: Description" << endl;
	ss.clear();
	ss.str(line);
	while (ss) {
		string temp;
		char skip;
		getline(ss, temp, ':');
		if (temp == "") {
			break;
		}
		cout << temp << ": ";
		getline(ss, temp, '|');
		cout << temp << endl;
	}
	cout << endl;
}

//Change name of character in file
void editName(const string& name);

//Change spells of character in file
void editSpells(const map<string, string>& spells);

//Change abilities of character in file
void editAbilities(const map<string, string>& abilities);

//Change level of character in file
void editLevel(int level);

//Delete a character's file
void deleteCharacter(const string& name) {
	string tempName = name + ".txt";
	if (std::filesystem::remove(tempName)) {
		cout << name << " deleted." << endl;
	}
	else {
		cout << name << " not found." << endl;
	}

}

//Creating operator << between ostream and map (key:value||key:value...)
std::ostream& operator <<(ostream& os, const map<string, string>& m) {
	for (const auto& p : m) {
		os << p.first << ":";
		os << p.second << "|";
	}
	return os;
}