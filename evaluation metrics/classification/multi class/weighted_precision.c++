#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

using namespace std;

// Function to extract unique numbers from an array in the order they appear
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
    int y_true[10] = {1, 0, 1, 2, 0, 1, 0, 0, 1, 2}; // Ground truth
    int y_pred[10] = {0, 0, 0, 2, 0, 1, 0, 1, 2, 2}; // Predictions

    int size = sizeof(y_true) / sizeof(y_true[0]);

    // Get unique class labels
    vector<int> uniqueNumbers = getUniqueNumbersOrdered(y_true, size);

    // Initialize TP, FP, FN, TN for each class
    int num_classes = uniqueNumbers.size();
    vector<float> TP(num_classes, 0), TN(num_classes, 0), FP(num_classes, 0), FN(num_classes, 0);

    // Calculate confusion matrix values for each class
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < num_classes; j++)
        {
            if (y_true[i] == uniqueNumbers[j])
            { // Actual belongs to class `j`
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
            { // Actual does not belong to class `j`
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

    // Calculate weighted precision
    float precision = 0;
    unordered_map<int, int> class_counts;

    for (int i = 0; i < size; i++)
        class_counts[y_true[i]]++;

    for (int i = 0; i < num_classes; i++)
        if (TP[i] + FP[i] > 0)
            precision += (TP[i] / (TP[i] + FP[i])) * class_counts[uniqueNumbers[i]];

    // Normalize precision by the total number of samples
    precision /= size;

    cout << "Weighted Precision: " << setprecision(10) << precision << endl;

    return 0;
}
