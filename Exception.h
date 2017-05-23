#pragma once
#include "Queue.h"

class Exception
{
public:
	static void exception_for_input()
	{
		Queue &q = Queue::instance();
		q.travel_to_file();
		cout << "File is damaged. Your Information will be saved:)" << endl;
		system("pause");
		exit(1);
	}
};