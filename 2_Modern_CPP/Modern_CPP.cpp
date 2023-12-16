
// Douglas Neiva - Learning Notes - Programming Language - Modern C++
// ====================================================================================================
// >>>  Source file (.cpp) - C++ Code  ================================================================


#include "Modern_CPP.h"          // 1 - Header files

#include <iostream>              // 2 - Libraries
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cstdint>
#include <algorithm>


using namespace std;             // 3 - Global Namespaces [the main global namespace has no name]
using namespace std::literals;



// Function declarations [compiler-aware]
// ====================================================================================================

// Introduction
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
void M_NameSpaces_OutOfScope_01();
void M_NameSpaces_OutOfScope_02();
void M_FunctionPointers();

// String Interface
void M_BasicStringOperations();
void M_SearchingStrings();
void M_AddingStringElements();
void M_RemovingStringElements();
void M_StringNumberConversion();
void M_MiscStringOperations();
void M_CharacterFunctions();
void M_CompareStrings();
void M_SimpleAddMultiply();

// Files and Streams
void M_FileStreamRead();
void M_FileStreamOverWrite();
void M_StreamBuffering();
void M_UnbufferedStream01();
void M_UnbufferedStream02();
void M_FileModes01();
void M_FileModes02();
void M_StreamMembersStates();
void M_StreamManipulators();
void M_StringStreams();   // Calling a custom template function, that requires definition above this callee function
void M_StreamRandomAccess();
void M_StreamIterator();
void M_BinaryFiles();
void M_BinaryFileBitmap();   // Uses several structs [ compound types ], written right above the function

// Special member functions
void M_MemberFunctions();
void M_CopyConstructor();
void M_RAIIstring();
void M_ConversionOperator();
void M_DefaultDelete();
void M_OperatorsOverloads();
void M_MemberOperators();
void M_VectorSort();
void M_PointerIterator();
void M_FunctionCallOp();

// Algorithms and Lambda Expressions
void M_StringAlgorithms();
void M_PredicateFunction();
void M_CompareStringsLambda();
void M_LambdaCaptures();
void M_PartialEvaluation();
void M_DanglingReference();
void M_GenericLambdas();
void M_PairType();
void M_InsertIterators();
void M_STLFunctionObjects();

// Algorithms continued
void M_SearchingAlgorithms();





// Standard "main" function - C++
// ====================================================================================================
int main()
// int M_Practice_XX_main()
{
	cout << endl << "Welcome to Modern_CPP.cpp!  Created by Douglas Neiva " << endl << endl;
// ====================================================================================================
// Section 01 - Runs only once, before the loop                                                     1 V

	M_SearchingAlgorithms();



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

double NewDouble = 3.141592f;   // Since this variable is being declared outside of any namespace scope, it belongs to the "global namespace" [no name],
								// and can be called by using the scope-resolution operator "::" with no name on prefix [e.g. ::NewDouble

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

	cout << NewDouble << endl;     // Prints the 'CustomNameSpace' local variable, due to namespace hierarchy
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

	M_NameSpaces_OutOfScope_01();
	M_NameSpaces_OutOfScope_02();

}

void M_NameSpaces_OutOfScope_01()
{
	cout << endl << "Out of the scope from the 'M_NameSpaces()' function! The 'CustomNameSpace' doesn't work anymore..." << endl;

	cout << "But it's possible to use the scope-resolution operator from 'CustomNameSpace' symbols! Example: " << CustomNameSpace::NewDouble << endl;

	// NewClass TestObject_02;   // This expression doesn't recognize the class of the "CustomNameSpace", since it's out of scope [previous function]

	// NewFunction();   // ERROR: identifier not found [the namespace was declared locally on the 'M_NameSpaces()' function
}

void M_NameSpaces_OutOfScope_02()
{
	cout << "Before the 'using' keyword: " << NewDouble << endl;   // It refers to the 'NewDouble' varibale declared outside of any namespace scope [global namespace]

	using CustomNameSpace::NewDouble;   // Makes the variable within its namespace available as if it are declared on the global namespace

	cout << "After the 'using' keyword: " << NewDouble << endl;   // Now it refers to the 'NewDouble' varibale declared within the 'CustomNameSpace' scope, due to the 'using' keyword

}

void M_FunctionPointers()
{
	void AddressableFunction(int Input);   // Declaring a function within other function's scope
	auto ptr_FunctionAddress = &AddressableFunction;   // Creating a new pointer [with the 'auto' keyword] and assigning the address of the previously created function

	(*ptr_FunctionAddress)(54);   // Calling the addressed function bu dereferencing the pointer and passing the input arguments

}

void AddressableFunction(int Input)   // A function that gets called by a pointer
{
	cout << "The input is: " << Input << endl;
}

void M_BasicStringOperations()
{
	
	string s1 = "Douglas"s;
	string s2{ "Neiva"s };

	string s3 = "Result"s;

	// String operations: assignment, appending, concatenation and comparison

	s3 = s1 + (" ") + s2;
	cout << s3 << endl;

	if (s1 == s2)
	{
		cout << "The strings are equal." << endl;
	}
	else
	{
		cout << "The strings are different." << endl;
	}

	if (s1 > s2)
	{
		cout << "S1 is greater than S2." << endl;
	}
	else
	{
		cout << "S2 is greater than S1." << endl;
	}

	const char* ptr_Cstring = s3.c_str();   // The "c_str()"member function of the std::string returns a C-style string

	cout << ptr_Cstring << endl;

	string s4 = s3.substr(8,5);
	s4[1] = 'o';

	cout << "The Last Name is: " << s4 << endl;

	string s5(s4, 1, 3);

	cout << s5 << endl;
	
}

void M_SearchingStrings()
{
	string FullName{ "Douglas do Carmo Neiva"s };

	size_t strPos1 = FullName.find('N');

	size_t strPos2 = FullName.find("Car");

	size_t strPos3 = FullName.find("dor");   // Should be checked from being std::npos [like a pointer from being nullptr]

	cout << "The sizes are: " << strPos1 << ", " << strPos2 << ", " << strPos3 << endl;

	if (strPos3 != string::npos)
	{
		cout << "The index was found." << endl;
	}
	else
	{
		cout << "The third index is impossible to find." << endl;
	}

	size_t strPos4 = FullName.rfind('o');

	cout << strPos4 << endl;
}

void M_AddingStringElements() 
{
	string Hello{ "Hello"s };

	Hello.append(" World"s);

	cout << Hello << endl;

	Hello.append("wow!!!", 3, 2);   // Creating a substring on the 'append()' argument list

	cout << Hello << endl;

	string Wonderful{ " Wonderful"s };

	Hello.insert(5, Wonderful);

	cout << Hello << endl;

}

void M_RemovingStringElements()
{
	string MyFullName{ "Douglas do Carmo Neiva"s };

	MyFullName.erase(7, 9);

	cout << MyFullName << endl;

	auto LastNamePosition = MyFullName.find("Neiva"s);

	if (LastNamePosition != string::npos)
	{
		cout << "The Last_Name_Position is: " << LastNamePosition << endl;

		MyFullName.erase(LastNamePosition);

		cout << "The first name is: " << MyFullName << endl;
	}
	else
	{
		cout << "The Last_Name_Position'wasn't found." << endl;
	}
	
	MyFullName.replace((begin(MyFullName)), (begin(MyFullName)+3), "Garbage "s);

	cout << MyFullName << endl;

	MyFullName.assign("Douglas do Carmo Neiva"s);

	cout << MyFullName << endl;
}

void M_StringNumberConversion()
{
	string Num_Pi = (to_string(3.141592));

	cout << Num_Pi << endl;

	Num_Pi += 88;

	cout << Num_Pi << endl;

	// The 'stoi()' function has a second argument [out parameter] that returns the same string's size if there is no error

	string ToInt = "2.4836470"s;   // Maximum 'int' value

	int Num_GR = 5;   // Int, not float

	size_t NumberOfCharacters;
	
	Num_GR = (stoi(ToInt, &NumberOfCharacters, 10));   // The string should have the number represented as a 'float' value [with at least 1 decimal value] on a base 10 [third argument]

	// If the conversion is partially successful, the second argument gives the index of the first non-numberic character

	if (NumberOfCharacters == (ToInt.size()))
	{
		cout << "'String to Int' has given errors." << endl;   // If the string [to be converted to an int] is non-numerical, it will 'throw an exception' and the software will crash

		cout << "The error is on the index: " << NumberOfCharacters << endl;
	}
	else
	{
		cout << "'String to Int' works, no errors." << endl;

		cout << Num_GR << endl;
	}

	int HexToInt = (stoi("0xAF", &NumberOfCharacters, 16));   // 'stoi()' function can convert an Hex value [formatted as a string] to a decimal number ['int' type]

	cout << HexToInt << endl;

	cout << ToInt << " with 'stod()' returns " << (stod(ToInt)) << endl;   // Only 5 decimal numbers

}

void M_MiscStringOperations()
{
	string MyData{ "HashTable"s };

	string OtherData{ "MappedValues"s };

	const char *ptr_ToMyData = (MyData.data());   // The 'data()' member function returns a pointer to the first element of a C-style string [array of const char]

	cout << "Value: " << MyData << ".   Address: " << &ptr_ToMyData 
		<< ".   Size: " << MyData.size() << ".   Value on address: " << *ptr_ToMyData << "." << endl;

	for (int i_iterator = 0; i_iterator < (MyData.size()); i_iterator++)
	{
		cout << ptr_ToMyData[i_iterator];
	}

	cout << endl;

	swap(MyData, OtherData);   // Swaps the values between 2 variables, and this function has overloads for all built-in C++ variable types

	cout << "MyData: " << MyData << ".   OtherData: " << OtherData << endl;

}

void M_CharacterFunctions()
{

	string MyFullInfo = "Douglas do Carmo Neiva, +55 (31) 9 9567-8623";

	cout << "Decomposing the string..." << endl << endl;

	// Ranged for-loop
	for (char Character : MyFullInfo)
	{

		switch (Character)
		{
		case 'A':
			cout << "A" << endl;
			break;
		case 'E':
			cout << "E" << endl;
			break;
		case 'I':
			cout << "I" << endl;
			break;
		case 'O':
			cout << "O" << endl;
			break;
		case 'U':
			cout << "U" << endl;
			break;
		default:
			cout << " ";
		}

		if (isdigit(Character))
		{
			cout << "Digit; ";
		}
		if (islower(Character))
		{
			cout << "Lower-case; ";
		}
		if (isupper(Character))
		{
			cout << "Upper-case; ";
		}
		if (isspace(Character))
		{
			cout << "Space; ";
		}
		if (ispunct(Character))
		{
			cout << "Punctuation; ";
		}

	}

	cout << endl << "String decomposed!" << endl;

}

void M_CompareStrings()
{
	// Case-insensitive string comparison

	string sCompare01{ "Douglas"s };
	string sCompare02{ "dOuGlAs"s };
	// string sCompare02{ "Douglas"s };

	bool EqualityCheck = false;

	if ((sCompare01.size()) != (sCompare02.size()))
	{
		cout << "The 2 strings are different (different sizes)." << endl;

	}
	else
	{
		cout << "The 2 strings have equal sizes, comparing..." << endl;

		for (int i = 0; i < (sCompare01.size()); i++)
		{
			char cComp01 = (toupper(sCompare01[i]));
			char cComp02 = (toupper(sCompare02[i]));

			cout << "Char01[" << i << "]: " << cComp01 << ".  " << "Char02[" << i << "]: " << cComp02 << ".  " << endl;

			if (cComp01 == cComp02)
			{
				EqualityCheck = true;
			}
			else
			{
				EqualityCheck = false;
			}
			if (!EqualityCheck)
			{
				break;
			}
		}
	}

	if (EqualityCheck)
	{
		cout << endl << "The strings are fully equal!  [ case-insensitive ]" << endl;
	}
	else
	{
		cout << endl << "The strings are different!  [ difference on the line above ]" << endl;
	}

	cout << "String 01: " << sCompare01 << ".  String 02: " << sCompare02 << ". " << endl;

	cout << endl << "Using the standard 'is_equal ==' operator: " << endl;

	cout << "String01 is" << (sCompare01 == sCompare02 ? "" : " not") << " equal to String02." << endl;   // Simple 'if' statement, with the '?' operator [to represent the 'if' scope] 
																								          // and the ':' operator to separate the 'true' and the 'false' conditions
}

