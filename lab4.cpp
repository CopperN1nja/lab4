#include <iomanip>
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <string>

using namespace std;

void showMenu();
int mainMenu();
int writeNumbers();
string writeWord();



class cooking
{
private:

	string ingredient;
	string country;
public:
	cooking()
	{

	};
	cooking( string ingredient, string country);
	void show();
};

class frying :public cooking
{
private:
	bool isfry;
	string temp;
public:
	frying( string ingredient, string country, bool isfry, string temp);
	void show();
};

class boiling :public cooking
{
private:
	string boil;
	bool boil_1;
public:
	boiling(string ingredient, string country, string boil, bool boil_1);
	void show();
};

class stewing :public cooking
{
private:
	int sol;
	string temperatyra;
public:
	stewing(string ingredient, string country, int sol, string temperatyra);
	void show();
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout << endl;
	mainMenu();
	return 0;
}

void showMenu()
{
	cout << "\t Нажмите 1 - если блюдо жарится \n\tНажмите 2 - если блюдо варится \n\tНажмите 3 - если блюдо тушится\n\tНажмите 4 - выход\n\tВаш выбор:> ";
}

int mainMenu()
{
	frying* fry = NULL;
	boiling* boil = NULL;
	stewing* strew = NULL;

	int choice;
	while (true)
	{
		showMenu();
		choice = writeNumbers();
		switch (choice)
		{
		case 1:
		{
			string ingredient, country;
			
			cout << endl << "Введите основной ингредиент" << endl;
			ingredient = writeWord();
			
			
			//cin >> ;
			cout << endl  << "Введите страну происхождения блюда" << endl;
			country = writeWord();

			bool ch;
			cout <<  endl << " содержил ли блюдо мясо ('1' - да, '2' -нет)" << endl;
			ch = writeNumbers();
			string s;
			cout << endl << "блюдо холодное или горячее: " << endl;
			s = writeWord();
			fry = new frying( ingredient, country, ch, s);
			fry->show();
			break;
		}
		case 2:
		{
			string n, c;
			string ingredient, country;
			
			cout << "Введите основной ингредиент" << endl;
			ingredient = writeWord();
			
			cout << "Введите страна происхождения блюда" << endl;
			country = writeWord();

			bool ch;
			string m;
			cout << "Введите название блюда: " << endl;
			m = writeWord();
			cout << "содержил ли блюдо мясо ('1' - да, '0' -нет)" << endl;
			ch = writeNumbers();
			boil = new boiling( ingredient, country, m, ch);
			boil->show();
			break;
		}
		case 3:
		{
			string n, c;
			string ingredient, country;
			
			cout << "Введите основной ингредиент" << endl;
			ingredient = writeWord();
			
			cout << "Введите национальность блюда" << endl;
			country = writeWord();

			string t;
			int a;
			cout << "Введите блюдо холодное или горячее:: " << endl;
			t = writeWord();
			cout << "Введите кол-во соли: " << endl;
			a = writeNumbers();
			strew = new stewing( ingredient, country, a, t);
			strew->show();
			break;
		}
		case 4:
			return 0;
		default:
			cout << endl << "Ошибка! Неверное действие" << endl;
		}
	}
	if (fry != NULL) delete fry;
	if (boil != NULL) delete boil;
	if (strew != NULL) delete strew;
}

cooking::cooking( string ingredient, string country)
{
	this->ingredient = ingredient;
	this->country = country;
}

frying::frying( string ingredient, string country, bool isfry, string temp)
{
	this->cooking::cooking( ingredient, country);
	this->isfry = isfry;
	this->temp = temp;
}

boiling::boiling( string ingredient, string country, string boil, bool boil_1)
{
	this->cooking::cooking( ingredient, country);
	this->boil = boil;
	this->boil_1 = boil_1;
}

stewing::stewing( string ingredient, string country, int sol, string temperatyra)
{
	this->cooking::cooking( ingredient, country);
	this->sol = sol;
	this->temperatyra = temperatyra;
}

void cooking::show()
{
	cout << "главный ингредиент: " << this->ingredient << endl << "Страна происхождения: " << this->country << endl;
}
void frying::show()
{
	cooking::show();
	cout << "наличие мяса: " << this->isfry << endl << "температура : " << this->temp << endl;
}

void boiling::show()
{
	cout << "Название блюда: " << this->boil << endl << "Наличие мяса: " << this->boil_1 << endl;
	cooking::show();
}

void stewing::show()
{
	cout << endl << "кол-во соли: " << this->sol << endl << "Температура: " << this->temperatyra << endl;
	cooking::show();
}

int writeNumbers()
{
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224)
		{
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

string writeWord()
{
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}