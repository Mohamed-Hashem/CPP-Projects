#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <functional>
#include <algorithm>
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

	tr.postOrder();
	cout << endl;

	tr.preOrder();
	cout << endl;

	return 0;
}