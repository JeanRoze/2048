#pragma once
#include "Grille.h"
using namespace std;
class Partie
{
public:
	Partie();
	~Partie();
	void gagner(); //d�tecte lorsque la partie est gagn�e : une case � 2048
	void perdu(); //d�tecte lorsque la partie est perdue: pas de case � 2048 et aucun d�placement possible
	void AfficherScore(); //met � jour le score � chaque d�placement et l'affiche
	void AfficherGrille(); //met � jour la grille selon les d�placements et l'affiche

private:
	Grille grille_;
	int score_;
};

Partie::Partie()
{
	Grille G();
	score_ = 0;
}

Partie::~Partie()
{
}