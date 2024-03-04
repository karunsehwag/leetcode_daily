class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0;
        int z=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        int ans=0;
        int count=0;
        while(z>=i)
        {
           if(power>=tokens[i])
           {
             power=power-tokens[i];
               i++;
               count++;
               ans=max(ans,count);
           }
            
            else if(count>0)
            {
                count--;
                power=power+tokens[z];
                z--;
            }
            else
            {
                break;
            }
            
        }  
            return ans;
        
    }
};