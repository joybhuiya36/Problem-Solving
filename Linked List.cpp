#include<bits/stdc++.h>
using namespace std;

class node {
	public:
		int data;
		node* next;
		
		node(int val)
		{
			data=val;
			next=NULL;
		}
};

	void addAtHead(node* &head, int val)
	{
		node* n= new node(val);
		n->next=head;
		head=n;
	}
	void addAtTail(node* &head, int val)
		{
			node* n= new node(val);
			while(head==NULL)
			{
				head=n;
				return;
			}
			node* temp=head;
			while(temp->next!=NULL)
			temp=temp->next;
			temp->next=n;
		}
		void search(node* head, int key)
		{
			int flag=0;
			node* temp=head;
			while(temp!=NULL)
			{
				if(temp->data==key)
				{
					flag=1;
					break;
				}
				temp=temp->next;
			}
			if(flag==1) cout<<key<<" Found"<<endl;
			else cout<<key<<" Not Found"<<endl;
		}
		void deleteData(node* &head, int key)
		{
			node* temp=head;
			node* pre;
			while(temp!=NULL)
			{
				if(temp->data==key && head->data!=key)
				{
					pre->next=temp->next;
					break;
				}
				else if(head->data==key)
				{
					head=temp->next;
					break;
				}
				pre=temp;
				temp=temp->next;
			}
		}
		void display(node* head)
		{
			node* temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}

int main()
{
	node* head=NULL;
	addAtTail(head,1);
	addAtTail(head,2);
	addAtTail(head,3);
	display(head);
	addAtHead(head,0);
	display(head);
	search(head,3);
	search(head,5);
	deleteData(head,0); //head deleted
	display(head);
	return 0;
}
