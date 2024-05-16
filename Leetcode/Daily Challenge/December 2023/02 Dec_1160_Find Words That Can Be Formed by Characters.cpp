class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int arr[26]={0};
        int n=chars.length();
        for(int i=0;i<n;i++)
        arr[chars[i]-'a']++;
        n=words.size();
        int tmp[26];
        int ch,flag,ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            tmp[j]=arr[j];
            flag=0;
            for(int j=0;j<words[i].length();j++)
            {
                ch=words[i][j]-'a';
                tmp[ch]--;
                if(tmp[ch]<0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            ans+=words[i].length();
        }
        return ans;
    }
};