void M_SimpleAddMultiply()
{
	cout << "Adding and multiplying 2 'floating-point' numbers..." << endl << endl;

	double fFirstNumber{ 0.0f };
	double fSecondtNumber{ 0.0f };

	cout << "Input of Number 1:  ";

	cin >> fFirstNumber;

	cout << endl << "Input of Number 2:  ";

	cin >> fSecondtNumber;

	cout << endl << endl;

	cout << fFirstNumber << " + " << fSecondtNumber << " = " << (fFirstNumber + fSecondtNumber) << endl;
	cout << fFirstNumber << " * " << fSecondtNumber << " = " << (fFirstNumber * fSecondtNumber) << endl;
}

void M_FileStreamRead()
{
	string sFileName{ "F:\\Udemy\\Developer\\02_C++\\LOG.txt"s };   // Name of the file to be initialized as an 'ifstream' object

	ifstream fInputFile{ sFileName };   // Opens the file for reading
										// 'FileStream' C++ code only accepts 'Modern C++' initializing with {}   [ the 'assignment' operator will cause errors ]

	string sFileBuffer{ ""s };   // Creating a new 'string' variable, to be used as a memory buffer

	cout << "The '" << sFileName << "' file was declared as an 'ifstream' object!   [ read operations ]" << endl;

	// fInputFile.close();   // The C++ program needs to call the 'close()' member function twice in order to fail the 'is available' condition
	// fInputFile.close();   // If the 'close()' member function is called once, the file will no longer be readable, but it will still be available, passing the 'is available' condition

	if (fInputFile)   // Checks if the file is ready to use, returns false if cannto be used
	{
		cout << "The '" << sFileName << "' file is available to use by the C++ program!   Reading... " << endl << endl;

		while (fInputFile >> sFileBuffer)   // Reads the file word-by-word, returning each word [ sepparated by whitespaces ] as an individual value 
											// Using the 'right-shift' operator '>>' to write data from the file to the string  [ receiving an input and writing it as an output ]
		{
			cout << sFileBuffer << " ";   // Inserts the whitespace at the end of all values  [ since 'fstream' objects reads only one value at once, sepparated by whitespaces ] 
										  // Using the 'left-shift' operator '<<' to read data from the string to the terminal  [ receiving an output and reading it as an input ]

		}

		cout << endl << endl << "The content of the file was read successfully!  [ as shown above ]" << endl;

		fInputFile.close();   // Closes the previously-opened file, releasing the binding between the 'fInputFile' 'ifstream' object from the 'sFileName' file
		fInputFile.close();

		if (fInputFile)
		{
			cout << "The '" << sFileName << "' file is still available to use by the C++ program." << endl;
		}
		else
		{
			cout << "The '" << sFileName << "' file is no longer available to use by the C++ program." << endl;
		}
	}
	else
	{
		cout << "The '" << sFileName << "' file is not available to use by the C++ program!" << endl;
	}

	cout << endl << "Reading again...   [ line-by-line, using the 'getline()' member function ]" << endl;

	fInputFile.open(sFileName);   // Opening the same file again on the same 'ifstream' object

	if (fInputFile)
	{
		while (getline(fInputFile, sFileBuffer))   // The 'getline()' member function of the 'fstream' library reads a complete line of the file [ first argument ] and 
		{										   // assigns its content to the string-buffer [ second argument ], returning false at the end of the file

			cout << sFileBuffer << endl;   // By using the 'getline()' member function [best-practice], all the whitespaces and puntuation will remain on the string 
										   // and onlye 'newline' characters will be used as value separators, returning true when it founds a new line with data
		}

		fInputFile.close();
		fInputFile.close();
	}

}

void M_FileStreamOverWrite()
{
	string sFileName{ "F:\\Udemy\\Developer\\02_C++\\LOG.txt"s };

	ofstream fOutputFile{ sFileName };   // Opens the file and create a 'communication channel' to write data into the filename

	cout << "The '" << sFileName << "' file was declared as an 'ofstream' object!   [ write operations ]" << endl;

	if (fOutputFile)   // Checking the stream state
	{
		fOutputFile << endl << "Overwriting existing data" << endl << "New data... " << endl << endl;

		const vector<string> vWords = { "First", "Second" };   // A vector with strings [ 3 elements ] costs 256 bits [ 32 bytes ] on the memory per element

		const string aWords[2] = { "Third", "Fourth" };   // An array of strings [ 3 elements ] costs 320 bits [ 40 bytes ] on the memory per element

		cout << "Vector with 2 string elements... Its size is: " << ((sizeof(vWords)) * 1) << " bits allocated on the memory." << endl;
		cout << "Array  with 2 string elements... Its size is: " << ((sizeof(aWords)) * 1) << " bits allocated on the memory." << endl;

		cout << endl;

		for (string Word : vWords)
		{
			fOutputFile << Word << ", ";   // The 'ofstream' object can be used as the same way as 'cout' to send data to the file [ as was done for sending to the terminal ]
		}
		fOutputFile << endl;

		for (string Word : aWords)
		{
			fOutputFile << Word << ", ";
		}
		fOutputFile << endl;
				
		fOutputFile.close();
		fOutputFile.close();
	}

}

void M_StreamBuffering()
{
	// Do the large for-loop shown on the lecture 35 !

	int iMyInt{ 32 };

	string sFileName{ "F:\\Udemy\\Developer\\02_C++\\LOG.txt"s };

	ofstream fOutputFile{ sFileName };   // Opens the file and create a 'communication channel' to write data into the filename

	cout << "The '" << sFileName << "' file was declared as an 'ofstream' object!   [ write operations ]" << endl << endl;

	cout << iMyInt << flush;   // 'Flushes' the 'iMyInt' data into the terminal  [ won't add a 'newline character' at the end ]

	cout << iMyInt << endl;   // Similar results, will register the value immediately on a LOG.txt file for large iterators

}

void M_UnbufferedStream01()
{
	cout << "Enter some text..." << endl << endl;

	char cUnbufferedData{ 'X' };

	while (cin.get(cUnbufferedData))   // Using the 'get()' member function of the input stream 
									   // The 'get()' will return TRUE until it reads 'end-of-input' character
									   // Remember that the 'data packet' will be valid when the input stream reads the 'new-line' character  [ line-oriented input ]
									   // So the 'std::cin' only reads the data when the 'new-line' character is sent to the input stream
	{
		cout.put(cUnbufferedData);   // Using the 'put()' member function of the output stream
	}   // The 'Ctrl+Z' (Windows 'end-of-input' character)  will end the 'while-loop' by returning FALSE
}

void M_UnbufferedStream02()
{
	// Creating a new buffer variable to be used with 'read()' and 'write()' member functions

	const int iFileSize{ 10 };   // The size of the memory buffer
	char acFileBuffer[iFileSize];   // Creating a new memory buffer

	string sFileName{ "F:\\Udemy\\Developer\\02_C++\\LOG.txt"s };
	ifstream fInputFile_01{ sFileName };    // Opens the file and create a 'communication channel' to read data from the filename

	// The output stream could be opened on the same time as the input stream!, but, by default, all the data previously stored on the file will be deleted!!!
	// To avoid this issue, open the 'ofstream' with the 'std::app' as the second argument!

	ofstream fOutputFile_01{ sFileName, fstream::app };   // Opens the file and create a 'communication channel' to write data into the filename

	if ((fInputFile_01) && (fOutputFile_01))
	// if (fInputFile_01)
	{
		fInputFile_01.read(acFileBuffer, iFileSize);

		cout << "Reading from:  " << sFileName << endl;
		cout << "Buffer data:   " << acFileBuffer << endl;   // Every time a 'read()' member function is used on a memory buffer,
		cout << "Buffer size:   " << iFileSize << endl;      // the correct buffer data only will be returned by the 'write()' member function

		cout << "File data:     ";
		cout.write(acFileBuffer, iFileSize);
		cout << endl;

		cout << "File size:     ";
		cout << fInputFile_01.gcount() << endl << endl;
	}
	else
	{
		cout << "ERROR!  ";

		if (!fInputFile_01)
		{
			cout << "The given file was not opened as an input file!" << endl;
		}
		if (!fOutputFile_01)
		{
			cout << "The given file was not opened as an output file!" << endl;
		}
	}

	fOutputFile_01.close();
	fOutputFile_01.close();
	fInputFile_01.close();
	fInputFile_01.close();

	cout << "I/O file stream closed!" << endl;

}

void M_FileModes01()
{
	string sFileName{ "F:\\Udemy\\Developer\\02_C++\\LOG.txt"s };

	
	ofstream fOutputStream_Def{ sFileName };

	if (fOutputStream_Def)
	{
		cout << "The file was opened! Using 'by-default' config...   [ 'truncate' file-mode ] " << endl;
	}
	else
	{
		cout << "The file could not be opened!" << endl;
	}

	fOutputStream_Def.close();
	fOutputStream_Def.close();
	

	ofstream fOutputStream_App{ sFileName, fstream::app };

	if (fOutputStream_App)
	{
		cout << "The file was opened! Using the optional second argument...   [ 'append' file-mode ] " << endl;

		fOutputStream_App << endl << "NEW DATA" << endl << endl;

		for (int Counter = 0; Counter < 999; Counter++)
		{
			fOutputStream_App << "Counting...   " << Counter << endl;
		}

	}
	else
	{
		cout << "The file could not be opened!" << endl;
	}

	fOutputStream_App.close();
	fOutputStream_App.close();

}

void M_FileModes02()
{
	string sFilePath{ "F:\\Udemy\\Developer\\02_C++\\LOG.txt"s };

	fstream fFileIO{ sFilePath, fstream::in | fstream::out | fstream::app };   // Using the same 'fstream' object for Input and Output, preserving the previously-stored data

	if (fFileIO)
	{
		cout << "The I/O file was opened successfully!" << endl;
	}
	else
	{
		cout << "The I/O file wasn't opened..." << endl;
	}

	fFileIO.close();
	fFileIO.close();

}

void M_StreamMembersStates()
{
	string sFilePath{ "F:\\Udemy\\Developer\\02_C++\\LOG.txt"s };

	// Binding a file to an 'fstream' object

	ofstream fFile_01;   // The 'fstream' object can be created without being initialized [ this object was not bound to any file yet ]

	ofstream fFile_02{ sFilePath, fstream::out };   // In this case, the 'open()' member function is implicitly being called, receiving the arguments from the initializer

	fFile_01.open(sFilePath);   // In this case, the 'open()' member function is explicitly being called

	if (fFile_01.is_open())
	{
		cout << "The 'fFile_01' is open! " << endl;
	}
	else
	{
		cout << "The 'fFile_01' is closed! " << endl;
	}


	fFile_01.close();
	fFile_01.close();
	fFile_02.close();
	fFile_02.close();

	if (fFile_01.is_open())
	{
		cout << "The 'fFile_01' is open! " << endl;
	}
	else
	{
		cout << "The 'fFile_01' is closed! " << endl;
	}

	int iInput = 0;
	bool bIsValidInput = false;

	while (!bIsValidInput)
	{
		cout << "Please enter a valid number:  " << endl << endl;

		cin >> iInput;
		cout << endl;

		if (cin.good())   // Reads an 'int' value
		{
			cout << "You entered a valid number!" << endl;
			bIsValidInput = true;
		}
		else if (cin.fail())   // Reads an 'non-int' value
		{
			cout << "You entered an invalid number!" << endl;
		}
		else if (cin.bad())   // Software error
		{
			cout << "The software has crashed!" << endl;
		}
		else   // Error handling
		{
			cout << "ERROR" << endl;
		}

		cout << "The input data remains with the value of:  " << iInput << endl;

		cin.clear();             // The input stream member functions 'clear()' and 'ignore()' should always be used together  [ 'clear()' first, 'ignore()' second ]
		cin.ignore(999, '\n');   // Ignores all the remaining data on the input stream, similar to 'flush()' of output streams, stopping on the 'new-line' character
	}

}

