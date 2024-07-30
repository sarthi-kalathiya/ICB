#include <iostream>
#include <sstream>
#include <string>


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

        stringstream ss(numbers);
        string item;
        int sum = 0;

        while (getline(ss, item, ','))
        {
            sum += stoi(item);
        }

        return sum;
    }
};

int main()
{
    StringCalculator calculator;
    return 0;
}
