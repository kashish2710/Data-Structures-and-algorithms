class Solution {
   public:
    string minWindow(string s, string t) {
        int require = t.size();
        int i = 0;
        int j = 0;
        int n = s.size();
        int window = INT_MAX;
        int start_index = 0;
        unordered_map<char, int> mpp;

        for (char ch : t) {
            mpp[ch]++;
        }
        while (j < n) {
            char ch = s[j];

            if (mpp[ch] > 0) {
                require--;
            }
            mpp[ch]--;

            while (require == 0) {
                // shrink
                if (window > j - i + 1) {
                    window = j - i + 1;
                    start_index = i;
                }
                mpp[s[i]]++;

                if (mpp[s[i]] > 0) {
                    require++;
                }
                i++;
            }
            j++;
        }
        return window==INT_MAX?"":s.substr(start_index,window);
    }
};
