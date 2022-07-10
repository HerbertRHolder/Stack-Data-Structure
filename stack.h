#include <iostream>
#include "assert.h"
using namespace std;
template <class t>
struct Stack
{
	int maxSize;
	int top;
	//pointer to the array that holds the stack elements ->
	t* list;
public:
	// #1 constructor
	Stack(int SIZE = 100);
	//#2 copy constructor
	Stack(const Stack<t>& otherStack);
	// #3 operator
	const Stack<t> & operator=(const Stack<t>&);
		// #4 Destructor 
		~Stack();
	// #5 
	void initializeStack();
	//#6 returns true if empty else false
	bool isEmpty() const;
	// #7 returns true if full else false 
	bool isFull();
	// #8
	void push(const t& item);
	// #9
	t pop();
	// #10 This function returns the top element
	int showTop();
  
  
};
// #1
// CONSTRUCTOR
template <class t>
Stack<t>::Stack(int length)
{
	if (length <= 0)
	{
		cout << "Error! length must be a positive value." << endl;
	}
	else
	{
		maxSize = length;
		top = 0;
    //t *temp = list;
    //list[top-1] = 0;
		list = new t[maxSize];
	}

}
// #2
// Copy Contructor
template <class t> 
Stack<t>::Stack(const Stack<t>& otherStack)
{
	delete[] list;
	maxSize = otherStack.maxSize;
	top = otherStack.top;
}
// #3
// operator
template <class t>
const Stack<t> & Stack<t>::operator= (const Stack<t>& otherStack)
{
	if (this != &otherStack) //avoid self-copy
	{
		delete[] list;
		maxSize = otherStack.maxSize;
		top = otherStack.top;

		return *this;
	}
}
// #4
template <class t>
Stack<t>::~Stack()
{
	delete[] list; 
}

// #5
template <class t>
void Stack<t>::initializeStack()
{
	top = 0;
}
// #6
template <class t>
bool Stack<t>::isEmpty()const
{
	return(top == 0);
}
// #7
template <class t>
bool Stack<t>::isFull()
{
	return(top == maxSize);
}
// #8
template <class t>
void Stack<t>::push(const t & item)
{
	if (!isFull())
	{
		list[top] = item;
    top++;
	}
	else cout << "Error Stack is full" << endl;
}
// #9
template <class t>
t Stack<t>::pop() // need change
{
	if (!isEmpty())
		top--;
	else cout << "Error List is Empty" << endl;
  return list[top];
}

// #10
template <class t>
int Stack<t>::showTop() 
{
	assert(top != 0);
		return list[top-1];
}
