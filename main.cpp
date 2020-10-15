#include <iostream>
#include <string>
#include <vector>
#include "usefulFunctions.h"

using namespace std;

int main()
{
    int const nbreMax(6);
    char decision('n');
    vector<int> scores;

    do
    {
        //string mot = saisir_un_mot();
        string mot = un_mot_aleatoire();

        string mystere = melanger_les_lettres(mot);

        int score = trouver_le_mot(mot, mystere, nbreMax);
        scores.push_back(score);

        cout << "Voulez-vous faire une autre partie ? (o/n)" << endl;
        cin >> decision;
    } while(decision == 'o');

    double moyenne = score_moyen(scores);
    cout << "Votre score moyen : " << moyenne << "/" << nbreMax-1 << endl;

    return 0;
}
