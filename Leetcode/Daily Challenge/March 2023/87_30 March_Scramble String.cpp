class Solution {
public:
unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        cout<<s1<<" "<<s2<<endl;
        if(s1==s2)
        return true;
        if(s1.length()<=1)
        return false;
        string key=s1+"*"+s2;
        if(mp.count(key))
        return mp[key];
        
        vector<int> freq(26, 0);	//
        for (char &c : s1) {
            freq[c - 'a']++;		//Checking two string characters are wheather same or not
        }
        for (char &c : s2) {
            freq[c - 'a']--;
        }
        for (int &i : freq) {
            if (i != 0) 
            return mp[key] = false;
        }							//
        
        for(int len=1;len<s1.length();len++)
        {
            if(isScramble(s1.substr(0,len),s2.substr(s1.length()-len)) && isScramble(s1.substr(len),s2.substr(0,s1.length()-len)))
            {
                return mp[key]=true;
                break;
            }
            if(isScramble(s1.substr(0,len),s2.substr(0,len)) && isScramble(s1.substr(len),s2.substr(len)))
            {
                return mp[key]=true;
                break;
            }
        }
        return mp[key]=false;
    }
};
//Check By Printing
class Solution {
public:
unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        // if(s1==""||s2=="")
        // return false;
        cout<<s1<<" "<<s2<<endl;
        if(s1==s2)
        {
            
            cout<<"base case"<<endl;
            return true;
        }
        if(s1.length()<=1)
        return false;
        string key=s1+"*"+s2;
        cout<<key<<" mapping"<<endl;
        if(mp.count(key))
        {
            cout<<key<<" "<<mp[key]<<endl;
            return mp[key];
        }

        // vector<int> freq(26, 0);
        // for (char &c : s1) {
        //     freq[c - 'a']++;
        // }
        // for (char &c : s2) {
        //     freq[c - 'a']--;
        // }
        // for (int &i : freq) {
        //     if (i != 0) 
        //     return mp[key] = false;
        // }

        for(int len=1;len<s1.length();len++)
        {
            if(isScramble(s1.substr(0,len),s2.substr(s1.length()-len)) && isScramble(s1.substr(len),s2.substr(0,s1.length()-len)))
            {
//                if(isScramble(s1.substr(0,len),s2.substr(s1.length()-len)))
//                cout<<s1.substr(0,len)<<" 1.1 "<<s2.substr(s1.length()-len)<<endl;
//                if(isScramble(s1.substr(len),s2.substr(0,s1.length()-len)))
//                cout<<s1.substr(len)<<" 1.2 "<<s2.substr(0,s1.length()-len)<<endl;
                // vector<int> freq(26, 0);
                // for (char &c : s1) {
                //     freq[c - 'a']++;
                // }
                // for (char &c : s2) {
                //     freq[c - 'a']--;
                // }
                // for (int &i : freq) {
                // if (i != 0) 
                // return mp[key] = false;
                // }
                return mp[key]=true;
                break;
            }
            if(isScramble(s1.substr(0,len),s2.substr(0,len)) && isScramble(s1.substr(len),s2.substr(len)))
            {
//                if(isScramble(s1.substr(0,len),s2.substr(0,len)))
//                cout<<s1.substr(0,len)<<" 2.1 "<<s2.substr(0,len)<<endl;
//                if(isScramble(s1.substr(len+1),s2.substr(len+1)))
//                cout<<s1.substr(len+1)<<" 2.2 "<<s1.substr(len+1)<<endl;
                // vector<int> freq(26, 0);
                // for (char &c : s1) {
                //     freq[c - 'a']++;
                // }
                // for (char &c : s2) {
                //     freq[c - 'a']--;
                // }
                // for (int &i : freq) {
                // if (i != 0) 
                // return mp[key] = false;
                // }
                return mp[key]=true;
                break;
            }
        }
        return mp[key]=false;
    }
};
