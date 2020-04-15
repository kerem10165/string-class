#pragma once
#include <iostream>

class String
{
friend std::ostream& operator<<(std::ostream&,const String&);
friend std::istream& operator>>(std::istream&, String&);
public:

	//default constructor
	String();
	
	//ilk deðer constructoru (metin alýr)
	String(const char*);

	//ilk deðer constructoru (karkater alýr)
	String(const char);
	
	//kopyalama constructoru
	String(String&);
	
	//= operatörü ile gelen metini eþitleme
	String& operator=(const char*);
	
	//= operatörü þle gelen karakteri eþitliyor
	String& operator=(const char);
	
	//uzunluk dönderiyor
	int getLenght() const;
	
	//yýkýcý constuctor
	~String();

private:
	int lenght;
	char* string;
};