# CS50 Lab 3
## CS50 Spring 2022

### Functionality test

Various functionality tests are conducted in counterstest.c: 

* TEST 1: creating an empty counter
* TEST 2: inserting nodes into a valid counter
* TEST 3: inserting nodes into a null counter
* TEST 4: inserting negative key into a valid counter
* TEST 5: inserting negative key into a null counter
* TEST 6: setting a negative key's counter in a valid counter
* TEST 7: setting a valid key's counter in a valid counter
* TEST 8: setting a valid key's counter in a null counter
* TEST 9: getting counter in a valid counter with valid key
* TEST 10: getting counter in a null counter with valid key 
* TEST 11: getting counter in a valid counter with negative key and nonexistent key
* TEST 12: printing a valid counter
* TEST 13: printing a null counter
* TEST 14: printing a valid counter with a null file
* TEST 15: deleting a valid counter



#### Functionality test output
```
./counterstest
Testing counters_add

Making sure NULL is ignored by add

Testing counters_set. Should print 0, 1, 1
0, 1, 1

Testing counters_get. Should print 0, 2, 3, 0
0, 2, 3, 0

Making sure NULL is handled by get. Should print all zeros
0, 0, 0, 0

Testing counters_print. Should print {(2,3), (1,2)}
{(2, 3), (1, 2)}

Testing counters_print with null file

Making sure NULL is handled by print
(null)

Testing counters_iterate by counting the counters. Should print 2
2

Deleting test counter

```

#### Memory test output
```
==40294== 
==40294== HEAP SUMMARY:
==40294==     in use at exit: 0 bytes in 0 blocks
==40294==   total heap usage: 4 allocs, 4 frees, 1,064 bytes allocated
==40294== 
==40294== All heap blocks were freed -- no leaks are possible
==40294== 
==40294== For counts of detected and suppressed errors, rerun with: -v
==40294== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
