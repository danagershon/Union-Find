#ifndef WET2CPP_UNIONFIND_H
#define WET2CPP_UNIONFIND_H

const int SAME_GROUP = -1;
const int NO_PARENT = -2;
const int NOT_ROOT = -3;

class UnionFind {
    int n;
    int* parent_array;
    int* sizes_array;

    void compressPath(int group_name, int element_name);

public:
    explicit UnionFind(int n);

    ~UnionFind();

    int Find(int element_name);

    int Union(int element_name1, int element_name2);
};

#endif //WET2CPP_UNIONFIND_H
