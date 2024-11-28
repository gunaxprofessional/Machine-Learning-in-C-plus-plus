#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> getUniqueNumbersOrdered(const int arr[], int size)
{
    unordered_set<int> uniqueSet;
    vector<int> uniqueNumbers;

    for (int i = 0; i < size; ++i)
    {
        if (uniqueSet.insert(arr[i]).second)
        {
            uniqueNumbers.push_back(arr[i]);
        }
    }

    return uniqueNumbers;
}

int main()
{
    int y_true[10] = {1, 0, 1, 2, 0, 1, 0, 0, 1, 2};
    int y_pred[10] = {0, 0, 0, 2, 0, 1, 0, 1, 2, 2};

    int size = sizeof(y_true) / sizeof(y_true[0]);

    vector<int> uniqueNumbers = getUniqueNumbersOrdered(y_true, size);

    double precision = 0;

    double *TP = (double *)calloc(uniqueNumbers.size(), sizeof(double));
    double *TN = (double *)calloc(uniqueNumbers.size(), sizeof(double));
    double *FP = (double *)calloc(uniqueNumbers.size(), sizeof(double));
    double *FN = (double *)calloc(uniqueNumbers.size(), sizeof(double));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < uniqueNumbers.size(); j++)
        {
            if (y_true[i] == j)
            {
                if (y_pred[i] == j)
                {
                    TP[j] += 1;
                }
                else
                    FN[j] += 1;
            }
            else
            {
                if (y_pred[i] == j)
                {
                    FP[j] += 1;
                }
                else
                    TN[j] += 1;
            }
        }
    }

    double mcc = 0;
    double tp = 0, tn = 0, fp = 0, fn = 0;

    for (int i = 0; i < uniqueNumbers.size(); i++)
    {
        tp += TP[i];
        tn += TN[i];
        fp += FP[i];
        fn += FN[i];
    }

    mcc = ((tp * tn) - (fp * fn)) / sqrt((tp + fp) * (tp + fn) * (tn + fp) * (tn + fn));

    cout << setprecision(10) << mcc << endl;

    return 0;
}
