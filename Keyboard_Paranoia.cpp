// Keyboard_Paranoia.cpp : This file contains the 'main' function. Program execution begins and ends there.

/* === Minimum Functions ===
*  [+] Have different states/modes.  
*  [+] Program progressively changes to different modes/states over a period of time.
*  [-] Remove fixed keys and randomly assign different keys to different effects.
*  [-] Wait for user input before proceeding inside the while loop.
*  
*   
*/
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

void key_press(char key_press_char)
{
    if (key_press_char == 'C')
    {
        std::cout << "[!] Activate Caps Lock" << "\n";
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
    else if (key_press_char == 'D')
    {
        std::cout << "[!] Press F" << "\n";
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
    else if (key_press_char == 'E')
    {
        std::cout << "[!] Type hello" << "\n";
        INPUT inputs[10] = {};
        ZeroMemory(inputs, sizeof(inputs));

        std::vector<int> keys = {0x48, 0x45, 0x4C, 0x4C, 0x4F};

        int j = 0;
        for (int i = 0; i < 10; i++)
        {
            //inputs[i].type = INPUT_KEYBOARD;
            //inputs[i].ki.wVk = keys[j];
            std::cout << i << "\n";
            i++;
            std::cout << i << "\n";
            //inputs[i].type = INPUT_KEYBOARD;
            //inputs[i].ki.wVk = keys[j];
            //inputs[i].ki.dwFlags = KEYEVENTF_KEYUP;
            std::cout << "End here" << "\n";
            j++;
        }

        Sleep(10);

        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = 0x48;

        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 0x48;
        inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

        inputs[2].type = INPUT_KEYBOARD;
        inputs[2].ki.wVk = 0x45;

        inputs[3].type = INPUT_KEYBOARD;
        inputs[3].ki.wVk = 0x45;
        inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

        inputs[4].type = INPUT_KEYBOARD;
        inputs[4].ki.wVk = 0x4C;

        inputs[5].type = INPUT_KEYBOARD;
        inputs[5].ki.wVk = 0x4C;
        inputs[5].ki.dwFlags = KEYEVENTF_KEYUP;

        inputs[6].type = INPUT_KEYBOARD;
        inputs[6].ki.wVk = 0x4C;

        inputs[7].type = INPUT_KEYBOARD;
        inputs[7].ki.wVk = 0x4C;
        inputs[7].ki.dwFlags = KEYEVENTF_KEYUP;

        inputs[8].type = INPUT_KEYBOARD;
        inputs[8].ki.wVk = 0x4F;

        inputs[9].type = INPUT_KEYBOARD;
        inputs[9].ki.wVk = 0x4F;
        inputs[9].ki.dwFlags = KEYEVENTF_KEYUP;

        UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
        if (uSent != ARRAYSIZE(inputs))
        {
            std::cout << "SendInput failed: 0x%x\n", HRESULT_FROM_WIN32(GetLastError());
        }
        Sleep(150);
    }
}

#include <conio.h>
int main()
{
    // Use to hide console window.
    //::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);

    // std::cout << alphabet[rand() % (alphabet.size())] << "\n";
    int key_press_cout = 0;
    int aggression_mode = 0;
    while (1)
    {
        // Sleep used to decrease CPU usage in an infinite while loop.
        Sleep(10);
        std::cout << key_press_cout << "\n";
        /*
        https://stackoverflow.com/questions/18001317/receiving-keypresses-while-in-background
        _getch(); waits for user input before continuing. Reads from Standard streams.
        std::cout << "Current Key State: " << GetKeyState << "\n";
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
        // TODO: If statement to detect any key press here. (Wait condition). Waiting for user input while out of focus.
        for (int key = 8; key <= 190; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                char char_of_the_day = alphabet[rand() % (alphabet.size())];
                std::cout << char_of_the_day << "\n";
                key_press_cout++;
                if (key_press_cout == 25)
                {
                    aggression_mode = 1;
                }
                else if (key_press_cout == 50)
                {
                    aggression_mode = 2;
                }
                if (aggression_mode == 0)
                {
                    if (GetKeyState(char_of_the_day) & 0x8000)
                    {
                        std::cout << "Char of the day pressed" << "\n";
                    }
                    else if (GetKeyState('A') & 0x8000)
                    {
                        std::cout << "Alpha" << "\n";
                        sound_effects(2);
                    }
                    // https://stackoverflow.com/questions/5607849/how-to-simulate-a-key-press-in-c
                    else if (GetKeyState('C') & 0x8000)
                    {
                        // Activate Caps Lock
                        key_press('C');
                    }
                    else if (GetKeyState('D') & 0x8000)
                    {
                        // Press F
                        key_press('D');
                    }
                    else if (GetKeyState('E') & 0x8000)
                    {
                        // Type "Hello"
                        key_press('E');
                    }
                }
                else if (aggression_mode == 1)
                {
                    if (GetKeyState('B') & 0x8000)
                    {
                        std::cout << "Beta" << "\n";
                        sound_effects(1);
                    }
                }
                else if (aggression_mode == 2)
                {
                    if (GetKeyState('Z') & 0x8000)
                    {
                        sound_effects(0);
                    }
                }
            }
        }
    }
    return 0;
}
