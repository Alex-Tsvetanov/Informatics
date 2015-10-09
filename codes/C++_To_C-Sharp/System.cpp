#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdarg.h>
#include "cppformat/format.cc"
#include <exception>

using namespace fmt;

using String = std::string;

std::logic_error NotImplementedException ()
{
	return std::logic_error ("Function not yet implemented.");
}

char ConsoleReadKey ()
{
	try
	{
		throw NotImplementedException ();
		return cin.get ();
	}
	catch (std::exception& e)
	{
		throw e;
	}
}
char ConsoleRead ()
{
	try
	{
		char out;
		cin >> out;
		return out;
	}
	catch (std::exception& e)
	{
		throw e;
	}
}
String ConsoleReadLine ()
{
	try
	{
		String out;
		getline (cin, out);
		return out;
	}
	catch (std::exception& e)
	{
		throw e;
	}
}

#define ConsoleWrite print
#define ConsoleWriteLine println

#define run_main \
int main (const int argc, const char* argv [])\
{\
	String args [argc];\
	try\
	{\
		for (int i = 0 ; i < argc ; i ++)\
			args [i] = string (argv [i]);\
	}\
	catch (...)\
	{\
		throw exception (runtime_error("Bad parameters"));\
	}\
	try\
	{\
		Project::Program::Main (args);\
	}\
	catch (const exception& e)\
	{\
		throw e;\
	}\
}

#define public public:
