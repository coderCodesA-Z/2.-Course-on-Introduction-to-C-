# 2.-Course-on-Introduction-to-C-
Important Points from the Course

**Note:** 
Single Core Processor : Context Switching Happens. Capable of executing 1 process only(10^8 ops/sec)
Multi Core Processor : Capable of running more than 1 process at a time.
Point to be noted: 10^8 ops/sec capable of being executed by a processor.


## HeaderFiles
```
#include<iostream>
// #include is the pre-processor directive that is used to include header files.
// iostream is a header file, standard input output stream header file of c++
```

## Namespaces
```
using namespace std; // std is the standard namespace of c++
// Namespace can be treated of as a shell that contains code maybe from different authors(developers).
// Different implementations for doing the same work can exist and can be present in different shells[namespaces]
// To use a particular implementation(from some specific shell we can use namespaces) we can mention the 
// namespace we want to use.
```

```
<returnType> main() { return val; }
// main function, program execution starts from here
```

**Compilation:** 
```
g++ fileName.cpp -o run
./run
```

**NOTE**: An executable piece of code is actually a low level code, which gets converted from its parent high level code during the process of compilation.

## Variables
variables : buckets / containers to store data in memory which can be used later.
variable without initialisation contains garbage value.
After initialisation, the variable holds the actual value.

datatype : type of data, a variable can hold.
```
<dataType> identifier = <optional val>; // declaration + assignment
```
```
<dataType identifier; // declaration
identifer = val; // assignment
```
Datatypes : int, float, char, bool, ......

Identifier Naming Rules : 
 - Names can contain letters, digits and underscores
 - Names must begin with a letter or an underscore ()
 - Names are case sensitive (myVar and myvar are different variables)
 - Names cannot contain whitespaces or special characters like !, #, %, etc.
 - Reserved words (like C++ keywords, such as int) cannot be used as names

 sizeof() -> returns size of a datatype or variable.

 **Note:** Size of datatypes vary, depending on compilers. 

 MAX_INT + 1 => Value Wrap Around in c++. Values becomes negative.

## Functions
Functions are blocks of code that structures the overall program file and also helps to reuse code.

Arguments : passed to functions. (Inputs)

Parameters : Recieved in the functions.(DataHolders for the Inputs)

Output is the return value.

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
Primitives are shared as copy, actual address location of the primitive variable is not shared.
**Note:** If an array was created inside a function other than the main(), then it's instance is destroyed 

as soon as the function gets removed from call stack.

## Pointers
Pointers store addresses. Size : 8bytes(depends on compiler), but size doesn't vary depending on the datatype. 

```
<dataType of var> *ptrName = &varName; 
cout<< ptrName<<"\n"; // address of variable
cout<< *ptrName<<"\n"; // value present within the address of variable. Dereferencing
```

**Pointer that stores address of another pointer is a double pointer.** 
```
int a = 10;
int *p1 = &a;
int **p2 = &p2;
```

Pointers can be incremented / decremented. They support pointer arithmetics.

**Note:** Array name is the base address of an array.

Memory allocated during process execution :

1. Stack Memory -> Local Vars stored, Function Calls are pushed(stack frame), also stores record of code execution.
 
2. Heap Memory -> Huge Pool of Memory(new, delete)

