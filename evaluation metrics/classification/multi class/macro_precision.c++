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

    float precision = 0;

    float *TP = (float *)calloc(uniqueNumbers.size(), sizeof(float));
    float *TN = (float *)calloc(uniqueNumbers.size(), sizeof(float));
    float *FP = (float *)calloc(uniqueNumbers.size(), sizeof(float));
    float *FN = (float *)calloc(uniqueNumbers.size(), sizeof(float));

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
        precision += (TP[i] / (TP[i] + FP[i]));
    }

    cout << setprecision(5) << precision / uniqueNumbers.size() << endl;

    return 0;
}