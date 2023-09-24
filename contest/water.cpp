#include <iostream>
#include <vector>

using namespace std;

void maxWaterContainer(const vector<int>& heights, int& leftIndex, int& rightIndex) {
    int left = 0;
    int right = heights.size() - 1;
    int maxArea = 0;

    while (left < right) {
        // Calculate the width of the container.
        int width = right - left;
        // Calculate the height of the container.
        int minHeight = min(heights[left], heights[right]);
        // Calculate the area of the container.
        int area = width * minHeight;

        // Update the maximum area and indices if the current area is greater.
        if (area > maxArea) {
            maxArea = area;
            leftIndex = left;
            rightIndex = right;
        }

        // Move the pointers.
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> heights(N);
        for (int i = 0; i < N; i++) {
            cin >> heights[i];
        }

        int leftIndex, rightIndex;
        maxWaterContainer(heights, leftIndex, rightIndex);

        // Adding 1 to the indices to convert them from 0-based to 1-based.
        cout << leftIndex + 1 << " " << rightIndex + 1 << endl;
    }

    return 0;
}
