#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Enter your code here
    vector<int> nums;
    
    int num = 0;
    
    while (num != -1)
    {
        cout << "Please enter a positive number (-1 to quit): ";
        cin >> num;
        
        if (num == -1)
        {
            break;
        }
        
        vector<int>::iterator itr = nums.begin();
        
        int insertIdx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (num <= nums[i])
            {
                break;
            }
            insertIdx = i;
        }
        nums.insert(itr + insertIdx, num);
    }
    
    for (int number : nums)
    {
        cout << number << endl;
    }
    
    
    return 0;
}