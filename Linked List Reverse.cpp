#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node* next;
    node(int _val)
    {
        val=_val;
        next=NULL;
    }
};
node* func(node* &head)
{
    if(head->next==NULL)
    return head;
    node* newhead=func(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
int main()
{
    node* ob=new node(1);
    node* ob2=new node(2);
    node* ob3=new node(3);
    node* ob4=new node(4);
    ob->next=ob2;
    ob2->next=ob3;
    ob3->next=ob4;
    node* head=ob;
    while(ob)
    {
        cout<<ob->val<<" ";
        ob=ob->next;
    }
    cout<<endl;
    head=func(head);
    ob=head;
    while(ob)
    {
        cout<<ob->val<<" ";
        ob=ob->next;
    }
    return 0;
}

