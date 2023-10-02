#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste nouvelleListe = (Liste)malloc(sizeof(Cellule));
	nouvelleListe->val = v;
	nouvelleListe->suiv = NULL;
	return nouvelleListe;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste nouvelleCellule = creer(v);
	nouvelleCellule->suiv = l;
	return nouvelleCellule;
}

/*
void afficheElement(Element e) {
	printf("%i ",e);
}*/

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	while (l != NULL) {
		afficheElement(l->val);
		l = l->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if (l != NULL) {
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}
/*
void detruireElement(Element e) {
    free(e);
}*/

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste suivant, courant = l;
	while (courant != NULL) {
		suivant=courant->suiv;
		detruireElement(courant->val);
		free(courant);
		courant=suivant;
	}
}

// version récursive
void detruire_r(Liste l) {
	if (l != NULL) {
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if (l == NULL) {
		return creer(v);
	}

	Liste debut = l;
	while (l->suiv != NULL) {
		l = l->suiv;
	}
	l->suiv = creer(v);

	return debut;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if (l == NULL) {
		return creer(v);
	}

	l->suiv = ajoutFin_r(v, l->suiv);

	return l;
}
/*
// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}*/

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while (l != NULL) {
		if (equalsElement(l->val, v)) {
			return l;
		}
		l = l->suiv;
	}
	return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (l == NULL) {
		return NULL;
	}
	if (equalsElement(l->val, v)) {
		return l;
	}
	return cherche_r(v, l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	if (l->val == v) {
		return l->suiv;
	}
	Liste debut = l;
	while (l->suiv != NULL && l->suiv->val != v) {
		l = l->suiv;
	}

	if (l->suiv != NULL) {
		l->suiv = l->suiv->suiv;
	}
	return debut;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (l == NULL) {
		return NULL;
	}
	if (l->val == v) {
		return l->suiv;
	}
	l->suiv = retirePremier_r(v, l->suiv);
	return l;
}


void afficheEnvers_r(Liste l) {
	if (l != NULL) {
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}



