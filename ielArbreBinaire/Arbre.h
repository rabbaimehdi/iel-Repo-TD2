#include <iostream>
#include<cstdlib>

using namespace std;

#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

class ARBRE {
    private:
        struct Noeud{
            int cle;
            Noeud* gauche;
            Noeud* droite;
        };
    Noeud* root;

    public:
    ARBRE();
};

#endif // ARBRE_H_INCLUDED
