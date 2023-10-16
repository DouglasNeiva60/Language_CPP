
// Douglas Neiva - Learning Notes - Programming Language - Modern C++
// ====================================================================================================
// >>>  Source file (.cpp) - C++ Code  ================================================================


#include "Modern_CPP.h"          // 1 - Header files

#include <iostream>              // 2 - Libraries
#include <string>

using namespace std;             // 3 - Global Namespaces [the main global namespace has no name]
using namespace std::literals;



// Function declarations [compiler-aware]
// ====================================================================================================

void M_Initialization();
void M_Pointers();
void M_IntSizes();
void M_StringLiterals();
void M_Casting();
void M_ArrayIterator();
void M_AutoKeyword();
void M_RangedForLoop();
void M_NewIfStatement();
void M_Templates();
void M_NameSpaces();
void M_NameSpaces_OutOfScope();



// Standard "main" function - C++
// ====================================================================================================
int main()
// int M_Practice_XX_main()
{
	cout << endl << "Welcome to Modern_CPP.cpp! " << endl << endl;
// ====================================================================================================
// Section 01 - Runs only once, before the loop                                                     1 V

	M_NameSpaces();


// Section 01 - END                                                                                 1 A
// ====================================================================================================
	for (;;)
	{
		cout << endl;
// ====================================================================================================
// Section 02 - Loop                                                                                2 V



// Section 02 - END                                                                                 2 A
// ====================================================================================================
		cout << "Loop executed! " << endl << endl;
		system("pause");
		// break;
	}
// ====================================================================================================
// Section 03 - Runs only once, after the loop                                                      3 V



// Section 03 - END                                                                                 3 A
// ====================================================================================================
	cout << "Loop ended! " << endl << endl;
	system("pause");
	return 0;
}
// ====================================================================================================


void M_Initialization()
{
	// Classical C++
	int Classical_X = 7;

	// Modern C++
	int Modern_X{7};	// C++11 Universal initialization syntax by using curly braces

	string Classical_S = "Classical";
	string Modern_S{ "Modern" };
}

void M_Pointers()
{
	int iInt{ 2 };   // C++11 initialization

	int* p_iInt = &iInt;   // "Pointer to int" initialization by using the "address of"
	int *p_2Int = &iInt;   // Same as above, but the * symbol is the prefix of the variable, and not the sufix of the type

	cout << p_iInt << endl;
	cout << iInt << endl;
	cout << &iInt << endl;
	cout << *p_iInt << endl;
	cout << *p_2Int << endl;
}

void M_IntSizes()
{
	cout << "char: " << ((sizeof(char))*8) << " bits." << endl;

	cout << "int: " << ((sizeof(int)) * 8) << " bits." << endl;
	cout << "long int: " << ((sizeof(long int)) * 8) << " bits." << endl;

	cout << "int8: " << ((sizeof(int8_t)) * 8) << " bits." << endl;
	cout << "int32: " << ((sizeof(int32_t)) * 8) << " bits." << endl;

	cout << "string: " << ((sizeof(string)) * 8) << " bits." << endl;

	cout << "float: " << ((sizeof(float)) * 8) << " bits." << endl;
	cout << "double: " << ((sizeof(double)) * 8) << " bits." << endl;
}

void M_StringLiterals()
{
	string Message_01 = "Welcome "s;   // "s" suffix by "using namespace std::literals"
	string Message_02 = "Douglas"s;
	string Message_03 = " !!!"s;

	cout << (Message_01 + Message_02 + Message_03) << endl;

	// Raw string literal from C++11
	string RawString = R"x(...Your name is Douglas, and your files are on the path: F:\Udemy()\Engineer...)x";   // R"x( <Raw_String_Here> )x"  way of creating raw strings

	cout << RawString << endl;
}

void M_Casting()
{
	// Casting is used often on Object-Oriented programming, but rarely on other cases

	cout << endl << "C-style casting below... " << endl;

	int CastedInt = 'A';               // Creates an 'int' variable with the value 'A'
	cout << CastedInt << endl;         // Prints the 'int' value
	cout << (char)CastedInt << endl;   // C-style casting, Casts the 'CastedInt' variable to a char type

	// Unreal Engine uses the C++98-style casting, that uses a Template Function [that requires a parameter on the Angle-Brackets]
	cout << endl << "C++98-style casting below... " << endl;

	cout << static_cast<float>(CastedInt) << endl;   // C++98-style static_cast, compile-time, convert an expression to a different type

	// cout << reinterpret_cast<char*>(CastedInt) << endl;   // C++98-style reinterpret_cast, compile-time, convert data into a buffer to untyped binary data,
							                                 // used in low-level work, like communication with hardware and binary files

	// C++98-style dynamic_cast, run-time, converts a pointer of a base-class object into a pointer of child-class object
}

