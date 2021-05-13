// PROBLEM: Given a string, convert it into a number.

#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>
#include <cctype>
#include <cstdlib>

using namespace std;


// Trim string of all leading & trailing white spaces.
string Trim(const string &str)
{
  int i = 0, j = 0;
  while (isspace(str[i]))
    i++;

  while (!isspace(str[i + j]))
    if ((i + j) == str.length() - 1)
      return str.substr(i);
    else
      j++;

  return str.substr(i, j);
}


// Convert a integer into string.
int Convert(const string &str)
{
  const string s = Trim(str);
  const int n = s.length();

  if (n == 0)
    throw runtime_error("Empty string");

  // Get the sign of the number.
  const bool sign = (s[0] != '-');

  // Set the starting position for digits.
  int p = ((s[0] == '+') || (s[0] == '-')) ? 1 : 0;

  while (s[p] == '0') // Trim all leading zeroes and
    p++;              // adjust start position.

  // Set the limit based on sign.
  const int limit = sign ? INT_MAX : INT_MIN;

  int result = 0;
  int exp = sign ? 1 : -1;
  for (int i = n - 1; i >= p; i--)
  {
    // Check if the digits are within bounds.
    if ((s[i] < '0') || (s[i] > '9'))
      throw runtime_error("Invalid format");

    // Check if there is more room to add,
    // then add else throw overflow exception.
    int delta = exp * (s[i] - '0');
    int diff = limit - result;
    if (sign ? (diff >= delta) : (diff <= delta))
      result += delta;
    else
      throw overflow_error("Integer overflow");

    // If the limit of # of digits have reached and
    // there are still more digits left to be processed,
    // then throw overflow exception.
    double ratio = ((double) limit) / exp;
    if ((ratio < (double) 10) && (i > p))
      throw overflow_error("Integer overflow");
    else
      exp *= 10;
  }

  return result;
}


// Test the input string by converting it into a number.
void test(const string& str)
{
  cout<<"\""<<str<<"\"\t-->\t";
  try { cout<<Convert(str)<<endl; }
  catch(const exception& e)
  { cout<<"EXCEPTION - "<<e.what()<<endl; }
}


// Main function that runs all the test cases.
int main(void) {
  test("+000002147483647");
  test("-0000002147483648");
  test("-0000002147483649");
  test("    02147483648  ");
  test("0000000000000000");
  test(" adfasfdgher ewr");
  return 0;
}
