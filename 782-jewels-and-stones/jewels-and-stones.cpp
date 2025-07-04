class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(),jewels.end());
        int cnt=0;

        for(auto stone:stones)
        cnt+=(jewelSet.find(stone)!=jewelSet.end());

        return cnt;
    }
};