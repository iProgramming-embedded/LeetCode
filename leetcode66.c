给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。


int* plusOne(int* digits, int digitsSize, int* returnSize){
	int carry = 1;
	int i;
	for(i=digitsSize-1; i>=0; i--){
		int val = digits[i]+carry;
		carry = val/10;
		digits[i] = val%10;
		
		if(carry = 0)
			break;
	}
	if(carry){
		int *res = (int*)calloc(digitsSize+1,sizeof(int));
		res[0] = 1;
		*returnSize = digitsSize+1;
		return res;
	}else{
		*returnSize = digitSize;
		return digits;
	}
}