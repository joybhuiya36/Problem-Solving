class node {
public:
    int val;
    node* next;
    node(int data) { val=data; next=NULL; }
};
class MyCircularQueue {
int n=0,mx;
node* head=NULL;
node* last=NULL;
public:
    MyCircularQueue(int k) {
        mx=k;
    }
    
    bool enQueue(int value) {
        if(n<mx)
        {
            node* temp= new node(value);
            if(head==NULL)
            {
                head=temp;
                last=temp;
            }
            else
            {
                last->next=temp;
                last=last->next;
            }
            n++;
            return true;
        }
        else return false;
    }
    
    bool deQueue() {
        if(n>0)
        {
            node* temp=head;
            head=head->next;
            if(head==NULL) last=NULL;
            n--;
            delete temp;
            return true;
        }
        else return false;
    }
    
    int Front() {
        if(n==0) return -1;
        return head->val;
    }
    
    int Rear() {
        if(n==0) return -1;
        return last->val;
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==mx;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
