class Solution {
public:
    int dayOfYear(string date) {
        bool isLeap=0;
        int res=0;
        int i=0;
        
        int year;
        year= (date[0] - '0')*1000 + (date[1] - '0')*100 + (date[2] - '0')*10 + date[3] - '0' ;

        if( year %4 == 0 and year != 1900) isLeap=1;
       
        int month = (date[5]-'0')*10 + date[6] - '0' ;

        

        int j=1;

        while(j <= month-1)
        {
            if(j<8)
            {
                if(j==2) res+=28;
                else if(j%2 !=0) res +=31 ;
                else res += 30;
            }

            else
            {
                
                if(j%2 !=0) res +=30 ;
                else res += 31;
            }
            j++;
        }
        
        int dt = (date[8] - '0')*10  + date[9] - '0' ;
        
        res = res + dt;

        if(isLeap and month > 2) res+=1;

        return res;
    }
};