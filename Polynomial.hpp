#pragma once

#include <cmath>
#include <limits>
#include "ListSequence.hpp"
#include "ArraySequence.hpp"

using namespace std;

template<class T>
class Polynomial {
    Sequence<T> *coefficients;
public:
    Polynomial(const Polynomial<T> &polynomial) : coefficients(polynomial.coefficients->Clone()) {};

    explicit Polynomial(Sequence<T> *sequence) : coefficients(sequence->Clone()) {};

    [[nodiscard]] int GetSize() const {
        return coefficients->GetSize();
    }

    void Resize(int size) {
        coefficients->Resize(size);
    }

    T &Get(int index) const {
        return (*coefficients)[index];
    }

    T GetFirst() const {
        return coefficients->GetFirst();
    }

    T GetLast() const {
        return coefficients->GetLast();
    }

    T operator[](int index) const {
        return (*coefficients)[index];
    }

    T &operator[](int index) {
        return (*coefficients)[index];
    }

    void Append(T &item) {
        coefficients->Append(item);
    }

    void Prepend(T &item) {
        coefficients->Prepend(item);
    }

    void InsertAt(T &item, int index) {
        coefficients->InsertAt(item, index);
    }

    void Print() const {
        coefficients->Print();
    }

    Polynomial<T> *AddPolynomial(Polynomial<T> &polynomial) {
        auto *summed = new Polynomial<T>(coefficients);
        int target_size = max(GetSize(), polynomial.GetSize());
        summed->Resize(target_size);
        for (int i = 0; i < target_size; i++) {
            if (i < polynomial.GetSize())
                (*summed)[i] += polynomial[i];
        }
        return summed;
    }

    Polynomial<T> *MulScalar(T scalar) {
        auto *mulled = new Polynomial<T>(coefficients);
        for (int i = 0; i < GetSize(); i++) {
            (*mulled)[i] *= scalar;
        }
        return mulled;
    }

    Polynomial<T> *MulPolynomial(Polynomial<T> &polynomial) {
        if (GetSize() == 0)
            return this;
        if (polynomial.GetSize() == 0)
            return new Polynomial<T>(polynomial);
        auto *mulled = new Polynomial<T>(coefficients);
        int target_size = GetSize() + polynomial.GetSize() - 1;
        mulled->Resize(target_size);
        for (int i = 0; i < target_size; i++)
            (*mulled)[i] = 0;
        for (int i = 0; i < GetSize(); i++) {
            for (int j = 0; j < polynomial.GetSize(); j++) {
                (*mulled)[i + j] += (*coefficients)[i] * polynomial[j];
            }
        }
        return mulled;
    }

    T CalculatingValue(T value) {
        T result = 0;
        for (int i = 0; i < GetSize(); ++i) {
            T item = (*coefficients)[i];
            result += item * pow(value, i);
        }
        return result;
    }

    Polynomial<T> *Composition(Polynomial<T> &polynomial) {
        if (GetSize() == 0)
            return new Polynomial<T>(polynomial);
        if (polynomial.GetSize() == 0)
            return this;
        auto *composition = new Polynomial<T>(coefficients);
        for (int i = 1; i < GetSize(); i++)
            (*composition)[i] = 0;
        for (int i = 1; i < GetSize(); i++) {
            T item = (*coefficients)[i];
            auto *composited = new Polynomial<T>(polynomial);
            for (int j = 0; j < i - 1; j++) {
                composited = composited->MulPolynomial(polynomial);
            }
            composited = composited->MulScalar(item);
            composition = composition->AddPolynomial(*composited);
        }
        return composition;
    }

    Polynomial<T> &operator=(const Polynomial<T> *polynomial) {
        coefficients = polynomial->coefficients->Clone();
        return *this;
    }

    friend bool operator==(const Polynomial<T> &polynomial1, const Polynomial<T> &polynomial2) {
        if (polynomial1.GetSize() != polynomial2.GetSize()) {
            return false;
        } else {
            for (int i = 0; i < polynomial1.GetSize(); i++) {
                if (fabs(polynomial1[i] - polynomial2[i]) >= numeric_limits<double>::epsilon()) {
                    return false;
                }
            }
        }
        return true;
    }

    friend bool operator!=(const Polynomial<T> &polynomial1, const Polynomial<T> &polynomial2) {
        return !(polynomial1 == polynomial2);
    }

    ~Polynomial() = default;
};
