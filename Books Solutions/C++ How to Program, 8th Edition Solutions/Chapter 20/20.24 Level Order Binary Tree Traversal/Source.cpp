#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"

using namespace std;

int main()
{	
	Tree <int> tr;

	tr.insert(15);
	tr.insert(6);
	tr.insert(20);
	tr.insert(18);
	tr.insert(3);
	tr.insert(9);
	tr.insert(8);
	tr.insert(25);

	tr.inOrder();
	cout << endl;

	tr.preOrder();
	cout << endl;

	tr.postOrder();
	cout << endl;
	
	tr.LevelOrder_Traversal();
	cout << endl;

	return 0;
}