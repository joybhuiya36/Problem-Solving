#include <bits/stdc++.h>
using namespace std;

class ListNode {
	public:
	int val;
	ListNode* next;
	ListNode()
	{
		val=0;
		next=NULL;
	}
	ListNode(int data)
	{
		val=data;
		next=NULL;
	}
	ListNode(int data, ListNode* nxt)
	{
		val=data;
		next=nxt;
	}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        ListNode* temp;
        temp=head;
        int count=-1,sum=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            sum+=temp->val*pow(2,count);
            count--;
            temp=temp->next;
        }
        return sum;
    }
};

void display(ListNode* head)
{
	ListNode* temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->val<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

int main()
{
	ListNode* head=new ListNode(1);
	ListNode* h2=new ListNode(0);
	ListNode* h3=new ListNode(1);
	head->next=h2;
	h2->next=h3;
	display(head);
	Solution ob;
	cout<<ob.getDecimalValue(head);
	return 0;
}

//Another technic by O(n)
//class Solution {
//public:
//    int getDecimalValue(ListNode* head) {
//        int ans = 0;
//        ListNode* cur = head;
//        
//        while(cur){
//            ans = (ans *2) + cur->val;
//            cur = cur->next;
//        }
//        
//        return ans;
//    }
//};
