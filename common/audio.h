#ifndef AUDIO_H
#define AUDIO_H

#include <AL/al.h>
#include <AL/alc.h>

class Audio
{
public:
	Audio();
	virtual ~Audio();

private:
	ALvoid* buffer;

};

#endif
