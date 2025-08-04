class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> u;
        int n=fruits.size(),l=0,r=0,res=0;

        while(r<n)
        {
            u[fruits[r]]++; // acquire

            // while condn of the probm is false, i.e. the window has more than two types 
            // of fruits/elements
            while(u.size()>2)
            {
                u[fruits[l]]--; // release
                if(u[fruits[l]]==0) // the window no longer contains element fruits[l]
                u.erase(fruits[l]);

                l++; // shrink the window (release)
            }

            // now u.size()<=2, i.e condn of the probm: window (basket) must contain
            // only a max of two different types of elements (fruits) is satisfied/true
            // so update the result
            res=max(res,r-l+1);

            r++; // expand the window (acquire) 
        }

        return res;
    }
};