void M_ArrayIterator()
{
	const char StringArray[] = { 'H', 'E', 'L', 'L', 'O' };   // Creates a new array, a new block of contiguous memory

	const char* ptr_StartArray = StringArray;   // Creates a pointer that points to the first element of the array
	const char* ptr_EndArray = (StringArray + 5);   // Creates a pointer that points to the first address after the end of the contiguous memory block [last + 1]

	int Iterator = 0;   // Int variable that represents the index of the contiguous memory block

	while (ptr_StartArray != ptr_EndArray)   // Iterates over all elements of the contiguous memory block
	{
		cout << *ptr_StartArray << ", ";   // Dereferences the pointer and prints its content
		ptr_StartArray++;   // Moves to the next memory address
		Iterator++;
	}

	cout << endl << Iterator << endl;

	// The std::string library has two member functions to behave similar to the logic above, with the "begin()" statement [that returns an iterator to the first element of the string]
	// and the "end()" statement [that returns an interator corresponding to the element after the last element of the string, and it's an invalid iterator, shouldn't be dereferenced]
	// Reverse iteration also can be done by using the member functions "rbegin()" [that returns the last element] and the "rend()" [that returns the address before the first element],
	// and const estatement can be added ["crbegin()" and "crend()"]. The variable can aslo be passed as an argument on template container member functions [ crbegin(str_Name) ]
	// "end() - begin()" [or "distance(begin(), end())"] gives the number of container elements, "next()" returns the following iterator, and "prev()" returns the previous iterator

	string str{ "DouglasNeiva" };   // Creates a new String object from the std::string library

	string::reverse_iterator str_Iterator = str.rbegin();   // Calls the "begin()" member function, that returns the address of the first element

	cout << "The number of elements on the string are: " << ((end(str)) - (begin(str))) << endl;

	while (str_Iterator != (str.rend()))   // If the string container object is empty, begin() and end() will return the same value, and the loop won't be executed
	{   // the "for loop" is more performant!
		cout << (*str_Iterator) << " ,";
		str_Iterator++;
	}

	// Iterators can be used on any standard containers, like strings, arrays, vectors, matrices and other library containers
}

void M_AutoKeyword()
{
	auto i{ 42 };   // Will be interpreted as an int literal
	auto String_01 = "Hello";   // Will be interpreted as an array of const char[] literal
	auto String_02 = "Welcome"s;   // Will be interpreted as an std::string object container, due to the "s" suffix

	auto first_element = String_02.begin();
	cout << endl << *first_element << endl;
}

void M_RangedForLoop()
{
	cout << endl;

	for (;;)
	{
		cout << "Infinite looping..." << endl;
		break;
	}

	cout << endl;

	for (int iIterator1 = 0; iIterator1 < 3; iIterator1++)
	{
		cout << "Fixed looping, loop " << iIterator1 << endl;
	}

	cout << endl;

	// Iteration over containers, classical form and modern form [range-based]
	// Range-based for-loops should be used only when the loop needs to go through all container elements

	string str_MyName{ "Douglas" };

	for (int iIterator2 = 0; iIterator2 < 7; iIterator2++)   // Classical for-loop form [half-open-range, from 0 up to 6, but not 7],
	{                                                        // with an initial variable; a test-condition, and iteration operation
		cout << str_MyName[iIterator2] << " ";
	}

	cout << endl;

	for (char cCharacter : str_MyName)   // Modern range-based for-loop, with an initial variable to be used as cache [each element of the container will be copied to this variable,
	{                                    // that should be the same type of each element of the container / array], a single-colon symbol [range], and the container / array variable
		cout << cCharacter << " ";
	}

	cout << endl;

	{
		for (char& cCharacter : str_MyName)   // To modify each element with a range-based loop, instead of creating a "char" variable, create a "char reference" variable,
		{                                     // so, on each iteration, each element of the container variable will be referenced by [and not copied to] the cache variable
			cout << cCharacter << " ";
			cCharacter = 'X';
		}

		cout << "Full name modified: " << str_MyName << endl;
	}
}

void M_NewIfStatement()
{
	// C++98 old way of writing if-statement, the variable remains outside of the loop scope

	bool bAllowed = false;

	if (bAllowed)
	{
		cout << "The bool variable is true!" << endl;
	}
	else
	{
		cout << "The bool variable is false!" << endl;
	}

	// C++17 new way of writing if-statement, the variable exists only within the loop scope
	// ERROR: language feature 'init-statements in if/switch' requires compiler flag '/std:c++17'
	/*
	if (bool bPermitted = false; bPermitted)
	{
		cout << "The bool variable is true!" << endl;
	}
	else
	{
		cout << "The bool variable is false!" << endl;
	}
	*/

	char cSingleChar{ 'A' };

	switch(cSingleChar)
	{
		cout << endl;

		case 'A':
			cout << 'A' << endl;
			// [[fallthrough]];   // C++17 code, not highlighted due to lack of the std:C++17 flag
		case 'B':
			cout << 'B' << endl;
		case 'C':
			cout << 'C' << endl;
		case 'D':
			cout << 'D' << endl;
		case 'E':
			cout << 'E' << endl;
		default:
			break;
	}
}

