#pragma once

#include "DynamicArray.hpp"

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> items;
public:
    ArraySequence() : items() {}

    ArraySequence(T *list, int size) : items(list, size) {}

    ArraySequence(ArraySequence<T> &list) : items(list.items) {}

    void Resize(int size) override {
        items.Resize(size);
    }

    T GetFirst() const override {
        return items[0];
    }

    T GetLast() const override {
        return items[items.GetSize() - 1];
    }

    T &Get(int index) const override {
        return items.Get(index);
    }

    T operator[](int index) const override {
        return items[index];
    }

    T &operator[](int index) override {
        return items[index];
    }

    [[nodiscard]] int GetSize() const override {
        return items.GetSize();
    }

    void Append(T &item) override {
        int size = items.GetSize();
        items.Resize(size + 1);
        items[size] = item;
    }

    void Prepend(T &item) override {
        int size = items.GetSize();
        items.Resize(size + 1);
        for (int i = size; i > 0; i--)
            items[i] = items[i - 1];
        items[0] = item;
    }

    void InsertAt(T &item, int index) override {
        int size = items.GetSize();
        if (index < 0 || index > size)
            throw out_of_range("Index out of range");
        items.Resize(size + 1);
        for (int i = size; i > index; i--)
            items[i] = items[i - 1];
        items[index] = item;
    }

    Sequence<T> *GetSubsequence(int startIndex, int endIndex) override {
        auto *sub = new ArraySequence<T>;
        sub->items.Resize(endIndex - startIndex);
        for (int i = startIndex; i < endIndex; i++)
            sub->items[i - startIndex] = items[i];
        return sub;
    }

    Sequence<T> *Concat(Sequence<T> &list) override {
        auto *concatenated = new ArraySequence<T>;
        concatenated->items.Resize(GetSize() + list.GetSize());
        for (int i = 0; i < items.GetSize(); i++)
            concatenated->items[i] = items[i];
        for (int i = 0; i < list.GetSize(); i++)
            concatenated->items[i + items.GetSize()] = list[i];
        return concatenated;
    }

    void Print() const override {
        bool zero = true;
        for (int i = 0; i < GetSize(); ++i) {
            T value = items[i];
            if (value != 0) {
                zero = false;
                if (i == 0) {
                    cout << value;
                } else {
                    if (value < 0) {
                        cout << " - ";
                    } else {
                        cout << " + ";
                    }
                    if (abs(value) != 1)
                        cout << abs(value);
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
            }
        }
        if (zero)
            cout << 0;
        cout << endl;
    }

    virtual ~ArraySequence<T>() = default;

};