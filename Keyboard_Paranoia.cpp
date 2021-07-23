// Keyboard_Paranoia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Windows.h>
#include <vector>

std::vector<char> alphabet = 
      { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 
        'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
        'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 
        'X', 'Y', 'Z' };

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

    std::cout << alphabet[rand() % (alphabet.size())] << "\n";

    double counter = 0;
    while (1)
    {
        char char_of_the_day = alphabet[rand() % (alphabet.size())];
        std::cout << char_of_the_day << "\n";
        //Sleep(500);
        std::cout << "[!] Ready" << "\n";
        // TODO: Waiting for user input while out of focus.
        // https://stackoverflow.com/questions/18001317/receiving-keypresses-while-in-background
        // _getch(); waits for user input before continuing.
        //_getch();
        std::cout << "Current Key State: " << GetKeyState << "\n";
        /*
        while ((GetKeyState('Q') & 0x8000) == false)
        {
            // https://stackoverflow.com/questions/15737495/c-execute-a-while-loop-until-a-key-is-pressed-e-g-esc
            // https://stackoverflow.com/questions/18001317/receiving-keypresses-while-in-background
            std::cout << "LOOP HERE" << "\n";
            // std::string test = "";
            // std::cin >> test;
            _getch();
            std::cout << "Current Key State: " << GetKeyState << "\n";
        }
        */
        if (GetKeyState(char_of_the_day) & 0x8000)
        {
            std::cout << "Char of the day pressed" << "\n";
        }
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
        // https://stackoverflow.com/questions/5607849/how-to-simulate-a-key-press-in-c
        if (GetKeyState('C') & 0x8000)
        {
            std::cout << "Charlie" << "\n";
            INPUT inputs[2] = {};
            ZeroMemory(inputs, sizeof(inputs));
            inputs[0].type = INPUT_KEYBOARD;
            inputs[0].ki.wVk = VK_CAPITAL;

            inputs[1].type = INPUT_KEYBOARD;
            inputs[1].ki.wVk = VK_CAPITAL;
            inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

            UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
            if (uSent != ARRAYSIZE(inputs))
            {
                std::cout << "SendInput failed: 0x%x\n", HRESULT_FROM_WIN32(GetLastError());
            }
            Sleep(1000);
        }
        if (GetKeyState('D') & 0x8000)
        {
            std::cout << "Delta" << "\n";
            INPUT inputs[2] = {};
            ZeroMemory(inputs, sizeof(inputs));
            inputs[0].type = INPUT_KEYBOARD;
            inputs[0].ki.wVk = 0x46;

            inputs[1].type = INPUT_KEYBOARD;
            inputs[1].ki.wVk = 0x46;
            inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

            UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
            if (uSent != ARRAYSIZE(inputs))
            {
                std::cout << "SendInput failed: 0x%x\n", HRESULT_FROM_WIN32(GetLastError());
            }
            Sleep(150);
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