void M_StreamManipulators()
{
	bool bTrue = true;
	bool bFalse = false;

	cout << bTrue << endl;   // Prints the 'bTrue' variable value 'as-it-is', printing the '1' value
	cout << boolalpha << bTrue << endl;   // Prints the 'true()' string, and not the '1' value

	cout << endl;
	cout << left << setw(10) << "Penguins" << setw(10) << 9462 << setw(10) << "units" << endl;   // The 'left' 'sticky' manipulator could be used only once 
	cout << setw(10) << "Bears" << setw(10) << 83 << setw(10) << "units" << endl;                // and the whole stream will remain in this manipulator's state,
	cout << setw(10) << "Fishes" << setw(10) << 5 << setw(10) << "units" << endl;                // needing another opposite manipulator to restore the stream's original state

	cout << endl;
	cout << right << setfill('-') << "Full" << "Name:" << endl;   // Using the 'right' [ to revert the 'left' ] and the 'setfill()' sticky output stream's manipulators
	cout << setw(15) << "Douglas" << setw(15) << "do" << setw(15) << "Carmo" << setw(15) << "Neiva" << endl;
	cout << setw(15) << "Unreal" << setw(15) << "Engine" << setw(15) << "Senior" << setw(15) << "Developer" << endl;
	cout << setw(15) << "C++" << setw(15) << "Senior" << setw(15) << "Software" << setw(15) << "Engineer" << endl;

	cout << right << setfill(' ') << endl;   // Reverting back the sticky manipulators to its original states

	float fF{ 1.618034f };   // Fibonacci 'golden ratio'
	float fE{ 2.718281f };   // Natural logarythm
	float fP{ 3.141592f };   // Value of 'pi'

	cout << endl << "Scientific notation for Fibonacci, 'e' and 'pi'..." << endl;
	cout << scientific << (fF*1000) << endl;
	cout << (fE/1000) << endl;
	cout << fP << endl;

	cout << endl << "Fixed notation for Fibonacci, 'e' and 'pi'..." << endl;
	cout << fixed << setprecision(9) << (fF * 1000) << endl;
	cout << (fE / 1000) << endl;
	cout << fP << endl;

	cout << setprecision(6) << defaultfloat << endl;   // Resetting both 'scientific' and 'fixed' floating-point 'sticky' manipulators

}

template <typename InputToString>                    // Template function!
string M_ToString(const InputToString& InputValue)   // Template functions requires both declaration and definition above the callee function,
{                                                    // meaning that all its C++ code must be written on the header file
	ostringstream ssOutputStringStream{ "" };
	ssOutputStringStream << setprecision(7) << InputValue;
	return (ssOutputStringStream.str());
}

void M_StringStreams()
{
	ostringstream ssOutputStream;

	ssOutputStream << "New string on the 'ostringstream' object!";

	cout << ssOutputStream.str() << endl;

	float NewFloat{ 2.718281f };

	cout << "The custom 'M_ToString' function returns the float-to-int value: " << M_ToString<int>(NewFloat) << endl;   // Calling the custom template function by using the wrong template-parameter,
																												 // causing loss of data of the decimal places from the 'floating-point' type
	cout << "The custom 'M_ToString' function returns the float value: " << M_ToString<float>(NewFloat) << endl;   // Calling the custom template function, 
																												   // passing the type 'float' as the template-parameter
	int NewInt{ 762 };

	cout << "The custom 'M_ToString' function returns the int value: " << M_ToString<int>(NewInt) << endl;   // Calling the custom template function,
																											 // passing the type 'int' as the template-parameter

}

void M_StreamRandomAccess()
{
	string sData{ "It is time to say:  "s };   // Specifies the string data

	ostringstream ssOutputStream;   // Opens the output string-stream

	ssOutputStream << sData;   // Writes data to the output string-stream [ as same as the 'cout' output stream for terminal ]

	auto MarkerPosition = ssOutputStream.tellp();   // Saving the current Marker Position of the output stream, to be retrieved later

	cout << sData.size() << " characters [bytes] written into the 'ostringstream' object." << endl;
	cout << "The stream marker is at the byte-position [character] " << MarkerPosition << " on the 'ostringstream' object." << endl;

	ssOutputStream << "Hello!";   // Moves the position marker 6 bytes forward
	cout << "The stream marker is now at the byte-position [character] " << (ssOutputStream.tellp()) << " on the 'ostringstream' object." << endl;

	cout << (ssOutputStream.str()) << endl;

	if (MarkerPosition != -1)
	{
		cout << "Going back into the position to be retrieved, changing the stream..." << endl;

		ssOutputStream.seekp(MarkerPosition);

		ssOutputStream << "Goodbye!";   // Writing on the marker position will overwrite the characters, not append them! The C++ developer should be aware of the size of the data!

		cout << "The output stream now have the value below..." << endl;

		cout << ssOutputStream.str();

	}
	else
	{
		cout << "The 'ostringstream' object is on an invalid state, and its marker returned the value of -1." << endl;
	}

	ssOutputStream.seekp(MarkerPosition);   // Retrieving the previous Marker Position of the output stream

}

void M_StreamIterator()
{
	string sNewData{ "OldValue"s };

	cout << "The 'OldData' is:  " << sNewData << endl;

	ostream_iterator<int> OsI_Index(cout, "_");   // Creates the output stream iterator, sending the 'new-line character' after each iterator assignment, and binding 'cout' to it
												  // Since iterators are template-types [parametric], the variable type should be provided on the template-parameter [ in this case, 'int' ]

	*OsI_Index = 88;   // Will display the 'int' number 88

	cout << endl;

	*OsI_Index = 3.141592;   // Will display the 'int' number 3 [ since the iterator type was declared as an 'int' type ]

	cout << endl;

	*OsI_Index = 'X';   // Will display the decimal ASCII-equivalent-value of the char [ 'X' = ASCII 88 ], since the iterator type was declared as an 'int' type

	cout << endl;

	for (int Counter = 0; Counter < 10; Counter++)
	{
		*OsI_Index = Counter;   // Dereferences the output stream iterator [ does nothing, but will look like a 'pointer' iterator ] and assigns the number [from 0 to 9] to the 'ostream_iterator'
		OsI_Index++;            // Increments the output stream iterator [ does nothing, but makes the syntax clear and explicit, as if it were a common iterator ]
	}

	cout << endl;

	istream_iterator<int> IsI_Index(cin);   // Creating the input stream iterator, of type 'int', and binding the 'cin' input stream to it 
											// When a new input stream iterator is created, the bound input stream will read information [ in this case, will wait for the user's input ]

	string sUserInput{ ""s };
	sUserInput = *IsI_Index;   // Every time an input stream iterator is dereferenced, the data will be read from the input stream bound to it
	
	cout << sUserInput << endl;   // Since the 'sUserInput' is a 'string' type, and the input stream iterator is an 'int' type,
								  // the user's input [ must be an 'int' value ] will be converted into an ASCII character and be displayed to the 'cout' output stream

	istream_iterator<int> IsI_Empty;   // Creating an 'empty-iterator' of type 'int', to be used for end-of-input detection

	vector<int> vIntVector;

	IsI_Index++;   // Incrementing the 'input stream iterator' will move to the next data
				   // If the line above gets commented [ not incrementing ], the first element read from user's input will remain on the memory buffer

	while (IsI_Index != IsI_Empty)   // Using the 'empty-iterator' to detect 'end-of-input'
	{
		vIntVector.push_back(*IsI_Index);   // Adding the input to the vector
		IsI_Index++;
	}

	cout << endl;

	for (int iElement : vIntVector)   // Printing each element of the vector, filled-up by user's input
	{
		*OsI_Index = iElement;
		OsI_Index++;
	}

}

// #pragma pack (push, 2)
struct bDataStruct   // Creating a new 'struct' custom type 'bDataStruct'
{
	// 1 byte
	char cHeader;   // The first element should be a 'char' variable, to be used by the 'pointer-to-char' variable [ the first argument of the 'read()' and 'write()' functions ]
	// 4 bytes
	int32_t iX;     // 'int32_t' will make sure that the 'int' variable will have a fixed size of 32 bits, no matter what is the CPU and OS bit-size of the end-user machine
	// 4 bytes
	int32_t iY;     // This approach makes sure that the C++ software will achieve the same results on all systems
};   // 10 bytes on 16-bit machines, 12 bytes on 32-bit machines, 24 bytes on 64-bit machines
// #pragma pack (pop)

void M_BinaryFiles()
{
	bDataStruct WriteBinaryData{ 'C', 32, 64 };   // Creating a new variable of type 'struct' 'bDataStruct' to be used for writing [ every block uses Hex-encoding ]
												  // This will write to the file [ 43 CC CC CC 20 00 00 00 40 00 00 00 ] for 4-byte padding [ default ]
												  // This will write to the file [ 43 CC 20 00 00 00 40 00 00 00 ] for 2-byte padding
												  // '0x43' is the ASCII code for 'C' symbol;  '0xCC' is the padding-byte [ 'Ì' symbol ];
												  // '0x20' is the HTML number '32';  '0x40' is the HTML number '64'
												  // https://www.ascii-code.com/

	ofstream fOutputBinaryFile{ "F:\\Udemy\\Developer\\02_C++\\BinFile.bin", fstream::binary };   // Opens the given file, creating one if the file doesn't exist

	if (fOutputBinaryFile.is_open())
	{
		fOutputBinaryFile.write(reinterpret_cast<char*>(&WriteBinaryData), sizeof(bDataStruct));   // This expression: reads the size of the type [ in this case, the custom struct 'bDataStruct' ]
																								 //  creates a new 'pointer-to-char' for the object [ of type 'bDataStruct' ], and writes the data
	}
	else
	{
		cout << "Couldn't open the given file for writing." << endl;
	}

	fOutputBinaryFile.close();
	fOutputBinaryFile.close();

	bDataStruct ReadBinaryData{ 'H', 11, 22 };   // Creating a new variable of type 'struct' 'bDataStruct' to be used for reading

	ifstream fInputFile{ "F:\\Udemy\\Developer\\02_C++\\BinFile.bin", fstream::binary };   // Opnening the same file for reading

	if (fInputFile.is_open())
	{
		fInputFile.read(reinterpret_cast<char*>(&ReadBinaryData), sizeof(bDataStruct));

		cout << "The size in bytes of the data structure is:  " << sizeof(bDataStruct) << endl;

		cout << "The number of bytes received was:  " << fInputFile.gcount() << endl;

		cout << "The received data is:  " << ReadBinaryData.cHeader << ", " << ReadBinaryData.iX << ", " << ReadBinaryData.iY << ". " << endl;
	}
	else
	{
		cout << "Couldn't open the given file for reading." << endl;
	}

	fInputFile.close();
	fInputFile.close();
}

// Binary file: Bitmap
// Practicing with binary files [ corrupted data will invalidate the file, and invalid files cannot be opened ]

	// Bitmap is a simple image file-format, made-up of 'pixels', and each pixel consist of 3 bytes [ R,G,B, from 0 to 255 ] represented by a 'pixel' struct
	// The position of a pixel depends on its cartesian coordinates, written left-to-right, bottom-to-top [ the offset coordinate is ((Y * width) + X) ]
	// On the C++ code, the first pixel will be at the bottom-left of the image [ it means that the index of the 'vector of pixels' element will be the pixel's offset ((Y * width) + X) ]
	// The bitmap format has three parts: File Header, Info Header and Image Data
	// The Bitmap File Header was designed in 16-bit format [ 2-byte 'word-alignment' ], since it was created on MS-DOS operating system [ running on 16-bit Intel processors ]
	// The default Bitmap Headers are not Object-Oriented [ meaning that there is no encapsulation with protected or private members, and no 'class's interface' member functions ]
	// The default Bitmap Image Data is Object-Oriented, custom-designed by the C++ developer to store Image Data [ class 'Bitmap_ImageData' ]

#pragma pack (push, 2)
struct Bitmap_FileHeader
{
	char Header[2]{ 'B','M' };   // These 2 characters are designed to say what is the file-type
	                             // Fixed-width integers, to behave the same on every machine [ 16, 32 or 64 bits ]
	int32_t file_size;           // Contains the size of the file
	int32_t reserved{ 0 };       // Don't used by the C++ software
	int32_t data_offset;         // Offset data to say 'how far, from the beginning of the file, where the image data starts'
};
#pragma pack (pop)

struct Bitmap_InfoHeader
{
	// All the values are default values, excepting the 'width' and 'height' variables
	int32_t header_size{ 40 };
	int32_t width;    // Designed to be changed
	int32_t height;   // Designed to be changed
	int16_t planes{ 1 };
	int16_t bits_per_pixel{ 24 };
	int32_t compression{ 0 };
	int32_t data_size{ 0 };
	int32_t horizontal_resolution{ 2400 };
	int32_t vertical_resolution{ 2400 };
	int32_t colours{ 0 };
	int32_t important_colours{ 0 };
};

