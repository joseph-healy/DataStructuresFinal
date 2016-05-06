#include <iostream>
#include "Set.h"

struct testVtex
{
	int data;
};

void testSet();

int main()
{
	testSet();
	system("pause");
	return 0;
}

void testSet()
{
	Set<testVtex*>test;

	for (int i = 0; i < 10; i++)
	{
		int tmp = rand() % 100 + 1;
		test.insert(new testVtex{tmp});
	}

	cout << "Set size: " << test.nodeCount() << endl;;

	testVtex** testArr = test.getNodes();

	cout << "Set contents: " << endl;

	for (int i = 0; i < test.nodeCount() - 1; i++)
		cout << testArr[i]->data << endl;


}