
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class node
{
public:
	string data;
	node *next;

};

class STACK
{
public:
	STACK();
	STACK(string s);
	string pop();
	void push(string s);
	friend ostream &operator <<(ostream &, const STACK &S);

private:
	node *top;
	node *bottom;
	int length;
};

#endif