struct Bitmap_Pixel   // The standard Bitmap order is: Blue, Green, Red (developed by Microsoft)
{
	uint8_t blue;
	uint8_t green;
	uint8_t red;
};

class Bitmap_ImageData
{
public:

	Bitmap_ImageData();    // Default constructor function
	~Bitmap_ImageData();   // Default destructor function

	void SetFileName(const string &sNewFileName);

	void UpdateFile();

	void SetPixel(int X_NewPixel, int Y_NewPixel, Bitmap_Pixel Color_NewPixel);

	void SetRow(int Y_NewRow, Bitmap_Pixel Color_NewRow);

	void SetAll(Bitmap_Pixel Color_New);

	int GetWidth();
	int GetHeight();

protected:

private:

	int iWidth{ 800 };
	int iHeight{ 600 };
	std::string sFileName{""s};

	ofstream NewBitmapFile;
	Bitmap_FileHeader NewFileHeader;
	Bitmap_InfoHeader NewInfoHeader;
	std::vector <Bitmap_Pixel> NewFilePixels;   // A vector variable to store image data

	bool CheckFileName();
};

Bitmap_ImageData::Bitmap_ImageData()   // Default constructor function
{
	cout << endl << " Bitmap says:  A new Bitmap Object was created!" << endl;

	NewFilePixels.clear();

	Bitmap_Pixel BlankPixel{ 128,128,128 };

	for (int iPixels = 0; iPixels < (iWidth * iHeight); iPixels++)
	{
		NewFilePixels.push_back(BlankPixel);
	}
}

Bitmap_ImageData::~Bitmap_ImageData()   // Default destructor function
{
	cout << " Bitmap says:  The Bitmap Object was deleted!  Closing the Bitmap File..." << endl;

	NewBitmapFile.close();
	NewBitmapFile.close();
}

void Bitmap_ImageData::SetFileName(const string &sNewFileName)
{
	if (sNewFileName != "")
	{
		sFileName = sNewFileName;

		cout << " Bitmap says:  File-name set!" << endl;
	}
	else
	{
		cout << " Bitmap says:  Please specify a valid file-name!" << endl;
	}
}

bool Bitmap_ImageData::CheckFileName()
{
	if (sFileName != "")
	{
		// cout << " Bitmap says:  The file has a valid name..." << endl;
		return true;
	}
	else
	{
		cout << " Bitmap says:  Please specify the name of the file!  [ using the 'SetFileName()' member function ]" << endl;
	}
	return false;
}

void Bitmap_ImageData::UpdateFile()
{
	if (CheckFileName())
	{
		cout << " Bitmap says:  'UpdateFile()' member function called..." << endl;

		// Sets the standard values for the Bitmap file about to be created [ FileHeader and InfoHeader ]
		
		NewFileHeader.file_size = ((sizeof(Bitmap_FileHeader)) + (sizeof(Bitmap_InfoHeader)) + ((iWidth * iHeight) * (sizeof(Bitmap_Pixel))));

		NewFileHeader.data_offset = ((sizeof(Bitmap_FileHeader)) + (sizeof(Bitmap_InfoHeader)));

		NewInfoHeader.width = iWidth;

		NewInfoHeader.height = iHeight;

		// Creates the Bitmap file using the standard values set previously

		cout << " Bitmap says:  Updating the Bitmap File..." << endl;

		NewBitmapFile.open(sFileName, fstream::binary );

		if (NewBitmapFile.is_open())
		{
			cout << " Bitmap says:  Writing data into the Bitmap File..." << endl;

			// Writes the data into the file

			NewBitmapFile.write(reinterpret_cast<char*>(&NewFileHeader), sizeof(Bitmap_FileHeader));

			NewBitmapFile.write(reinterpret_cast<char*>(&NewInfoHeader), sizeof(Bitmap_InfoHeader));

			NewBitmapFile.write(reinterpret_cast<char*>(NewFilePixels.data()), ((NewFilePixels.size()) * sizeof(Bitmap_Pixel)));   // Notice the 'data()' member function
			// The std::vector '.data()' member cuntion returns a direct pointer to the memory array used internally by the vector to store its owned elements.

			cout << " Bitmap says:  The Bitmap File was updated! Closing..." << endl;
		}
		else
		{
			cout << " Bitmap says:  Could not open the file" << endl;
		}

		NewBitmapFile.close();
		NewBitmapFile.close();
	}
}

void Bitmap_ImageData::SetPixel(int iX_NewPixel, int iY_NewPixel, Bitmap_Pixel Color_NewPixel)
{
	if (CheckFileName())
	{
		int iPixelIndex = ((iY_NewPixel * iWidth) + iX_NewPixel);

		NewFilePixels[iPixelIndex] = Color_NewPixel;
	}
}

void Bitmap_ImageData::SetRow(int Y_NewRow, Bitmap_Pixel Color_NewRow)
{
	if (CheckFileName())
	{
		for (int iCounter = 0; (iCounter < iWidth); iCounter++)
		{
			SetPixel(iCounter, Y_NewRow, Color_NewRow);
		}
	}
}

void Bitmap_ImageData::SetAll(Bitmap_Pixel Color_New)
{
	if (CheckFileName())
	{
		for (int iCounter = 0; (iCounter < iHeight); iCounter++)
		{
			SetRow(iCounter, Color_New);
		}
	}
}

int Bitmap_ImageData::GetWidth()
{
	return iWidth;
}

int Bitmap_ImageData::GetHeight()
{
	return iHeight;
}

void M_BinaryFileBitmap()
{
	// The image to be drawn will be 'C++' written on a Bitmap file, using 4 variables:
	// 'x_unit' = the thickness on the X axis
	// 'y_unit' = the thickness on the Y axis
	// 'x_mid' = the center of the image at the X axis
	// 'y_mid' = the center of the image at the Y axis

	Bitmap_ImageData NewBitmap;

	NewBitmap.SetFileName("F:\\Udemy\\Developer\\02_C++\\CppGeneratedImage.bmp"s);

	NewBitmap.UpdateFile();

	int ColorDivider = ((NewBitmap.GetHeight()) / 8);

	{
		Bitmap_Pixel ColorIndex_01{ 0,0,0 };

		for (int iCounter = (ColorDivider * 0); iCounter < (ColorDivider * 1); iCounter++)
		{
			NewBitmap.SetRow(iCounter, ColorIndex_01);
		}

		Bitmap_Pixel ColorIndex_02{ 0,0,255 };

		for (int iCounter = (ColorDivider * 1); iCounter < (ColorDivider * 2); iCounter++)
		{
			NewBitmap.SetRow(iCounter, ColorIndex_02);
		}

		Bitmap_Pixel ColorIndex_03{ 0,255,0 };

		for (int iCounter = (ColorDivider * 2); iCounter < (ColorDivider * 3); iCounter++)
		{
			NewBitmap.SetRow(iCounter, ColorIndex_03);
		}

		Bitmap_Pixel ColorIndex_04{ 0,255,255 };

		for (int iCounter = (ColorDivider * 3); iCounter < (ColorDivider * 4); iCounter++)
		{
			NewBitmap.SetRow(iCounter, ColorIndex_04);
		}

		Bitmap_Pixel ColorIndex_05{ 255,0,0 };

		for (int iCounter = (ColorDivider * 4); iCounter < (ColorDivider * 5); iCounter++)
		{
			NewBitmap.SetRow(iCounter, ColorIndex_05);
		}

		Bitmap_Pixel ColorIndex_06{ 255,0,255 };

		for (int iCounter = (ColorDivider * 5); iCounter < (ColorDivider * 6); iCounter++)
		{
			NewBitmap.SetRow(iCounter, ColorIndex_06);
		}

		Bitmap_Pixel ColorIndex_07{ 255,255,0 };

		for (int iCounter = (ColorDivider * 6); iCounter < (ColorDivider * 7); iCounter++)
		{
			NewBitmap.SetRow(iCounter, ColorIndex_07);
		}

		Bitmap_Pixel ColorIndex_08{ 255,255,255 };

		for (int iCounter = (ColorDivider * 7); iCounter < (ColorDivider * 8); iCounter++)
		{
			NewBitmap.SetRow(iCounter, ColorIndex_08);
		}

	}

	NewBitmap.UpdateFile();

	cout << "Written data into the Bitmap File, check the file on the machine..." << endl;

}

class Ethernet
{
public:

	void Connect() { cout << " Ethernet:  Connected to the network!" << endl; }

	void Login(const string& UserID, const string& UserPW) {
		cout << " Ethernet Login:  Username provided:  " << UserID << endl;
		cout << " Ethernet Login:  Password provided:  " << UserPW << endl;
	}


protected:

private:

};

class Refrigerator
{
public:

	void PrintStatus() {
		cout << "The refrigerator temperature is:  " << Temperature << endl;
		cout << "The refrigerator is cooling?  ";
		if (IsCooling)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	// 1 - The default constructor member function, defined inside the class's body [ same as Refrigerator::Refrigerator() ]
	Refrigerator()
	{
		Connection.Connect();
		Connection.Login("Douglas", "Neiva");
	}

	// 2 - A 'function overload' of the 'default constructor' member function, setting the temperature [ ambiguous with the 4th overload ]
	Refrigerator(int SetTemp) : Temperature(SetTemp) {
		Connection.Connect();
		Connection.Login("Douglas", "Neiva");
	}

	// 3 - A 'function overload' of the 'default constructor' member function, setting New UserID and UserPW
	Refrigerator(const string& NewUserID, const string& NewUserPW) {
		Connection.Connect();
		Connection.Login(NewUserID, NewUserPW);
	}

	// 4 - A 'function overload' of the 'default constructor' member function, setting both the temperature and New UserID and UserPW
	Refrigerator(int SetTemp, const string& NewUserID = "Default_User"s, const string& NewUserPW = "Default_Password"s, bool SetPower = false) : Temperature(SetTemp), IsCooling(SetPower) {
		Connection.Connect();
		Connection.Login(NewUserID, NewUserPW);
	}

    // Constructor function overloads are constructor member function that initializes the data members with default arguments but accepting custom arguments
    // This member functions can be used when a new object is created, overwriting the default arguments by new custom arguments when a new object is created
	// All the non-initialized custom arguments should be the first arguments; and all the initialized default arguments should be the last arguments
	// [ C++ doesn't accept a non-initialized custom argument after an initialized default argument ]

protected:


private:
	int Temperature;
	bool IsCooling;
	Ethernet Connection;
};

// This programming technique is called DRY [ Don't Repeat Yourself ] - Using constructor's delegates avoids writing the same C++ code on every overloaded version
// Instead of writing 4 different constructors using the same C++ code, it can be refactored by using DRY technique and writing all the repeated code into a member function
// C++11 allows 'constructors calling constructors', where multiple constructor functions with multiple input signatures calls a 'delegate constructor function' with all the possible inputs
// [ so when a new object is created, the called constructor using the given input signature will 'delegate' to the 'delegate constructor function' with the complete input signature ]

class Delegator
{
public:

	Delegator() : Delegator(true, 7, 1.618034f) {};   // Default constructor [ with default arguments ] that will delegate to the 'delegate constructor'

	Delegator(const bool& Set_MV_01) : Delegator(Set_MV_01, 7, 1.618034f) {};   // Delegating [ Calling the 'delegate constructor' ]

	Delegator(const bool& Set_MV_01, const int& Set_MV_02) : Delegator(Set_MV_01, Set_MV_02, 1.618034f) {};   // Calling the 'delegate constructor'

	Delegator(const bool& Set_MV_01, const int& Set_MV_02, const double& Set_MV_03) : bMV_01(Set_MV_01), iMV_02(Set_MV_02), fMV_03(Set_MV_03) {   // Delegate constructor
		cout << "This member function delegate always gets called by the other constructors!  Setting all the class's variables..." << endl;
		cout << "bMV_01 value:  " << bMV_01 << endl;
		cout << "iMV_02 value:  " << iMV_02 << endl;
		cout << "fMV_03 value:  " << fMV_03 << endl;
	}

	void GetValues() {
		cout << "bMV_01 value:  " << bMV_01 << endl;
		cout << "iMV_02 value:  " << iMV_02 << endl;
		cout << "fMV_03 value:  " << fMV_03 << endl;
	};

protected:

private:

	// This class will have a 'Compiler-Generated' synthesized 'Copy Constructor' by implicitly calling the C++ code that initializes all the data members:
	// Delegator(const Delegator& New) : bMV_01(New.bMV_01), iMV_02(New.iMV_02), fMV_03(New.fMV_03) {}

	bool   bMV_01 = false;
	int    iMV_02 = 5;
	double fMV_03 = 3.141592f;
};

void M_MemberFunctions()
{
	cout << endl << "Fridge 01 says: " << endl;
	Refrigerator NewFridge_01;
	NewFridge_01.PrintStatus();

	cout << endl << "Fridge 02 says: " << endl;
	Refrigerator NewFridge_02("MyUser"s, "MyPassword"s);
	NewFridge_02.PrintStatus();

	cout << endl << "Fridge 03 says: " << endl;
	Refrigerator NewFridge_03(-25, "Unreal"s, "Engine"s);
	NewFridge_03.PrintStatus();

	cout << endl << "Delegator 01 says: " << endl;
	Delegator NewDelegateFunction_01;
	cout << endl << "Delegator 02 says: " << endl;
	Delegator NewDelegateFunction_02(true);
	cout << endl << "Delegator 03 says: " << endl;
	Delegator NewDelegateFunction_03(false,9);
	cout << endl << "Delegator 04 says: " << endl;
	Delegator NewDelegateFunction_04(true,14,2.718281f);

}

class CopyConstructor
{
public:

	// Default Constructor [ explicit C++ code ]
	CopyConstructor() {
		cout << "Calling the Default Constructor" << endl;
	};

	// Copy Constructor [ explicit C++ code ]
	CopyConstructor(const CopyConstructor& New) : bMV_01(false), iMV_02(9), fMV_03(3.141592f) {   // Custom C++ functionality can override the 'copy data members' default behavior
		cout << "Calling the Copy Constructor" << endl;
	};

	// Assignment Operator [ explicit C++ code ]
	CopyConstructor& operator=(const CopyConstructor& New) {
		cout << "Calling the Assignment Operator" << endl;

		bMV_01 += New.bMV_01;   // The 'AssignmentOperator()' could also be used to perform custom C++ functionality
		iMV_02 -= New.iMV_02;
		fMV_03 += New.fMV_03;

		return *this;
	};

	// Default Destructor [ explicit C++ code ]
	~CopyConstructor() {
		cout << "Calling the Default Destructor" << endl;

		bMV_01 = false;
		iMV_02 = 99;
		fMV_03 = 0.0f;
	};

	void GetValues() {
		cout << "bMV_01 value:  " << bMV_01 << endl;
		cout << "iMV_02 value:  " << iMV_02 << endl;
		cout << "fMV_03 value:  " << fMV_03 << endl;
	};

protected:

private:

	bool   bMV_01 = true;
	int    iMV_02 = 2;
	double fMV_03 = 1.618034f;
};

void M_CopyConstructor()
{
	cout << endl << "Delegator says: " << endl;
	Delegator NewDelegateFunction(true, 15, 2.718281);   // Creating a new object and calling the class's constructor

	cout << endl << "Copy Constructor 01 says: " << endl;
	Delegator NewCopyConstructor01(NewDelegateFunction);   // Creating a new object and calling the Copy Constructor [ initializes using the same values as the existing object ]
	NewCopyConstructor01.GetValues();

	cout << endl << "Copy Constructor 02 says: " << endl;
	Delegator NewCopyConstructor02 = NewDelegateFunction;   // Creating a new object and also calling the Copy Constructor [ initializes using the same values as the existing object ]
	NewCopyConstructor02.GetValues();

	cout << endl << "Copy Constructor - Object_01  says: " << endl;
	CopyConstructor Object_01;              // Creating a new object by using the 'Default Constructor' [ won't call the explicit C++ code 'CopyConstructor()' ]
	Object_01.GetValues();                  // The data members will have its values initialized from the class's default values

	cout << endl << "Copy Constructor - Object_02  says: " << endl;
	CopyConstructor Object_02(Object_01);   // Creating a new object by using the 'Copy Constructor' [ won't call the explicit C++ code 'DefaultConstructor()' ]
	Object_02.GetValues();                  // The data members will have its values initialized from the explicit C++ code 'CopyConstructor()'

	cout << endl << "Copy Constructor - Object_03  says: " << endl;
	CopyConstructor Object_03 = Object_01;   // Creating a new object by using the 'AssignmentOperator=', but calls the 'CopyConstructor()' [ won't call the explicit C++ code 'AssignmentOperator()' ]
	Object_03.GetValues();                   // The data members will have its values initialized from the explicit C++ code 'CopyConstructor()'

	cout << endl << "Copy Constructor - Object_04  says: " << endl;
	CopyConstructor Object_04;   // Creates an empty object [ with the class's default values ] and calls the 'DefaultConstructor()'
	Object_04 = Object_01;       // Copies the Object_01 to the Object_04 by using the 'AssignmentOperator=' and calling the 'AssignmentOperator()'
	Object_04.GetValues();       // The data members will have its values set the same values from the Object_01

	cout << endl << "Objects now reaching 'out-of-scope'... " << endl;

}

class CustomString
{
public:

	CustomString() : CustomString("X"s) {};   // Delegating Constructor()
	CustomString(const std::string& Data);    // Constructor() delegate, allocates the memory on the heap
	~CustomString();   // ~Destructor(), releases the memory allocated on the heap

	CustomString(const CustomString& NewCopy) {   // Copy Constructor
		cout << "'CopyConstructor()' call from 'CustomString' class, 'Deep Copying'..." << endl;

		StringSize = (NewCopy.StringSize);
		StringData = new char[StringSize];   // Allocates [ acquires ] the resource [ the memory buffer on the heap ], avoids blindly copying the pointer address

		for (int Counter = 0; Counter < StringSize; Counter++)   // Populate the data
		{
			StringData[Counter] = NewCopy.StringData[Counter];
		}

		cout << "'CustomString' copy-object says:  Size - " << StringSize << " elements,  Content - ";
		PrintContent();
	};

	CustomString&  operator=(const CustomString& NewAssignment) {   // [NewAssignment] is a class's object
		cout << "'AssignmentOperator()' call from 'CustomString' class, 'Deep Assigning'..." << endl;
		
		if ((&NewAssignment) == (this))   // Checking self-assignment using the object's address
		{                                 // [ this ] is a pointer [ and its value is an address ]
			cout << "Self assignment!" << endl;
		}
		else
		{
			StringSize = 0;
			delete[] StringData;

			StringSize = NewAssignment.StringSize;
			StringData = new char[StringSize];

			for (int Counter = 0; Counter < StringSize; Counter++)
			{
				StringData[Counter] = NewAssignment.StringData[Counter];
			}
		}

		cout << "'CustomString' assigned-object says:  Size - " << StringSize << " elements,  Content - ";
		PrintContent();

		return *this;   // [ *this ] is the class's object that the pointer is pointing-to
	};

protected:

private:

	char* StringData;   // In this case, the pointer will be overwritten by a new address on the synthesized 'CopyConstructor()', causing memory-leaks
	int   StringSize;   // and the same is true for the synthesized 'AssignmentOperator()'

	void PrintContent() {
		for (int Counter = 0; Counter < StringSize; Counter++)   // Populate the data
		{
			cout << StringData[Counter];
		}
		cout << "." << endl;
	};
};

CustomString::CustomString(const std::string& Data)   // Constructor() delegate
{
	cout << "Creating a new 'CustomString' object..." << endl;

	StringSize = (Data.size());
	StringData = new char[StringSize];   // Allocates [ acquires ] the resource [ the memory buffer on the heap for the array ]

	for (int Counter = 0; Counter < StringSize; Counter++)   // Populate the data
	{
		StringData[Counter] = Data[Counter];
	}

	cout << "'CustomString' object says:  Size - " << StringSize << " elements,  Content - ";
	PrintContent();
}

CustomString::~CustomString()   // ~Destructor()
{
	cout << "Deleting the 'CustomString' object..." << endl;

	delete [] StringData;   // Releases the resource [ the memory buffer on the heap allocated for the array ]
	StringSize = 0;
}

void M_RAIIstring()
{
	CustomString MyString_01;
	CustomString MyString_02("Y"s);
	CustomString MyString_03("DOUGLAS"s);
	cout << endl;

	CustomString MyString_04(MyString_03);
	cout << endl;

	MyString_02 = MyString_03;   // Calls the 'AssignmentOperator()' default branch
	MyString_03 = MyString_03;   // Calls the 'self-assignment' branch [ does nothing ]
}

class TestClass
{
public:

	explicit TestClass() { cout << "A new 'TestClass' object was created! " << endl; };   // Default Constructor()
	~TestClass() { cout << "The 'TestClass' object was deleted! " << endl; };    // Default Destructor()

	// 'Conversion Operator' special member function that converts this object from a 'TestClass' type into a 'bool' type
	explicit operator bool() const {   // In this case, the 'bPowered' data member will be returned by this object when the expression expects a 'bool' type
		cout << "Calling the 'this-to-bool' ConversionOperator()..." << endl;
		return bPowered;
	};

	// 'Conversion Operator' special member function that converts this object from a 'TestClass' type into an 'int' type
	operator int() const {   // In this case, the 'iPower' data member will be returned by this object when the expression expects an 'int' type
		cout << "Calling the 'this-to-int' ConversionOperator()..." << endl;
		return iPower;
	};

	bool bPowered = false;
	int  iPower = 35;

protected:

private:

	// bool bPowered = false;
	// int  iPower = 35;
};

void M_ConversionOperator()
{
	TestClass NewTest_01;
	TestClass NewTest_02;
	cout << endl;

	int iCounter = 8;
	iCounter += NewTest_01;   // The 'Conversion Operator' for the 'int' type will be called

	cout << "Object 01   Power:  " << NewTest_01.iPower << endl;
	cout << "Total added Power:  " << iCounter << endl;
	cout << endl;

	if (NewTest_02)   // The 'Conversion Operator' for the 'bool' type will be called
	{
		cout << "Object 02 is powered!" << endl;
	}
	else
	{
		cout << "Object 02 is not powered!" << endl;
	}

	NewTest_02.bPowered = true;

	if (NewTest_02)   // The 'Conversion Operator' for the 'bool' type will be called
	{
		cout << "Object 02 is now powered!" << endl;
	}
	else
	{
		cout << "Object 02 is now not powered!" << endl;
	}
	cout << endl;

	cout << NewTest_01 << endl;   // Will cause an 'implicit conversion' error, since it could ask for either 2 or more 'ConversionOperator()' functions defined
	// [ error: 'the operator << is ambiguous' ], the error could be solved by setting all the 'ConversionOperator()' functions 'explicit' excepting one [ this one will be used
    // on implicit conversions, in this case, the 'int' Conversion Operator ]

	// Asking specifically for the 'operator int()' [ explicit conversion ]
	cout << NewTest_01.operator int() << endl;

	// Asking specifically for the types by casting [ casting also calls the 'ConversionOperator()' special member functions ]
	cout << "Bool value:  " << static_cast<bool>(NewTest_02) << ".  Int value: " << static_cast<int>(NewTest_02) << ". " << endl;

	cout << endl;

}

class CompilerClass
{
public:

	// Explicitly forcing the compiler to call this constructor, even if there are other constructors declared
	
	// Forcing the compiler to create a synthesized default Constructor()
	CompilerClass() = default;

	// Forcing the compiler to delete the synthesized CopyConstructor()
	CompilerClass(const CompilerClass& New) =delete;   // This '=delete' keyword makes the class's objects uncopyable

	// Forcing the compiler to delete the synthesized AssignmentOperator()
	CompilerClass& operator=(const CompilerClass& New) =delete;   // This '=delete' keyword makes the class's objects uncopyable

	// Forcing the compiler to create a synthesized default Destructor(), but does nothing
	~CompilerClass() =default;


protected:

private:

	bool bPowered = true;
	int  iPower = 23;

};

void M_DefaultDelete()
{
	CompilerClass NewObject_01;
	CompilerClass NewObject_02;

	// NewObject_01 = NewObject_02;   // This will cause an error [ ' operator= function was explicitly deleted, attempting to reference a deleted function' ]
}

class OpOverload
{
public:

