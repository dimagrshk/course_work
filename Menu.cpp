#include "Menu.h"
#include "Queue.h"
#include <fstream>

void init_fields(Try * item, Queue &q)
{
	item->set_subject();
	item->set_var();
	item->set_num();
	item->set_question();
	q.push(item);
}

void save_to_file(Queue &q)
{
	ofstream fout("chapie.txt");
	fout.close();
	ofstream fout2("chapie2.txt");
	fout2.close();
	////
	for (int i = 0; i < q.counter(); i++)
		q[i]->save_to_file();
}

void moder_reading(Queue &q, string file_name)
{
	if (file_name != "chapie.txt" && file_name != "chapie2.txt")
	{
		cout << "wrong file name:(" << endl;
		system("pause");
		return;
	}
	ifstream fin(file_name);
	string check;
	Try *e;
	while (!fin.eof())
	{
		if (!getline(fin, check))
			break;
		if (file_name == "chapie.txt")
		{
			Try *e = new Test();
			e->read_from_file(fin);
			q.push(e);
		}
		else if (file_name == "chapie2.txt")
		{
			Try *e = new Exam();
			e->read_from_file(fin);
			q.push(e);
		}	
	}
}

//void read_from_file(Queue &q)
//{
//	
//	ifstream fin_exam("chapie2.txt");
//	string key;
//	while (!fin_exam.eof())
//		{
//			if (!getline(fin_exam, key))
//				break;
//			Try *e = new Exam();
//			e->read_from_file(fin_exam);
//			q.push(e);
//		}
//	fin_exam.close();
//	ifstream fin2("chapie.txt");
//	while (!fin2.eof())
//	{
//		if (!getline(fin2, key))
//			break;
//		Try *t = new Test();
//		t->read_from_file(fin2);
//		q.push(t);
//	} 
//	fin2.close();
//}

void Menu::Budy()
{
	int key;
	Queue &q = Queue::instance();
	char s[10];
	do
	{
		system("cls");
		std::cout << "=========== MENU ===========" << std::endl;
		std::cout << "<1>.Create 'Test' object\n";
		std::cout << "<2>.Create 'Exam' object\n";
		std::cout << "<3>.Create 'Try' object\n";
		std::cout << "<4>.Show the queue\n";
		std::cout << "<5>.Remove form the queue\n";
		std::cout << "<6>.Save to the file\n";
		std::cout << "<7>.Load from the file\n";
		std::cout << "<8>.Sort objects\n";
		std::cout << "<9>.Do request\n";
		std::cout << "<10>.Exit\n";
		std::cin.getline(s, 10);
		key = atoi(s);
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
			cout << "Creating Try: " << endl;
			cout << "It`s a virtual class:)" << endl;
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
			//save_to_file(q);
			q.travel_to_file();
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "<7>\n";
			//read_from_file(q);
			moder_reading(q, "chapie.txt");
			moder_reading(q, "chapie2.txt");
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "<8>\n";
			cout << "size: " << q.counter() << endl;
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			std::cout << "<9>\n";
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
				std::cout << "Try again)\n\n";
			}
			break;
		}
		}
	} while (key != 10);
}

void Menu::create_exam(Queue & q)
{
	Try *e = new Exam();
	init_fields(e, q);
}

void Menu::create_test(Queue & q)
{
	Try *t = new Test();
	init_fields(t, q);
}

void Menu::show_queue(Queue & q)
{
	q.travel();
}

void Menu::remove_queue(Queue & q)
{

}
