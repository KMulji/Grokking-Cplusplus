#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

/*
    Problem 1: Two pair with target sum

    Given an array of numbers sorted in ascending order and a target sum, find a pair in the array whose sum is equal to the given target.

    Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target. If no such pair exists return [-1, -1].

    Example 1:

    Input: [1, 2, 3, 4, 6], target=6
    Output: [1, 3]
    Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
    Example 2:

    Input: [2, 5, 9, 11], target=11
    Output: [0, 2]
    Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11
    Constraints:

    2 <= arr.length <= 104
    -109 <= arr[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/
vector<int> PairSum(vector<int> &nums,int target)
{
    std::sort(nums.begin(),nums.end());

    int i=0;
    int j=nums.size()-1;
    vector<int> ans;
    while(i<j)
    {
        if(nums[i]+nums[j]==target)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }else if(nums[i]+nums[j]>target)
        {
            j--;
        }else if(nums[i]+nums[j]<target)
        {
            i++;
        }
    }
    return {};
}
/*
    Given an array of sorted numbers, move all non-duplicate number instances at the beginning of the array in-place. The non-duplicate numbers should be sorted and you should not use any extra space so that the solution has constant space complexity i.e., .

    Move all the unique number instances at the beginning of the array and after moving return the length of the subarray that has no duplicate in it.

    Example 1:

    Input: [2, 3, 3, 3, 6, 9, 9]
    Output: 4
    Explanation: The first four elements after moving element will be [2, 3, 6, 9].
    Example 2:

    Input: [2, 2, 2, 11]
    Output: 2
    Explanation: The first two elements after moving elements will be [2, 11].
    Constraints:

    1 <= nums.length <= 3 * 104
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.
*/
int NonDuplicate(vector<int> &nums)
{
    int nextNonDuplicate = 1;
    
    for(int i=0;i<nums.size();i++)
    {
        if(nums[nextNonDuplicate-1]!=nums[i])
        {
            nums[nextNonDuplicate] = nums[i];
            nextNonDuplicate++;
        }
    }
    return nextNonDuplicate;
}

/*
    Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.

    Example 1:

    Input: [-2, -1, 0, 2, 3]
    Output: [0, 1, 4, 4, 9]
    Example 2:

    Input: [-3, -1, 0, 1, 2]
    Output: [0, 1, 1, 4, 9]
    Constraints:

    1 <= arr.length <= 104
    -104 <= arr[i] <= 104
    arr is sorted in non-decreasing order.
*/

vector<int> MakeSquares(vector<int> & nums)
{
    vector<int> ans(nums.size());
    int k=ans.size()-1;

    int i=0;
    int j=nums.size()-1;

    while(i<j)
    {
        int leftPow = pow(nums[i],2);
        int rightPow = pow(nums[j],2);

        if(leftPow>rightPow)
        {
            ans[k--]=leftPow;
            i++;
        }else if(rightPow>leftPow)
        {
            ans[k--]=rightPow;
            j--;
        }else if(rightPow==leftPow)
        {
            ans[k--]=leftPow;
            ans[k--]=rightPow;
            i++;
            j--;
        }
        
    }
    if(k>0)
    {
        ans[k] = pow(nums[i],2);
    }
    
    return ans;
}
int main()
{
    vector<int> nums1 = {-7,-3,2,3,11};
    vector<int> ans2 = MakeSquares(nums1);

    for(auto x:ans2)
    {
        std::cout<<x<<std::endl;
    }
    return 0;
}