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

    write_results(test_create_int(10000), file_name, "TEST CREATE INT (N=10000)");
    write_results(test_create_double(10000), file_name, "TEST CREATE DOUBLE (N=10000)");

    write_results(test_copy_int(10000), file_name, "TEST COPY INT (N=10000)");
    write_results(test_copy_double(10000), file_name, "TEST COPY DOUBLE (N=10000)");

    write_results(test_get_int(10000), file_name, "TEST GET INT (N=10000)");
    write_results(test_get_double(10000), file_name, "TEST GET DOUBLE (N=10000)");

    write_results(test_append_int(10000), file_name, "TEST APPEND INT (N=10000)");
    write_results(test_append_double(10000), file_name, "TEST APPEND DOUBLE (N=10000)");

    write_results(test_prepend_int(10000), file_name, "TEST PREPEND INT (N=10000)");
    write_results(test_prepend_double(10000), file_name, "TEST PREPEND DOUBLE (N=10000)");

    write_results(test_insert_int(10000), file_name, "TEST INSERT INT (N=10000)");
    write_results(test_insert_double(10000), file_name, "TEST INSERT DOUBLE (N=10000)");

    write_results(test_add_int(10000), file_name, "TEST ADD INT (N=10000)");
    write_results(test_add_double(10000), file_name, "TEST ADD DOUBLE (N=10000)");

    write_results(test_mul_scalar_int(10000), file_name, "TEST MUL SCALAR INT (N=10000)");
    write_results(test_mul_scalar_double(10000), file_name, "TEST MUL SCALAR DOUBLE (N=10000)");

    write_results(test_mul_polynomial_int(1000), file_name, "TEST MUL POLYNOMIAL INT (N=1000)");
    write_results(test_mul_polynomial_double(1000), file_name, "TEST MUL POLYNOMIAL DOUBLE (N=1000)");

    write_results(test_composition_int(30), file_name, "TEST COMPOSITION INT (N=30)");
    write_results(test_composition_double(30), file_name, "TEST COMPOSITION DOUBLE (N=30)");

    return 0;
}
