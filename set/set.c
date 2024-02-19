/*
* set.c - CS50 'set' module
*
* see set.h for more information.
*
* Dylan Lawler, CS50 Spring 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "memory.h"

/**************** local types ****************/
typedef struct setnode {
  void *item;                 // pointer to data for this item
  char *key;
  struct setnode *next;       // link to next node
} setnode_t;

/**************** global types ****************/
typedef struct set {
  struct setnode *head;       // head of the list of items in set
} set_t;

/**************** set_new() ****************/
/* see set.h for description */
set_t * set_new(void){
  set_t *set = malloc(sizeof(set_t));

  if (set == NULL){
    return NULL;              // error allocating set
  } else {
    // initialize contents of set structure
    set->head = NULL;
    return set;
  }
}

/**************** setnode_new ****************/
/* Allocate and initialize a setnode */
static setnode_t * // not visible outside this file
setnode_new(const char *key, void *item)
{
  setnode_t *node = malloc(sizeof(setnode_t));
  if (node == NULL) {
    // error allocating memory for node; return error
    return NULL;
  } else {
    node->key = malloc(sizeof(key));
    strcpy(node->key, key);
    node->item = item;
    node->next = NULL;
    return node;
  }
}

/**************** set_insert() ****************/
/* see set.h for description */
bool set_insert(set_t *set, const char *key, void *item){
  // makes sure key doesn't already exist

  if (set != NULL && item != NULL && key != NULL) {

    for (setnode_t *node = set->head; node != NULL; node = node->next){
        if (strcmp(node->key, key) == 0){
            return false;
        }
    }
    // allocate a new node to be added to the list
    // const char *keycopy = key;
    setnode_t *new = setnode_new(key, item);
    if (new != NULL) {
      // add it to the head of the list
      new->next = set->head;
      set->head = new;
      return true;
    }
  }
    return false;
}

/**************** set_find() ****************/
/* see set.h for description */
void *set_find(set_t *set, const char *key){
    if (set != NULL && key != NULL) {
        // returns item of found key
        for (setnode_t *node = set->head; node != NULL; node = node->next){
            if (strcmp(node->key, key) == 0){
                return node->item; 
            }
        }
    }
    // key doesn't exist or a parameter is null
    return NULL;
}

/**************** set_print() ****************/
/* see set.h for description */
void set_print(set_t *set, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item) ){
  if (fp != NULL) {
    if (set != NULL){
      // prints out entire set in {(key, item)} form
      fputc('{', fp);
      for (setnode_t *node = set->head; node != NULL; node = node->next){
          if (itemprint != NULL) {
            fputc('(', fp);
            (*itemprint)(fp, node->key, node->item); 
            fputc(')', fp);
            if(node->next != NULL){
              fputs(", ", fp);
            }
          }
      }
      fputc('}', fp);
      return;
    }
    // null set
    else{
      fputs("(null)", fp);
    }
  }
}


/**************** set_iterate() ****************/
/* see set.h for description */
void set_iterate(set_t *set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item)){
    if (set != NULL && itemfunc != NULL) {
        for (setnode_t *node = set->head; node != NULL; node = node->next){
            // iterates over all nodes and calls function on them
            (*itemfunc)(arg, node->key, node->item); 
        }
    }
}

/**************** set_delete() ****************/
/* see set.h for description */
void set_delete(set_t *set, void (*itemdelete)(void *item)){
    if (set != NULL) {
        for (setnode_t *node = set->head; node != NULL; ) {
            if (itemdelete != NULL) {         // if possible...
                (*itemdelete)(node->item);     // delete node's item
            }
            setnode_t *next = node->next;     // remember what comes next
            free(node->key);
            free(node);                 // free the node
            node = next;                      // and move on to next
        }
        free(set);
  }
}
