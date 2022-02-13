#pragma once
#include "Baton.h"
class Magicien
{
private:
	int m_pointsVie;
	int m_pointsMana;
	int m_bouclier;
	Baton m_baton;

public:
	Magicien();
	int pointsVie();
	int pointsMana();
	int bouclier();
	std::string baton();
	int utiliserSortAttaque(Magicien&);
	void utiliserSortDefense();
	void changerBaton();
	void recevoirAttaque(int);
	std::string toString();
};

