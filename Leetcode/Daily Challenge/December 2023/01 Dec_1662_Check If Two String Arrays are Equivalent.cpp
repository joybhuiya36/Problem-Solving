class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        string s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<word1[i].size();j++)
            {
                s+=word1[i][j];
            }
        }
        int k=0;
        n=word2.size();
        int m=s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<word2[i].size();j++)
            {
                if(k==m) return false;
                if(s[k]!=word2[i][j])
                return false;
                k++;
            }
        }
        if(k!=m) return false;
        return true;
    }
};
//or
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0; //word pointers
        int m = 0, n = 0; //char pointers

        while(i < word1.size() && j < word2.size()){
            if(word1[i][m++] != word2[j][n++])
            return false;

            if(m >= word1[i].size()){
                i++;
                m = 0;
            }
            if(n >= word2[j].size())
            j++, n = 0;
        } 

        return i == word1.size() && j == word2.size();
    }
};
