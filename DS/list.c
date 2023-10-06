#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    ListNode *node = malloc(sizeof(ListNode));
    node->data = item_data;
    node->prev = list->last;
    node->next = NULL;

    if (list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        list->last = node;
    }

}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {
    if (list->last == NULL) {
        return -1;
    }
    data_t dernier = list->last->data;
    if (list->first == list->last) {
        free(list->last);
        list->first = NULL;
        list->last = NULL;
    } else {
        list->last = list->last->prev;
        free(list->last->next);
        list->last->next = NULL;
    }
    return dernier;
}

void list_print(List *l) {
    ListNode *p=l->first;
    printf("La liste contient : ");
    while (p!=NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}


int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);
    list_print(l);

    return 0;
}