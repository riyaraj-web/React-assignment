// https://leetcode.com/problems/design-hashset/description/
#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    int size;
    vector<list<int>> table;

    MyHashSet() {
        size = 10007;
        table.resize(size);
    }

    int hash(int key){
        return key % size;
    }
    
    void add(int key) {
        int idx = hash(key);
        for(auto i : table[idx]){
            if(i == key) return;
        }
        table[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        // iterate on table[idx]
        for(auto i = table[idx].begin(); i != table[idx].end(); i++){
            if(*i == key){
                table[idx].erase(i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        for(auto i : table[idx]){
            if(i == key) return true;
        }
        return false;
    }
};

int main(){
    int key = 5;

    MyHashSet* obj = new MyHashSet();
    obj->add(key);
    obj->remove(key);
    bool param_3 = obj->contains(key);

    cout << param_3 << endl;
}