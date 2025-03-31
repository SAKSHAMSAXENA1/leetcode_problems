#define ll long long
class Solution {
public:
ll sumSubarrayMax(vector<int> &nums)
{
    int n=nums.size();
    vector<int> pgee(n),nge(n);
    stack<int> st;
    ll sum=0;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && nums[st.top()]<nums[i])
        {
            st.pop(); // keep removing prev smaller elements from stack
        }

        pgee[i]=(st.empty())? -1:st.top();
        st.push(i);
    }

    st=stack<int>();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums[st.top()]<=nums[i])
        {
            st.pop(); // keep removing next smaller or equal elements from stack
        }

        nge[i]=(st.empty())? n:st.top();
        st.push(i);
    }

    for(int i=0;i<n;i++)
    {
        ll left=i-pgee[i],right=nge[i]-i;
        ll contribution=left*right;
        sum+=contribution*nums[i];
    }

    return sum;
}

ll sumSubarrayMin(vector<int> &nums)
{
    int n=nums.size();
    vector<int> psee(n),nse(n);
    stack<int> st;
    ll sum=0;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && nums[st.top()]>nums[i])
        {
            st.pop(); // keep removing prev greater elements from stack
        }

        psee[i]=(st.empty())? -1:st.top();
        st.push(i);
    }

    st=stack<int>();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums[st.top()]>=nums[i])
        {
            st.pop(); // keep removing next greater or equal elements from stack
        }

        nse[i]=(st.empty())? n:st.top();
        st.push(i);
    }

    for(int i=0;i<n;i++)
    {
        ll left=i-psee[i],right=nse[i]-i;
        ll contribution=left*right;
        sum+=contribution*nums[i];
    }

    return sum;
}
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)-sumSubarrayMin(nums);
    }
};