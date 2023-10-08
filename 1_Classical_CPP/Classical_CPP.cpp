
// Douglas Neiva - Learning Notes - Programming Language - Classical C++
// ====================================================================================================
// >>>  Source file (.cpp) - C++ Code  ================================================================


#include <iostream>

using namespace std;

// ====================================================================================================
// int main()

int Practice_XX_main ()
{
	cout << endl;
// ====================================================================================================


// ====================================================================================================
	for (;;)
	{
		cout << endl;
// ====================================================================================================


// ====================================================================================================
		cout << "Hello World!" << endl << endl;
		system("pause");
	}
	return 0;
}


// ====================================================================================================
// >>> Practice_01


#include <iostream>
#include <string>

using namespace std;

void Goodbye();  // Only forward declaration [above "int main()"], needs to be implemented [below "int main()"]
                 // Forward declaration is a technique to declare an identifier before before it is defined; and its useful
                 // to save compile time, since it informs the compiler about a class, function, or variable before it is used in code.

void Welcome()  // Both declaration and implementation (or definition) [above "int main()"]
{
	cout << "Welcome! " << endl;

	int i = 3;

	cout << "Post-increment! " << i++ << endl;
	cout << "Incremented! " << i << endl;


	int y = 3;

	cout << "Pre-decrement! " << --y << endl;
	cout << "Decremented! " << y << endl;

	float z = 7;
	z /= 3;
	cout << z << endl;
}

char UserInput();

int A = 2;

void PassByValue(int Num);
void PassByReference(int& Num);

// int main()
int Practice_01_1_main()
{
	for (;;)
	{
		char UserChar;

		float f1 = 0.010F;
		float f2 = 1.990F;

		while (f2 > f1)
		{
			cout << f1 << "   ";
			f1 += 0.01F;
		}

		Welcome();



		UserChar = UserInput();

		if (UserChar != 'Y')
		{
			cout << "Exiting... \n";
			break;
		}
		else
		{
			cout << "Great choice! \n";

			PassByValue(A);
			PassByReference(A);
		}

		Goodbye();

		// MyFunction2(); // This is a function from another file (Source.cpp)


		system("pause");

	}

	double NumberPi = 3.141592;
	double NumberE = 2.718281;

	int Counter = 0;   // Variable declaration
	int& Ref_Counter = Counter;   // Ref declaration, passing the variable as an argument (both "Counter" and "Red_Counter" points to the same memory location)
								  // This statement means: the reference "Ref_Counter" becomes an alias (pseudonym) for "Counter"
							      // References holds the same memory address than the original variable with its value stored

	bool bCondition = true;

	do {

		cout << "The number pi is: " << NumberPi << endl;
		cout << "The number e is: " << NumberE << endl;

		cout << "Pre-incrementing the 'Counter' variable: " << ++Counter << endl;

		if (Counter <= 100)
		{
			bCondition = true;
		}
		else
		{
			bCondition = false;
		}

	} while (bCondition);

	int k = 1;

	for (;(k <= 10); k++)
	{
		cout << k << endl;

		for (int j = 1; j <= 20; j++)
		{
			cout << k << " and " << j << endl;
		}
	}

	return 0;

}

void Goodbye()  // Only implementation (or definition) [below "int main()"], needs to be declared [above "int main()"]
{
	cout << "Thanks! Goodbye! \n";
}

char UserInput()
{
	char Answer;
	cout << "Do you want more? \n Yes[Y]/No[N] \n";
	cin >> Answer;  // The "cin" statement automatically waits for the user input, and doesn't need the "system("pause")" statement

	return Answer;

}

void PassByValue(int Num)  // "Num" (local variable) is a copy of "A" (global variable), and won't change it
{
	cout << "Value: " << Num << endl;
	Num += 2;
	cout << "Num: " << Num << "     A: " << A << endl;
}

void PassByReference(int& Num)  // "Num" (local variable) is the memory address of "A" (global variable), and will change it
{  // "int&" is a Reference variable, "&" is the Reference Sign
	cout << "Reference: " << Num << endl;
	Num += 3;
	cout << "Num: " << Num << "     A: " << A << endl;
}


// Function practicing 02

void ChangeStr(string& str);

void PrintValue(int var);   // Function overloading: the same function name, 3 overloads (different argument datatypes and input numbers)
void PrintValue(float var);
void PrintValue(string var1, char [5]);

const float pi = 3.141592F;
const int ConstChar = 'X';

// int main()
int Practice_01_2_main()
{
	for (;;)
	{
		
		string myStr = "Neiva";
		string& Ref_myStr = myStr;   // Ref_myStr is the alias of myStr

		cout << myStr << endl;
		cout << Ref_myStr << endl;

		Ref_myStr += " Douglas";   // Strings can be concatenated using the + operator

		cout << myStr << endl;
		cout << Ref_myStr << endl;

		cout << endl;

		ChangeStr(myStr);

		cout << myStr << endl;

		int iVar = 3;
		float fVar = 3.14F;
		string sVar = "Unreal";
		char cVar = 'N';

		PrintValue(iVar);
		// PrintValue(sVar, cVar);
		PrintValue(fVar);
		

		char ArrayOfChars[5] = { 'D','j','o','w','\0' };
		string MyName = "Douglas";
		MyName += 78;

		char cASCII = '<';

		cout << ArrayOfChars << endl;
		cout << ++cASCII << endl;
		cout << MyName << endl;

		PrintValue("Hello", ArrayOfChars);

		



		cout << "Loading..." << endl;

		system ("pause");
	}
}



void ChangeStr(string& str)   // The function's argument string& can receive both string (variable) and string& (ref) datatypes,
{                             // but not literals (like the contant string "Douglas")
	str += " changed!";
}

void PrintValue(int var)
{
	cout << "Overloaded 1.0 : " << var << endl;
}

void PrintValue(float var)
{
	cout << "Overloaded 2.0 : " << var << endl;
}

void PrintValue(string var1, char[5])
{
	cout << "Overloaded 3.1 : " << var1 << endl;
	// cout << "Overloaded 3.2 : " << var2 << endl;
}


// ====================================================================================================
// >>> Practice_02


#include <cstdlib>
#include <iostream>
#include <iomanip>

#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

// int main()
int Practice_02_main()
{
	// ====================================================================================================

	int myIntArray[3];
	myIntArray[0] = 3;
	myIntArray[1] = 5;
	myIntArray[2] = 7;

	float Notations[] = { {3.1415920f},{2.7182810f},{1.6180340f},{100.0000000f} };

	unsigned int uInt = 2U;
	long int lInt = 5L;

	int RandomValues[10];
	srand((time(NULL))*1.123);

	enum PlayerStatus {   // Defining the enum "PlayerStatus" (it's like creating a constant variable of type "PlayerStatus")
		PS_Crouched,   // implicitly equals 0
		PS_Standing,   // implicitly equals 1
		PS_Wallking,   // implicitly equals 2
		PS_Sprinting   // implicitly equals 3
	};

	enum PlayerData {
		PD_MaxHealth = 100,   // explicitly equals 100
		PD_MaxStamina = 10,   // explicitly equals 10
		PD_MaxWeapons = 2,   // explicitly equals 2
	};

	enum GameState {GS_Paused, GS_Playing};

	enum ErrorList {
		EL_401 = 401,   // explicitly equals 401
		EL_402,   // implicitly equals 402 (previous + 1)
		EL_403,   // implicitly equals 403 (previous + 1)
		EL_404,   // implicitly equals 404 (previous + 1)
		EL_802 = 802,   // explicitly equals 802
		EL_803,   // implicitly equals 803 (previous + 1)
		EL_804   // implicitly equals 804 (previous + 1)
	};


	struct Character {   // Defining a custom datatype "Character" (is not an object, is just an outline or blueprint)
		string Name = " ";
		float Health = 0.0F;
		int Level = 0;
		float Damage = 0.0F;

		int GetLevel()
		{
			return Level;   // The best practice to acess struct members is by calling fucntions (unlike "Character.Level" direct access)
			cout << "Level member accessed!" << endl;
		}

		void Attack()
		{
			cout << Name << " does " << Damage << " damage!" << endl;
		}
	};


	// ====================================================================================================

	for (;;)
	{
		// ====================================================================================================

		for (int i = 0; i <= 2; i++)
		{
			// cout << fixed << showpoint;
			// cout << setprecision(15);
			cout << myIntArray[i] << endl;
			cout << Notations[i] << endl;
		}
		
		for (int i = 0; i < 10; i++)
		{
			RandomValues[i] = (rand() % 100+1);
			cout << RandomValues[i] << endl;
		}

		cout << endl;
		cout << endl;

		PlayerStatus Player_01_Stats;
		Player_01_Stats = PlayerStatus::PS_Wallking;

		switch (Player_01_Stats)
		{
		case PS_Crouched:
			cout << Player_01_Stats << endl;
			break;
		case PS_Wallking:
			cout << Player_01_Stats << endl;
			break;
		case PS_Standing:
			cout << Player_01_Stats << endl;
			break;
		case PS_Sprinting:
			cout << Player_01_Stats << endl;
			break;
		default:
			cout << "Default condition" << endl;
		}

		ErrorList GameErrors;
		GameErrors = ErrorList::EL_802;

		cout << GameErrors << endl << endl;


		Character Djow;   // Creating a "Character" object (Declaring a custom datatype "Character"), instantiating an object
		Djow.Name = "Douglas";   // Initializing one element a custom datatype "Character"
		Djow.Health = 100.0F;
		Djow.Level = 52;
		Djow.Damage = 85.450F;
		Djow.Attack();

		Character Mu = { "Lucas", 250.F, 38, 61.280F };   // Initializing the entire instance of a custom datatype "Character"
		Mu.Attack();   // Calling the "Attack" function from the "Mu" object
		cout << "This character's level is: " << Mu.GetLevel() << endl;
		



		// ====================================================================================================

		// cout << "Hello Word!" << endl;
		cout << endl;
		system("pause");

	}
}


// ====================================================================================================
// >>> Practice_03


#include <iostream>
using namespace std;

int MyFunction1(int Param_one, int Param_two)
{
	int local_variable;
	local_variable = Param_one + Param_two;
	cout << "The local variable is: " << local_variable << " !" << endl;
	return local_variable;
}

void MyFunction2()
{
	cout << "Void functions doesn't need the 'return' statement! \n";
	// return;
	
	// When the last line of code of this function (that have a 'void' return-type) is executed,
	// the next expression to be executed will be on the caller, no matter if there is an explicit "return" statement...
	
	// When the return type of the function is "void", the "return" statement is not necessary (it will be implicit),
	// since the generated Assembly code is the same for implicit and explicit "return" statements.
}

void MyFunction3()
{
	cout << "Welcome! \n";
}

// int main()
int Practice_03_main()
{
	for (;;)
	{
		// ====================================================================================================


		char myCharacter;
		myCharacter = 'Y';

		int myInteger;
		myInteger = 13;

		std::string myString;
		myString = "hello";

		// std::cout << "You Died! \n";  (line 2)
		cout << myCharacter << "\n" << myInteger << endl;

		myCharacter = 'n';
		myInteger = 24;

		cout << myString << endl;

		if (5 != 4)
		{
			cout << "The 'if' Statement is true!" << endl;
		}
		else if (5 !=5)
		{
			cout << "The 'if' Statement if false!" << endl;
		}
		else
		{
			cout << "Third condition was achieved!" << endl;
		}

		MyFunction1(myInteger, 5);
		MyFunction3();
		MyFunction2();


		// ====================================================================================================
		system("pause");
	}
}


// ====================================================================================================
// >>> Practice_04


#include <iostream>
#include <string>

using namespace std;


struct Docker {   // Struct definition, all struct members are public by default
public:
	// Docker();
	string Name;
	int X;
	void sToBeQualified();

	// private:
	int Y;
	int Z;
	void StructMethod()
	{
		cout << "Struct method called! \n";
	}
};

class Kubernetes {   // Class definition, all class properties are private by default
public:
	Kubernetes();   // Class "constructor" function, called as soon as a new instance is created

	string Name;
	int X;
	void cToBeQualified();

	// private:
	int Y;
	int Z;
	void ClassMethod()
	{
		cout << "Class method called! \n";
	}
};

