#pragma once

#include <fstream>
#include <cstdlib>

void write_results(pair<int, int> time, const string &file_name, const string &test_name) {
    int array_time = time.first;
    int list_time = time.second;
    ofstream fout(file_name, ios_base::app);
    cout << test_name << endl;
    fout << test_name << endl;
    cout << "Dynamic array: " << array_time << " microseconds" << endl;
    fout << "Dynamic array: " << array_time << " microseconds" << endl;
    cout << "Linked list: " << list_time << " microseconds" << endl;
    fout << "Linked list: " << list_time << " microseconds" << endl;
    if (array_time >= list_time) {
        cout << "Linked list is " << array_time / list_time << " times faster than a dynamic array!" << endl;
        fout << "Linked list is " << array_time / list_time << " times faster than a dynamic array!" << endl;
    }
    if (array_time < list_time) {
        cout << "Dynamic array is " << list_time / array_time << " times faster than a linked list!" << endl;
        fout << "Dynamic array is " << list_time / array_time << " times faster than a linked list!" << endl;
    }
    cout << endl;
    fout << endl;
    fout.close();
}

Polynomial<int> create_polynomial_int() {
    Polynomial<int> polynomial(new ArraySequence<int>());
    int n = -1;
    cout << "Polynomial size: ";
    cin >> n;
    while (n < 0) {
        cout << "Enter a positive integer!" << endl << "size: ";
        cin >> n;
    }
    if (n > 0) {
        cout << endl << "Select the way to create polynomial:" << endl
             << "1 - input from keyboard" << endl
             << "2 - create identity" << endl
             << "3 - create random" << endl;
        int s = 0, item = 1;
        while ((s < 1) or (s > 3)) {
            cin >> s;
            switch (s) {
                case 1: {
                    for (int i = 0; i < n; i++) {
                        cout << "Input value: ";
                        cin >> item;
                        polynomial.Append(item);
                    }
                    break;
                }
                case 2: {
                    for (int i = 0; i < n; i++) {
                        polynomial.Append(item);
                    }
                    break;
                }
                case 3: {
                    for (int i = 0; i < n; i++) {
                        item = rand() % 100;
                        polynomial.Append(item);
                    }
                    break;
                }
                default: {
                    printf("Enter a number from the list!\n");
                    break;
                }
            }
        }
    }
    return polynomial;
}

Polynomial<double> create_polynomial_double() {
    Polynomial<double> polynomial(new ArraySequence<double>());
    int n = -1;
    cout << "Your polynomial size: ";
    cin >> n;
    while (n < 0) {
        cout << "Enter a positive integer!" << endl << "size: ";
        cin >> n;
    }
    if (n > 0) {
        cout << endl << "Select the way to create polynomial:" << endl
             << "1 - input from keyboard" << endl
             << "2 - create identity" << endl
             << "3 - create random" << endl;
        int s = 0;
        double item = 1.0;
        while ((s < 1) or (s > 3)) {
            cin >> s;
            switch (s) {
                case 1: {
                    for (int i = 0; i < n; i++) {
                        cout << "Input value: ";
                        cin >> item;
                        polynomial.Append(item);
                    }
                    break;
                }
                case 2: {
                    for (int i = 0; i < n; i++) {
                        polynomial.Append(item);
                    }
                    break;
                }
                case 3: {
                    for (int i = 0; i < n; i++) {
                        item = (rand() % 1000) / 10;
                        polynomial.Append(item);
                    }
                    break;
                }
                default: {
                    printf("Enter a number from the list!\n");
                    break;
                }
            }
        }
    }
    return polynomial;
}
