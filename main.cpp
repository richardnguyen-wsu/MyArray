#include<iostream>//For cout, endl, etc.
#include "MyArray.h"

using std::cout;
using std::endl;


//This program is based on video "Constructors Destructors and Assignment Operators"
//main.cpp is the test driver file

int main() {


	MyArray array1;//Will invoke default constructor since there are no parameters
	//To have better test coverage, add_item() should be tested. But for this simple example, we will skip this test.
	array1.add_item(1);//Value 1 at position 0
	array1.add_item(5);//Value 5 at position 1
	array1.add_item(2);//Value 2 at position 2
	//array1 size should be 3
	cout << "Array Size: " << array1.get_size() << endl;
	//array1 capacity should be 10
	cout << "Array Capacity: " << array1.get_capacity() << endl;
	//Invoke the copy constructor
	MyArray array2(array1);
	//Check to see array2 has values from array1
	cout << "array2 values: " << array2.get_value(0) << " " << array2.get_value(1);
	cout << " " << array2.get_value(2) << endl;

	//To check if it was doing a shallow copy or deep copy
	array1.set_item(1, 7);
	cout << "array2 values after changing array1: " << array2.get_value(0) << " " << array2.get_value(1);
	cout << " " << array2.get_value(2) << endl;

	//To force the destructor to be invoke, create a dynamically allocated instance of the class.
	MyArray* aptr = new MyArray();//a pointer to point to the dynamically allocated array object
	aptr->add_item(8);
	aptr->add_item(3);
	cout << "aptr values: " << aptr->get_value(0) << " " << aptr->get_value(1) << endl;
	//Use assignment operator to copy aptr to array2
	array2 = *aptr;
	//Check to see array2 has values from aptr
	cout << "array2 values: " << array2.get_value(0) << " " << array2.get_value(1) << endl;

	//Invoke destructor on dynamically allocated array
	delete aptr;

	//Check to see that array2 still exists
	array2.add_item(9);
	cout << "array2 values after deleting aptr: " << array2.get_value(0) << " " << array2.get_value(1);
	cout << " " << array2.get_value(2) << endl;


	return 0;
}