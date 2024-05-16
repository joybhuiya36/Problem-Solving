#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubArraySum(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int leftMax = maxSubArraySum(arr, low, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, high);
    int crossMax = maxCrossingSum(arr, low, mid, high);

    return max(leftMax, rightMax, crossMax);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxSum = maxSubArraySum(arr, 0, n - 1);

    cout << maxSum << endl;

    return 0;
}
