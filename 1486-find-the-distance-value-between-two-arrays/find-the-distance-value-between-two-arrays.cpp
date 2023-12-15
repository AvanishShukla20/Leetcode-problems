class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res=0, flag;
        for(int i=0; i< arr1.size(); i++)
        {
            flag=0;
            for(int j=0; j< arr2.size(); j++)
            {
                if( abs(arr2[j]-arr1[i]) <= d ) flag=1;
            }
            cout<<"res be : "<<res<<endl;
            if(flag==0) res+=1;
            cout<<"res af : "<<res<<endl;

        }
        return res;
    }
};