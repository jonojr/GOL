#include <iostream>
#include <windows.h> 
#include <string>
#include <fstream>

using namespace std;

const int x = 20; const int y = 40;
const int sleep = 45;
int map1[x][y];  int map2[x][y];
void display();
void tick();
void reset();
void load();

int main() {
	for (size_t xpos = 0; xpos < x; xpos++)
	{
		for (size_t i = 0; i < y; i++)
		{
			map1[xpos][i] = 0;
			map2[xpos][i] = 0;
		}
	}
	load();
	while (true)
	{
		display();
		tick();
		Sleep(sleep);
	}
	return 0;
}
void load(){
	string temp,filename;
	cout << "Please enter the file you wish to load:";
	cin >> filename;
	ifstream file(filename);
	for (size_t xpos = 0; xpos < x; xpos++)
	{
		getline(file, temp);
		for (size_t i = 0; i < y; i++)
		{
			map1[xpos][i] = temp[i] - '0';
		}
	}
	

}
int check(int x, int y) {
	int numAdj = 0;
	numAdj = map1[x - 1][y - 1] + map1[x - 1][y] + map1[x - 1][y + 1] + map1[x][y - 1] + map1[x][y + 1] + map1[x + 1][y - 1] + map1[x + 1][y] + map1[x + 1][y + 1];
	if (numAdj == 2)
	{
		return map1[x][y];
	}
	else if (numAdj == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void tick() {
	for (size_t xpos = 0; xpos < x; xpos++)
	{
		for (size_t i = 0; i < y; i++)
		{
			map2[xpos][i] = check(xpos,i);
		}
	}
	reset();
}
void reset() {
	for (size_t xpos = 0; xpos < x; xpos++)
	{
		for (size_t i = 0; i < y; i++)
		{
			map1[xpos][i] = map2[xpos][i];
			map2[xpos][i] = 0;
		}
	}
}
void display() {
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t xpos = 0; xpos < x; xpos++)
	{
		for (size_t i = 0; i < y; i++)
		{
			if (map1[xpos][i] == 0)
			{
				SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_INTENSITY);
			}
			else {
				SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY);
			}
			cout << map1[xpos][i];
		}
		cout<<endl;
	}
}