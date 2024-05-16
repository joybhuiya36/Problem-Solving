class MyLinkedList {
    int val;
    MyLinkedList* next;
    MyLinkedList* head=NULL;
public:
    MyLinkedList() {}
    MyLinkedList(int data) {
        val=data;
        next=NULL;
    }
    
    int get(int index) {
        if(head==NULL) return -1;
        int count=0;
        MyLinkedList* cur=head;
        while(count<index)
        {
            cur=cur->next;
            if(cur==NULL) break;
            count++;
        }
        if(count!=index) return -1;
        return cur->val;
    }
    
    void addAtHead(int val) {
        if(head==NULL)
        {
            head=new MyLinkedList(val);
            return;
        }
        MyLinkedList* temp=head;
        head=new MyLinkedList(val);
        head->next=temp;
    }
    
    void addAtTail(int val) {
        if(head==NULL)
        {
            addAtHead(val);
            return;
        }
        MyLinkedList* cur=head;
        while(cur->next!=NULL)
        cur=cur->next;
        cur->next=new MyLinkedList(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        if(head==NULL) return;
        int count=0;
        MyLinkedList* cur=head;
        while(count<index-1)
        {
            cur=cur->next;
            if(cur==NULL) break;
            count++;
        }
        if(count==index-1)
        {
            MyLinkedList* temp=cur->next;
            cur->next=new MyLinkedList(val);
            cur->next->next=temp;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index==0)
        head=head->next;
        int count=0;
        MyLinkedList* cur=head;
        while(count<index-1)
        {
            cur=cur->next;
            if(cur==NULL) break;
            count++;
        }
        if(count==index-1 && cur->next!=NULL)
        cur->next=cur->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
