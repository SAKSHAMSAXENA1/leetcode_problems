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
int getSize(ListNode *head)
{
    int n = 0;

    while(head)
    {
        n++;
        head = head->next;
    }

    return n;
}
    ListNode* rotateRight(ListNode* head, int k) {
     if(!head) return head;

     int n=getSize(head);

     k%=n;

     if(k==0) return head;

     ListNode *cur=head, *last = NULL;

     int rem = n - k;

     for(int i=0;i<rem;i++)  
     {
        last = cur;
        cur=cur->next;
     }

     ListNode *newHead = cur;
     last->next = NULL;

     ListNode *prev = NULL;

     while(cur)
     {
        prev = cur;
        cur = cur->next;
     }

     prev->next = head;
     return newHead;
    }
};