// Use Quick sort to sort an array (vector).


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


// Choose a pivot and align the elements on the left & right of pivot.
int partition(vector<data>& input, int p,int r)
{
	int q=p;

	const data x = input[r]; // Choose a pivot

	for(int i = p; i<r; ++i)
		if (input[i] <= x)
		{
			swap(input, i, q);
			q++;	
		}

	swap(input, q, r);
	return q;
}


// The main function that does the sorting.
void quickSortHelper(vector<data>& input, int p, int r)
{
	if (p>=r) // If the input positions are criss-crossed, do nothing!
		return;

	const int q = partition(input, p,r);
	quickSortHelper(input, p, q-1);
	quickSortHelper(input, q+1,r);

	return;
}


// Entry point to sort a vector.
void quickSort(vector<data>& input)
{
	quickSortHelper(input, 0, input.size()-1);
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

	quickSort(input); // Sort the input array (vector)
	
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