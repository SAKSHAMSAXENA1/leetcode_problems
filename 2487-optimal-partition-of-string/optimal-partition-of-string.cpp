class Solution {
public:
    int partitionString(string s) {
        int partitions=0;
        unordered_set<char> u;

        for(auto it:s)
        {
            if(u.find(it)!=u.end()) // cur char present in substring under consideration
            {
                partitions++;
                u.clear();
            }

            // now cur char is not present in substring under consideration
            u.insert(it); 
        }

        return partitions+1; // no of substrings= no of partitions+1
    }
};