	OpOverload(int iNewValue = 2, string sNewName = "B") : iValue(iNewValue), sName(sNewName) {
		cout << "Creating a new object..." << endl;
	};

	~OpOverload() { cout << "Deleting the object..." << endl; };

	// This function [ declared and defined within the class's body ] have the same behavior as the 'Friend' function [ defined outside the class's body ]
	
	OpOverload operator+(const OpOverload& InputObj)   // Built-in operator'+' overload, only accessible by the class's object, but takes only one argument
	{
		cout << "  Built-in(): Adding 2 objects of class 'OpOverload' by using '+' operator overloading, 1 argument [ unary ]... " << endl;

		OpOverload NewOverloaded;

		NewOverloaded.iValue = iValue + InputObj.iValue;
		NewOverloaded.sName = sName + InputObj.sName;

		cout << "The 1 result is: " << NewOverloaded.iValue << ", " << NewOverloaded.sName << "." << endl;

		return NewOverloaded;
	};
	
	// Breaking the 'encapsulation' property by using the 'friend' keyword
	// friend OpOverload operator+(const OpOverload& InputObj01, const OpOverload& InputObj02);   // Friend operator'+' overload, accessible anywhere
																							      // Declared within the class's body, defined outside of the class's scope

	// Avoiding the 'friend' keyword by delegating external a non-member-function call [ that takes this class's object as an argument ] to this member-function [ must be 'const' ]
	void PrintContent() const { cout << "Object content:  " << iValue << ", " << sName << "." << endl; };   // Public member function with access to protected / private members

protected:

private:

	int iValue{ 3 };
	string sName{ "Y" };

};

// Breaking the 'encapsulation' property by using the 'friend' keyword
// Friend operator'+' overload, accessible anywhere [ declared within the class's body, defined outside of the class's scope ]
/*
OpOverload operator+(const OpOverload& InputObj01, const OpOverload& InputObj02)   // Friend operator'+' overload, accessible anywhere
{
	cout << "Friend(): Adding 2 objects of class 'OpOverload' by using '+' operator overloading, 2 arguments [ binary ]... " << endl;

	int iNewValue = InputObj01.iValue + InputObj02.iValue;
	string sNewName = InputObj01.sName + InputObj02.sName;

	OpOverload NewOverloaded(iNewValue, sNewName);

	cout << "The 2 result is: " << NewOverloaded.iValue << ", " << NewOverloaded.sName << "." << endl;

	return NewOverloaded;
};
*/

// Avoiding the 'friend' keyword by delegating external a non-member function call [ that takes this class's object as an argument ] to this member function
void PrintObjectContent(const OpOverload& Object)   // Non-member function that delegates the function call to the public member function
{
	Object.PrintContent();   // When delegating a non-member-function call to a member-function call, the member-function must be 'const'
							 // to avoid any changes on the class's members
}

void M_OperatorsOverloads()
{
	cout << endl << "   [1] Creating objects..." << endl;
	OpOverload NewObject_01;
	OpOverload NewObject_02(7,"H");
	OpOverload NewObject_03(8,"Z");

	cout << endl << "   [2] Adding objects..." << endl;
	NewObject_01 = NewObject_02 + NewObject_03;

	cout << endl << "   [3] Printing object contents..." << endl;
	PrintObjectContent(NewObject_01);
	PrintObjectContent(NewObject_03);

	cout << endl << "   [4] Deleting objects..." << endl;
}

class MemberOps
{
public:

	MemberOps(int iC = 0, float fR = 0.0f) : iCounter(iC), fRange(fR) {   // Default initializer constructor
		cout << "A new object was created!" << endl;
		cout << "Printing obj values:  " << iCounter << ",  " << fRange << ". " << endl;
	};
	
	MemberOps(const MemberOps& NewCopy) : iCounter(NewCopy.iCounter), fRange(NewCopy.fRange) {   // Copy constructor
		cout << "Calling the 'copy constructor'!" << endl;
		cout << "Printing new values:  " << iCounter << ",  " << fRange << ". " << endl;
	};

	~MemberOps() { cout << "The object was deleted!" << endl; };   // Default destructor

	MemberOps operator +=(const MemberOps& NewObj) {   // '+=' operator [ compound assignment ]

		cout << "Calling the '+=' operator..." << endl;

		iCounter += NewObj.iCounter;
		fRange += NewObj.fRange;

		return *this;   // Returns the modified object by reference [ dereferencing the 'this' pointer ]
	};

	friend MemberOps operator +(const MemberOps& NewObj_01, const MemberOps& NewObj_02);   // '+' operator [ delegating to the compound assignment ]


	// Equality operator [ should be a non-member-function since it's binary, taking 2 arguments ]
	friend bool operator ==(const MemberOps& NewObj_01, const MemberOps& NewObj_02);

	// Inequality operator, the inverse of the 'equality' operator [ should be a non-member-function since it's binary, taking 2 arguments ]
	friend bool operator !=(const MemberOps& NewObj_01, const MemberOps& NewObj_02);


	// More-than operator [ should be a non-member-function since it's binary, taking 2 arguments ]
	friend bool operator >(const MemberOps& NewObj_01, const MemberOps& NewObj_02);

	// Less-than operator, the inverse of the 'more-than' operator [ should be a non-member-function since it's binary, taking 2 arguments ]
	friend bool operator <(const MemberOps& NewObj_01, const MemberOps& NewObj_02);

	// Prefix-increment '++' operator
	MemberOps& operator ++() {
		cout << "Calling the 'prefix-increment' ++ operator" << endl;

		++iCounter;
		++fRange;
		return *this;   // Returns by reference
	};

	// Postfix-increment '++' operator [ needs a different input signature to be recognized as a postfix operator, and uses an 'int' argument ]
	MemberOps operator ++(int iDummy) {   // Since there is no difference on both '++' operator functions, the postfix operators needs a 'dummy' 'int' argument
		cout << "Calling the 'postfix-increment' ++ operator" << endl;

		MemberOps temp(*this);   // Needs a 'copy-constructor' function
		++iCounter;
		++fRange;
		return temp;   // Returns by value
	};

protected:

// private:
public:

	int iCounter{ 2 };
	float fRange{ 2.718281f };
};

// Addition operator
MemberOps operator +(const MemberOps& NewObj_01, const MemberOps& NewObj_02) {

	cout << "Calling the '+'  operator..." << endl;

	MemberOps NewObj_03{ NewObj_01 };   // The class needs to implement the copy constructor

	NewObj_03 += NewObj_02;   // Delegating to the 'compound-assignment addition' operator

	// NewObj_03.iCounter = NewObj_01.iCounter + NewObj_02.iCounter;   // Already implemented on the '+=' operator
	// NewObj_03.fRange = NewObj_01.fRange + NewObj_02.fRange;         // Already implemented on the '+=' operator

	return NewObj_03;
};

// Equality operator
bool operator ==(const MemberOps& NewObj_01, const MemberOps& NewObj_02) {

	cout << "Calling the '==' operator..." << endl;

	if (NewObj_01.iCounter == NewObj_02.iCounter)
	{
		if (NewObj_01.fRange == NewObj_02.fRange)
		{
			return true;
		}
	}

	return false;
};

// Inequality operator
bool operator !=(const MemberOps& NewObj_01, const MemberOps& NewObj_02) {

	cout << "Calling the '!=' operator..." << endl;

	bool bInequality = (NewObj_01 == NewObj_01);

	return (!bInequality);
};


// More-than operator
bool operator >(const MemberOps& NewObj_01, const MemberOps& NewObj_02)
{
	cout << "Calling the '>' operator..." << endl;

	if (NewObj_01.iCounter > NewObj_02.iCounter)
	{
		if (NewObj_01.fRange > NewObj_02.fRange)
		{
			return true;
		}
	}

	return false;
}

// Less-than operator
bool operator <(const MemberOps& NewObj_01, const MemberOps& NewObj_02)
{
	cout << "Calling the '<' operator..." << endl;

	if (NewObj_01.iCounter < NewObj_02.iCounter)
	{
		if (NewObj_01.fRange < NewObj_02.fRange)
		{
			return true;
		}
	}

	return false;
}

void M_MemberOperators()
{
	// Addition operators [ simple '+' and compound '+=' ]

	MemberOps Obj_01(3, 3.141592f);
	MemberOps Obj_02(7, 1.618034f);
	cout << endl << endl;

	MemberOps Obj_03{ Obj_02 };
	cout << endl << endl;

	Obj_02 += Obj_03;
	cout << endl << endl;

	Obj_01 = Obj_02 + Obj_03;
	cout << endl << endl;

	cout << "Printing final values:  " << Obj_01.iCounter << ",  " << Obj_01.fRange << ". " << endl;
	cout << endl << endl;

	MemberOps Obj_04(Obj_02);

	// Equality and inequality operators
	if (Obj_01 == Obj_03)
	{
		cout << "The 2 objects are equal!" << endl;
	}
	else
	{
		cout << "The 2 objects are different!" << endl;
	}

	if (Obj_02 != Obj_04)
	{
		cout << "The 2 objects are different!" << endl;
	}
	else
	{
		cout << "The 2 objects are equal!" << endl;
	}


	// More-than and Less-than operators
	if (Obj_01 > Obj_03)
	{
		cout << "The first object is bigger!" << endl;
	}
	else
	{
		cout << "The second object is bigger!" << endl;
	}

	if (Obj_02 < Obj_04)
	{
		cout << "The second object is bigger!" << endl;
	}
	else
	{
		cout << "The first object is bigger!" << endl;
	}
}

void M_VectorSort()
{
	cout << "Sorting elements of a vector..." << endl;

	vector<string> sNames = { "Stephen", "James", "Djow", "Biel", "Bueno", "T" };

	cout << "Vector [of strings] before sorting: ";
	for (string Name : sNames)
	{
		cout << Name << ", ";
	}
	cout << endl;

	// std::sort is defined on the <algorithm> Standard Library
	sort((begin(sNames)), (end(sNames)));   // Sorts the vector variable and makes a permanent change on the element's order

	cout << "Vector [of strings] after sorting: ";
	for (string Name : sNames)
	{
		cout << Name << ", ";
	}
	cout << endl;
}

void M_PointerIterator()
{
	char aChars[] = {'D', 'O', 'U', 'G', 'L', 'A', 'S' };

	char* pIterator = aChars;    // The 'pointer-to-string' variable will point at the very first element of the vector [ the variable receiver the vector without the 'address-of' operator ]

	for (int i=0; i<7; ++i)      // Iterator using the number of vector's elements
	{
		cout << *pIterator;      // Dereferences the pointer, accessing the element pointed-to on the vector
		++pIterator;             // Iterates the pointer, so the pointer moves to the next address [ the next element of the vector, since it's a container, a compound data structure ]
	}
	cout << endl;
}

class Callable
{
public:

	Callable() { cout << "A new object was created!" << endl; };
	~Callable() { cout << "The object was deleted!" << endl; };

	void NMF(int i1, int i2);   // Non-member-function, declared with default arguments

	int iCounter{ 0 };
	float fRange{ 3.141592f };

	// void (*pfNMF)(int, int) = &NMF;   // Creating a 'pointer-to-function' with the same input-signature data-types [ C-style ]

	// Function-call '()' operator, can take any input signature and can return anything [ supports overloading ]
	void operator()(int i3) {
		cout << "Calling the function-call-operator(), argument:  " << i3 << endl;

	}

