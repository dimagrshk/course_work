#pragma once
#define Queue_h

#include "Try.h"
#include "Test.h"
#include "Exam.h"

using namespace std;

//typedef Try * Try *;

struct Node
{
	Try * item;
	struct Node * next;
};

class Queue
{
private:
	
	Node *front;
	Node *rear;
	//int items; // 
	Queue(const Queue & q);//
	Queue & operator=(const Queue & q);
	Queue();
	~Queue();
public:
	static Queue &instance()
	{
		static Queue qe;
		return qe;
	}
	bool isempty() const;
	int counter() const;
	bool push(Try * & item);
	bool pop();
	void travel() const;
	void travel_to_file() const;
	void read_from_file();
	void sort_queue();
	void query_queue(string subj);
	Try	* operator[](int i) const;
};