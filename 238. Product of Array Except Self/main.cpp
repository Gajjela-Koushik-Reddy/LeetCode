#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    vector<int> v = {1,2,3,4};
    vector<int>out = productExceptSelf(v);

    for(auto x: out)
        cout << x << " " << endl;
    
    return 0;
}