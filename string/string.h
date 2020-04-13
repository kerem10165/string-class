#pragma once
#include <iostream>

class String
{
friend std::ostream& operator<<(std::ostream&,const String&);
public:

	String();
	String(const char*);
	String& operator=(const char*);
	int getLenght() const;
	~String();

private:
	int lenght;
	char* string;
};