#include <iostream>
#include <vector>
using namespace std;
struct layer
{
    double input, weight;
}
int main ()
{
  int n;
    cout << "Enter the number of layers: ";
    cin >> n;
    vector<layer> layers(n);
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter net input and weight for layer " << i + 1 << ": ";
        cin >> layers[i].input >> layers[i].weight;
    }
    double bias, bias_weight, net_input = 0;
    cout << "Enter the bias: ";
    cin >> bias;
    cout << "Enter the weight of bias: ";
    cin >> bias_weight;
    for (size_t i = 0; i < n; ++i)
        net_input += layers[i].input * layers[i].weight;
    net_input += bias * bias_weight;
    cout << "Net input to the output = " << net_input << endl;
    int ActivationFun;
    cout << "Choose the activation function:\n";
    cout << "1-Identity Function\n";
    cout << "2-Binary Step Function\n";
    cout << "3-Bipolar Step Function\n";
    cout << "4-Binary Sigmoid Function\n";
    cout << "5-Bipolar Sigmoid Function\n";
    cout << "6-Ramp Function\n";
    cin >> ActivationFun;
    switch (ActivationFun)
    {
    case 1:
    {
        cout << net_input << "\n\n";
        break;
    }

    case 2:
    {
        if (net_input >= 0)
            cout << 1.0 << "\n\n";
        else
            cout << 0.0 << "\n\n";
        break;
    }

    case 3:
    {
        if (net_input >= 0)
            cout << 1.0 << "\n\n";
        else
            cout << -1.0 << "\n\n";
        break;
    }
    case 4:
    {
        cout << 1.0 / (1.0 + exp(-net_input)) << "\n\n";
        break;
    }
    case 5:
    {
        cout << (2.0 / (1.0 + exp(-net_input))) - 1.0 << "\n\n";
        break;
    }
    case 6:
    {
        if (net_input < 0)
            cout << 0 << "\n\n";
        if (net_input > 1)
            cout << 1 << "\n\n";
        cout << net_input << "\n\n";
        break;
    }
    default:
    {
        cout << "Invalid choice!\n\n";
        break;
    }
    }
return 0;
}
