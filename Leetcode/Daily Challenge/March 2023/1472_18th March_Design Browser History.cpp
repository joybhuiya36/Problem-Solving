//Design Browser History
//Vector and two pointer(ptr,limit)
class BrowserHistory {
public:
    int ptr,limit;
    vector<string> v;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        ptr=0;
        limit=0;
    }
    
    void visit(string url) {
        if(ptr==v.size()-1)
        {
            v.push_back(url);
            ptr++;
            limit++;
            return;
        }
        else
        {
            ptr++;
            limit=ptr;
            v[ptr]=url;
            return;
        }

    }
    string back(int steps) {
        if(ptr-steps<0)
        ptr=0;
        else
        ptr=ptr-steps;
        return v[ptr];
    }
    string forward(int steps) {
        if(ptr+steps>limit)
        ptr=limit;
        else
        ptr+=steps;
        return v[ptr];
    }
};

//Two Stack
class BrowserHistory {
public:
	stack<string> fwd, bwd;
    BrowserHistory(string homepage) {
        bwd.push(homepage);
    }
    
    void visit(string url) {
        bwd.push(url);
        while(!fwd.empty())
        fwd.pop();
    }
    
    string back(int steps) {
        while(steps-- && bwd.size()>1)
        {
            fwd.push(bwd.top());
        	bwd.pop();
        }
        return bwd.top();
    }
    
    string forward(int steps) {
        while(steps-- && !fwd.empty())
        {
			bwd.push(fwd.top());
        	fwd.pop();
        }
        return bwd.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
