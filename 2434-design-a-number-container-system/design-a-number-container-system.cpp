class NumberContainers {
public:
unordered_map<int,int> indexToNumber;
unordered_map<int, set<int>> numberToIndex;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNumber.find(index)!=indexToNumber.end())
        {
            int prevNumber=indexToNumber[index];
            numberToIndex[prevNumber].erase(index);

            if(numberToIndex[prevNumber].size()==0) numberToIndex.erase(prevNumber);
        }
        indexToNumber[index]=number;
        numberToIndex[number].insert(index);
    }
    
    int find(int number) {
        return (numberToIndex.find(number)!=numberToIndex.end()) ? *numberToIndex[number].begin():-1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */