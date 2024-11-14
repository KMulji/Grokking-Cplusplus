#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using std::vector;
using std::set;

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
/*
    Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

    Example 1:

    Input: [-3, 0, 1, 2, -1, 1, -2]
    Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]
    Explanation: There are four unique triplets whose sum is equal to zero. smallest sum.'
    Example 2:

    Input: [-5, 2, -1, -2, 3]
    Output: [[-5, 2, 3], [-2, -1, 3]]
    Explanation: There are two unique triplets whose sum is equal to zero.
    Constraints:

    3 <= arr.length <= 3000
    -105 <= arr[i] <= 105

    sorted = -3,-2,-1,0,1,1,2

    i+j+k=0
    j+k=-i

*/
vector<vector<int>> ThreeSum(vector<int> &nums)
{
    std::sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    
    set<vector<int>> st;
    
    for(int i=0;i<nums.size()-1;i++)
    {
        int j=i+1;
        int k = nums.size()-1;

        while(j<k)
        {
            if(nums[j]+nums[k]==-nums[i])
            {
                if(st.find({nums[i],nums[j],nums[k]})==st.end())
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                }
                j++;
                k--;
                
            }else if(nums[j]+nums[k]<-nums[i])
            {
                j++;
            }else if(nums[j]+nums[k]>-nums[i])
            {
                k--;
            }
        }
    }
    return ans;
}

/*
    Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

    Example 1:

    Input: [-1, 0, 2, 3], target=3 
    Output: 2
    Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
    Example 2:

    Input: [-1, 4, 2, 1, 3], target=5 
    Output: 4
    Explanation: There are four triplets whose sum is less than the target: 
    [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
    Constraints:

    n == arr.length
    0 <= n <= 3500
    -100 <= arr[i] <= 100
    -100 <= target <= 100
*/
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
         
    int minDiff = INT_MAX;
    int minSum=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
        int j=i+1;
        int k = nums.size()-1;

        while(j<k)
        {
            int sum = nums[i]+nums[j]+nums[k];
            int diff = abs(target-sum);

            if(diff<= minDiff)
            {
                minDiff=diff;
                minSum = sum;
            }
            if(nums[j]+nums[k] +nums[i] == target)
            {
                return target;
            }else if(nums[j]+nums[k]+nums[i]>target)
            {
                k--;
            }else if(nums[j]+nums[k]+nums[i]<target)
            {
                j++;
            }
        }
    }
    return minSum;
}
/*
    Given an array with positive numbers and a positive target number, find all of its contiguous subarrays whose product is less than the target number.

    Example 1:

    Input: [2, 5, 3, 10], target=30                                              
    Output: [2], [5], [2, 5], [3], [5, 3], [10]                           
    Explanation: There are six contiguous subarrays whose product is less than the target.
    Example 2:

    Input: [8, 2, 6, 5], target=50                                              
    Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5]                         
    Explanation: There are seven contiguous subarrays whose product is less than the target.
    Constraints:

    1 <= arr.length <= 3 * 104
    1 <= arr[i] <= 1000
    0 <= k <= 106
*/
vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;
    if(target<=1)
    {
        return {};
    }
    int count =0;
    int start=0;
    int product=1;

    for(int end=0;end<arr.size();end++)
    {
        product*=arr[end];

        while(start<arr.size() && product>=target)
        {
            product/=arr[start];
            start++;
        }
        vector<int> templist;

        for(int i=end ; i>=start;i--)
        {
            templist.insert(templist.begin(),arr[i]);

            result.push_back(templist);
        }
    }

    return result;
  }
int main()
{
    vector<int> nums1 = {2, 5, 3, 10};
    vector<vector<int>> ans = findSubarrays(nums1,30);

    for(auto x:ans)
    {
        for(auto y:x)
        {
            std::cout<<y;
        }
        std::cout<<std::endl;
    }
    return 0;
}