class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p1=0;
        int max_len=0;
        unordered_map<char, int> m;
        for (int p2=0; p2<s.length(); p2++){
            if (m.find(s[p2])!=m.end()){
                p1=max(p1, m[s[p2]]);
            }
            max_len= max(max_len, p2-p1+1);
            m[s[p2]]=p2+1;
        }
        return max_len;
    }
};