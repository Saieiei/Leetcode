class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // Check if the element is already present
        if (indexMap.find(val) != indexMap.end()) {
            return false;
        }
        
        // Add the element to the vector and update its index in the map
        elements.push_back(val);
        indexMap[val] = elements.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        // Check if the element is present
        if (indexMap.find(val) == indexMap.end()) {
            return false;
        }
        
        // Swap the element with the last element in the vector
        // Update the index in the map for the last element
        int lastElement = elements.back();
        int idxToRemove = indexMap[val];
        
        elements[idxToRemove] = lastElement;
        indexMap[lastElement] = idxToRemove;
        
        // Erase the element from the vector and map
        elements.pop_back();
        indexMap.erase(val);
        
        return true;
    }
    
    int getRandom() {
        // Generate a random index and return the corresponding element
        int randomIndex = rand() % elements.size();
        return elements[randomIndex];
    }

private:
    std::vector<int> elements;
    std::unordered_map<int, int> indexMap; // Map to store the index of each element in the vector
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */