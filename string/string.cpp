#include "string.h"

/*
default consturctor
hiçbir þey almadýðý zaman 1 uzunlukta null karakter atayarak baþlar
*/
String::String()
{
	lenght = 1;
	string = new char;
	*string = '\0';
}

/*
eðer null karakter alýrsa, nullptr veya null alýrsa;

uzunluðu 1 yapýp yeni karakter oluþturup null karkater atar

eðer gelen karakter nullptr veya null deðilse yeni bir string oluþturur 

*/
String::String(const char* dizi)
{
	if (dizi == nullptr)
	{
		lenght = 1;
		string = new char;
		*string = '\0';
	}

	else if (*dizi == '\0')
	{
		lenght = 1;
		string = new char;
		*string = '\0';
	}

	else
	{
		//sonuna null karakter koyabilmek için lenght = i+2 yaptým (dizi = "k" olursa string uzunluk = 2 olur)
		for (int i = 0; dizi[i] != '\0'; ++i)
		{
			lenght = i + 2;
		}

		string = new char[lenght];

		for (int i = 0; i < lenght - 1; i++)
		{
			string[i] = dizi[i];
		}
	
		//son elemana null karakter atadýk
		string[lenght - 1] = '\0';
	}
}


String::String(const char a)
{
	lenght = 2;
	string = new char[2];
	string[0] = a;
	string[1] = '\0';
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

String& String::operator=(const char a)
{
	delete[] string;
	string = new char[2];
	string[0] = a;
	string[1] = '\0';

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

//enter tuþu sonlandýrýr ctrl z iþe yaramaz
std::istream& operator>>(std::istream& al, String& nesne)
{
	delete[] nesne.string;
	
	//sürekli kopyalama yapmamasý için belli bir boyuttan baþlattým
	nesne.string = new char[20];
	int lenght = 0;

	int maxlenght = 20;


	for (int i = 0; i < maxlenght; i++)
	{
		//tek tek karakter okuyoruz
		al.get(nesne.string[i]);
		//okuduðumuz karakterleri 
		nesne.lenght = ++lenght;
		
		//eðer enter tuþuna basýlýrsa döngüden çýkar ve son karaktere null atar
		if (nesne.string[i] == (char)10)
		{
			nesne.string[i] = '\0';
			break;
		}

		//eðer kullanýcý hala enter girmediyse boyutu 10 arttýrýp devam ediyoruz
		if (i == maxlenght - 1)
		{
			char* temp = new char[maxlenght + 10];
			memcpy(temp, nesne.string, maxlenght);
			delete[] nesne.string;
			nesne.string = new char[maxlenght + 10];
			maxlenght += 10;
			memcpy(nesne.string, temp, maxlenght);
			delete[] temp;
		}
	}

	return al;
}
