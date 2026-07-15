class Solution {
public:
    bool solve(vector<int>& nums, int k, int currsum, int start_index, int target, vector<int>& vis, int count) {
        // If we have successfully formed k-1 subsets, the last one is guaranteed
        if (count == k - 1) return true;
        
        // If current subset sum reached target, start building the next subset
        if (currsum == target) {
            return solve(nums, k, 0, 0, target, vis, count + 1);
        }
        
        for (int i = start_index; i < nums.size(); i++) {
            if (vis[i] == 0 && currsum + nums[i] <= target) {
                vis[i] = 1;
                if (solve(nums, k, currsum + nums[i], i + 1, target, vis, count)) 
                    return true;
                vis[i] = 0; // Backtrack
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        
        // Sorting helps in pruning the search space
        sort(nums.rbegin(), nums.rend());
        
        vector<int> vis(nums.size(), 0);
        return solve(nums, k, 0, 0, total / k, vis, 0);
    }
};