#include "Queue.h"
#include <iostream>
#include <stdlib.h>

Queue::Queue()
{
	front = rear = nullptr;
	items = 0;
}
//add in queue
bool Queue::enqueue(const Item & item)
{
	Node * add = new Node;
	add->item = item;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}
//delete form queue
bool Queue::dequeue()
{
	Item item;
	if (isempty())
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp->item;
	delete temp;
	if (items == 0)
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
	return items == 0;
}



int Queue::queue_counter() const
{
	return items;
}

void Queue::travel() const
{
	Node *tmp;
	tmp = front;
	for (int i = 0; i < items; i++)
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
//			enqueue(e);
//			//delete e;
//		}
//		else if (id == "Test")
//		{
//			Test *t = new Test();
//			fin >> (*t);
//			enqueue(t);
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
