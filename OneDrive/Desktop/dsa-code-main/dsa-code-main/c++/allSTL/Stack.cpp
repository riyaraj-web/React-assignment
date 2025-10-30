#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    stack<int> st;
    st.push(1765);
    st.push(1343);
    st.push(341);
    st.push(13);
    st.push(14);

    while(st.empty() == false){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}