/*Грішко Дмитро БС-51
Визначення методів класу Queue*/
#include "Queue.h"

//--------------------------------------
//Конструктор за замовчуванням
Queue::Queue() : front(nullptr), rear(nullptr)
{
	front = rear = nullptr;
}
//--------------------------------------
//Додає елемент в чергу
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
//--------------------------------------
//Видаляє елемент з черги
bool Queue::pop()
{
	if (!isempty())
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
		cout << "Object was removed" << endl;
		return true;
	}
	else
	{
		cout << "Queue is empty" << endl;
		return false;
	}

}
//--------------------------------------
//Деструктор класу
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
//--------------------------------------
//Перевіряє чи пустий контейнер
bool Queue::isempty() const
{
	return front == nullptr;
}
//--------------------------------------
//Підраховує скільки елементів на даний час в черзі
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
//--------------------------------------
//Виводить дані об’єктів з черги на екран
void Queue::travel() const
{
	if (!isempty())
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
	else
		cout << "Queue is empty" << endl;

}
//--------------------------------------
//Метод запису вмісту контейнера в файл
void Queue::travel_to_file() const
{
	ofstream fout("chapie.txt");
	if (fout)
	{
		if (!isempty())
		{
			Node *tmp;
			tmp = front;
			for (int i = 0; i < counter(); i++)
			{
				fout << tmp->item;
				tmp = tmp->next;
			}
			fout.close();
			cout << "Objects was saved to file" << endl;
		}
		else
			cout << "Conteiner is empty" << endl;
	}
	else
		cout << "File didn`t open" << endl;
}
//--------------------------------------
//Метод читання об’єктів з файлу
void Queue::read_from_file()
{
	ifstream fin("chapie.txt");
	if (fin)
	{
		bool check = false;
		string id;
		getline(fin, id);
		while (!fin.eof())
		{
			if (id == "Exam")
			{
				Try *e = new Exam();
				try
				{
					fin >> e;
				}
				catch (exception & ex)
				{
					cout << "Exception" << endl;
					delete e;
					break;
				}
				push(e);
				check = true;
			}
			else if (id == "Test")
			{

				Try *t = new Test();
				try
				{
					fin >> t;
				}
				catch (exception & ex)
				{
					cout << "Exception, file was changed" << endl;
					delete t;
					break;
				}
				push(t);
				check = true;
			}
			fin.clear();
			getline(fin, id);
		}
		if (!check) cout << "nothing have been read :(" << endl;
		fin.close();
	}
	else
	{
		cout << "File isn`t exist, information will be saved:)" << endl;
		travel_to_file();
	}

}
//--------------------------------------
//Метод сортуваня об’єктів контейнера
void Queue::sort_queue() const
{
	if (!isempty())
	{
		Node *tmp;
		Try *test;
		tmp = front;
		int length = counter();
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
		cout << "Sorting complete" << endl;
	}
	else
		cout << "Queue is empty" << endl;
}
//--------------------------------------
//Метод пошуку об’єктів за заданою темою
void Queue::query_queue(string subj) const
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

