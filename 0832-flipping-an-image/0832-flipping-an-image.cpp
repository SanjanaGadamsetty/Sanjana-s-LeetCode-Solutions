class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int N= image.size();
        for (int r= 0; r< N; r++){
            reverse(image[r].begin(), image[r].end());
        }
        for (int r= 0; r< N; r++){
            for (int c= 0; c< N; c++){
                if (image[r][c]== 0) image[r][c]= 1;
                else image[r][c]= 0;
            }
        }
        return image;
    }
};