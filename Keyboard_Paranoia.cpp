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
        // Allows sound effect to play while pausing program.
        Sleep(5000);
    }
    if (track_number == 1)
    {
        play_track = "presses_8";
        PlaySound(TEXT("presses_8"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(500);
    }
    if (track_number == 2)
    {
        play_track = "mixkit-glitch-crackles-1044";
        PlaySound(TEXT("mixkit-glitch-crackles-1044"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(500);
    }
    std::cout << track_number << ") Playing Track: " << play_track << "\n";
}

#include <conio.h>
int main()
{
    //::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);

    double counter = 0;
    while (1)
    {
        std::cout << "[!] Ready" << "\n";
        // _getch(); waits for user input before continuing.
        _getch();
        if (GetKeyState('A') & 0x8000)
        {
            std::cout << "Alpha" << "\n";
            sound_effects(0);
        }
        if (GetKeyState('B') & 0x8000)
        {
            std::cout << "Beta" << "\n";
            sound_effects(1);
        }
        if (GetKeyState('Z') & 0x8000)
        {
            std::cout << "ZZZ" << "\n";
            sound_effects(2);
            Sleep(2000);
        }
    }
    return 0;
}
