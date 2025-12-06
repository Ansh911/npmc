#include <iostream>
#include <cmath>
using namespace std;

float best_case(float q, float gama)
{
    return 1.0f / (6.0f * pow(q, -gama));
}
float worst_case(float q, float gama)
{
    return 1.0f / (2.0f * pow(q - 1, -gama) + 2.0f * pow(q, -gama) + 2.0f * pow(q + 1, -gama));
}
int main()
{
    cout << "Name-  M.Tech CSE Roll no. " << endl;
    float gama;
    float q = sqrt(3 * 7);
    cout << "Enter the value of gama: ";
    cin >> gama;
    float res1 = best_case(q, gama);
    float res2 = worst_case(q, gama);
    cout << "Best case result: " << res1
         << " Worst case result: " << res2 << endl;
    return 0;
}
