class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            
            if(nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }

        if(nums[l] >= target) return l;
        return l+1;
    }
};