#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    int n, w;
    cin >> n >> w;
    vector<pair<double, pair<int, int>>> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].second.first >> items[i].second.second;
        items[i].first = (double)items[i].second.first / items[i].second.second;
    }
    sort(items.rbegin(), items.rend());
    double totalValue = 0.0, totalWeight = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (w == 0)
            break;
        if (items[i].second.second <= w)
        {
            totalWeight += items[i].second.second;
            totalValue += items[i].second.first;
            w -= items[i].second.second;
        }
        else
        {
            totalWeight += w;
            totalValue += items[i].first * w;
            break;
        }
    }
    cout << "Maximum value in the knapsack: " << totalValue << endl;
    cout << "Total weight in the knapsack: " << totalWeight << endl;
    cout << "Remaining weight in the knapsack: " << w << endl;
    cout << "Total items taken: " << n - (w / items[0].second.second) << endl;
    cout << "Total items remaining: " << w / items[0].second.second << endl;
    return 0;
}
