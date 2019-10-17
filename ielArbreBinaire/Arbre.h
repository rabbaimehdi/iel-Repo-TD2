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
    void AjouterNoeudPrivee(int cle, Noeud* Ptr);
    void AfficherArbrePrivee(Noeud* Ptr);

    public:
    ARBRE();
    Noeud* CreationFeuille(int cle);
    void AjouterNoeud(int cle);
    void AfficherArbre();
};

#endif // ARBRE_H_INCLUDED