// int main()
int Practice_04_main()
{
	// ====================================================================================================

	int MyInt = 3;   // Memory allocation on the hardware for an integer (4 bytes * 8 bits = 32 bits allocated)
	int& REF_MyInt = MyInt;   // Declaration and initialization of the variable datatye "REF to int" (named as "REF_MyInt"),
							  // passing the variable name "MyInt" as the value for the "REF_MyInt" REF

	int* My_Ptr;   // Declaring a variable type "pointer to int" (named "My_Ptr")
	My_Ptr = &MyInt;   // Assigning the address of the variable "MyInt" (prefix "&" modifier) as the value for the "My_Ptr" pointer to int

	int Your_Int = *My_Ptr;

	char Full_Name[] = { 'D','O','U','G','L','A','S' };
	char* ptr_Full_Name = Full_Name;   // On arrays, the "address of: &" operator is not necessary (since arrays are contiguous memory blocks)



	// ====================================================================================================
	for (;;)
	{
		// ====================================================================================================

		cout << "REFs! " << endl;   //REF datatype
		cout << MyInt << endl;   // Prints the number 3 using the original variable name (passing by value)
		cout << REF_MyInt << endl;   // Prints the number 3 using the REF variable that references the original variable (passing by reference)
		// cout << endl;

		cout << "Pointers! " << endl;   // Pointer datatype
		cout << &MyInt << endl;   // Prints the memory address of the variable "MyInt" allocated on the hardware
		cout << My_Ptr << endl;   // Prints the memory address pointed by the pointer variable
		cout << *My_Ptr << endl;   // Prints the value stored on the memory address pointed by the pointer variable (the number 3)
								   // The operation of accessing the content of a pointer is called "dereferencing"
		// cout << endl;

		cout << "Tests! " << endl;
		cout << &REF_MyInt << endl;   // The REF address is the same address of the refered variable (doesn't take extra memory)
		cout << &My_Ptr << endl;   // The Pointer address is different from the pointed address (requires extra memory to store the address value)
		// cout << endl;

		cout << Your_Int << endl;
		cout << *ptr_Full_Name << endl;

		for (int i = 0; i <= 6; i++)   // Prints each element of the variable "Full_Name" (array of chars, contiguous memory)
		{
			ptr_Full_Name = Full_Name;

			ptr_Full_Name += i;   // Pointer arithmetic
			cout << *ptr_Full_Name;

		}
		cout << endl << endl;


		Docker Container = { "Magic", 3, 4, 5 };
		Docker* ptr_Container = &Container;

		cout << (*ptr_Container).X << endl;   // Pointers can be used with structs to acccess its members
		cout << ptr_Container->Z << endl;   // Both "dereferencing" + "dot operator" (default method to access struct members by using pointers); 
										 // or "arrow operator" ("syntactic sugar", will be translated to default); can be used with pointers
		cout << endl;

		Kubernetes Cluster;
		// Cluster.ClassMethod();
		cout << Cluster.Name << ", " << Cluster.X << ", " << Cluster.Y << ", " << Cluster.Z << ", " << endl;
		Cluster.Name = "Ubuntu";
		Cluster.X = 12;
		cout << Cluster.Name << ", " << Cluster.X << ", " << Cluster.Y << ", " << Cluster.Z << ", " << endl;

		// ====================================================================================================

		cout << endl << "Hello World!" << endl;
		system("pause");
	}
}

Kubernetes::Kubernetes()
{
	ClassMethod();
	Name = "Default name";
	X = 8;
	Y = 7;
	Z = 5;
}

void Docker::sToBeQualified()
{
	cout << "Fully qualified function definition outside of the struct body! \n";
}

void Kubernetes::cToBeQualified()
{
	cout << "Fully qualified function definition outside of the class body! \n";
}


// ====================================================================================================
// >>> Practice_05


#include <iostream>

using namespace std;

// Object-oriented programming: class inheritance
// Parent class (C++ base class) and child class (C++ derived class)
/* Class inheritance code (using the ":" operator)

class <Derived_Class> : public <Base_Class>
{
	...
};

*/

class Arachnid {   // Definition of a parent class "Arachnid"

public:   // Public section of a class, where the "public:" keyword is an access modifier
	Arachnid();   // "Constructor" function of the parent class (function without return type, with the same name as the class name)
	Arachnid(string message);
	string Name;   // Public property
	int Eyes;   // Public property
	void Attack(float& AttackDamage);   // Public method declaration, to be defined outside of the class scope

private:   // Private section of a class, where the "private:" keyword is an access modifier
	string EnemyID;   // Private property
	void ArachnidPrivateMethod();   // Private method declaration, to be defined outside of the class scope
};

// "::" is the "scope resolution operator", and finds properties and methods on scopes of classes and structs
Arachnid::Arachnid()   // Full-qualified constructor function definition of a parent class, outside of its class scope
{
	Name = "New Arachnid";
	Eyes = 4;

	EnemyID = "0xFBA";   // Assigning a value to a private property of the parent class from its constructor function
	cout << "A new Arachnid was created! \n";
}

void Arachnid::Attack(float& AttackDamage)   // Full-qualified public method definition of a parent class, outside of its class scope
{
	cout << "Arachnid attacking with " << AttackDamage << " of damage!!!" << endl;
}

void Arachnid::ArachnidPrivateMethod()   // Full-qualified private method definition of a parent class, outside of its class scope
{
	cout << "Accessing private method of the 'Arachnid' class!" << endl;
}


// Declaration of an "is a" relationship (the "Spider" child class will have "Arachnid" as a parent; "Spider" also is an "Arachnid")
class Spider : public Arachnid {   // Definition of a child class "Spider", with "Arachnid" as a parent 
								  // ("Spider" inherits all "Arachnid" properties and methods, it's derived from the parent class)
public:   // Even if all properties and methods are public on the base class, the derived class will be private by default
	Spider();   // "Constructor" function of the child class (function without return type, with the same name as the class name)
	Spider(string name, int eyes, float damage);   // The constructor function also can be overloaded!
	float PoisonDamage;
};

Spider::Spider()   // Full-qualified "constructor function" definition of a child class, outside of its class scope
{
	Name = "Black Widow";   // Initializing properties of the parent class
	Eyes = 8;

	PoisonDamage = 32.4F;   // Initializing properties of the child class
	cout << "A new " + Name + " spider was created! \n";

	float& ref_PoisonDamage = PoisonDamage;   // Declaring a "REF" variable "pointer to float" and assigning a float variable to it
	Arachnid::Attack(ref_PoisonDamage);   // Calling a method of the parent class from the child class with a child property
	cout << endl;
};

// Constructor functions can also be called as initializer lists, as shown below (using the ":" operator)
/*
Spider::Spider(string name, int eyes, float damage) :
	Name(name), Eyes(eyes), PoisonDamage(damage){}
*/

Spider::Spider(string name, int eyes, float damage)   // Full-qualified overloaded (different signature) "constructor function" definition
{
	Name = name;
	Eyes = eyes;
	PoisonDamage = damage;

	cout << "The overloaded constructor function was called! \n";
	cout << "Properties changed: " << endl;
	cout << "- " << Name << endl;
	cout << "- " << Eyes << endl;
	cout << "- " << PoisonDamage << endl;
	cout << endl;
}


class Scorpion : public Arachnid
{   // By default, even if the class "Scorpion" have the constructor function defined, the constructor function of the parent class will be called;
	// and even if the parent class have multiple overloads of the constructor function, the default one (without inputs or outpus) will be called
public:
	
	Scorpion() {
		Name = "Scorpion";   // Only the constructor can have access to the variables on the base class
		cout << "A scorpion was born! \n" << endl;
		// On the constructor function, other overloads of the base class constructor function could be called!
	}
	// Name = "Scorpion";   // Outside the constructor, the child class won't have access to the properties of the base class
};

