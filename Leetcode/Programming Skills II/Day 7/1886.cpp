class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int f1=1,f2=1,f3=1,f4=1;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                if(f1 && target[i][j]!=mat[mat.size()-1-j][i])
                f1=0;
                if(f2 && target[i][j]!=mat[mat.size()-1-i][mat.size()-1-j])
                f2=0;
                if(f3 && target[i][j]!=mat[j][mat.size()-1-i])
                f3=0;
                if(f4 && target[i][j]!=mat[i][j])
                f4=0;
                if(!f1&&!f2&&!f3&&!f4)
                break;
            }
            if(!f1&&!f2&&!f3&&!f4)
            break;
        }
        if(f1||f2||f3||f4) return true;
        return false;
    }
};
//same Long version in different loop
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int flag=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                if(target[i][j]!=mat[mat.size()-1-j][i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
            if(mat.size()-1==i) return true;
        }
        flag=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                if(target[i][j]!=mat[mat.size()-1-i][mat.size()-1-j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
            if(mat.size()-1==i) return true;
        }
        flag=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                if(target[i][j]!=mat[j][mat.size()-1-i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
            if(mat.size()-1==i) return true;
        }
        flag=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                if(target[i][j]!=mat[i][j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
            if(mat.size()-1==i) return true;
        }
        return false;
    }
};
