#include <iostream>
#include<cstdlib>
#include "Arbre.h"

using namespace std;


ARBRE::ARBRE(){
    root = NULL;
}

ARBRE::Noeud* ARBRE::CreationFeuille(int cle){

        Noeud* n = new Noeud;
        n->cle = cle;
        n->gauche = NULL;
        n->droite = NULL;

        return n;
}

void ARBRE::AjouterNoeud(int cle){
    AjouterNoeudPrivee(cle, root);
}

void ARBRE::AjouterNoeudPrivee(int cle, Noeud* Ptr){
    if(root ==NULL){
        CreationFeuille(cle);
    }

    else if (cle < Ptr->cle){
        if(Ptr->gauche !=NULL){
            AjouterNoeudPrivee(cle, Ptr->gauche);
        }
        else{
            Ptr->gauche = CreationFeuille(cle);
        }
    }

    else if (cle > Ptr->cle){
        if(Ptr->droite !=NULL){
            AjouterNoeudPrivee(cle, Ptr->droite);
        }
        else{
            Ptr->droite = CreationFeuille(cle);
        }
    }
    else{
        cout<< "ce Noeud existe deja !!! \n";
    }
}

void ARBRE::AfficherArbre(){
        AfficherArbrePrivee(root);
}

void ARBRE::AfficherArbrePrivee(Noeud* Ptr){
    if(root !=NULL){
      if (Ptr->gauche != NULL){
            AfficherArbrePrivee(Ptr->gauche);
      }
      cout << Ptr->cle << " ** ";
      if(Ptr->droite !=NULL){
        AfficherArbrePrivee(Ptr->droite);
      }
    }
    else{
        cout << "Arbre n exste pas !!! ";
    }
}
