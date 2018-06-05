#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using std::string;

class Student
{
protected:
	string imie;
	string nazwisko;
	int semestr;
	string numerIndeksu;

public:
	/*Student(string imie, string nazwisko, int semestr, string numerIndeksu)
	{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->semestr = semestr;
	this->numerIndeksu = numerIndeksu;
	}*/

	friend std::ostream& operator << (std::ostream& out, Student & s);

	friend std::istream& operator >> (std::istream& in, Student & s);

	string getImie()
	{
		return imie;
	}

	void setImie(string imie)
	{
		this->imie = imie;
	}

};

class StudentInformatyki : public Student
{
private:
	bool znaCpp;
public:

	/*StudentInformatyki(string imie, string nazwisko, int semestr, string numerIndeksu, bool znaCpp) :
	Student(imie, nazwisko, semestr, numerIndeksu)
	{
	this->znaCpp = znaCpp;
	}*/

	bool isZnaCpp()
	{
		return znaCpp;
	}


	void setZnaCpp(bool znaCpp)
	{
		this->znaCpp = znaCpp;
	}

	friend std::ostream& operator << (std::ostream& out, StudentInformatyki & s)
	{
		Student a = s;
		out << a;
	    if (s.znaCpp) /*out << "Zna C++";*/ out << "1";
		else /*<< "Dopiero uczy sie w C++";*/ out << "0";
		out << std::endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, StudentInformatyki & s)
	{
		in >> s.imie;
		in >> s.nazwisko;
		in >> s.semestr;
		in >> s.numerIndeksu;
		in >> s.znaCpp;
		return in;
	}

	void modyfikujNumerIndeksu()
	{
		if (numerIndeksu[0] != 'I') numerIndeksu = 'I' + numerIndeksu;
	}
};

std::istream& operator >> (std::istream& in, Student & s)
{
	in >> s.imie;
	in >> s.nazwisko;
	in >> s.semestr;
	in >> s.numerIndeksu;
	return in;
}
/*std::ostream& operator << (std::ostream& out, Student & s)
{
	out << "Dane studenta: " << std::endl;
	out << "Imie: " << s.imie << std::endl;
	out << "Naziwsko: " << s.nazwisko << std::endl;
	out << "Semestr: " << s.semestr << std::endl;
	out << "Numer indeksu: " << s.numerIndeksu << std::endl;
	return out;
}*/

std::ostream& operator << (std::ostream& out, Student & s)
{
	out << s.imie << " " << s.nazwisko << " " << s.semestr << " " << s.numerIndeksu << " ";
	return out;
}

int main()
{
	/*StudentInformatyki s1("Franek", "Kowalski", 2, "123456", 1);
	std::cout << s1 << std::endl << std::endl;
	s1.setZnaCpp(0);
	std::cout << s1 << std::endl << std::endl;
	s1.modyfikujNumerIndeksu();
	std::cout << s1;*/


	/*ZAD1
	std::cout << "Podaj dane studenta w kolejnosci(imie,nazwisko,semestr,nrIndeksu)" << std::endl;
	Student s1;
	std::cin >> s1;
	std::cout << s1;
	*/

	/*ZAD2
	StudentInformatyki s1;
	char NazwaPliku[] = "studinf.txt";
	std::ifstream plik;
	plik.open(NazwaPliku);

	if (!plik)
	std::cerr << "Nie mozna otworzyc pliku";
	else
	{
	int temp = 0;
	while (plik >> s1)
	{
	if (s1.isZnaCpp() == 1) temp++;
	}
	pli.close();
	std::cout << "Ilosc studentow znajacych C++: " << temp << std::endl;
	}*/

	StudentInformatyki s1;
	char NazwaPliku2[] = "zadaniedom.txt";
	std::ofstream plik2;
	plik2.open("zadanie.dom.txt", std::ios::app);

	if (!plik2)
		std::cerr << "Nie mozna otworzyc pliku";
	else
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << "Podaj dane " << i+1 << "-go studenta w kolejnosci(imie,nazwisko,semestr,nrIndeksu,czy zna C++ (1 jezeli zna)):\n";
			std::cin >> s1;
			plik2 << i + 1 << "."<< s1;
		}
	}



	system("pause");
	return 0;
}