/*题号：26.删除排序数组中的重复项

示例：

给定数组nums=[1,1,2];

函数应该返回新的长度2，原数组的前两个元素被改为1，2.

解题思路：定义一个局部变量与数组中的所有元素进行逐次比较，如果不相同就加一，将其传入数组保存*/


int remove(int *nums,int numsSize)  
{  
    int num=0;  
  if(numsSize==0)｛  
    return 0;  
    ｝            //注：第一次提交未能通过，原因是没有考虑数组长度为0的情况，考虑问题应该全面  
    for(int i=0;i<numsSize;i++){  
        if(nums[i]!=nums[num]){  
          num++;  
          nums[num]=nums[i];  
        }  
    }  
    num+=1;  
         return num;  
}