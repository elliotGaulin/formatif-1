#pragma once
#include <string>
class Baton
{
private:
	std::string m_nom;
	std::string m_sortAttaque;
	std::string m_sortDefense;
	int m_attaqueMaximum;
	int m_defenseMaximum;

public:
	Baton();
	std::string nom();
	std::string sortAttaque();
	std::string sortDefense();
	int utiliserSortAttaque();
	int utiliserSortDefense();
};

