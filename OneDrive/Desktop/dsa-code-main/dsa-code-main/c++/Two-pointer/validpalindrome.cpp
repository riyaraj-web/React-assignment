#include<bits/stdc++.h>
#define ll long long int 
using namespace std;


bool alphanumeric(char ch){
        if((ch>='0'&&ch<='9')||(tolower(ch)>='a'&& tolower(ch)<='z')){
            return true;
        }
        return false;
}

bool isPalindrome(string s) {
      int st=0; int e=s.size()-1;
       while(st<=e){
        if(!alphanumeric(s[st])){
            st++; continue;
        }
        if(!alphanumeric(s[e])){
            e--; continue;
        }
        if(tolower(s[st])!=tolower(s[e])){
            return false;
        }
        st++; e--;
      }
      return true;
}

signed main(){
    ios::sync_with_stdio(false);
cin.tie(NULL);
string s;
getline(cin,s);
if(isPalindrome(s)){
    cout<<"true"<<endl;
}
else{
    cout<<"false"<<endl;
}  
}
