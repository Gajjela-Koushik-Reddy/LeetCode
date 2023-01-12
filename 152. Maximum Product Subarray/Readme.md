# 152. Maximum Product Subarray

## Code
````
int maxProduct(vector<int>& nums) {

    int maxProduct = 1;
    int minProduct = 1;
    int ret = nums[0];
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        maxProduct = max(max(maxProduct * nums[i], minProduct * nums[i]), nums[i]);
        minProduct = min(min(maxProduct * nums[i], minProduct * nums[i]), nums[i]);
        ret = max(ret, maxProduct);
    }

    return ret;
}
````
