# 121. Best Time to Buy and Sell Stock

You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>ith</code> day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return <code>0</code>.

## Solution

<code>prices = [7,1,5,3,6,4]</code>
We can use two pointer method, where the left pointer <code>L</code> will be pointing at <code>index: 0</code> and the right pointer <code>R</code> will be pointing at <code>index: 1</code>

The idea here is to buy the dip and sell when the stock reaches it's maximum. 
If <code>prices[R] - prices[L] < 0</code> which is negative then we move the left pointer to the right pointer position i.e., <code>L = R</code> and increment the rigth pointer <code>R++</code>

Else we calculate the profit by <code>prices[R] - prices[L]</code> and increment the right pointer <code>R</code> and continue calculating the maximum profit until we reach the end of the array i.e., <code>index < lengthOfTheArray && R < lengthOFTheArray</code>
