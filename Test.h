#pragma once
#include <iostream>
#include "Try.h"

struct test_content		//структура описує відповіді для тестів
{
	string answer[4];   // варіантів відповідей на тест завжди чотири
};

class Test : public Try
{
private:
	test_content *works;	// масив структур для збереження відповідей для тесту
public:
	//Construcors
	Test(); //default
	Test(string sub, string *str, int num, int var, test_content *arr); // конструктор з параметрами
	//Destructor
	~Test();
	//Methods
	void set_question(); // перевизначений метод встановлення питань
	void set_answer(int i); // метод встановлення відповідей
	test_content * get_works(); //повертає покажчик на масив структур
	void show() const; // перевизначений метод відображення вмісту об'єкту
	ostream& operator<<(ostream& out); ///перевизначенні методи виводу та вводу в потік
	istream& operator>>(istream& in);
};