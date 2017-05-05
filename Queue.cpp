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

//void Queue::travel_to_file() const
//{
//	Node *tmp;
//	tmp = front;
//	for (int i = 0; i < items; i++)
//	{
//		tmp->item->save_to_file();
//		tmp = tmp->next;
//	}
//}

//void Queue::read_from_file()
//{
//	ifstream fin("chapie.txt");
//	//Exam *e;
//	//Test *t;
//	
//	//Try *t = new Test("", nullptr, 0, '\0', nullptr);
//	string id;
//	getline(fin, id);
//	while (!fin.eof())
//	{
//		if (id == "Exam")
//		{
//			Exam *e = new Exam();
//			fin >> (*e);
//			push(e);
//			//delete e;
//		}
//		else if (id == "Test")
//		{
//			Test *t = new Test();
//			fin >> (*t);
//			push(t);
//		}
//		getline(fin, id);
//	}
//	fin.close();
//}

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
