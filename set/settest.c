/* 
 * setstest.c - test program for CS50 set module
 *
 * usage: hardcoded function testing
 *
 * CS50, Spring 2022
 * 
 * test_print and test_delete are borrowed from bag module nameprint and namedelete
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/memory.h"
#include "set.h"

void test_find(set_t *set); 
void test_iterate(void *arg, const char *key, void *item);
void test_print(FILE *fp, const char *key, void *item);
void test_delete(void *item); 
int test_insert(set_t *set);

int main(){
    set_t *testset = set_new(); 
    
    //testing set_new
    if (testset == NULL) {
    fprintf(stderr, "set_new failed\n");
    return 1;
    }

    set_t *nullset = NULL; 

    //testing set_insert
    printf("Testing set_insert\n");
    test_insert(testset);
    printf("\n");

    // testing null in set_insert
    printf("Making sure NULL is ignored by insert\n");
    test_insert(nullset); 
    printf("\n");

    //  testing set_find
    printf("Testing set_find. Should print 4.0, 3.0, (null)\n");
    test_find(testset); 
    printf("\n\n");

    // testing null in set_find
    printf("Making sure NULL is handled by find. Should print all (null)\n");
    test_find(nullset); 
    printf("\n\n");

    // testing set_print
    printf("Testing set_print. Should print {(Test, 3.0), (Dylan, 4.0)}\n");
    set_print(testset, stdout, test_print); 
    printf("\n\n");

    // testing null in set_print
    printf("Making sure NULL set  is handled by print. Should print (null)\n");
    set_print(nullset, stdout, test_print); 
    printf("\n\n");

    // testing null itemprint in set_print
    printf("Making sure NULL itemprint is handled by print. Should print empty set\n");
    set_print(testset, stdout, NULL); 
    printf("\n\n");

    // testing null file in set_print
    printf("Testing set_print with null file\n");
    set_print(testset, NULL, test_print); 
    printf("\n");

    // testing set_iterate
    printf("Testing set_iterate by counting the set. Should print 2\n");
    int count = 0;
    set_iterate(testset, &count, test_iterate);
    printf("%d\n\n", count);
    
    // testing set_delete
    printf("Deleting test set\n");
    set_delete(testset, test_delete); 
    printf("\n");

    return 0;
}

int test_insert(set_t *set){
    // test set tuples
    char *name1 = "Dylan";
    char *name2 = "Test"; 
    char *fakename = NULL; 

    char *gpa1 = "4.0";
    char *gpa2 = "3.0";
    char *fakegpa = NULL;

    // insert key and item
    if ((set_insert(set, name1, gpa1)) == 0){
      if (set != NULL){
      fprintf(stderr, "set_insert failed\n");
      return 2;
      }
    } 
    if ((set_insert(set, name2, gpa2)) == 0 ){
      if (set != NULL){
      fprintf(stderr, "set_insert failed\n");
      return 2;
      }
    } 
    if ((set_insert(set, fakename, gpa1)) != 0){
      fprintf(stderr, "set_insert failed\n");
      return 3;
    } 
    if ((set_insert(set, name1, fakegpa)) != 0){
      fprintf(stderr, "set_insert failed\n");
      return 3;
    } 
  return 0;
}

void test_find(set_t *set){
  char *name1 = "Dylan";
  char *name2 = "Test"; 
  char *fakename = NULL; 

  // find key return item
  printf("%s, ", (char*)set_find(set, name1));
  printf("%s, ", (char*)set_find(set, name2));
  printf("%s ", (char*)set_find(set, fakename));
}

void test_iterate(void *arg, const char *key, void *item){
  int *numsets = arg;

  if (numsets != NULL && key != NULL && item != NULL){
    (*numsets)++;
  }
}

// print name and gpa as pair
void test_print(FILE *fp, const char *key, void *item)
{
  const char *name = key; 
  char *gpa = item;
  if (name == NULL || gpa == NULL) {
    fprintf(fp, "(null)");
  }
  else {
    fprintf(fp, "%s, %s", name, gpa); 
  }
}

// delete a name 
void test_delete(void *item)
{
  if (item != NULL) {
    item = NULL;   
  }
}


