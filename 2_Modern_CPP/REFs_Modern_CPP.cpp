
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

void AnyFunction(const int &i_Integer)   Pass by Constant Reference: also called 'in-parameter', the variable passed by reference won't have its value changed by the function since it's const
                                         Creates a new copy of the address of the variable passed as an argument  [ fastest ], using the same variable on the memory

void AnyFunction(int *i_Integer)   Pass by pointer: should be used only when 'nullptr' is a valid value, otherwise use 'pass-by-reference' since references can't be NULL
                                   Re-assigns the pointer passed as an argument  [ fast ]; pointers can be re-assigned while references cannot; pointers can act as iterators over the memory

Literal V.S. Keyword V.S. Expression V.S. Statement

A literal is a pure value from a variable type
A keyword is a specific word that is used by C++ to write code
An expression is anything that returns a value whether or not the value is used
A statement is analogous to a line of code. It may do many things but it's treated as a unit of execution, and is always terminated with a semicolon.


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
char      - 8 bits [ 1 byte ]
int       - 16 bits [ 2 bytes ]
long      - 32 bits [ 4 bytes ]
long long - new in C++11
string    - 320 bits [ 40 bytes ]
float       - 32 bits, 6 digits of precision [ 4 bytes ]
double      - 64 bits, 15 digits of precision [ 8 bytes ]
long double - 64 bits, 20 digits of precision [ 8 bytes ]

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
	- clear()     resets the stream to a valid state
	- eof()       returns true after reaching the end of file
	- ignore()    similar to 'flush()' of output streams, but instead of sending, the remaining data will be deleted [ ignored ]
	              it takes 2 arguments: the maximum number of characters to remove, the 'delimiter character' [ stops removing characters ]

*The 2 member functions 'clear()' and 'ignore()' must always be used together!

C++ streams have member functions to check the state of the stream
Stream States:

	- good()   returns true if the input was read successfully
	- fail()   returns true if there was a recoverable error  [ e.g.  data in the wrong format ]
	- bad()    returns true if there was an unrecoverable error  [ e.g.  media failure ]

*Every time a stream is used, the stream could contain remaining data from the previous operation if the state is 'fail()' or 'bad()'  [ leaving some unprocessed characters
in the buffer ], and the solution is to flush the stream memory buffer before utilizing it again  [ to prevent utilizing the previous data, commonly used with 'cin' ]
Since input streams does not support 'flush', C++ provides the 'ignore()' member function that removes the characters from the buffer

	   >> Stream manipulators and formatting

The C++ program can push a 'manipulator' onto a stream to affect the stream's behavior [ std::flush and std::endl are types of 'manipulators' ]
The C++ standard library provides a number of manipulators on <iostream> and <iomanip> libraries  [ <iomanip> holds the manipulators which take arguments ]

Sometimes, the C++ program needs to present data formatted as a table, with fixed-size output fields, and the 'setw()' manipulator [ adds 'space-characters' ] will pad the output field to
make it the width of its argument  [ 'setw()' takes the argument 'width of the following data output field', affecting only the next data item on the stream, and is defined on <iomanip> ]
Since 'setw()' manipulator is, by default, a 'right-justified' manipulator, the 'left' manipulator should be used before the 'setw()' manipulator to create a left-justified output

