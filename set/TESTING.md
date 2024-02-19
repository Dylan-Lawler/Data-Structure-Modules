# CS50 Lab 3
## CS50 Spring 2022

### Functionality test

Various functionality tests are conducted in settest.c: 

* TEST 1: creating an empty set
* TEST 2: inserting nodes into a valid set
* TEST 3: inserting nodes into a null set
* TEST 4: inserting null and valid keys into a valid set
* TEST 5: inserting null and valid keys into a null set
* TEST 6: inserting null and valid items into a valid set
* TEST 7: inserting null and valid items into a null set
* TEST 8: finding item in a valid set with null and valid keys
* TEST 9: finding item in a null set with null and valid keys
* TEST 10: printing a valid set with valid and null files and itemprints
* TEST 11: printing a null set
* TEST 12: iterating a valid set
* TEST 13: deleting a valid set




#### Functionality test output
```
./settest
Testing set_insert

Making sure NULL is ignored by insert

Testing set_find. Should print 4.0, 3.0, (null)
4.0, 3.0, (null) 

Making sure NULL is handled by find. Should print all (null)
(null), (null), (null) 

Testing set_print. Should print {(Test, 3.0), (Dylan, 4.0)}
{(Test, 3.0), (Dylan, 4.0)}

Making sure NULL set  is handled by print. Should print (null)
(null)

Making sure NULL itemprint is handled by print. Should print empty set
{}

Testing set_print with null file

Testing set_iterate by counting the set. Should print 2
2

Deleting test set
```

#### Memory test output
```
==32392== 
==32392== HEAP SUMMARY:
==32392==     in use at exit: 0 bytes in 0 blocks
==32392==   total heap usage: 6 allocs, 6 frees, 1,096 bytes allocated
==32392== 
==32392== All heap blocks were freed -- no leaks are possible
==32392== 
==32392== For counts of detected and suppressed errors, rerun with: -v
==32392== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
