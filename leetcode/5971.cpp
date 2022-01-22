class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = 0;
        for (int i = cost.size() - 1; i >= 0; i--) {
            if (i >= 0) {
                ans += cost[i];
                printf("get %d\n", cost[i]);
                i--;
            }
            if (i >= 0) {
                ans += cost[i];
                printf("get %d\n", cost[i]);
                i--;
            }
        }
        return ans;
    }
};