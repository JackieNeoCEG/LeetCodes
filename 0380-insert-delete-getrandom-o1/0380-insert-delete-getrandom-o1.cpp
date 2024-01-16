class RandomizedSet {
    // Vector to store elements
    vector<int> v;
    // Unordered map to store element indices in vector
    unordered_map<int,int> mp;
    
public:
    //constructor
    RandomizedSet() {
    }
    
    //aka exist function
    bool search(int val) {
         if(mp.find(val)!= mp.end()) {
            return true;
         }
         return false;
    }

    
    bool insert(int val) {
        if(search(val)) {
            return false;
        }
        
        v.push_back(val);
        mp[val] = v.size() - 1; // Store the index of the added value in mp
        return true;
    }

    
    bool remove(int val) {
        if(!search(val))
            return false;

        auto it = mp.find(val);             //find the iterator to the value in mp
        v[it->second] = v.back();           //swap the value to be removed with the last element in v
        mp[v[it->second]] = it->second;     //update index in mp
        v.pop_back();                       //remove last element in v
        mp.erase(val);                      //remove val from mp
        return true;
    }

   
    int getRandom() {
        // Generate a random index within the size of the vector
        return v[rand() % v.size()];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */