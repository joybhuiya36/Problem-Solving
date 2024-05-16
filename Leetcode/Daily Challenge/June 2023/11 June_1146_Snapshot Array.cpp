class SnapshotArray {
public:
vector<vector<pair<int,int>>> v;
int id,l,r,mid;
    SnapshotArray(int length) {
        id=0;
        v.resize(length,vector<pair<int,int>>(1,{0,0})); //{id,val}
    }
    
    void set(int index, int val) {
        if(v[index].back().first==id)
        v[index].back().second=val;
        else v[index].push_back({id,val});
    }
    
    int snap() {
        id++;
        return id-1;
    }
    
    int get(int index, int snap_id) {
        l=0; r=v[index].size()-1;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(v[index][mid].first>snap_id)
            r=mid-1;
            else l=mid+1;
        }
        return v[index][r].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
