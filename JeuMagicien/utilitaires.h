#pragma once
#include <random>
/// <summary>
/// Genere un int aléatoire entre un min et un max.
/// Inspiré de https://stackoverflow.com/a/7560564/14228180
/// </summary>
/// <param name="min">la borne minimale de la plage (inclusif)</param>
/// <param name="max">la borne maximales de la plage (inclusif)</param>
/// <returns>un nombre aléatoire entre min et max inclusivement</returns>
int chiffreAleatoire(int min, int max);