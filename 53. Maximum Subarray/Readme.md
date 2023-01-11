# 53. Maximum Subarray
Given an integer array ```nums```, find the ```subarray``` with the largest sum, and return its sum.

## Solution
Maximum sub array is the maximum sum of contiguious elements in a array.
````
nums = [-2,1,-3,4,-1,2,1,-5,4]
output = 6
The maximum subarray [4,-1,2,1] has the largest sum 6.
````
One way to solve this to find the maximum sumarray from the start of the elements in the array.
Now what does that mean 

[-2,1,-3,4,-1,2,1,-5,4]

here let's first take the subarray [-2]
here the maximum sum of subarray is -2 itself i.e, max = -2

now we move a position forward

[-2, 1]
Here the sum of maximum subarray is -2 + 1 = -1
and as -2 is less than -1 now max = -1

now move a position forward 

[-2, 1, -3]
Here the sum of the maximum subarray is -2 + 1 - 3 = -4
if the sum < the element that we have encountered in the array while moving forward then we replace the sum by the element at that position.

here as the sum = -4 and -4 < -3 so we skip the subarray that we have been adding and make sum = array[currentPosition] i.e., -3. Now the sum here is -3 and max previously was -1  and as -3 is not greater that -1 our max variable will not change it's value.

we move a position forward and start sum from the position where the sum went below the value of the current index.
[-3]

and now we continue the above steps


## Code
````
int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    int maxLR = nums[0];

    for (int i = 0; i < n; i++) {
        sum = sum + nums[i];
        if(sum < nums[i])
            sum = nums[i];

        if(maxLR < sum)
            maxLR = sum;
    }

    return maxLR;
}
````