// Use Bucket sort to sort an array (vector). Here we assume that
// each element in the input array is bounded by a limit, say (Min, Max).
// We devidie it into N bucklets and sort them within bucket.

// It works great when the data is evenly distributed adn data inside the
// bucket is small.


#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using namespace std;


// Defines the data type, which can be c hanged ot any type.
// If you want to sort a list of string, instead of int, just
// change it here.
typedef float data;


const int N = 10; // Divide the data into 10 buckets


// Swap the data between position i and j, the vector is passed by reference.
void swap(vector<data>& input, int i, int j)
{
	assert(i<input.size() && i>=0); // Make sure, i is within bounds.
	assert(j<input.size() && j>=0); // Make sure, j is within bounds.

	const data t = input[i];
	input[i] = input[j];
	input[j] = t;
}


// An inefficient sorting but will work if the bcuket size is small.
// Note that the vector is passed by reference, not by value.
void sort(vector<data>& input)
{
	const int n = input.size();

	for(int i=n-1; i>0; --i)
		for(int j=0; j<i; ++j)
			if (input[j] > input[j+1])
				swap(input, j, j+1);
	return;
}
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
vector<data> bucketSort(vector<data>& input)
{
	if (input.size() <2) // If the array is empty or have 1 element,
		return input;          // then do nothing!

    const auto pair = getMaxMin(input); // Get max & min elements.
	const data max = pair.first;
	const data min = pair.second;
	
	const data delta = (max - min) / N; // The width of the bucket.
	vector<vector<data>> buckets(N, vector<data>());
	
	for(const auto& x: input)
	{
		// Calculate the bucket, and adjust for the case where x == Max
		int bucket = (x == max) ? N-1 : (x-min) / delta;

		// Place x into the appropriate bucket
		buckets[bucket].push_back(x);
	}

	int k = 0; // Index for output
	vector<data> output(input.size());
	for(auto& bucket : buckets)
	{
		sort(bucket); // Sort individual buckets.
		for(const auto& x: bucket)
			output[k++] = x; // Place data in output bucket.
	}
			
	return output;
}


/* ***** TEST CODE ***** */

int main(void)
{
	vector<data> input({1.0, 4.67, 2.23, 9.67, 3.98, 5.89, 0.98, 1.23});

	// Print before Sorting
	cout<<"Before Sorting:";
	for(const auto& x: input)
		cout<<" "<<x;
	cout<<endl;

	auto output = bucketSort(input); // Sort the input array (vector).
	
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