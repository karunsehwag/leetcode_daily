class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> atomCounts;
        stack<map<string, int>> stk;
        int i = 0;
        int n = formula.size();
        
        while (i < n) {
            if (formula[i] == '(') {
                stk.push(atomCounts);
                atomCounts.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                num = (num == 0) ? 1 : num;
                
                if (!stk.empty()) {
                    map<string, int> top = stk.top();
                    stk.pop();
                    for (auto &p : atomCounts) {
                        top[p.first] += p.second * num;
                    }
                    atomCounts = top;
                }
            } else {
                string atom;
                atom += formula[i++];
                while (i < n && islower(formula[i])) {
                    atom += formula[i++];
                }
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                num = (num == 0) ? 1 : num;
                atomCounts[atom] += num;
            }
        }
        
        string ans;
        for (auto &p : atomCounts) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }
        
        return ans;
    }
};


