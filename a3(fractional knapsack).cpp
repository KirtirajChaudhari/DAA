//-------------------------------------------------------------
//Fractional KnapSack Problem
//-------------------------------------------------------------

#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    float wt, val, ratio;
};

int main() {
    int n; float W;
    cout << "Enter number of items: ";
    cin >> n;

    Item a[n];
    cout << "Enter weight and value:\n";
    for(int i = 0; i < n; i++){
        cin >> a[i].wt >> a[i].val;
        a[i].ratio = a[i].val / a[i].wt;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    sort(a, a+n, [](Item x, Item y){ return x.ratio > y.ratio; }); // sort by value/weight

    float profit = 0;
    for(int i = 0; i < n; i++){
        if(W == 0) break;
        if(a[i].wt <= W){
            W -= a[i].wt;
            profit += a[i].val;
        } else {
            profit += a[i].ratio * W; // take fractional part
            W = 0;
        }
    }

    cout << "\nMaximum Profit: " << profit;
    return 0;
}