	void print(ostream& OutputStream) const {   // The 'const' keyword means that the function is 'read-only'. and doesn't modify data
		OutputStream << "Object data: " << iCounter << ", " << fRange << ". " << endl;
	}


protected:

private:

};

void Callable::NMF(int i1, int i2)
{
	cout << "Calling the NMF with the values: " << i1 << ", " << i2 << ". " << endl;
	iCounter = (i1 + i2);
}

std::ostream& operator <<(std::ostream& OutStream, const Callable& Obj)   // Since it's an 'operator overload', it not needed to be a 'friend' class's member
{
	cout << "Calling the 'left-shift operator <<' overload for a 'Callable' object... " << endl;
	Obj.print(OutStream);
	return OutStream;
}

void M_FunctionCallOp()
{
	Callable Obj_01;   // In this case, the 'Obj_01' is a 'functor' object [ its class defines an 'function-call operator()' ]
	
	// Obj_01.pfNMF(3, 4);

	Obj_01(14);   // Calling the 'Function-call operator ()', using the same input signature [ the same as Obj_01.operator()(...) ]
	Obj_01.operator()(23);   // In this case, the 'Callable' class is a 'functor' [ defines an 'function-call operator()' ]

	Obj_01.print(cout);   // A generic member function that prints the object's data using an output stream as an argument [ can be cout, ofstream or any other output stream ]

	cout << endl << Obj_01;   // Using the binary 'left-shift <<' overloaded operator designed to use the 'Callable' class's object
}

// Defining a custom 'predicate' function [ that compares the size of 2 strings and returns a 'bool' value ]
bool is_shorter(const string& sName1, const string& sName2)
{
	return ((sName1.size()) < (sName2.size()));
}

void M_StringAlgorithms()
{
	std::string sName{ "Douglas"s };
	char cSearch{ 'T' };

	cout << "Find() using the std::string" << endl;
	cout << "The string is:  " << sName << endl;
	cout << "The '" << cSearch << "' letter is at the position: " << (sName.find(cSearch)) << endl;   // This 'find()' [ from std::string ] returns an index
	cout << endl;


	cout << "Find() using the std::find <algorithm>" << endl;
	cout << "The string is:  " << sName << endl;

	auto cResult = find(cbegin(sName), cend(sName), cSearch);   // The 'cend()' is the 'one after last' element [ next memory address out of the container ]

	if (cResult != cend(sName))   // If the character is not found, the iterator will return the 'one after last' element
	{
		cout << "The '" << cSearch << "' letter is at the position: " << (distance((cbegin(sName)), cResult)) << endl;   // This 'find()' [ from std::string ] returns an index
	}
	else
	{
		cout << "The '" << cSearch << "' letter was not found." << endl;
	}
	cout << endl;

	vector<string> sNames = { "Stephen"s, "James"s, "Djow"s, "Biel"s, "Bueno"s, "T"s };

	cout << "Vector before sorting..." << endl;   // Prints the vector's content
	for (string Name : sNames)
	{
		cout << Name << ", ";
	}
	cout << endl << endl;

	sort((begin(sNames)), (end(sNames)));   // Uses the default predicate for the 'less-than <' operator, built-in on std::string
	cout << "Vector after sorting alphabetically [ default predicate ]..." << endl;
	for (string Name : sNames)
	{
		cout << Name << ", ";
	}
	cout << endl << endl;

	sort((begin(sNames)), (end(sNames)), is_shorter);   // Uses the custom predicate for the 'less-than <' operator, created by the C++ developer [ 'function-pointer' third argument ]
	cout << "Vector after sorting by length [ custom predicate ]..." << endl;
	for (string Name : sNames)
	{
		cout << Name << ", ";
	}
	cout << endl << endl;

}

class FunctorMt
{
public:

	FunctorMt(const int iChars) : iCharacters(iChars) { cout << "A new object was created!  Value: " << iCharacters << endl; };
	~FunctorMt() { cout << "The object was deleted!" << endl; };

	// Overloaded Function-Call operator(), acting as the 'Function predicate argument' [ returns a 'bool' value ] for the <algorithm> 'std::find_if()' function
	bool operator()(const string& sVar) const {   // Evaluates if the string size is bigger than the desired number of characters

		// cout << "Function-call operator() called, function predicate..." << endl;
		return ((sVar.size()) > iCharacters);
	}

protected:

private:

	const int iCharacters{ 1 };   // This variable can be called as the 'functor-state'
};

void M_PredicateFunction()
{
	vector<string> sNames = { "Stephen"s, "James"s, "Douglas"s, "Biel"s, "Bueno"s, "T"s };
	FunctorMt NewFunctor(4);

	cout << "Printing vector content..." << endl;
	for (string Name : sNames)
	{
		cout << Name << ", ";
	}
	cout << endl << endl;

	// Non-algorithm C++ code
	for (string Name : sNames)   // Ranged 'for-loop'
	{
		if (NewFunctor(Name))   // Calls the 'function-call-operator' that takes one string as input signature
		{
			cout << "[Manual] The name  '" << Name << "' has more than 4 characters." << endl;
		}
	}
	cout << endl;

	// Algorithm C++ code '_if()'
	auto Result1 = find_if((cbegin(sNames)), (cend(sNames)), FunctorMt(4));   // Calls the 'std::find_if()' [ defined on the <algorithm> library ] wiht the 'functor' as the predicate

	// In this case, the 'predicate function' input signature on the 'functor' class should have 1 argument and match the variable type, because the 'std::find_if()'
	// will call the 'functor' on each element of the iteration, and the 'Result' variable is the 'pointer' iterator returned by the 'std::find_if()'

	if (Result1 != (cend(sNames)))   // The 'std::find_if()' returns only the first result
	{
		cout << "[Algorithm] The name  '" << (*Result1) << "' is the first with more than 4 characters." << endl;   // Since the 'Result' is a 'pointer' variable, it should be dereferenced
	}
	cout << endl;

	// Algorithm C++ code '_if_not()'
	auto Result2 = find_if_not((cbegin(sNames)), (cend(sNames)), FunctorMt(4));   // Setting the 'state of the functor' with the value 4

	if (Result2 != (cend(sNames)))   // The 'std::find_if_not()' returns only the first result
	{
		cout << "[Algorithm] The name  '" << (*Result2) << "' is the first with 4 characters or less." << endl;
	}
	cout << endl;

	// Algorithm C++ code '_if()' with a 'Lambda Expression'
	cout << "Using a Lambda Expression!" << endl;
	auto Result3 = find_if((cbegin(sNames)), (cend(sNames)), [](string sMyName)->bool { return (sMyName == "Douglas"); } );
	// The argument-type of the lambda expression should match the iterator's type, and the 'bool' return type was explicitly written

	if (Result3 != (cend(sNames)))   // The 'std::find_if_not()' returns only the first result
	{
		cout << "[Algorithm] The name  '" << (*Result3) << "' was recognized as the Developer's Name." << endl;
	}
	cout << endl;


}

char cGlobal{'A'};   // By default, it can be accessed by the lambda expression

bool equal_strings(const string& ct1, const string& ct2)
{
	static char cStaticLocal{ 'B' };   // By default, it can be accessed by the lambda expression
	const char cLocal{ 'C' };          // Cannot be accessed by the lambda expression [ error message: 'cannot be implicitly captured, because no default capture mode has been specified' ]
	const char& cRefLocal{ 'D' };      // Cannot be accessed by the lambda expression [ error message: 'cannot be implicitly captured, because no default capture mode has been specified' ]

	// Calling the 'equal()' algorithm overloaded [ with a Lambda Expression as the Predicate Function ]

	return (equal((cbegin(ct1)),(cend(ct1)),(cbegin(ct2)),(cend(ct2)),      // In this case, the 'equal()' algorithm compares each character between 2 std::string containers
		[](char cC1, char cC2) { return (toupper(cC1) == toupper(cC2)); }   // The Lambda Expression converts all character to upper-case [ case-non-sensitive ]
		));
}

void test_strings(const string& st1, const string& st2)
{
	// Calling the 'equal_strings' function to compare 2 elements [ with the 'equal()' algorithm defined within the function ]

	cout << st1 << " and " << st2 << " are" << ((equal_strings(st1, st2)) ? "" : " not") << " equal." << endl;   // Using the 'single-line if-statement'
}

void M_CompareStringsLambda()
{
	test_strings("Lambda", "lambda");
	test_strings("Lambda", "lembda");
}

class Generated_LE   // The C++ compiler will generate a 'functor' object similar to the 'Generated_LE' class written below
{
public:

	Generated_LE(const int iMin, int& iIndex) : iMin(iMin), iIndex(iIndex) {};   // Class's constructor, passing arguments by value and by reference

	bool operator() (const string& sString) const   // The 'function-call-operator ()' generated by the lambda expression, with the same input signature expected by the 'find_if' algorithm
	{
		++iIndex;
		return ((sString.size()) < iMin);
	};

protected:

private:

	const int iMin;   // Data member 'int' declared as 'const', cannot be modified, will be captured by value by receiving the lambda expression's input
	int& iIndex;      // Data member 'ref-to-int' declared without the 'const' keyword, will act as an 'alias' by receiving the 'address-of' the lambda expression's input [ passing by reference ]
};

void M_LambdaCaptures()
{
	vector<string> sNames = { "Douglas", "Stephen", "Biel", "Bueno", "T", "Djow", "Mu" };

	int iMin{ 2 }, iIndex{ -1 };

	auto Result = find_if((cbegin(sNames)),(cend(sNames)),   // The 'auto' Result variable will be a 'pointer-to-element', used by the 'find_if()' algorithm as the iterator
		[iMin, &iIndex](const string& Name) { ++iIndex;  return ((Name.size()) < iMin);  }   // This lambda expression will generate a 'functor' object based on the 'Generated_LE' class written above
		// Generated_LE(iMin, iIndex)   // Will generate the same results as the lambda expression written above
		);

	if (Result != (cend(sNames)))
	{
		cout << "The first word with less than " << iMin << " characters is:  " << *Result << endl;
		cout << "Its index on the vector is:  " << iIndex << endl;
	}

}

auto FTRALE(const string& sInput_01)   // 'FTRALE' stands for 'Function That Returns A Lambda Expression', must have an 'auto' retunr-type, allowed on C++14
{
	return [sInput_01](const string& sInput_02) { return (sInput_01 + ", "s + sInput_02); };
}

void M_PartialEvaluation()
{
	cout << "Creating a variable [ 'auto' type ] to store a lambda expression" << endl << "[converted to an object from a generated 'functor' class]..." << endl << endl;

	vector<string> sNames = { "T", "Djow", "Mu", "Douglas", "Stephen", "Biel", "Bueno" };
	int iMax{ 4 }, iIndex{ -1 };

	auto foPredicate_01 = [=, &iIndex] (const string& Name) { ++iIndex; return ((Name.size()) > iMax); };   // The compiler will provide the variable type [ 'functor' object ], must be 'auto'

	auto Result = find_if((cbegin(sNames)), (cend(sNames)), foPredicate_01);   // The compiler will provide the variable type [ iterator pointer ], must be 'auto', allowed on C++14

	if (Result != (cend(sNames)))
	{
		cout << "The first element with more than " << iMax << " characters is:  " << *Result << endl;
		cout << "Its index of the element on the vector is:  " << iIndex << endl;
	}

	auto LEO = FTRALE("Name_01"s);   // 'LEO' stands for 'Lambda Expression Object'; it will be a Lambda which takes the 'sInput_02' string as an argument and adds the "Name_01"s string to it

	cout << LEO("Name_02"s) << endl;   // In this case, the value "Name_01"s is defined on the 'LEO' Lambda-Variable initialization, that receives the "Name_02"s as an argument

	// In this case, 'Partial Evaluation' was implemented by the 'LEO' variable that only needs the second name as an argument [ the first name was already defined on the variable's initialization ]
	// Another 'Partial Evaluations' could be implemented by creating a new 'FTRALE' variable, initializing it with a different 'Name_01' value
}

int& DanglingFunction()   // Returns a 'ref-to-int' variable [ alias ]
{
	int X{ 7 };   // Local variable 'X'
	return X;     // The local variable 'X' is destroyed as soon as the function returns
}

void M_DanglingReference()
{
	cout << DanglingFunction() << endl;

	int Y{ 3 };
	Y -= (--(DanglingFunction()));   // Could crash the C++ software, since the variable 'X' is being destroyed on its scope
	cout << Y << endl;

	int& Z = DanglingFunction();   // 'Z', acting as an alias, receives the reference of the local variable 'X' [ about to be destroyed on its scope ]
	--Z;
	cout << Z << endl;
	cout << endl;

	auto LEO = [&](const string sDef = "Default_Lambda_String"s) { cout << sDef << endl;  cout << Z << endl;  return true; };   // Captures all the variables by reference
	cout << (LEO()) << endl;   // Since the Lambda Expression has captured 'Z' [ and alias of 'X' ], and since 'X' was deleted [ out of scope ], the 'X' address now contains garbage data

}

class Class_GLE   // The C++ equivalent of the 'functor' class generated by a 'Generic Polymorphic Lambda'
{
public:

	template <typename Obj_GLE>      // Generic independent return-type from the 'function-call operator()'

