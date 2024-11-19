#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int y_true[5] = {0, 1, 1, 0, 1};
    float y_hat[5] = {0.1, 0.9, 0.8, 0.3, 0.7};

    float n = sizeof(y_hat) / sizeof(y_hat[0]);
    float summation = 0;
    for (int i = 0; i < n; i++)
    {
        summation += ((y_true[i] * log(y_hat[i])) + ((1 - y_true[i]) * log(1 - y_hat[i])));
    }

    n = -(1 / n);
    cout << static_cast<float>(n) * summation << endl;
    return 0;
}