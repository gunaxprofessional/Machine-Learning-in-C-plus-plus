#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>

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

    double f1_score = 0, precision = 0, recall = 0;

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

    for (int i = 0; i < uniqueNumbers.size(); i++)
    {
        recall = (TP[i] / (TP[i] + FN[i]));
        precision = (TP[i] / (TP[i] + FP[i]));
        f1_score += (2 * ((precision * recall) / (precision + recall)));
    }

    cout << setprecision(10) << f1_score / uniqueNumbers.size() << endl;

    return 0;
}