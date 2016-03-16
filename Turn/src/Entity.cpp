#include <iostream>

#include "..\include\Entity.h"
#include "..\include\Common.h"
using namespace std;
using namespace Common;

Entity::Entity() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Entity::DisplayName() {
	// Prints the enemy's name in dark gray.

	SetConsoleTextAttribute(hConsole, DARK_GREY);
	cout << name;
	SetConsoleTextAttribute(hConsole, GREY);
}

bool Entity::IsDead() {
	// Returns a bool value, if the player's health is equal or below 0.
	if (health <= 0) {
		DisplayName();
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
	SetConsoleTextAttribute(hConsole, GREY);
	string healthBar = "        " + std::to_string(health);

	for (int i = healthBar.length(); i < 20; i++)
		healthBar += " ";

	for (size_t i = 0; i < healthBar.length(); i++) {
		if ((i + 1) * 10 <= (size_t)health * 2) {
			SetConsoleTextAttribute(hConsole, RED_BACKGROUND);
			cout << healthBar.at(i);
		}
		else {
			SetConsoleTextAttribute(hConsole, GREY_BACKGROUND);
			cout << healthBar.at(i);
		}
	}

	SetConsoleTextAttribute(hConsole, GREY);
}

void Entity::Heal() {
	int heal = ReturnHealAmount();
	health += heal;
	if (health > 100) health = 100;
	DisplayName();
	cout << " gains ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << heal;
	SetConsoleTextAttribute(hConsole, GREY);
	cout << " HP! " << endl;
}