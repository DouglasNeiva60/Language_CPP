
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
void M_NameSpaces_OutOfScope_01();
void M_NameSpaces_OutOfScope_02();
void M_FunctionPointers();
void M_BasicStringOperations();
void M_SearchingStrings();
void M_AddingStringElements();
void M_RemovingStringElements();
void M_StringNumberConversion();
void M_MiscStringOperations();
void M_CharacterFunctions();
void M_CompareStrings();
void M_SimpleAddMultiply();
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




// Standard "main" function - C++
// ====================================================================================================
int main()
// int M_Practice_XX_main()
{
	cout << endl << "Welcome to Modern_CPP.cpp!  Created by Douglas Neiva " << endl << endl;
// ====================================================================================================
// Section 01 - Runs only once, before the loop                                                     1 V

	M_BinaryFileBitmap();


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

	void CreateFile();

	void WritePixels();

protected:

private:

	int iWidth{ 800 };
	int iHeight{ 600 };
	std::string sFileName{""s};
	std::vector <Bitmap_Pixel> vPixels;   // A vector variable to store image data

	ofstream NewBitmapFile;
	Bitmap_FileHeader NewFileHeader;
	Bitmap_InfoHeader NewInfoHeader;
};

Bitmap_ImageData::Bitmap_ImageData()   // Default constructor function
{

}

Bitmap_ImageData::~Bitmap_ImageData()   // Default destructor function
{
	NewBitmapFile.close();
	NewBitmapFile.close();
}

void Bitmap_ImageData::SetFileName(const string &sNewFileName)
{
	if (sNewFileName != "")
	{
		sFileName = sNewFileName;
	}
	else
	{
		cout << "Please specify a valid file-name!" << endl;
	}
}

void Bitmap_ImageData::CreateFile()
{
	if (sFileName != "")
	{
		NewBitmapFile.open(sFileName, fstream::out);
		
		NewBitmapFile.write(reinterpret_cast<char*>(&NewFileHeader), sizeof(Bitmap_FileHeader));

		NewBitmapFile.write(reinterpret_cast<char*>(&NewInfoHeader), sizeof(Bitmap_InfoHeader));

		NewBitmapFile.write(reinterpret_cast<char*>(&vPixels), ((vPixels.size()) * sizeof(Bitmap_Pixel)));
	}
	else
	{
		cout << "Please specify the name of the file!" << endl;
	}
}

void Bitmap_ImageData::WritePixels()
{
	if (sFileName != "")
	{

	}
	else
	{
		cout << "Please specify the name of the file!" << endl;
	}
}

void M_BinaryFileBitmap()
{
	// The image to be drawn will be 'C++' written on a Bitmap file, using 4 variables:
	// 'x_unit' = the thickness on the X axis
	// 'y_unit' = the thickness on the Y axis
	// 'x_mid' = the center of the image at the X axis
	// 'y_mid' = the center of the image at the Y axis

	Bitmap_ImageData NewBitmap;

}