class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int,int> mp;
    bool search(int val)
    {
        if(mp.find(val)!=mp.end()) return true;        
        return false;
    }
    RandomizedSet() {
        
        
    }
    
    bool insert(int val) {
        if(search(val))
            return false;
        vec.push_back(val);
        mp[val]=vec.size()-1;
        
        return true;
        
    }
    
    bool remove(int val) {
        
        if(!search(val))
            return false;
        int k=mp[val];
        vec[k]=vec.back();
        mp[vec.back()]=k;
        mp.erase(val);
        vec.pop_back();
        return true;
        
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */