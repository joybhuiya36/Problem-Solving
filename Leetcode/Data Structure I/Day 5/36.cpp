class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int n=b.size();
        for(int i=0;i<n;i++)
        {
            int r_arr[10]={0};
            int c_arr[10]={0};
            for(int j=0;j<n;j++)
            {
                if(b[i][j]!='.')
                {
                    r_arr[b[i][j]-'0']++;
                    if(r_arr[b[i][j]-'0']>1)
                    return false;
                }
                if(b[j][i]!='.')
                {
                    c_arr[b[j][i]-'0']++;
                    if(c_arr[b[j][i]-'0']>1)
                    return false;
                }

            }
        }
        //2nd box
        int x=3;
        for(int a=1,k=2;a<x;a++)
        {
            int i=a+k,j=0,loop=9;
            int r_arr[10]={0};
            int c_arr[10]={0};
            while(loop--)
            {
                if(b[i][j]!='.')
                {
                    r_arr[b[i][j]-'0']++;
                    if(r_arr[b[i][j]-'0']>1)
                    return false;
                }
                if(b[j][i]!='.')
                {
                    c_arr[b[j][i]-'0']++;
                    if(c_arr[b[j][i]-'0']>1)
                    return false;
                }
                j++;
                if(j==3)
                {
                    i++;
                    j=0;
                }
            }
            k+=2;

        }
        //3rd box
        for(int i=0;i<9;)
        {
            int ii=i;
            int j=i,loop=9,t=0;
            int r_arr[10]={0};
            int c_arr[10]={0};
            while(loop--)
            {
                if(b[i][j]!='.')
                {
                    r_arr[b[i][j]-'0']++;
                    if(r_arr[b[i][j]-'0']>1)
                    return false;
                }
                j++; t++;
                if(t==3)
                {
                    i++;
                    j=ii; t=0;
                }
            }
        }
        //4th box
        int loop=9,i=3,j=6;
        int r_arr[10]={0};
        int c_arr[10]={0};
        while(loop--)
        {
            if(b[i][j]!='.')
            {
                r_arr[b[i][j]-'0']++;
                if(r_arr[b[i][j]-'0']>1)
                return false;
            }
            if(b[j][i]!='.')
            {
                c_arr[b[j][i]-'0']++;
                if(c_arr[b[j][i]-'0']>1)
                return false;
            }
            j++;
            if(j==9)
            {
                i++;
                j=6;
            }
        }
        return true;
    }
};
