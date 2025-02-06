#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

const char *keywords[] = {"int", "char", "return", "if", "else", "while", "for", "float", "double", "void", "main"};
const char operators[] = "+-*/=<>!&|";
const char punctuations[] = "();{},";
const int MAX_IDENTIFIERS = 100;

char symbolTable[MAX_IDENTIFIERS][20];
int identifierCount = 0;

int keywordCount = 0, identifierCnt = 0, constantCount = 0, stringCount = 0, operatorCount = 0, punctuationCount = 0, errorCount = 0;

bool isKeyword(const char *word)
{
  for (int i = 0; i < 11; i++)
  {
    if (strcmp(word, keywords[i]) == 0)
      return true;
  }
  return false;
}

bool isOperator(char c)
{
  for (int i = 0; i < strlen(operators); i++)
  {
    if (c == operators[i])
      return true;
  }
  return false;
}

bool isPunctuation(char c)
{
  for (int i = 0; i < strlen(punctuations); i++)
  {
    if (c == punctuations[i])
      return true;
  }
  return false;
}

void addIdentifier(const char *word)
{
  for (int i = 0; i < identifierCount; i++)
  {
    if (strcmp(symbolTable[i], word) == 0)
      return;
  }
  strcpy(symbolTable[identifierCount++], word);
}

void processFile(const char *filename)
{
  ifstream file(filename);
  if (!file)
  {
    cout << "Error opening file!" << endl;
    return;
  }

  char ch, word[20];
  int index = 0;
  bool inString = false, inComment = false, inSingleComment = false;

  while (file.get(ch))
  {
    if (inSingleComment)
    {
      if (ch == '\n')
        inSingleComment = false;
      continue;
    }

    if (inComment)
    {
      if (ch == '*' && file.peek() == '/')
      {
        file.get(ch);
        inComment = false;
      }
      continue;
    }

    if (ch == '/' && file.peek() == '*')
    {
      file.get(ch);
      inComment = true;
      file.get(ch);
      continue;
    }

    if (ch == '/' && file.peek() == '/')
    {
      file.get(ch);
      inSingleComment = true;
      continue;
    }

    if (ch == '"')
    {
      inString = !inString;
      stringCount++;
      continue;
    }

    if (ch == '\'')
    {
      char nextChar = file.get();
      if (file.peek() == '\'')
      {
        file.get();
        cout << "String: '" << nextChar << "'" << endl;
        stringCount++;
      }
      else
      {
        cout << "Lexical Error: '" << nextChar << "'" << endl;
        errorCount++;
      }
      continue;
    }

    if (inString)
      continue;

    if (isalnum(ch) || ch == '_')
    {
      word[index++] = ch;
    }
    else
    {
      if (index > 0)
      {
        word[index] = '\0';
        index = 0;

        bool isNumber = true;
        for (int i = 0; word[i] != '\0'; i++)
        {
          if (!isdigit(word[i]))
          {
            isNumber = false;
            break;
          }
        }

        if (isKeyword(word))
        {
          cout << "Keyword: " << word << endl;
          keywordCount++;
        }
        else if (isNumber)
        {
          cout << "Constant: " << word << endl;
          constantCount++;
        }
        else if (isdigit(word[0]) && !isNumber)
        {
          cout << "Lexical Error: " << word << endl;
          errorCount++;
        }
        else
        {
          cout << "Identifier: " << word << endl;
          addIdentifier(word);
          identifierCnt++;
        }
      }

      if (isOperator(ch))
      {
        cout << "Operator: " << ch << endl;
        operatorCount++;
      }
      else if (isPunctuation(ch))
      {
        cout << "Punctuation: " << ch << endl;
        punctuationCount++;
      }
      else if (!isspace(ch))
      {
        cout << "Lexical Error: " << ch << endl;
        errorCount++;
      }
    }
  }

  file.close();
}

void print()
{
  cout << "\nSummary:\n";
  cout << "Keywords: " << keywordCount << endl;
  cout << "Identifiers: " << identifierCnt << endl;
  cout << "Constants: " << constantCount << endl;
  cout << "Strings: " << stringCount << endl;
  cout << "Operators: " << operatorCount << endl;
  cout << "Punctuation: " << punctuationCount << endl;
  cout << "Lexical Errors: " << errorCount << endl;

  cout << "\nSymbol Table Entries:\n";
  for (int i = 0; i < identifierCount; i++)
  {
    cout << i + 1 << ") " << symbolTable[i] << endl;
  }
}

int main()
{
  const char *filename = "test.c";
  processFile(filename);
  print();
  return 0;
}
