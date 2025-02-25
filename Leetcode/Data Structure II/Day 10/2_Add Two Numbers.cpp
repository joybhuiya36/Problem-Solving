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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur=new ListNode(0);
        ListNode* dummy=cur;
        int sum=0;
        while(l1!=NULL || l2!=NULL)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode* temp=new ListNode(sum%10);
            cur->next=temp;
            cur=cur->next;
            sum/=10;
        }
        if(sum)
        {
            ListNode* temp=new ListNode(sum);
            cur->next=temp;
        }
        return dummy->next;
    }
};
