class Solution {
public:
    int nthUglyNumber(int n) {
        
        set<long> pq;
        pq.insert(1);
        long long  val=1;
        for(int i=1;i<=n;i++)
        {
            val=*pq.begin();
            pq.erase(pq.begin());
            pq.insert(val*2);
            pq.insert(val*3);
            pq.insert(val*5);
        }
        
        return val;
        
    }
};