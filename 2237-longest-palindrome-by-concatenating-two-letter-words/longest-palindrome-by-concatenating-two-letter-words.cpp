class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<int,int> reverseWord,palindromeWordsWithoutReverse;
        int reversePairs=0;

        for(auto it:words)
        {
            int hashWord=(it[0]-'a')*26+(it[1]-'a');
            int hashReverseWord=(it[1]-'a')*26+(it[0]-'a');

            if(reverseWord.find(hashReverseWord)!=reverseWord.end()) // reverse of it exists
            {
                reversePairs++;
                reverseWord[hashReverseWord]--;
                if(reverseWord[hashReverseWord]==0)
                reverseWord.erase(hashReverseWord);

                if(it[0]==it[1]) // it itself is a palindrome
                {
                    palindromeWordsWithoutReverse[hashReverseWord]--;
                    palindromeWordsWithoutReverse.erase(hashReverseWord);
                }
            }
            else // reverse of it does not exist
            {
                reverseWord[hashWord]++;

                if(it[0]==it[1]) // it itself is a palindrome
                palindromeWordsWithoutReverse[hashWord]++;
            }
        }

        return reversePairs*2*2+(!palindromeWordsWithoutReverse.empty())*2;
    }
};