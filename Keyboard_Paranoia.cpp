// Keyboard_Paranoia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Windows.h>

#pragma comment(lib, "Winmm.lib")
//#include <mmsystem.h>
void sound_effects(int track_number)
{
    std::string play_track = "";
    if (track_number == 0)
    {
        play_track = "knocking.wav";
        PlaySound(TEXT("knocking.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    std::cout << track_number << ") Playing Track: " << play_track << "\n";
}

void HideConsole()
{
    //::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

#include <conio.h>
int main()
{
    HideConsole();

    bool flag = false;
    double counter = 0;
    while (1)
    {
        //_getch();
        if (GetKeyState('A') & 0x8000 && flag == false)
        {
            std::cout << "Alpha" << "\n";
            sound_effects(0);
            // Allows sound effect to play while pausing program.
            Sleep(5000);
            std::cout << "End Sleep" << "\n";
            //flag = true;
        }
        if (GetKeyState('B') & 0x8000 && flag == false)
        {
            std::cout << "Beta" << "\n";
            //flag = true;
        }
        if (GetKeyState('Z') & 0x8000 && flag == false)
        {
            std::cout << "ZZZ" << "\n";
            //flag = true;
        }
    }
    return 0;
}
