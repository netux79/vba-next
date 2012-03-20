#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

// For backwards compatibility with the original VBA defines

#ifdef __CELLOS_LV2__
extern uint32_t special_action_msg_expired;
extern char special_action_msg[256];
#endif

extern bool systemPauseOnFrame();
extern void systemScreenCapture(int);
extern void systemDrawScreen();
// updates the joystick data
extern bool systemReadJoypads();
extern uint32_t systemGetClock();
extern void systemMessage(int, const char *, ...);
extern void systemSetTitle(const char *);
extern void systemScreenMessage(const char *);
#ifdef USE_MOTION_SENSOR
extern void systemUpdateMotionSensor();
extern int  systemGetSensorX();
extern int  systemGetSensorY();
#endif
extern bool systemCanChangeSoundQuality();
extern void systemShowSpeed(int);
extern void systemFrame();

// sound functions
extern bool systemSoundInit();
extern bool systemSoundInitDriver(long samplerate);
extern void systemSoundPause();
extern void systemSoundResume();
extern void systemSoundReset();
extern void systemSoundSetThrottle(unsigned short throttle);
extern void systemSoundNonblock(bool enable);
extern void systemOnWriteDataToSoundBuffer(int16_t * finalWave, int length);
extern void systemOnSoundShutdown();

extern uint16_t systemColorMap16[0x10000];
extern uint32_t systemColorMap32[0x10000];

extern int systemRedShift;
extern int systemGreenShift;
extern int systemBlueShift;

extern int systemColorDepth;
extern int systemFrameSkip;
extern int systemSaveUpdateCounter;
extern int systemSpeed;

#define SYSTEM_SAVE_UPDATED 30
#define SYSTEM_SAVE_NOT_UPDATED 0

#include "VbaNext.h"

#endif // SYSTEM_H
