#include "Test.h"

Test::Test()//: works(nullptr), Try()
{
	works = nullptr;
}

Test::Test(string sub, string *str, unsigned int num, char var, test_content *arr) : Try(sub, str, num, var)
{
	works = new test_content[num_of_question];
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			works[i].answer[j] = arr[i].answer[j];
		}
	}
}

Test::~Test()
{
	delete[] works;
}

void Test::set_question()
{
	if (questions != nullptr)
	{
		delete[] questions;
	}
	works = new test_content[num_of_question];
	questions = new string[num_of_question];
	for (int i = 0; i < num_of_question; i++)
	{
		cout << "question: ";
		//cin >> question[i];
		getline(cin >> ws, questions[i]);
		cout << "> " << questions[i] << endl;
		set_answer(i);
	}
}

void Test::set_answer(int i)
{
	if ((works != nullptr) && (i == 0))
	{
		delete[] works;
		works = new test_content[num_of_question];
	}
	for (int j = 0; j < 4; j++)
	{
		cout << "answer:";
		getline(cin >> ws, works[i].answer[j], '\n');
	}
}

void Test::show() const
{
	using std::cout;
	cout << "For test: " << endl;
	//Try::show();
	cout << "subject: " << subject << endl;
	cout << "variant: " << variant << endl;
	cout << "number of question: " << num_of_question << endl;

	for (int i = 0; i < num_of_question; i++)
	{
		cout << questions[i] << endl;
		for (int j = 0; j < 4; j++)
		{
			cout << works[i].answer[j] << endl;
		}
	}
}

void Test::save_to_file() const // old method for saving
{
	fstream fout("chapie.txt", ios_base::app);
	fout << "Test\n";
	fout << *this; 
	fout.close();
}

void Test::read_from_file(istream & in)
{
	in >> *this;
}

ostream & Test::operator<<(ostream & out) // new method for saving
{
	out << "Test" << endl;
	fstream fout("chapie.txt", ios_base::app);
	fout << "Test" << "\n";
	fout << *this;
	fout.close();
	return out;
}

istream & Test::operator>>(istream & in)
{
	return in >> *this;
}

ostream & operator<<(ostream & out, const Test & t)
{
	out << t.subject << endl;
	out << t.variant << endl;
	out << t.num_of_question << endl;
	for (int i = 0; i < t.num_of_question; i++)
	{
		out << t.questions[i] << endl;
		for (int j = 0; j < 4; j++)
		{
			out << t.works[i].answer[j] << endl;
		}
	}
	return out;
}

istream & operator>>(istream & in, Test & t)
{
	getline(in, t.subject);
	in >> t.variant;
	in.ignore();
	in >> t.num_of_question;
	in.ignore();
	t.questions = new string[t.num_of_question];
	t.works = new test_content[t.num_of_question];
	for (int i = 0; i < t.num_of_question; i++)
	{
		getline(in >> ws, t.questions[i]);
		for (int j = 0; j < 4; j++)
		{
			getline(in >> ws, t.works[i].answer[j]);
		}
	}
	return in;
}
