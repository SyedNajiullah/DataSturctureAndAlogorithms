#pragma once
#include<iostream>
template<class T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
};