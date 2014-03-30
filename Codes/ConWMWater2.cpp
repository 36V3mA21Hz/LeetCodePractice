class Solution {
public:
    int maxArea(vector<int> &height) {
      if (height.empty())
        return 0;
      int n = (int)height.size();
      int max = 0, mL = height[0], mH = height[0], iL = 0, iH = 0;
        for (int i = 1; i < n; i++) {
            int ai = height[i];
            int m1 = min(ai, mL) * (i - iL);
            int m2 = min(ai, mH) * (i - iH);
            if (m1 > max || m2 > max) {
                if (m1 >= m2) {
                    max = m1;
                    if (ai < mL) {
                        mH = mL, iH = iL;
                        mL = ai, iL = i;
                    } else {
                        mH = ai, iH = i;
                    }
                } else {
                    max = m2;
                    if (ai < mH) {
                        mL = ai, iL = i;
                    } else {
                        mL = mH, iL = iH;
                        mH = ai, iH = i;
                    }
                }
            }
        }
      return max;
    }
};
