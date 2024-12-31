#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DFA
{
public:
  int nSymbol;
  vector<char> symbol;
  int nStates;
  vector<int> states;
  int initState;
  int nFinal;
  vector<int> finalState;
  vector<vector<int>> trans;

  DFA() {}

  void set()
  {
    cout << "Add No. of Input Symbol: ";
    cin >> nSymbol;

    char c;
    for (int i = 0; i < nSymbol; i++)
    {
      cout << "Add Symbols: ";
      cin >> c;
      symbol.push_back(c);
    }

    cout << "Add No. of States: ";
    cin >> nStates;
    cout << "Add Initial State: ";
    cin >> initState;
    cout << "Add no. of Final states: ";
    cin >> nFinal;
    int p;
    for (int i = 0; i < nFinal; i++)
    {
      cout << "Add Accepting states: ";
      cin >> p;
      finalState.push_back(p);
    }
    cout << "Add Transition Function: " << endl;
    vector<int> temp(nSymbol);
    for (int i = 0; i < nStates; i++)
    {
      for (int j = 0; j < nSymbol; j++)
      {
        cout << i + 1 << " to " << symbol[j] << "-> ";
        cin >> temp[j];
      }
      trans.push_back(temp);
    }
  }
  void get()
  {
    cout << "Symbols: ";
    for (int i = 0; i < nSymbol; i++)
    {
      cout << symbol[i];
    }
    for (int i = 0; i < nStates; i++)
    {
      for (int j = 0; j < nSymbol; j++)
      {
        cout << i + 1 << " to " << symbol[j] << "-> " << trans[i][j] << endl;
      }
    }
  }
  void AcceptString(string g)
  {
    int curr = initState;
    bool p = true;
    cout << "Input String: " << g << endl;
    for (int i = 0; i < g.size(); i++)
    {
      for (int j = 0; j < symbol.size(); j++)
      {
        if (g[i] == symbol[j])
        {
          curr = trans[curr - 1][j];
          cout << curr << endl;
        }
      }
    }
    cout << curr;

    for (int i = 0; i < nFinal; i++)
    {
      if (curr == finalState[i])
      {
        cout << "Valid";
        return;
      }
    }
    cout << "Invalid";
  }
};

int main()
{
  DFA d;
  d.set();
  // d.get();
  d.AcceptString("ab");
  return 0;
}