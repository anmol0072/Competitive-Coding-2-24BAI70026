class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                }
                int oldDiff = diff;
                diff = abs(sum - target);
                if (oldDiff >= diff) {
                    ans = sum;
                } else {
                    diff = oldDiff;
                }
                if (diff == 0) {
                    return ans;
                }
            }
        }
        return ans;
    }
};