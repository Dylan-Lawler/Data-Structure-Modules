/*
* counters.c - CS50 'counter' module
*
* see counters.h for more information.
*
* Dylan Lawler, CS50 Spring 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "memory.h"

/**************** local types ****************/
typedef struct countersnode {
   int key;        // key pointers
   int counter;      //counter for given key     
   struct countersnode *next;
} countersnode_t;

/**************** global types ****************/
typedef struct counters {
    countersnode_t *head; 
} counters_t;

/**************** counters_new() ****************/
/* see counters.h for description */
counters_t *
counters_new(void){

    // allocate memory forcounter struct
    counters_t *counter = malloc(sizeof(counters_t));
  
    // makes sure allocation is successful
   if (counter == NULL){
       return NULL;
   }
   // initialize head node and return counter struct
   else{
        counter->head = NULL;
        return counter;
   }
}
 
/**************** countersnode_new ****************/
/* Allocate and initialize a bagnode */
static countersnode_t * // not visible outside this file
countersnode_new(int key){

   countersnode_t *node = malloc(sizeof(countersnode_t));

    // makes sure allocation is successful
   if (node == NULL){
       return NULL;
   }
   // initialize node key and counter and return the node
   else{
       node->key = key;
       node->counter = 1;
       return node;
   }
}

/**************** counters_add() ****************/
/* see counters.h for description */
int
counters_add(counters_t *ctrs, const int key){

    // ensures that counters isn't null and key is positive 
    if (ctrs != NULL && key >= 0){
        for (countersnode_t *node = ctrs->head; node != NULL; node = node->next){
            // increment found key
            if (node->key == key){
                node->counter += 1;
            }
        }
        // add new node to the head of the list and initialize to 1
        countersnode_t *new = countersnode_new(key);
        if (new != NULL) {
            new->next = ctrs->head;
            ctrs->head = new;
        }
        return new->counter;
   }
   return 0;
}

/**************** counters_get() ****************/
/* see counters.h for description */
int
counters_get(counters_t *ctrs, const int key){

    // ensures that counters isn't null and key is positive 
    if (ctrs != NULL && key >= 0){

        for (countersnode_t *node = ctrs->head; node != NULL; node = node->next){
            // return found key's counter
            if (node->key == key){
                return node->counter;
            }
        }
    }
    // return 0 if not found;
        return 0;
}

/**************** counters_get() ****************/
/* see counters.h for description */
bool
counters_set(counters_t *ctrs, const int key, int count){
   
    // ensures that counters isn't null and key is positive 
    if (ctrs != NULL && key >= 0 && count >=0){

        for (countersnode_t *node = ctrs->head; node != NULL; node = node->next){
            // set found key's counter to given int
            if (node->key == key){
                node->counter = count; 
                return true;
            }
        }
        // creates new counternode if key isn't found
        countersnode_t *new = countersnode_new(key);
        // ensures enough memory
        if (new == NULL){
            return false;
        }
        // assign the counter the given value and add new node to the head of the list
        new->counter = count; 
        new->next = ctrs->head;
        ctrs->head = new;
        return true;
    }
    // return NULL if ctrs is null or key is negative
    return false;
}

/**************** counters_print() ****************/
/* see counters.h for description */
void
counters_print(counters_t *ctrs, FILE *fp){

    // prints null if ctrs doesn't exist
    if (ctrs == NULL){
        fputs("(null)", fp);
    }
    else{
        if (fp != NULL){
            fputc('{', fp); 
            // print all nodes as (key, counter) pairs
            for (countersnode_t *node = ctrs->head; node != NULL; node = node->next){
                fprintf(fp, "(%d, %d)", node->key, node->counter);
                if (node->next != NULL){
                    fprintf(fp, ", ");
                }
            }
            fputc('}', fp); 
        }
    }
}

/**************** counters_iterate() ****************/
/* see counters.h for description */
void 
counters_iterate(counters_t *ctrs, void *arg, void (*itemfunc)(void *arg, const int key, int count)){
   
    if (ctrs != NULL && itemfunc != NULL) {
    // call itemfunc with arg, on each item
    for (countersnode_t *node = ctrs->head; node != NULL; node = node->next){
      (*itemfunc)(arg, node->key, node->counter); 
    }
  }
}

/**************** counters_delete() ****************/
/* see counters.h for description */
void counters_delete(counters_t *ctrs){
    if (ctrs != NULL){
        for (countersnode_t *node = ctrs->head; node != NULL;){
            countersnode_t *next = node->next;     // remember what comes next
            free(node);                      // free the node
            node = next; 
        }
    free(ctrs);
    }
}

 

