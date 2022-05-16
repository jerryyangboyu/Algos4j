//
// Created by Jerry on 2022/5/16.
//

#include "../../headers/union_found.h"

UF::UF(int N) {
    this->_count = N;
    this->length = N;
    id = new int[N];
    for (int i = 0; i < N; ++i) {
        id[i] = i;
    }
}

UF::~UF() {
    delete id;
}

int UF::count() const {
    return this->_count;
}

bool UF::connected(int p, int q) {
    return find(p) == find(q);
}

int UF::find(int p) {
    return this->id[p];
}

void UF::connect(int p, int q) {
    int pID = find(p);
    int qID = find(q);

    if (pID == qID) return;

    for (int i = 0; i < this->length; i++)
        if (id[i] == pID) id[i] = qID;

    this->_count--;
}


