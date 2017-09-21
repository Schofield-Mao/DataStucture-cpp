#include<iostream>
#include"LList.h"
using namespace std;

int main()
{
	LList<int> test;
	for(int i=0;i<10;i++)
	{
		test.append(i);
	}
	test.print();
	cout << endl;
	test.move2pos(5);
	test.insert(100);
	test.print();
	cout << endl;
	test.remove();
	test.print();
	cout << endl;
	test.move2start();
	test.getvalue();
	//test.print();
	cout <<test.getvalue()<<endl;
	test.clear();
	test.print();
	cout << "clear"<<endl;
}
