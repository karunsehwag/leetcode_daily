class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> vec;
        for(int i=0;i<nums.size();i++)
        {
            if(x==nums[i])
                vec.push_back(i);
        }
        vector<int> answer;
        for(int q:queries)
        {
            if(vec.size()>=q)
                answer.push_back(vec[q-1]);
            else
                answer.push_back(-1);
        }
        return answer;
        
    }
};