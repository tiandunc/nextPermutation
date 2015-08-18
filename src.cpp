#include<iostream>
using namespace std;
void reverse(int* x, int len)
{
	int t;
	for(int i = 0, j = len - 1; i < j; i++, j--)
	{
		t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
}

void nextPermutation(int* nums, int numsSize) {
	if(numsSize <= 1 || !nums)
		return;
	int i,j;
	for(i = numsSize - 2; i >= 0; i--)
	{
		if(nums[i] < nums[i + 1])
			break;
	}//从后往前数第一个比当前值还要小的
	if(i < 0)
	{
		reverse(nums, numsSize);
	}
	else
	{
		for(j = numsSize - 1; j > i; j--)
			if(nums[j] > nums[i])
				break;
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
		reverse(nums + i + 1, numsSize - i - 1);
	}
}
int main()
{
	int x[] = {8,9,7};
	int len = sizeof(x)/sizeof(int);
	nextPermutation(x,len);
	for(int i = 0; i < len; i++)
		cout<<x[i]<<" ";
	cout<<endl;
	return 0;
}