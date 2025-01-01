#include <iostream>
#include <string>

using namespace std;

bool isValidFA(const string &input)
{
  int currentState = 1;

  for (char symbol : input)
  {
    if (symbol == 'a')
    {

      if (currentState == 1)
        currentState = 2;
      else if (currentState == 2)
        currentState = 1;
      else if (currentState == 3)
        currentState = 4;
      else if (currentState == 4)
        currentState = 3;
    }
    else if (symbol == 'b')
    {
      if (currentState == 1)
        currentState = 3;
      else if (currentState == 2)
        currentState = 4;
      else if (currentState == 3)
        currentState = 1;
      else if (currentState == 4)
        currentState = 2;
    }
    else
    {
      return false;
    }
  }

  return (currentState == 2);
}

int main()
{
  string test1 = "abbabab";
  string test2 = "ab";
  string test3 = "aaaa";
  string test4 = "abba";

  // Validate test cases
  cout << "String \"" << test1 << "\" is "
       << (isValidFA(test1) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test2 << "\" is "
       << (isValidFA(test2) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test3 << "\" is "
       << (isValidFA(test3) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test4 << "\" is "
       << (isValidFA(test4) ? "Valid" : "Not Valid") << endl;

  return 0;
}
