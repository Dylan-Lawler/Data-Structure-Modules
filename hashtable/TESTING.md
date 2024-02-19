# CS50 Lab 3
## CS50 Spring 2022

### Functionality test

Various functionality tests are conducted in hashtabletest.c: 

* TEST 1: creating an empty hashtable
* TEST 2: inserting nodes into a valid hashtable
* TEST 3: inserting nodes into a null hashtable
* TEST 4: inserting null and valid keys into a valid hashtable
* TEST 5: inserting null and valid keys into a null hashtable
* TEST 6: inserting null and valid items into a valid hashtable
* TEST 7: inserting null and valid items into a null hashtable
* TEST 8: finding item in a valid hashtable with null and valid keys
* TEST 9: finding item in a null hashtable with null and valid keys
* TEST 10: printing a valid hashtable with valid and null files and itemprints
* TEST 11: printing a null hashtable
* TEST 12: iterating a valid hashtable
* TEST 13: deleting a valid hashtable




#### Functionality test output
```
./hashtabletest
Testing hashtable_insert

Making sure NULL is ignored by insert

Testing hashtable_find. Should print 4.0, 3.0, (null), 1.0, 2.0
4.0, 3.0, (null) 2.0, 1.0, 

Making sure NULL is handled by find. Should print all (null)
(null), (null), (null) (null), (null), 

Testing hashtable_print.
{(Adam, 1.0)}
{(Dylan, 4.0)}
{}
{}
{(Mary, 2.0), (Test, 3.0)}


Testing hashtable_print with null itemprint.
{}
{}
{}
{}
{}


Testing hashtable_print with null file.


Testing hashtable_iterate by counting the key pairs. Should print 4
4

Deleting test hashtable
```

#### Memory test output
```
==22492== 
==22492== HEAP SUMMARY:
==22492==     in use at exit: 0 bytes in 0 blocks
==22492==   total heap usage: 16 allocs, 16 frees, 1,248 bytes allocated
==22492== 
==22492== All heap blocks were freed -- no leaks are possible
==22492== 
==22492== For counts of detected and suppressed errors, rerun with: -v
==22492== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
