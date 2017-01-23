#ifndef SOUND_H
#define SOUND_H

#include <AL/al.h>
#include <string>
#include <iostream>
#include "wav.h"

class Sound {
    public:
        Sound();
        Sound(std::string filename, bool l = false, float p = 1.0f);
    	virtual ~Sound();

        enum State {STATE_PLAYING, STATE_STOPPED, STATE_PAUSED};

        bool load(std::string filename);
        void play();
        void pause();
        void stop();
        void rewind();
        State state();

        void pitch(float p);
        void gain(float g);
        void loop(bool l);
        void position(float x, float y, float z);
        void velocity(float x, float y, float z);

    protected:
    	void init(bool l = false, float p = 1.0f);

        ALuint _buffer;
    	ALuint _source;
};

#endif /* SOUND_H_ */
