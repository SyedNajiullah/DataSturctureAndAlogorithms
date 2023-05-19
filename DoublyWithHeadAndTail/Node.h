#pragma once
#include<iostream>
#include<string>
template<class T>
struct Node
{
	T data;
	Node<T> *next;
	Node<T> *prev;
};