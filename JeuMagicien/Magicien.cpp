#include "Magicien.h"

/// <summary>
/// Constructeur pour le magicien
/// PV : 50
/// PM : 50
/// PB : 0
/// Baton aléatoire
/// </summary>
Magicien::Magicien() : m_pointsVie{ 50 }, m_pointsMana{ 50 }, m_bouclier{ 0 }, m_baton{ Baton() } {};


/// <summary>
/// Accesseur public pour le nombre de points de vie
/// </summary>
/// <returns>le nombre de points de vie du magicien</returns>
int Magicien::pointsVie()
{
	return m_pointsVie;
}
/// <summary>
/// Accesseur public pour le nombre de points de mana
/// </summary>
/// <returns>le nombre de points de vie</returns>
int Magicien::pointsMana()
{
	return m_pointsMana;
}
/// <summary>
/// Accesseur public pour le bouclier
/// </summary>
/// <returns>le nombre de points de bouclier</returns>
int Magicien::bouclier()
{
	return m_bouclier;
}
/// <summary>
/// Accesseur pour le baton
/// Retourne seulement le nom du baton pour ne pas pouvoir modifier ses sorts de l'extérieur
/// </summary>
/// <returns>le nom du baton</returns>
std::string Magicien::baton()
{
	return m_baton.nom();
	m_pointsMana -= 10;
}

/// <summary>
/// Utilise le sort d'attaque sur l'ennemi
/// </summary>
/// <param name="ennemi">le magicien ennemi</param>
/// <returns>le nombre de dégats</returns>
int Magicien::utiliserSortAttaque(Magicien& ennemi)
{
	int degats{ m_baton.utiliserSortAttaque() };
	ennemi.recevoirAttaque(degats);
	return abs(degats);
}

/// <summary>
/// Utilise le sort de guérison pour augmenter sa vie ou son bouclier
/// </summary>
void Magicien::utiliserSortDefense()
{
	int pointsDefense{ m_baton.utiliserSortDefense() };
	//Si positif, augmente PV
	if (pointsDefense > 0)
	{
		if (m_pointsVie + pointsDefense > 100)
		{
			m_pointsVie = 100;
		}
		else
		{
			m_pointsVie += pointsDefense;
		}
	}
	//Si negatif, augmente PB
	else if (pointsDefense < 0)
	{
		pointsDefense = abs(pointsDefense);
		if (m_bouclier + pointsDefense > 50)
		{
			m_bouclier = 50;
		}
		else
		{
			m_bouclier += pointsDefense;
		}
	}
	m_pointsMana -= 10;
}
/// <summary>
/// Recois une attaque d'un certain nombre de dégats
/// </summary>
/// <param name="degats">le nombre de dégats</param>
void Magicien::recevoirAttaque(int degats)
{
	if (degats > 0)
	{
		if (m_bouclier - degats >= 0)
		{
			m_bouclier -= degats;
		}
		else
		{
			degats -= m_bouclier;
			m_bouclier = 0;
			m_pointsVie -= degats;
		}
	}
	else
	{
		//+= parce que degats est negatif
		m_pointsVie += degats;
	}
}
/// <summary>
/// Remplace le baton du magicien par un nouveau et remets son mana à 50
/// </summary>
void Magicien::changerBaton()
{
	m_baton = Baton();
	m_pointsMana = 50;
}

std::string Magicien::toString()
{
	std::string sortie{};
	sortie += "Points de vie : ";
	sortie += std::to_string(pointsVie());
	sortie += "\n";
	sortie += "Points de Mana : ";
	sortie += std::to_string(pointsMana());
	sortie += "\n";
	sortie += "Points de bouclier : ";
	sortie += std::to_string(bouclier());
	sortie += "\n";
	sortie += "Baton : ";
	sortie += m_baton.nom();

	return sortie;
}