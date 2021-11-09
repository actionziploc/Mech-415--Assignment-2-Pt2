// Assignment2_Pt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include <MMSystem.h>
#include "Audio.h"


int main()
{
    char file[] = ("beam_canonical.wav");
    Audio A(file);

    A.play();
    std::cout << "Channel Number: " << A.NumChannels << "\nSample Rate: " << A.SampleRate << "\n";


    system("pause");
    
}

