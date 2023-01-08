# 238. Product of Array Except Self

Given an integer array <code>nums</code>, return an array <code>answer</code> such that <code>answer[i]</code> is equal to the product of all the elements of nums except ```nums[i]```.

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

## Solution

``` data = [1,2,3,4] ``` we need to find the product of the array without including itself and that would be ```output = [24,12,8,6]``` why ```24?``` when we are at ```index 0``` in ```data``` the product at that position is going to be ```2*3*4``` which equals to ```24``` as you can see in the ```output.```

To solve this problem we can find the induvidual product of the array from 

```Left to Right product from i=0 to i = n-1```
```product = 1```
| formula            |   solution    |
|--------------------|---------------|
|data[0] * product | 1 * 1  = 1|
|data[1] * product | 1 * 1  = 1|
|data[2] * product | 2 * 1  = 2|
|data[3] * product | 3 * 2  = 6|

```LtoR = [1,1,2,6]```

```Right to Left product from i=n-1 to i = 0```
```product = 1```
| LtoR[i] * (data[i] * product)  |   solution    |
|--------------------|---------------|
|LtoR[3] * product | 6 * 1  = 6  |
|LtoR[2] * (data[3] * product) | 2 * (4 * 1)  = 8 |
|LtoR[1] * (data[2] * product) | 1 * (3 * 4 * 1)  = 12|
|LtoR[0] * (data[1] * product) | 1 * (2 * 3 * 4 * 1)  = 24|



## C++ Code
````
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ret;
    int lProduct = 1;
    for (auto x : nums)
    {
        ret.push_back(lProduct);
        lProduct = x * lProduct;
    }

    int rProduct = 1;
    for (int i = (nums.size() - 1); i >= 0; i--)
    {
        ret[i] = rProduct * ret[i];
        rProduct = nums[i] * rProduct;
    }

    return ret;
}
````