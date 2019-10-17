#include <iostream>
#include<cstdlib>
#include "Arbre.h"

using namespace std;

using namespace std;

int main()
{
    int monTableau[16]={51, 77, 22, 5, 16, 33, 65, 53, 15, 101, 84, 3, 4, 71, 88, 81};

    ARBRE arbre;
    for (int i=0; i<16; i++){
        arbre.AjouterNoeud(monTableau[i]);
    }

    arbre.AfficherArbre();
    return 0;
}
