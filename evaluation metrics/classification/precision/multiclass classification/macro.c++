#include <iostream>
#include <iomanip>

int main()
{
    int y_true[6] = {0, 1, 2, 0, 1, 2};
    int y_pred[6] = {0, 2, 1, 0, 0, 1};
    int total_sample = sizeof(y_pred) / sizeof(y_pred[0]);
    int total_matches = 0;

    for (int i = 0; i < total_sample; i++)
    {
        if (y_true[i] == 0 && y_true[i] == y_pred[i])
        {
            total_matches += 1;
        }
    }

    std::cout << std::fixed << std::setprecision(4)
              << static_cast<float>(total_matches) / total_sample << std::endl;

    return 0;
}