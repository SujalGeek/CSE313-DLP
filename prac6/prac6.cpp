#include <bits/stdc++.h>
using namespace std;

map<char, set<char>> first, follow;
map<char, vector<string>> grammar;
char startSymbol;

void computeFirst(char symbol) {
    if (!first[symbol].empty()) return;

    for (string rule : grammar[symbol]) {
        if (!isupper(rule[0]) || rule[0] == '#') {
            first[symbol].insert(rule[0]);
        } else {
            for (char ch : rule) {
                computeFirst(ch);
                first[symbol].insert(first[ch].begin(), first[ch].end());
                if (first[ch].count('#') == 0) break;
                first[symbol].erase('#');
            }
        }
    }
}

void computeFollow(char symbol) {
    if (!follow[symbol].empty()) return;
    if (symbol == startSymbol) follow[symbol].insert('$');

    for (auto &[lhs, rules] : grammar) {
        for (string rule : rules) {
            for (size_t i = 0; i < rule.size(); i++) {
                if (rule[i] == symbol) {
                    bool nullable = true;
                    for (size_t j = i + 1; j < rule.size(); j++) {
                        computeFirst(rule[j]);
                        follow[symbol].insert(first[rule[j]].begin(), first[rule[j]].end());
                        if (first[rule[j]].count('#') == 0) {
                            nullable = false;
                            break;
                        }
                        follow[symbol].erase('#');
                    }
                    if (nullable && lhs != symbol) {
                        computeFollow(lhs);
                        follow[symbol].insert(follow[lhs].begin(), follow[lhs].end());
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    set<char> non_terminals;
    for (int i = 0; i < n; i++) {
        string prod;
        cout << "Enter productions (e.g., S->AB|a): ";
        cin >> prod;
        if (i == 0) startSymbol = prod[0];
        non_terminals.insert(prod[0]);
        string rhs = prod.substr(3);
        grammar[prod[0]].push_back(rhs);
    }

    for(auto it = non_terminals.begin();it!=non_terminals.end();it++){
        //cout<<*it<<" ";
        for(auto it1=grammar[*it].begin();it1!=grammar[*it].end();it1++){
            cout<<*it1<<" ";
        }
        computeFirst(*it);
    }
    for(auto it = non_terminals.begin();it!=non_terminals.end();it++){
        computeFollow(*it);
    }

    cout << "\nFIRST:\n";
    for (auto &[symbol, s] : first) {
        cout << symbol << " : { ";
        for (char c : s) cout << c << " ";
        cout << "}\n";
    }

    cout << "\nFOLLOW:\n";
    for (auto &[symbol, s] : follow) {
        cout << symbol << " : { ";
        for (char c : s) cout << c << " ";
        cout << "}\n";
    }

    return 0;
}
