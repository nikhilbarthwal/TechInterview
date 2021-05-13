// Use Heap sort to sort an array (vector).


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
	assert(i<=input.size() && i>0); // Make sure, i is within bounds.
	assert(j<=input.size() && j>0); // Make sure, j is within bounds.

	const data t = input[i-1];
	input[i-1] = input[j-1];
	input[j-1] = t;
}


// Heapify a subtree below i.
void heapify(vector<data>& input, int i, int n)
{
	if (2*i>n) return; // Left & Right does not exists

	if (2*i+1>n) // if Right does not exists
	{
		if (input[2*i-1] > input[i-1])
		{
			// Swap left & root and max heapify
			swap(input, i, 2*i);
			heapify(input, 2*i, n);
		}
	}
	else // Right & Left exists
	{
		if ((input[i-1] < input[2*i-1]) || (input[i-1] < input[2*i]))
			if (input[2*i-1] > input[2*i]) // Left is greater than right
			{
				swap(input, i, 2*i);
				heapify(input, 2*i, n);
			}
			else
			{
				swap(input, i, 2*i+1);
				heapify(input, 2*i+1, n);
			}
	}

	return;
}


void heapSort(vector<data>& input)
{
	const int N = input.size();

	// Build the Max heap.
	for(int i=(int) (N/2); i>0; i--)
		heapify(input, i, N);

	for(int i=N; i>1; i--)
	{
		swap(input, 1, i);
		heapify(input, 1, i-1);
	}
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

	heapSort(input); // Sort the input array (vector)
	
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
