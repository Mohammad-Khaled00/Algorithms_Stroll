#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) 
{
    int refils = 0;
    while (true)
    {
        int x = 0;

        if (tank >= dist)
            break;

        for (int stop : stops) {
            if (stop <= tank && stop > x)
                x = stop;
        }

        if (x > 0)
        {
            refils += 1;
            dist -= x;
            for (int& stop : stops) {
                stop -= x;
            }
        }
        else
        {
            refils = -1;
            break;
        }
    }
    return refils;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
