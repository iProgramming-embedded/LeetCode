反转整数

给定一个32位有符号整数，将整数中的数字进行反转；

示例：输入：123

          输出：321
          
思路：
int reverse(int x)  
{  
int result=0;  
while(x!=0){  
int temp=result*10+x%10;  
if(temp/10!=result){  
return 0;  
}   //考虑溢出的情况，temp由商和余数构成，当溢出之后，值的商一定不会再等于result  
result=temp;  
x=x/10;  
}  
return result;
