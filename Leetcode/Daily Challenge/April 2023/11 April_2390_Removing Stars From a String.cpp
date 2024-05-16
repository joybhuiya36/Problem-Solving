class Solution {
public:
    string removeStars(string s) {
        string str;
        int n=s.length(), count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(count==0 && s[i]!='*')
            str+=s[i];
            else if(s[i]=='*')
            count++;
            else
            count--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
class Solution {
public:
    string removeStars(string s) {
        string answer = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                answer.pop_back();
            } else {
                answer.push_back(s[i]);
            }
        }
        return answer;
    }
};
//Can be aslo solved by stack in the characters and pop while we find any star(*)
//Two Pointer Approach
class Solution {
public:
    string removeStars(string s) {
        vector<char> ch(s.size());
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                j--;
            } else {
                ch[j++] = s[i];
            }
        }

        string answer = "";
        for (int i = 0; i < j; i++) {
            answer.push_back(ch[i]);
        }

        return answer;
    }
};
