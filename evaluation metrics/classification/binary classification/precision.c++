#include <iostream>
#include <iomanip>

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

    std::cout << "TP: " << TP << ", FP: " << FP << ", FN: " << FN << ", TN: " << TN << std::endl;

    if (TN + FP > 0)
    {
        std::cout << "precision: " << std::fixed << std::setprecision(4)
                  << static_cast<float>(TP) / (TP + FP) << std::endl;
    }
    else
    {
        std::cout << "precision: Undefined (TN + FP = 0)" << std::endl;
    }

    return 0;
}
