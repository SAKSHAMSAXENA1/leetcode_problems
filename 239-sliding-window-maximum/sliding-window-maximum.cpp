class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // dq is monotonic STRICTLY decreasing -> front element is always largest for current 
        // window
        deque<int> dq;
        vector<int> res;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            // step 1: remove any such element from dq which is not part of current window
            if(!dq.empty() && dq.front()<=i-k)
            {
                dq.pop_front();
            }

            // step 2: remove all such elements from dq which are<= nums[i]
            while(!dq.empty() && nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }

            // step 3: insert nums[i] in dq, as it is part of my current window
            dq.push_back(i);

            // step 4: if I have k elements in window, include the max element of window
            // in  answer
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};