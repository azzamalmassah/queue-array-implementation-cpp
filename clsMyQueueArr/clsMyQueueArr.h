#pragma once

#include <iostream>
#include "clsDynamicArray.h"

template <class T>

class clsMyQueueArr
{

protected:
	clsDynamicArray <T> _MyList;

public:

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}


	void pop()
	{
		if (IsEmpty())
			throw std::out_of_range("Queue is empty");
		_MyList.DeleteFirstItem();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		if (IsEmpty())
			throw std::out_of_range("Queue is empty");
		return _MyList.GetItem(0);
	}

	T back()
	{
		if (IsEmpty())
			throw std::out_of_range("Queue is empty");
		return _MyList.Size()-1;
	}

	
	void Clear()
	{
		_MyList.Clear();
	}



};


