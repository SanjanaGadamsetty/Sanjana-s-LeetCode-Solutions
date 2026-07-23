class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int curr_prod= 1;
        int count= 0;
        int left= 0;
        for (int i= 0; i< nums.size(); i++){
            curr_prod*= nums[i];
            while (curr_prod>= k){
                curr_prod/= nums[left];
                left++;
            }
            count+= i-left+1;
        }
        return count;
    }
};