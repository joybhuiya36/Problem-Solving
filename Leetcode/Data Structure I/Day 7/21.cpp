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
 //Recursive way
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        return list2;
        if(list2==NULL)
        return list1;
        ListNode* result;
        if(list1->val<list2->val)
        {
            result=list1;
            result->next=mergeTwoLists(list1->next,list2);
        }
        else
        {
            result=list2;
            result->next=mergeTwoLists(list1,list2->next);
        }
        return result;
    }
};
//Iterative way
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* l1=list1; ListNode* l2=list2;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                temp->next=l1;
                l1=l1->next;
            }
            else
            {
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        while(l1!=NULL)
        {
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2!=NULL)
        {
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
//Iterative way, that I thought first
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* dummy=NULL;
        ListNode* l1=list1; ListNode* l2=list2;
            if(l1->val<l2->val)
            { dummy=l1; l1=l1->next;}
            else
            { dummy=l2; l2=l2->next;}
            ListNode* temp=dummy;
            while(l1!=NULL && l2!=NULL)
            {
                if(l1->val<l2->val)
                {
                    temp->next=l1;
                    l1=l1->next;
                }
                else
                {
                    temp->next=l2;
                    l2=l2->next;
                }
                temp=temp->next;
            }
        if(l1!=NULL)
        temp->next=l1;
        else temp->next=l2;
        return dummy;
    }
};
