#pragma once
#include <iostream>

template <typename sTYPE>
class Node {
public:
	sTYPE data;
	Node *next;
	Node *prev; //Используется для дека
	Node(sTYPE value) : data(value), next(nullptr), prev(nullptr)
	{}
};