#include "Sound.h"

void Sound::Load()
{

}

void Sound::Play(bool loop)
{
	if (loop)
	{
		// �ѹ� ���
		PlaySound(TEXT("..\\Sound\\SokoSong.wav"), 0, SND_FILENAME | SND_ASYNC);
	}
	else
	{
		// �������
		PlaySound(TEXT("..\\Sound\\SokoSong.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
}
