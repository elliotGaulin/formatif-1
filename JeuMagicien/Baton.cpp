#include "Baton.h"
#include "utilitaires.h"
/// <summary>
/// Constructeur pour un baton
/// Choisi un sort aléatoire pour chaque type
/// </summary>
Baton::Baton()
{
	std::string sortsAttaque[2] = { "Incinérateur", "Foudre" };
	std::string sortsDefense[2] = { "Guérison", "Protection" };

	std::string sortAttaque = sortsAttaque[chiffreAleatoire(0, sizeof(sortsAttaque) / sizeof(sortsAttaque[0]) - 1)];
	std::string sortDefense = sortsDefense[chiffreAleatoire(0, sizeof(sortsDefense) / sizeof(sortsDefense[0]) - 1)];
	m_nom = sortAttaque + " de " + sortDefense;
	m_sortAttaque = sortAttaque;
	m_sortDefense = sortDefense;
	m_defenseMaximum = 50;
	m_attaqueMaximum = 50;
}
/// <summary>
/// Accesseur pour le nom du baton
/// </summary>
/// <returns>le nom du baton</returns>
std::string Baton::nom()
{
	return m_nom;
}
/// <summary>
/// Accesseur pour le sort d'attaque
/// </summary>
/// <returns>le nom du sort d'attaque</returns>
std::string Baton::sortAttaque()
{
	return m_sortAttaque;
}
/// <summary>
/// Accesseur pour le sort de defense
/// </summary>
/// <returns>le nom du sort de defense</returns>
std::string Baton::sortDefense()
{
	return m_sortDefense;
}

/// <summary>
/// Utilise le sort d'attaque du baton
/// </summary>
/// <returns>les degats de l'attaque</returns>
int Baton::utiliserSortAttaque()
{
	if (m_sortAttaque == "Incinérateur")
	{
		return chiffreAleatoire(0, m_attaqueMaximum);
	}
	else if (m_sortAttaque== "Foudre")
	{
		return chiffreAleatoire(0, m_attaqueMaximum) * -1;
	}
	return 0;
}

/// <summary>
/// Utilise le sort d'attaque du baton
/// </summary>
/// <returns>les degats de l'attaque</returns>
int Baton::utiliserSortDefense()
{
	if (m_sortDefense == "Guérison")
	{
		return chiffreAleatoire(0, m_defenseMaximum);
	}
	else if (m_sortDefense == "Protection")
	{
		return chiffreAleatoire(0, m_defenseMaximum) * -1;
	}
	return 0;
}

