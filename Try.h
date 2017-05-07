#pragma once
#define Try_h_
#include <string>
#include <fstream>

using namespace std;

class Try {
protected:
	string subject;
	string *questions;
	unsigned int num_of_question;
	char variant;
public:
	//Constructors
	Try();
	Try(string, string *, unsigned int, char);
	//Destructor
	virtual ~Try();
	//Methods
	virtual void set_subject();
	virtual void set_question();
	virtual void set_num();
	virtual void set_var();
	virtual void set_type();
	virtual void show() const;

	//to file
	virtual void save_to_file() const;
	virtual void read_from_file(istream & in);
	virtual ostream& operator<<(ostream& out);
	virtual istream& operator>>(istream& in);
	// friends
	friend ostream& operator<<(ostream& out, const Try * & tr);
	friend istream& operator>>(istream& in, const Try * & tr);
};