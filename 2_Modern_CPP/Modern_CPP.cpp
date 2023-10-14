
// Douglas Neiva - Learning Notes - Programming Language - Modern C++
// ====================================================================================================
// >>>  Source file (.cpp) - C++ Code  ================================================================


#include "Modern_CPP.h"          // 1 - Header files

#include <iostream>              // 2 - Libraries
#include <string>

using namespace std;
using namespace std::literals;   // 3 - Namespaces



// Function declarations [compiler-aware]
// ====================================================================================================

void M_Initialization();
void M_Pointers();
void M_IntSizes();
void M_StringLiterals();
void M_Casting();



// Standard "main" function - C++
// ====================================================================================================
int main()
// int M_Practice_XX_main()
{
	cout << endl << "Welcome to Modern_CPP.cpp! " << endl << endl;
// ====================================================================================================
// Section 01 - Runs only once, before the loop                                                     1 V

	M_Casting();


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
