#include "Try.h"
#include "Queue.h"


Try::Try()
{
	questions = nullptr;
}


Try::Try(string sub, string *str, int num, int var) : subject(sub), num_of_question(num), variant(var)
{
	questions = new string[num_of_question];
	for (int i = 0; i < num_of_question; i++)
	{
		questions[i] = str[i];
	}
}



Try::~Try()
{
	delete[] questions;
}

int Try::num_question()
{
	return num_of_question;
}

string Try::get_subject()
{
	return subject;
}

string * Try::get_question()
{
	return questions;
}

int Try::get_variant()
{
	return 0;
}

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



ostream & Try::operator<<(ostream & out)
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



ostream & operator<<(ostream & out, Try * & tr)
{
	*tr << out;
	return out;
}

istream & operator>>(istream & in, Try *& tr)
{
	*tr >> in;
	return in;
}
