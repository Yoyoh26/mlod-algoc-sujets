#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void afficheElement(Element e) {
    printf("%s ", (char*)e);
}

void detruireElement(Element e) {}

bool equalsElement(Element e1, Element e2) {
    return strcmp(e1, e2)==0;
}

int main(void){
    Liste l;
    
    l=NULL;
    l = ajoutTete("boy ! ",l);
	l = ajoutTete("my ",l);
	l = ajoutTete("Hello ",l);

	afficheListe_i(l);

    retirePremier_r("my ",l);
    afficheListe_i(l);
}