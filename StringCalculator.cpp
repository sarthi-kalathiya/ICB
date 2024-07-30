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

        vector<string> delimiters = {",", "\n"};
        string modifiedNumbers = numbers;

        // Check for custom delimiter
        if (numbers.rfind("//", 0) == 0)
        {
            size_t delimiterEnd = numbers.find("\n");
            if (delimiterEnd != string::npos)
            {
                string delimiterSection = numbers.substr(2, delimiterEnd - 2);
                modifiedNumbers = numbers.substr(delimiterEnd + 1);
                if (delimiterSection[0] == '[')
                {
                    regex delimiterRegex(R"(\[(.*?)\])");
                    sregex_iterator iter(delimiterSection.begin(), delimiterSection.end(), delimiterRegex);
                    sregex_iterator end;
                    while (iter != end)
                    {
                        delimiters.push_back(iter->str(1));
                        ++iter;
                    }
                }
                else
                {
                    delimiters.push_back(delimiterSection);
                }
            }
        }

        string regexPattern = "[";
        for (const auto &delim : delimiters)
        {
            for (char c : delim)
            {
                regexPattern += '\\';
                regexPattern += c;
            }
        }
        regexPattern += "]+";

        regex regexSplit(regexPattern);
        sregex_token_iterator it(modifiedNumbers.begin(), modifiedNumbers.end(), regexSplit, -1);
        sregex_token_iterator end;

        int sum = 0;
        vector<int> negatives;
        for (; it != end; ++it)
        {
            if (!it->str().empty())
            {
                int number = stoi(it->str());
                if (number < 0)
                {
                    negatives.push_back(number);
                }
                else
                {
                    sum += number;
                }
            }
        }

        if (!negatives.empty())
        {
            string errorMsg = "negative numbers not allowed: ";
            for (size_t i = 0; i < negatives.size(); ++i)
            {
                errorMsg += to_string(negatives[i]);
                if (i < negatives.size() - 1)
                {
                    errorMsg += ",";
                }
            }
            throw runtime_error(errorMsg);
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

    string input9 = "//;\n1;-2;3";
    try
    {
        cout << "Input: \"" << input9 << "\", Output: " << calculator.add(input9) << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    string input10 = "1,-2,-3,4";
    try
    {
        cout << "Input: \"" << input10 << "\", Output: " << calculator.add(input10) << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
