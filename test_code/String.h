#pragma once
#include <iostream>
#include<stdio.h>

using namespace std;
class String
{
	
private:
		char* str;
		int length;

		int size;

		String(int m);
		
public:
	String();
	~String();
	String(const char* init, int m);
	String Concat(const String& t);
	int Length();
	int Find(const String pat);
	String Substr(int i, int j);
	

	bool operator==( const String& t);
	bool operator!= (const String& t);
	
	
};

