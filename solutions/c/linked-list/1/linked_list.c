#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void) {
    struct list *new_list = malloc(sizeof(struct list));
    if (new_list == NULL) return NULL; 

    new_list->first = NULL;
    new_list->last = NULL;

    return new_list;
}

size_t list_count(const struct list *list){
   if (list == NULL) return 0;
   
   size_t count = 0;
   struct list_node *my_node = list->first; 

   while (my_node != NULL){
      my_node = my_node->next;
      count++;
   }
   return count;
}


void list_push(struct list *list, ll_data_t item_data){
   struct list_node *new_node = malloc(sizeof(struct list_node));
   if (new_node == NULL) return; 

   new_node->data = item_data;
   new_node->next = NULL; 

   if (list->last == NULL) { 
        new_node->prev = NULL;
        list->first = new_node;
        list->last = new_node;
    } else {
        new_node->prev = list->last; 
        list->last->next = new_node; 
        list->last = new_node;
    }
}

ll_data_t list_pop(struct list *list) {
    if (list->last == NULL) return -1; 

    struct list_node *old_last = list->last;
    ll_data_t data = old_last->data;

    list->last = old_last->prev;

    if (list->last == NULL) {
        list->first = NULL;
    } else {
        list->last->next = NULL;
    }

    free(old_last);
    return data;
}

void list_unshift(struct list *list, ll_data_t item_data) {
    struct list_node *new_node = malloc(sizeof(struct list_node));
    if (new_node == NULL) return;
    
    new_node->data = item_data;
    new_node->prev = NULL; 
    new_node->next = list->first; // Eski birinciyi "ikinci" sıraya itiyoruz

    if (list->first == NULL) {
        list->first = new_node;
        list->last = new_node;
    } else {
        list->first->prev = new_node;
        list->first = new_node; 
    }
}

ll_data_t list_shift(struct list *list) {
    if (list->first == NULL) return -1; 

    struct list_node *old_first = list->first;
    ll_data_t data = old_first->data;

    list->first = old_first->next;

    if (list->first == NULL) {
        list->last = NULL;
    } else {
        list->first->prev = NULL;
    }

    free(old_first);
    return data;
}

void list_delete(struct list *list, ll_data_t data) {
    struct list_node *current = list->first;

    while (current != NULL) {
        if (current->data == data) {

            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                list->first = current->next; 

            if (current->next != NULL)
                current->next->prev = current->prev;
            else
                list->last = current->prev; 

            free(current);
            return; 
        }
        current = current->next;
    }
}

void list_destroy(struct list *list) {
    if (list == NULL) return;

    struct list_node *current = list->first;
    struct list_node *next_node;

    while (current != NULL) {
        next_node = current->next; 
        free(current);
        current = next_node;       
    }

    free(list);
}




