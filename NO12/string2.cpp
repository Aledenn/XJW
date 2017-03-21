// string1.cpp -- String class methods

#include <cstring>                 // string.h for some
#include<string.h>
#include <cctype>
#include "string2.h"        // includes <iostream>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char * s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    strcpy_s(str,len+1, s);           // initialize pointer
    num_strings++;                 // set object count
}

String::String()                   // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                 // default string
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char [len + 1];  // allot space
    strcpy_s(str, len+1,st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    --num_strings;                    // required
    delete [] str;                    // required
}




// overloaded operator methods    

    // assign a String to a String
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
   strcpy_s(str, len+1,st.str);
    return *this;
}

    // assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    strcpy_s(str,len+1, s);
    return *this;
}

String  operator+(const String &s1, const String &st)
{
	String sum;
	sum.len = s1.len + st.len;
	int s = sum.len + 1;
	sum.str = new char[s];
	strcpy_s(sum.str,s, s1.str);
	strcat_s(sum.str,s,st.str);
	return sum;
}

String operator+(const char * s1, const String & st)//（1）使用引用当作函数参数和返回值，效率更高。
                                                    //（2）函数返回的对象引用，必须在调用函数前就已经存在，不允许返回局部变量的引用！
                                                    //（3）当不希望返回的对象被修改的时候，可以添加const。
{
	String sum;
	sum.len = strlen(s1) + st.len;
	int s = sum.len + 1;
	sum.str = new char[s];	
	strcpy_s(sum.str, s, s1);
	strcat_s(sum.str, s,st.str);
	return sum;
}

String operator+(const String & st, const char * s1)//todo;
{
	String sum;
	sum.len = strlen(s1) + st.len;
	int s = sum.len + 1;
	sum.str = new char[s];
	strcpy_s(sum.str, s, st.str);
	strcat_s(sum.str, s, s1);
	return sum;
}

    // read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}

    // read-only char access for const String
const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}



    // simple String output
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os; 
}

    // quick and dirty String input
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is; 
}

     //to lower
void String::Stringlow()//todu
{
	for (int i = 0; i < len;i++)
	str[i]=tolower(str[i]);
}

void String::Stringup()
{
	for (int i = 0; i < len; i++)
	str[i] = toupper(str[i]);
}

int String::Many(const char &a)
{
	int i = 0;
	int num = 0;
	while (i < len)
	{
		if (a != '/0')
			if (str[i] == a)
				num++;
		i++;
	}
	return num;
}