class Mite : public Arachnid   // In this case, the "public" keyword won't change access levels of any parent class variables and functions
	// If the expression was "class Mite : protected Arachnid", all public variables and functions of the "Arachnid" class will be protected
	// If the expression was "class Mite : private Arachnid", all public and protected variables and functions of the "Arachnid" class will be private

{   // All the scope of any class is private by default
public:   // "public:" access modifier: accessible from outside the class scope (can be used by any statement at any line of code)
	Mite()
	{
		Name = "Mite";
		LegLength = 5;
		BiteLength = 8;
		// EnemyID = "0xAAF0";
	}
	Mite(string message);
protected:   // "protected:" access modifier: not accessible from outside the class scope, but accessible by derived classes
	int LegLength;
private:   // "private:" access modifier: not accessible from outside the class scope (can only be used within the class and its functions)
	int BiteLength;
};

Arachnid::Arachnid(string message)
{
	Eyes = 3;
	cout << "Avoided the parent constructor default function!" << endl;
	cout << "Message: " << message << " from the parent class..." << endl;
}

// How to avoid calling the default parent class constructor function: using the overload constructor function of the child class
// as initializer list (both overload contructor functions of parent and child classes must have the same signature)
Mite::Mite(string message) : Arachnid("Parent! ") {   // The function of the parent class will be executed first!
	cout << "Message: " << message << " from the child class..." << endl;
}

// To call the second overload of the child class and also call the first overload of the parent class
// just define the constructor function (without being an initializer list)
/*
Mite::Mite(string message)
{
	Name = "Mite!";
	cout << "A new " << Name << " was created!" << endl;
	cout << "The message is: " << message << endl;
}
*/

class Hobo : public Spider   // Multiple inheritance ("Hobo" decends from "Spider", that decends from "Arachnid"; "Hobo" is an "Arachnid")
{
public:
	Hobo()
	{
		Name = "Hobo Spider";
		cout << "A new " + Name + " spider was created! \n";
	}

};


int Practice_05_main()
// int main()
{
	cout << endl;
	// ====================================================================================================

	Arachnid NewArachnid;   // Instancing a new "Arachnid" object (and implicitly calling the contructor function of the "Arachnid" class)
	float NewArachnidDamage = 43.9F;
	float& ref_NewArachnidDamage = NewArachnidDamage;
	NewArachnid.Attack(ref_NewArachnidDamage);
	cout << endl;

	Spider Spider_01;   // Instancing a new "Spider" object, calling the first overload of the constructor function (without inputs)
	// Spider_01.Spider("Brown", 14, 93.6F);   // The constructor function (or all its overloads) is called only once when a new
											   // object is created (and cannot be called after instancing the object)

	Spider Spider_02("Wolf", 12, 65.7F);   // Instancing a new "Spider" object, calling the second overload of the constructor function
	
	cout << NewArachnid.Name << endl;
	cout << Spider_01.Name << endl;
	cout << Spider_02.Name << endl;
	cout << endl;

	Scorpion Scorpion_01;

	// Mite Mite_01;
	Mite Mite_01("Child! ");
	cout << endl;

	Hobo Spider_03;   // The inheritance chain will be executed from top (root parent) to bottom (latest child)
	Spider_03.Eyes = 20;
	Spider_03.PoisonDamage = 71.4F;
	cout << Spider_03.Eyes << endl;
	float& ref_HoboDamage = Spider_03.PoisonDamage;
	Spider_03.Attack(ref_HoboDamage);


	// ====================================================================================================
	for (;;)
	{
		cout << endl;
		// ====================================================================================================



		// ====================================================================================================

		cout << "Hello World!" << endl << endl;
		system("pause");
	}
}


// ====================================================================================================
// >>> Practice_06


#include <iostream>

using namespace std;

// Object-oriented programming: access modifiers
// When a class has protected and private variables (properties) that could be changed,
// the class should have public "getters" and "setters" functions (methods), using a technique called "encapsulation"
// Encapsulation always should be used (best practice), instead of direct acessing class variables by making them public (bad practice)

class Creature
{

public:
	Creature();   // If the default class constructor function was declared as private, it could never be instanciated
	// int getter();   // "getter" default function
	// void setter(int& value);   // "setter" default function

	string getName();
	void setName(string name);

	int getProtected();
	void setProtected(int value);

	int getPrivate();
	void setPrivate(int value);

	void Report();


public:
	int iC_Public;

protected:
	int iC_Protected;
	char cC_Protected;

private:
	int iC_Private;

	string Name;

};

Creature::Creature()
{
	Name = " ";
	iC_Public = 0;
	iC_Protected = 0;
	iC_Private = 0;
	cC_Protected = 'C';
	cout << "A new Creature was created!" << endl;
}

string Creature::getName()
{
	cout << "getName function called! Name got: " << Name << endl;
	return Name;
}

void Creature::setName(string name)
{
	cout << "setName function called! Name set: " << name << endl;
	Name = name;
}

int Creature::getProtected()
{
	cout << "iC_Protected returned! The value is: " << iC_Protected << endl;
	return iC_Protected;
}

void Creature::setProtected(int value)
{
	cout << "The old value of iC_Protected was: " << iC_Protected << endl;
	iC_Protected = value;
	cout << "The new value of iC_Protected is: " << iC_Protected << endl;
}

int Creature::getPrivate()
{
	cout << "iC_Private returned! The value is: " << iC_Private << endl;
	return iC_Private;
}

void Creature::setPrivate(int value)
{
	cout << "The old value of iC_Private was: " << iC_Private << endl;
	iC_Private = value;
	cout << "The new value of iC_Private is: " << iC_Private << endl;
}

void Creature::Report()
{
	cout << endl << "Creature name: " << Name;
	cout << ".  Key values are: " << endl << "- Public: " << iC_Public << endl << "- Protected: " << iC_Protected  << " and " << cC_Protected << endl << "- Private: " << iC_Private << endl;
}



class Player : public Creature
{
public:
	Player();   // The constructor function must be public! Otherwise, it will not possible to instantiate new objects of this class

	int getHealth();
	void setHealth(int health);

	void setType(char type);

	void TakeDamage(int damage);


protected:


private:

	int Health;

};

Player::Player()
{
	cC_Protected = 'P';
	Health = 100;
	cout << "A new Player was created!" << endl;
}

int Player::getHealth()
{
	cout << "getHealth function called! Health got: " << Health << endl;
	return Health;
}

void Player::setHealth(int health)
{
	cout << "setHealth function called! Health set: " << health << endl;
	Health = health;
}

void Player::setType(char type)
{
	cout << "setType function called! Type set: " << type << endl;
	cC_Protected = type;
}

