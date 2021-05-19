#include "String.h"
#include <stdio.h>
#include <iostream>
using namespace std;
String::String()
{
	length = 0;//���ڿ� ���� ����
	str = NULL;

}
String::String(const char* init, int m)
{
	String(m + 1);
	for (int i = 0; i < m; i++)
		str[i] = init[i];
	str[m] = '\0';
	length = m; 

}
String::~String()
{
	if (str != NULL)
		delete[]str;
}
bool String::operator==( const String& t)
{
	return strcmp(str, t.str) ? false : true;

}
bool String::operator!=( const String& t)
{
	if (t.str== NULL)
		return true;
	else
		return false;
}
int String::Length()
{
	length = strlen(str) + 1;
	return length;

}
int String::Find(const String pat)
{
	
	for (int start = 0; start <= Length() - pat.length; start++)
	{
		int j;
		for (j = 0; j <(pat.length) && str[start + j] == pat.str[j]; j++)
			if (j == pat.length)return start;

	}
	return -1; 
}
String String::Concat(const String &t)
{ 
	String result(this->length + t.length + 1);
	for (int i = 0; i < length; i++)
		result.str[i] = str[i];
	for (int i = 0; i < t.length; i++)
		result.str[length + i] = t.str[i];
	result.str[length + t.length] = '\0';
	result.length = length + t.length;

	return result;
}