	Obj_GLE operator() (Obj_GLE X, Obj_GLE Y, Obj_GLE Z) { return (X + Y + Z); };   // Similar to a C++ equivalent of the 'Generic Polymorphic Lambda' expression body 
																					// [ in this case, both input-signature and return-type should be the same variable-type ]	 
protected:

private:

};

void M_GenericLambdas()
{
	auto GLE1 = [=](auto X, auto Y, auto Z) { return (X + Y + Z); };   // By using C++14, the compiler will always deduce the type of all the 'auto' variables 
																	  // [ all C++ operators used on the Generic 'Polymorphic Lambda' needs to be implemented for all input variable-types ]

	cout << "Generic Lambda Expression with 'int' returns:          " << GLE1(2, 4, 6) << endl;
	cout << "Generic Lambda Expression with 'float' returns:        " << GLE1(3.141592f, 2.718281f, 1.618034f) << endl;
	cout << "Generic Lambda Expression with 'std::string' returns:  " << GLE1("Biel "s, "Bueno "s, "T "s) << endl;
	cout << endl;

	cout << "'Functor Class' C++ equivalent of a Generic Polymorphic Lambda..." << endl;
	cout << "Functor Object with 'int' returns:          " << (Class_GLE()(2, 4, 6)) << endl;
	cout << "Functor Object with 'float' returns:        " << (Class_GLE()(3.141592f, 2.718281f, 1.618034f)) << endl;
	cout << "Functor Object with 'std::string' returns:  " << (Class_GLE()("Biel "s, "Bueno "s, "T "s)) << endl;
	cout << endl;

	// 'Generic 'Polymorphic Lambda' with Local Variables initialized on the 'Capture Specifier []'
	int iCounter{ 5 };
	auto GLE2 = [=, &iCounter, Lvar01=3, Lvar02=(9+iCounter)](auto X, auto Y, auto Z) { cout << ((--iCounter)+ Lvar02) << endl;  return ((X + Y + Z)*Lvar01); };   // 'Capture by move'

	cout << "Generic Lambda Expression returns:  " << GLE2(2, 4, 6) << endl;

}

pair<int, string> FindIndex(const vector<string>& vInput, const int& iLength)   // A function that returns a 'std::pair' object
{
	int iIndex{ -1 };   // Iterator's index

	// The 'Result' type is  vector<string>::const_iterator
	auto Result = find_if((cbegin(vInput)), (cend(vInput)),   // Algorithm call that iterates over a vector of strings
		[iLength, &iIndex](const string& Word) { ++iIndex;  return ((Word.size()) == iLength); }   // Lambda Expression [ predicate ] that captures 'iLength' by value and 'iIndex' by reference
	);

	if (Result != (cend(vInput)))   // Checks if the iterator is on the next address after the last element [ not found ]
	{
		// cout << "String found!   Index:  " << iIndex << ", String:  " << (*Result) << ". " << endl;
		return (make_pair(iIndex, *Result));
	}
	else
	{
		// cout << "String not found..." << endl;
		return (make_pair(iIndex, "Not found"s));
	}

}

void M_PairType()
{

	pair<string, string> FullName{ "Douglas"s, "Neiva"s };   // Constructor call of the std::pair

	cout << "First Name:  " << FullName.first << endl;
	cout << "Last  Name:  " << FullName.second << endl;

	auto Profession_01{ make_pair("Electrical"s, "Engineer"s) };   // The pair variable will have its type deduced by the C++ compiler

	// C++17 Class Template Argument Deduction (CTAD)
	// pair Profession_02{ "Game"s, "Developer"s };   // In C++17, the C++ compiler can deduce the variable's types [ avoiding explicitly typing the variable's types ]

	vector<string> sNames{ "Biel"s, "Bueno"s, "Djow"s, "T"s, "Mu"s };   // A new vector of strings with 5 elements
	int iLengthSearch{ 8 };
	pair<int, string> pResult;

	cout << "'FindIndex()' by the length " << iLengthSearch << " returns...  ";
	pResult = (FindIndex(sNames, iLengthSearch));
	cout << "Name:  " << pResult.second << ",   Index:  " << pResult.first << endl;
	cout << endl;

	cout << "The previous 'sNames' vector's size was:  " << (sNames.size()) << endl;

	// The std::vector and the std::string doesn't have the 'push_front()' member functions defined
	// auto  Iterator1 = front_inserter(sNames);   // Calls the 'front_inserter()' function to get the 'front_insert_iterator' of the container [ adds to the beginning ]
	auto  Iterator2 = back_inserter(sNames);    // Calls the 'back_inserter()'  function to get the 'back_insert_iterator'  of the container [ adds to the end ]

	// *Iterator1 = "Stephen"s;    // Assigns a new value [ in this case, a string literal ] to the 'front_insert_iterator'
	*Iterator2 = "Ulibarri"s;   // it calls the 'pushback()' member function of the container, passing the new value as the argument [ sNames.push_back("Ulibarri"s); ]

	cout << "The current  'sNames' vector's size is:   " << (sNames.size()) << endl;

	cout << "'FindIndex()' by the length " << iLengthSearch << " returns...  ";
	pResult = (FindIndex(sNames, iLengthSearch));
	cout << "Name:  " << pResult.second << ",   Index:  " << pResult.first << endl;
	cout << endl;

	cout << "'sNames' previous vector's content: ";
	for (auto Element : sNames)
	{
		cout << Element << "  ";
	}
	cout << endl;

	auto Element3 = (next(next(begin(sNames))));   // Gets the position of the third element of the container
	auto Iterator3 = inserter(sNames, Element3);   // Gets the 'insert_iterator' [ adds at any given position ] of the 'sNames' std::vector container [ of std::strings ]
	*Iterator3 = "Bjarne"s;                        // Adds the new value at the given position [ defined at the 'insert_iterator' initialization ]
	*Iterator3 = "Stroustrup"s;                    // Since the vector has done a memory rearrangement, the insert iterator [ and all iterators before it ] are no longer valid on the vector

	cout << "'sNames' current  vector's content: ";
	for (auto Element : sNames)
	{
		cout << Element << "  ";
	}
	cout << endl;
	cout << "The current  'sNames' vector's size is:   " << (sNames.size()) << endl;

}
void M_InsertIterators()
{
	cout << "Enter some words:   " << endl << endl;

	istream_iterator<string> ISI_1(cin);   // Binding the 'cin' input stream to an 'input stream iterator'
	istream_iterator<string> ISI_2;        // Creating a second empty 'input stream iterator', to be used as 'end-line-character detector'

	vector<string> InputData;                       // Creating an empty vector [ to store the 'cin input stream's' input ]
	auto BackIterator = back_inserter(InputData);   // Getting the 'back_insert_iterator' from the 'InputData' vector using its 'back_inserter()' member function
													// Assigning a value to the 'back_insert_iterator' calls the 'InputData' vector's 'push_back()' function, passing the assigned value as an argument

	// The loop will take each string as a value, separated by spaces or by ENTER; the 'end-line-character' is Ctrl+Z on the Windows Terminal
	while (ISI_1 != ISI_2)   // Starts reading the 'cin' input stream [ bound to the 'ISI_1' ], checking when the input stream reads the 'end-line-character' [ comparing-it to an empty input stream ]
	{
		*BackIterator = *ISI_1;   // Assigns the 'cin' value to the 'InputData' vector [ calling its 'push_back()' member function ]
		++ISI_1;                  // Moves to the next address
	}

	cout << "The " << (InputData.size()) << " words read by the terminal were:   ";
	for (string Word : InputData)   // Ranged for-loop
	{
		cout << Word << ", ";   // Prints each character of the std::vector container
	}
	cout << endl << endl;   // Flushes the output stream
}

// Pseudo-code for the C++ STL 'less' object [ that implements the 'less-than' operator ]
template <typename GenericType>   // Templated variable to be used on the Class [ tha generates Templated Functor Objects ]
class LessThan                    // A Templated Class that implements the 'less-than <' operator
{
public:

	bool operator()(GenericType arg1, GenericType arg2) { return (arg1 < arg2); };   // The 'function-call-operator()' of the 'functor' class, implementing the 'less-than <' operator

};

void M_STLFunctionObjects()
{
	vector<string> sNames{ "Bjarne"s, "Biel"s, "Stephen"s, "Bueno"s, "Ulibarri"s, "Djow"s, "T"s, "Mu"s, "Stroustrup"s };   // A new vector of strings with 5 elements
	int iIndex{ -1 };

	cout << "Vector before sorting..." << endl;
	iIndex = 0;
	for (string Name : sNames)   // Ranged for-loop
	{
		cout << iIndex << "   - " << Name << "\n";   // Prints each character of the std::vector container
		++iIndex;
	}
	cout << endl << endl;   // Flushes the output stream

	// sort((begin(sNames)), (end(sNames)), LessThan<string>());   // Uses the 'LessThan' Custom Templated Class as the 'Function Predicate' for the std::sort algorithm
	sort((begin(sNames)), (end(sNames)), less<string>());   // Uses the 'less' C++ STL as the 'Function Predicate' for the std::sort algorithm

	cout << "Vector after  sorting using 'less'..." << endl;
	iIndex = 0;
	for (string Name : sNames)   // Ranged for-loop
	{
		cout << iIndex << "   - " << Name << "\n";   // Prints each character of the std::vector container
		++iIndex;
	}
	cout << endl;   // Flushes the output stream

	sort((begin(sNames)), (end(sNames)), greater<string>());   // Uses the 'greater' C++ STL as the 'Function Predicate' for the std::sort algorithm

	cout << "Vector after  sorting using 'greater'..." << endl;
	iIndex = 0;
	for (string Name : sNames)   // Ranged for-loop
	{
		cout << iIndex << "   - " << Name << "\n";   // Prints each character of the std::vector container
		++iIndex;
	}
	cout << endl;   // Flushes the output stream


}

void M_SearchingAlgorithms()
{
	string Name{ "DOUGLAS" };   // String to use 'find_first_of()' member function [ case-sensitive ]
	string Vowels{ "AEIOU" };   // Character-by-character evaluation
	cout << "First vowel at index:  " << (Name.find_first_of(Vowels)) << endl;   // Returns a 'size-type' variable-type, using the std::string.find_first_of()

	auto Vowel1 = find_first_of((cbegin(Name)), (cend(Name)), (cbegin(Vowels)), (cend(Vowels)));   // Returns an iterator to the first vowel, using the std::find_first_of [ from <algorithm> ]

	if (Vowel1 != (cend(Name)))
	{
		cout << "The first  vowel on the string is:  " << *Vowel1 << ",  at index:  " << (distance((cbegin(Name)), Vowel1)) << endl;
	}

	// To find the next vowel, pass the string's iterator range starting from the previous search address [ and not from 'cbegin()' ]
	auto Vowel2 = find_first_of((next(Vowel1)), (cend(Name)), (cbegin(Vowels)), (cend(Vowels)));   // Returns an iterator to the second vowel, using the std::find_first_of [ from <algorithm> ]

	if (Vowel2 != (cend(Name)))
	{
		cout << "The second vowel on the string is:  " << *Vowel2 << ",  at index:  " << (distance((cbegin(Name)), Vowel2)) << endl;
	}
	cout << endl << endl;

	string Teachers{ "Stephen Ulibarri and Jamess Raynard" };

	auto Adj1 = adjacent_find((cbegin(Teachers)), (cend(Teachers)));

	if (Adj1 != (cend(Teachers)))
	{
		cout << "Found         2 adjacent elements with value:  " << (*Adj1) << ", at index:  " << (distance((cbegin(Teachers)), Adj1)) << endl;
	}

	auto Adj2 = adjacent_find((next(Adj1)), (cend(Teachers)));

	if (Adj2 != (cend(Teachers)))
	{
		cout << "Found another 2 adjacent elements with value:  " << (*Adj2) << ", at index:  " << (distance((cbegin(Teachers)), Adj2)) << endl;
	}
	cout << endl << endl;

	string MyName{ "James" };
	auto FindMyName = search((cbegin(Teachers)), (cend(Teachers)), (cbegin(MyName)), (cend(MyName)));

	if (FindMyName != (cend(Teachers)))
	{
		cout << "The name " << MyName << " was found at the index:  " << (distance((cbegin(Teachers)), FindMyName)) << ",  with the value:  " << (*FindMyName) << endl;
	}

}
