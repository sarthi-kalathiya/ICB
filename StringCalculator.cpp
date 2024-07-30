// developed by sarthi kalathiya
#include <bits/stdc++.h>

using namespace std;
class StringCalculator
{
public:
    int add(const string &numbers)
    {
        // If input is empty, return 0
        if (numbers.empty())
        {
            return 0;
        }

        string delimiter = ",";
        string modifiedNumbers = numbers;

        // Check for custom delimiter
        if (numbers.rfind("//", 0) == 0)
        {
            size_t delimiterEnd = numbers.find("\n");
            if (delimiterEnd != string::npos)
            {
                delimiter = numbers.substr(2, delimiterEnd - 2);
                modifiedNumbers = numbers.substr(delimiterEnd + 1);
            }
        }

        // Replace new lines with delimiter
        replace(modifiedNumbers.begin(), modifiedNumbers.end(), '\n', delimiter[0]);

        string regexStr = delimiter == "," ? "[,\n]" : "[" + delimiter + "\n]";
        regex regexPattern(regexStr);
        sregex_token_iterator it(modifiedNumbers.begin(), modifiedNumbers.end(), regexPattern, -1);
        sregex_token_iterator end;

        int sum = 0;
        for (; it != end; ++it)
        {
            if (!it->str().empty())
            {
                sum += stoi(it->str());
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

    string input7 = "//;\n1;2";
    cout << "Input: \"" << input7 << "\", Output: " << calculator.add(input7) << endl;

    string input8 = "//|\n2|3|8";
    cout << "Input: \"" << input8 << "\", Output: " << calculator.add(input8) << endl;

    return 0;
}
