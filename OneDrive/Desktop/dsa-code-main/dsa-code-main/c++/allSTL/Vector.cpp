#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

  vector<int> vec;
  vec.push_back(54);
  vec.push_back(0);
  vec.emplace_back(523);
  cout<<vec.size()<<endl; // 3
  //simple way to print vec el
  for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<" "; // 54 0 523 
  }

  cout<<endl;
  
  // iterator
  vector<int>:: iterator beginItr = vec.begin();
  vector<int>:: iterator endItr = vec.end();
   for(vector<int>:: iterator i = beginItr; i<endItr; i++){
    cout << *i <<" "; // 54 0 523 
   }

  cout<<endl;

   //better way with "auto" (automatically identifies the datatype of vec)
   vector<int> vec2 = {3,5,6};
   
   auto bvec2 = vec2.begin();
   auto evec2 = vec2.end();
   for(auto i=bvec2; i<evec2; i++){
    cout<< *i<<" "; // 54 0 523 
  }
  
  //more advanced way with for each


  for(auto i: vec){
    cout<< i <<" "; // 3 5 6 54 0 523  
  }

  cout<<endl;
  //Reverse Iterator

  auto reverseBegin = vec.rbegin();
  auto reverseEnd = vec.rend();
  for(auto i=reverseBegin; i<reverseEnd;i++){
    cout<<*i<<" "; // 523 0 54 
  }

  cout<<endl;

  //initialise vector
  vector<int> vec1 = {1,2,3};
  vec1.push_back(5);
  for(auto i: vec1){
    cout<< i << " "; // 1 2 3 5 
  }
  cout<<endl;

  //duplicate a vector

  vector<int>dupVec(vec1);
  for(auto i: dupVec){
    cout<<i<<" "; // 1 2 3 5 
  }
  cout<<endl;

}