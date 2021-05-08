#pragma once

#include "ListSequence.hpp"
#include "ArraySequence.hpp"

using namespace std;

template<class T>
class Polynomial {
    Sequence<T> *coefficients;
public:
    Polynomial(Polynomial<T> &polynomial) : coefficients(polynomial.coefficients) {};

    explicit Polynomial(Sequence<T> &sequence) : coefficients(&sequence) {};

    void Resize(int size) {
        coefficients->Resize(size);
    }

    [[nodiscard]] int GetSize() const {
        return coefficients->GetSize();
    }

    T GetFirst() const {
        return coefficients->GetFirst();
    }

    T GetLast() const {
        return coefficients->GetLast();
    }

    T &Get(int index) const {
        return (*coefficients)[index];
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
        int size1 = GetSize();
        int size2 = polynomial.GetSize();
        int target_size = size1 + size2 - 1;
        mulled->Resize(target_size);
        for (int i = 0; i < target_size; i++)
            (*mulled)[i] = NULL;
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                (*mulled)[i + j] = (*coefficients)[i] * polynomial[j];
            }
        }
        return mulled;
    }

    ~Polynomial() = default;
};
