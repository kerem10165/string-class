#pragma once
#include <iostream>

class String
{
friend std::ostream& operator<<(std::ostream&,const String&);
friend std::istream& operator>>(std::istream&, String&);
public:

	//default constructor
	String();
	
	//ilk de�er constructoru (metin al�r)
	String(const char*);

	//ilk de�er constructoru (karkater al�r)
	String(const char);
	
	//kopyalama constructoru
	String(String&);
	
	//= operat�r� ile gelen metini e�itleme
	String& operator=(const char*);
	
	//= operat�r� �le gelen karakteri e�itliyor
	String& operator=(const char);
	
	//uzunluk d�nderiyor
	int getLenght() const;
	
	//y�k�c� constuctor
	~String();

private:
	int lenght;
	char* string;
};