#include "Try.h"
#include "Queue.h"
#include <string>
#include <iostream>

//function for exception
void exception_for_input()
{
	Queue &q = Queue::instance();
	q.travel_to_file();
	cout << "Information will be saved:)" << endl;
	system("pause");
	exit(1);
}

Try::Try()//: subject(NULL), num_of_question(0), variant(NULL), questions(nullptr)
{
	questions = nullptr;
}


Try::Try(string sub, string *str, unsigned int num, char var) : subject(sub), num_of_question(num), variant(var)
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

void Try::set_subject()
{
	cout << "subject: ";
	getline(cin, subject, '\n');
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
		cout << "> " << questions[i] << endl;
	}
}

void Try::set_num()
{
	cout << "number of question: ";
	cin >> num_of_question;
}

void Try::set_var()
{
	cout << "variant: ";
	cin >> variant;
}

//void Try::set_type()
//{
//	
//}

void Try::show() const
{
	//using std::cout;
	//cout << "For Try: " << endl;
	cout << "subject: " << subject << endl;
	cout << "variant: " << variant << endl;
	cout << "number of question: " << num_of_question << endl;
	for (int i = 0; i < num_of_question; i++)
	{
		cout << questions[i] << endl;
	}
}


void Try::save_to_file() const
{
	/*fstream fout("chapie.txt", ios_base::app);
	fout << "For Try" << endl;
	fout << "subject: " << subject << endl;
	fout << "variant: " << variant << endl;
	fout << "number of question: " << num_of_question << endl;
	for (int i = 0; i < num_of_question; i++)
	{
		fout << questions[i] << endl;
	}
	fout.close();*/
}

void Try::read_from_file(istream & in)
{
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
	try
	{
		if (in.fail())
		{
			throw "error";
		}
	}
	catch (char * error)
	{
		cout << error << endl;
		exception_for_input();
	}
	in.ignore();
	//
	in >> num_of_question;
	try
	{
		if (in.fail())
		{
			throw "error";
		}
	}
	catch (char * error)
	{
		cout << error << endl;
		exception_for_input();
	}
	//
	in.ignore();
	questions = new string[num_of_question];
	for (int i = 0; i < num_of_question; i++)
	{
		getline(in >> ws, questions[i]);
		try
		{
			if (in.fail())
			{
				throw "error";
			}
		}
		catch (char * error)
		{
			cout << error << endl;
			exception_for_input();
		}

	}
	return in;
}

//Try* & Try::operator=(const Try* & obj)
//{
//	return *this = obj;
//}

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
