/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  d65yang@uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  Fall 201N
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include <iostream>
using namespace std;


class Dynamic_stack {

	private:
		int *array;
		int count;		
		int array_size;
		int initial_size;
	
	public:
		Dynamic_stack(int = 10);
		~Dynamic_stack();

		int top() const;
		int size() const;
		bool empty() const;
		int capacity() const;
			
		void push( int const & );
		int pop();
		void clear();		
};

Dynamic_stack::Dynamic_stack( int n ):
count( 0 ),
array_size( n ),
initial_size(n)
{
	array = new int[array_size];
}


Dynamic_stack::~Dynamic_stack() {
	delete[] this -> array;
}


int Dynamic_stack::top() const {
	if (count == 0) {
		throw underflow();
	}
	return this -> array[count - 1];
}


int Dynamic_stack::size() const {
	return this -> count;
}


bool Dynamic_stack::empty() const {
	if (this -> count == 0){
		return true;
	}
	return false;  
}


int Dynamic_stack::capacity() const {
	return this -> array_size;
}


void Dynamic_stack::push( int const &obj ) {
	if (this -> array_size != this -> count) {
		this -> array[count] = obj;
		count++;
	} else {
		int* newArray = new int[(this -> array_size * 2)];
		for (int i = 0; i < this -> array_size; i++) {
			newArray[i] = this -> array[0];
		}
		this -> array_size = this -> array_size * 2;
		this -> array[count] = obj;
		count++;
	}
}


int Dynamic_stack::pop() {
	if (count == 0){
		throw underflow();
	} else {
		count--;
		return this -> array[count];
	}
}

void Dynamic_stack::clear() {
	this -> count = 0;
	if (this -> array_size != this -> initial_size) {
		delete [] this -> array;
		this -> array = new int[this -> initial_size];
	}
}
#endif