#pragma once
using namespace std;
class Case
{
public:
	Case();
	~Case();
	void DeplacerDroite(); //déplace à droite la case si collision = faux
	void DeplacerGauche(); //déplace à droite la case si collision = faux
	void DeplacerHaut();   //déplace à droite la case si collision = faux
	void DeplacerBas();    //déplace à droite la case si collision = faux
	bool collisionDroite(); // booleen : vrai collision 
	bool collisionGauche();
	bool collisionHaut();
	bool collisionBas();
	int donneValeurCase(); //retourne les valeurs de la case dans le tableau

private:
	int x_; //position de la case sur l'axe des abscisses
	int y_; //position de la case sur l'axe des ordonnées
	int valeur_; //valeur actuelle de la case (2,4,8,16,32..64..etc)


};

Case::Case()
{
	
}

Case::~Case()
{
}

