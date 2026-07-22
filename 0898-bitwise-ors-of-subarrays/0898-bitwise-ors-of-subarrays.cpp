class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;

        for (int i= 0; i< arr.size(); i++){
            unordered_set<int> curr;
            curr.insert(arr[i]);
            for (int n: prev){
                curr.insert(n | arr[i]);
            }
            result.insert(curr.begin(), curr.end());
            prev= curr;
        }
        return result.size();
    }
};