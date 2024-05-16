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
    void reorderList(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL)
        return;
        stack<ListNode*> stk;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            stk.push(cur);
            cur=cur->next;
        }
        cur=head;
        ListNode* temp;
        while(cur!=stk.top() && cur->next!=stk.top())
        {
            temp=cur->next;
            cur->next=stk.top();
            stk.pop();
            cur->next->next=temp;
            cur=cur->next->next;
        }
        if(cur==stk.top())
        cur->next=NULL;
        else if(cur->next==stk.top())
        cur->next->next=NULL;
    }
};
