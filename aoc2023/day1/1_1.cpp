#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    ifstream inputFile("input_1_test.txt");
    regex numberRegex("(\\d)");
    smatch digitMatch;
    int sum = 0;
    if (inputFile.is_open())
    {
        while ( getline (inputFile,line) )
        {
            string number = "";
            while (regex_search(line, digitMatch, numberRegex))
            {
                number += digitMatch[0];
                line = digitMatch.suffix().str();
            }
            string twoDigitNumber = "";
            twoDigitNumber += number[0];
            twoDigitNumber += number[number.size()-1];
            sum += stoi(twoDigitNumber);
        }
        inputFile.close();
    }
    cout << sum << endl;
    return 0;
}