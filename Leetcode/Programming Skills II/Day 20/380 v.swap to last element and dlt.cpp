class RandomizedSet {
    unordered_map<int,int>mp;
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.count(val))
        return false;
        else
        {
            mp[val]=v.size();
            v.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.count(val))
        {
            int pos=mp[val];
            int last=v.back();
            mp[last]=pos;
            v[pos]=last;
            v.pop_back();
            mp.erase(val);
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