**Types :**

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
    <dataType> *ptr = null; // null in ascii is '\0'
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

 ```
 Source Code -> Compiler(compiles + makes optimizations) -> Assembly Code -> Object Code -> Linking and Loading -> Executable File 
 ```

 Integers stored in memory as -> Binary.

 Binary -> a> Unsigned b> Signed

 Positive Numbers in Binary Form and, 

 Negative Numbers Stored in 2's Compliment.

 ## Strings
 **Declaring Strings**
 ```
 string str = "abc"; // abc
 string strr("abc"); // abc
 string strrr('q', 10); // qqqqqqqqqq

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
 str.push_back(el); -> append a character
 str.find(substring); -> substring search
 str.size() -> returns the size of the string
 str.substr(pos, size) -> returns a slice of the string
 str.at(idx) -> same thing as str[idx], returns the character present at any index 
 str.swap(str1); -> swaps the content of both strings.
 ```

 **Taking String User-inputs**
 ```
 string ip;
 cin>>ip; // string user-input without spaces. Terminates when whitespace found.

 // cin.get(charArrayName, size); -> works only for C-style strings(character array implementation)

 getline(cin, ip); // best-way
 ```

 **Taking multiple inputs**
 ```
 // Take multiple string inputs without knowing how many strings will be present.
 string str;
 while(getline(cin, str)) { // getline functions true/false based on input recieved
   cout<<str<<"\n"; 
 }

 // if multiple number inputs to be taken 
 int x;
 while(cin>>x) {
   cout<<x<<"\n";
 }
 ```

 **Tokenising**

 Tokenising refers to the separation of a string based on delimeters.
 ```
 string str = "abc@def@ghi";
 char *token = strtok(str, '@');

 // C-style tokenisation
 while(token != NULL) {
   cout<<token<<"\n"; 
   token = strtok(NULL, '@');
 }

 string str1 = "abc@def@ghi";
 // C++ way of tokenisation
 isstringstream var(str1); // convert the string to a string stream. include <sstream> and <string> header files
 string token1;
 while(getline(var, token1, '@')) {
   cout<< token1<<"\n";
 }
 ```
 **Comparing Strings**
 ```
 string str = "abc";
 string str1 = str;
 cout<<str == str1;
 ```

 **Conversion of string to integer and vice-versa**
 ```
 string s = "123";
 cout<<stoi(s);
 int x = 10;
 cout<<to_string(x);
 ```

 **NOTE** : Always pass strings to functions as references, else a copy is passed.

 **Concatenation**
 ```
 str+=str1; // str1 appended to old string. No new string created in memory hence faster
 str = str + str1; // new string created in memory after concatenation. Slower
 ```

 ## Structs
 User-defined Datatype to store data of non-similar type as a single unit. 

 Structs are not stored as arrays in memory.
 ```
 struct Point {
   int x, y;
 };

 int main() {
   struct Point p;
   p.x = 10; // initialise values using dot operator
   p.y = 20;

   p = {30, 40}; // initialise values 

   cout<<p.x<<" "<<p.y<<"\n"; // accessing using dot operator
   return 0;
 }
 ```

 **Default Values to member fields**
 ```
 struct Point {
   int x = 0, y = 0;
 };

 // if default values assigned to struct members then {} initialisation can no more be used.
 int main() {
   struct Point p;

   // p = {30, 40}; // {} initialisation can no more be used.
   return 0;
 }
 ```
 **Inside structs we can have member fields + member functions.**
 ```
 struct Point {
   // Constructor
   Point(int x1, int y1) {
      x = x1;
      y = y1;
   }

   int x = 0, y = 0;

   void sum() {
      cout<<x + y<<"\n";
   }
 };

 int main() {
   struct Point p = Point(1, 2); // since constructor present, struct needs to be created using constructor.
   // if values not passed, default values gets assigned.
   return 0;
 }
 ```

 **A variable assocaited with struct**

 ```
 struct Point {
   Point(int x1, int y1) {
      x = x1;
      y = y1;
   }

   int x = 0, y = 0;
  

   void sum() {
      cout<<x + y<<"\n";
   }
 // } var = Point(1, 2); // also works
 } var(1, 2); // variable assocaited with struct

 int main() {
   cout<<var.x<<" "<<var.y<<"\n";
   return 0;
 }
 ```
 **Structs can be global as well as local like functions**

 **In C writing "struct" while declararing a struct varaiable is mandatory, but in C++ its not necessary.**
 
 **Static Member Vars in structs**
 ```
 struct Point {
   const static int y = 0;
   static int x; // shared variable. Not a property of the struct vars anymore but part of the struct itself.
 };
 int Point::x = 0; // non-constant static vars needs to be initialised out of the struct block.
 // If the static var is made constant, then it can't be updated

 int main() {
   Point p;
   cout<<p.x<<"\n"; // 0

   p.x+=1;
   cout<<p.x<<"\n"; // 1

   Point p1;
   cout<<p1.x<<"\n"; // 1
   return 0;
 }
 ```
 **Declaring a member function globally**
 ```
 struct Point {
   void display();
 };
 void Point::display() {
   cout<<"Function\n";
 }
 
 int main() {
  struct Point p;
  p.display();
  return 0;
}
 ```

 ## Special Pointers
 **Function Pointers:**
 ```
 void print(string &str) {
   cout<<str<<"\n";
 }

 int main() {
   // void (*ptr)(string) = &print; // if string was not passed as reference
   void (*ptr)(string &str) = &print;
   // void (*ptr)(string &str) = print; // &wow not needed, simply wow works(function name)

   string x = "def";

   (*ptr)(x);

   return 0;
 }
 ```

 Can't allocate/deallocate memory using function pointers.

 **In C++ we can have function pointer arrays if all the functions are of the same return type and input type.**
 ```
 void sayHi(string &str) {
   cout<<"Hi "<<str<<"\n";
 }

 void sayHello(string &str) {
   cout<<"Hello "<<str<<"\n";
 }

 int main() {
   void (*ptr[])(string &str) = {sayHi, sayHello};

   string x = "abc";
   (*ptr[0])(x);
   (*ptr[1])(x);
 }
 ```

 **Passing functions to functions using function pointers**
 ```
 void sayHiHelper(string &x) {
   cout<<"Hi "<<x<<"\n";
 }

 void sayHi(void (*helper)(string &x)) {
   string x = "abc";
   helper(x);
 }

 int main() {
   sayHi(sayHiHelper);
   return 0;
 }
 ```
 **Returning functions from functions using function pointers**
