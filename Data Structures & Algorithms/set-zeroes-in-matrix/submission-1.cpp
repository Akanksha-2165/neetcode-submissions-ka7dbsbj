class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        bool zeroCol=false;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)  {
                if(matrix[i][j] == 0)   {
                    if(j == 0)
                        zeroCol = true;
                    else
                        matrix[0][j] = 0;

                    matrix[i][0] = 0;
                }
            }
        }
        //first row and col are already marked
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++)  {
                if(matrix[i][0]==0 || matrix[0][j]==0) 
                    matrix[i][j]=0;
            }
        }
        if(matrix[0][0]==0) 
            for(int j=0; j<n; j++)   
                matrix[0][j]=0;

        if(zeroCol) 
            for(int i=0; i<m; i++)   
                matrix[i][0]=0;
    }
};
/*
INTUITION:
- Use the first row and first column as marker arrays.
- If matrix[i][j] == 0:
    - mark row  -> matrix[i][0] = 0
    - mark col  -> matrix[0][j] = 0
- matrix[0][0] is shared by both the first row and first column,
  so use one extra boolean (zeroCol) to track whether the first
  column should be zero.
- Update the inner matrix first (i=1, j=1), then handle the first
  row and first column separately.

Time Complexity : O(m * n)
Space Complexity: O(1)
*/
