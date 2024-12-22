class MyCalendar {
public:
    vector<vector<int>> vec;
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        int prevs,preve;
        bool p = true;
        for(int i=0; i<vec.size(); i++)
        {
            prevs = vec[i][0], preve = vec[i][1];
            if(preve > startTime && prevs < endTime) return false;
        }
        vec.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */