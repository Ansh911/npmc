#include <iostream>
using namespace std;
int main()
{
    int data_A, data_B, size, sum;
    cout << "Enter the data bit of stations A and B: ";
    cin >> data_A >> data_B;
    data_A = data_A == 1 ? 1 : -1;
    data_B = data_B == 1 ? 1 : -1;
    cout << "Enter the size of chip code: ";
    cin >> size;
    int chip_A[size], chip_B[size], encoded_A[size], encoded_B[size], c[size],
        decoded_A[size], decoded_B[size];
    cout << "Enter the PN sequence number(chip code) for A:";
    for (int i = 0; i < size; i++)
        cin >> chip_A[i];
    cout << "Enter the PN sequence number(chip code) for B:";
    for (int i = 0; i < size; i++)
        cin >> chip_B[i];
    for (int i = 0; i < size; i++)
    {
        chip_A[i] = chip_A[i] == 1 ? 1 : -1;
        chip_B[i] = chip_B[i] == 1 ? 1 : -1;
    }
    cout << "Encoded data at A: ";
    for (int i = 0; i < size; i++)
    {
        encoded_A[i] = data_A * chip_A[i];
        cout << encoded_A[i] << " ";
    }
    cout << endl;
    cout << "Encoded data at B: ";
    for (int i = 0; i < size; i++)
    {
        encoded_B[i] = data_B * chip_B[i];
        cout << encoded_B[i] << " ";
    }
    cout << endl;
    cout << "C[i]: ";
    for (int i = 0; i < size; i++)
    {
        c[i] = encoded_A[i] + encoded_B[i];
        cout << c[i] << " ";
    }
    cout << endl;
    cout << "Encoded Successfully." << endl
         << endl;
    sum = 0;
    cout << "Decoded data at A: ";
    for (int i = 0; i < size; i++)
    {
        decoded_A[i] = c[i] * chip_A[i];
        cout << decoded_A[i] << " ";
        sum += decoded_A[i];
    }
    cout << endl;
    cout << "Sum= " << sum << endl;
    sum > 0 ? cout << "A= 1 " : cout << "A= 0 ";
    sum = 0;
    cout << endl;
    cout << "Decoded data at B: ";
    for (int i = 0; i < size; i++)
    {
        decoded_B[i] = c[i] * chip_B[i];
        cout << decoded_B[i] << " ";
        sum += decoded_B[i];
    }
    cout << endl;
    cout << "Sum= " << sum << endl;
    sum > 0 ? cout << "B= 1" : cout << "B= 0";
    cout << endl;
    return 0;
}
