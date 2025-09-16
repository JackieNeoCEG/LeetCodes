class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st; // acts like a stack

        for (int x : nums) {
            st.push_back(x);

            // keep merging while top two are non-coprime
            while (st.size() >= 2) { // ensures at least 2 numbers to compare
                int a = st.back();
                int b = st[st.size() - 2];

                if (std::gcd(a, b) > 1) {
                    int l = std::lcm(a, b);
                    st.pop_back();
                    st.pop_back();
                    st.push_back(l);
                } else {
                    break;
                }
            }
        }
        return st;
    }
};