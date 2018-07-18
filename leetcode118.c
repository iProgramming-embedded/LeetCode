在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
	*columnSizes = (int*)malloc(sizeof(int)*numRows);
	int** triangle = (int**)malloc(sizeof(int*)*numRows);
	for (int i = 0;i < numRows; i++){
		(*columnSizes)[i] = i + 1;
		triangle[i] = (int*)malloc(sizeof(int)*(i+1));
		triangle[i][0] = triangle[i][i] = 1;
		for(int j = 1; j < i;j++ ){
			triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
		}
	}
	return triangle;
}