#pragma once
#include<iostream>
template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;


public:
	T* OriginalArray;

	
	clsDynamicArray(int Size=0) {
		if (Size < 0) {
			_Size = 0;
		}
		_Size = Size;
		OriginalArray = new T[_Size];
	}
	~clsDynamicArray() {
		delete[] OriginalArray;
	}


	bool SetItem(int index, T value) {
		if (index >= _Size || index < 0) {
			return false;
		}
		OriginalArray[index] = value;
		return true;
	}

	bool IsEmpty() {
		return _Size == 0;
	}
	int Size() {
		return _Size;
	}

	void PrintList() {
		for (int i = 0; i < _Size; i++) 
		{
			std::cout << OriginalArray[i] << " ";

		}
		std::cout << "\n";
		
	}

	void Resize(int newSize) {
		if (newSize < 0) {
			newSize = 0;
		}
		_TempArray = new T[newSize];

		if (newSize < _Size) {
			_Size = newSize;
		}
		for (int i = 0; i < _Size; i++) {
			_TempArray[i] = OriginalArray[i];

		}
		_Size = newSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}


	T GetItem(int index) {
		if (_Size <= index || index < 0) {
			return NULL;
		}
		return OriginalArray[index];
	}

	void Reverse() {
		_TempArray = new T[_Size];
		int counter = 0;
		for (int i = _Size-1; i >=0; i--) {
			_TempArray[counter] = OriginalArray[i];
			counter++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear() {
		_Size = 0;
		_TempArray = new T[0];
		
		delete[]OriginalArray;
		OriginalArray = _TempArray;
		

	}

	bool DeleteItemAt(int index) {
		if (_Size <= index || index < 0) {
			return false;
		}

		_Size--;
		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++) {
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = index + 1; i < _Size + 1; i++) {
			_TempArray[i-1] = OriginalArray[i];
		}


		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	bool DeleteFirstItem() {
		return DeleteItemAt(0);
	}
	bool DeleteLastItem() {
		return DeleteItemAt(_Size-1);

	}

	int Find(T itemValue) {
		for (int i = 0; i < _Size; i++) {
			if (itemValue == OriginalArray[i]) {
				return i;
			}
		}
		return -1;
	}
	bool DeleteItem(T itemValue) {
		int itemIndex = Find(itemValue);
		if (itemIndex != -1) {
			DeleteItemAt(itemIndex);
			return true;
		}
		return false;
	}

	bool InsertAt(int index, T value) {
		if (_Size < index || index < 0) {
			return false;
		}
		_Size++;
		_TempArray = new T[_Size ];

		for (int i = 0; i < index; i++) {
			_TempArray[i] = OriginalArray[i];
		}
		_TempArray[index] = value;
		for (int i = index ; i < _Size; i++) {
			_TempArray[i + 1] = OriginalArray[i ];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}
	void InsertAtBeginning(T value) {
		InsertAt(0, value);
	}
	void InsertAtEnd(T value) {
		
		InsertAt(_Size, value);
	}
	bool InsertBefore(int index,T value) {
		if (index < 1) {
			
			return InsertAt(0, value);

		}
		return InsertAt(index-1, value);
	}
	bool InsertAfter(int index,T value) {
		if (index >= _Size) {
			return InsertAt(_Size, value);
		}
		return InsertAt(index + 1, value);
	}
};

