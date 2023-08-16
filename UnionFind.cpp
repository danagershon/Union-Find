#include "UnionFind.h"

UnionFind::UnionFind(int n) : n(n) {
    parent_array = new int[n+1];
    sizes_array = new int[n+1];
    for (int i = 1; i <= n; i++) {
        parent_array[i] = NO_PARENT;
        sizes_array[i] = 1;
    }
}

UnionFind::~UnionFind() {
    delete[] parent_array;
    delete[] sizes_array;
}

int UnionFind::Find(int element_name) {
    if(parent_array[element_name] == NO_PARENT) {
        return element_name;
    }

    int curr_parent = parent_array[element_name];

    while(parent_array[curr_parent] != NO_PARENT) {
        curr_parent = parent_array[curr_parent];
    }

    int group_name = curr_parent;

    compressPath(group_name, element_name);

    return group_name;
}

int UnionFind::Union(int element_name1, int element_name2) {
    int group_name1 = Find(element_name1);
    int group_name2 = Find(element_name2);

    if(group_name1 == group_name2) {
        return SAME_GROUP;
    }

    int bigger_group;
    int smaller_group;

    if(sizes_array[group_name1] < sizes_array[group_name2]) {
        bigger_group = group_name2;
        smaller_group = group_name1;
    } else {
        bigger_group = group_name1;
        smaller_group = group_name2;
    }

    parent_array[smaller_group] = bigger_group;
    sizes_array[bigger_group] += sizes_array[smaller_group];
    sizes_array[smaller_group] = NOT_ROOT;

    return bigger_group;
}

void UnionFind::compressPath(int group_name, int element_name) {
    int curr_element = element_name;

    while(parent_array[curr_element] != NO_PARENT) {
        int temp = curr_element;
        curr_element = parent_array[curr_element];
        parent_array[temp] = group_name;
    }
}
