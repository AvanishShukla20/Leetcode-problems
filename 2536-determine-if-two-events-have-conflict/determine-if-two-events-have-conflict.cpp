class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string curr_s = event1[0], curr_e = event1[1], next_s = event2[0], next_e = event2[1];
 
        if(curr_s <= next_s && curr_e >= next_s) return true;
        else if(curr_s > next_s && curr_s <= next_e) return true;
        return false;
    }
};