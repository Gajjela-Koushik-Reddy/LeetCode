#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int L = 0;
    int R = nums.size() - 1;

    while (L < R)
    {
        int mid = (L + R) / 2;
        if (nums[mid] > nums[R])
            L = mid + 1;
        else
            R = mid;
    }
    return nums[L];
}

int main()
{
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    std::cout << findMin(v) << std::endl;

    return 0;
}