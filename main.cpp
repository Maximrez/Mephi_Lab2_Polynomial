#include <chrono>
#include <string>
#include <iostream>
#include <fstream>
#include "Polynomial.hpp"
#include "tests.hpp"

using namespace std;

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

int main() {
    const string file_name = "logs.txt";
    ofstream fout(file_name, ios_base::trunc);
    fout.close();
    write_results(test_create_int(), file_name, "TEST CREATE INT");
    write_results(test_create_double(), file_name, "TEST CREATE DOUBLE");
    write_results(test_append_int(), file_name, "TEST APPEND INT");
    write_results(test_append_double(), file_name, "TEST APPEND DOUBLE");
    return 0;
}
