#pragma once

#include "ofMain.h"

class ofxMayaCam : public ofCamera
{
public:
	
	ofxMayaCam();
	~ofxMayaCam();
	
	void setSensitivity(float v) { sensitivity = v; }
	void setUpVector(ofVec3f v) { upVector = v; }
	
	void reset();
	
	void mouseDragged(ofMouseEventArgs& mouse);
	void mouseMoved(ofMouseEventArgs& mouse);
	void mousePressed(ofMouseEventArgs& mouse);
	void mouseReleased(ofMouseEventArgs& mouse);
	
	void enableMouseInput();
	void disableMouseInput();
	bool getMouseInputEnabled();

protected:

	bool bMouseInputEnabled;
	
	float sensitivity;
	
	ofVec3f upVector;
	ofVec3f eye, pos;
	ofQuaternion rot;
	
	bool getAltKeyState();
	bool getShiftKeyState();
	
	void updateTransform();
	
};
