class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m =matrix.size(), n= matrix[0].size();
        int top=0,
        bottom= m-1,
        left =0,
        right = n-1 ;

        vector<int> spiral;
        
        while( left<= right && top <= bottom)   {
            //left to right
            for(int i=left; i<=right; i++)
                spiral.push_back(matrix[top][i]);
            top++;
            //top to bottom
            for(int i=top; i<=bottom; i++)  
                spiral.push_back(matrix[i][right]);
            right--;

            if(top<= bottom)    {
                for(int i=right; i>=left; i--)  
                    spiral.push_back(matrix[bottom][i]);
                bottom--;
            }
            if(left<= right)    {
                for(int i=bottom; i>=top; i--)  
                    spiral.push_back(matrix[i][left]);
                left++;
            }
        }
        return spiral;
    }
};
/*
INTUITION:
- Think of the matrix as a shrinking rectangle.
- Maintain 4 boundaries:
    top    -> first unvisited row
    bottom -> last unvisited row
    left   -> first unvisited column
    right  -> last unvisited column
- Traverse in the order:
    Right → Down → Left → Up
- After each traversal, move the corresponding boundary inward.
- Before traversing Left and Up, check if the remaining rectangle is still valid
  (to avoid revisiting elements in single-row/single-column cases).

Traversal:
1. Top row    : left -> right,   top++
2. Right col  : top -> bottom,   right--
3. Bottom row : right -> left,   bottom--   (if top <= bottom)
4. Left col   : bottom -> top,   left++     (if left <= right)

Time Complexity : O(m * n)
Space Complexity: O(1)   // excluding the output vector
*/
