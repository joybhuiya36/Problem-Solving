class Solution {
public:
    void dfs(vector<vector<int>>& img, int sr, int sc, int &color, int &oc)
    {
        cout<<"out loop "<<sr<<sc<<endl;
        if(sr>=0 && sr<img.size() && sc>=0 && sc<img[0].size() && img[sr][sc]==oc)
        {
            img[sr][sc]=color;
            dfs(img,sr-1,sc,color,oc);
            dfs(img,sr+1,sc,color,oc);
            dfs(img,sr,sc-1,color,oc);
            dfs(img,sr,sc+1,color,oc);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int oc=img[sr][sc];
        if(oc==color)
        return img;
        cout<<oc<<endl;
        dfs(img,sr,sc,color,oc);
        return img;
    }
};
