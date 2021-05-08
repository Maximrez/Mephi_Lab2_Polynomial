#include <iostream>
#include <chrono>
#include "Polynomial.hpp"

using namespace std;

int main() {
    chrono::time_point<chrono::steady_clock> startTime, endTime;

    int list[3];
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int item;

    cout << "Array" << endl;

    startTime = chrono::steady_clock::now();

    ArraySequence<int> seq_a;

    item = 2;
    seq_a.Append(item);
    item = 3;
    seq_a.Append(item);
    item = 5;
    seq_a.Append(item);
    item = 1;
    seq_a.Prepend(item);
    item = 4;
    seq_a.InsertAt(item, 3);

    ArraySequence<int> seq1_a(seq_a);

    seq_a.Print();
    seq1_a.Print();

    cout << seq_a.GetFirst() << ' ' << seq_a.GetLast() << endl;

    auto concatenated_a = seq_a.Concat(seq1_a);
    concatenated_a->Print();

    auto subsequence_a = concatenated_a->GetSubsequence(2, 7);
    subsequence_a->Print();

    ArraySequence<int> seq2_a(list, 3);
    seq2_a.Print();

    seq2_a[1] = -2;

    seq2_a.Resize(4);

    seq2_a.InsertAt(item, 4);
    seq2_a.Print();

    endTime = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " microseconds" << endl;

    cout << endl << "List" << endl;

    startTime = chrono::steady_clock::now();
    ListSequence<int> seq_l;

    item = 2;
    seq_l.Append(item);
    item = 3;
    seq_l.Append(item);
    item = 5;
    seq_l.Append(item);
    item = 1;
    seq_l.Prepend(item);
    item = 4;
    seq_l.InsertAt(item, 3);

    ListSequence<int> seq1_l(seq_l);

    seq_l.Print();
    seq1_l.Print();

    cout << seq_l.GetFirst() << ' ' << seq_l.GetLast() << endl;

    auto concatenated_l = seq_l.Concat(seq1_l);
    concatenated_l->Print();

    auto subsequence_l = concatenated_l->GetSubsequence(2, 7);
    subsequence_l->Print();

    ListSequence<int> seq2_l(list, 3);
    seq2_l.Print();

    seq2_l[1] = -2;

    seq2_l.Resize(4);

    seq2_l.InsertAt(item, 4);
    seq2_l.Print();

    endTime = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " microseconds" << endl;

    cout << endl << "Polynomial" << endl;

    Polynomial<int> p(seq2_a);

    seq2_a[1] = 0;

    p.Print();

//    auto p_mul = p.MulPolynomial(p);
//
//    p_mul->Print();
//
//    auto p_sum = p.AddPolynomial(p);
//    p_sum->Print();
//
//    auto p_mul = p_sum->MulScalar(3);
//    p_mul->Print();


    return 0;
}
