#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    ifstream inputFile("1_2_test.txt");
    regex numberRegex("\\d|one|two|three|four|five|six|seven|eight|nine");
    smatch digitMatch;

    regex oneRegex("one");
    regex twoRegex("two");
    regex threeRegex("three");
    regex fourRegex("four");
    regex fiveRegex("five");
    regex sixRegex("six");
    regex sevenRegex("seven");
    regex eightRegex("eight");
    regex nineRegex("nine");
    int sum = 0;
    if (inputFile.is_open())
    {
        while ( getline (inputFile,line) )
        {
            string number = "";
            while (regex_search(line, digitMatch, numberRegex))
            {
                string matched = digitMatch[0];
                matched = regex_replace(matched, oneRegex, "1");
                matched = regex_replace(matched, twoRegex, "2");
                matched = regex_replace(matched, threeRegex, "3");
                matched = regex_replace(matched, fourRegex, "4");
                matched = regex_replace(matched, fiveRegex, "5");
                matched = regex_replace(matched, sixRegex, "6");
                matched = regex_replace(matched, sevenRegex, "7");
                matched = regex_replace(matched, eightRegex, "8");
                matched = regex_replace(matched, nineRegex, "9");
                number += matched;
                line = line.substr(digitMatch.position()+1,10000);//digitMatch.suffix().str();
            }
            // cout << number << endl;
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