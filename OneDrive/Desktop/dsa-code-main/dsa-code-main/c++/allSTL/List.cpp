#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> ls = {2,3};
    ls.push_front(1);
    for(auto i: ls){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<ls.front();
    
    return 0;
}