// Use Merge sort to sort an array (vector).


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// Defines the data type, which can be c hanged ot any type.
// If you want to sort a list of string, instead of int, just
// change it here.
typedef int data;


void mergeSort(vector<data>& input)
{
	const int N = input.size();

	if (N<2) // If empty or only 1 element, do nothing!
		return;

	const int n1 = (int) (N/2);
	const int n2 = N - n1;

	vector<data> subArray1 = vector<data>(n1);
	vector<data> subArray2 = vector<data>(n2);

	for(int i=0; i<n1; i++)
		subArray1[i] = input[i];
	
	for(int i=0; i<n2; i++)
		subArray2[i] = input[n1 + i];

	mergeSort(subArray1);
	mergeSort(subArray2);

	// Merge the two subarrays
	int i=0, j=0, k=0;
	while ((i < n1) && (j < n2))
		if (subArray1[i] > subArray2[j])
			input[k++] = subArray2[j++];
		else
			input[k++] = subArray1[i++];

	// Merge whatever is remaining in sub array 1.
	for(int t=i; t<n1; t++)
		input[k++] = subArray1[t];

	// Merge whatever is remaining in sub array 2.
	for(int t=j; t<n2; t++)
		input[k++] = subArray2[t];

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

	mergeSort(input); // Sort the input array (vector)
	
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