void Player::TakeDamage(int damage)
{
	int buffer_Health = getHealth();
	buffer_Health -= damage;
	cout << "Health buffer with the value of: " << buffer_Health << endl;

	if (buffer_Health <= 0)
	{
		setHealth(0);
		cout << "The Player " << getName() << " was killed!  Respawning... \n";
		setHealth(100);
		cout << endl;
	}
	else
	{
		setHealth(buffer_Health);
		cout << "Damage taken: " << damage << ".  Player " << getName() << " health: " << getHealth() << endl;
		cout << endl;
	}
}


// ====================================================================================================
// int main()
int Practice_06_main()
{
	cout << endl;
	// ====================================================================================================

	Creature Igor;
	Igor.setName("Igor");
	Igor.Report();
	cout << endl;

	Igor.iC_Public = 1;
	Igor.setProtected(5);
	Igor.setPrivate(7);
	Igor.Report();
	cout << endl;

	cout << (Igor.getProtected()) << endl;
	cout << (Igor.getPrivate()) << endl;
	cout << endl << endl;;

	Player Douglas;
	Douglas.setName("Douglas");
	Douglas.Report();
	cout << endl;

	Douglas.TakeDamage(54);
	/*
	Douglas.TakeDamage(38);
	Douglas.TakeDamage(25);
	Douglas.TakeDamage(10);
	Douglas.TakeDamage(512);
	*/
	Douglas.setPrivate(5);   // It's possible to set the "iC_Private" variable (from "Creature" class, unaccessible)
							 // by using the public "setter" function defined on the "Creature" class
	Douglas.setType('X');   // It's possible to set the "cC_Protected" variable (from "Creature" class, acessible to childs)
							// by using the public "setter" function defined on the "Player" class
	Douglas.Report();
	cout << endl;



	// ====================================================================================================
	for (;;)
	{
		cout << endl;
		// ====================================================================================================



		// ====================================================================================================
		cout << "Hello World!" << endl << endl;
		system("pause");
	}
}


// ====================================================================================================
// >>> Practice_07


#include <iostream>

using namespace std;

// Memory management: variables created at compile time (automatically managed) and at the runtime (manually managed)
// Ctrl+Shift+X = Visual Studio Class Wizard

struct Character
{
public:
	Character();   // Explicit declaration of the "Constructor" default function (otherwise, it will be implicitly created by default)
	~Character();   // Explicit declaration of the "Destructor" default function
	string Name;
	string Type;
	float Health;

	string getName();   // Struct (class) encapsulation: "getter" function
	void setName(string name);   // Struct (class) encapsulation: "setter" function

	int* Age;

	static void ReportCharacters();   // Since static functions exists outside of the class scope, it must be public to be accessible

	virtual void SetType();   // This "virtual" function can be overwritten by child classes with the same function name [don't confuse
							  // overwriting (same function names, with "virtual" keyword on the base class, to be overwritten by child classes) with
							  // overloading (same function names, different input signatures and definitions for each function)

protected:
	int iC_Protected;

	static int CharacterCount;   // By default, all "static" variables will be initialized with 0; and this line of code will be run only once,
								 // since "static" variables cannot be declared twice; and must be initialized outside of the class (like any other variable)

private:
	int iC_Private;
};

int Character::CharacterCount = 0;   // "Static" variables must be initialized outside of the class's body (and also outside of class's functions)

Character::Character()   // Constructor functions are used to initialize class's variables with default values when the object is created
{
	// As the same as Classes, struct datatypes also have a "constructor" function by default (even if it was not written on the code)
	// When the constructor function is called on object's dynamically allocation (by the "new" keyword), it dynamically allocates memory
	// for the object's variables (that should be deleted when the object is destroyed)
	Name = "Default name";
	Type = "Default type";
	Health = 100.0F;
	iC_Protected = 2;
	iC_Private = 5;
	cout << "A new Character was created!" << endl;

	Age = new int(3);   // Dynamically allocation (on the heap) of a new "int" variable, initializing it with the value "3" and assigning
						// its address (returned by the "new" keyword) to the "pointer to int" object's variable (on the stack)

	CharacterCount += 1;
	cout << "Character Count: " << CharacterCount << ". \n" << endl;

}

Character::~Character()   // Destructor functions are used to clean memory when the object is destroyed (and is called with the "delete" keyword)
{
	// When dynamically allocated objects are deleted from the heap memory, the destructor function is called, and must delete all
	// object's variables (delcared on the class scope, and both dynamically allocated and initialized on the constructor function)
	Health = 0.0F;
	cout << "The character was destroyed!" << endl;

	delete Age;   // Dynamically deallocation (deleting from the heap) the "int" variable (created on the constructor function)

	CharacterCount -= 1;
	cout << "Character Count: " << CharacterCount << ". \n" << endl;

}

string Character::getName()   // Fully-qualifying the name of the function by the "::" scope operator
{
	cout << "getName function was called" << endl;
	return Name;
}

void Character::setName(string name)
{
	cout << "setName function was called" << endl;
	Name = name;
}

void Character::ReportCharacters()
{
	cout << "Number of characters alive: " << CharacterCount << ". \n" << endl;
}

void Character::SetType()
{
	Type = "Character";
	cout << "Char: The " << Name << " is a " << Type << ". \n" << endl;
}

void StaticVariable()
{
	static int Counter01 = 0;
	int Counter02 = 0;
	Counter01++ && Counter02++;
	cout << "Counter01:  " << Counter01 << ".   Counter02:  " << Counter02 << ". \n" << endl;
}

class Ally : public Character
{
public:

	// void SetType();   // Works the same way as the expression below
	virtual void SetType() override;  // Since the "SetType()" function is marked as "virtual", all child functions
									  // could also have "virtual" and "override" keywords for documentation reasons (but isn't required)

	
};

void Ally::SetType()
{
	Type = "Player";
	cout << "Ally: The " << Name << " is a " << Type << ". \n" << endl;

	// Character::SetType();   // Parent functions overwritten can also be called!
}

