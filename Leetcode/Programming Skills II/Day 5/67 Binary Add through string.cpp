//Add two binary number
//Inspired Solution
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i= a.size()-1,j=b.size() -1;
        int sum ,carry=0;
        while( i>=0||j>=0){
            sum=carry;
            if(i>=0) sum+=a[i] -'0';
            if(j>=0) sum+=b[j] -'0';
            res += to_string(sum % 2);
            carry=sum/2;
            i--,j--;
            
            
        }
        if(carry!=0) res+= '1';
        reverse(res.begin(),res.end());
        return res;
        
    }
};

//My Solution
class Solution {
public:
    int add(int x, int y)
    {
        if(x==1 && y==1)
        return 10;
        else return int(x^y);
    }
    string addBinary(string a, string b) {
        int n1=a.length(), n2=b.length();
        int len=max(n1,n2);
        vector<int>v(len+1,0);
        int res=0;
        int i=len;
        for(int j=n1-1,k=n2-1;j>=0&&k>=0;i--,j--,k--)
        {
            int x=a[j]-'0';
            int y=b[k]-'0';
            int z=add(x,y);
            z=add(z,res);
            v[i]=z%10;
            res=z/10;
        }
        if(n1>n2)
        while(i>0)
        {
            int x=a[i-1]-'0';
            int z=add(x,res);
            v[i]=z%10;
            res=z/10;
            i--;
        }
        if(n1<n2)
        while(i>0)
        {
            int x=b[i-1]-'0';
            int z=add(x,res);
            v[i]=z%10;
            res=z/10;
            i--;
        }
        v[i]=res;
        int t;
        if(v[0]==0)
        t=1;
        else t=0;
        string str;
        while(t<=len)
        str+=to_string(v[t++]);
        return str;
    }
};
