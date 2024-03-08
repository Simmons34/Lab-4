#include <iostream>
#include "Stack.h"

using namespace std;
int main() {
	cout << "Hello Recursion" << endl;
	
	Stack<int> myStack;
	
	myStack.Push(3);
	myStack.Push(5);
	myStack.Push(7);
	myStack.Push(9);
	myStack.Push(11);

	cout << "Before reversal" << endl;
	myStack.PrintStack();
	
	cout << endl;

	myStack = myStack.RevStack();
	
	cout << "After reversal" << endl;
	myStack.PrintStack();

	return 0;
}
