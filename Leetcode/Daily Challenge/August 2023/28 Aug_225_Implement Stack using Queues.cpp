//One Queue
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            int front=q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int p=q.front();
        q.pop();
        return p;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
//Two Queue
class MyStack {
public:
queue<int> q1,q2;
int f=0;
    MyStack() {
        
    }
    
    void push(int x) {
        if(!f)
        q1.push(x);
        else
        q2.push(x);
    }
    
    int pop() {
        if(!f)
        {
            int n;
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            n=q1.front();
            q1.pop();
            f=!f;
            return n;
        }
        else
        {
            int n;
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            n=q2.front();
            q2.pop();
            f=!f;
            return n;
        }
    }
    
    int top() {
        if(!f)
        {
            int n;
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            n=q1.front();
            q1.pop();
            q2.push(n);
            f=!f;
            return n;
        }
        else
        {
            int n;
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            n=q2.front();
            q2.pop();
            q1.push(n);
            f=!f;
            return n;
        }
    }
    
    bool empty() {
        if(!f)
        return q1.empty();
        else return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
