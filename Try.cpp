#include "Try.h"
#include "Queue.h"

#include <limits>

//function for exception
//void exception_for_input()
//{
//	Queue &q = Queue::instance();
//	//q.travel_to_file();
//	cout << "Information will be saved:)" << endl;
//	//system("pause");
//	exit(1);
//}

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
		getline(cin >> ws, questions[i]);
	}
}

void Try::set_num()
{
	cout << "number of question: ";
	cin >> num_of_question;
	while (cin.fail() || num_of_question <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Not correct input, try again" << endl;
		cin >> num_of_question;
	}
}

void Try::set_var()
{
	cout << "variant: ";
	cin >> variant;
	while (cin.fail() || variant <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Not correct input, try again" << endl;
		cin >> variant;
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
	/////
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
