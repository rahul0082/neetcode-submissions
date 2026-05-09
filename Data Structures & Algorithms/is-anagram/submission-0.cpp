class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count_s = vector<int>(26, 0);
        vector<int> count_t = count_s;

        for(auto &v: s) {
            count_s[v - 'a']++;
        }

        for(auto &v: t) {
            count_t[v - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(count_s[i] != count_t[i]) return false;
        }

        return true;
    }
};
