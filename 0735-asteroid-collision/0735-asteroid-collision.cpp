class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int ast:asteroids)
        { int flag=1;
            while(!ans.empty()&&(ast<0&&ans.back()>0))
            {
                if(abs(ast)>abs(ans.back()))
                {
                    ans.pop_back();
                    continue;
                }
                else if(abs(ast)==abs(ans.back()))
                {   ans.pop_back();
                   
                   
                }  
                flag=0;
                break;
            }
         if(flag)
             ans.push_back(ast);
        }
        
        return ans;
    }
};