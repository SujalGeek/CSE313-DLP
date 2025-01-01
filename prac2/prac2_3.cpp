#include <iostream>
#include <string>

using namespace std;
bool stringmatching(const string &input)
{
  if (input.length() == 0)
  {
    return false; // Empty string is invalid
  }
  return input[0] == input[input.length() - 1];
}

int main()
{
  // Test cases
  string test1 = "abcba";
  string test2 = "baccb";
  string test3 = "abc";
  string test4 = "";
  string test5 = "c";

  cout << "String \"" << test1 << "\" is "
       << (stringmatching(test1) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test2 << "\" is "
       << (stringmatching(test2) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test3 << "\" is "
       << (stringmatching(test3) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test4 << "\" is "
       << (stringmatching(test4) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test5 << "\" is "
       << (stringmatching(test5) ? "Valid" : "Not Valid") << endl;

  return 0;
}
