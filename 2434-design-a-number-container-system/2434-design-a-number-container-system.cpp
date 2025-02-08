class NumberContainers {
public:
        unordered_map<int, int> indexToNumber;
        unordered_map<int, set<int>> NumberToIndices;

    NumberContainers() {

    }
    
    void change(int index, int number) {
        //1st we will check if the index is already present in the indexToNumber
            //if the number is present then we will have to check if they are the same
                //if they are the same then we dont have to do anything duh
                //else we will have to update the indexToNumber and remove the old number from NumberToIndices and insert this new 1 in the NumberToIndices
        if(indexToNumber.find(index) != indexToNumber.end()) //index found
        {
            if(indexToNumber[index] == number) return; //number is same and must be already present in the set and all
            else //number is not the same hence update NumberToIndices (just remove)
            {
                int oldNumber = indexToNumber[index];
                NumberToIndices[oldNumber].erase(index);
            }
        }
        //finally update the NumberToIndices and indexToNumber (just add)
        indexToNumber[index] = number;
        NumberToIndices[number].insert(index);
    }   
    
    int find(int number) {
        //1st we will see if that value is present in the NumberToIndices
            //if the value is present then we have to check if the set is not empty for the index has to be present
                //if present just print the 1st value of the set
        //else print -1

        if(NumberToIndices.find(number) != NumberToIndices.end() && !(NumberToIndices[number].empty()))
        {
            return*(NumberToIndices[number].begin());
        }
        else return -1;
}
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */