class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right= height.size()-1;
        int water=0;

        int left_max= 0,
        right_max=0;

        while(left<right)   {
            
            if(height[left] < height[right])    {
                if(height[left]>= left_max)
                    left_max= height[left];
                else
                    water+= left_max- height[left];
                left++;
            }

            else    {
                if(height[right] >= right_max)
                    right_max= height[right];
                else
                    water+= right_max- height[right];
                right--;
            }
        }
        return water;
    }
};

// BRUTE FORCE
/*
for every i:
leftMax = maximum height from 0 to i
rightMax = maximum height from i to n-1
water += min(leftMax, rightMax) - height[i]
TC- O(n^2), SC- O(1)

//BETTER 
leftMax[i]  = max(leftMax[i-1], height[i])
rightMax[i] = max(rightMax[i+1], height[i])
water += min(leftMax[i], rightMax[i]) - height[i]
TC- O(n), SC- O(n)

//OPTIMAL
Water = min(leftMax, rightMax) - currentHeight.
Use two pointers and maintain leftMax & rightMax.
Process the smaller side since its water level is already fixed.
TC- O(n), SC- O(1)
*/
