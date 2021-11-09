
#ifndef Audio
#define Audio_h

#include <iostream>
#include <cstdlib>
#include <cstring>

class Audio		//class declaration
{
public:

	char* p_buffer = nullptr;						//dynamic memory buffer of N_buffer bytes that stores the binary file
	char* p_data = nullptr;							//pointer to the audio data in p_buffer
	int N_buffer;									//number of bytes for the memory buffer
	int N_data;										//number of bytes for the audio data
	int SampleRate;									//number of samples per second for the audio data(Hz), 4 byte int
	short int NumChannels;							//number of audio channels (1- mono, 2- stereo), 2 byte int

	Audio(char* file_name);							//constructor that initializes all member variables using a wave file
	void play();									//use the windows PlaySoundA function to play the wave file in p_buffer
			
	~Audio();										//destructor

private:

	int bytes_read(int index, int N_bytes);
	void get_data();
	
};

#endif // !Audio 

