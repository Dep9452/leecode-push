class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        stack<NestedInteger> st;
        st.push(NestedInteger());

        string num = "";

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '-') {
                num += '-';
            }
            else if (isdigit(s[i])) {
                num += s[i];
            }
            else if (s[i] == ',' || s[i] == ']') {
                if (!num.empty()) {
                    st.top().add(NestedInteger(stoi(num)));
                    num = "";
                }

                if (s[i] == ']') {
                    if (st.size() > 1) {
                        NestedInteger temp = st.top();
                        st.pop();
                        st.top().add(temp);
                    }
                }
            }
            else if (s[i] == '[') {
                st.push(NestedInteger());
            }
        }

        return st.top();
    }
};