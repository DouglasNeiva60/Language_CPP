#pragma once


// Douglas Neiva - Learning Notes - Programming Language - Classical C++
// ====================================================================================================
// >>>  Header file (.h) - C++ Code  ==================================================================


#pragma once

#include <string>
using namespace std;

class Practice_09
{
public:
	Practice_09();
	~Practice_09();

	void ClassReport();

protected:
	virtual void ClassFunction();
	static int ClassCount;

private:
	string ClassType;
};
