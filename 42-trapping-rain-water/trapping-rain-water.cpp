class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),sum=0;
        vector<int> leftTallest(n,0); // prefixTallest
        vector<int> rightTallest(n,0); // suffixTallest
        leftTallest[0]=height[0];
        rightTallest[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            leftTallest[i]=max(leftTallest[i-1],height[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            rightTallest[i]=max(rightTallest[i+1],height[i]);
        }

        for(int i=0;i<n;i++)
        {
            sum+=min(leftTallest[i],rightTallest[i])-height[i];
        }

        return sum;
    }
};