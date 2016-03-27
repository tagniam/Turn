#include <iostream>

#include "..\include\Entity.h"
#include "..\include\Common.h"
using namespace std;
using namespace Common;

Entity::Entity() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

string Entity::GetName() {
	// Returns the enemy's name.

	return name;
}

bool Entity::IsDead() {
	// Returns a bool value, if the player's health is equal or below 0.
	if (health <= 0) {
		ColourPrint(name, DARK_GREY);
		cout << " is dead!" << endl << endl;
		Sleep(SLEEP_MS);
		return true;
	}
	return false;
}

void Entity::TakeDamage(int damage) {
	// Doesn't subtract damage points if player chooses to quit.
	if (damage == -1) {
		IsPlaying = false;
		return;
	}

	// Simply subtracts the damage player deals to the enemy.
	health -= damage;
}

void Entity::DisplayHealthBar(){
	string healthBar = "        " + to_string(health);

	for (int i = healthBar.length(); i < 20; i++)
		healthBar += " ";

	for (size_t i = 0; i < healthBar.length(); i++) {
		string currentChar = ""; 
		currentChar += healthBar.at(i);
		if ((i + 1) * 10 <= (size_t)health * 2) {
			ColourPrint(currentChar, RED_BACKGROUND);
		}
		else {
			ColourPrint(currentChar, GREY_BACKGROUND);
		}
	}
}

void Entity::Heal() {
	int heal = ReturnHealAmount();
	health += heal;
	if (health > 100) health = 100;
	
	ColourPrint(name, DARK_GREY);
	cout << " gains ";
	ColourPrint(to_string(heal), GREEN);
	cout << " HP!" << endl;

}