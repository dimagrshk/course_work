#include "Queue.h"
#include <iostream>
#include <stdlib.h>

Queue::Queue()
{
	front = rear = nullptr;
}
//add in queue
bool Queue::push(Try * & item)
{
	Node * add = new Node;
	add->item = item;
	add->next = nullptr;
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
	Node *tmp;
	tmp = front;
	for (int i = 0; i < counter(); i++)
	{
		*tmp->item << fout;
		tmp = tmp->next;
	}
	fout.close();
}

void Queue::read_from_file()
{
	ifstream fin("chapie.txt");
	string id;
	getline(fin, id);
	while (!fin.eof())
	{
		if (id == "Exam")
		{
			Try *e = new Exam();
			*e >> fin;
			push(e);
		}
		else if (id == "Test")
		{
			Try *t = new Test();
			*t >> fin;
			push(t);
		}
		getline(fin, id);
	}
	fin.close();
}

void Queue::sort_queue()
{
	Node *tmp;
	Try *test;
	tmp = front;
	int length = this->counter();
	for (int i = 0; i < length - 1; i++)
	{
		tmp = front;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (tmp->item->get_subject() > tmp->next->item->get_subject())
			{
				test = tmp->item;//				swap-algorithm
				tmp->item = tmp->next->item;//
				tmp->next->item = test;//
			}
			tmp = tmp->next;// travel to other elements
		}
	}
}

void Queue::query_queue(string subj)
{
	Node *tmp;
	tmp = front;
	int length = this->counter();
	for (int i = 0; i < length; i++)
	{
		if (tmp->item->get_subject() == subj)
		{
			tmp->item->show();
		}
		tmp = tmp->next;
	}
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