// ====================================================================================================
int Practice_07_main()
{
	for (;;)
	{
		// Character Player01;   // This expression will create a new "Character" variable (struct-type) named "Player01",
								 // and the variable "Player01" will be stored on the stack data-sctructre memory at the compile time
								 // The variable "Player01" is a struct "Character" variable, and contains all its properties

		// Character* ptr_Player02 = new Character();   // This expression will create a new "pointer to Character" variable (pointer-type)
														// named "ptr_Player02", and the variable "ptr_Player02" will be stored
														// on the stack data-sctructre memory at the compile time
														// This expression also will create a new "Character" variable (struct-type)
														// without a name, and this variable will be stored on the heap data-sctructre memory
														// at the runtime (by the keyword "new"), and its address will be pointed by
														// the "ptr_Player02" "pointer to Character" variable (that contains the address)
														// The variable "ptr_Player02" (created and stored on the stack memory) is a pointer
														// "pointer to Character" variable, and contains the address of the struct-type
														// "Character" variable (without a name) created and stored on the heap memory
		
		// Every variable statically created at the compile time will be stored on the stack memory (static memory),
		// and it will be automatically managed (created and deleted)
		
		// Every variable dynamically created at the runtime (by the keyword "new") will be stored on the heap memory (dynamic memory),
		// and must be manually managed (created by the keyword "new", and deleted by the keyword "delete" when is no longer needed)

		Character Player01;
		Character* ptr_Player02 = new Character;

		cout << Player01.getName() << endl;   // Dot operator, used by variables
		cout << ptr_Player02->getName() << endl;   // Arrow operator, used by pointers
		cout << endl;

		Character* ptr_Player04 = new Character;

		delete ptr_Player02;
		cout << endl;

		Player01.setName("Player 01");
		// ptr_Player02->setName("Player 02");   // The object dynamically allocated on the heap memory was deleted on line 79!
		cout << endl;

		cout << Player01.getName() << endl;
		// cout << ptr_Player02->getName() << endl;   // The object dynamically allocated on the heap memory was deleted on line 79!
		cout << endl;

		Character* ptr_Player03 = new Character;   // Declaring a new variable "pointer to character", dynamically allocating a new "Character"
												   // object on the heap memory, and assigning the object to the pointer (on dynamic allocation,
												   // the "addres of [&]" operator isn't needed before the variable created on the heap, because
												   // the "new" keyword returns a pointer to the address of the "Character" object on the heap)
												   // When a new "Character" object is created, the "Character()" constructor function is called
		ptr_Player03->getName();
		ptr_Player03->setName("Suicide Player");
		delete ptr_Player03;   // When a new "Character" object is deleted, the "~Character()" destructor function is called
							   // The "delete" keyword deletes the class itself, but won't delete its member variables and functions
							   // (that's why a "destructor" function must be created, to delete variables within the deleted object)

		cout << endl;
		for (int i = 0; i < 10; i++)
		{
			StaticVariable();
		}
		
		// Counter01 = 5;   // Since the "Counter01" static variable was declared within "StaticVariable" function, it cannot be accessed
							// outside of its function's scope (unlike global variables; but both "global" and "static" variables persists
							// on memory during the program lifecycle (but "static" public variables within classes can be accessed outside
							// of the class scope!)

		delete ptr_Player04;

		{   // This scope will automatically manage memory for local variables, but won't delete static or dynamically allocated variables

			Character Player05;   // This "Character" variable (named Player05) will be deleted at the end of scope (on line 165)
			static Character Player06;   // This "Character" static variable (named Player06) won't be deleted at the end of scope (on line 165)

			// "Static" variables and functions have their own space on memory, isolated from local variables (stack) and dynamic variables (heap)
		}

		// Player06.SetType();   // Static variables aren't accessible outside of its scope

		Player01.SetType();
		Ally Djow;
		Djow.SetType();

		Character::ReportCharacters();

		Character* ChildPlayer;   // "pointer to Character" variable (Character is the base class [or superclass])

		ChildPlayer = new Ally;   // Pointer polymorphism (due to "is a" [or "type of"] relationship), where any subclass (child class)
								  // can be assigned to a pointer that points to a superclass (useful to multiple pointers of same datatype)
								  // Pointer polymorphism also works with overriding and overloading, calling the right method of the assgined class
		delete ChildPlayer;

		ChildPlayer = new Ally;   // The previous object (dynamically allocated on teh heap) was deleted from the "heap" dynamic memory,
								  // but the "pointer to Character" variable remains on the "stack" static memory
		delete ChildPlayer;


		ptr_Player02 = new Character;   // Dynamically allocating a new "Character" object (base class) to the "pointer to Character" variable
		ChildPlayer = new Ally;   // Dynamically allocating a new "Ally" object (sub class) to the "pointer to Ally" variable
		Character* ptr_array_Characters[] = { ptr_Player02, ChildPlayer };   // Polymorphism allows an array of "pointer to base class"
																			 // to store "pointer to subclass" variables
		
		for (int i = 0; i < 2; i++)   // Due to poly                                                                                          morphism, the "virtual void" function will be called according to the object override
		{
			cout << i << endl;
			ptr_array_Characters[i]->SetType();
		}
		
		delete ptr_Player02;
		delete ChildPlayer;


		// ====================================================================================================
		cout << "Dangerous ways! \n" << endl;
		system("pause");
		break;
	}

	Character::ReportCharacters();   // Since static variables and functions persists on memory (and exists outside of any scope),
									 // class's static functions can be called even if any object wasn't created
	return 0;
}


int Practice_07_main_2()
{
	cout << endl;
	// ====================================================================================================



	// ====================================================================================================
	for (;;)
	{
		cout << endl;
		// ====================================================================================================

		int* ptr_Int = new int;   // Declaring a new pointer "ptr_Int" and initializing it with a "new int" variable allocated on the "heap" memory data structure
		*ptr_Int = 3;   // Assigning the value "3" to the "new int" variable created (and pointed) at the "heap" memory, by dereferencing the pointer "ptr_Int"
		// At this time, the pointer "ptr_Int" (allocated on the stack) points to the address of the variable "new int" (allocated on the heap)
		
		// Since the variable "new int" was dynamically allocated on the heap, it must be deallocated as soon as the variable is no longer needed
		// unlike common variables (automatically deleted at the end of the scope), dynamically allocated memory won't be deleted automatically
		
		// delete ptr_Int;   // This line of code must be used to deallocate the allocated memory on the heap (before overwriting the pointer)


		ptr_Int = new int(15);   // The "new int" statement:  (assigned to the pointer [pointers stores addresses])
								 // allocates memory on the heap, creates a new "int variable" and returns the address of the variable created
		// At this time, the pointer "ptr_Int" no longer points to the previous "int" on heap (with the value "3"), it was overwritten,
		// and now points to the "int" on heap with the value "15" (but both previous and current "int"s still on the heap memory

		// When the pointer "ptr_Int" was overwrite, the previous "int" created on the heap memory is no longer accessible anymore,
		// (because its address is unknown), but stays allocated (and unavailable), causing a "memory leak" (multiple memory leaks crashes the program)

		delete ptr_Int;   // This statement doesn't delete the pointer "ptr_Int"; but only deallocate the memory address stored on the pointer
						  // (that points to the memory allocated on the "heap" data structure)
		// At this time, the pointer "ptr_Int" no longer have a valid address to point at (and is called a "dangling pointer",
		// a pointer that points to deallocated memory), and dereferencing it will return garbage data (and needs to be re-assigned)

		ptr_Int = nullptr;   // To avoid getting garbage data when pointers are dereferenced, assign the "nullptr" value (points to nothing)


		// ====================================================================================================
		cout << "Dangerous ways! \n" << endl;
		system("pause");
	}
	return 0;
}


// ====================================================================================================
// >>> Practice_08


