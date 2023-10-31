
// Douglas Neiva - Learning Notes - Programming Language - Modern C++
// ====================================================================================================
// >>>  Source file (.cpp) - C++ Code  ================================================================


#include "Modern_CPP.h"          // 1 - Header files

#include <iostream>              // 2 - Libraries
#include <fstream>
#include <string>
#include <vector>

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
void M_UnbufferedStream();




// Standard "main" function - C++
// ====================================================================================================
int main()
// int M_Practice_XX_main()
{
	cout << endl << "Welcome to Modern_CPP.cpp!  Created by Douglas Neiva " << endl << endl;
// ====================================================================================================
// Section 01 - Runs only once, before the loop                                                     1 V

	M_UnbufferedStream();



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

void M_UnbufferedStream()
{
	cout << "Enter some text..." << endl << endl;

	char cUnbufferedData{ 'X' };

	while (cin.get(cUnbufferedData))   // Using the 'get()' member function of the input stream 
									   // The 'get()' will return TRUE until it reads 'end-of-input' character
									   // Remember that the 'data packet' will be valid when the input stream reads the 'new-line' character  [ line-oriented input ]
	{
		cout.put(cUnbufferedData);   // Using the 'put()' member function of the output stream
	}   // The 'Ctrl+Z' (Windows 'end-of-input' character)  will end the 'while-loop' by returning FALSE

}