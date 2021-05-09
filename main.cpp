#include <string>
#include <iostream>
#include "tests.hpp"
#include "functions.hpp"

using namespace std;

int main() {
    int s1 = 0;
    while (s1 != 3) {
        cout << endl << "Select an action:" << endl << "1 - create polynomial" << endl << "2 - run tests" << endl
             << "3 - exit" << endl;
        cin >> s1;
        switch (s1) {
            case 1: {
                Polynomial<int> polynomial = create_polynomial_int();
                int s2 = -1, index, item;
                while (s2 != 0) {
                    cout << endl << "Your polynomial:" << endl;
                    polynomial.Print();
                    cout << endl << "Select the action with polynomial:" << endl
                         << "1 - change element" << endl
                         << "2 - append element" << endl
                         << "3 - prepend element" << endl
                         << "4 - insert element" << endl
                         << "5 - add polynomial" << endl
                         << "6 - multiply by scalar" << endl
                         << "7 - multiply by polynomial" << endl
                         << "8 - composition" << endl
                         << "9 - calculating value" << endl
                         << "0 - exit" << endl;
                    cin >> s2;
                    switch (s2) {
                        case 1: {
                            cout << "index: ";
                            cin >> index;
                            while ((index < 0) or (index >= polynomial.GetSize())) {
                                cout << "Index out of range!" << endl << "index: ";
                                cin >> index;
                            }
                            cout << "old value: " << polynomial[index] << endl;
                            cout << "new value: ";
                            cin >> item;
                            polynomial[index] = item;
                            break;
                        }
                        case 2: {
                            cout << "new value: ";
                            cin >> item;
                            polynomial.Append(item);
                            break;
                        }
                        case 3: {
                            cout << "new value: ";
                            cin >> item;
                            polynomial.Prepend(item);
                            break;
                        }
                        case 4: {
                            cout << "index: ";
                            cin >> index;
                            while ((index < 0) or (index > polynomial.GetSize())) {
                                cout << "Index out of range!" << endl << "index: ";
                                cin >> index;
                            }
                            cout << "new value: ";
                            cin >> item;
                            polynomial.InsertAt(item, index);
                            break;
                        }
                        case 5: {
                            Polynomial<int> new_polynomial = create_polynomial_int();
                            cout << endl << "New polynomial:" << endl;
                            new_polynomial.Print();
                            polynomial = polynomial.AddPolynomial(new_polynomial);
                            break;
                        }
                        case 6: {
                            int scalar;
                            cout << "scalar: ";
                            cin >> scalar;
                            polynomial = polynomial.MulScalar(scalar);
                            break;
                        }
                        case 7: {
                            Polynomial<int> new_polynomial = create_polynomial_int();
                            cout << endl << "New polynomial:" << endl;
                            new_polynomial.Print();
                            polynomial = polynomial.MulPolynomial(new_polynomial);
                            break;
                        }
                        case 8: {
                            Polynomial<int> new_polynomial = create_polynomial_int();
                            cout << endl << "New polynomial:" << endl;
                            new_polynomial.Print();
                            polynomial = polynomial.Composition(new_polynomial);
                            break;
                        }
                        case 9: {
                            int value;
                            cout << "value: ";
                            cin >> value;
                            cout << "result: " << polynomial.CalculatingValue(value) << endl;
                            break;
                        }
                        case 0: {
                            break;
                        }
                        default: {
                            printf("Enter a number from the list!\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
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

                write_results(test_calculating_int(10000), file_name, "TEST CALCULATING INT (N=10000)");
                write_results(test_calculating_double(10000), file_name, "TEST CALCULATING DOUBLE (N=10000)");

                cout << "Tests successfully saved to " << file_name << endl;
                break;
            }
            case 3 : {
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
                break;
            }
        }
    }
    return 0;
}
