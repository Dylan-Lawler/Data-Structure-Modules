# CS50 Lab 3
## CS50 Spring 2022

### set

A `set` is an unordered collection of key item pairs
The `set` starts empty, grows as the caller adds a key one at a time.
No key duplicates are allowed.

### Usage

The *set* module, defined in `set.h` and implemented in `set.c`, implements `char *key` and `void *item`, and exports the following functions:

```c
static setnode_t *setnode_new(const char *key, void *item);
bool set_insert(set_t *set, const char *key, void *item);
void *set_find(set_t *set, const char *key);
void set_print(set_t *set, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item))
void set_iterate(set_t *set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item))
void set_delete(set_t *set, void (*itemdelete)(void *item))
```

### Implementation

We implement this counters as a linked list.
The *set* itself is represented as a `struct set` containing a pointer to the head of the list; the head pointer is NULL when the counter is empty.

Each node in the list is a `struct setnode`, a type defined internally to the module.
Each node includes `char *key` and `void *item` and a pointer to the next setnode on the list.

To insert a new item in the set we create a new setnode to hold the `key` and `item`, and insert it at the head of the list.

The `counters_print` method prints a little syntax around the list, and between items, but mostly calls the `itemprint` function on each item and key by scanning the linked list.

The `counters_iterate` method calls the `itemfunc` function on each key and item by scanning the linked list.

The `counters_delete` method calls the `itemdelete` function on each item by scanning the linked list, freeing the nodes and keys as it proceeds.
It concludes by freeing the `struct set`.

### Assumptions

No assumptions beyond those that are clear from the spec.

No duplicate keys can exist

The key must be a string, neither the key or item cannot be null.

### Files

* `Makefile` - compilation procedure
* `set.h` - the interface
* `set.c` - the implementation
* `set.c` - unit test driver
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make set.o`.

### Testing

The `settest.c` provides a couple of hardcoded counter tuples and tests all of the counters module function

To test, simply `make test` after `make` to compile the test file

To test with valgrind, `make valgrind`.
