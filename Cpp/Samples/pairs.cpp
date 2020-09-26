// PROBLEM: Given a number and an array of numbers,
//   print all the pairs of numbers in the array
//   whose sum is the given number.

#include <iostream> 
#include <unordered_map> 
#include <list>
#include <utility>

using namespace std;

typedef int data; // Can be modified to include any type.
typedef list<pair<data, data>> pair_list;


// The function to calculate list of pairs from the input.
pair_list GetPairs(const list<data>& input, const data N)
{
  unordered_map<data, bool> map;
  pair_list result;

  // All the entries that are represented only once are
  // stored with their values being false and for
  // others, the value is true.
  for(auto& x: input)
    map[x] = (map.find(x) != map.end());


  // If the key is a=b=N/2 and both a & b are present in
  // the input or a<>B and both a & b are present, include
  // them in the result.
  for(auto& z: map)
  {
    const data a = z.first;
    const data b = N - z.first;

    if (((a == N/2) && z.second) ||
      ((a<N/2) && (map.find(b) != map.end())))
        result.push_back(make_pair(a, b));
  }
  return result;
}


// The main program to test the case.
int main() 
{
  for(auto& z: GetPairs({-1,-4,6,8,-10,2,0,2}, 4))
    cout<<"("<<z.first<<" , "<<z.second<<")"<<endl;
  return 0;
}
