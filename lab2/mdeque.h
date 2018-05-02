#pragma once
#include "node.h" 

template <typename sTYPE>
class mdeque {
private:
	Node<sTYPE> *start; //указатель на начало дека
	Node<sTYPE> *end; //указатель на конец дека
public:
	int  size = 0;
	mdeque() : start(nullptr), end(nullptr)
	{}
	void push_end(sTYPE);
	void push_start(sTYPE);
	void pop_start();
	void pop_end();
	void print_left_right();
	void print_right_left();
	sTYPE r_end();
	sTYPE r_start();
	~mdeque();
};

template <typename sTYPE>
void mdeque<sTYPE>::push_end(sTYPE value) {
	if (end == nullptr) {
		start = new Node<sTYPE>(value);
		end = start;
	}
	else {
		Node<sTYPE> * q = new Node<sTYPE>(value);
		end->next = q;
		q->prev = end;
		end = q;
	}
	size++;
}

template <typename sTYPE>
void mdeque<sTYPE>::push_start(sTYPE value) {
	if (start == nullptr) {
		start = new Node<sTYPE>(value);
		end = start;
	}
	else {
		Node<sTYPE> * q = new Node<sTYPE>(value);
		start->prev = q;
		q->next = start;
		start = q;
	}
	size++;
}

template <typename sTYPE>
void mdeque<sTYPE>::pop_end() {
	if (end == nullptr) {
		std::cout << "\n ERROR: Deque is empty " << size << "\n";
		return;
	}
	Node<sTYPE> * q = end;
	end = end->prev;
	size--;
	delete q;

	if (end != nullptr)
		end->next = nullptr;
	else
		start = nullptr;
}

template <typename sTYPE>
void mdeque<sTYPE>::pop_start() {
	if (start == nullptr) {
		std::cout << "\n ERROR: Deque is empty " << size << "\n";
		return;
	}
	Node<sTYPE> * q = start;
	start = start->next;
	size--;
	delete q;

	if (start != nullptr)
		start->prev = nullptr;
	else
		end = nullptr;
}

template <typename sTYPE>
void mdeque<sTYPE>::print_left_right() {
	Node<sTYPE>* q = start;
	while (q) {
		std::cout << "\'" << q->data << "\'";
		q = q->next;
	}
	std::cout << "\n Deque size is " << size << "\n";
}

template <typename sTYPE>
sTYPE mdeque<sTYPE>::r_end() {
	return end->data;
}

template <typename sTYPE>
sTYPE mdeque<sTYPE>::r_start() {
	return start->data;
}

template <typename sTYPE>
void mdeque<sTYPE>::print_right_left() {
	Node<sTYPE>* q = end;
	while (q) {
		std::cout << "" << q->data << "\'";
		q = q->prev;
	}
	std::cout << "\n Deque size is " << size << "\n";
}

template <typename sTYPE>
mdeque<sTYPE>::~mdeque() {
	while (size > 0)
		pop_end();
}

