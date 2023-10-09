
// Douglas Neiva - Learning Notes - Programming Language - Modern C++
// ====================================================================================================
// >>>  Source file (.cpp) - C++ Code  ================================================================


#include "Modern_CPP.h"

using namespace std;

#include <iostream>
#include <string>



// Function declarations [compiler-aware]
// ====================================================================================================

void M_Initialization();
void M_Pointers();



// Standard "main" function - C++
// ====================================================================================================
int main()
// int M_Practice_XX_main()
{
	cout << "Welcome! " << endl;
	cout << endl;
// ====================================================================================================
// Section 01 - Runs only once, before the loop                                                     1 V

	M_Pointers();

// Section 01 - END                                                                                 1 A
// ====================================================================================================
	for (;;)
	{
		cout << endl;
// ====================================================================================================
// Section 02 - Loop                                                                                2 V



// Section 02 - END                                                                                 2 A
// ====================================================================================================
		cout << "Loop executed! " << endl;
		system("pause");
		// break;
	}
// ====================================================================================================
// Section 03 - Runs only once, after the loop                                                      3 V



// Section 03 - END                                                                                 3 A
// ====================================================================================================
	cout << "Loop ended! " << endl;
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
