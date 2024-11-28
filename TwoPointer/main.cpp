#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
using std::vector;
using std::set;
using std::stack;
using std::string;

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
/*
    Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

    Example 1:

    Input: [-1, 0, 2, 3], target=3 
    Output: 2
    Explanation: There are two triplets with distance '1' from the target: [-1, 0, 3] & [-1, 2, 3]. Between these two triplets, the correct answer will be [-1, 0, 3] as it has a sum '2' which is less than the sum of the other triplet which is '4'. This is because of the following requirement: 'If there are more than one such triplet, return the sum of the triplet with the smallest sum.'
    Example 2:

    Input: [-3, -1, 1, 2], target=1
    Output: 0
    Explanation: The triplet [-3, 1, 2] has the closest sum to the target.
    Example 3:

    Input: [1, 0, 1, 1], target=100
    Output: 3
    Explanation: The triplet [1, 1, 1] has the closest sum to the target.
    Example 4:

    Input: [0, 0, 1, 1, 2, 6], target=5
    Output: 4
    Explanation: There are two triplets with distance '1' from target: [1, 1, 2] & [0, 0, 6]. Between these two triplets, the correct answer will be [1, 1, 2] as it has a sum '4' which is less than the sum of the other triplet which is '6'. This is because of the following requirement: 'If there are more than one such triplet, return the sum of the triplet with the smallest sum.'
    Constraints:

    3 <= arr.length <= 500
    -1000 <= arr[i] <= 1000
    -104 <= target <= 104
*/
int TripletsWithSmallerSum(vector<int> & nums,int target)
{
    std::sort(nums.begin(),nums.end());
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        int j=i+1;
        int k = nums.size()-1;

        while(j<k)
        {
            if(nums[j]+nums[k]<target-nums[i])
            {
                count+=k-j;
                j++;
            }else
            {
                k--;
            }
        }
    }
    return count;

}
/*
    Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.

    The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.

    Example 1:

    Input: [1, 0, 2, 1, 0]
    Output: [0 0 1 1 2]
    Example 2:

    Input: [2, 2, 0, 1, 2, 0]
    Output: [0 0 1 2 2 2 ]
    Constraints:

    n == arr.length
    1 <= n <= 300
    arr[i] is either 0, 1, or 2.
*/
void Swap(int * a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}
vector<int> DutchProblem(vector<int> &nums)
{
    int left=0;
    int right = nums.size()-1;
    int i=0;
    while(i<=right)
    {
        if(nums[i]==0)
        {
            int temp = nums[i];
            nums[i]=nums[left];
            nums[left]=temp;
            i++;
            left++;
        }
        else if(nums[i]==1)
        {
            i++;
        }else
        {
            int temp = nums[i];
            nums[i]=nums[right];
            nums[right]=temp;
            right--;
        }
    }
    return nums;
}

/*
    Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.

    Example 1:

    Input: str1="xy#z", str2="xzz#"
    Output: true
    Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
    Example 2:

    Input: str1="xy#z", str2="xyz#"
    Output: false
    Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
    Example 3:

    Input: str1="xp#", str2="xyz##"
    Output: true
    Explanation: After applying backspaces the strings become "x" and "x" respectively.
    In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.
    Example 4:

    Input: str1="xywrrmp", str2="xywrrmu#p"
    Output: true
    Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.
    Constraints:

    1 <= str1.length, str2.length <= 200
    str1 and str2 only contain lowercase letters and '#' characters.
*/
static bool compare(const string &str1, const string &str2) {
    // TODO: Write your code here
    stack<char> s1;
    stack<char> s2;


    for(auto x:str1)
    {
        if(x!='#')
        {
            s1.push(x);
        }else if(x=='#')
        {
            s1.pop();
        }
        
    }

    for(auto x:str2)
    {
        if(x!='#')
        {
            s2.push(x);
        }else if(x=='#')
        {
            s2.pop();
        }
    }

    return s1==s2;
  }

int main()
{
    string s1 = "xy#z";
    string s2 = "xzzx#";

    bool test = compare(s1,s2);

    std::cout<<test<<std::endl;
    

    
    return 0;
}