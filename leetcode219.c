给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

解题思路：循环判断，判断条件增加一个差值判断即可。
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
	int i,j;
	for(i=0; i<numsSize; i++){
		for(j=i+1; j<numsSize; j++){
			if((nums[i]==nums[j]&&((j-i)<=k))
				return true;
		}
	}
	return false;
}
