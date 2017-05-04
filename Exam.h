#pragma once
#define Exam_h_
#include <iostream>
#include "Test.h"


class Exam : public Try
{
private:
	string type;
public:
	//Construcors
	Exam(); //defult
	Exam(string sub, string *str, unsigned int num, char var, string typ);
	//Destructor
	~Exam();
	//Methods
	void set_question();
	void set_type();
	void show() const;
	void save_to_file() const;
	//void read_from_file();
	friend ostream & operator<<(ostream & out, const Exam & e);
	friend istream & operator>>(istream & in, Exam & e);
};
