class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char,pair<int,int>> mv;
        mv['N']={0,1};
        mv['S']={0,-1};
        mv['E']={1,0};
        mv['W']={-1,0};
        unordered_set<string> mp;
        mp.insert("0,0");
        pair<int,int> cur;
        int x=0,y=0;
        string s;
        for(char &c:path)
        {
            cur=mv[c];
            x+=cur.first;
            y+=cur.second;
            s=to_string(x)+','+to_string(y);
            if(mp.count(s)) return true;
            mp.insert(s);
        }
        return false;
    }
};
