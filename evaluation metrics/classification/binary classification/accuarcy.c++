#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int y_true[10] = {1, 0, 0, 0, 0, 1, 1, 0, 0};
    int y_pred[10] = {0, 1, 1, 0, 0, 0, 1, 0, 0};
    int total_sample = sizeof(y_pred) / sizeof(y_pred[0]);
    int total_matches = 0;

    for (int i = 0; i < total_sample; i++)
    {
        if (y_true[i] == y_pred[i])
        {
            total_matches += 1;
        }
    }

    cout << "Total Samples: " << total_sample << "\n"
         << "Total Matches: " << total_matches << endl;

    cout << "Accuarcy: " << fixed << setprecision(4)
         << static_cast<float>(total_matches) / total_sample << endl;

    return 0;
}
