#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void printArray(double array[], int n)
{
    for (int i = 0; i < n; i++){
        cout << *(array + i) << " ";
    }
    cout << endl;
}

int main(){
    const int max_array_elements = 10000;
    int n; 
    cout << "Enter amount elements of array < " << max_array_elements << ": ";
    cin >> n;

    if(n < 1 || n > max_array_elements){
        cout << "Invalid input";
        return 1;
    }

    double* arr = new double[n];

    cout << "Enter 0 if you want to fill the array with random numbers or 1 if from console: ";
    bool variant_of_input;
    cin >> variant_of_input;

    double element;

    srand(static_cast<unsigned int>(time(0)));

    if(variant_of_input == 0){
        int firstn, secondn;
        cout << "Enter range of random elements(Example: 4 9): ";
        cin >> firstn >> secondn;

        int size_range = secondn - firstn + 1;

        for(int i = 0; i < n; i++){
            int rn = rand();
            *(arr+i) = (rand()%size_range + firstn) + rn/pow(10, ceil(log10(rn)));
            if(*(arr+i) > secondn)
                *(arr+i) -= 1;
            else if(*(arr+i) < firstn)
                *(arr+i) += 1;
        }
    }
    else{
        for(int i = 0; i < n; i++){
            cin >> element;
            *(arr+i) = element;
        }
    }

    double P;
    cout << "Enter P: "; cin >> P;

    printArray(arr, n);

    int index_last_negative;
    int num_counter = 0, negatve_counter = 0;
    for(int i = 0; i < n; i++){
        if(*(arr+i) < P)
            num_counter++;
        if(*(arr+i) < 0){
            negatve_counter++;
            index_last_negative = i;
        }
    }

    cout << "Amount numbers < P: " << num_counter << endl;

    int summ = 0; 

    if(negatve_counter == 0)
        cout << "Zero numbers < 0";
    else{
        
        for(int i = index_last_negative+1; i < n; i++ ){
            summ += (int)*(arr+i);
        }
    }
    cout << "Sum of integer part of elements after last negative: " << summ << endl;

    int strt = 0;

    for(int i = 0; i < n; i++){
        if(*(arr+i) < P){
            double swapp = *(arr+strt);
            *(arr+strt) = *(arr+i); 
            *(arr+i) = swapp;
            strt++; 
        }
    }

    printArray(arr, n);

    delete[]arr;
}