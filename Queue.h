#pragma once
#define Queue_h

#include "Try.h"
#include "Test.h"
#include "Exam.h"

using namespace std;

typedef Try * Item;

struct Node
{
	Item item;
	struct Node * next;
};

class Queue
{
private:
	
	Node *front;
	Node *rear;
	int items; // 
	Queue(const Queue & q);//
	Queue & operator=(const Queue & q) { return *this; }//
public:
	Queue();
	~Queue();
	bool isempty() const;
	int queue_counter() const;
	bool enqueue(const Item & item);
	bool dequeue();
	void travel() const;
	void travel_to_file() const;
	void read_from_file();
	Try	* operator[](int i) const;
};