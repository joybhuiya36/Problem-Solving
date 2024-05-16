class Solution {
public:
vector<vector<int>> visit;
    bool search(int row, int col, int idx, vector<vector<char>> &brd, string &wrd, int &m, int &n, int &k)
    {
        if(idx==k)
        return true;
        if(brd[row][col]==wrd[idx] && visit[row][col]==0)
        {
            visit[row][col]=1;
            if(col+1<n && search(row,col+1,idx+1,brd,wrd,m,n,k))
            return true;
            if(row+1<m && search(row+1,col,idx+1,brd,wrd,m,n,k))
            return true;
            if(col-1>=0 && search(row,col-1,idx+1,brd,wrd,m,n,k))
            return true;
            if(row-1>=0 && search(row-1,col,idx+1,brd,wrd,m,n,k))
            return true;
            visit[row][col]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size(), k=word.length();
        if(m==1 && n==1 && k==1 && board[0][0]==word[0])
        return true;
        visit.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && search(i,j,0,board,word,m,n,k))
                return true;
            }
        }
        return false;
    }
};
