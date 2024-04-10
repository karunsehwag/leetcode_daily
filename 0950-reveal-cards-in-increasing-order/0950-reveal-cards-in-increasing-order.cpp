class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int k=0;
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int> vec(n,0);
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        
        while(!q.empty())
        {
            vec[q.front()]=deck[k];
            k++;
            q.pop();
            if(!q.empty())
            {
                q.push(q.front());
                cout<<q.front();
                q.pop();
            }
        }
        return vec;
        
    }
};