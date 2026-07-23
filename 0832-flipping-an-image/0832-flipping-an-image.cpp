class Solution {
public:
    vector<vector<int>>& flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int r = 0; r < n; r++) {
            int left = 0, right = n - 1;
            while (left <= right){
                if (left == right){
                    image[r][left] ^= 1;
                } 
                else if (image[r][left] == image[r][right]){
                    image[r][left] ^= 1;
                    image[r][right] ^= 1;
                }                
                left++;
                right--;
            }
        }
        return image;
    }
};