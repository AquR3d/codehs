#include "util.h"
#include <vector>

void calculate(vector<double> & nums, double *mean, double *min, double *max){
    
    if (nums.empty()) {
        *mean = 0;
        *min = 0;
        *max = 0;
        return;
    }
    
    // calculate mean
    for (int i = 0; i < nums.size(); i++) *mean += nums[i];
    *mean /= nums.size();
    
    // find min
    *min = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < *min) *min = nums[i];    
    }
    
    //find max
    *max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > *max) *max = nums[i];    
    }
}

int main()
{
    
    vector<double> nums;
    // Enter your code here
    while (true) {
        double num = readDouble("Please enter a positive number (-1 to quit): ");
        if (num == -1) break;
        nums.push_back(num);
    }
    
    double mean, min, max;
    
    calculate(nums, &mean, &min, &max);
    
    cout << "Min: " << min << "\nMax: " << max << "\nMean: " << mean << endl;
    
    return 0;
}