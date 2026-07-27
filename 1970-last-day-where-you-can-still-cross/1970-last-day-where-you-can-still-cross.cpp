class Solution {
private:
    int Find(vector<int> &l_arr, int node){
        if (l_arr[node]== node) return node;
        return l_arr[node]= Find(l_arr, l_arr[node]);
    }

    void join(vector<int> &l_arr, int left, int right){
        l_arr[Find(l_arr, left)]= Find(l_arr, right);
    }

public:
    int latestDayToCross(int R, int C, vector<vector<int>>&cells) {
        int days= 0;
        vector<bool> water(R* C+ 2, false);
        vector<int> l_arr(R* C+ 2);
        for (int i= 0; i<= R* C+ 1; i++) l_arr[i]= i;

        vector<vector<int>> diff= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (vector<int> cell: cells){
            int row= cell[0];
            int col= cell[1];
            row--;
            col--;

            water[row* C+ col+ 1]= true;

            for (vector<int> d: diff){
                int ar= row+ d[0];
                int ac= col+ d[1];

                if (ar>= 0 && ar< R && ac>= 0 && ac< C && water[ar* C+ ac+ 1]){
                    join(l_arr, row* C+ col+ 1, ar* C+ ac+ 1);
                }
            }

            if (col== 0){
                join(l_arr, 0, row* C+ col+ 1);
            }

            if (col== C- 1){
                join(l_arr, R* C+ 1, row* C+ col+ 1);
            }

            if (Find(l_arr, 0)== Find(l_arr, R* C+ 1)) break;

            days++;
        }

        return days;
    }
};