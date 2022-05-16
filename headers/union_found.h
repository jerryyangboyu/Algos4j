//
// Created by Jerry on 2022/5/16.
//

#pragma once


class UF {
private:
    int* id;
    int _count;
    int length;
public:
    explicit UF(int N);
    ~UF();
    int count() const;
    bool connected(int p, int q);
    int find(int p);
    void connect(int p, int q);
};

