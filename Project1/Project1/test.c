#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_row 3
#define Max_col 3
char chess_board[Max_row][Max_col];
int menu(){
	printf("---------------\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("---------------\n");
	printf("请输入您的选择");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Init(){
	//棋盘用X表示玩家落子，o表示电脑落子
	// ''表示未落子
	for (int row = 0; row < Max_row; ++row){
		for (int col = 0; col < Max_col; ++col){
			chess_board[row][col] = ' ';
		}
	}
}
void Print(){
	for (int row = 0; row < Max_row; ++row){
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		if (row != Max_row - 1){
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove(){
	printf("玩家落子\n");
	while (1){
		printf("请输入一组坐标(row clo):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row > Max_row || row < 0 || col > Max_col || col < 0){
			printf("您的输入非法！\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("您输入的坐标已经被占用！\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
void ComputerMove(){
	while (1){
		int row = rand() % Max_row;
		int col = rand() % Max_col;
		if (chess_board[row][col] != ' '){
			//这个位置被占用
			//重新随机一次
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
//检查棋盘是否满了
int IsFull(){
	for (int row = 0; row < Max_row; ++row){
		for (int col = 0; col <Max_col; ++col){
			if (chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	//只要找到一个位置为' '就认为没满
	//必须得把所有的位置都找完也没发现空格，此时才是满了
	return 1;
}
//返回x表述玩家胜
//返回o表示电脑胜
//返回q表示和棋
//返回' ' 表述未分出胜负，也不是和棋，继续进行游戏
char CheckGameOver(){
	//检查所有行是否构成三子棋
	for (int row = 0; row< Max_row; ++row){
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//检查所有列是否构成三子棋
	for (int col = 0; col< Max_col; ++col){
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//检查对角线是否构成三子棋
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	if (IsFull()){
	}
	return 'q';
}
void Game(){
	//创建并初始化一个棋盘
	Init();
	char winner = ' ';
	while (1){
		system("cls");
		//打印棋盘
		Print();
		//玩家落子
		PlayerMove();
		//检测游戏结束
		winner = CheckGameOver();
		if (winner != ' '){
			//分出胜负或者和棋
			break;
		}
		//电脑落子
		ComputerMove();
		//检测游戏结束
		winner = CheckGameOver();
		if (winner != ' '){
			break;
		}
	}
	system("cls");
	if (winner == 'x'){
		printf("玩家胜利！\n");
	}
	else if (winner == 'o'){
		printf("你真菜电脑都下不过\n");
	}
	else if (winner == 'q'){
		printf("你还是真菜，和电脑五五开！\n");
	}
	else{
		printf("好像出错了！\n");
	}
}
int main()
{
	while (1){
		int choice = menu();
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("goodbye\n");
			break;
		}
		else {
			printf("您的输入有误\n");
		}
	}
	system("pause");
	return 0;
}