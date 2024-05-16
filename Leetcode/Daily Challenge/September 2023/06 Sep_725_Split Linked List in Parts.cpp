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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0,rem;
        ListNode* cur=head;
        while(cur)
        {
            n++;
            cur=cur->next;
        }
        cur=head;
        rem=n%k;
        n/=k;
        int c=n;
        vector<ListNode*> v;
        ListNode *tmp, *lst;
        while(k--)
        {
            n=c;
            tmp=cur;
            while(n && cur)
            {
                lst=cur;
                cur=cur->next;
                n--;
            }
            if(rem && cur)
            {
                lst=cur;
                cur=cur->next;
                rem--;
            }
            if(lst)
            lst->next=NULL;
            v.push_back(tmp);
        }
        return v;

    }
};
