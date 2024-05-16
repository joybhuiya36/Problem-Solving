class MyCalendar {
    set<pair<int,int>> st;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(st.empty())
        {
            st.insert({start,end});
            return true;
        }
        for(auto it=st.begin();it!=st.end();it++)
        {
            if(it->second<=start || it->first>=end)
            {
                continue;
            }
            else return false;
        }
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
