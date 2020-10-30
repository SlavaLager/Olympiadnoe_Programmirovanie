#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

bool maze[50][50][50];//z - y - x

struct Pos { int x, y, z, turn; };

queue<Pos>poses;//x - y - z - turn
char Px, Py;
int M, N, H;

void go(int x, int y, int z, int step) {
	if (x < 0 || y < 0 || x >= N || y >= M || z >= H)return;
	bool res = maze[z][y][x];
	if (!res) {
		maze[z][y][x] = true;
		poses.push({ x,y,z,step });
	}
}

int main() {
	ifstream input;
	input.open("input.txt");
	input >> H >> M >> N;
	for (int h = 0; h < H; h++) {
		char c;
		for (int y = 0; y < M; y++) {
			
			for (int x = 0; x < N; x++) {
				input >> c;
				switch (c) {
				case'1':poses.push({x, y, h, 0}); maze[h][y][x] = false; break;
				case'2':Px = x; Py = y; maze[h][y][x] = false; break;
				case'o':maze[h][y][x] = true; break;
				case'.':maze[h][y][x] = false; break;
				}
				cout << c;
			}
			//input >> c;
			cout << endl;
		}
		//input >> c;
		cout << endl;
	}
	while (true) {
		int x = poses.front().x,y = poses.front().y,z = poses.front().z, turn = poses.front().turn;
		poses.pop();
		if (z == (H - 1) && x == Px && y == Py) {
			ofstream output;
			output.open("output.txt");
			output << turn * 5 << endl;
			output.close();
			return 0;
		}
		turn++;
		go(x + 1, y, z, turn);
		go(x - 1, y, z, turn);
		go(x, y + 1, z, turn);
		go(x, y - 1, z, turn);
		go(x, y, z + 1, turn);
	}
}