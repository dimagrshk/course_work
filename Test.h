#pragma once
#include <iostream>
#include "Try.h"

struct test_content
{
	string answer[4];
};

class Test : public Try
{
private:
	test_content *works;
public:
	//Construcors
	Test(); //default
	Test(string sub, string *str, unsigned int num, char var, test_content *arr);
	//Destructor
	~Test();
	//Methods
	void set_question();
	void set_answer(int i);
	void show() const;
	void save_to_file() const;
	void read_from_file(istream & in);
	friend ostream & operator<<(ostream & out, const Test & t);
	friend istream & operator>>(istream & in, Test & t);
};