class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> *max1;
        max1 = findMaxSubarray(A, 0, n - 1);
        return max1->at(2);
    }
    vector<int> *findMaxCrossingSubarray(int A[], int low, int mid, int high) {
        int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
        vector<int> *m = new vector<int>(3, 0);
        for (int i = mid; i >= low; i--) {
            sum += A[i];
            if (sum > leftSum) {
                leftSum = sum;
                m->at(0) = i;
            }
        }
        sum = 0;
        for (int j = mid + 1; j <= high; j++) {
            sum += A[j];
            if (sum > rightSum) {
                rightSum = sum;
                    m->at(1) = j;
            }
        }
        m->at(2) = leftSum + rightSum;
        return m;
    }
    vector<int> *findMaxSubarray(int A[], int low, int high) {
        vector<int> *m = new vector<int>(3, 0);
        if (high == low) {
            m->at(0) = low, m->at(1) = high, m->at(2) = A[low];
            return m;
        }
        else {
            int mid = (low + high) / 2;
            vector<int> *left = findMaxSubarray(A, low, mid);
            vector<int> *right = findMaxSubarray(A, mid + 1, high);
            vector<int> *cross = findMaxCrossingSubarray(A, low, mid, high);
            if (left->at(2) >= right->at(2) && left->at(2) >= cross->at(2))
                return left;
            else if (right->at(2) >= left->at(2) && right->at(2) >= cross->at(2))
                return right;
            else
                return cross;
        }

    }
};