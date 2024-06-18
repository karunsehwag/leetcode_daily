class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int ans = 0, best = 0, j = 0;
        for (int i = 0; i < worker.size(); ++i) {
         
            while (j < jobs.size() && jobs[j].first <= worker[i]) {
                best = max(best, jobs[j].second);
                ++j;
            }
            ans += best;
        }

        return ans;
    }
};
