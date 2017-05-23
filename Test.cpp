#include "Test.h"

Test::Test()
{
	works = nullptr;
}

Test::Test(string sub, string *str, int num, int var, test_content *arr) : Try(sub, str, num, var)
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

		//cout << "> " << questions[i] << endl;
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

test_content * Test::get_works()
{
	return works;
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

ostream & Test::operator<<(ostream & out) // new method for saving
{
	out << "Test" << endl;
	this->Try::operator<<(out);
	for (int i = 0; i < num_of_question; i++)
	{
		//out << t.questions[i] << endl;
		for (int j = 0; j < 4; j++)
		{
			out << works[i].answer[j] << endl;
		}
	}
	return out;
}

istream & Test::operator>>(istream & in)
{
	this->Try::operator>>(in);
	works = new test_content[num_of_question];
	for (int i = 0; i < num_of_question; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			getline(in >> ws, works[i].answer[j]);
			if (in.fail() || works[i].answer[j] == "" )
				throw exception();
		}
	}
	return in;
}


