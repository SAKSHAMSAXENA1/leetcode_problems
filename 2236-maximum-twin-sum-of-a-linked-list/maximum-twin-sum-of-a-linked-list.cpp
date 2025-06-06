/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        int maxi=INT_MIN;
        while(head)
        {
            arr.push_back(head->val);
            head=head->next;
        }

        int n=arr.size(),halfLen=n/2;

        for(int i=0;i<halfLen;i++)
        maxi=max(maxi,arr[i]+arr[n-1-i]);

        return maxi;
    }
};