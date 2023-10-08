
// Douglas Neiva - Learning Notes - Programming Language - Classical C++
// ====================================================================================================
// >>>  Source file (.cpp) - C++ References  ==========================================================
/*

   >>> Introduction

Flow of control: C++ runs the code line-by-line (a single expression at once), from top to bottom, and each expression ends with ;
At each line of code (expression), C++ reads the line from right to left (at the same line, the last statement will be executed first!)

Declaration: instancing a new variable / function (ex.:  "bool bCondition"; "bool" is a datatype, "bCondition" is a variable)
Definition: creating the scope of a new function (ex.: "void Print(string text)" is a declaration, "{ cout << text; }" is a definition
Initialization: assigning a value to the variable (ex.: "bCondition = false"; "false" is a value)

C++ object-oriented programming have 4 concepts: abstraction, encapsulation, inheritance and polymorphism
- Abstraction: multiple objects (instances, or entities) can be created from a class, and a class (type, or template) is a definition of
			   what is the object and what are its members (relevant data) that could be properties (variables) and methods (functions)
			   [abstraction is all about simplifying reality]
- Encapsulation: protected / private (hidden) variables and functions within classes, accessible only via public class methods (data integrity)
				 by getter / setter functions, to perform checks and logs, and avoid data corruption or invalid assignments
- Inheritance: derived classes (child, or subclass) that inherits all base class (parent, or superclass) members
			   (variables [properties] and functions [methods]), controlled by access modifiers (public, protected and private),
			   extending the base class functionality ("type of" relationship)
			   C++ also allows multiple inheritance (one sub-class can have multiple base-classes, inheriting its properties)
- Polymorphism: ability of variables, functions and objects to take many different forms and performing different tasks
				by calling the same name (variable, function or object) and expecting multiple behaviors based on input / output signatures
				There are 2 types of polymorphism: overloading (at compile time), and overriding (at runtime),
				and must be used on derivation chains (inheritance hierarchy), overriding base-class functions by sub-class functions


// ====================================================================================================
   >>> Libraries

 #include <iostream>   // header file able to run cout and cin statements
 #include <iomanip>   // header file able to manipulate the iostream data (inputs and outputs)

 #include <string>   // header file able to use string datatypes (a string is an array of chars)

 #include <stdio.h>   // printf, scanf, puts, NULL
 #include <stdlib.h>   // srand, rand
 #include <time.h>   // time

 #include <cstdlib>   // system("pause")


// ====================================================================================================
   >>> Primitive Datatypes

 void   (nothing)
 bool   (1 byte)
 char   (1 byte), follows the ASCII table (ex.:  ++'(' = ')' )
 int   (4 bytes)
 float   (4 bytes) up to 6 decimal digits, and needs the "F" suffix (ex.: float MyFloat = 3.141592F)
 double   (8 bytes)
 std::string   (24 bytes)

 string   (derived from <string>, is an array of chars + null char at the end of the string) (ex.: "Djow" is a 5 char array (4 + null)
		  strings are null-terminated char arrays, and must end with "\0" (the "null" character, used in C programming language),
		  and even if a string variable has a single character (ex.: "A"), it will be an 2-char array (and double quotes must be used)
		  strings can be concatenated (ex.: myStr1 = "Douglas"; myStr2 = "Neiva; myStr1 += myStr2; returns "DouglasNeiva")


// ====================================================================================================
   >>> Compound Datatypes

Compound datatypes are composed by primitive datatypes

 array[]   arrays are containers to store multiple elements (values of the same datatype) on a "contiguous memory" (ex.: int myIntArray[3])
		   on arrays, elements are stored next to each other in memory (consecutive blocks of memory allocated are called contiguous memory),
		   and enables "random access" (same time required to read any element from an array by specifying the element address of that array),
		   because an array is just a memory location (pointer) that points to a contiguous memory on the hardware (and the first element is the [0] index)

 enum{}   enums are arrays of named const ints, used for representative program states, and all the const int values will be automatically assigned
		  (from 0 to infinite, starting from the first element up to the last) enum arrays are aliases for "const int", from 0 onwards
		  after defining an enum, all its instances must be initialized with one of the elements defined (not a raw integer or int variable)
		  enums are used most by the element names (descriptive states, switch-case state management), and not by its element values
		  enum elements should be referred as enum::element

 struct{}   structs are custom objects (C++ object-oriented programming) that hold several members (any variables, datatypes and functions)
			structs are data structures (objects vith variables and functions) that can be defined with several variables and functions;
			declared as a custom datatype, initialized with any value and modified by the code (structs can also have other structs as members)
			(since structs could have non-constant elements [variables] unlike enums)

 class{}   on object-oriented programming, both structs and classes are blueprints (definitions) for objects (instances)
		   the key differences between structs and classes are:
		   - by default, all struct members are public, cannot be declared as Protected, and uses stack memory allocation (contiguous blocks)
		   - by default, all class members are private, can be declared as Protected, and uses heap memory allocation (random order)
		   - classes enables inheritance and polymorphism
		   - on classes, all variables declared are "properties" of its class; and all functions are "methods" of its class
		   - on both, a function called "constructor" (with same name as the class name) should be created to initialize the variables
		     (properties) of the class / struct, without any return type [ex.: class Character {  Character(); ... } ]; and a function called
			 "destructor" should be created to perform actions when dynamically allocated objects are deleted [ex.: class Character {  ~Character(); ... } ];
		   - on both, all methods (functions) could be only declared at the definition body, and then defined outside the definition body
		     by full qualifiers [ex.: void DefinedClass::DefinedFunction() {} ]
		   - on classes, inheritance is allowed (both classes "Spider" and "Scorpion" could be child classes of the parent class "Arachnid"),
		     where "string Name" and "int Eyes" are defined on the parent class "Arachnid", and "float PoisonDamage" can be defined on child classes

 !!! Pointers that points to array datatypes will return the first element of the array when dereferenced; and can be incremented
	 to read the next array elements
 !!! Private variables are inaccessible by the code without constructors (the function that gets called when the object is created)


// ====================================================================================================
   >>> Datatype Modifiers

       >> Preffix

 signed   (by default, every variable is signed, meaning that it can be positive or negative)
 unsigned   (the variable will never be negative, and its value can be higher than the signed int), and needs the "U" suffix (ex.: unsigned int MyInt = 44U)
 short   (cuts the memory space of the variable by half [short int will have 2 bytes])
 long   (doubles the memory space of the variable [long int will have 8 bytes]), and needs the "L" suffix (ex.: long int MyInt = 44L)
 const   (a variable designed to not be changed, saving memory costs)

 &   (prefix of the variable name = "address of" operator, gets the address of the given variable)
 *   (prefix of the variable name = "dereferencing" operator, gets the value stored on the memory address pointed by the given pointer)
	 (the "*" dereferencing operator only works with Pointer variables [a datatype that contains memory address])

       >> Suffix

 *   (suffix of the variable datatype = pointer datatype [ex.: int* is a datatype "pointer to int"])
 &   (suffix of the variable datatype = REF datatype [ex.: int& is a datatype "REF to int"])


// ====================================================================================================
   >>> Literals and Variables

Any raw data (numbers, chars, strings, etc) is called a "literal" (the number 3 is literally a number, not a variable)
Literals are hardcoded, and cannot be changed, unlike variables (which can be changed)
 !!! Hexadecimal values must start with 0x (ex.: 0xFA8CB5)


// ====================================================================================================
   >>> Variables, REFs and Pointers

 int Var   a variable wich can be declared, initialized with raw data and changed; and requires memory space to be stored on the hardware

 int& ref_Var   alias (or pseudonym), reference variable for an "int" datatype (always initialized with other variable, to reference its address)
				REFs must be declared and initialized at the same line, using the address of its parent variable
				REFs are initialized by passing the reffered variable name as the REF value

 int* ptr_Var   pointer for an "int" datatype (memory efficiency, memory management)
				pointers points to addresses that contains segments of memory allocated on the hardware (ex.: 4 bytes for an int variable),
				pointing at the first byte of the pointed memory segment (every memory byte location [address] is an hexadecimal number)
				Pointers take up 32 bits (4 bytes) of memory on 32-bit machines; and 64 bits (8 bytes) of memory on 64-bit machines,
				and is very memory-efficient when dealing with large amounts of data (ex.: structs with several members)
				(pointers can be declared without being initialized, and are initialized with the address of some variable or struct)
				pointers also can be incremented or decremented (moving to the next / previous block of contiguous memory, useful with arrays)
				When pointers are used with structs, they can acess struct members when dereferenced [ex.: (*ptr_Location).X ], and
				"syntactic sugar" can be used to achieve the same results without dereferencing the pointer [ex.: ptr_Location -> X ]
				using the "arrow" operator (access members of structs and classes)

 !!! reference variables doesn't take extra memory (faster), while pointers stores address data (and needs memory)


// ====================================================================================================
   >>> Operators

       >> Arithmetic Operators

 +   addition
 ++   add 1  (pre-increment: ++i first add +1, then return.  post-increment: i++ first return, then add +1)
 -   subtraction
 --   subtract 1  (pre-decrement: --i first subtract -1, then return.  post-decrement: i-- first return, then subtract -1)
 *   multiplication
 /   division
 %   remainder of division

       >> Assignment Operators

 =   assign
 +=   add and assign
 -=   subtract and assign
 *=   multiply and assign
 /=   divide and assign
 %=   divide by and assign the remainder of division

       >> Relational Operators

 >   greater than
 <   less than
 >=   greater than or equal
 <=   less than or equal
 ==   is equal to   (= is the assignment operator!)
 !=   is not equal to

       >> Logical Operators

 &&   logical AND
 ||   logical OR
 !   logical NOT

       >> Bitwise Operators

 &   binary AND
 |   binary OR
 ^   binary XOR
 ~   binary One's Complement
 <<   binary Shift Left
 >>   binary Shift Risght

       >> Other Operators

 sizeof   returns the size of data type
 :   "single colon", can be used for: function initialization list, class inheritance, and access modifiers
 ::   "scope resolution" operator, access methods within scope of the given class / struct
 ?:   returns value based on the condition
 &   "address of" operator, reference sign, represents the memory address of the operand
 .   accesses members of struct variables or class objects
 ->   "arrow" operator, used with pointers to access members of classes or structs
 <<   prints the value to the "cout" statement
 >>   gets the input from the "cin" statement
 ~   "destructor function" operator, used within classes


// ====================================================================================================
   >>> Statements

 if (condition) {code}, if-else, if-else-if ...
 switch (variable) {case1 <condition1>: break;  case2 <condition2>: break; default:} ...

 !!! Performance (less speed): array lookup (random acess) > switch-case < if-else-if (switch-case goes straight to the required condition)


// ====================================================================================================
   >>> Functions

On C++, only 1 function called "int main()" can (and must) exist for all source files (.cpp) inside a solution!
If the solution have multiple source files (.cpp), and two or more files contains the "int main()" function,
the compiler will return an error (the "int main()" function is the core of C++, and will be the first to be executed).

Every function must be written immediatly above the "int main()" function!
Otherwise (if the function implementation is written below the "int main()"),
the same function must be declared above "int main()" (requiring more lines of code).

Refactoring is a powerful skill, and can be achieved by making the code more developer-friendly without change its behavior.
Code refactoring is a way to group multiple lines of code (and multiple functions) into a single (and self-descriptive) function,
where the entire code can be read with more abstraction (higher the abstraction level, more closer to the human understanding).

Always think on code reusability (each function designed to run a single specific task) on development, saving memory and lines of code.


// ====================================================================================================
   >>> Function Arguments

Arguments on functions (inputs) can be passed:
- by value (creating a copy of the parameter on the memory), and the variable outside the function remains unchanged,
  only the copy of the variable inside the function will be changed
- by reference (using REFs, creating a copy of the parameter address on the memory)
- by address (using pointers that points to the original segment of memory allocated by the variable definition)


// ====================================================================================================
   >>> Function Overloading

The same function name (ex.: void PrintNumber(int Num) ) can be used with different (and multiple) inputs (ex.: void PrintNumber (double Num1, float Num2) )
For the case shown above, the same function "has 2 overloads, each one with its own input signature", and overloads are based on argument datatypes
(the "cout" itself is an overloaded function: can print int, char, string, double... etc)
Changing only the return type of a function won't be an overloading operation (ex.: void Print(int iVar) and int Print(int iVar) )


// ====================================================================================================
   >>> Loops

 while(){}   checks the condition: if its true, runs the "while" loop body and check the condition again; if its false, exit the loop body
 do {} while()   runs the "do" loop body once before checking the condition, and runs the loop body again if the condition is true
 for (;;)   the first statement is the declaration of a variable, the second statement is the condition, the third statement is the increment
            execution flow: first the declaration (once), then the condition, then the loop body, then the increment; then the condition again

 break   stops the loop iteration at current line and moves to the next line of code outside of the loop body
 continue   stops the loop iteration at current line and runs the iteration again, skipping the following lines of code inside the loop body


// ====================================================================================================
   >>> Memory Management

The memory used by the program is divided into multiple sections, each one with its own address on the hardware
There are sections for the program itself (compiled code), for global variables, for functions, for addresses, and so on
Each memory block has a size of 1 byte (8 bits), and the pointer's memory size depends on the system architecture (32-bit or 64-bit)
All memory addresses of a program are stored on a "stack" data structure (last input, first output, both on top of the stack)

Every time a function is called, the program will store the address of the return point into the stack memory, execute the function,
and then use the address stored on the stack memory to go back to the previous scope that was being executed before the function was called
(also, each variable declared inside the function will have its address stored on the stack memory, getting out when the function scope ends)

In C++, the first address added to the stack (when the program starts) is the "int main()" function address, always at the bottom of the stack
The "stack" data structure is an static memory type, used to keep track of the "flow of control" of the C++ program
"pop" is the act of getting the lastest data (on top of the stack) out of the stack memory (and consequently removing it from the stack)

During the runtime, the C++ program also use the "heap" data structure (dynamically allocated at the runtime)
The "heap" memory is used when the programmer is uncertain about the memory size of the variable to be used

The C++ Memory Management is all about allocating (according to the program needs) and deallocating (as soon as the job is done)
The keyword "new" is used to dynamically allocate a variable on the "heap" memory, and returns a pointer to the variable address (ex.: new int)
The keyword "delete" is used to dynamically deallocate a variable on the "heap" memory by using its pointer on the "stack" memory (ex.: delete ptr_ToHeap)
The keyword "static" is used to keep the variable on the memory even if the scope where it is inserted ends (unlike local variables,that gets
    deleted automatically by the program when the scope ends), and must be declared and initialized at the same line of code; and if the
	flow of control reach the "static" variable expression again, it won't be executed (variables cannot be initialized 2 times) (ex.: static int Count = 5;)
	Since "static" variables and functions can be declared only once, its useful to create shared parameters among class objects (ex.: static int ObjectCount = 0;)
The keyword "virtual" is used to override inherited methods (functions) within classes [ex.: virtual void SetType() ]

Common variables (without keywords "new" and "delete") are allocated on the stack (ex.: int* PointerToInt),
Local variables (without keyword "static") will be deleted automatically by the program when the scope ends
Global variables (and "static") persists on the memory on all program lifecycle on a memory space called "data section",
(different from "heap" and "stack"), but "static" variables cannot be accessed outside of its scope.
Stack and Data Section memories are managed at the runtime by the program, Heap memory is managed by the programmer.


// ====================================================================================================
*/
