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
    if(root == NULL){
        root = CreationFeuille(cle);
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
        cout << "Arbre vide.... !!! ";
    }
}

ARBRE::Noeud* ARBRE::GetNoeud(int cle){
    return GetNoeudPrivee(cle, root);
}

ARBRE::Noeud* ARBRE::GetNoeudPrivee(int cle, Noeud* Ptr){
    if (Ptr !=NULL){
        if(Ptr->cle == cle){
            return Ptr;
        }
        else {
            if (cle < Ptr->cle){
                 return GetNoeudPrivee(cle, Ptr->gauche);
            }
            else {
                return GetNoeudPrivee(cle, Ptr->droite);
            }
        }
    }
    else {
        return NULL;
    }
}

int ARBRE::GetCleRoot(){
    if (root !=NULL){
        return root->cle;
    }
    else return -999;
}

void ARBRE::AfficherEnfants(int cle){
    Noeud* Ptr = GetNoeud(cle);
    cout << "Ptr->cle: " << Ptr->cle;
    if (Ptr != NULL){
       cout<<"Le Noeud Parent est = "<< Ptr->cle << endl;
       Ptr->gauche == NULL ?
       cout << "Il n y a pas de fils a gauche \n" :
       cout << "Le fils gauche est = " << Ptr->gauche->cle <<endl;

       Ptr->droite == NULL ?
       cout << "Il n y a pas de fils a droite \n" :
       cout << "Le fils a droite est = "<< Ptr->droite->cle <<endl;
    }
    else{
        cout << "La cle est " << cle << " n existe pas \n";
    }
}

int ARBRE::TrouverPlusPetiteCle(){
   return TrouverPlusPetiteClePrivee(root);
}

int ARBRE::TrouverPlusPetiteClePrivee(Noeud* Ptr){
    if (root == NULL){
        cout << "l arbre est vide.... \n" ;
        return -999;
    }
    else {
        if(Ptr->gauche !=NULL){
            return TrouverPlusPetiteClePrivee(Ptr->gauche);
        }
        else {
            return Ptr->cle;
        }
    }
}
