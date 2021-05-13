// Use Counting sort to sort an array (vector). Here we assume that
// each element in the input array is bounded by a limit, say (Min, Max).


#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using namespace std;


// Defines the data type, which can be c hanged ot any type.
// If you want to sort a list of string, instead of int, just
// change it here.
typedef char data;


// The main function that returns the sorted array/vector.
pair<data, data> getMaxMin(const vector<data>& input)
{
	assert(input.size() > 0);
	data Max = input[0];
	data Min = input[0];
	for(const auto& x: input)
	{
		if (x > Max)
			Max = x;
		if (x < Min)
			Min = x;
	}
	return make_pair(Max, Min);
}


// The main function that returns the sorted array/vector.
vector<data> countingSort(vector<data>& input)
{
	if (input.size() <2) // If the array is empty or have 1 element,
		return input;          // then do nothing!

    const auto pair = getMaxMin(input); // Get max & min elements.
	const data max = pair.first;
	const data min = pair.second;

	// Counter to keep a count of element but initialized to 0.
	const int size = max - min + 1;
	vector<int> counter(size, 0);
	
	for(const auto& x: input)
		counter[x - min]++;

	int k=0;
	vector<data> output(input.size());
	for(int i=0; i<size; i++)
		for(int j=0; j<counter[i]; j++)
		{
			// Make sure k is within vector bounds.
			assert(k < input.size());
			output[k++] = i + min;
		}
			
	return output;
}


/* ***** TEST CODE ***** */

int main(void)
{
	vector<data> input({'f', 'y', 'a', 'p', 'e', 'r', 'a', 't'});

	// Print before Sorting
	cout<<"Before Sorting:";
	for(const auto& x: input)
		cout<<" "<<x;
	cout<<endl;

	auto output = countingSort(input); // Sort the input array (vector).
	
	// Print after Sorting
	cout<<"After  Sorting:";
	for(const auto& x: output)
		cout<<" "<<x;
	cout<<endl;

	// Check if indeed the array is sorted.
	for(int i=0; i<output.size()-1; i++)
		if (output[i] > output[i+1])
		{
			cerr<<"Out of order pairs at ("<<(i+1)<<", "<<i<<")"<<endl;
			return 1;
		}

	return 0;
}