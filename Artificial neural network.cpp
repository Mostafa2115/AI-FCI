#include <iostream>
#include <vector>
using namespace std;
int main ()
{
  int n;
    cin >> n;
    vector<double> inputs(n);
    vector<double> weights(n);
    for (int i = 0; i < n; ++i)
        cin >> inputs[i];
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    double bias, bias_weight, net_input = 0;
    cin >> bias >> bias_weight;
    for (size_t i = 0; i < inputs.size(); ++i)
        net_input += inputs[i] * weights[i];
    net_input += bias * bias_weight;
    cout << "Net input to the output = " << net_input << endl;

return 0;
}
