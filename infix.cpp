
#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"
using  namespace std;
int main()
{
	string h;
	STACK a;
	int r = 0;

	int again = 1;
	while (again == 1)
	{
		cout << "Enter a postfix expression ";
		if (r == 1)
		{
			cin.ignore();

		}
		getline(cin, h);
		STACK b(h);

		cout << b;
		cout << "Type 1 if you want to go again ";
		cin >> again;
		
		r = 1;
	}
}