#include <iostream>

using namespace std;

// Multiple inheritance, Virtual inheritance and casting
// Diamond inheritance must be avoided (a sub-class derived from 2 sub-classes that derives from the same base-class, causing errors)
// by using Virtual inheritance

// "Casting" is the process of explicitly converting one type of data into another type. Datatype conversions can be:
// - Implicit type conversion:  float fValue = 6.32F;  int iValue = fValue;
// - Explicit type conversion:  float fValue = 6.32F;  int iValue = (int)(fValue); (C-style casting, without checks at the runtime)

// C++ "Dynamic cast" is used on a derivation chain and only works on polymorphic types (at least one virtual member function), and can be:
// - Upcast: convert a sub-class (child) data type into a base-class (parent) datatype, leveling-up the hierarchy level of inheritance
// - Downcast: convert a base-class (parent) data type into a sub-class (child) datatype, leveling-down the hierarchy level of inheritance
// - Crosscast: convert one class data type into another class data type, without changing the hierarchy level of inheritance
// The C++ dynamic_cast function returns the new data type when succeeds, and returns NULL when fails
// Thanks to inheritance, upcast isn't needed for class objects (due the "is a" [or "type of"] relationship: a sub-class "is a" base-class)

// - C++ "Static cast" casts a pointer from one type to another at the compile type, without runtime checks (RTTI - Run Time Type Information),
//   and can be used with non-polymorphic types on a derivation chain (similar to C-style casting), but can cause errors (dynamic cast is secure)

// Multiple inheritance without Virtual inheritance, where diamond inheritance can cause errors and
// takes more memory [ copying parent's variables (properties) and functions (methods) ]

class A   // Base-class 'A'
{
public:
	void F1();   // Public method 'F1' from base-class 'A'
	virtual void Casting1();   // Polymorphic member that can be overwritten
};

void A::F1()   // Definition of the public method 'F1' from base-class 'A'
{
	cout << "'F1' function from base-class 'A' called!\n" << endl;
}

void A::Casting1()
{
	cout << " The 'Casting' function base-class 'A' was called!\n" << endl;
}

class B   // Base-class 'B'
{
public:
	void F2();   // Public method 'F2' from base-class 'B'
};

void B::F2()   // Definition of the public method 'F2' from base-class 'B'
{
	cout << "'F2' function from base-class 'B' called! \n" << endl;
}

class C : public A   // Sub-class 'C' derived from base-class 'A'
{   // The sub-class 'C' will inherit the method 'F1' from the base-class 'A'

};

class D : public B   // Sub-class 'D' derived from base-class 'B'
{   // The sub-class 'D' will inherit the method 'F2' from the base-class 'B'

};

class E : public A, public B   // Sub-class 'E' derived from both base-class 'A' and base-class 'B', multiple inheritance
{   // The sub-class 'E' will inherit the method 'F1' from the base-class 'A' and the method 'F2' from the base-class 'B'

};

class F : public C, public D   // Sub-class 'F' derived from both sub-class 'C' and sub-class 'D', multiple inheritance
{   // The sub-class 'F' will inherit the method 'F1' from the sub-class 'C' and the method 'F2' from the sub-class 'D',
	// because:
	// > the sub-class 'C' inherits the method 'F1' from the base-class 'A' and
	// > the sub-class 'D' inherits the method 'F2' from the base-class 'B'
	// and won't cause any errors

};

class G : public E, public F   // Sub-class 'G' derived from both sub-class 'E' and sub-class 'F', "diamond inheritance" problem
{   // The sub-class 'G' will inherit:
	// > the method 'F1' and the method 'F2' from the sub-class 'E' (that inherits
	//   the method 'F1' from the base-class 'A' and the method 'F2' from the base-class 'B')
	// > the method 'F1' and the method 'F2' from the sub-class 'F' (that inherits
	//   the method 'F1' from the sub-class 'C' and the method 'F2' from the sub-class 'D')
	// causing ambiguity errors (and taking twice the amount of memory)

};


// Multiple inheritance with Virtual inheritance, where diamond problem is solved and
// takes less memory [ without copying parent's variables (properties) and functions (methods) ]

class H : virtual public A   // Sub-class 'H' virtually derived from base-class 'A'
{
public:

	void HF()
	{
		cout << "H function called, hierarchy level 2.\n\n";
	}
};

class I : virtual public A, virtual public B   // Sub-class 'I' virtually derived from both base-class 'A' and base-class 'B'
{
public:

	void IF()
	{
		cout << "I function called, hierarchy level 2.\n\n";
	}
};

class J : virtual public H, virtual public I   // Sub-class 'J' virtually derived from both sub-class 'H' and sub-class 'I'
{
public:

	void JF()
	{
		cout << "J function called, hierarchy level 3.\n\n";
	}
};

class K : virtual public H, virtual public I, virtual public J   // Diamond inheritance
{

};

class L : virtual public J, virtual public K   // Diamond inheritance
{

};


