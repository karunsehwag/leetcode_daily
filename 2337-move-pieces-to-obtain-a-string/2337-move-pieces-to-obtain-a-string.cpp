class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int startindex=0,targetindex=0;
        while(startindex<n||targetindex<n)
        {
            while(startindex<n&&start[startindex]=='_')
                startindex++;
            while(targetindex<n&& target[targetindex]=='_')
                targetindex++;
            if(startindex==n||targetindex==n)
                return startindex==n&&targetindex==n;
            
            if(start[startindex]!=target[targetindex]||(start[startindex]=='L'&&startindex<targetindex)||(start[startindex]=='R'&&startindex>targetindex))
                return false;
            
            startindex++;
            targetindex++;
        }
        
        return true;
        
    }
};