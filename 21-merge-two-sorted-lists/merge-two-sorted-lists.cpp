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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *h1=list1,*h2=list2;
        ListNode *listRes=new ListNode();
        ListNode *hRes=listRes;

        while(h1 && h2)
        {
            if(h1->val < h2->val)
            {
                hRes->next=new ListNode(h1->val);
                hRes=hRes->next;
                h1=h1->next;
            }
            else if(h2->val < h1->val)
            {
                hRes->next=new ListNode(h2->val);
                hRes=hRes->next;
                h2=h2->next;
            }
            else
            {
                hRes->next=new ListNode(h1->val);
                hRes=hRes->next;
                hRes->next=new ListNode(h1->val);
                hRes=hRes->next;
                h1=h1->next;
                h2=h2->next;
            }
        }

        while(h1)
        {
            hRes->next=new ListNode(h1->val);
            hRes=hRes->next;
            h1=h1->next;
        }

        while(h2)
        {
            hRes->next=new ListNode(h2->val);
            hRes=hRes->next;
            h2=h2->next;
        }
        
        return listRes->next;
    }
};