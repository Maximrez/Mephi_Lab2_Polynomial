#include <string>
#include <iostream>
#include <fstream>
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

    write_results(test_copy_int(), file_name, "TEST COPY INT");
    write_results(test_copy_double(), file_name, "TEST COPY DOUBLE");

    write_results(test_get_int(), file_name, "TEST GET INT");
    write_results(test_get_double(), file_name, "TEST GET DOUBLE");

    write_results(test_append_int(), file_name, "TEST APPEND INT");
    write_results(test_append_double(), file_name, "TEST APPEND DOUBLE");

    write_results(test_prepend_int(), file_name, "TEST PREPEND INT");
    write_results(test_prepend_double(), file_name, "TEST PREPEND DOUBLE");

    write_results(test_insert_int(), file_name, "TEST INSERT INT");
    write_results(test_insert_double(), file_name, "TEST INSERT DOUBLE");

    write_results(test_add_int(), file_name, "TEST ADD INT");
    write_results(test_add_double(), file_name, "TEST ADD DOUBLE");

    write_results(test_mul_scalar_int(), file_name, "TEST MUL SCALAR INT");
    write_results(test_mul_scalar_double(), file_name, "TEST MUL SCALAR DOUBLE");

    write_results(test_mul_polynomial_int(), file_name, "TEST MUL POLYNOMIAL INT");
    write_results(test_mul_polynomial_double(), file_name, "TEST MUL POLYNOMIAL DOUBLE");

    write_results(test_composition_int(), file_name, "TEST COMPOSITION INT");
    write_results(test_composition_double(), file_name, "TEST COMPOSITION DOUBLE");

    return 0;
}
