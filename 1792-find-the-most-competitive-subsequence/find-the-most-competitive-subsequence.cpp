class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> st;

        for(int i=0;i<n;i++)
        {
            // !st.empty() -> some element is already present at the cur posn
            // after placing the ith element at the cur posn, I still need to fill
            // k-st.size() vacancies
            // after the ith element I still have n-i-1 elements to its right
            // the no of elements on the right must be >= no of vacancies after the cur posn
            // the original element at the cur posn > ith element, so displacing it with 
            // ith element gives a smaller (more competitive) result overall
            while(!st.empty() && n-i-1 >= k-st.size() && st.back() > nums[i])
            st.pop_back();

            if(st.size() < k) // I still need more elements
            st.push_back(nums[i]);
        }

        return st;
    }
};