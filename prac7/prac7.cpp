#include<iostream>
#include<bits/stdc++.h>
using namespace std;

set<char> find_first(vector<string> grammar, set<char> terminals, char non_terminals, int index){
    set<char> st;
    set<char> st0;
    for(int i=0;i<grammar.size();i++){
        if(grammar[i][0]==non_terminals){
            if(terminals.find(grammar[i][index])!=terminals.end()){
                st.insert(grammar[i][index]);
            } //terminal
            else{
                if(grammar[i][3]=='_'){
                    st.insert('_');
                    return st;
                }
                else{
                    for(int j=index;j<grammar[i].size();j++){
                        set<char> st2;
                        st2 = find_first(grammar, terminals, grammar[i][j],j);
                        st.insert(st2.begin(),st2.end());
                    }
                }
            }//non terminal
        }
        st0.insert(st.begin(),st.end());
    }
    return st0;
}

/*
map<char,vector<char>> first(vector<string> grammar, vector<string> terminals, vector<string> non_terminals){
    map<char,vector<char>> fs;
    set<char> st;
    for(auto it=non_terminals.begin();it!=non_terminals.end();it++){
        for(int i=0;i<grammar.size();i++){
            if(grammar[i][0]==*it){
                if(terminals.find(grammar[i][3])!=terminals.end()){
                    st.insert(grammar[i][3]);
                } //terminal
                else{

                }//non terminal
            }
        }
    }
    return fs;
}
*/

int main()
{
    //map<char,vector<char>> p;
    vector<string> grammar = {"S->ABC","S->D","A->a","A->_","B->b","B->_","C->(S)","C->c","D->AC"};
    set<char> terminals;
    set<char> non_terminals;

    int n;
    /*cout<<"Add No. of Productions: ";
    cin>>n;*/
    string g;
    /*
    for(int i=0;i<n;i++){
        cout<<"Add Production "<<i+1<<": ";
        cin>>g;
        grammar.push_back(g);
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<grammar[i].size();j++){
            if(grammar[i][j]>='A' && grammar[i][j]<='Z'){
                non_terminals.insert(grammar[i][j]);
            }
            else if((grammar[i][j]>='a' && grammar[i][j]<='z')||(grammar[i][j]=='_')||(grammar[i][j]=='(')||(grammar[i][j]==')')){
                terminals.insert(grammar[i][j]);
            }
        }
    }
    terminals.insert('$');
    for(auto it = terminals.begin();it!=terminals.end();it++){
        cout<<*it<<" ";
    }
    cout<<"yuyu"<<endl;
    set<char> p = find_first(grammar,terminals,'D',3);
    for(auto it = p.begin();it!=p.end();it++){
        cout<<*it<<" ";
    }
}