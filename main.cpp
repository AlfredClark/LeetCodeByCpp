#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
private:
    int parm;
    vector<list<int>> hashMap;

    int hash(int key) {
        return key % parm;
    }

public:
    MyHashSet() {
        parm = 100;
        hashMap.resize(parm);
    }

    void add(int key) {
        hashMap[hash(key)].push_back(key);
    }

    void remove(int key) {
        hashMap[hash(key)].remove(key);
    }

    bool contains(int key) {
        return find(hashMap[hash(key)].begin(), hashMap[hash(key)].end(), key) != hashMap[hash(key)].end();
    }
};

int main() {
    MyHashSet *obj = new MyHashSet();
    obj->add(1);
    obj->add(3);
    cout << obj->contains(1) << endl;
    cout << obj->contains(3) << endl;
    obj->remove(1);
    obj->remove(3);
    cout << obj->contains(1) << endl;
    cout << obj->contains(3) << endl;
    return 0;
}

