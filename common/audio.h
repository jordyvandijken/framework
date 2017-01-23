#ifndef AUDIO_H
#define AUDIO_H

#include <AL/al.h>
#include <AL/alc.h>

#include <iostream>

class Audio
{
public:
	Audio();
	virtual ~Audio();
	static void init();

  static void closeAudio();
protected:
		static ALCdevice *device;
		static ALCcontext *context;

};

#endif
