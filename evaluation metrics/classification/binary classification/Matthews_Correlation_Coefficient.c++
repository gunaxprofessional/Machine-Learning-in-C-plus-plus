#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    int y_true[10] = {1, 0, 0, 0, 0, 1, 1, 0, 0, 0};
    int y_pred[10] = {0, 1, 1, 0, 0, 0, 1, 0, 0, 0};
    int total_sample = sizeof(y_pred) / sizeof(y_pred[0]);
    int TP = 0, FP = 0, FN = 0, TN = 0;

    for (int i = 0; i < total_sample; i++)
    {
        if (y_true[i] == 1)
        {
            if (y_pred[i] == 1)
                TP++;
            else if (y_pred[i] == 0)
                FN++;
        }
        else
        {
            if (y_pred[i] == 1)
                FP++;
            else if (y_pred[i] == 0)
                TN++;
        }
    }

    cout << "TP: " << TP << ", FP: " << FP << ", FN: " << FN << ", TN: " << TN << endl;

    double mcc = 0;

    mcc = ((TP * TN) - (FP * FN)) / sqrt((TP + FP) * (TP + FN) * (TN + FP) * (TN + FN));

    cout << setprecision(10) << mcc << endl;

    return 0;
}
