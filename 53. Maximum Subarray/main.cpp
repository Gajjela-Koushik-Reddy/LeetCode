#include <iostream>
#include <vector>
using namespace std;

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

int main() {

    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int out = maxSubArray(v);

    cout << out << endl;

    return 0;
}