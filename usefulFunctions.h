#ifndef USEFULFUNCTIONS_H_INCLUDED
#define USEFULFUNCTIONS_H_INCLUDED

#include <vector>
#include <string>

std::string saisir_un_mot();
std::string melanger_les_lettres(std::string mot);
int trouver_le_mot(std::string mot, std::string mystere, int nbreMax=10);
void sauts_de_ligne();
double score_moyen (std::vector<int> const& scores);
std::string un_mot_aleatoire();
int taille_fichier(std::string const& path);
#endif // USEFULFUNCTIONS_H_INCLUDED
