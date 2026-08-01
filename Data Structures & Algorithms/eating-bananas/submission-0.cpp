class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = 0;
        for(int pile :piles)
            high= max(high, pile);
        
        while(low <= high)  {
            int mid = low + (high-low)/2;
            //find out the hour with the mid
            int hours=0;
            for(int i =0; i<piles.size(); i++)
                hours+= ceil((double)piles[i] / mid);
            if(hours <= h)
                high= mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};

//BRUTE
// Try every possible eating speed from 1 to the largest pile.
// For each speed, calculate the total hours required to finish all piles.
// Return the first speed that finishes within h hours.
// Time Complexity: O(n * maxPile)    Space Complexity: O(1)

//OPTIMAL (binary search on answers)
// The answer is the eating speed (k), not an index in the array.
// As the eating speed increases, the total hours required can only
// decrease or stay the same (monotonic property).
// Binary search the possible speed range [1, maxPile].
// If a speed finishes within h hours, try a smaller speed.
// Otherwise, increase the speed.

// Binary Search Note:
// - low always points to the first possible valid speed.
// - high always points to the last invalid speed.
// When the loop ends (low > high),
// low becomes the minimum valid answer, so return low.
//
// Time Complexity: O(n * log(maxPile))   Space Complexity: O(1)
