#include "Menu.h"
#include "Queue.h"
#include <fstream>

void init_fields(Try * item, Queue &q)
{
	item->set_subject();
	item->set_var();
	item->set_num();
	item->set_question();
	// can exist in other method
	//e->set_type();
	q.enqueue(item);
	//cout << "subject: ";
	////cin >> *subj;
	//getline(cin, *subj, '\n');
	//cout << "variant: ";
	//cin >> *var;
	//cout << "number of question: ";
	//cin >> *num;
}

void save_to_file(Queue &q)
{
	ofstream fout("chapie.txt");
	fout.close();
	for (int i = 0; i < q.queue_counter(); i++)
		q[i]->save_to_file();
}

void read_from_file(Queue &q)
{
	ifstream fin("chapie.txt");
	string id;
	getline(fin, id);
	while (!fin.eof())
	{
		if (id == "Exam")
		{
			Exam *e = new Exam();
			fin >> (*e);
			q.enqueue(e);
		}
		else if (id == "Test")
		{
			Test *t = new Test();
			fin >> (*t);
			q.enqueue(t);
		}
		getline(fin, id);
	}
	fin.close();
}

void Menu::Budy()
{
	int key;
	Queue q;
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
			//char variant;
			//string subject;
			//unsigned int num_of_question;
			//init_fields(&subject, &num_of_question, &variant);
			//string *question = new string[num_of_question];
			//test_content *works = new test_content[num_of_question];
			//for (int i = 0; i < num_of_question; i++)
			//{
			//	cout << "question:";
			//	getline(cin>>ws, question[i], '\n');
			//	//cout << "\n";
			//	for (int j = 0; j < 4; j++)
			//	{
			//		cout << "answer:";
			//		//cin >> works[i].answer[j];
			//		//cin.ignore();
			//		getline(cin>>ws, works[i].answer[j], '\n');
			//		//cin.clear(); 
			//		//cout << "\n";
			//	}
			//}
			//Try *tmp = new Test(subject, question, num_of_question, variant, works);
			//q.enqueue(tmp);
			//delete[] question;
			//delete[] works;
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "<2>\n"; 
			cout << "Creating Exam: " << endl;
			create_exam(q);
			//char variant;
			//string subject, type;
			//unsigned int num_of_question;
			//init_fields(&subject, &num_of_question, &variant);
			//string *question = new string[num_of_question];
			//for (int i = 0; i < num_of_question; i++)
			//{
			//	cout << "question: ";
			//	//cin >> tmp_q[i];
			//	//cin.ignore();
			//	getline(cin>>ws, question[i]);
			//	cout << "> " << question[i] << endl;
			//}
			//cout << "Verb or write?" << endl;
			//int choice;
			//cin >> choice;
			//if (choice)
			//	type = "verb";
			//else
			//	type = "write";
			//Try *tmp = new Exam(subject, question, num_of_question, variant, type);
			//q.enqueue(tmp);
			//delete[] question;
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "<3>\n";
			cout << "Creating Try: " << endl;
			cout << "It`s a virtual class:)" << endl;
			//char variant;
			//string subject;
			//unsigned int num_of_question;
			//init_fields(&subject, &num_of_question, &variant);
			//string *question = new string[num_of_question];
			//for (int i = 0; i < num_of_question; i++)
			//{
			//	cout << "question: ";
			//	//cin >> question[i];
			//	getline(cin >> ws, question[i]);
			//	cout << "> " << question[i] << endl;
			//}
			//Try *tmp = new Try(subject, question, num_of_question, variant);
			//q.enqueue(tmp);
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "<4>\n";
			show_queue(q);
			//q.travel();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "<5>\n";
			////
			q.dequeue();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "<6>\n";
			save_to_file(q);
			//q.travel_to_file();
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "<7>\n";
			read_from_file(q);
			//q.read_from_file();
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "<8>\n";
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
