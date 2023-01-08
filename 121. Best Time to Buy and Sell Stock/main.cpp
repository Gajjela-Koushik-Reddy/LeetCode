#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int L = 0;
    int R = 1;
    int index = 0;
    int maxProfit = 0;
    int length = prices.size();
    while(index < length && R < length) {
        if((prices[R] - prices[L]) < 0){
            L = R;
            R++;
        }
        else {
            if(maxProfit < (prices[R] - prices[L]))
                maxProfit = prices[R] - prices[L];
            R++;
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {2, 1, 2, 1, 0, 1, 2};

    cout << maxProfit(prices) << endl;
    return 0;
}