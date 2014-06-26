#include "includes.h"

extern void mainloop();

using namespace std;

char levelmap[LEVELHEIGHT][LEVELWIDTH + 1] =
{
"1555555555555555555555555552",
"6............^^............6",
"6.!%%@.!%%%@.^^.!%%%@.!%%@.6",
"67^  ^.^   ^.^^.^   ^.^  ^86",
"6.#%%$.#%%%$.#$.#%%%$.#%%$.6",
"6..........................6",
"6.!%%@.!@.!%%%%%%@.!@.!%%@.6",
"6.#%%$.^^.#%%@!%%$.^^.#%%$.6",
"6......^^....^^....^^......6",
"355552.^#%%@ ^^ !%%$^.155554",
"     6.^!%%$ #$ #%%@^.6     ",
"     6.^^    B     ^^.6     ",
"     6.^^ 155&&552 ^^.6     ",
"555554.#$ 6      6 #$.355555",
"      .   6I   C 6   .      ",
"555552.!@ 6  P   6 !@.155555",
"     6.^^ 35555554 ^^.6     ",
"     6.^^          ^^.6     ",
"     6.^^ !%%%%%%@ ^^.6     ",
"155554.#$ #%%@!%%$ #$.355552",
"6............^^............6",
"6.!%%@.!%%%@.^^.!%%%@.!%%@.6",
"6.#%@^.#%%%$.#$.#%%%$.^!%$.6",
"69..^^.......X .......^^..06",
"6%@.^^.!@.!%%%%%%@.!@.^^.!%6",
"6%$.#$.^^.#%%@!%%$.^^.#$.#%6",
"6......^^....^^....^^......6",
"6.!%%%%$#%%@.^^.!%%$#%%%%@.6",
"6.#%%%%%%%%$.#$.#%%%%%%%%$.6",
"6..........................6",
"3555555555555555555555555554"
};

void loadlevel()
{
    char curcharacter;
    SetTextColor(WHITE);
    SetCursorPosition(-3, 3);
    cout << "1UP";
    SetCursorPosition(-3, 9);
    cout << "HIGH SCORE";
    player.scoreinc = 0;
    player.printscore();
    SetCursorPosition(0, 0);
    player.left = 0;
    for(int y = 0; y < LEVELHEIGHT; y++)
    {
        for(int x = 0; x < LEVELWIDTH; x++)
        {
            curcharacter = levelmap[y][x];
            SetTextColor(DARKBLUE);
            switch(curcharacter)
            {
            case 'X':
            {
                player.yinit = y;
                player.xinit = x;
                level[y][x] = ' ';
                break;
            }
            case 'B':
            {
                ghosts[BLINKY].yinit = y;
				ghosts[BLINKY].xinit = x;
				ghosts[BLINKY].colorinit = RED;
				ghosts[BLINKY].diropp = 's';
                level[y][x] = ' ';
                break;
            }
            case 'P':
            {
                ghosts[INKY].yinit = y;
                ghosts[INKY].xinit = x;
                ghosts[INKY].colorinit = MAGENTA;
                level[y][x] = ' ';
                break;
            }
            case 'I':
            {
                ghosts[PINKY].yinit = y;
				ghosts[PINKY].xinit = x;
				ghosts[PINKY].colorinit = CYAN;
                level[y][x] = ' ';
                break;
            }
            case 'C':
            {
                ghosts[CLYDE].yinit = y;
				ghosts[CLYDE].xinit = x;
				ghosts[CLYDE].colorinit = YELLOW;
                level[y][x] = ' ';
                break;
            }
            case '7':
            {
                pellets[0].y = y;
                pellets[0].x = x;
                SetTextColor(WHITE);
                level[y][x] = 'o';
                player.left++;
                break;
            }
            case '8':
            {
                pellets[1].y = y;
                pellets[1].x = x;
                SetTextColor(WHITE);
                level[y][x] = 'o';
                player.left++;
                break;
            }
            case '9':
            {
                pellets[2].y = y;
                pellets[2].x = x;
                SetTextColor(WHITE);
                level[y][x] = 'o';
                player.left++;
                break;
            }
            case '0':
            {
                pellets[3].y = y;
                pellets[3].x = x;
                SetTextColor(WHITE);
                level[y][x] = 'o';
                player.left++;
                break;
            }
            case '.':
            {
                SetTextColor(WHITE);
                level[y][x] = char(250);
                player.left++;
                break;
            }
            case ' ':
            {
                level[y][x] = curcharacter;
                break;
            }
            case '&':
            {
                SetTextColor(WHITE);
                curcharacter = '%';
            }
            }
            if(curcharacter == '1')
                level[y][x] = char(201);
            else if(curcharacter == '2')
                level[y][x] = char(187);
            else if(curcharacter == '3')
                level[y][x] = char(200);
            else if(curcharacter == '4')
                level[y][x] = char(188);
            else if(curcharacter == '5')
                level[y][x] = char(205);
            else if(curcharacter == '6')
                level[y][x] = char(186);
            else if(curcharacter == '!')
                level[y][x] = char(218);
            else if(curcharacter == '@')
                level[y][x] = char(191);
            else if(curcharacter == '#')
                level[y][x] = char(192);
            else if(curcharacter == '$')
                level[y][x] = char(217);
            else if(curcharacter == '%')
                level[y][x] = char(196);
            else if(curcharacter == '^')
                level[y][x] = char(179);
            cout << level[y][x];
        }
        SetCursorPosition(y + 1, 0);
    }
    initall();
    showall();
    player.printlives();
    printready();
}

void nextlevel()
{
    Sleep(1000);
    hideall();
    SetCursorPosition(12, 13);
    cout << "  ";
    for(int i = 0; i < 4; i++)
    {
        SetScreenColor(WHITE);
        player.show();
        Sleep(200);
        SetScreenColor(DARKBLUE);
        player.show();
        Sleep(200);
    }
    SetCursorPosition(0, 0);
    initall();
}

void printready()
{
    SetTextColor(YELLOW);
    SetCursorPosition(17, 11);
    cout << "READY!";
    Sleep(2000);
    SetCursorPosition(17, 11);
    cout << "      ";
}

void gameover()
{
    SetCursorPosition(17, 9);
    SetTextColor(RED);
    cout << "GAME  OVER";
    Sleep(1000);
    mainloop();
}
