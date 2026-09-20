#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            auto it = seen.find(complement);

            if (it != seen.end()) {
                return {it->second, i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution s;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = s.twoSum(nums, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}