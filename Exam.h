#pragma once
#define Exam_h_
#include <iostream>
#include "Try.h"


class Exam : public Try
{
private:
	string type; // поле для позначення типу
public:
	//Construcors
	Exam(); //defult
	Exam(string sub, string *str, int num, int var, string typ); // конструктор з параметрами
	//Destructor
	~Exam();
	//Methods
	void set_question(); // перевизначений метод встановлення питань
	void set_type(); // метод встановлення відповідей
	string get_type(); // метод повернення типу екзамену
	void show() const; // перевизначений метод відображення вмісту об'єкту
	// to file
	ostream& operator<<(ostream& out); ///перевизначенні методи виводу в потік
	istream& operator>>(istream& in);
};
