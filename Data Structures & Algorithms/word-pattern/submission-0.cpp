class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp;
        unordered_map<string, char> rev;

        int i = 0;

        for (int j = 0; j < pattern.size(); j++) {
            if (i >= s.size()) return false;

            string word = "";

            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // pattern character already mapped to another word
            if (mpp.find(pattern[j]) != mpp.end()) {
                if (mpp[pattern[j]] != word)
                    return false;
            }
            else {
                // word already mapped to another character
                if (rev.find(word) != rev.end())
                    return false;

                mpp[pattern[j]] = word;
                rev[word] = pattern[j];
            }

            // skip space
            if (i < s.size())
                i++;
        }

        // Extra words remaining
        if (i < s.size())
            return false;

        return true;
    }
};