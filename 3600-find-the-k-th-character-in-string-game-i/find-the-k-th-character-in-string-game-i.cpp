class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(k>word.size())
        {
            string newWord=word;

            for(auto &it:newWord)
            it='a'+(it-'a'+1)%26;

            word=word+newWord;
        }

        return word[k-1];
    }
};