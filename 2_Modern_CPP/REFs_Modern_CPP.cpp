
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

void AnyFunction(int i_Integer)   Pass by Value: the function argument will be a new variable, declared and initialized as a copy of the argument's value
                                  Creates a new copy of the variable passed as an argument  [ slowest ], using 2 different variables on the memory

void AnyFunction(int &i_Integer)   Pass by Reference: also called 'out-parameter', the variable passed by reference will have its value changed by the function
                                   Creates a new copy of the address of the variable passed as an argument  [ fastest ], using the same variable on the memory

void AnyFunction(const int &i_Integer)   Pass by Reference: also called 'in-parameter', the variable passed by reference won't have its value changed by the function since it's const
                                         Creates a new copy of the address of the variable passed as an argument  [ fastest ], using the same variable on the memory

void AnyFunction(int *i_Integer)   Pass by pointer: should be used only when 'nullptr' is a valid value, otherwise use 'pass-by-reference' since references can't be NULL
                                   Re-assigns the pointer passed as an argument  [ fast ]; pointers can be re-assigned while references cannot; pointers can act as iterators over the memory


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

Vector is a sequential container to store elements and not index based. Array stores a fixed-size sequential collection of elements of the same type and it is index based.
Vector is dynamic in nature so, size increases with insertion of elements. As array is fixed size, once initialized can't be resized.

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


   >>> Files and Streams

In C++, a file is represented by a sequence of bytes, identified by a filename  [ and the developer doesn't need to know where the data is stores or how it is stored]
The 'File Stream' C++ library is very similar to the 'iostream' library  [ file interactions are represented by 'fstream' objects, similar to 'iostream' objects for inputs / outputs ]
'fstream' objects always access files "sequentially"  [ and 'fstreams' do not understand file formats ]
	- a sequence of bytes
	- in order
	- of unknown length
	- with no structure
C++ 'fstream' Object 4 Operations:
	- Open: connects the 'fstream' object to the file, and the file becomes available to use by the C++ program
	- Read: data is copied from the file into the program's memory
	- Write: data is copied from the program's memory to the file
	- Close: disconnects the 'fstream' object from the file, and the file will no longer be available to use by the C++ program

For each 'fstream' object operation [task], the 'fstream' object will call a function on the operating system's API 'Application Program Interface', and the C++ program will stop
and start to wait for the operation to be fully performed. When the operating system has completed the task, the API call will return and then the program will resume its execution

	   >> Opening and Closing a file

As there are many different files on a computer, we need to associate a 'fstream' object with the file being used
For every file handled by the 'fstream' object, the file must be opened before the C++ program starts to use it, and must be closed when the C++ program no longer needs it anymore
This 'best-practice' ensures that any outstanding data is saved to the file, and avoids the possibility of a "too many open files" error  [ even if the C++ program automatically closes all open files ]
It's also a 'best-practice' to close files as soon as the C++ program don't need it to avoid file-locking  [ when 2 parallel tasks tries to open a file that was already opened ]
As data passes between the C++ program and the file, the data is temporarily stored on the memory buffer, making large data transfers more efficient but less faster

To open a file, use the 'ifstream' class and declare a new variable, initializing it with the name of the file  [ e.g.  ifstream Input_File{ "NewTextFile.txt"s }; ]
The 'Input_File' variable will be used as a "communication channel" to receive data from the file  [ sinc it was declared as an 'ifstream' object, read-only ]
The 'variable state' [ is ready to use? ] should always be checked before manipulating the file's data  [ e.g.  if (Input_File) {...},  will return 'true' if it's ready ]
On earlier versions of C++, 'fstream' objects could only take C-style strings for the file name, now replaced by a 'std::string' object acting as a filename
The 'ifstream' object could be used the same way as the 'cin' keyword from the 'iostream' standard library  [ e.g.  while(Input_File >> sNewString) { cout << sNewString << ", "; } ]
    [ this approach will read one word at a time, removing all whitespaces from the input, difficult to handle errors if the file structure doesn't match the C++ program's expectations ]
After handling data from an 'ifstream' object, the object's variable has a '.close()' member function that should be used when the C++ program no longer neeeds the file to be available

To manipulate files within the solution, the file needs to be added to the Vistual Studio C++ project

	   >> Creating a file

The 'ofstream' object has the ability to create new files!  If the specified file-name on the file-path does not exists, the C++ program will create that specified file

	   >> Stream types

iostream:   'cin' keyword for input [istream class], 'cout' keyword for output [ostream class] - only one console on a machine
fstream:     'file stream for reading', input file [ifstream class], 'file stream for writing', output file [ofstream class] - multiple files on a machine

