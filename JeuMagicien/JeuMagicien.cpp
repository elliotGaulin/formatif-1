// JeuMagicien.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "JeuMagicien.h"
#include "Magicien.h"
#include "utilitaires.h"

int main()
{
	Magicien joueur{ Magicien() };
	Magicien ordinateur{ Magicien() };
	//Pour décider qui commence
	bool passerTourJoueur{ (bool)chiffreAleatoire(0,1) };
	//Boucle du jeu
	while (joueur.pointsVie() > 0 && ordinateur.pointsVie() > 0)
	{
		if (!passerTourJoueur)
		{
			std::cout << affichageJeu(joueur, ordinateur);
			std::string choixJoueur{ " " };
			while (choixJoueur != "1" && choixJoueur != "2" && choixJoueur != "3")
			{
				std::cout << "JOUEUR : Choississez votre action :\n1-Utiliser votre sort d'attaque (-10 mana)\n2-Utiliser votre sort de défense (-10 mana)\n3-Changer de baton\nVotre choix:";
				std::cin >> choixJoueur;
				if (choixJoueur == "1" || choixJoueur == "2")
				{
					if (joueur.pointsMana() < 10)
					{
						std::cout << "\nMana insuffisant!\n";
						choixJoueur = " ";
					}
				}
				else if (choixJoueur != "3")
				{
					std::cout << "Choix invalide\n";
				}
			}
			//Vide la console
			std::system("CLS");
			if (choixJoueur == "1")
			{
				std::cout << "Vous avez attaqué l'ennemi de ";
				std::cout << joueur.utiliserSortAttaque(ordinateur);
				std::cout << "points.\n\n";
			}
			else if (choixJoueur == "2")
			{
				std::cout << "Vous utilisez votre sort de défense\n";
				joueur.utiliserSortDefense();
			}
			else if (choixJoueur == "3")
			{
				std::cout << "Vous changez de baton\n";
				joueur.changerBaton();
			}
		}
		else
		{
			passerTourJoueur = 0;
		}

		//Vérification de tous le monde est en vie
		if (joueur.pointsVie() < 0 || ordinateur.pointsVie() < 0)
		{
			continue;
		}
		//Au tour de l'ordinateur
		int choixOrdinateur;
		if (ordinateur.pointsMana() > 10)
		{
			choixOrdinateur = chiffreAleatoire(1, 3);
		}
		else
		{
			choixOrdinateur = 3;
		}

		if (choixOrdinateur == 1)
		{
			std::cout << "L'ordinateur vous attaque de ";
			std::cout << ordinateur.utiliserSortAttaque(joueur);
			std::cout << "points.\n\n";
		}
		else if (choixOrdinateur == 2)
		{
			std::cout << "L'ordinateur utilise son sort de défense\n";
			ordinateur.utiliserSortDefense();
		}
		else if (choixOrdinateur == 3)
		{
			std::cout << "L'ordinateur change de baton!\n";
			ordinateur.changerBaton();
		}
	}
	
	if (joueur.pointsVie() > 0)
	{
		std::cout << "\nBRAVO, vous avez-vaincu le magicien ennemi.\n";
	}
	else
	{
		std::cout << "\nOH NON, vous avez été vaincu par le magicien ennemi.\n";

	}
}

std::string affichageJeu(Magicien joueur, Magicien ordinateur)
{
	std::string output{};
	output += "JOUEUR :\n";
	output += joueur.toString();
	output += "\n\nORDINATEUR :\n";
	output += ordinateur.toString();
	output += "\n\n";

	return output;
}
