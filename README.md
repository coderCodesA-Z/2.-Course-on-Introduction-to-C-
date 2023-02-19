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

Arguments : passed to functions

Parameters : Recieved in the functions.

Parameter Types :

a. Default

b. Actual

c. Formal

**Pass By Value, Pass By Reference**
```
<returnType> function1(int a, int b) {} // a & b are recieved a copy of actual arguments
<returnType> function2(int &a, int &b) {} // a & b are pointing to the same memory address where actual parameters are located.
<returnType> function3(int *a, int *b) {} // a & b are pointers to the actual arguments
```


## Pointers
Pointers store addresses. Size : 8bytes(depends on compiler), but size doesn't vary depending on the datatype. 

```
<dataType of var> *ptrName = &varName; 
cout<< ptrName<<"\n"; // address of variable
cout<< *ptrName<<"\n"; // value present within the address of variable. Dereferencing
```

Types : 

a. Dangling Pointer : Pointer that was initialised some address but later deleted. 
   ```
   <dataType> *ptr = &x;
   delete ptr;
   ```

b. Wild Pointer : Pointer created but not assigned some value.
   ```
   <dataType> *ptr;
   ```
c. Null Pointer : Special Pointer pointing to null value.
   ```
    <dataType> *ptr = null;
   ```

d. Void Pointer : Special Pointer that points to some memory address, not specific.
   ```
   void *ptr;
   ```
   Pointer arithmetics not possible on void pointer.

   Dereferencing not possible on void pointer. Until typecasting.

**Memory Leakage** 
If pointers are not handled carefully, there can be memory leakages. 
Dangling Pointers and Wild Pointers can cause this issue, so they should be pointed to null to avoid it.
Memory Leakages are instances where some part of memory space can be accessed by the pointers even though it was supposed to be a hidden data.

 ## References
 Aliases to actual variables present in memory.

 ## Pointers vs References
 Pointers are variables themselves that stores address whereas references are just aliases.

 Pointers can be assigned any time after declaration, References needs to be initialised when declared.

 Pointers can be reassigned whereas References can't be reassigned.

 Pointers can be null but not references.

 Pointers support pointer arithmetics but not references.

 Pointers can be deeply nested but not references. [Double Pointer : Pointer Pointing to Pointer....]

 ## Compilation and Internals
 g++ -E learn.cpp -> pre-processing result

 g++ -E learn.cpp > learn1.cpp -> store the pre-processed result of learn.cpp in learn1.cpp

 g++ -E -O1 learn.cpp > learn2.cpp -> store level1 optimisation of learn.cpp in learn1.cpp

 g++ -E -O2 learn.cpp > learn3.cpp -> store level2 optimisation of learn.cpp in learn3.cpp

 g++ -E -O3 learn.cpp > learn4.cpp -> store level3 optimisation of learn.cpp in learn4.cpp

 g++ -S learn.cpp -o learn.s -> generate assemly file of learn.cpp

 Source Code -> Compiler(compiles + makes optimizations) -> Assembly Code -> Object Code -> Linking and Loading -> Executable File 

 ## Strings
 **Declaring Strings**
 ```
 string str = "abc";

 char str1[] = "def";
 char str2[] = {'g', 'h', 'i', '\0'}; // '/0' is the Null character used for terminating strings.

 const char *str3 = "string"; // without 'const' c++ throws a warning. 
 
 // Use of string implementation : 
 // 1. Mutable String Needed.
 // 2. Dynamic String, can be updated, characters can be appended etc.
 // 3. also has lots of in-built methods.
 // 4. Reserves memory in stack, but if size if large then based on the size, memory is reserved 
 //    in heap as well. 

 // char[] use, C-style strings : 
 // 1. Avoid, reserves memory in stack.

 // const char* use :
 // 1. size not needed.
 // 2. immutable strings. 
 ```

 **Note** : When using `string` implementation don't use headers like : 

 #include<cstring>
 #include<string.h>
 Then string becomes a c-style string.

 Some important string methods : 
 ```
 
 ```
