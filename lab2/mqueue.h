#pragma once
#include "node.h"

template <typename sTYPE>
class mqueue {
private:
	Node<sTYPE> *start; //указатель на начало очереди
	Node<sTYPE> *end; //указатель на конец очереди
public:
	int  size = 0;
	mqueue() : start(nullptr), end(nullptr)
	{}
	void push(sTYPE);
	void pop();
	void print();
	~mqueue();
};

template <typename sTYPE>
void mqueue<sTYPE>::push(sTYPE value) {
	if (end == nullptr) {
		end = new Node<sTYPE>(value);
		start = end;
	}
	else {
		Node<sTYPE>* q = new Node<sTYPE>(value);
		end->next = q;
		end = q;
	}
	size++;
}

template <typename sTYPE>
void mqueue<sTYPE>::pop() {
	if (start == nullptr) {
		std::cout << "\n ERROR: Queue is empty " << size << "\n";
		return;
	}
	Node<sTYPE>* q = start;
	start = start->next;
	size--;
	delete q;
}

template <typename sTYPE>
void mqueue<sTYPE>::print() {
	Node<sTYPE>* q = end;
	while (q) {
		std::cout << " " << q->data;
		q = q->next;
	}
	std::cout << "\n Queue size is " << size << "\n";
}

template <typename sTYPE>
mqueue<sTYPE>::~mqueue() {
	while (size>0) {
		pop();
	}
}