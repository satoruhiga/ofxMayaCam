#include "ofxMayaCam.h"

#ifdef TARGET_OSX

#include <Cocoa/Cocoa.h>

bool ofxMayaCam::getAltKeyState()
{
	return [[NSApp currentEvent] modifierFlags] & NSAlternateKeyMask;
}

bool ofxMayaCam::getShiftKeyState()
{
	return [[NSApp currentEvent] modifierFlags] & NSShiftKeyMask;
}

#endif