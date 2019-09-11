//
//  快速排序.cpp
//  0 week
//
//  Created by Apple on 2019/2/15.
//  Copyright © 2019年 Apple. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int partition(int lo, int hi){
    swap(a[lo], a[lo + rand()%(hi - lo + 1)]);
    int pivot = a[lo];
    //printf("%d", pivot);
    while (lo < hi) {
        while((lo < hi) && pivot <= a[hi])
            hi--;
        a[lo] = a[hi];
        while((lo < hi) && (a[lo] <= pivot))
            lo++;
        a[hi] = a[lo];
    }
    a[lo] = pivot;
    return lo;
}


void quickSort(int lo, int hi){
    if(hi - lo < 2)
        return;
    int mi = partition(lo, hi - 1);
    quickSort(lo, mi);
    quickSort(mi+1, hi);}


void getanswer(int n){
    quickSort(0, n);
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    getanswer(n);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
    return 0;
}
