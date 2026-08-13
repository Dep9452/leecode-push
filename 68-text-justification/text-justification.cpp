class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;

        while(i < words.size()) {
            int j = i, len = 0;

            while(j < words.size() && len + words[j].size() + (j-i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int spaces = maxWidth - len;
            int cnt = j - i;
            string line;

            if(j == words.size() || cnt == 1) {
                for(int k=i; k<j; k++) {
                    if(k > i) line += " ";
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int gap = cnt - 1;
                int each = spaces / gap;
                int extra = spaces % gap;

                for(int k=i; k<j; k++) {
                    line += words[k];

                    if(k < j-1) {
                        line += string(each, ' ');
                        if(extra > 0) {
                            line += " ";
                            extra--;
                        }
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};