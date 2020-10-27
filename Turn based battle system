#include <iostream.h> 
#include <stdlib.h> 
#include <stdio.h> 
int hp = 20, mp = 20, ehp = 35, move;

void lose (void) 
{ 
	cout << "You lose." << endl; 
	hp = 20; 
	mp = 20; 
	ehp = 20; 
	} 

void win (void) 
{ 
	cout << "You win." << endl; 
	hp = 20; 
	mp = 20; 
	ehp = 20;
}


int main() 
{   
label:
cout << "ehp: " << ehp << endl << "hp: " << hp << endl << "mp: " << mp << endl << "(1) Attack" << endl << "(2) Magic Missle" <<endl << "(3) Summon" << endl; 
	cin >> move;  
	system("cls"); 
	cout << "Status:" << endl;

	if (move == 1) 
	{
		cout << "You sliced the enemy with your sword." << endl; 
		ehp -= 1;  
		if (ehp < 0) 
{ 
	win();  
	return 0;
} 

if (hp < 0) 
{ 
	lose();  
	return 0;
}
	cout << "The enemy cast a Magic Missle." << endl << endl; 
hp -= 2; 
	} 

	if (move == 2) 
	{ 
	cout << "You cast a devistating Magic Missle." << endl; 
		ehp -= 2; 
		mp -= 1; 
		if (ehp < 0) 
{ 
	win();  
	return 0;
} 

if (hp < 0) 
{ 
	lose();  
	return 0;
}
	cout << "The enemy used his sword." << endl << endl; 
hp -= 1; 
	}   

	if (move == 3) 
	{ 
	cout << "You summoned Ultima!" << endl; 
		ehp -= 10; 
		mp -= 15;  
		hp -= 1;
		if (ehp < 0) 
{ 
	win();  
	return 0;
} 

if (hp < 0) 
{ 
	lose();  
	return 0;
}
	cout << "The enemy used his sword." << endl << endl; 
hp -= 1; 
	}  
	
	goto label;
}
