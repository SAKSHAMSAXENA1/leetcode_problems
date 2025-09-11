class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels({'a','e','i','o','u','A','E','I','O','U'});
        priority_queue<char,vector<char>,greater<>> pq;

        for(auto it:s)
        {
            if(vowels.find(it)!=vowels.end())
            pq.push(it);
        }

        string res="";

        for(auto it:s)
        {
            if(vowels.find(it)!=vowels.end())
            {
                res.push_back(pq.top());
                pq.pop();
            }
            else res.push_back(it);
        }

        return res;
    }
};