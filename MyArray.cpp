//This program is based on video "Constructors Destructors and Assignment Operators"

#include "MyArray.h"

MyArray::MyArray() {
	capacity = 10;
	size = 0;//Though already initialized by the header, but repeated here again for clarity/readability
	arr = new int[capacity];
	
}//Default Constructor
MyArray::MyArray(const MyArray& other) {
//Initialize the new array to a deep copy of the other array being passed in.
		
	this->capacity = other.capacity;
	this->size = other.size;
	this->arr = new int[this->capacity];//Could also use other.capacity as well. They are the same since you set them to be equal earlier.

	*(this->arr) = *other.arr;

	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	

}//Copy-Constructor

MyArray::~MyArray() {

}//Destructor

MyArray& MyArray::operator=(const MyArray& other) {
	return *this;
}//Assignment Operator

void MyArray::add_item(int value) {
	arr[size++] = value;//update the size after adding the value to the array	
}

void MyArray::set_item(int pos, int value) {
	//Note: We would need error checking needs to be added if pos<0, if pos is outside the bounds of the array, if pos > size, etc. But for this example we won't add all the error checking.

	arr[pos] = value;
}

int MyArray::get_size() {
	return size;
}

int MyArray::get_capacity() {
	return capacity;
}

int MyArray::get_value(int pos) {
	
	return arr[pos];
}