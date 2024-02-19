/* 
 * counterstest.c - test program for CS50 counters module
 *
 * usage: helper functions and hardcode to test header file functions
 * 
 * CS50, Spring 2022, Dylan Lawler
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/memory.h"
#include "counters.h"


void test_add(counters_t *ctr); 
void test_get(counters_t *ctr); 
void test_iterate(void *arg, const int key, int count);
void test_set(counters_t *ctr);

int main(){
  counters_t *testctr = counters_new(); 
  
  // testing counters_new
  if (testctr == NULL) {
    fprintf(stderr, "counters_new failed\n");
    return 1;
  }

  counters_t *nullctr = NULL; 

  // testing counters_add
  printf("Testing counters_add\n\n");
  test_add(testctr);

  printf("Making sure NULL is ignored by add\n\n");
  test_add(nullctr); 

  // testing counters_set
  printf("Testing counters_set. Should print 0, 1, 1\n");
  test_set(testctr); 
  printf("\n\n");

  // testing counters_get
  printf("Testing counters_get. Should print 0, 2, 3, 0\n");
  test_get(testctr); 
  printf("\n");


  printf("Making sure NULL is handled by get. Should print all zeros\n");
  test_get(nullctr); 
  printf("\n");

  // testing counters_print
  printf("Testing counters_print. Should print {(2,3), (1,2)}\n");
  counters_print(testctr, stdout); 
  printf("\n\n");

  printf("Testing counters_print with null file\n");
  counters_print(testctr, NULL); 
  printf("\n");

  printf("Making sure NULL is handled by print\n");
  counters_print(nullctr, stdout); 
  printf("\n\n");

  // testing counters_iterate
  printf("Testing counters_iterate by counting the counters. Should print 2\n");
  int count = 0;
  counters_iterate(testctr, &count, test_iterate);
  printf("%d\n\n", count);
  
  // testing counters_delete
  printf("Deleting test counter\n");
  counters_delete(testctr); 
  printf("\n");

  return 0;
}

void test_add(counters_t *ctr){
  // adding hardcoded keys
  counters_add(ctr, -1); 
  counters_add(ctr, 1);
  counters_add(ctr, 2);
}

void test_get(counters_t *ctr){
  // finding added hardcoded keys
  printf("%d, ", counters_get(ctr, -1));
  printf("%d, ", counters_get(ctr, 1));
  printf("%d, ", counters_get(ctr, 2));
  printf("%d\n", counters_get(ctr, 3));
}

void test_set(counters_t *ctr){
  // setting added hardcoded counters
  printf("%d, ", counters_set(ctr, -1, 2));
  printf("%d, ", counters_set(ctr, 1, 2));
  printf("%d", counters_set(ctr, 2, 3));
}

void test_iterate(void *arg, const int key, int count){
  int *numctrs = arg;

  if (numctrs != NULL && key >=0 && count >= 0){
    (*numctrs)++;
  }
}