#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "usefulFunctions.h"

using namespace std;

string saisir_un_mot()
{
    string mot;
    cout << "Saisissez un mot " << endl;
    cin >> mot;
    cout << endl;

    sauts_de_ligne();

    return mot;
}

string melanger_les_lettres(string mot)
{
    string mystere("");
    while (mot != "")
    {
        // Générer un nombre aléatoire
        int nbAleatoire;
        srand(time(0)); //initialiser la génération des nombres aléatoires
        nbAleatoire = rand() % mot.size();
        mystere += mot[nbAleatoire];
        mot.erase(nbAleatoire, 1);
    }

    return mystere;
}

int trouver_le_mot(string mot, string mystere, int nbreMax)
{
    int essaisRestants(nbreMax-1);
    string suggestion;
    cout << "Quel est ce mot ? "<< mystere << endl;
    cin >> suggestion;

    while ((suggestion != mot) && (essaisRestants>0))
    {
        cout << "Ce n'est pas le mot !" << endl;
        cout << endl;
        cout << "Il vous reste " << essaisRestants << " essais!" << endl;
        cout << "Quel est ce mot ? "<< mystere << endl;
        cin >> suggestion;
        essaisRestants--;
    }

    if (suggestion==mot && essaisRestants>=0)
        cout << "Bravo !" << endl;
    else
        cout << "Desole! T'as perdu !!!" << endl << "La bonne réponse est : " << mot << endl;
    cout << essaisRestants <<endl;
    return essaisRestants;
}

void sauts_de_ligne()
{
    for (int i(0); i<50; i++)
        cout << endl;
}

double score_moyen (vector<int> const& scores)
{
    double moyenne(0);
    for (int i(0); i<scores.size(); i++)
    {
        moyenne += (double) scores[i];
    }

    return moyenne/scores.size();
}

string un_mot_aleatoire()
{
    string const dicoPath("C:/Users/ASUS/Desktop/c++ mines/dico.txt");
    ifstream flux(dicoPath.c_str());

    string ligne("");
    if (flux)
    {
        int taille = taille_fichier(dicoPath);

        int ligneAleatoire;
        srand(time(0));
        ligneAleatoire = rand() % (taille+1);

        for (int i(0); i<ligneAleatoire; i++)
        {
            getline(flux, ligne);
        }

        //cout << ligne << endl;
    }
    else
    {
        cout << "Error !!!" << endl;

    }
    return ligne;
}

int taille_fichier(string const& path)
{
    int taille(0);
    ifstream flux(path.c_str());
    string ligne;
    while (getline(flux, ligne))
    {
        taille++;
    }

    return taille;
}
