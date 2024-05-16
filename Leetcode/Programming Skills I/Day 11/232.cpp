/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyQueue {
public:
stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int arr=s2.top();
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return arr;
    }
    
    int peek() {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int arr=s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return arr;
    }
    
    bool empty() {
        return (s1.empty());
    }
};

class MyQueue {
public:
vector<int> v;
    MyQueue() {
        
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    int pop() {
        int arr=v[0];
        v.erase(v.begin());
        return arr;
    }
    
    int peek() {
        return v[0];
    }
    
    bool empty() {
        if(v.size()==0)
        return true;
        else return false;
    }
};