// ====================================================================================================
// int main()
int Practice_08_main()
{
	for(;;){
	cout << endl;
	// ====================================================================================================

	// Implicit type conversion
	float myFloat1 = 5.13F;
	int myInt1 = 2;
	myInt1 = myFloat1;   // Implicit conversion of "float" value to "int" value, deleting all the decimal numbers
	cout << "myInt1 value is: " << myInt1 << endl;

	// Explicit type conversion
	float myFloat2 = 7.94F;
	int myInt2 = 3;
	myInt2 = (int)(myFloat2);   // Explicit conversion of "float" value to "int" value (C-style)
	cout << "myInt2 value is: " << myInt2 << endl;

	// C++ dynamic casting
	A* ptr_A;   // Uninitialized "pointer to Base-class 'A'"
	H* ptr_H;   // Uninitialized "pointer to Sub-class 'H'" (derived from base-class 'A')
	I* ptr_I;   // Uninitialized "pointer to Sub-class 'I'" (derived from base-class 'A')
	cout << endl;
	L* ptr_L = new L;   // Initialized "pointer to Sub-class 'L'" (from virtual diamond inheritance)
	// At this point, all the 4 pointers created are completely different data types

	// Since virtual inheritance is being used, diamond inheritance will no longer cause errors
	ptr_L->F1();
	ptr_L->F2();

	// Upcasting: casting-up the derivation chain
	ptr_A = dynamic_cast<A*>(ptr_L);   // Converting the value of "pointer to Sub-class 'L'" variable to
									   // "pointer to Base-class 'A'" data type, and assigning it to the variable "pointer to Base-class 'A'"
	ptr_A = ptr_L;   // Thanks to inheritance, the "is a" "child-to-parent" relationship could replace upcasting on class objects
					 // (base-class pointers can be used with sub-class objects)

	// Downcasting: casting-down the derivation chain
	ptr_H = dynamic_cast<H*>(ptr_A);   // Converting the value of "pointer to Base-class 'A'" variable to
									   // "pointer to Sub-class 'H'" data type, and assigning it to the variable "pointer to Sub-class 'H'"
	// ptr_H = ptr_A;   // Sub-class pointers cannot be used with base-class objects,
						// since the "is a" relationship is only valid for "child-to-parent", and can't replace downcasting

	// Cross-casting: changing data type on the same hierarchy level
	ptr_I = dynamic_cast<I*>(ptr_H);   // Converting the value of "pointer to Sub-class 'H'" variable to
									   // "pointer to Sub-class 'I'" data type, and assigning it to the variable "pointer to Sub-class 'I'"
	ptr_H = dynamic_cast<H*>(ptr_I);   // Converting the value of "pointer to Sub-class 'I'" variable to
									   // "pointer to Sub-class 'H'" data type, and assigning it to the variable "pointer to Sub-class 'H'"


	delete ptr_L;
	// ====================================================================================================
	cout << "Hello World!" << endl << endl;
	system("pause");
	break;
	}

	// ====================================================================================================
	for (;;)
	{

		cout << endl;
		// ====================================================================================================

		cout << "Calling 'object1' of base-class 'A'" << endl;
		A object1;
		object1.F1();
		cout << endl;

		cout << "Calling 'object2' of base-class 'B'" << endl;
		B object2;
		object2.F2();
		cout << endl;

		cout << "Calling 'object3' of sub-class 'C'" << endl;
		C object3;
		object3.F1();
		cout << endl;

		cout << "Calling 'object4' of sub-class 'D'" << endl;
		D object4;
		object4.F2();
		cout << endl;

		cout << "Calling 'object5' of sub-class 'E' (multiple inheritance from 'A' and 'B', without the 'virtual' keyword)" << endl;
		E object5;
		object5.F1();
		object5.F2();
		cout << endl;

		cout << "Calling 'object6' of sub-class 'F' (multiple inheritance from 'C' and 'D', without the 'virtual' keyword)" << endl;
		F object6;
		object6.F1();
		object6.F2();
		cout << endl;

		cout << "Calling 'object7' of sub-class 'G' (diamond inheritance from 'E' and 'F', without the 'virtual' keyword)" << endl;
		G object7;
		// object7.F1();   // Error: the function 'G::F1()' is ambiguous (both 'F1 from E' and 'F1 from F' could be accessed)
		// object7.F2();   // Error: the function 'G::F2()' is ambiguous (both 'F2 from E' and 'F2 from F' could be accessed)

		object7.E::F1();   // The 'G::F1()' function can be called from 'E' by fully qualifying it [ G::E::F1() ]
		object7.F::F1();   // The 'G::F1()' function can be called from 'F' by fully qualifying it [ G::F::F1() ]

		object7.E::F2();   // The 'G::F2()' function can be called from 'E' by fully qualifying it [ G::E::F2() ]
		object7.F::F2();   // The 'G::F2()' function can be called from 'F' by fully qualifying it [ G::F::F2() ]

		cout << endl;

		cout << "Calling 'object8' of sub-class 'L' (diamond inheritance from 'E' and 'F', with the 'virtual' keyword)" << endl;
		L object8;
		object8.F1();   // The Virtual inheritance takes care of the "diamond" problem, without creating a copy of parent's attributes
		object8.F2();   // Using the 'virtual' keyword when creating derived classes avoids errors on multiple inheritance

		// ====================================================================================================

		cout << "Hello World!" << endl << endl;
		system("pause");
		break;
	}
	for (;;)
	{
		// Casting
		cout << endl;

		A Aobject;   // object of Hierarchy level 1
		H Hobject;   // object of Hierarchy level 2
		I Iobject;   // object of Hierarchy level 2
		J Jobject;   // object of Hierarchy level 3

		A* ptr_to_A = &Aobject;   // pointer to Hierarchy level 1
		H* ptr_to_H = &Hobject;   // pointer to Hierarchy level 2
		I* ptr_to_I = &Iobject;   // pointer to Hierarchy level 2
		J* ptr_to_J = &Jobject;   // pointer to Hierarchy level 3

		A* BaseArray[] = { ptr_to_A, ptr_to_H, ptr_to_I, ptr_to_J };   // Even if the array was declared with data type "A" (base-class),
																	   // the array also can hold sub-class data types (due to the "is a" relationship)

		for (int i = 0; i < 4; i++)
		{
			cout << "Iteration step " << i << endl;

			A* Aobj = BaseArray[i];   // Working with temporary variables is more efficient and secure than working with the original variables
			
			H* Hobj = dynamic_cast<H*>(Aobj);   // Downcasting, returning NULL if the 'Aobj' doesn't point to an 'H*' data type ('H' object)
			I* Iobj = dynamic_cast<I*>(Aobj);   // Downcasting, returning NULL if the 'Aobj' doesn't point to an 'I*' data type ('I' object)
			J* Jobj = dynamic_cast<J*>(Aobj);   // Downcasting, returning NULL if the 'Aobj' doesn't point to an 'J*' data type ('J' object)

			if (Hobj != NULL)   // Testing if the "dynamic_cast" expression doesn't return NULL (a pointer that points to zero)
			{
				Hobj->HF();   // If the casting expression returns a pointer that points to a 'H' object, its function will be called
			}
			if (Iobj != NULL)
			{
				Iobj->IF();   // If the casting expression returns a pointer that points to a 'I' object, its function will be called
			}
			if (Jobj != NULL)
			{
				Jobj->JF();   // If the casting expression returns a pointer that points to a 'J' object, its function will be called
			}
		}

		// ====================================================================================================
		cout << "Hello World!" << endl << endl;
		system("pause");
		break;
	}
	return 0;

}


// ====================================================================================================
// >>> Practice_09


#include "CPP.h"

#include <string>
using namespace std;

#include <iostream>


int Practice_09::ClassCount = 0;

Practice_09::Practice_09()
{
	ClassType = "Practice_09";
	static int ClassCount = 0;
	ClassCount++;
	cout << "A new base-class object was created! \n" << endl;
}

Practice_09::~Practice_09()
{
	cout << "The base-class object was deleted! \n" << endl;
}

void Practice_09::ClassReport()
{
	cout << "Total number of objects alive: " << ClassCount << ". \n" << endl;
}

void Practice_09::ClassFunction()
{
	cout << "The base-class function was called! \n" << endl;
}



// ====================================================================================================
int main()
// int Practice_09_main()
{
	cout << endl;
	// ====================================================================================================

	Practice_09 Object01;


	// ====================================================================================================
	for (;;)
	{
		cout << endl;
		// ====================================================================================================



		// ====================================================================================================
		cout << "Hello World!" << endl << endl;
		system("pause");
	}
	return 0;
}
