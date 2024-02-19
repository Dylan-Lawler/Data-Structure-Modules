/* 
 * hashtabletest.c - test program for CS50 hashtable module
 *
 * usage: helper functions and hardcode to test header file functions
 * 
 * CS50, Spring 2022, Dylan Lawler
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"


void test_find(hashtable_t *ht);
void test_iterate(void *arg, const char *key, void *item);
int test_insert(hashtable_t *ht);
void test_print(FILE *fp, const char *key, void *item);
void test_delete(void *item);

int main(){
    hashtable_t *testht = hashtable_new(5); 

    // testing new
    if (testht == NULL){
        fprintf(stderr, "set_new failed\n");
        return 1;
    }

    // testing hashtable_insert
    printf("Testing hashtable_insert\n");
    test_insert(testht);
    printf("\n");

    printf("Making sure NULL is ignored by insert\n");
    test_insert(NULL); 
    printf("\n");

    // testing hashtable_find
    printf("Testing hashtable_find. Should print 4.0, 3.0, (null), 1.0, 2.0\n");
    test_find(testht); 
    printf("\n\n");

    printf("Making sure NULL is handled by find. Should print all (null)\n");
    test_find(NULL); 
    printf("\n\n");

    // testing hashtable_print
    printf("Testing hashtable_print.\n");
    hashtable_print(testht, stdout, test_print); 
    printf("\n\n");

    printf("Testing hashtable_print with null itemprint.\n");
    hashtable_print(testht, stdout, NULL); 
    printf("\n\n");

    printf("Testing hashtable_print with null file.\n");
    hashtable_print(testht, NULL, test_print); 
    printf("\n\n");

    // testing hashtable_iterate
    printf("Testing hashtable_iterate by counting the key pairs. Should print 4\n");
    int count = 0;
    hashtable_iterate(testht, &count, test_iterate);
    printf("%d\n\n", count);

    // testing hashtable_delete
    printf("Deleting test hashtable\n");
    hashtable_delete(testht, test_delete); 
    printf("\n");

    return 0; 

}

int test_insert(hashtable_t *ht){
    // test tuple data 
    char *name1 = "Dylan";
    char *name2 = "Test";
    char *name3 = "Mary";
    char *name4 = "Adam";
    char *fakename = NULL; 

    char *gpa1 = "4.0";
    char *gpa2 = "3.0";
    char *gpa3 = "2.0";
    char *gpa4 = "1.0";
    char *fakegpa = NULL;


    // make sure insert works properly
    if ((hashtable_insert(ht, name1, gpa1)) == 0){
      if (ht != NULL){
      fprintf(stderr, "set_insert failed\n");
      return 2;
      }
    } 
    if ((hashtable_insert(ht, name2, gpa2)) == 0 ){
      if (ht != NULL){
      fprintf(stderr, "set_insert failed\n");
      return 2;
      }
    } 

    // should have null for null parameters
    if ((hashtable_insert(ht, fakename, gpa1)) != 0){
      fprintf(stderr, "set_insert failed\n");
      return 3;
    } 
    if ((hashtable_insert(ht, name1, fakegpa)) != 0){
      fprintf(stderr, "set_insert failed\n");
      return 3;
    } 

    //insert more if testing passes 
    hashtable_insert(ht, name3, gpa3);

    hashtable_insert(ht, name4, gpa4);

   return 0;
}

void test_find(hashtable_t *ht){
  char *name1 = "Dylan";
    char *name2 = "Test";
    char *name3 = "Mary";
    char *name4 = "Adam";
    char *fakename = NULL; 

  // find all inserted keys, tests null name
  printf("%s, ", (char*)hashtable_find(ht, name1));
  printf("%s, ", (char*)hashtable_find(ht, name2));
  printf("%s ", (char*)hashtable_find(ht, fakename));
  printf("%s, ", (char*)hashtable_find(ht, name3));
  printf("%s, ", (char*)hashtable_find(ht, name4));
}

// counting key item pairs
void test_iterate(void *arg, const char *key, void *item){
  int *numitem = arg;

  if (numitem != NULL && key != NULL && item != NULL){
    (*numitem)++;
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

// delete item 
void test_delete(void *item){
  if (item != NULL) {
    item = NULL;   
  }
}
