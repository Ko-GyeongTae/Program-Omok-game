#include <stdio.h>
//#include <Windows.h>

int Board[19][19] = { 0 };
int cnt = 0, game = 0;

void input();
void X_Check(int _y, int _x, int stone); //가로
void Y_Check(int _y, int _x, int stone); //세로
void RXY_Check(int _y, int _x, int stone); //y = -x 대각선
void LXY_Check(int _y, int _x, int stone); //y = x 대각선
void GameWin(int stone);
void output();

int main() {
	while (1) {
		input();
		output();
		if (game == 1)
			break;
	}
	return 0;
}

void input() {
	int x, y;
	if ((cnt % 2) + 1 == 1)
		printf("흑의 차례입니다.. ");
	else
		printf("백의 차례입니다.");
	scanf("%d %d", &x, &y);
	if (x < 0 || x > 19 || y < 0 || y >19)
		printf("돌을 던지지 마세오...\n");
	if (Board[y][x] != 0) {
		printf("이미 돌이 놓여있습니다.\n");
		input();
	}
	else {
		Board[y][x] = (cnt % 2) + 1; //홀수일때 흑 짝수일때 백 
		cnt++;

		X_Check(y, x, Board[y][x]); //가로
		Y_Check(y, x, Board[y][x]); //세로
		RXY_Check(y, x, Board[y][x]); //y = -x 대각선
		LXY_Check(y, x, Board[y][x]); //y = x 대각선
	}
}

void X_Check(int _y, int _x, int stone) {
	int x, y, count;
	x = _x, y = _y;
	count = 0;

	if (Board[_y][x - 1] == stone) {
		while (Board[_y][x - 1] == stone && x >= 0) //x값만 감소 stone과 같은동안
			x--;
		while (Board[_y][x++] == stone && x < 19) //x값만 증가 stone과 같을동안
			count++;
	}
	else {
		while (Board[_y][x + 1] == stone && x < 19)
			x++;
		while (Board[_y][x--] == stone && x >= 0)
			count++;
	}

	if (count == 5)
		GameWin(stone);
}

void Y_Check(int _y, int _x, int stone) {
	int x, y, count;
	x = _x, y = _y;
	count = 0;

	if (Board[y - 1][_x] == stone && y >= 0) {
		while (Board[y - 1][_x] == stone && y >= 0) //y값만 감소 stone과 같을동안
			y--;
		while (Board[y++][_x] == stone && y < 19) //y값만 증가 stone과 같을 동안
			count++;
	}
	else {
		while (Board[y + 1][_x] == stone && y < 19)
			y++;
		while (Board[y--][_x] == stone && y >= 0)
			count++;
	}

	if (count == 5)
		GameWin(stone);
}

void RXY_Check(int _y, int _x, int stone) {
	int x, y, count;
	x = _x, y = _y;
	count = 0;

	if (Board[y - 1][x - 1] == stone && x >= 0 && y >= 0) {
		while (Board[y - 1][x - 1] == stone && x >= 0 && y >= 0) //x, y값 감소,stone과 같을 동안 
			x--, y--;
		while (Board[y++][x++] == stone && x < 19 && y < 19) //x, y값 증가 stone과 같을 동안
			count++;
	}
	else {
		while (Board[y + 1][x + 1] == stone && x < 19 && x < 19)
			x++, y++;
		while (Board[y--][x--] == stone && x >= 0 && y >= 0)
			count++;
	}

	if (count == 5)
		GameWin(stone);
}

void LXY_Check(int _y, int _x, int stone) {
	int x, y, count;
	x = _x, y = _y;
	count = 0;

	if (Board[y - 1][x + 1] == stone && x < 19 && y >= 0) {
		while (Board[y - 1][x + 1] == stone && x < 19 && y >= 0) //x값 증가, y값 감소, stone과 같을 동안
			x++, y--;
		while (Board[y++][x--] == stone && x >= 0 && y < 19) //x값 감소, y값 증가, stone과 같을 동안
			count++;
	}
	else {
		while (Board[y + 1][x - 1] == stone && x < 19 && y >= 0)
			x--, y++;
		while (Board[y--][x++] == stone && x >= 0 && x < 19)
			count++;
	}

	if (count == 5)
		GameWin(stone);
}

void GameWin(int stone) {
	//system("cls");
	if (stone == 1) {
		printf("흑의 승리입니다.\n");
		game = 1;
	}
	else {
		printf("백의 승리입니다.\n");
		game = 1;
	}
}

void output() {
	int i, j;
	printf("** 0 1 2 3 4 5 6 7 8 9101112131415161718\n");
	for (i = 0; i < 19; i++) {
		printf("%2d ", i);
		for (j = 0; j < 19; j++)
			printf("%d ", Board[i][j]);
		printf("\n");
	}
}