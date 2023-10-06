#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a= (ArbreBinaire)malloc(sizeof(Noeud));
	a->val=e;
	a->filsDroit=NULL;
	a->filsGauche=NULL;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire temp =a;
	while (a!=NULL) {
		if (e<a->val) {
			a= a->filsGauche;
		}
		if (e>a->val) {
			a= a->filsDroit;
		}
		if (a->val==e) {
		return temp;
		}
	}
	a=creer(e);
	return temp;
}	

ArbreBinaire insere_i2(ArbreBinaire a, Element e) {
	ArbreBinaire pere = NULL, p=a, res=a;
	while (p!=NULL && p->val!=e) {
		pere=p;
		if (e<=p->val) {
			p= p->filsGauche;
		}
		if (e>=p->val) {
			p= p->filsDroit;
		}
	}
	if (p==NULL) {
			if (pere==NULL) {
				res=creer(e);
			}
			else {
				if (pere->val>e) {
					pere->filsGauche=creer(e);
				}
				if (pere->val<e) {
					pere->filsDroit=creer(e);
				}
			}
		}
		return res
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if (a==NULL) { 
		return creer(e);
	}
	if (e<a->val) {
		insere_r(a->filsGauche, e);
	}
	if (e>a->val) {
		insere_r(a->filsDroit, e);
	}
	if (e==a->val) {
		return a;
	}
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if (a==NULL) {
		return 0;
	}
	return 1+ nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche);
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if (a==NULL) {
		return -1;
	}
	if (e==a->val) {
		return 0;
	}
	if (e<a->val) {
		int pg=profondeur(a->filsGauche, e);
		if (pg==-1) {
			return -1;
		};
		return 1+pg;
	}
	if (e>a->val) {
		int pd=profondeur(a->filsDroit, e);
		if (pd==-1) {
			return -1;
		};
		return 1+pd;
	}
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if (a==NULL){
		return 0;
	}
	int g =
	return 1+ ()
	(a > b) ? a : b
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
}

void afficheGRD_r(ArbreBinaire a){
}

void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

