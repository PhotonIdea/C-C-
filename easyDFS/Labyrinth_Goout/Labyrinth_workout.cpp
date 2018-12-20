//目的：快速判断一个maze是否有解
/*****************************
* author：wyrctzy
* environment：VS 2019
* time：2018/12/20 03：22
*****************************/
#include "pch.h"
#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
using namespace std;
char** maze;//二维迷宫数组
int** traveled;//迷宫拜访数组
//定义四种可能的移动方式
int move[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool DFS(int n, int m) {
	//遍历上下左右4个点，保证每次只改变x或y坐标 
	for (int i = 0; i < 4; i++) {
		//获得当前的位置 1.行不动，列动→ 2行动，列不动↓ 3.← 4.↑
		int current_n = n + move[i][0], current_m = m + move[i][1];
		if (maze[current_m][current_n] == '*'&&traveled[current_m][current_n] == 0 && maze[current_m][current_n] != '#') {//可通过，而且以前没有走过
			traveled[current_m][current_n] = 1;//标记为已走过这个位置 
			if (DFS(current_n, current_m))
				return  true;
		}
		if (maze[current_m][current_n] == 'T')//终点 
			return true;
	}
	return false;
}
int main() {
	int  m, n;//m行，n列
	int pos_m = 0, pos_n = 0;//起点的xy坐标
	scanf_s("%d%d", &m, &n);
	getchar();//输入数字，后输入字符getchar吃掉回车符
	//C++写法申请一个动态二维数组
	maze = new char*[m+2];
	for (int i = 0; i <=m+2; i++) {
		maze[i] = new char[n+2];
		memset(maze[i], '#', (n + 2) * sizeof(char));
	}
	traveled = new int*[m+2];
	for (int i = 0; i <= m+2; i++) {
		traveled[i] = new int[(n + 2)];
		memset(traveled[i], 0, (n + 2) * sizeof(int));
	}
	//C 写法
	/*maze = (char**)malloc((m + 2) * sizeof(char*));
	for (int i = 0; i < (m + 2); i++) {
		maze[i] = (char*)malloc((n + 2) * sizeof(char));
	}
	traveled = (int**)malloc((m + 2) * sizeof(int*));
	for (int i = 0; i < (m + 2); i++) {
		traveled[i] = (int*)malloc((n + 2) * sizeof(int));
	}*/
	//memset(traveled, 0, sizeof(traveled));错误写法，初始化失败
	//memset(maze, '#', sizeof(maze));
	///MSDN中对memset函数的解释，它不能够简单的初始化一个二维数组https://docs.microsoft.com/zh-cn/cpp/c-runtime-library/reference/memset-wmemset?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev15.query%3FappId%3DDev15IDEF1%26l%3DZH-CN%26k%3Dk(memset);k(DevLang-C%2B%2B);k(TargetOS-Windows)%26rd%3Dtrue&view=vs-2017
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%c", &maze[i][j]);
			//找到起点的位置
			if (maze[i][j] == 'S') {
				pos_m = i;
				pos_n = j;
			}
		}//for:j
		getchar();//getchar吃掉回车符
	}//for:i
	/*for (int i = 0; i <= m+1; i++) {
		for (int j = 0; j <= n+1; j++) {
			printf("[%c]\t", maze[i][j]);
		}
		printf("\n");
	}*/
	if (DFS(pos_n, pos_m))
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
