class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),sum=0,maxi=0;
        vector<int> leftTallest(n,0); // prefixTallest
        vector<int> rightTallest(n,0); // suffixTallest

        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,height[i]);
            leftTallest[i]=maxi;
        }

        maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,height[i]);
            rightTallest[i]=maxi;
        }

        for(int i=0;i<n;i++)
        {
            sum+=min(leftTallest[i],rightTallest[i])-height[i];
        }

        return sum;
    }
};