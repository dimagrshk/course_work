/*Грішко Дмитро БС-51
Визначення методів класу Menu*/

#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

//--------------------------------------
//Метод для реалізації інтерфейсу користувача
void Menu::Budy()
{
	int key;
	Queue &q = Queue::instance();
	string s;
	do
	{
		system("cls");
		std::cout << "=========== MENU ===========" << std::endl;
		std::cout << "<1>.Create 'Test' object\n";
		std::cout << "<2>.Create 'Exam' object\n";
		std::cout << "<3>.Delete queue\n";
		std::cout << "<4>.Show the queue\n";
		std::cout << "<5>.Remove form the queue\n";
		std::cout << "<6>.Save to the file\n";
		std::cout << "<7>.Load from the file\n";
		std::cout << "<8>.Sort objects\n";
		std::cout << "<9>.Do request\n";
		std::cout << "<10>.Exit\n";
		getline(cin, s);
		key = atoi(s.c_str());
		switch (key)
		{
		
		case 1:
		{
			system("cls");
			std::cout << "<1>\n";
			cout << "Creating Test: " << endl;
			create_test(q);
			
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "<2>\n"; 
			cout << "Creating Exam: " << endl;
			create_exam(q);
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "<3>\n";
			remove_queue(q);
			cout << "All objects were deleted" << endl;
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "<4>\n";
			show_queue(q);
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "<5>\n";
			q.pop();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "<6>\n";
			q.travel_to_file();
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "<7>\n";
			q.read_from_file();
			cout << "Reading from file complete" << endl;
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "<8>\n";
			sort(q);
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			std::cout << "<9>\n";
			query(q);
			system("pause");
			break;
		}
		case 10:
		{
			system("cls");
			std::cout << "Exit <10>\n";
			system("pause");
			break;
		}
		default:
		{
			if (key > 10 || key < 1)
			{
				std::cout << "Try again)\n";
				system("pause");
			}
			break;
		}
		}
	} while (key != 10);
}
//--------------------------------------
//Створення об’єкту класу Exam та завантаження його в контейнер
void Menu::create_exam(Queue & q)
{
	Try *e = new Exam();
	e->set_subject();
	e->set_var();
	e->set_num();
	e->set_question();
	q.push(e);
}
//--------------------------------------
//Створення об’єкту класу Test та завантаження його в контейнер
void Menu::create_test(Queue & q)
{
	Try *t = new Test();
	t->set_subject();
	t->set_var();
	t->set_num();
	t->set_question();
	q.push(t);
}
//--------------------------------------
//Виведення на екран об’єктів контейнера
void Menu::show_queue(Queue & q)
{
	cout << "size queue: " << q.counter() << endl;
	q.travel();
}
//--------------------------------------
//Видалення об’єктів з контейнера
void Menu::remove_queue(Queue & q)
{
	cout << "Deleting queue: " << endl;
	int length = q.counter();
	for (int i = 0; i < length; i++)
		q.pop();
}
//--------------------------------------
//Сортування об’єктів контейнера
void Menu::sort(Queue &q)
{
	q.sort_queue();
}
//--------------------------------------
//Виконання запиту за темою предмету
void Menu::query(Queue & q)
{
	string tmp;
	cout << "input Subject: ";
	cin >> tmp;
	q.query_queue(tmp);
}
