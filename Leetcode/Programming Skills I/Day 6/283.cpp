#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<int> nums;

    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(12);
    int j=0;
    for(int i=0;i<nums.size();i++)
    {
    	if(nums[i]!=0)
    	{
    		nums[j]=nums[i];			//
    		if(i!=j)
    		{							//swap(nums[j],nums[i]);
    			nums[i]=0;
			}							//
			j++;
		}
	}
	    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
	return 0;
}

//180ms time
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int count=0;
//         for(int i=0;i<nums.size()-count;i++)
//        {
//            if(nums[i]==0)
//            {
//            	agn:
//                nums.erase(nums.begin()+i);
//                nums.push_back(0);
//                count++;
//                if(count>nums.size())
//                break;
//                if(nums[i]==0)
//                goto agn;
//            }
//        }
//    }
//}; 



//void moveZeros(vector<int>& nums) {
//    int slow = 0;
//    for (int fast = 0; fast < nums.size(); fast++) {
//        if (nums[fast] != 0) {
//            swap(nums[slow++], nums[fast]);
//        }
//    }
//}
//
//int main() {
//    vector<int> nums;
//    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(0);
//    nums.push_back(3);
//    nums.push_back(12);
//    moveZeros(nums);
//    for (int i=0;i<5;i++) {
//        cout<< nums[i]<< " ";
//    }
//    cout << endl;
//    return 0;
//}

