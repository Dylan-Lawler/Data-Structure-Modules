/*
* hashtable.c - CS50 'hashtable' module
*
* see hashtable.h for more information.
*
* Dylan Lawler, CS50 Spring 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "../set/set.h"
#include "../lib/memory.h"
#include "jhash.h"

/**************** global types ****************/
typedef struct hashtable {
    set_t **ptr_array;       // array of sets
    int num_slots;              // number of slots in the hashtable
} hashtable_t;

/**************** hashtable_new() ****************/
/* see hashtable.h for description */
hashtable_t *hashtable_new(const int num_slots){
    hashtable_t *ht = malloc(sizeof(hashtable_t)); 

    if (ht == NULL){
    return NULL;              // error allocating hashtable
  } else {
      ht->num_slots = num_slots; 
      ht->ptr_array = calloc(ht->num_slots, sizeof(set_t*));
      for (int i = 0; i < ht->num_slots; i++){
          ht->ptr_array[i] = set_new();
      }
      return ht;
  }
}


/**************** hashtable_insert() ****************/
/* see hashtable.h for description */
bool hashtable_insert(hashtable_t *ht, const char *key, void *item){
    if (ht != NULL && key != NULL && item != NULL){
        //calculates slot to be put in and puts it there
        int hashnum = JenkinsHash(key, ht->num_slots);
        //set insert takes care of duplicate keys and key copying
        return (set_insert(ht->ptr_array[hashnum], key, item));
    }
    return false;
}

/**************** hashtable_find() ****************/
/* see hashtable.h for description */
void *hashtable_find(hashtable_t *ht, const char *key){
    if (ht != NULL && key != NULL){
        int hashnum = JenkinsHash(key, ht->num_slots);
        return (set_find(ht->ptr_array[hashnum], key));
    }
    return NULL;
}

/**************** hashtable_print() ****************/
/* see hashtable.h for description */
void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item)){
    if (fp != NULL){
        if (ht != NULL){
            // prints each set by line with indicating slot number 
            for (int i = 0; i < ht->num_slots; i++){
                set_print(ht->ptr_array[i], fp, itemprint);
                fputc('\n', fp);
            }
        }  
    }
}

/**************** hashtable_iterate() ****************/
/* see hashtable.h for description */
void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item)){
    if (ht != NULL){
        for (int i = 0; i < ht->num_slots; i++){
            // iterates over every pair in the set (see set.c for set iteration details)
            set_iterate(ht->ptr_array[i], arg, itemfunc); 
        }
    }
}

/**************** hashtable_delete() ****************/
/* see hashtable.h for description */
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item)){
    if (ht != NULL){
        // frees setnodes (see set.c for set_delete)
        for (int i = 0; i < ht->num_slots; i++){
            set_delete(ht->ptr_array[i], itemdelete); 
        }
        // delete the entire hashtable
        free(ht->ptr_array);
        free(ht);  
    }
}

