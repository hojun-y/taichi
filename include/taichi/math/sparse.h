#pragma once

#include <taichi/math/linalg.h>
#include <taichi/math/array_1d.h>

TC_NAMESPACE_BEGIN

class SparseMatrix {
private:
    struct Entry {
        int j;
        real val;
        Entry() {}
        Entry(int j, real val) : j(j), val(val) {}
    };

    //TODO: This is slow... make some low-level optimizations here...
    std::vector<std::vector<Entry>> entries;

    int n;

public:

    SparseMatrix(int n) : n(n) {
        entries.resize(n);
    }

    SparseMatrix() {}

    void insert(int i, int j, real value) {
        for (int k = 0; k < (int)entries[i].size(); k++) {
            if (entries[i][k].j == j) {
                entries[i][k].val += value;
                return;
            }
        }
        entries[i].push_back(Entry(j, value));
    }

    void clear() {
        for (int i = 0; i < n; i++) {
            entries[i].clear();
        }
    }

    Array1D multiply(const Array1D &x) {
        Array1D y(x.get_dim());

        return y;
    }
};

TC_NAMESPACE_END
