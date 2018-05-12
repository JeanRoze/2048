#pragma once
#include "Grille.h"
using namespace std;
class Partie
{
public:
	Partie();
	~Partie();
	void gagner(); //détecte lorsque la partie est gagnée : une case à 2048
	void perdu(); //détecte lorsque la partie est perdue: pas de case à 2048 et aucun déplacement possible
	void AfficherScore(); //met à jour le score à chaque déplacement et l'affiche
	void AfficherGrille(); //met à jour la grille selon les déplacements et l'affiche

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