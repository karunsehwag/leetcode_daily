class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int maxarea=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty()&&heights[i]<heights[s.top()])
            {
                int height=heights[s.top()];
                s.pop();
                int width=s.empty()?i:(i-s.top()-1);
                maxarea=max(maxarea,width*height);
            }
            s.push(i);
        }
        return maxarea;
        
    }
};