template <class Template_01>   // Declaring a new template "Template_01" by using the "template" keyword
							   // [it will be used for a Template Function, won't work for a Template Class]

// Defining a new Template Function [find the maximum value of two values]
Template_01 Tf_Max(const Template_01& t1, const Template_01& t2)
{
	cout << "The maximum value is: ";

	if (t1 > t2)
	{
		return t1;
	}
	return t2;

	// On template functions, the template type [TemplateFunction_01] will be replaced by the template parameter-type when the function gets called
	// Unlike normal function [declared on the header file and defined on the source file], template functions must be declared and defined on header files
}

template <class Template_02>   // Declaring a new template "Template_02" by using the "template" keyword
							   // [it will be used for a Template Class, won't work for a Template Function]

// Defining a new Template Class
class Tc_Class
{
public:
	Template_02 MemberVariable_01;   // Variable type to be replaced by the template-parameter type

	Tc_Class(const Template_02& MemberVariable_01) : MemberVariable_01(MemberVariable_01) {}   // Constructor function that initializes the member variable

};

template <typename Template_03>   // Declaring a new template "Template_03" by using the "template" and the "typename" keywords, introduced by C++98,
								  // since the "class" keyword was confusing [both classes and templates can be instantiated for built-in types]

// Defining a new Template Function [prints something to the screen]
Template_03 Tf_Print(const Template_03& p1)
{
	cout << "C++98 typename also works! The value to be printed is: " << p1;

	return p1;
}

void M_Templates()
{
	float X1 = 7.23f;
	float X2 = 9.41f;

	char Y1 = 'F';
	char Y2 = 'Z';

	cout << Tf_Max<int>(Y1, Y2) << endl;   // Template function called, passing the "int" type as an argument [and int will be returned]
										   // Even if the input variables are "char" type, the template function will return an "int" type

	Tf_Print<string>("Dulga");

	Tc_Class<int> Object_01{ 12 };
	Tc_Class<float> Object_02{ 7.14f };
	Tc_Class<string> Object_03{"Hello"s};   // Each object will instantiate a unique object, generated by a unique class with an unique name for every data-type
											// On C++17, the compiler now can deduce the variable type, without needing the template-parameter [Constructor Template Argument Deduction - CTAD]
}

double NewDouble = 3.141592f;

namespace CustomNameSpace   // Creating a new namespace
{
	class NewClass;
	int NewInt;
	string NewString;

	double NewDouble = 1.618034f;

	void NewFunction();
}

class CustomNameSpace::NewClass   // Definition of a class that belongs to a 'CustomNameSpace'
{
public:
	
	NewClass();   // Declaration of the class's constructor function

	float NewFloat;
};

CustomNameSpace::NewClass::NewClass()   // Definition of the class's constructor function, that belongs to a 'CustomNameSpace'
{
	cout << "A new Object was created!" << endl;
	NewFloat = 0.1f;
}

void CustomNameSpace::NewFunction()   // Definition of a member function [symbol] that belongs to a 'CustomNameSpace'
{
	cout << "Custom function from the CustomNameSpace!" << endl;

	cout << NewDouble << endl;     // Prints the 'CustomNameSpace' local variable
	cout << ::NewDouble << endl;   // Prints the global variable with the same name, declared outside of the 'CustomNameSpace' scope
}

namespace CustomNameSpace   // Continuing creating a new namespace [the creation can be splitted into several pieces of code]
{                           // This approach is useful to only declare member functions of classes within namespaces on header files,
							// and then define class's member functions within a namespace on source files
	char NewChar;
}

void M_NameSpaces()
{
	using namespace CustomNameSpace;   // This expression ensures that the namespace 

	NewClass TestObject;

	NewFunction();

	NewString = "Welcome to CustomNameSpace!";
	cout << NewString << endl;

	NewChar = 'X';   // The declaration of this variable from the namespace should be above this line of code!

	M_NameSpaces_OutOfScope();
}

void M_NameSpaces_OutOfScope()
{
	cout << endl << "Out of the scope from the 'M_NameSpaces()' function! The 'CustomNameSpace' doesn't work anymore..." << endl;

	// NewClass TestObject_02;   // This expression doesn't recognize the class of the "CustomNameSpace", since it's out of scope [previous function]

	// NewFunction();   // ERROR: identifier not found [the namespace was declared locally on the 'M_NameSpaces()' function
}
