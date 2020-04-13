#include "string.h"

String::String()
{
	lenght = 1;
	string = new char;
	*string = '\0';
}

String::String(const char* dizi)
{
	lenght = 0;

	if (*dizi == '\0')
	{
		lenght = 0;
	}

	for (int i = 0; dizi[i] != '\0'; ++i)
	{
		lenght = i+2;
	}

	string = new char[lenght];

	for (int i = 0; i < lenght-1; i++)
	{
		string[i] = dizi[i];
	}

	string[lenght-1] = '\0';

}


String& String::operator=(const char* dizi)
{
	int temp_lenght = 0;
	
	for (int i = 0; dizi[i] != '\0' ; ++i)
	{
		temp_lenght = i+2;
	}

	if (temp_lenght != lenght)
	{
		delete[] string;
		lenght = temp_lenght;
		string = new char[lenght];
	}

	for (int i = 0; i < lenght-1; i++)
	{
		string[i] = dizi[i];
	}

	string[lenght - 1] = '\0';

	return *this;
}


int String::getLenght() const
{
	return lenght;
}

String::~String()
{
	delete[] string;
}

std::ostream& operator<<(std::ostream& yazdir,const String& nesne)
{
	yazdir << nesne.string; 

	return yazdir;
}
