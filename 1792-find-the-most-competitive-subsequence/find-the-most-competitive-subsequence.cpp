class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n=nums.size();
        vector<int> res(k);

        for(int i=0;i<n;i++)
        {
            // !st.empty() -> some element is already present at the cur posn
            // after placing the ith element at the cur posn, I still need to fill
            // k-st.size() vacancies
            // after the ith element I still have n-i-1 elements to its right
            // the no of elements on the right must be >= no of vacancies after the cur posn
            // the element at the cur posn > ith element, so displacing it with ith element
            // gives a smaller (more competitive) result overall
            while(!st.empty() && n-i-1 >= k-st.size() && st.top() > nums[i])
            st.pop();

            if(st.size() < k) // I still need more elements
            st.push(nums[i]);
        }

        for(int index=k-1;index>=0;index--)
        {
            res[index]=st.top();
            st.pop();
        }

        return res;
    }
};