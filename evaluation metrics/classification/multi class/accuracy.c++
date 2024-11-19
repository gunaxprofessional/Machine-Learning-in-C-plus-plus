#include <iostream>

using namespace std;

int main()
{
    int y_true[10] = {0, 1, 2, 2, 1, 0, 1, 2, 0, 1};
    int y_pred[10] = {0, 1, 2, 0, 1, 0, 2, 2, 0, 1};

    int total_sample = sizeof(y_true) / sizeof(y_true[0]);

    int total_matches = 0;
    for (int i = 0; i < total_sample; i++)
    {
        if (y_true[i] == y_pred[i])
        {
            total_matches += 1;
        }
    }

    cout << "Accuracy: " << static_cast<float>(total_matches) / (total_sample) << endl;
    return 0;
}