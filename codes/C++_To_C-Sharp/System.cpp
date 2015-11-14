#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>
#include <exception>

//using namespace fmt;

namespace convert
{
    constexpr size_t DEFAULT_MAX_LENGTH = 128;

    template <typename V> struct backingValue
    {
        static V value;
    };
    template <typename V> V backingValue<V>::value;

    template <typename V, typename... Vcount> struct backingList
    {
        static std::initializer_list<V> list;
    };
    template <typename V, typename... Vcount>
    std::initializer_list<V> backingList<V, Vcount...>::list = {(Vcount)backingValue<V>::value...};

    template <size_t maxLength, typename It, typename V = typename It::value_type, typename... Vcount>
    static typename std::enable_if< sizeof...(Vcount) >= maxLength,
           std::initializer_list<V> >::type generate_n(It begin, It end, It current)
    {
        throw std::length_error("More than maxLength elements in range.");
    }

    template <size_t maxLength = DEFAULT_MAX_LENGTH, typename It, typename V = typename It::value_type, typename... Vcount>
    static typename std::enable_if< sizeof...(Vcount) < maxLength,
           std::initializer_list<V> >::type generate_n(It begin, It end, It current)
    {
        if (current != end)
            return generate_n<maxLength, It, V, V, Vcount...>(begin, end, ++current);

        current = begin;
        for (auto it = backingList<V,Vcount...>::list.begin();
                it != backingList<V,Vcount...>::list.end();
                ++current, ++it)
            *const_cast<V*>(&*it) = *current;

        return backingList<V,Vcount...>::list;
    }
}


template <typename It>
std::initializer_list<typename It::value_type> range_to_initializer_list(It begin, It end)
{
    return convert::generate_n(begin, end, begin);
}


struct String : public std::string
{
    String () : std::string ()
    {}
    String (std::string a) : std::string (a)
    {}
    std::initializer_list <string> Split (std::string sep = " \t\n")
    {
		std::string str = *this;
		std::string curr;
		vector < string > ans;
		for (size_t i = 0 ; i < str.size () ; i ++)
		    if (sep.find (str [i]) != string::npos)
		    {
			ans.push_back (curr); curr = "";
		    }
		    else
			curr += str [i];
		if (curr.size () > 0)
		    ans.push_back (curr);
		return range_to_initializer_list (ans.begin (), ans.end ());
    }
};

std::initializer_list <String> Split (std::string str, std::string sep = " \t\n")
{
    std::string curr;
    vector < String > ans;
    for (size_t i = 0 ; i < str.size () ; i ++)
		if (sep.find (str [i]) != string::npos)
		{
		    ans.push_back (String (curr)); curr = "";
		}
	else
	    curr += str [i];
    if (curr.size () > 0)
		ans.push_back (curr);
    return range_to_initializer_list (ans.begin (), ans.end ());
}

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
	string out;
	getline (cin, out);
	return out;
    }
    catch (std::exception& e)
    {
	throw e;
    }
}

#define run_main \
int main (const int argc, const char* argv [])\
{\
	string args [argc];\
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
#define private private:
#define protected protected:

