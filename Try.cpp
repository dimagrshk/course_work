/*Грішко Дмитро БС-51
Визначення методів класу Try*/
#include "Try.h"

//--------------------------------------
//Конструктор за замовчуванням класу Try
Try::Try()
{
	questions = nullptr;
}
//--------------------------------------
//Конструктор з параметрами класу Try

Try::Try(string sub, string *str, int num, int var) : subject(sub), num_of_question(num), variant(var)
{
	questions = new string[num_of_question];
	for (int i = 0; i < num_of_question; i++)
	{
		questions[i] = str[i];
	}
}


//--------------------------------------
//Деструктор класу Try
Try::~Try()
{
	delete[] questions;
}
//--------------------------------------
//метод отримання значення поля num_of_question
int Try::num_question() const
{
	return num_of_question;
}
//--------------------------------------
//метод отримання значення поля subject
string Try::get_subject() const
{
	return subject;
}
//--------------------------------------
//метод отримання покажчика на масив questions
string * Try::get_question() const
{
	return questions;
}
//--------------------------------------
//метод отримання значення поля variant
int Try::get_variant() const
{
	return variant;
}
//--------------------------------------
//метод задання значення поля subject
void Try::set_subject()
{
	while (true)
	{
		cout << "subject: ";
		getline(cin, subject, '\n');
		try
		{
			if (cin.fail() || subject == "")
			{
				throw "error";
			}
		}
		catch (char * error)
		{
			cout << "Not correct input, try again" << endl;
			continue;
		}
		break;
	}
}
//--------------------------------------
//метод задання значення поля questions
void Try::set_question()
{
	if (questions != nullptr)
	{
		delete[] questions;
	}
	questions = new string[num_of_question];
	for (int i = 0; i < num_of_question; i++)
	{
		cout << "question: ";
		getline(cin >> ws, questions[i], '\n');
	}
}
//--------------------------------------
//метод задання значення поля num_of_question
void Try::set_num()
{
	cout << "number of question: ";
	string tmp_num;
	getline(cin, tmp_num);
	num_of_question = atoi(tmp_num.c_str());
	while (cin.fail() || num_of_question <= 0 || num_of_question >= 60)
	{
		cout << "Not correct input, try again" << endl;
		getline(cin, tmp_num);
		num_of_question = atoi(tmp_num.c_str());
	}
}
//--------------------------------------
//метод задання значення поля variant
void Try::set_var()
{
	cout << "variant: ";
	string tmp_var;
	getline(cin, tmp_var);
	variant = atoi(tmp_var.c_str());
	while (cin.fail() || variant <= 0 || variant >= 30)
	{
		cout << "Not correct input, try again" << endl;
		getline(cin, tmp_var);
		variant = atoi(tmp_var.c_str());
	}
}
//--------------------------------------
//метод виведення на екран полів  базового класу
void Try::show() const
{
	cout << "subject: " << subject << endl;
	cout << "variant: " << variant << endl;
	cout << "number of question: " << num_of_question << endl;
	for (int i = 0; i < num_of_question; i++)
	{
		cout << questions[i] << endl;
	}
}
//--------------------------------------
//Перевантаження операції << (побітового зміщення вліво) для класу Try, як віртуальний метод
ostream & Try::operator<<(ostream & out) const
{
	out << subject << endl;
	out << variant << endl;
	out << num_of_question << endl;
	for (int i = 0; i < num_of_question; i++)
	{
		out << questions[i] << endl;
	}
	return out;
}
//--------------------------------------
//Перевантаження операції >> (побітового зміщення вправо) для класу Try, як віртуальний метод	
istream & Try::operator>>(istream & in)
{
	getline(in, subject);
	in >> variant;
	if (in.fail())
	{
		in.ignore();
		throw exception();
	}
	in.ignore();
	//
	in >> num_of_question;
	if (in.fail())
	{
		in.ignore();
		throw exception();
	}
	//
	in.ignore();
	questions = new string[num_of_question];
	for (int i = 0; i < num_of_question; i++)
	{
		getline(in >> ws, questions[i]);
		if (in.fail())
		{
			throw exception();
		}
	}
	return in;
}
//--------------------------------------
//Перевантаження операції << (побітового зміщення вліво) для класу Try, як дружня функція
ostream & operator<<(ostream & out, Try * & tr)
{
	*tr << out;
	return out;
}
//--------------------------------------
//Перевантаження операції >>(побітового зміщення вправо) для класу Try, як дружня функція
istream & operator>>(istream & in, Try *& tr)
{
	*tr >> in;
	return in;
}
