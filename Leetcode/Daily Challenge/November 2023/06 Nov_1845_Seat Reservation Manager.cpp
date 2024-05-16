class SeatManager {
public:
int s=1, num;
priority_queue<int, vector<int>, greater<int>> q;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        if(!q.empty())
        {
            num=q.top();
            q.pop();
            return num;
        }
        num=s++;
        return num;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
