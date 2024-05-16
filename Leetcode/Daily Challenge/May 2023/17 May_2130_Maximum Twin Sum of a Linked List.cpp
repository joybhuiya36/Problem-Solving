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
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n=0;
        ListNode* cur=head;
        while(cur)
        {
            n+=2;
            cur=cur->next->next;
        }
        n/=2;
        int i=n, ans=0;
        cur=head;
        head=NULL;
        ListNode* nxt=cur->next;
        while(i--)
        {
            cur->next=head;
            head=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        while(cur)
        {
            ans=max(ans,cur->val+head->val);
            cur=cur->next;
            head=head->next;
        }
        return ans;
    }
};
