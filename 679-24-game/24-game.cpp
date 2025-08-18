#define epsilon (double)(1e-6)
#define target (double)(24.0)
class Solution {
public:
bool f(vector<double> &nums,int n)
{
    if(n==1) //  base case when nums is reduced to single element = result of operations we did
    {
        return abs(nums[0]-target) <= epsilon; 
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            // selecting two nos a=nums[i],b=nums[j] on which we will perform operations
            double a=nums[i],b=nums[j];

            vector<double> newArray;
            for(int k=0;k<n;k++) // selecting remaining elements (other than those at i and j)
            {
                if(k==i || k==j) continue;
                
                newArray.push_back(nums[k]);
            }

            vector<double> operations={a+b,a-b,a*b,b-a};

            if(b!=0) operations.push_back(a/b);

            if(a!=0) operations.push_back(b/a);

            for(auto it:operations)
            {
                // backtracking
                newArray.push_back(it); // do

                if(f(newArray,n-1)==true) return true; // explore

                newArray.pop_back(); // undo
            }
        }
    }

    return false;
}
    bool judgePoint24(vector<int>& cards) {
        int n=cards.size();
        vector<double> nums;
        for(auto it:cards)
        nums.push_back(it*1.0);

        return f(nums,n);
    }
};