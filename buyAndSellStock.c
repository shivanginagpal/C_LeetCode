//121. Best Time to Buy and Sell Stock

#include <limits.h>
#include <stdio.h>
int maxProfit(int *prices, int size)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else if (maxProfit < (prices[i] - minPrice))
        {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}
int main()
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(int);
    printf("Max Profit you can make is %d\n", maxProfit(prices, pricesSize));
    return 0;
}