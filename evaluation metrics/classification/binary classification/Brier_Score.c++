#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double prob[4] = {0.9, 0.3, 0.4, 0.8};
    double y_pred[4] = {1, 0, 0, 1};
    double n = 4, brier = 0;

    for (int i = 0; i < 4; i++)
    {
        brier += ((prob[i] - y_pred[i]) * (prob[i] - y_pred[i]));
    }

    cout << setprecision(10) << brier / n << endl;
    return 0;
}