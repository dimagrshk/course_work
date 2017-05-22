#include "Exam.h"


Exam::Exam()
{
}

Exam::Exam(string sub, string *str, int num, int var, string typ) : Try(sub, str, num, var)
{
	type = typ;
}

Exam::~Exam()
{
}

void Exam::set_question()
{
	Try::set_question();
	set_type();
}

void Exam::set_type()
{
	cout << "Verb - 1, or write - 0?" << endl;
	int choice;
	cin >> choice;
	while (cin.fail() || choice < 0 || choice >1)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Not correct input, try again" << endl;
		cin >> choice;
	}
	if (choice)
		type = "verb";
	else
		type = "write";
}

string Exam::get_type()
{
	return type;
}

void Exam::show() const
{
	using std::cout;
	cout << "For exam: " << endl;
	Try::show();
	cout << "type: " << type << endl;
}




ostream & Exam::operator<<(ostream & out) // new method for saving
{
	out << "Exam" << endl;
	this->Try::operator<<(out);
	out << type << endl;
	return out;
}

istream & Exam::operator>>(istream & in)
{
	this->Try::operator>>(in);
	getline(in, type);
	try
	{
		if (in.fail() || !(type != "verb" || type != "write"))
		{
			throw "error";
		}
	}
	catch (char * error)
	{
		cout << error << endl;
		exception_for_input();
	}
	return in;
}

