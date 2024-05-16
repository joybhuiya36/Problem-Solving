class RandomizedSet {
    map<int,int>mp;
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp[val]==1)
        return false;
        else
        {
            mp[val]=1;
            v.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp[val]==1)
        {
            mp.erase(val);
            v.erase(find(v.begin(), v.end(), val));
            return true;
        }
        else
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
