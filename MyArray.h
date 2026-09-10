#ifndef MY_ARRAY_H
#define MY_ARRAY_H
#endif // MY_ARRAY_H

//This program is based on video "Constructors Destructors and Assignment Operators"

//A C++ class to manage a dynamically allocated array.


class MyArray {
public:
	MyArray();//Default Constructor
	//Rule of 3 is to define copy-constructor, destructor, and assignment operator (if you need to define any of them)
	MyArray(const MyArray& other);//Copy-Constructor
	~MyArray();//Destructor
	MyArray& operator=(const MyArray& other);//Assignment Operator

	void add_item(int value);//Add item to the end of the array (for simplicity)
	int get_size();//Get size
	int get_capacity();//Get capacity
	int get_value(int pos);//Get the value from a specific location

private:
	int* arr = nullptr;//Pointer to dynamically allocated integer array
	int size = 0;//Current of elements currently stored in the array
	int capacity = 0;//Number of elements that could be stored in the array
};