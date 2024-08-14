class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        
        sort(clips.begin(),clips.end());
        int i=0;
        int currenthand=0;
        int farthest=0;
        int count=0;
        while(time>currenthand)
        {
            
            while(clips.size()>i&&clips[i][0]<=currenthand)
            {
                farthest=max(clips[i][1],farthest);
                i++;
            }
            if(farthest<=currenthand)
                return -1;
            currenthand=farthest;
            count++;
        }
        
        return count;
        
    }
};