//Shortcut
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i = 0; i < asteroids.size(); i++){
            if (asteroids[i] > 0) res.push_back(asteroids[i]);
            else if (res.empty() || res.back() < 0) res.push_back(asteroids[i]);
            else if (res.back() <= -asteroids[i]){
                if (res.back() < -asteroids[i]) --i; 
                res.pop_back(); 
            }
        }
        return res; 
    }
};
//My Solution
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size(), a, b;
        stack<int> stk;
        stk.push(ast[0]);
        for(int i=1;i<n;i++)
        {
            a=stk.top();
            b=ast[i];
            if(a>=0 && b<0)
            {
                if(a<abs(b))
                {
                    while(a>=0 && a<abs(b))
                    {
                        stk.pop();
                        if(stk.size()==0)
                        break;
                        a=stk.top();
                    }
                    if(stk.size()==0 || a<0)
                    stk.push(b);
                    else if(a==abs(b))
                    {
                        stk.pop();
                        if(stk.size()==0)
                        {
                            i++;
                            if(i<n)
                            stk.push(ast[i]);
                        }
                    }
                }
                else if(a==abs(b))
                {
                    stk.pop();
                    if(stk.size()==0)
                    {
                        i++;
                        if(i<n)
                        stk.push(ast[i]);
                    }
                }
            }
            else stk.push(ast[i]);
        }
        n=stk.size();
        if(n==0) return {};
        vector<int> v(n);
        for(int i=n-1;i>=0;i--)
        {
            v[i]=stk.top();
            stk.pop();
        }
        return v;
    }
};
