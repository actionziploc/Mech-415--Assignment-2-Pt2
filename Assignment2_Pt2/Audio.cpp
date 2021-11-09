#include "Audio.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

Audio::Audio(char* file_name)
{
	ifstream file = ifstream(file_name, ios::binary | ios::ate);			//open the binary file at the end
	streamsize N_buffer = file.tellg();										//define N_buffer to the size of the file (number of bytes)
	file.seekg(0, ios::beg);												//move to the beginning of the file

	p_buffer = new char[N_buffer];											//dynamic memory buffer of N_buffer bytes that stores the binary file


	int index = 0;
	int value = 0;

	if (file.read(p_buffer, N_buffer))
	{

		NumChannels = get_read_data(22, 2);
		SampleRate = get_read_data(24, 4);
		N_data = readBytes(40, 4);

		for (int i = 44; i < 44 + N_data; i++)
		{
			p_data[0] = p_buffer[i];
		}

	}
	else
	{
		cout << "\nUnable to read file " << file_name << "... try again chief.\n";
	}


	delete[] buffer;
}

int Bytes_read(int index, int N_bytes)
{
	
}

void get_read_data()
{
	int index = 0;
	int value = 0;
	D.p_data = new char[D.N_data];


	for (int i = index + N_bytes - 1; i >= index; i--)
	{
		value = (value << 8) + D.p_buffer[i];
	}

	for (int i = 44; i < 44 + D.N_data; i++)
	{
		D.p_data[index] = D.p_buffer[i];
	}

}