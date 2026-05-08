class Solution {
public:
    int search(vector<int>& nums, int target) {
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

        return nums[l] == target ? l : -1;
    }
};
