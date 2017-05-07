#include "Exam.h"
#include <string>
#include <iostream>

Exam::Exam()//:type(""), Try()
{
}

Exam::Exam(string sub, string *str, unsigned int num, char var, string typ) : Try(sub, str, num, var)
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
	if (choice)
		type = "verb";
	else
		type = "write";
}

void Exam::show() const
{
	using std::cout;
	cout << "For exam: " << endl;
	Try::show();
	cout << "type: " << type << endl;
}

void Exam::save_to_file() const // old method for saving
{
	fstream fout("chapie2.txt", ios_base::app);
	fout << "Exam" << "\n";
	fout << *this;
	/*fout << "For exam: \n";
	fout << "subject: " << subject << endl;
	fout << "variant: " << variant << endl;
	fout << "number of question: " << num_of_question << endl;
	for (int i = 0; i < num_of_question; i++)
	{
		fout << questions[i] << endl;
	}*/
	fout.close();
}

void Exam::read_from_file(istream & in)
{
	in >> *this;
}

ostream & Exam::operator<<(ostream & out) // new method for saving
{
	out << "Exam" << endl;
	fstream fout("chapie2.txt", ios_base::app);
	fout << "Exam" << "\n";
	fout << *this;
	fout.close();
	return out;
}

istream & Exam::operator>>(istream & in)
{
	return in >> *this;
}

ostream & operator<<(ostream & out, const Exam & e)
{
	out << e.subject << endl;
	out << e.variant << endl;
	out << e.num_of_question << endl;
	for (int i = 0; i < e.num_of_question; i++)
	{
		out << e.questions[i] << endl;
	}
	out << e.type << endl;
	return out;
}

istream & operator>>(istream & in, Exam & e)
{
	getline(in, e.subject);
	in >> e.variant;
	in.ignore();
	in >> e.num_of_question;
	in.ignore();
	e.questions = new string[e.num_of_question];
	for (int i = 0; i < e.num_of_question; i++)
	{
		getline(in>>ws, e.questions[i]);
	}
	getline(in, e.type);
	return in;
}
