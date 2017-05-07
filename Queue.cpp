#include "Queue.h"
#include <iostream>
#include <stdlib.h>

Queue::Queue()
{
	front = rear = nullptr;
	//items = 0;
}
//add in queue
bool Queue::push(Try * & item)
{
	Node * add = new Node;
	add->item = item;
	add->next = nullptr;
	//items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}
//delete form queue
bool Queue::pop()
{
	Try * item;
	if (isempty())
		return false;
	item = front->item;
	//items--;
	Node * temp = front;
	front = front->next;
	delete temp->item;
	delete temp;
	if (counter() == 0)
		rear = nullptr;
	return true;
}

Queue::~Queue()
{
	Node * temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return counter() == 0;
}




int Queue::counter() const
{
	int count = 0;
	if (front == nullptr)
	{
		return count;
	}
	else
	{
		Node * temp;
		temp = front;
		count++;
		while (temp != rear)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}
}

void Queue::travel() const
{
	Node *tmp;
	tmp = front;
	int length = this->counter();
	for (int i = 0; i < length; i++)
	{
		tmp->item->show();
		tmp = tmp->next;
	}
}

void Queue::travel_to_file() const
{
	ofstream fout("chapie.txt");
	fout.close();
	ofstream fout2("chapie2.txt");
	fout2.close();
	ofstream fout_ord("order.txt");
	Node *tmp;
	tmp = front;
	for (int i = 0; i < counter(); i++)
	{
		*tmp->item << fout_ord;
		tmp = tmp->next;
	}
	fout_ord.close();
}

void Queue::read_from_file()
{
	ifstream fin_exam("chapie2.txt");
	string key;
	while (!fin_exam.eof())
		{
			if (!getline(fin_exam, key))
				break;
			Try *e = new Exam();
			*e >> fin_exam;
			push(e);
		}
	fin_exam.close();
	ifstream fin2("chapie.txt");
	while (!fin2.eof())
	{
		if (!getline(fin2, key))
			break;
		Try *t = new Test();
		*t >> fin2;
		push(t);
	} 
	fin2.close();
}

Try * Queue::operator[](int index) const
{
	Node *tmp;
	tmp = front;
	for (int i = 0; i <index ; i++)
	{
		tmp = tmp->next;
	}
	return tmp->item;
}
