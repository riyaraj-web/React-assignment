//this problem returns the intersection of the two arrays
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
  
        unordered_map<int,int>mpp;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mpp.find(nums2[i])!=mpp.end()){
                ans.push_back(nums2[i]);
                if(mpp[nums2[i]]>1)mpp[nums2[i]]--;
                else mpp.erase(nums2[i]);
            }
        }
      cout<<"the common elements of the array are:"<<
        for(auto i:ans){
            cout<<i<<" ";
        }
}
