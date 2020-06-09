#ifndef IAUDIO_COMMAND_H
#define IAUDIO_COMMAND_H

class IAudioCommand {
		virtual void pause() = 0;
		
        virtual void unpause() = 0;
		
        virtual void stopMusic() = 0;		
		
        virtual bool isPlaying() const = 0;
}
#endif