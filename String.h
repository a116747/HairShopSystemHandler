#pragma once
#ifndef __STRING_H_
#define __STRING_H_
#include "CommonThings.h"
#include <iostream>
#include <cstring>
using namespace std;
class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);
	String(const String& s);
	~String();
	String& operator= (const String& s);
	String& operator+= (const String& s);
	bool operator== (const String& s);
	String operator+ (const String& s);

	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};
ostream& operator<< (ostream& os, const String& s);
istream& operator>> (istream& is, String& s);
#endif