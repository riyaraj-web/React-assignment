// Suffix Automaton - builds automaton for a string and checks substring existence
#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
    struct State{ int len, link; array<int,26> next; State(){len=0;link=-1; next.fill(-1);} }; 
    vector<State> st; int last;
    SuffixAutomaton(){ st.reserve(2e5); st.push_back(State()); last=0; }
    void extend(char ch){ int c=ch-'a'; int cur=st.size(); st.push_back(State()); st[cur].len=st[last].len+1; int p=last;
        for(; p!=-1 && st[p].next[c]==-1; p=st[p].link) st[p].next[c]=cur;
        if(p==-1) st[cur].link=0;
        else{ int q=st[p].next[c]; if(st[p].len+1==st[q].len) st[cur].link=q; else{
            int clone=st.size(); st.push_back(st[q]); st[clone].len=st[p].len+1; 
            for(; p!=-1 && st[p].next[c]==q; p=st[p].link) st[p].next[c]=clone;
            st[q].link=st[cur].link=clone;
        }} last=cur;
    }
    bool contains(const string &s){ int v=0; for(char ch: s){ int c=ch-'a'; if(st[v].next[c]==-1) return false; v=st[v].next[c]; } return true; }
};

int main(){
    string text = "ababa"; SuffixAutomaton sa; for(char c: text) sa.extend(c);
    vector<string> queries = {"aba","bab","ab","ac"};
    for(auto &q: queries) cout<<q<<" -> "<<(sa.contains(q)?"YES":"NO")<<"\n";
    return 0;
}
