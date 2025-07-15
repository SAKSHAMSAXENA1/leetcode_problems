class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;

        int vowels=0,consonants=0;

        for(auto it:word)
        {
            if('0'<=it && it<='9') continue;
            else if(isalpha(it))
            {
                it=tolower(it);
                if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u')
                vowels++;
                else consonants++;
            }
            else return false;
        }

        return vowels && consonants;
    }
};