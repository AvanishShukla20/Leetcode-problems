class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        int i=0;
        while( i< operations.size() )
        {
            if(operations[i]=="C")
            {
                if(!st.empty()) st.pop();   
            }

            else if(operations[i]=="D")
            {
                st.push( 2*st.top() );
            }
            else if(operations[i]=="+")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                int z=x+y;
                st.push(y);
                st.push(x);
                st.push(z);
            }
            else
            {
                st.push( stoi(operations[i]));
            }
            i++;
        }

        int res=0;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};