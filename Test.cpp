/*Грішко Дмитро БС-51
Визначення методів класу Test*/
#include "Test.h"

//--------------------------------------
//Конструктор за замовчуванням
Test::Test()
{
	works = nullptr;
}
//--------------------------------------
//Конструктор з параметрами
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
//--------------------------------------
//Деструктор
Test::~Test()
{
	delete[] works;
}
//--------------------------------------
//перевизначений метод встановлення питань
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
		getline(cin >> ws, questions[i]);
		set_answer(i);
	}
}
//--------------------------------------
//метод встановлення відповідей
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
//--------------------------------------
//повертає покажчик на масив структур відповідей
test_content * Test::get_works() const
{
	return works;
}
//--------------------------------------
//Константний метод для виведення на екран вмісту об’єкта класу Test
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
//--------------------------------------
//Перевантаження операції << (побітового зміщення вліво) для класу Test, як метод класу
ostream & Test::operator<<(ostream & out) const 
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
//--------------------------------------
//Перевантаження операції >> (побітового зміщення вправо) для класу Test, як метод класу
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


