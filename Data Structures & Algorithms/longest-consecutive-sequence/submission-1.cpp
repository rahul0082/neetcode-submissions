class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto &v: nums) {
            mp.insert(v);
        }

        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(mp.find(nums[i]-1) != mp.end()) {
                continue;
            }
            int itr = nums[i];
            int l = 0;
            while(mp.find(itr) != mp.end()) {
                l++;
                itr++;
            }
            ans = max(l, ans);
        }
        return ans;
    }
};
