#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // exercise 1
    vector<string> fruits {
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };

    string searchWord = "berry";
    auto it = find_if(fruits.begin(), fruits.end(), [searchWord](const string& fruit) {
        return fruit.find(searchWord) != string::npos;
    });

    if ( it != fruits.end() ) {
        cout << "There is a fruit what contains '" << searchWord << "'.\n";
    } else {
        cout << "There is no fruit what contains '" << searchWord << "'.\n";
    }

    cout << endl;
    // exercise 2
    vector<int> numbers { 1, 2, 4, 5, 7, 8 };
    vector<int> evenNumbers { 2, 4, 66, 88, 54, 98, 100 };

    bool notAllAreEven = all_of(numbers.begin(), numbers.end(), [](int num) {
       return num % 2 == 0;
    });

    if ( notAllAreEven ){
        cout << "Every number is even." << endl;
    } else {
        cout << "NOT every number is even." << endl;
    }

    bool allAreEven = all_of(evenNumbers.begin(), evenNumbers.end(), [](int num) {
        return num % 2 == 0;
    });

    if ( allAreEven ){
        cout << "Every number is even." << endl;
    } else {
        cout << "NOT every number is even." << endl;
    }

    cout << endl;
    // exercise 3
    cout << "Numbers: " << endl;
    for( int current : numbers ){
        cout << current << " ";
    }
    cout << endl;

    for_each( numbers.begin(), numbers.end(), [](int &num){
       num *= 2;
    });

    cout << "Doubled numbers: " << endl;
    for( int current : numbers ){
        cout << current << " ";
    }
    cout << endl;

    cout << endl;
    // exercise 4
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    int fiveLetterMonthCount = count_if(months.begin(), months.end(), [](const string& month) {
        return month.size() == 5;
    });

    cout << "The number of 5 letter months: " << fiveLetterMonthCount << endl;

    cout << endl;
    // exercise 5
    vector<double> realNumbers1{3.14, 2.71, 1.618, 0.577, 2.718};

    sort(realNumbers1.begin(), realNumbers1.end(), [](double a, double b) {
        return a > b;
    });

    cout << "Sorted array: ( With lambda )";
    for (const auto& num : realNumbers1) {
        cout << num << " ";
    }
    cout << endl;

    sort(realNumbers1.begin(), realNumbers1.end(), greater<>());

    cout << "Sorted array: ( greater<> functor ): ";
    for (const auto& num : realNumbers1) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
    // exercise 6
    vector<pair<string, int>> temperatureData{
            {"January", 0},
            {"February", 2},
            {"March", 8},
            {"April", 15},
            {"May", 20},
            {"June", 25},
            {"July", 28},
            {"August", 27},
            {"September", 22},
            {"October", 16},
            {"November", 9},
            {"December", 3}
    };

    sort(temperatureData.begin(), temperatureData.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    cout << "Sorted array by their average temperature: " << endl;
    for (const auto& data : temperatureData) {
        cout << data.first << ": " << data.second << "C\n";
    }

    cout << endl;
    // exercise 7
    vector<double> realNumbers2{-3.14, 2.71, -1.618, 0.577, -2.718, 1.414};

    sort( realNumbers2.begin(), realNumbers2.end(), [](double a, double b){
       return abs(a) < abs(b);
    });

    cout << "Sorted array by their absolute value: " << endl;
    for( const auto &num : realNumbers2 ){
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
    // exercise 8
    transform ( months.begin(), months.end(), months.begin(), [](string &month){
        transform ( month.begin(), month.end(), month.begin(), ::tolower);
        return month;
    });

    cout << "Months with lowercase: ";
    for (const auto& month : months) {
        cout << month << " ";
    }
    cout << endl;

    cout << endl;
    // exercise 9
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    srand(time(0 ));
    random_shuffle(alphabet.begin(), alphabet.end());

    sort(months.begin(), months.end(), [](const string& a, const string& b) {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    });

    cout << "Sorted months by strange abc: " << endl;
    for (const auto& month : months) {
        cout << month << " ";
    }
    cout << endl;



    return 0;
}