The 'left' keyword is also known as a 'sticky' manipulator [ the change on the stream is permanent until it's reverted back to the original format ], changing the stream permanently
The 'setw()' manipulator is 'non-sticky', meaning that it will affect only the next output operation on the stream, and won't make permanent changes on the stream's behavior
[ and, in fact, the 'setw()' manipulator is the only 'non-sticky' manipulator from <iomanip> ]

The 'setfill()' manipulator [ sticky! ] from <iomanip> sets the padding character to its argument [ similar to 'setw()', but adds a custom character instead of a 'white-space' character ]

		  > Floating-point output formats

In scientific notation, digits are displayed with the decimal point immediately after the first significant digit [ known as 'mantissa' ], followed by an 'exponent' which gives
the magnitude of the number as a power of ten  [ e.g.  3.141592e+005 is equal to 3.141592*10^+8;  1.618034e-002 is equal to 1.618034*10^-2;  2.718281e+000 is equal to 2.718281 ]

The 'scientific' keyword manipulator [ sticky! ] forces the stream to use scientific notation, showing seven significant figures including the integer number
The 'fixed' keyword manipulator [ sticky! ] will cause floating-point numbers to be displayed as fixed-point [ all integer digits and 6 decimal places, and very small numbers will be truncated ]

To restore floating-point defaults, the 'defaultfloat' keyword manipulator should be used to reset the 'stream's behavior for floating-point numbers
The default floating-point precision [ the number of decimal places to be displayed ] is 6 decimal places, but can be changed by the 'setprecision()' manipulator


   >>> String Streams

The basic C++ stream is represented by std::ios [ <iostream> ], that contains:

- istream         (cin) input stream for Terminal [ only 1 terminal per machine ]
- ostream         (cout) output stream for Terminal [ only 1 terminal per machine ]

- fstream         general file-stream object
- ifstream        file stream object for reading
- ofstream        file stream object for writing

- stringstream    general string-stream object
- istringstream   string stream object for reading
- ostringstream   string stream object for writing

'fstream' objects can bind one file at its initialization, an then bind another file using the same 'fstream' object variable
'stringstream' objects are defined in <sstream> library, and the 'stringstream' class has an 'std::string' data member [ it has the same member functions as the other stream classes ]

The 'ostringstream' object has an empty std::string object, and the C++ software can store data in this string, using the same operations as for other output streams,
and the 'str()' member function will return a copy the stream's string  [ the 'ostringstream' object could be used to implement a custom 'To_String()' function! ]
'ostringstream' objects are useful when interfacing to systems that expect formatted strings [ e.g.  GUIs, third-party softwares, etc ]

The 'istringstream' object uses a copy of an existing string, useful for processing inputs [ checking for incomplete or corrupted data, checking the correct data format and handling errors ]
The correct way to work with 'istringstream' objects is to assign the raw input into an std::string object, validate the data formatting, and then bind the validated 'string' object
into an 'istringstream' object to be used for valid input-processing C++ code [ this method separates the raw 'string' data from the valid 'istringstream' data ]
'istringstream' objects can be used with the 'getline()' member function to process input more easily than with the 'right-shift' '>>' operator

	   >> Random Access to Streams

Normally, when the C++ software access the stream, the access is done sequentially [ from beginning to end ], but it's possible to access streams randomly [ jumping into a desired position ]
C++ streams [ the 'stream' class ] have a data member storing a 'position marker' that keeps track of where the next read / write operation will be performed
Normally, the 'stream' object controls the marker's position [ placed after the last read for 'read' operations, and placed at the end of the data for 'write' operations ]
However, the C++ software needs to take control of the marker's position to read/write data anywhere in the stream by altering the marker's position [ used by 'fstream' and 'stringstream' objects ]

C++ Streams provides 'seek' [ change ] and 'tell' [ return ] member functions, to manipulate the position of the marker before performing read/write operations:
'seek' and 'tell' operations are only defined for the appropriate 'stream' objects [ 'fstream' and 'stringstream' ]
[ 'get' operations are defined only for input streams ]
[ 'put' operations are defined only for output streams ]

- seekg   (get) sets the current position in an input stream
- seekp   (put) sets the current position in an output stream
- tellg   (get) returns the current position in an input stream
- tellp   (put) returns the current position in an output stream

* If an 'fstream' was opened in 'app' mode, 'seekp' has no effect [ the output will always be written at the end of the file ]
* 'tell' operations returns a 'pos_type' variable that represents a position in the stream, and it can be converted to 'int',
 but the conversion could fail if the stream is on an invalid state, returning '-1' value [ this condition should be checked for error-handling ]
* 'seek' operations can take a 'pos_type' argument, moving the marker to an absolute position [ but they can also move the marker to a relative base-position ]
* 'std::ios_base' provides three 'base-positions':  beg [ the beginning of the stream ], end [ the end of the stream ], cur [ the current marker position ]
  [ e.g.  seekp(-1, std::ios_base::end);  moves the position marker to 10 characters {or 10 bytes} before the end of the file ]
* A good C++ programming practice is to save the marker's current position before changing it, to be retrieved later on the code

The best way to modify a file with random access is by:
- reading it into a istringstream
- get the bound string [ to the 'istringstream' object ] and make the changes to the data
- when ready, overwrite the original file by writing the modified string on the file

Seek and Tell operations can be used to modify a file in-place, but is more complicated and will loss/corrupt original data if the C++ developer doesn't know the data-structure
Otherwise, it may be necessary if there is not enough memory to copy the file's data into a 'stringstream' object and manipulate it

	   >> Stream Iterators

Iterators are commonly used with containers [ arrays and vectors ] for random-access [ jumps anywhere ], taking the same speed to access any element of the container [ no matter what is it position ]
The C++ Standard Library provides iterators which work on streams, defined on the <iterator> library, and since they are parametric types, they should be instantiated with the type of the data
[ e.g.  istream_iterator   reads an input stream;   ostream_iterator   writes an output stream; ]

Stream iterators have a very limited interface, and should be bounded to an input/output stream to be ready to use

- assigning to an 'ostream_iterator' will put an object on the stream  [ only works for output streams, since it's a 'write' operation ]
- dereferencing an 'istream_iterator' will get the object at the iterator position on the stream  [ only works for input streams, since it's a 'read' operation ]
- incrementing an 'istream_iterator' will move the stream's position marker to the next object

* 'ostream_iterator' also has dereferencing '* operator' and incrementing/decrementing '++/-- operators' [ looking similar to common iterator's syntax ]
* to bind an 'ostream_iterator' to an 'ostream' [ output stream ], the iterator-type should be specified as a template-parameter [ e.g.  ostream_iterator<int> OsI_Index(cout); ],
  and every time a value is assigned to the 'ostream_iterator' object, the value will be pushed onto the output stream [ the 'ostream_iterator' will call the 'left-shift' operator ]
* the 'ostream_iterator' could receive a optional second argument which is the delimiter-character [ must be a C-style string ] that will be sent after each iterator assignment

To read multiple inputs, the input stream iterator should be used within a 'for-loop', and the C++ software needs to know when to stop reading the input
In this case, the iterator will be empty where there is no more input to read, detecting the end of input by comparing the iterator against an 'empty iterator'
[ the 'empty iterator' is created without binding an input stream to it, and using the same 'template-parameter' as the desired iterator to be compared against ]


   >>> Binary Files

A binary file is more closer to the hardware than other file-types, and binary code is 'literal' [ the data must be exactly what the data is supposed to be ]
To open a binary file, the output stream should be used on binary mode [ fstream::binary ], but the 'shift-operators << and >>' won't work with binary files
[ text data is corrupted on output, and white-spaces are discarded on input ], instead the C++ software must always use 'write()' and 'read()' member functions with binary files

Data stores on a binary file is all '0 and 1', meaning that there is no abstraction [ and there is nothing that indicates what the data means ]
The data in a binary file should be application-specific, designed in a way that it won't be corrupted by the C++ software, and often binary files uses a standard file-format for storing data
that is meaningful for other applications [ .jpg .bmp .zip and custom file-types ], and the best way to work with binary files is to create a struct whose data members correspond to the fields
of the standard file-format, using the struct as a 'formatting-memory-buffer'

The 'read()' and 'write()' functions takes 2 arguments:
- 1: the address of the struct, represented by a 'pointer-to-char' variable [ the address of the struct should be converted to a 'pointer-to-char' type, using 'reinterpret_cast<char *>()' ]
- 2: the number of bytes of the data to be read/write [ using the 'sizeof()' function ]
* [ e.g.  Os_fNewFile.read (reinterpret_cast<char *>(&bDataStructObject), sizeof(bDataStruct)); ]
* [ e.g.  Os_fNewFile.write(reinterpret_cast<char *>(&bDataStructObject), sizeof(bDataStruct)); ]

	   >> Memory aligment and Padding

Modern hardware is faster, optimized for accessing data which is 'word-aligned', meaning that the address of each object is a multiple of: 4 bytes on 32-bit system, 8 bytes on 64-bit system
[ if a bool variable takes one single bit to be stored on a normal memory, it will take 4 bytes to be stored on 32-bit modern hardware on address 0x1000, and the next bool variable
will take more 4 bytes to be stored on the next address address 0x1004, next to the previous variable; this method is applied for 64-bit modern hardware, using 8-byte memory-blocks addresses ]

If the binary data-struct is not word-aligned, compilers will usually add extra bytes [ padding bytes ], placing the struct members at the right 'word-offsets' [ since a 'char' variable uses
only 1 byte, the compiler will add 3 'padding-bytes' to fill-up the memory block with the 'char' variable, and store the next variable on the next 'multiple-of-4' memory-block  ]

If there are file-formats expecting data to have different 'word-alignment' offsets [ like 2 bytes on 16-bit machines ], most compilers provides a non-standard directive to set the alignment,
and this directive should be used before and after creating the binary data-struct, so the compiler will understand that the binary data-struct have a 'word-alignment' of the number of desired bytes
[ e.g.  #pragma pack(push, 2)   ... Create the data-struct to be used with binary files ...   #pragma pack(pop) ]



   >>> Special Member funtions

If a C++ Class needs to implement one of the special member functions below:
	- Copy Constructor
	- Assignment Operator
	- Destructor
Then it probably needs to implement the other 2 as well [ in C++, this is called 'The Rule of Three', where all the 3 special member functions has to be defined for a given class ]
[ e.g.  Classes with pointers has to acquire resources on the Constructor and release on the Destructor; and 'Deep Copy' and 'Deep Assignment' should be provided for this Class ]
For this case [ classes with resource-management ], all the synthesized special member functions will cause errors or unexpected behaviors on the C++ software
*The Constructor() and the Destructor() are not included in 'The Rule of Three', since they are noth synthesized and should be provided by the C++ developer
to make the class fully functional [ e.g.  initializing data members with default values or empty states, managing resources by acquiring and releasing, etc  ]

	   >> Constructors in Modern C++

The 'Constructor()' member function of a C++ class gets called every time a new class's object is created, and it's used to setup the object [ e.g.  initialize object's data members ]
Data members [ class's variables ] are default-initialized if not set in the constructor [ undefined initial values ]
On C++11, the data members can be initialized on the class itself  [ C++11 also allows "constructors calling constructors", a programming technique called 'delegating constructor' ]

	   >> Copy Constructor

The 'Copy Constructor' is a special member function that takes only one argument: an object of the same class [ implicitly calls 'const Class& Object' ]
The 'Copy Constructor' uses the existing object [ passed as an argument by reference implicitly ] to initialize a new object with the same values of the object passed as an argument
The 'Copy Constructor' is automatically invoked when a new object is initialized from an existing object of the same class

If the 'Copy Constructor' is not explicitly written by the C++ developer, the compiler will 'synthesize' it by copying all the data members [ but the default constructor won't be called
when the new object is created ], but the copy constructor should be explicitly written when the given Class manages resources [ the new object need to have its own version of the resource,
that involves acquiring a new resource and initializing it from the copied object's resource ], creating additional C++ code rather than simply copying all the data members [ like allocating memory,
establishing database connections, etc. ], avoiding different objects managing the same resource

	   >> Assignment Operator

The 'Assignment Operator =' is also a class's member function [ operator= ] that automatically gets called when assigning existing object of the same class, synthesized by the compiler
[ e.g.  if 'Y' and 'Z' are objects from the same class, the 'Y=Z;' statement will behave the same as the 'Y.operator=(Z)' statement, and the data members of Y will have the same values of Z ]
The 'Assignment Operator =' [ taking its argument on the C++ implicit code by const reference  ] also returns the modified object by reference [ not const reference! ],
that can be used with a third object [ e.g.  'X=Y=Z' ], processing all chain-operators from right-to-left of the multiple-assignment statement
[ similar to left-shift chain-operators on streams:  cout << X << Y << Z << endl; ] 

The 'Assignment Operator =' class's member function takes an extra hidden argument [ the 'this' hidden pointer-to-object variable ] when it gets called
The correct signature [ explicit C++ code ] of the assignment operator of a given object from a given class is:  Class& Class::operator=(const Class&)
[ takes a class's object and returns a class's object ], and the modified object could be accessed by dereferencing the 'this' pointer-to-object after the assignment operator
Classes also have the keyword 'this' that returns a hidden pointer-to-object [ the address of the object from a given class ] pointing to the object itself

Since the 'Assignment Operator' is synthesized by the compiler, custom functionality has to be written into the class's body [ similar to the 'Copy Constructor' member function ],
usually applied when the given Class manages resources [ the new object need to have its own version of the resource, that involves acquiring a new resource and initializing it
from the copied object's resource, like allocating memory, establishing database connections, etc. ]. Since the assigned class already has an object of the resource [ which needs
to be released properly ], copying-it to another object will cause resource leaks [ e.g.  the allocated memory could be lost without being released before the 'assignment operator' ],
so the explicit C++ code for the 'assignment operator' should release the resource before copying-it to the object

	   >> Synthesized Member Functions

If class's special member functions [ like 'constructor()', 'destructor()' 'copy constructor()', 'assignment operator()' and others ] are not defined [ explicitly written ]
by the C++ developer, they will be 'synthesized' by the compiler [ Modern C++ also introduced new special member functions, like 'move semantics', and they will be synthesized
only if certain other special member functions are not defined ]

	   >> Conversion Operator

The 'ConversionOperator()' is a class's special member function that converts an object from a class into some other class type [ casting ], and it can be used to define custom 'casting'
A Class can define 'ConversionOperator()' special member functions that gets called whenever a class's object is used on an expression that expects an specific variable type, and the 
'ConversionOperator()' converts the object from the class-type into another variable-type [ casting ]

	   >> Implicit Conversion

Implicit conversions are often used by the compiler when the C++ developer don't explicitly ask for the exact type on an expression, and could lead to unexpected behaviors and software errors
In Modern C++, implicit conversions now will cause errors, and the C++ developer needs to explicitly ask for the exact type by casting [ casting also calls the 'ConversionOperator()'
member function designed for the 'casted-to' type ]
* A constructor with a single argument could act as an 'implicit conversion operator', causing unexpected results when passing an object as a function argument [ in this case, the
'explicit' keyword could be used immediately before the constructor, preventing errors and ensuring that only explicitly-created objects  ]

	   >> 'Default' and 'Delete' keywords on special member functions

		  > Default

Modern C++ allows developers to force the compiler to synthesize special member functions by writing '=default' after the function's parameter list
The advantages of 'defaulted' member functions are:
	- easier to see which special member function does the class have
	- sets the default behavior of the class for special member functions
	- if data members are added or removed, the compiler will automatically update the special member function definition
* Sometimes the compiler won't be able to synthesize '=default' member functions [ when the class has a member that cannot be default-initialized ]

		  > Delete

To prevent objects from being copied, the 'CopyConstructor()' and the 'AssignmentOperator()' should be on the class's 'private' section for Classical C++,
or using the keyword '=delete' at the end of the function on Modern C++, often used for copy operators and conversion operators [ and even non-member functions can be deleted ]
* If the C++ compiler tries to synthesize a member function and that member function doesn't work, the '=delete' keyword will be added to the compiler-created member function

	   >> The 'Friend' keyword

If a non-member function takes a class's object as an argument, the function can only access the class's public members
In this case, the class can declare [ and also define ] a non-member function to be a 'friend', allowing the function to access all the class's members [ public / protected / private ]
As well as functions, another classes can also be declared as a 'friend' within the Class's body, accessing all its public / protected / private members
[ e.g.  a 'Log' class could have member functions that takes another class's objects as arguments, and the 'Log' class could be declared as a 'friend' inside other classes  ]
* Using the 'friend' keyword on non-member functions reduces the 'encapsulation' property of Object-Oriented-Programming, so instead of giving non-member functions full access
   to the class's protected and private members, the C++ developer could write the function inside of the class's body [ public member function ] that implements the functionality,
   and then the non-member function [ that was previously designed to be a 'friend' ] just calls the public member function of the class's object [ keeping encapsulation by
   'delegating' the function call from an non-member function to a public member-function using the class's object ]


   >>> Copying

Using a Class with the RAII idiom [ Resource Acquisition Is Initialization ] to manage a resource means that:
	- the Class will allocate the needed memory for the object on the Constructor();
	- the Class will release  the needed memory for the object on the ~Destructor().

The Class is responsible for manage the allocated resource for its objects during its lifetime, and must make sure that:
	- the resource is correctly acquired before being used [ on the 'Constructor()' ]
	- the resource is correctly released when it's no longer needed [ on the '~Destructor()' ]
	- any copying of the resource is handled correctly [ on the 'CopyConstructor()' and on the 'AssignmentOperator()' ]
	- any transfer of the resource to another object [ should be of the same class ] is handled correctly [ on MoveSemantics() by Modern C++ ]

E.g.  A Custom String Class can have 2 data members:
	- char *DataContent   // A  'pointer-to-char' variable to store the characters into an 'array of characters'
	- int  *DataSize      // An 'int' variable to represent the number of elements in the 'array of characters'
*In the Custom String Class, the 'resource' is the memory allocated for the class's object

	   >> Shallow Copying

'Shallow Copying' is blindly copying data member values [ basically 'copy values' ] from one object to another using the synthesized 'copy constructor' and the 'assignment operator' functions
Since 'Shallow Copying' just copy values to data members [ from one object to another, both from the same class ], it can cause errors when it comes to pointers [ the address of the second
pointer variable will be copied to the first pointer, and the memory allocated that the first pointer was pointing-to will be lost ], and does not provide RAII idiom for specific use-cases
[ in this case, 'Shallow Copying' should be replaced by 'Deep Copying', providing the RAII idiom for the class's special member functions ]

	   >> Deep Copying

When a pointer [ that contains the address of a memory block on the heap ] gets assigned to point to another address, the previous address will be lost [ and the memory
allocated on the heap will be lost and won't be able to be released/deleted, causing memory leaks ].  To solve this problem, the C++ software needs to perform a 'Deep Copy',
creating a new resource [ in this case, creating a new dynamically-allocated variable on the heap-memory ] instead of just copying the address from one pointer to another [ shallow copy ]
Creating a 'Deep Copy' using the 'CopyConstructor()' avoids blindly copying variable values, which could cause software errors [ like resource leaks or 2 objects handling the same resource ]

	   >> Deep Assignment

While 'Deep Copying' is applied to a 'CopyConstructor()', the 'Deep Assignment' is applied to the 'AssignmentOperator()' [ releasing the previous resource before acquiring a new one ], 
and should have 'self-assignment' prevention [ to avoid an object modifying itself using the 'AssignmentOperator()' ]

	   >> Copy Elision

'Copy Elision' is a form of 'optimization' done by the compiler, where the compiler is allowed to skip over a call to the copy constructor in cases where a variable is initialized
using another variable, but the another variable is unused by the C++ software [ copying temporary variables during function calls ], and 'Copy Elision' is always applied on modern compilers
[ most compilers supply an option to disable it using  '-fno-elide-constructors' ], and for Visual C++ it requires disabling all optimizations
'Copy Elision' is applied even if the 'CopyConstructor()' [ to be elided ] was explicitly written with custom functionality, and could change the behavior of the C++ software

	   >> Making a class uncopyable

To prevent objects from being copied, the 'CopyConstructor()' and the 'AssignmentOperator()' should be on the class's 'private' section for Classical C++,
or using the keyword '=delete' at the end of the function on Modern C++


   >>> Operators and Overloading

C++ defines operators for built-in types [ e.g  for the 'int' type, the '+' operator will add, the '++' operator will increment by 1, the '==' operator will compare, and so on... ]
For every operator, a 'operator function' is defined on the type [ e.g.  the function 'explicit bool operator==(int)' is defined on the 'int' type to compare two 'int' variables, and
the function 'explicit int operator+(int,int)' is defined on the 'int' type to add two 'int' variables ]

When a custom C++ class is created by the C++ developer, the C++ compiler does not provide operators for it [ '+','-','==', etc. ]; however, these operators can be defined on the Class's
body the same way as the 'AssignmentOperator()' [ this is a programming technique called 'operator overloading', creating custom functionality for custom-created classes, allowing its
objects to behave the same as the built-in types when using standard operators like adding or subtracting, using the same syntax with same semantics for the same built-in symbols ]

	   >> Unary (one argument) Binary (two arguments) and Ternary (three arguments)

An operator that takes a single argument is called 'unary' [ e.g.  c = -b ], inverts the signal of the value
An operator that takes two arguments is called 'binary' [ e.g.  c = a - b ], subtracts one value from another
An operator that takes three arguments is called 'ternary' [ e.g.  the expression  'a ? b : c'  is the same as  'if (a) then (b) else (c)' ]

	   >> Which operators to overload?

Only provide needed operators for custom classes, and the return value should correspond to the built-in C++ equivalent operator

In general programming, the most useful operators are:
- '='   assignment
- '=='  equality
- '!='  inequality
- '<'   less than
- '()'  function call

There are other operators useful for math-related classes:
- '+'   addition
- '-'   subtraction
- '*'   multiplication
- '/'   division

There are some operators which should not be overloaded:
- '&&'  logical AND
- '||'  logical OR
- '&'   address-of
- ','   comma [ writing several expressions into a single statement ]
- '::'  scope-resolution [ access namespaces or class's members ]
- '.'   dot [ access struct members or class's members ]
- '.*'  dot-star [ member-function pointers ]
- '?:'  ternary operator [ if-then-else ]

	   >> Member operators

Operators which change the state of the object are best impelmented as member-functions [ compound assignments  += -= *= /=  , increments  ++  and decrements  --  ]
Operators which are closely related to data-member types are best implemented as member-functions [ dereference operator *, which returns an object of the same type of the data-member ]
* For compound assignments, the '+=' operator should behave the same as the '+' operator, so the '+' operator should delegate to the '+=' operator C++ code [ DRY coding technique ]

Most operators can be implemented as either member-functions or non-member-functions [ by using delegates and the 'friend' keyword ], but they should be implemented as member functions
[ keeping Class's encapsulation and providing access to private data members ], however some operators cannot be implemented as member-functions [ in this case, they must be non-members ]

E.g.  binary [ function with 2 arguments ] member operators don't work if a type conversion is needed [ like implicitly converting String literals into String objects ]
      In this case, the member-function-operators will only work with object of the same class, but won't work with implicit type-conversion [ will cause a compiler error ],
	  and a binary non-member-function [ function with 2 arguments ] must be defined [ using the 'friend' keyword ], and the compiler will implicitly convert the type with no errors
	  [ the difference is, on a member-function, the first argument is implicit, and should be a class's object; but on a non-member-function, the first argument is explicitly typed,
	  allowing the compiler to make an implicit conversion from the type passed as an argument to a class's object ]
	  For instance, all binary operators should be non-member functions, while member-functions should be unary operators

Some operators must be defined as member functions [ and they could take only one argument ] :
	- assignment     =
	- subscript      []   [ this operator is used on arrays and vectors, which takes an integer as an argument and returns the element at the integer's index ]
	- function call  ()
	- arrow          ->

Binary [ function with 2 arguments ] operators which might require type-conversion should be friend-non-member-functions
	- arithmetic operators
	- equality and relational operators
	- bitwise operators
* Input / Output bitwise operators 'left-shift  <<' and 'right-shift  >>' should be non-member-functions for syntax compatibility

		  > Less-than [ and More-than ] operator

'More-than' and 'Less-than' operators are important non-member-functions for sorting and ordering class's objects [ used by the C++ Standard Library ]
If the C++ developer tries to sort container variables [ like strings, arrays or vectors ] and its elements don't have the 'More-than' and 'Less-than' operators implemented,
the C++ code won't compile [ and this scenario it's also valid when the C++ developer tries to insert elements into a sorted container ], so the ob
When a class implements '<' and '>' operators, the operators '<=', '>=', '==' and '!=' should be implemented as well [ and class's objects should behave consistently among all operators ]

		  > Prefix and Postfix operators

Prefix  increment   ++i   -   equivalent to i+=1; i;  [ increment, then return ]
Postfix increment   i++   -   equivalent to temp=i; i+=1; temp;  [ create a copy, increment, then return the copy ]

Prefix  decrement   --i   -   equivalent to i-=1; i;  [ decrement, then return ]
Postfix decrement   i--   -   equivalent to temp=i; i-=1; temp;  [ create a copy, decrement, then return the copy ]

* Incrementing / Decrementing a pointer-to-array variable will move the pointer to the address of the next / previous element in the array,
  and the '++' / '--' operators combined with a pointer are useful to iterate over arrays and other container types [ like vectors ]

     >>> Sorting a Vector

C++ Standard Library defines a 'std::sort()' function in <algorithm>, sorting elements in an iterator range by taking 2 arguments: iterator.begin and iterator.end
To sort all the elements of a vector, just pass the return values from 'begin()' and 'end()' [ e.g.  sort((begin(sNames)),(end(sNames))); ]
This will sort the elements in ascending order [ and the 'less-than <' operator will be used on each element of the vector to determine the elements order; and if the 
vector elements are std::strings, the elements will be sorted in alphabetical order ]


   >>> Procedural and Functional Programming

In C++, a 'procedural' programming involves a sequence of commands, while a 'functional' programming involves a tree of function calls which transforms data
[ e.g. procedurally processing a vector:  a loop that processes one element at a time on each iteration of the loop ]
[ e.g. functionally processing a vector:  a function that takes one element as an input, processes the element and returns data, to become input for another function ]

In C++, Callable Objects are used to implement functional programming

	   >> Callable Objects

C++ allows the developer to create 'callable objects' by defining a 'function-call' operator:
	- define a non-member-function with custom input-signature
	- create a pointer-to-function variable, and assign the non-member-function to it
	- the 'pointer-to-function' is a data-member, that can be invoked like a function

A C++ class which implements a function-call operator is called 'functor'; an object of the class is a data variable, and the object can be called like a function



// ====================================================================================================
*/
