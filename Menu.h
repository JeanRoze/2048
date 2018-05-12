#pragma once
#include "Partie.h"
#include <iostream>
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();
	void Afficher();
	void Debut();
	void Quitter();

private:
	Partie* partie_;
};

Menu::Menu()
{
	partie_ = new Partie;
}

Menu::~Menu()
{
	delete partie_;
}

inline void Menu::Afficher()
{
	int choix;
	while (choix != 2)
	{
		cout << "1. Debuter une partie de 2048" << endl;
		cout << "2. Quitter le jeu" << endl;
		if (choix == 1)
		{
			Debut();
		}
		if (choix == 2)
		{
			cout << "Vous avez choisi de quitter le jeu " << endl;
			Quitter();
		}
		else
		{
			cout << "Vous n'avez pas choisi une option possible! Tapez 1 ou 2." << endl;
		}
	}
}

inline void Menu::Debut()
{
	Partie* P;
	P->AfficherScore();
	P->AfficherGrille();
}
