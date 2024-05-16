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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp;
        temp=head;
        vector<int> v;
        int n=0;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        if(n==1)
        return head;
        n=(n/2);
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            n--;
            if(n==0)
            break;
        }
        return temp;  
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
	ListNode* h2=new ListNode(2);
	ListNode* h3=new ListNode(3);
	head->next=h2;
	h2->next=h3;
	display(head);
	Solution ob;
	cout<<ob.middleNode(head)->val;
	return 0;
}

