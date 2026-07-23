class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_len= 1;
        int curr_len= 1;

        for (int i= 1; i< nums.size(); i++){
            if (nums[i]> nums[i-1]) curr_len++;
            else curr_len= 1;
            max_len= max(curr_len, max_len);
        }
        return max_len;
    }
};