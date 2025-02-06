#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <vector>
#include <unordered_set>
using namespace std;

// Define keywords in C++

// all 32 keyowrds in C++ should be stored in the above unordered_set
unordered_set<string> keywords = {
    "int",
    "char",
    "return",
    "if",
    "else",
    "for",
    "while",
    "break",
    "continue",
    "switch",
    "case",
    "default",
    "do",
    "double",
    "float",
    "long",
    "register",
    "short",
    "sizeof",
    "typedef",
    "unsigned",
    "void",
    "volatile",
    "auto",
    "const",
    "enum",
    "extern",
    "goto",
    "static",
    "struct",
    "union",
    "signed",
    "bool",
    "main",
};

unordered_set<string> arithmetic_operators = {"+", "-", "*", "/", "%"};
unordered_set<string> relational_operators = {"==", "!=", "<", ">", "<=", ">="};
unordered_set<string> logical_operators = {"&&", "||", "!"};
unordered_set<string> assignment_operators = {"=", "+=", "-=", "*=", "/=", "%="};

unordered_set<char> punctuations = {'(', ')', '{', '}', ',', ';'};

regex identifier_pattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
regex number_pattern("^[0-9]+$");
regex char_pattern("^'.'$");

regex single_line_comment("//.*");
regex multi_line_comment("/\\*.*?\\*/");

void mylex(const string &code)
{
  vector<string> tokens;
  vector<string> lerror;
  vector<string> symbol_table;
  vector<string> comments;

  sregex_iterator it(code.begin(), code.end(), single_line_comment);
  sregex_iterator end;
  while (it != end)
  {
    comments.push_back(it->str());
    it++;
  }

  it = sregex_iterator(code.begin(), code.end(), multi_line_comment);
  while (it != end)
  {
    comments.push_back(it->str());
    it++;
  }

  string filtered_code = regex_replace(code, single_line_comment, "");
  filtered_code = regex_replace(filtered_code, multi_line_comment, "");

  istringstream stream(filtered_code);
  string token;

  while (stream >> token)
  {
    if (keywords.count(token))
    {
      tokens.push_back("Keyword: " + token);
    }
    else if (arithmetic_operators.count(token))
    {
      tokens.push_back("Arithmetic Operator: " + token);
    }
    else if (relational_operators.count(token))
    {
      tokens.push_back("Relational Operator: " + token);
    }
    else if (logical_operators.count(token))
    {
      tokens.push_back("Logical Operator: " + token);
    }
    else if (assignment_operators.count(token))
    {
      tokens.push_back("Assignment Operator: " + token);
    }
    else if (punctuations.count(token[0]))
    {
      tokens.push_back("Punctuation: " + token);
    }
    else if (regex_match(token, number_pattern))
    {
      tokens.push_back("Constant: " + token);
    }
    else if (regex_match(token, char_pattern))
    {
      tokens.push_back("String: " + token);
    }
    else if (regex_match(token, identifier_pattern))
    {
      tokens.push_back("Identifier: " + token);
      if (find(symbol_table.begin(), symbol_table.end(), token) == symbol_table.end())
      {
        symbol_table.push_back(token);
      }
    }
    else
    {
      lerror.push_back(token + " invalid lexeme");
    }
  }

  cout << "TOKENS\n";
  for (const auto &t : tokens)
    cout << t << endl;

  cout << "\nLEXICAL ERRORS\n";
  for (const auto &e : lerror)
    cout << e << endl;

  cout << "\nSYMBOL TABLE ENTRIES\n";
  for (size_t i = 0; i < symbol_table.size(); ++i)
  {
    cout << i + 1 << ") " << symbol_table[i] << endl;
  }

  cout << "\nCOMMENTS\n";
  for (const auto &c : comments)
    cout << c << endl;
}

int main()
{
  ifstream file("input.cpp"); // Read from a file
  if (!file)
  {
    cerr << "Error opening file!" << endl;
    return 1;
  }

  string code((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
  file.close();

  mylex(code);
  return 0;
}
