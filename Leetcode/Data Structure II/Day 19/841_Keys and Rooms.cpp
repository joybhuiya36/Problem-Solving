class Solution {
public:
int count=0;
vector<bool> visit;
    void dfs(int idx, vector<vector<int>>& rooms)
    {
        count++;
        visit[idx]=true;
        for(int i=0;i<rooms[idx].size();i++)
        {
            if(visit[rooms[idx][i]]==false)
            dfs(rooms[idx][i],rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visit.resize(rooms.size(),false);
        dfs(0,rooms);
        if(count==rooms.size())
        return true;
        else return false;
    }
};
