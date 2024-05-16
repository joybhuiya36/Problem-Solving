//or
class Solution {
public:
    string intToRoman(int num) {
        int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string sym[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string ans;
    for(int i=0;i<13;i++){
        while(num>=value[i]){
            ans+=sym[i];
            num=num-value[i];
        }
    }
    return ans;
    }
};
//My Solution
class Solution {
public:
unordered_map<int,char> mp={{1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}};
int arr[7]={1,5,10,50,100,500,1000};
string s;
int a,b,i;
    string func49(char ch, int n)
    {
        a=ch-'0';
        b=a+1;
        while(n--)
        {
            a*=10;
            b*=10;
        }
        s="";
        s+=mp[b-a];
        s+=mp[b];
        return s;
    }
    string func(char ch, int n)
    {
        s="";
        a=ch-'0';
        while(n--)
        a*=10;
        while(a)
        {
            i=6;
            while(1)
            {
                if(a/arr[i]>0) break;
                else i--;
            }
            s+=mp[arr[i]];
            a-=arr[i];
        }
        return s;

    }
    string intToRoman(int num) {
        string s=to_string(num);
        string ans;
        while(s.length()!=0)
        {
            if(s[0]=='0')
            {}
            else if(s[0]=='4' || s[0]=='9')
            {
                ans+=func49(s[0],s.length()-1);
            }
            else
            {
                ans+=func(s[0],s.length()-1);
            }
            s.erase(s.begin());
        }
        return ans;
    }
};
