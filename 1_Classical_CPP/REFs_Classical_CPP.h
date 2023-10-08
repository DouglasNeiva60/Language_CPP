#pragma once


// Douglas Neiva - Learning Notes - Programming Language - Classical C++
// ====================================================================================================
// >>>  Header file (.h) - C++ References  ============================================================
/*

   >>> Introduction

#pragma once   avoids calling the header file multiple times, including its content only once at the compile time / runtime
			   the "preprocessor" runs the code before it gets compiled, and "preprocessor directives" are used prefixed by "#"

The Main_Source_File.cpp [that contains the "int main () {}" function] is the entry point of any C++ program, and no other file
can have another "int main () {}" function [otherwise, the C++ program no longer compiles]

The "#include" preprocessor includes header files (implementation-defined and programmer-defined manners) on the C++ project, that can be:
- #include <filename> : include header file by searching it on directories pre-designated by the compiler / IDE (standard library, implementation-defined)
- #include "filename" : include header file by searching it on the same directory as the source file is (by using the relative path;
						but absolute paths also can be used to include header files from other directories, programmer-defined)

When a header file (.h) is included on the given source file (.cpp), the process is the same as copying all the header file's code (.h)
and pasting it on the source file (.cpp) at the line where the header file was included.
Including a header file (.h) also will include its source file pair (.cpp), because header files #includes its source code and
everything inside in the source file (definitions) is delcared in the header file (declarations)

Ex.: Character.h and Character.cpp will be called by the #include "Character.h" statement because Character.h already calls Character.cpp

Header files (.h) are used to write all C++ code declarations (variables, classes and function names); and
Source files (.cpp) are used to write all C++ code definitions (variables, classes and function bodies).
All the C++ code functionality (function definitions and variable initializations) must be written on the Source file (.cpp)
(source files extends the functionality of header files; ".h" and ".cpp" are used together on large C++ projects)

When a class, function or variable is declared on the Source file (Character.cpp) instead of being declared on the Header file (Character.h),
other source file (World.cpp) with the #include "Character.h" statement won't recognize the declaration statement made on the Character.cpp
[since the Character.h file calls the Character.cpp file, everything inside the Character.cpp file must be declared on the Character.h file]


// ====================================================================================================
*/
