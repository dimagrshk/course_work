#ifndef Menu_h
#define Menu_h
#include "Try.h"
#include "Test.h"
#include "Exam.h"
#include "Queue.h"
#include <iostream>
#include <string.h>
#include <string>

class Menu {
private:
	Menu() {

	}
	~Menu() {

	}
	Menu(const Menu&);
	Menu& operator=(Menu const&);
public:
	static Menu &instance()
	{
		static Menu m;
		return m;
	}
	void Budy();
	void create_exam(Queue &q);
	void create_test(Queue &q);
	void show_queue(Queue &q);
	void remove_queue(Queue &q);
	void sort(Queue &q);
	void query(Queue &q);

};

#endif