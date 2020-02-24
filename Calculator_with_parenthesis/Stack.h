#pragma once

template<typename T>

class Stack
{	
private:
	T *stack;
	int size;
public:
	Stack();
	Stack(int _size);

	void push(T _element);
	T pop();
	bool isEmpty();
};