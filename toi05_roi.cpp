#include <bits/stdc++.h>
using namespace std;

int main()
{
    double c;
    scanf(" %lf",&c);
    tuple<double, double, double> ans = {0, 0, 1e9};
    for(double BookProduced = 1000 ; BookProduced <= 15000 ; BookProduced += 500)
    {
        double FundEach = 102 - BookProduced/500;
        double TotalFund = c + BookProduced * FundEach;
        for(double SoldPrice = 74 ; SoldPrice <= 144 ; SoldPrice += 1)
        {
            double SoldBook = ((100 - (0.8569 * exp(0.09*(SoldPrice-100)))) * BookProduced) / 100;
            double Income = SoldPrice * SoldBook;
            if(Income - TotalFund > 0 && get<2>(ans) > Income - TotalFund) ans = {BookProduced, SoldPrice, Income - TotalFund};
        }
    }
    printf("%.0lf\n%.0lf\n%.2lf\n",get<0>(ans),get<1>(ans),get<2>(ans));
    return 0;
}
