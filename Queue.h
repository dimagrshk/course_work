#pragma once
#define Queue_h

#include "Try.h"
#include "Test.h"
#include "Exam.h"

using namespace std;


struct Node
{
	Try * item;				// поле, що зберігає покажчик на базовий клас в вузлі
	struct Node * next;		// покажчик на наступний вузол
};

class Queue
{
private:
	
	Node *front;			//покажчик на початок черги
	Node *rear;				//покажчик на кінець черги
	Queue(const Queue & q);//конструктор копіювання
	Queue & operator=(const Queue & q);//оператор дорівнює
	Queue();				// конструктор за замовчуванням
	~Queue();				//деструктор
public:
	static Queue &instance() //статична функція для повернення посиланя на статичний об'єкт
	{
		static Queue qe;	//статичний об'єкт
		return qe;
	}
	bool isempty() const;	//перевірка на порожність контейнера
	int counter() const;	//метод рахує кількітсь вузлів в черзі
	bool push(Try * & item);//додавання вузла
	bool pop();				//видалення вузла
	void travel() const;	//виведення на екран об'єктів
	void travel_to_file() const;//запис об'єктів в файл
	void read_from_file();		//читання з файлу
	void sort_queue();			//сортування черги
	void query_queue(string subj);//запит для контейнера
};