*When 'ofstream' is being used, the write operation [ that sends data to the file ] could overwrite all the previous data to the new sent data, deleting all the previous data

	   >> Streams and Buffering

C++ streams uses 'buffering' to minimize calls to the operating system, holding data into a memory buffer during 'ifstream' write operations
'Flushing' the output buffer is when the size of the buffer reaches its maximum size acceptable by the operating system,
and the stream sends the data from the full-memory-size buffer to the operating system, removing it from the memory buffer
This method sends the maximum amount of data at a minimum amount of operating system calls  [ and there is no direct way to flush input streams ]

For 'ofstream' [ and general output streams, like 'cout' ] the stream buffer is flushed at the end of every line for terminals [ 'cout' is always flushed before the program reads from 'cin' ],
and 'ofstream' is only flushed when the buffer is full [ the same way as 'ifstream', minimizing calls to the operating system ]

std::flush  allows the C++ program to control when the stream's buffer is flushed, and all the data in the buffer is immediately sent to its destination  [ e.g.  cout << iMyInt << flush; ]
*This approach significantly reduces the program's perfomance, and should only be used if the data really needs to be immediately up-to-date  [ e.g.  log files on debugging tests to find crashes ]
*The 'endl' keyword has similar results when compared to 'flsuh'  [ because the stream buffer is flushed at the end of every line ]

	   >> Unbuffered Input - Output

There are some applications that stream buffering is not suitable  [ e.g.  network applications, where data must be transmitted in 'packets' of a fixed size, and data may need to be transmitted
at specific times, completely overwriting the buffer with new data, causing 'packet losses' ]
C++ supports lower level operations on streams  [ bypassing the stream's buffer without formatting data ], mainly used when the C++ software needs more control over how the data is transmitted
[ useful with networking applications and hardware communication, like sound cards ]

Streams have a member function for reading or writing data, one character at a time  [ and both takes a 'char' argument ]:
	- get()   fetches the next character from an input stream
	- put()   sends its argument to an output stream

Streams also have a member function for reading or writing data, using 'blocks of characters' [ array of characters ] instead of 'char-by-char' :
	- read()     to use this member function, the buffer must be large enough to store all the received data from the input
	- write()    to use this member function, the buffer must contain all the data desired to be sent to the output
	- gcount()   returns the number of characters that the memory buffer has received from an input stream [ can be used to detect partial or incomplete data transfers ]
*For both 'read()' and 'write()' member functions [ that doesn't use the std::stream buffer ], a new custom buffer has to be provided by the C++ programmer
*Both 'read()' and 'write()' member functions takes 2 arguments: the address of the buffer, and the number of characters in the buffer

	   >> FileModes

C++ gives a number of options [ called 'modes' ] for opening a file [ and the 'filemode' can be passed as an opntional second argument when opening a file with 'fstream' ]
By default, files are opened in 'text mode'  [ and all the values will be written as ASCII '1-byte' characters ]
By default, output files are opened in 'truncate mode'  [ any data that was previously in the file will be overwritten, and new data will be written from the start of the file ]
	Some other file modes:
	- in      opens the file for input
	          can be used with 'fstream' and 'ifstream' objects only
	- out     opens the file for output, and also in truncate mode [ even if the 'trunc' is not specified ]
	          can be used with 'fstream' and 'ofstream' objects only
	- trunc   opens the file in truncate mode
	          can be used only on output mode, and cannot be combined with 'app'
	- app     specify that the output mode will be on 'append' bote, preserving previously-stored data
	          can be used only on output mode, and cannot be combined with 'trunc'
	- ate     opens the file for output similar to append [ without erasing previously stored data ], but the output also can be written anywhere in the file

To open an 'ofstream' in 'append' mode, pass the 'fstream::app' as the optinal second argument when opening a 'ofstream' file [ when writing, the previously stored data will be preserved,
and the newly written data will be added after the current data, at the end of the file, useful for LOG files! ]

The files can also be read/write on other data formats [ binary, hex, etc ] but they are complicated to be handled and very error-prone [ but sometimes is needed
for working with specific file formats, like media files for audio hardware ]

Multiple FileModes can be combined by writing the Bitwise Operator '|'  [ binary OR ] between the multiple second arguments

	   >> Stream Member functions and States

Member functions:

	- is_open()   checks if the file is open
	- clear()     resets the stream to a valid state  [ good ]
	- eof()       returns true after reaching the end of file

C++ streams have member functions to check the state of the stream
Stream States:

	- good()   returns true if the input was read successfully
	- fail()   returns true if there was a recoverable error  [ e.g.  data in the wrong format ]
	- bad()    returns true if there was an unrecoverable error  [ e.g.  media failure ]



// ====================================================================================================
*/
