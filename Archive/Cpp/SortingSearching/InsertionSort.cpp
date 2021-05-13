// Use Insertion sort to sort an array (vector).


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// Defines the data type, which can be c hanged ot any type.
// If you want to sort a list of string, instead of int, just
// change it here.
typedef int data;


// Swap the data between position i and j, the vector is passed
// by reference.
void swap(vector<data>& input, int i, int j)
{
	assert(i<input.size() && i>=0); // Make sure, i is within bounds.
	assert(j<input.size() && j>=0); // Make sure, j is within bounds.

	const data t = input[i];
	input[i] = input[j];
	input[j] = t;
}


// User insertion sort to sort an input array(vector).
// Note that the vector is passed by reference, not by value.
void insertionSort(vector<data>& input)
{
	const int n = input.size();

	for(int i=n-1; i>0; --i)
		for(int j=0; j<i; ++j)
			if (input[j] > input[j+1])
				swap(input, j, j+1);
	return;
}


/* ***** TEST CODE ***** */

int main(void)
{
	vector<data> input({5, 8, 2, 9, 1, 0, 10, 34, 23, 11});

	// Print before Sorting
	cout<<"Before Sorting:";
	for(const auto& x: input)
		cout<<" "<<x;
	cout<<endl;

	insertionSort(input); // Sort the input array (vector)
	
	// Print after Sorting
	cout<<"After  Sorting:";
	for(const auto& x: input)
		cout<<" "<<x;
	cout<<endl;

	// Check if indeed the array is sorted.
	for(int i=0; i<input.size()-1; i++)
		if (input[i] > input[i+1])
		{
			cerr<<"Out of order pairs at ("<<(i+1)<<", "<<i<<")"<<endl;
			return 1;
		}

	return 0;
}
