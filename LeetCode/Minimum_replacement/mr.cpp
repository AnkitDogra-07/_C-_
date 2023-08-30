/*
You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.

For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
Return the minimum number of operations to make an array that is sorted in non-decreasing order.

 

Example 1:

Input: nums = [3,9,3]
Output: 2
Explanation: Here are the steps to sort the array in non-decreasing order:
- From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
- From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
There are 2 steps to sort the array in non-decreasing order. Therefore, we return 2.

Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: The array is already in non-decreasing order. Therefore, we return 0. 
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109


Runtime
89ms


Memory
54.59MB
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum number of replacements to make the array non-decreasing.
long long minimumReplacement(vector<int>& nums) {
    int n = nums.size();  // Get the size of the input array.
    long long ans = 0;    // Initialize the number of replacements to 0.
    int last = nums[n - 1];  // Start with the last element of the array.

    // Iterate through the array from right to left, starting from the second-to-last element.
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] > last) {
            int t = nums[i] / last;  // Calculate how many times the current element can be divided by the last element.
            if (nums[i] % last) t++; // If there's a remainder, add 1 to t.
            last = nums[i] / t;      // Update the last element to be the result of the division.
            ans += (t - 1);          // Increment the number of replacements by (t - 1).
        } else {
            last = nums[i];  // If the current element is not greater than the last, update the last element.
        }
    }
    return ans;  // Return the total number of replacements.
}

int main() {
    vector<int> nums = {5, 8, 7};
    long long result = minimumReplacement(nums);
    cout << "Minimum number of replacements: " << result << endl;

    return 0;
}
