#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    // int index = -1;
    int L = 0;
    int R = nums.size() - 1;

    while (L < R)
    {
        int mid = (L + R) / 2;
        if (nums[mid] < nums[R])
            R = mid;
        else
            L = mid + 1;
    }

    std::cout << L << std::endl;

    R = nums.size() - 1;

    std::cout << R << std::endl;

    while (L <= R)
    {

        std::cout << nums[L] << " " << nums[R] << std::endl;
        int mid = (L + R) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            R = mid - 1;
        else if (nums[mid] < target)
            L = mid + 1;
    }

    return -1;
}

int main()
{
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    std::cout << search(v, 0) << std::endl;

    return 0;
}