// https://leetcode.com/problems/design-hashmap/description/
#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    int size;
    vector<vector<pair<int, int>>> mp; // for each idx, an array of key and values (each vector is called bucket)

    int hash(int key){
        return key % size;
    }

    MyHashMap() {
        size = 10007;
        mp.resize(size);
    }
    
    void put(int key, int value) {
        int idx = hash(key); // hash the key
        for(auto &pair : mp[idx]){
            if(pair.first == key){
                pair.second = value;
                return;
            }
        }
        mp[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        for(auto &pair : mp[idx]){
            if(pair.first == key) return pair.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        vector<pair<int, int>> &bucket = mp[idx];

        for(int i = 0; i < bucket.size(); i++){
            if(bucket[i].first == key){
                bucket[i] = bucket.back(); // swap with last variable
                bucket.pop_back(); // and then pop last variable for O(1) time;
                return;
            }
        }  
    }
};

int main(){
    int key = 2, value = 24;

    MyHashMap* obj = new MyHashMap();
    obj->put(key,value);
    int param_2 = obj->get(key);
    obj->remove(key);
    cout << param_2 << endl;
}