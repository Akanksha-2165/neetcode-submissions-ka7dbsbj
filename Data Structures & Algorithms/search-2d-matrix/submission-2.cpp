class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size(), n= matrix[0].size(); //m-rowa, n-cols
        int left=0, right= m*n -1;

        while(left <= right)   {
            int mid= left + ( right- left)/2;
            int row= mid / n;
            int col= mid % n;

            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                left= mid+1;
            else
                right= mid-1;
        }
        return false;
    }
};
//BRUTE
// Traverse every element in the matrix and compare it with the target.
// Time: O(m*n)      Space: O(1)

//BETTER (Binary Search Row + Column)
// First identify the row whose range may contain the target.
// Then perform binary search within that row.
// Time: O(log m + log n)     Space: O(1)

//OPTIMAL (Treat Matrix as 1D Array)
// Since every row is sorted and the first element of each row is
// greater than the last element of the previous row, the entire
// matrix behaves like one sorted array.
// Perform binary search over indices [0, m*n-1].
// Convert the middle index into (row, col) using:
// row = mid / cols
// col = mid % cols.
// Time: O(log(m*n))      Space: O(1)