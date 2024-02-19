# CS50 Lab 3
## CS50 Spring 2022

### counter

A `counter` is an unordered collection of key counter pairs
The `counter` starts empty, grows as the caller adds a key one at a time.
The key's counter can be set at any given time, no key duplicates are allowed.

### Usage

The *counters* module, defined in `counters.h` and implemented in `counters.c`, implements an `int key` and `int counter`, and exports the following functions:

```c
static countersnode_t* countersnode_new(int key);
int counters_add(counters_t *ctrs, const int key);
int counters_get(counters_t *ctrs, const int key);
bool counters_set(counters_t *ctrs, const int key, int count);
void counters_print(counters_t *ctrs, FILE *fp);
void counters_iterate(counters_t *ctrs, void *arg, void (*itemfunc)(void *arg, const int key, int count))
void counters_delete(counters_t *ctrs)
```

### Implementation

We implement this counters as a linked list.
The *counter* itself is represented as a `struct counter` containing a pointer to the head of the list; the head pointer is NULL when the counter is empty.

Each node in the list is a `struct counternode`, a type defined internally to the module.
Each node includes `int key` and `int counter` and a pointer to the next node on the list.

To insert a new item in the counter we create a new counternode to hold the `key` and `counter`, and insert it at the head of the list.

The `counters_print` method prints a little syntax around the list and the ints as a tuple format. 

The `counters_iterate` method calls the `itemfunc` function on each key and counter by scanning the linked list.

The `counters_delete` method  frees the nodes as it proceeds, which also frees the key and counter.
It concludes by freeing the `struct counter`.

### Assumptions

No assumptions beyond those that are clear from the spec.

The `key` and `counter` inserted cannot be <= 0 and must be integers.



### Files

* `Makefile` - compilation procedure
* `counters.h` - the interface
* `counters.c` - the implementation
* `counterstest.c` - unit test driver
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make counters.o`.

### Testing

The `counterstest.c` provides a couple of hardcoded counter tuples and tests all of the counters module function

To test, simply `make test` after `make` to compile the test file

To test with valgrind, `make valgrind`.
