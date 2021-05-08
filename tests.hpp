#pragma once

#include <chrono>
#include <utility>
#include <iostream>
#include "Polynomial.hpp"

pair<int, int> test_create_int() {
    const int n = 10000;
    int values[n];
    for (int i = 0; i < n; i++) {
        values[i] = i;
    }

    auto startTime = chrono::steady_clock::now();
    Polynomial<int> polynomial_a(new ArraySequence<int>(values, n));
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    Polynomial<int> polynomial_l(new ListSequence<int>(values, n));
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    return {array_time, list_time};
}

pair<int, int> test_create_double() {
    const int n = 10000;
    double values[n];
    for (int i = 0; i < n; i++) {
        values[i] = i;
    }

    auto startTime = chrono::steady_clock::now();
    Polynomial<double> polynomial_a(new ArraySequence<double>(values, n));
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    Polynomial<double> polynomial_l(new ListSequence<double>(values, n));
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    return {array_time, list_time};
}

pair<int, int> test_copy_int() {
    const int n = 10000;
    int values[n];
    for (int i = 0; i < n; i++) {
        values[i] = i;
    }

    Polynomial<int> polynomial_a(new ArraySequence<int>(values, n));
    auto startTime = chrono::steady_clock::now();
    Polynomial<int> polynomial_a2(polynomial_a);
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    Polynomial<int> polynomial_l(new ListSequence<int>(values, n));
    startTime = chrono::steady_clock::now();
    Polynomial<int> polynomial_l2(polynomial_l);
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    return {array_time, list_time};
}

pair<int, int> test_copy_double() {
    const int n = 10000;
    double values[n];
    for (int i = 0; i < n; i++) {
        values[i] = i;
    }

    Polynomial<double> polynomial_a(new ArraySequence<double>(values, n));
    auto startTime = chrono::steady_clock::now();
    Polynomial<double> polynomial_a2(polynomial_a);
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    Polynomial<double> polynomial_l(new ListSequence<double>(values, n));
    startTime = chrono::steady_clock::now();
    Polynomial<double> polynomial_l2(polynomial_l);
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    return {array_time, list_time};
}

pair<int, int> test_get_int() {
    const int n = 10000;
    int values[n];
    for (int i = 0; i < n; i++) {
        values[i] = i;
    }
    Polynomial<int> polynomial_a(new ArraySequence<int>(values, n));
    Polynomial<int> polynomial_l(new ListSequence<int>(values, n));

    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = polynomial_a[i];
    }
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = polynomial_l[i];
    }
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    return {array_time, list_time};
}

pair<int, int> test_get_double() {
    const int n = 10000;
    double values[n];
    for (int i = 0; i < n; i++) {
        values[i] = i;
    }
    Polynomial<double> polynomial_a(new ArraySequence<double>(values, n));
    Polynomial<double> polynomial_l(new ListSequence<double>(values, n));

    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = polynomial_a[i];
    }
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = polynomial_l[i];
    }
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    return {array_time, list_time};
}

pair<int, int> test_append_int() {
    const int n = 10000;
    Polynomial<int> polynomial_a(new ArraySequence<int>());
    Polynomial<int> polynomial_l(new ListSequence<int>());

    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i;
        polynomial_a.Append(item);
    }
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i;
        polynomial_l.Append(item);
    }
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    return {array_time, list_time};
}

pair<int, int> test_append_double() {
    const int n = 10000;
    Polynomial<double> polynomial_a(new ArraySequence<double>());
    Polynomial<double> polynomial_l(new ListSequence<double>());

    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i;
        polynomial_a.Append(item);
    }
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i;
        polynomial_l.Append(item);
    }
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    return {array_time, list_time};
}

pair<int, int> test_prepend_int() {
    const int n = 10000;
    Polynomial<int> polynomial_a(new ArraySequence<int>());
    Polynomial<int> polynomial_l(new ListSequence<int>());

    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i;
        polynomial_a.Prepend(item);
    }
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i;
        polynomial_l.Prepend(item);
    }
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    return {array_time, list_time};
}

pair<int, int> test_prepend_double() {
    const int n = 10000;
    Polynomial<double> polynomial_a(new ArraySequence<double>());
    Polynomial<double> polynomial_l(new ListSequence<double>());

    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i;
        polynomial_a.Prepend(item);
    }
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i;
        polynomial_l.Prepend(item);
    }
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    return {array_time, list_time};
}

pair<int, int> test_insert_int() {
    const int n = 10000;
    Polynomial<int> polynomial_a(new ArraySequence<int>());
    Polynomial<int> polynomial_l(new ListSequence<int>());

    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i;
        polynomial_a.InsertAt(item, polynomial_a.GetSize() / 2);
    }
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = i;
        polynomial_l.InsertAt(item, polynomial_l.GetSize() / 2);
    }
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    return {array_time, list_time};
}

pair<int, int> test_insert_double() {
    const int n = 10000;
    Polynomial<double> polynomial_a(new ArraySequence<double>());
    Polynomial<double> polynomial_l(new ListSequence<double>());

    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i;
        polynomial_a.InsertAt(item, polynomial_a.GetSize() / 2);
    }
    auto endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = i;
        polynomial_l.InsertAt(item, polynomial_l.GetSize() / 2);
    }
    endTime = chrono::steady_clock::now();
    int list_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    return {array_time, list_time};
}