# CS50 Lab 3
## CS50 Spring 2022

### hashtable

A `hashtable` is an unordered collection of key item pairs
The `hashtable` starts empty, grows as the caller adds a key one at a time. It utilizes the `set` module to make an array of sets. No key duplicates are allowed.

### Usage

The *hashtablr* module, defined in `hashtable.h` and implemented in `hashtable.c`, implements `char *key` and `void *item` and `struct set ptrarray` with the array size given by `num_slots`, and exports the following functions:

```c
hashtable_t *hashtable_new(const int num_slots);
bool hashtable_insert(hashtable_t *ht, const char *key, void *item);
void *hashtable_find(hashtable_t *ht, const char *key);
void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item));
void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item));
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item));

```

### Implementation

We implement this counters as an array of sets, which is a linked list.
See README.md for set to see the implementation of each function, which is called by the same function in hashtable.

### Assumptions

No assumptions beyond those that are clear from the spec.

No duplicate keys can exist

The key must be a string, neither the key or item cannot be null.



### Files

* `Makefile` - compilation procedure
* `hashtable.h` - the interface
* `hashtable.c` - the implementation
* `hashtable.c` - unit test driver
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make hashtable.o`.

### Testing

The `hashtabletest.c` provides a couple of hardcoded counter tuples and tests all of the counters module function

To test, simply `make test` after `make` to compile the test file

To test with valgrind, `make valgrind`.
