# 2.-Course-on-Introduction-to-C-
Important Points from the Course

## HeaderFiles
```
#include<iostream>
// #include is the pre-processor directive
// iostream is a header file
```

## Namespaces
```
using namespace std;
// namespace can be treated of as a shell that contains code maybe from different authors.
// different implementations for doing the same work can exist and can be present in different shells
// to use a particular implementation(from some specific shell we can use namespaces)
```

```
<returnType> main() { return val; }
// main function, program execution starts from here
```

**NOTE**: An executable piece of code is actually a low level code, which gets converted from its parent high level code during the process of compilation.

## Variables
variables : buckets / containers to store data in memory which can be used later.
variable without initialisation contains garbage value.

datatypes : type of data, a variable can hold.
```
<dataType> identifier = val; // declaration + assignment
```
```
<dataType identifier; // declaration
identifer = val; // assignment
```

## Functions
Functions are blocks of code that structures the overall program file and also helps to reuse code.

## Pointers
Pointers store addresses. Size : 8bytes(depends on compiler), but size doesn't vary depending on the datatype. 

Types : 

a. Dangling Pointer : Pointer that was initialised some address but later deleted. 
   ```
   <dataType> *ptr = &x;
   delete ptr;
   ```
