#ifndef Menu_h
#define Menu_h

#include "Queue.h"

class Menu {
private:
	Menu() {			// конструктор за замовчуванням

	}
	~Menu() {			//деструктор

	}
	Menu(const Menu& m);//конструктор копіювання
	Menu& operator=(Menu const& m);//оператор дорівнює
public:
	static Menu &instance()			//статична функція для повернення посиланя на статичний об'єкт
	{
		static Menu m;				//статичний об'єкт
		return m;	
	}
	void Budy();					//відображення меню та взаємодії з ним
	void create_exam(Queue &q);		//створення об'єкту екзамен
	void create_test(Queue &q);		//створення ою'єкту тест
	void show_queue(Queue &q);		//виведення черги на екран
	void remove_queue(Queue &q);	//очищення черги
	void sort(Queue &q);			//сортування черши
	void query(Queue &q);			//запит до черги

};

#endif