class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        vector<vector<int>> bestSteps(ringLen, vector<int>(keyLen + 1, INT_MAX));
   
        for (auto& row : bestSteps) {
            fill(row.begin(), row.end(), INT_MAX);
        }
    
        for (int i = 0; i < ringLen; i++) {
            bestSteps[i][keyLen] = 0;
        }
   
        for (int keyIndex = keyLen - 1; keyIndex >= 0; keyIndex--) {
            for (int ringIndex = 0; ringIndex < ringLen; ringIndex++) {
                for (int charIndex = 0; charIndex < ringLen; charIndex++) {
                    if (ring[charIndex] == key[keyIndex]) {
                        bestSteps[ringIndex][keyIndex] = min(bestSteps[ringIndex][keyIndex],
                                1 + countSteps(ringIndex, charIndex, ringLen) 
                                + bestSteps[charIndex][keyIndex + 1]);
                    }
                }
            }
        }

        return bestSteps[0][0];
    }

private:

    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }
};