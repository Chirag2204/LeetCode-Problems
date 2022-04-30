class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       
        deque<int> q;
        sort(deck.rbegin(), deck.rend());
        int n=deck.size();
        q.push_back(deck[0]);
        for(int i=1;i<n;i++){
            q.push_front(q.back());
            q.pop_back();
            q.push_front(deck[i]);
        }
       vector<int>res(q.begin(),q.end());
        return res;
    }
};