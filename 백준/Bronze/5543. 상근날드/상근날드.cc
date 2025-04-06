#include <iostream>
// #include <queue>
using namespace std;

/* struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
}; */

int main()
{
    int input_price;
    int min_val1 = 21e8;
    // priority_queue<int, vector<int>, compare> burgers;
    // priority_queue<int, vector<int>, compare> drinks;
    for (int i = 0; i < 3; i++)
    {
        cin >> input_price;
        // burgers.push(input_price);
        min_val1 = min_val1 < input_price ? min_val1 : input_price;
    }
    int min_val2 = 21e8;
    for (int i = 0; i < 2; i++)
    {
        cin >> input_price;
        min_val2 = min_val2 < input_price ? min_val2 : input_price;
    }
    
    int ans = min_val1 + min_val2 - 50;
    cout << ans << '\n';
    return 0;
}