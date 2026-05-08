class Solution {
    vector<vector<int>> result;
    void traverse(vector<int>& c, vector<int>& nums, int target, int idx, int curSum) {
        if(curSum > target || idx >= nums.size()) {
            return;
        }

        if(curSum  == target) {
            result.push_back(c);
            return;
        }

        c.push_back(nums[idx]);
        curSum += nums[idx];

        traverse(c, nums, target, idx, curSum);
        c.pop_back();
        curSum -= nums[idx];
        traverse(c, nums, target, idx + 1, curSum);

        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combination;
        traverse(combination, nums, target, 0, 0);

        return result;
    }
};
