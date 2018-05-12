#pragma once
#include "Case.h"
#include <vector>

using namespace std;
class Grille
{
public:
	Grille();
	~Grille();
	void PopRamdom(); //permet de faire apparaitre aléatoirement une case 2 ou 4 à un espace vide de la grille uniquement si cela est possible
	void DeplacerGeneral(); //permet de faire bouger toutes les cases de la grille vers une direction selon le choix de l'utilisateur tout en gérant les collisions
	int retourneValeurCase(int x, int y);//permet de renvoyer la valeur de la case en [x][y]
private:
	Case tableau_[4][4] ; //stocke les cases, leurs pos x et y , leurs valeurs dans un tableau 4x4
	int nb_case_; //compte le nombre de cases qui sont sur la grille actuellement
};

Grille::Grille()
{
    nb_case_ = 2;
	PopRamdom();
	PopRamdom();
}

Grille::~Grille()
{

}