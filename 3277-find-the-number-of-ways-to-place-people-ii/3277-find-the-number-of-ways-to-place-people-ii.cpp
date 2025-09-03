class Solution {
public: 
   static bool comparator(const vector<int>&a , const vector<int>&b)
   {
       return(a[0]==b[0])?a[1]>b[1]:a[0]<b[0] ;
   }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin() , points.end() , &comparator) ;
        int result = 0 ;
      int   ymin = INT_MIN ;
      int   ymax = 0;
        for(int i = 0 ; i<points.size()  ; i++)
        {  ymax = points[i][1];
        ymin = INT_MIN ;
            for(int j = i+1 ; j<points.size() ; j++)
            {
       
           
            if(ymax>=points[j][1]&&ymin<points[j][1])
            {  ymin = points[j][1] ;
                result++ ;
            }
            }
        }
        return result ;
    }
};