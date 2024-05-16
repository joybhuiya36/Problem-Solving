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
        stack<int> stk1,stk2,ans;
        while(l1 || l2)
        {
            if(l1)
            {
                stk1.push(l1->val);
                l1=l1->next;
            }
            if(l2)
            {
                stk2.push(l2->val);
                l2=l2->next;
            }
        }
        int sum=0;
        int n=max(stk1.size(),stk2.size());
        for(int i=0;i<n;i++)
        {
            if(stk1.size())
            {
                sum+=stk1.top();
                stk1.pop();
            }
            if(stk2.size())
            {
                sum+=stk2.top();
                stk2.pop();
            }
            ans.push(sum%10);
            sum/=10;
        }
        if(sum)
        ans.push(sum);
        ListNode* cur=new ListNode(0);
        ListNode* dummy=cur;
        while(ans.size())
        {
            ListNode* temp=new ListNode(ans.top());
            ans.pop();
            cur->next=temp;
            cur=cur->next;
        }
        return dummy->next;
    }
};
