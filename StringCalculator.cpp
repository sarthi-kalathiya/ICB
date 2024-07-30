#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
class StringCalculator
{
public:
    int add(const string &numbers)
    {
        if (numbers.empty())
        {
            return 0;
        }

        string modifiedNumbers = numbers;

        // Replace new lines with commas
        replace(modifiedNumbers.begin(), modifiedNumbers.end(), '\n', ',');

        stringstream ss(modifiedNumbers);
        string item;
        int sum = 0;

        while (getline(ss, item, ','))
        {
            if (!item.empty())
            {
                sum += stoi(item);
            }
        }

        return sum;
    }
};

int main()
{
    StringCalculator calculator;

    string input1 = "";
    cout << "Input: \"" << input1 << "\", Output: " << calculator.add(input1) << endl;

    string input2 = "1";
    cout << "Input: \"" << input2 << "\", Output: " << calculator.add(input2) << endl;

    string input3 = "1,5";
    cout << "Input: \"" << input3 << "\", Output: " << calculator.add(input3) << endl;

    string input4 = "1,2,3,4,5";
    cout << "Input: \"" << input4 << "\", Output: " << calculator.add(input4) << endl;

    string input5 = "1\n2,3";
    cout << "Input: \"" << input5 << "\", Output: " << calculator.add(input5) << endl;

    string input6 = "1\n2\n3";
    cout << "Input: \"" << input6 << "\", Output: " << calculator.add(input6) << endl;

    return 0;
}