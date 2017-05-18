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
	Exam(string sub, string *str, unsigned int num, unsigned int var, string typ);
	//Destructor
	~Exam();
	//Methods
	void set_question();
	void set_type();
	void show() const;
	// to file
	void save_to_file() const;
	void read_from_file(istream & in);
	ostream& operator<<(ostream& out);
	istream& operator>>(istream& in);
	// friend functions
	friend ostream & operator<<(ostream & out, const Exam & e);
	friend istream & operator>>(istream & in, Exam & e);
};
