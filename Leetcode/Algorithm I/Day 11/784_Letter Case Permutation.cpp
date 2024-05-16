class Solution {
public:
vector<string> sv;
string temp;
int n;
	void bktrk(int i, string &s)
    {
        if(temp.length()==n)
        {
            sv.push_back(temp);
            return;
        }
        
            if(s[i]>='0' && s[i]<='9')
            {
                temp+=s[i];
                bktrk(i+1,s);
                temp.pop_back();
            }
            else
            {
                temp+=tolower(s[i]);
                bktrk(i+1,s);
                temp.pop_back();
                temp+=toupper(s[i]);
                bktrk(i+1,s);
                temp.pop_back();
            }
        
    }
    vector<string> letterCasePermutation(string s) {
        n=s.length();
        bktrk(0,s);
        return sv;
    }
};
