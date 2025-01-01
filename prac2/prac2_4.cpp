#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool alphabet(const string &input)
{
  if (input.empty())
  {
    return false;
  }
  return isalpha(input[0]) && islower(input[0]);
}

int main()
{
  // Test cases
  string test1 = "abc123";
  string test2 = "1abc";
  string test3 = "Aabc";
  string test4 = "";
  string test5 = "z9x8";

  cout << "String \"" << test1 << "\" is "
       << (alphabet(test1) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test2 << "\" is "
       << (alphabet(test2) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test3 << "\" is "
       << (alphabet(test3) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test4 << "\" is "
       << (alphabet(test4) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test5 << "\" is "
       << (alphabet(test5) ? "Valid" : "Not Valid") << endl;

  return 0;
}
