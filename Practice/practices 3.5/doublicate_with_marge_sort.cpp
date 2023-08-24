/*
https://www.codingninjas.com/studio/problems/find-duplicate-in-array_1112602?leftPanelTab=0

#include <bits/stdc++.h>
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int findDuplicate(vector<int> &arr, int n){
     merge_sort(arr, 0, arr.size() - 1);
	// sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return arr[i];
        }
    }
    return -1;
	
}



*/