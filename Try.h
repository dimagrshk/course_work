/*Грішко Дмитро БС-51
Визначення класу Try*/

#pragma once
#define Try_h_
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

class Try {
protected:
	string subject;				//тема випробування
	string *questions;			//масив запитань
	int num_of_question;		//кількість питань
	int variant;				//варіант випробування
public:
	//Constructors
	Try();						//конструктор за замовчуванням
	Try(string sub, string *str, int num, int var); //конструктор з параметрами
	//Destructor
	virtual ~Try() = 0;				//деструктор базового класу
	//Methods
	virtual int num_question() const; //метод для повернення значення кількості питань
	virtual string get_subject() const; //метод для повернення теми випробування
	virtual string * get_question() const; //метод для повернення покажчика на масив питань
	virtual int get_variant() const; //метод для повернення значення варіанту
	virtual void set_subject(); //метод для встановлення теми
	virtual void set_question();//метод для встановлення питань
	virtual void set_num();		//метод для встановлення кількості питань
	virtual void set_var();		//метод для встановлення варіанту
	virtual void show() const;	//виводить на екран вміст об'кту


	//to file
	virtual ostream& operator<<(ostream& out) const; //перевантаження оперції <<, як метод класу
	virtual istream& operator>>(istream& in);  //перевантаження оперції >>, як метод класу
	// friends
	friend ostream& operator<<(ostream& out, Try * & tr); //перевантаження оперції <<, як дружня ф-ція
	friend istream& operator>>(istream& in, Try * & tr);  ////перевантаження оперції >>, як дружня ф-ція
};