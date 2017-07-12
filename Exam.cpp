/*Грішко Дмитро БС-51
Визначення методів класу Exam*/
#include "Exam.h"

//--------------------------------------
//Конструктор за замовчуванням
Exam::Exam()
{
}
//--------------------------------------
//Конструктор з параметрами
Exam::Exam(string sub, string *str, int num, int var, string typ) : Try(sub, str, num, var), type(typ)
{
	//type = typ;
}
//--------------------------------------
//Деструктор
Exam::~Exam()
{
}
//--------------------------------------
//перевизначений метод встановлення питань
void Exam::set_question()
{
	Try::set_question();
	set_type();
}
//--------------------------------------
//метод встановлення типу екзамену
void Exam::set_type()
{
	cout << "Verb - 1, or write - 2?" << endl;
	string choice_tmp;
	int choice;
	getline(cin, choice_tmp);
	choice = atoi(choice_tmp.c_str());
	while (cin.fail() || choice < 1 || choice >2)
	{
		cout << "Not correct input, try again" << endl;
		getline(cin, choice_tmp);
		choice = atoi(choice_tmp.c_str());
	}
	if (choice == 1)
		type = "verb";
	else if (choice == 2)
		type = "write";
}
//--------------------------------------
//метод отримання типу екзамену
string Exam::get_type() const
{
	return type;
}
//--------------------------------------
//Константний метод для виведення на екран вмісту об’єкта класу Exam
void Exam::show() const
{
	using std::cout;
	cout << "For exam: " << endl;
	Try::show();
	cout << "type: " << type << endl;
}
//--------------------------------------
//Перевантаження операції << (побітового зміщення вліво) для класу Exam, як метод класу
ostream & Exam::operator<<(ostream & out) const // new method for saving
{
	out << "Exam" << endl;
	this->Try::operator<<(out);
	out << type << endl;
	return out;
}
//--------------------------------------
//Перевантаження операції >> (побітового зміщення вправо) для класу Exam, як метод класу
istream & Exam::operator>>(istream & in)
{
	this->Try::operator>>(in);
	getline(in, type);
	if (in.fail() || !(type != "verb" || type != "write"))
		throw exception();
	return in;
}

