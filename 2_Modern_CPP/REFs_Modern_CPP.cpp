
// Douglas Neiva - Learning Notes - Programming Language - Modern C++
// ====================================================================================================
// >>>  Source file (.cpp) - C++ References  ==========================================================
/*

   >>> General tips

C++98 introduced variable declaration and initialization inside a for-loop statement [previously not possible in C, where the iterator variable
should be declared and initialized before the for-loop, and remains on the memory after the for-loop, due to its declaration outside of the for-loop scope]

C++17 allows declaration and initialization of variable on an if-statement and switch-case statement, similar to a for-loop [meaning that the variable to be checked on a condition
can now be created inside of an if-statement, and will exist on the memory only on the if-statement scope, and also can be used on the remaining else-statement]

C++17 also provides a [[fallthrough]] attribute to be used on switch-case-statements, to explicitly indicate that the "break" statement was intentionally omitted

Function arguments:   // TEST ALL !!! -------------------------------------------------------------------------------

void AnyFunction(int i_Integer)   the function argument is a new variable, declared and initialized as a copy of the argument's value

void AnyFunction(int &i_Integer)

void AnyFunction(const int &i_Integer)

void AnyFunction(int *i_Integer)


   >>> Namespaces

Namespaces are used to group together all logically-related symbols [typically done within libraries: the C++ Standard Library
defines the "std" namespace]. Large programs often includes several libraries, leading to name conflicts [e.g. 2 different libraries could define a class with the same name]
A solution for several libraries could be adding a library-specific prefix to the names, but C++ addresses all the names using namespaces, and a best practice
when it comes to library creation is to define a namespace for all the library's symbols
Namespaces can be created by using the "namespace" keyword, and all its symbols [functions, types and variables] will have the namespace's name automatically prefixed
[the same way the scope-resolution-operator "::" is used to find members of a class, it will be used to find symbols of a namespace declared inside namespace's curly-braces]
Namespaces also have hierarchy [it's possible to create namespaces inside namespaces], and namespace symbols will hide any symbols with the same name from outter scopes
To use a namespace's object outside of its scope, write the fully-qualified name of the symbol with the scope=resolution operator "::"

Since large projects have multiple libraries, namespaces also comes with the "using" keyword, to make a symbol of a namespace available as if they are on global space
[e.g.  ::X{22}, Test::X{33};  "return X" will result in 22, but with "using Test::X"; "return X" will result in 33 ]. The "using" keyword takes effect only within its scope
The "using" keyword is not a good practice, since it brings everything from a namespace into the global namespace, bypassing the namespace's functionality

   >>> Templates

On C++, is often needed to write code that is functionally the same, but operates on different types of data
C++ Templates [known as "generic programming"] are C++ code that works with any type of data [writing the functionality with variable-type independency]
Templates can be either a Template Class or a Template Function, but not both at the same time

	   >> Template Instantiation

When a template is used with data of a particular type [template <parameter>], the compiler will generate the code needed for that type [meaning that the compiler will insert
the source code for the plugged-in class definition into the translation unit [the source-code file seen by the compiler], and then compile as part of the program]
e.g. "vector<int>" [the template container "vector" with the parameter "int"] will cause the compiler to define a class [create a new instance] that is a vector of ints
Templates only works when the compiler is able to see the full definition of the template class in the "translation unit"


   >>> Keywords

auto   - The "auto" keyword was originally used in C to specify that a local variable should be created on the stack memory,
         but in C++ it means that the compiler should deduce the variable-type based on the variable's initial value, and ignores variable qualifiers [like "const"]
         It means that the "auto" keyword avoids implicit conversions, and the compiler will use the exact type of the value to be the variable-type
         The "auto" keyword is useful on situations that it's impossible to know what variable-type is returned



   >>> Numeric Types and Literals


Decimal notation is the normal way of writing numbers [base 10]
Hexadecimal notation must have the "0x" prefix on the Hex. value [base 16]
Octal notation must have the "0" prefix on the Oct. value [base 8]
Binary notation [C++14] must have the "0b" prefix on the Bin. value [base 2]


    The size of types depends on the bit-size of the machine [32 bits or 64 bits]
char      - 8 bits
int       - 16 bits
long      - 32 bits
long long - new in C++11
string    - 320 bits
float       - 32 bits, 6 digits of precision
double      - 64 bits, 15 digits of precision
long double - 64 bits, 20 digits of precision

    C++11 introduced fixed-width integers on the <cstdint> library
Signed:  int8_t, int16_t, int32_t, int64_t
Unsigned:  uint8_t, uint16_t, uint32_t, uint64_t

The traditional string literal is an array of const char, terminated by a null character [C-style string]
On C++14, the "S" suffix can be added after closing the double quotes by "using namespace std::literals" C++14, supporting all std::string operations [like addition]


   >>> Custom Data Types


size_t   The datatype 'size_t' is unsigned integral type. It represents the size of any object in bytes and is returned by the 'sizeof' operator.
         It is used for array indexing and counting. It can never be negative

int 1D_Array[] = {3, 5, 7, 9};   // 1D Array can be initialized [and the size will be automatically calculated] or can be defined at a fixed size "int 1D_Array[4];"

int 2D_Array[2][4];   // Two-dimensional Array of 2 rows [outer-array] and 4 columns [inner-array],
                      // a 2D array is stored as a single memory block, following data order from left-to-right, top-to-bottom,
                      // and should be initialized as nested arrays using curly-braces [each array being a single row], as shown below

string 2D_Array_Names[2][4] = {
    {"Djow_00", "Djow_01", "Djow_02", "Djow_03"},   // Using a single subscript "2D_Array_Names[1]" will return a row, the outer-array
    {"Djow_10", "Djow_11", "Djow_12", "Djow_13"}    // Using two subscripts "2D_Array_Names[1][2]" will return an element of the inner-array
    };                                              // To iterate over an array, use two loops, one iterating over each row, and one inside to iterate over each column of that row


   >>> Function pointers

Every executable code is stored on the memory, and its possible to create a pointer that points to a function [the address of the executable code's starting point]
A pointer-to-function variable is a 'callable object' that beahves like a variable but can be called like a function by dereferencing the pointer
A pointer-to-function variable is also a 'first-class-object', that can be passed as an argument to another function or can be returned from another function


   >>> C++ Standard Libraries - std::

	   >> Vector   [ member functions also available on std::string ]

std::vector has a 'data()' member function that returns a pointer to the container's internal memory buffer, useful for working with APIs written in C

swap()   swaps the data between two vector elements [ this function is very fast when compared to a 'manual swap', without memory operations or copying data ]

	   >> Character   [ C++ is 'case-sensitive' ]

The C++ standard library has many character fucntions inherited from C. Some of the most useful are:

isdigit(char)   returns true if 'char' is a digit  [ 0-9 ]

islower(char)   returns true if 'char' is lower-case  [ a-z ]

isupper(char)   returns true if 'char' is upper-case  [ A-Z ]

isspace(char)   returns true if 'char' is a whitespace character  [ space, tab, etc ]

ispunct(char)   returns true if 'char' is a punctuation character  [ ? ! , . etc ]

tolower(char)   returns the lower-case equivalent of the argument

toupper(char)   returns the upper-case equivalent of the argument   [ to compare case-insensitive strings, use 'toupper' of every character inside a ranged for-loop ]

	   >> String


The C++ String container is a big interface with more than 100 member functions. Each string has a 'header'
[ composed by an integer with the character count, and a pointer to the character data ]
The std::string member functions are:

c_str()   returns a copy of the string data as a C-style string [which is an array of characters "const char", terminated by a null character], avoiding the need of creating C-style strings
on the code [just convert noraml C++ strings when needed]

substr()   returns a substring, starting at a given index [first index] of the original string and ending at a given index [second index] of the original string

find()   member function finds the first occurence of its arguments in the string [case-sensitive, and can be a char, a std::string or a C-style string] and returns the index [size_t] of the first match
If there's no match, it returns "string::npos" [it represents an impossible index], and the return value must always be checked

rfind()   'reverse find', similar to the 'find()' member function, but returns the index of the last occurrence [the searching starts from the end of the string]

append()   adds elements at the end of the string

insert()   adds elements at a specified index

erase()   removes characters from the string by a given index to a given length to be deleted

replace()   will remove characters at a a given index by a given length to a given string

assign()   replace all the string to a new one

To convert between strings and numbers, C provided the functions 'atoi()', 'atod()' to convert C-style strings to numbers
C++11 provides the function 'to_string()' that retuns an std::string literal [the function overloads supports 'int' and 'float' types]
and provides the function 'stoi()' that returns an integer from a given string [the string must contain only numbers, with no whitespaces]
The 'stod' works for floating points, and returns a 'double' variable type



// ====================================================================================================
*/
