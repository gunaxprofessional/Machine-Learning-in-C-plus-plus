#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
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

    int num_classes = uniqueNumbers.size();
    vector<float> TP(num_classes, 0), TN(num_classes, 0), FP(num_classes, 0), FN(num_classes, 0);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < num_classes; j++)
        {
            if (y_true[i] == uniqueNumbers[j])
            {
                if (y_pred[i] == uniqueNumbers[j])
                {
                    TP[j]++;
                }
                else
                {
                    FN[j]++;
                }
            }
            else
            {
                if (y_pred[i] == uniqueNumbers[j])
                {
                    FP[j]++;
                }
                else
                {
                    TN[j]++;
                }
            }
        }
    }

    float recall = 0;
    unordered_map<int, int> class_counts;

    for (int i = 0; i < size; i++)
        class_counts[y_true[i]]++;

    for (int i = 0; i < num_classes; i++)
        if (TP[i] + FP[i] > 0)
            recall += (TP[i] / (TP[i] + FN[i])) * class_counts[uniqueNumbers[i]];

    recall /= size;

    cout << "Weighted Recall: " << setprecision(10) << recall << endl;

    return 0;
}
