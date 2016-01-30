
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "stack.h"

using namespace std;

//Initializes stack
STACK::STACK()
{
	top = 0;
	bottom = 0;

}

//Takes a postfix expression and utilizes a stack to convert it into an infix expression
STACK::STACK(string s)
{
	
	top = new node;
	int count = 1;
	top->next = 0;
	length = 1;
	int slength = s.length();
	string y;
	string op;
	int lcount=0;
	int ocount = 0;
	if (slength == 0)
	{
		cout << "The string you entered is empty"<<endl;
		goto done;
	}
	for (int j = 0; j < slength; ++j)
	{
		if (isspace(s[j]))
		{
			s.erase(j, 1);
			slength--;
			j--;
		}
	}
	
	for (int x = 0; x < slength; x++)
	{
		if (s[x] == '*' || s[x] == '/' || s[x] == '+' || s[x] == '-')
		{
			
			ocount = ocount + 1;
			op = s[x];
			string q, a, r;
			q = (*this).pop();
			if (lcount<=ocount)
			{
				cout << "too many operators and not enough operand"<<endl;
				goto done;
			}
			q = "(" + (*this).pop() +" "+ op +" "+ q + ")";
						
			push(q);
			
		}
		else
		{
			
			lcount = lcount + 1;
			y= s[x];			
			push(y);
			
		}
		
		}

		done:;

}

//Deletes top and returns its string
string STACK::pop()
{
	string s = top->data;
	node *eras = top;

	if (eras->next == 0)
	{
		delete eras,top;
		top = new node;
		top->next = 0;
		return s;
	}
	else
	{
		eras = eras->next;
		delete top;
		top = eras;
		return s;
	}
}

//New node pushed to top of stack along with the string inserted into the node
void STACK::push(string s)
{
	node *piece = new node;
	piece->next = top;
	top = piece;
	top->data = s;

}


ostream &operator <<(ostream &out, const STACK &S)
{
	for (node *n = S.top; n != 0; n = n->next)
	{
		out << n->data;
	}
	cout << endl;
	return out;
}
