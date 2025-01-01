#include <iostream>
#include <string>
using namespace std;

bool isString(const string &input)
{
  for (size_t i = 0; i < input.length(); ++i)
  {
    if (input[i] == '0')
    {
      if (i + 2 >= input.length() || input[i + 1] != '1' || input[i + 2] != '1')
      {
        return false;
      }
      i += 2;
    }
    else if (input[i] != '1')
    {
      return false;
    }
  }
  return true;
}

int main()
{
  string test1 = "011011";
  string test2 = "0110110";
  string test3 = "1111";
  string test4 = "01";

  cout << "String \"" << test1 << "\" is "
       << (isString(test1) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test2 << "\" is "
       << (isString(test2) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test3 << "\" is "
       << (isString(test3) ? "Valid" : "Not Valid") << endl;

  cout << "String \"" << test4 << "\" is "
       << (isString(test4) ? "Valid" : "Not Valid") << endl;

  return 0;
}
