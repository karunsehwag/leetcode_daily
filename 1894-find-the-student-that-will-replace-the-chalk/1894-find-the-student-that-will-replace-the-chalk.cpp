class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long ans=0;
        for(int x:chalk)
            ans+=x;
        k=k%ans;
        int index=0;
        for(int i=0;i<chalk.size();i++)
        {
           if(chalk[i]>k)
               return i;
            k=k-chalk[i];
            
        }
        
        return 0;
    }
};