class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long int ans=0;
        if(skill.size()%2==1)
            return -1;
        sort(skill.begin(),skill.end());
        int i=0,n=skill.size();
        int j=n-1; 
        long long int k=skill[0]+skill[j];
        while(j>i)
        {  if(skill[i]+skill[j]!=k)
              return -1;
           ans+=skill[i]*skill[j];
            i++;
            j--;
        }
        return ans;  
    }
};