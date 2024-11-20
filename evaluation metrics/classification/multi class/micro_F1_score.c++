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

    float f1_score = 0, precision = 0, recall = 0;

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

    float numerator = 0, denominator = 0;

    for (int i = 0; i < uniqueNumbers.size(); i++)
    {
        numerator += TP[i];
        denominator += (TP[i] + FN[i]);
    }

    recall = (numerator / denominator);

    numerator = 0, denominator = 0;

    for (int i = 0; i < uniqueNumbers.size(); i++)
    {
        numerator += TP[i];
        denominator += (TP[i] + FP[i]);
    }

    precision = (numerator / denominator);

    f1_score = (2 * ((precision * recall) / (precision + recall)));

    cout << setprecision(5) << f1_score << endl;

    return 0;
}