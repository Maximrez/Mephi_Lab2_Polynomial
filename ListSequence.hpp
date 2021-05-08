#pragma once

#include "LinkedList.hpp"
#include "Sequence.hpp"

template<class T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> items;
public:
    ListSequence() : items() {}

    ListSequence(T *list, int size) : items(list, size) {}

    ListSequence(ListSequence<T> &list) : items(list.items) {}

    void Resize(int size) override {
        items.Resize(size);
    }

    T GetFirst() const override {
        return items.GetFirst();
    }

    T GetLast() const override {
        return items.GetLast();
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
        items.Append(item);
    }

    void Prepend(T &item) override {
        items.Prepend(item);
    }

    void InsertAt(T &item, int index) override {
        items.InsertAt(item, index);
    }

    Sequence<T> *GetSubsequence(int startIndex, int endIndex) override {
        auto *sub = new ListSequence<T>;
        for (int i = startIndex; i < endIndex; i++)
            sub->Append(items[i]);
        return sub;
    }

    Sequence<T> *Concat(Sequence<T> &list) override {
        auto *concatenated = new ListSequence<T>(*this);
        for (int i = 0; i < list.GetSize(); i++) {
            concatenated->Append(list[i]);
        }
        return concatenated;
    }

    void Print() const override {
        items.Print();
    }

    virtual ~ListSequence<T>() = default;
};