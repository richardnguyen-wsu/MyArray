//This program is based on video "Constructors Destructors and Assignment Operators"

#include "MyArray.h"

MyArray::MyArray() {
	capacity = 10;
	size = 0;//Though already initialized by the header, but repeated here again for clarity/readability
	arr = new int[capacity];
	
}//Default Constructor
MyArray::MyArray(const MyArray& other) {
//Copy-Constructor
//Initialize the new array to a deep copy of the other array being passed in.
	
	//Copy the array
	copy_array(other);


}

MyArray::~MyArray() {
//Destructor
	//Delete the array
	delete_array();	

}

MyArray& MyArray::operator=(const MyArray& other) {
//Assignment Operator
	//Check for self-assignment
	if (this != &other) //check the address the pointer is pointing to vs the address of the other object
	{
		//Clean up existing memory
		delete_array();
				
		//Copy the array
		copy_array(other);
	}

	return *this;
}
void MyArray::copy_array(const MyArray& other)
{
	//Deep copy code

	this->capacity = other.capacity;
	this->size = other.size;

	this->arr = new int[other.capacity];//You could also use this->capacity instead, as well. They are the same since you just set them to be equal.

	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}
void MyArray::delete_array()
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;//The professor set the pointer to nullptr outside the if statement, but I think it should go inside and ChatGPT agrees.
	}
	//It's best practice to set size and capacity of the array to zero when you delete the array using the helper function in case you call the helper function elsewhere (where you aren't destroying the object using the destructor or you aren't setting size and capacity to something else right after you delete the array like with the overloaded assignment operator).
	size = 0;
	capacity = 0;
}
void MyArray::add_item(int value) {
	//In the quick class example, the professor didn't check to see if size == capacity, else you have to resize.
	arr[size++] = value;//update the size after adding the value to the array	
}
void MyArray::set_item(int pos, int value) {
	//Note: We should have error checking to check if pos<0, if pos is outside the bounds of the array (i.e. pos > capacity), if pos > size, etc. But for this example we won't add all the error checking.

	arr[pos] = value;
}

int MyArray::get_size() {
	return size;
}

int MyArray::get_capacity() {
	return capacity;
}

int MyArray::get_value(int pos) {
	//Note: We should have error checking to check if pos<0, if pos is outside the bounds of the array (i.e. pos > capacity), if pos > size, etc. But for this example we won't add all the error checking.

	return arr[pos];
}