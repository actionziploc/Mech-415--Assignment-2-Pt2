#include "Audio.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

//constructor that opens and stores dynamic memory buffer from binary file
Audio::Audio(char* file_name)
{
	ifstream file = ifstream(file_name, ios::binary | ios::ate);			//open the binary file at the end
	streamsize N_buffer = file.tellg();										//define N_buffer to the size of the file (number of bytes)
	file.seekg(0, ios::beg);												//move to the beginning of the file

	p_buffer = new char[N_buffer];											//dynamic memory buffer of N_buffer bytes that stores the binary file
	p_data = new char[N_data];

	if (file.read(p_buffer, N_buffer))
	{

		NumChannels = bytes_read(22, 2);
		SampleRate = bytes_read(24, 4);
		N_data = bytes_read(40, 4);
		get_data();

	}
	else
	{
		cout << "\nUnable to read file " << file_name << "... try again chief.\n";
	}

}

//destructor
Audio::~Audio()
{
	delete p_buffer;
	cout << "\n Audio destructor.\n";
}

//function to get data for canonical wave from binary file to allocate in dynamic memory buffer
void Audio::get_data()
{
	int index = 0;

	for (int i = 44; i < 44 + N_data; i++)
	{
		p_data[index] = p_buffer[i];
	}
}

//function that read the number of bytes
int Audio::bytes_read(int index, int N_bytes)
{
	int value = 0;

	for (int i = index + N_bytes - 1; i >= index; i--)
	{
		value = (value << 8) + p_buffer[i];
	}
}

void Audio::play()
{
	PlaySoundA("beam.wav", NULL, SND_ASYNC);
	Sleep(3000);

	PlaySoundA("laser.wav", NULL, SND_ASYNC);
	Sleep(3000);

}