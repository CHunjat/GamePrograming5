/*
* 게임에서 위치를 표현하는 방법(2D)
* map 2차원 배열
* 미로 찾기? AI 존재 탈출구 까지 이동하는 코드를 작성해보세요
*/

#include <iostream>
#include <vector>
#include <Windows.h>

#define SIZE 10
         //Y   //X         //0은 이동, 1은 벽 // 입구를 (X,Y) = 1,0) 출구는 (X,Y) = 9,5
int maze[SIZE][SIZE] =
{
    {1,0,1,1,1,1,1,1,1,1,},
    {1,0,1,1,1,0,0,0,0,1,},
    {1,0,1,0,1,0,1,0,0,1,},
    {1,0,0,0,0,0,1,0,0,0,},
    {1,0,1,0,1,0,0,0,0,1,},
    {1,0,1,0,1,0,1,1,0,1,},
    {1,0,1,0,1,0,1,1,1,1,},
    {1,0,1,1,1,0,1,1,0,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,1,1,1,1,1,1,1,1,1,}
};

// 방향 (상,하,좌,우)
// 상 : x 의변화 0 y의 변화 ? -1
// 하 : x의 변화 0 y :1
// 좌 : x -2 y 0

const int dx[4] = { 0,0,-2,2 };
const int dy[4] = { -1,1,0,0 };

struct Monster
{
    int x, y;
    int prev_x, prev_y;
    int step;
    std::vector<int> direction;
    Monster() = default;
    Monster(int x, int y, std::vector<int> direction) :x(x), y(y), direction(direction) 
    {
        prev_x = x;
        prev_y = y;
        step = 0;
    }
};

void GoToXY(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// maze[y][x] 의 값이 0이면 '  ' 
int main()
{
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            if (maze[y][x] == 0)
            {
                std::cout << "  ";
            }
            else if (maze[y][x] == 1)
            {
                std::cout << "★";
            }
        }
        std::cout << std::endl;
    }


#pragma region 이동할 길을 미리 만들어 둔다

    //std::vector<int> direction = { 1,1,1,3,3,3,3,1,3,3,3,0,3,3};
    //int sx = 2;
    //int sy = 0;
    //GoToXY(sx, sy);
    //std::cout << "□";

    //// direction 숫자를 받아와서 Gotoxy를 변경해보세요

    //int pre_x = sx;
    //int pre_y = sy;

    //for (int i = 0; i < direction.size(); i++)
    //{
    //    // 잔상이 남는 현상을 해결해보세여
    //    //pre_x, pre_y;  "  " 
    //    //std::cout<<"  ";

    //  GoToXY(pre_x, pre_y);
    //    std::cout << "  "; 

    //    int dir = direction[i];
    //    sx += dx[dir];
    //    sy += dy[dir];
    //    pre_x = sx;
    //    pre_y = sy;
    //    GoToXY(sx, sy);
    //    std::cout << "□";
    //        Sleep(200);
    //}
#pragma endregion 

#pragma region 길일 따라 이동하는 몬스터
    std::vector<int>path = { 1,1,1,3,3,3,3,1,3,3,3,0,3,3 };
    int monster_count = 5;
    int interval = 2;
    int steps = path.size() + monster_count + interval; // 전체몬스터의 이동 거리
    int sx = 2;int sy = 0;

    std::vector<Monster> monsters;

    for (int i = 0; i < steps; i++)
    {
        if (i % interval == 0 && monsters.size() < monster_count);
        {
            monsters.emplace_back(sx, sy, path);
        }

        for (int i = 0; i < monsters.size(); i++)
        {
            Monster& monster = monsters[i];

            if (monster.step >= monster.direction.size()) continue;
            GoToXY(monster.prev_x, monster.prev_y);
            std::cout << "  ";

            int dir = monster.direction[monster.step];
            monster.x += dx[dir];
            monster.y += dy[dir];
            monster.prev_x = monster.x;
            monster.prev_y = monster.y;
            monster.step;

            GoToXY(monster.x, monster.y);


            std::cout << "□";
            Sleep(500);
        }

    }



#pragma endregion
    //2. 여러가지 몬스터가 각자의 방향으로 움직이는 코드를 작성해보세요

    //3. 맵에 따라서 도착지점을 자동으로 찾아주는 코드 작성 (길찾기 문제 dfs,
}