```
int f1() { return 1; }

int f2() { return 2; }

typedef int(*fptr)(); // This creates a type which represents a pointer for a particular function.

fptr f( char &c ) {
   if ( c == '1' ) {
     return f1;
   }
   else {
     return f2;
   }
}

int main() {
   char c = '1';
   ftpr fp = f(c);
   cout << fp() << endl;
}
```

## Smart Pointers
Helps such that we don't have to explicitly delete pointers from memory.

Handles destruction of pointers automatically.

**Note:** delete keyword only helps to delete the connection between the ref var present in the stack and the actual memory location in heap. The memory location however keeps existing until process ends. 

To handle this we have smart pointers. 

**Types:**
a. Unique Pointers : Handles auto destruction of pointer memory, If one object is created & a pointer points to it already then we can't assign any more pointers to point at that memory location.
```
#include <memory>
struct Point {
   int x = 10;
};

int main() {
   unique_ptr<Point> p1(new Point); // pointing to struct 
   unique_ptr<Point> p2;
   // p2 = p1; // not possible
   cout<<p1->x<<'\n'; // arrow operator is used to access any field of an object from memory that is pointed by the pointer
}
```

b. Smart Pointers : Multiple Pointers can point to same object.
```
#include <memory>
struct Point {
   int x = 10;
};

void demo(shared_ptr<Point> &p1) {
   shared_ptr<Point> p4(new Point);
   p4 = p1;
   cout<<p1.use_count()<<"\n";
   cout<<p4.use_count()<<"\n";
}

int main() {
   shared_ptr<Point> p1(new Point); // pointing to struct 
   shared_ptr<Point> p2(new Point);
   shared_ptr<Point> p3(new Point);

   p2 = p1;
   p3 = p1;

   demo(p1);


   // Reference Counter : Stores the count of the pointers pointing to the same memory location
   cout<<p1.use_count()<<"\n"; // . operator used because use_count() is a method of the shared_pointer object
   cout<<p2.use_count()<<"\n";
   cout<<p3.use_count()<<"\n";

   return 0;
}
```

**Note**:

If we have a function pointer, we can dereference it any number of times.  `*****(fptr)(1, 2);`

But in case of normal pointers that is pointing to a variable, dereferencing more than once won't be possible.

## Enums:
Maps any string to a value.
```
enum e{M,F};
cout<<M<<" "<<F<<"\n"; // 0 1

enums f{M=1, F, G};
cout<<M<<" "<<F<<" "<<G<<"\n"; // 1 2 3

enums f{M, F = 5, G};
cout<<M<<" "<<F<<" "<<G<<"\n"; // 0 5 6
```

