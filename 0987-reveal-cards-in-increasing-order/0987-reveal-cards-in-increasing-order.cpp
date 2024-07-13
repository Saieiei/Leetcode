class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> st;
        st.push_front(deck[n - 1]);
        
        for (int i = n - 2; i >= 0; i--) {
            st.push_front(st.back());
            st.pop_back();
            st.push_front(deck[i]);
        }

        vector<int> revealed;
        for (int i = 0; i < n; i++) {
            revealed.push_back(st.front());
            st.pop_front();
        }
        return revealed;
    }
};