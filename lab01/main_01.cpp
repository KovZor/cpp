#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

int countBits(int number);
bool setBit(int number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);


int main() {
    /*
    //EXERCISE 1

    int number;

    cout << "Enter a number: " << endl;
    cin >> number;

    if (number < 0) {
        cout << "The given number is not a whole positive number." << endl;
    } else {
        int result = countBits(number);
        cout << "The one bits: " << result << endl;
    }
    */
    //EXERCISE 2
    /*
    int number, order;

    cout << "Enter a number: " << endl;
    cin >> number;
    cout << "Enter the order: " << endl;
    cin >> order;

    bool state = setBit(number, order);

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if( setBit(n, i) ){
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }
    */
    //EXERCISE 3
    /*
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    double *array = new double[n];

    for(int i = 0; i < n;i++){
        cout << "Enter a number: " << endl;
        cin >> array[i];
    }

    cout << "\nThe array is: \n";
    for(int i = 0; i < n;i++){
        cout << array[i] << " ";
    }

    double avg = mean(array, n);
    cout << "The average of the array is: " << avg << endl;
    */
    //EXERCISE  4
    /*
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    double *array = new double[n];

    for(int i = 0; i < n;i++){
        cout << "Enter a number: " << endl;
        cin >> array[i];
    }
    cout << "\nThe array is: \n";
    for(int i = 0; i < n;i++){
        cout << array[i] << " ";
    }

    double result = stddev(array, n);

    if (!std::isnan(result)) {
        cout << "The Deviation: " << result << endl;
    } else {
        cout << "The array is empty, no deviation" << endl;
    }
    */
    //EXERCISE 5
    /*
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    double *array = new double[n];

    for(int i = 0; i < n;i++){
        cout << "Enter a number: " << endl;
        cin >> array[i];
    }
    cout << "\nThe array is: \n";
    for(int i = 0; i < n;i++){
        cout << array[i] << " ";
    }
    cout << "\n";

    pair<double, double> result = max2(array, n);

if( !isnan(result.first) && !isnan(result.second) ){
        cout << "The two highest item: " << result.first << " and " << result.second << endl;
    } else {
        cout << "There is an empty array or only one item." << endl;
    }
    */
    //NEXT ECERCISES
    //EXERCISE 1


    return 0;
}

int countBits(int number){
    int count = 0;
    while (number > 0) {
        count += (number & 1);
        number >>= 1;
    }
    return count;
}

bool setBit(int *number, int order){
    if (order < 0 || order > 31) {
        return false; // wrong order
    }

    int mask = 1 << order;
    *number |= mask; // set bit to 1

    return true;
}

double mean(double array[], int numElements){
    if( numElements == 0 ){
        return NAN;
    }

    double sum = 0;
    for(int i = 0;i < numElements;i++){
        sum += array[i];
    }

    double avg = sum / numElements;
    return avg;
}

double stddev(double array[], int numElements){
    if( numElements == 0 ){
        return NAN;
    }

    double avg = mean(array, numElements);
    cout << "The average of the array is: " << avg << endl;

    //calculating the deviation
    double variance = 0.0;
    for (int i = 0; i < numElements; i++) {
        variance += pow(array[i] - avg, 2);
    }
    double stdDev = sqrt(variance / numElements);

    return stdDev;
}

pair<double, double> max2(double array[], int numElements){
    pair<double, double> result = {NAN, NAN};

    if( numElements == 0 ){
        return result;
    }

    if( numElements == 1 ){
        result.first = array[0];
        result.second = array[0];
        return result;
    }

    double max1 = array[0];
    double max2 = array[1];

    if( max2 > max1 ){
        swap(max1, max2);
    }

    for (int i = 2; i < numElements; i++) {
        if (array[i] > max1) {
            max2 = max1;
            max1 = array[i];
        } else if (array[i] > max2) {
            max2 = array[i];
        }
    }

    result.first = max1;
    result.second = max2;

    return result;
}