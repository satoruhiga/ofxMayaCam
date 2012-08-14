#pragma once

#include "ofMain.h"

class ofxMayaCam : public ofCamera
{
public:
	
	ofxMayaCam();
	~ofxMayaCam();
	
	void setSensitivity(float v) { sensitivity = v; }
	void setUpVector(ofVec3f v) { upVector = v; }
	void setFocus(float v) { focus = v; }
	
	ofVec3f getEyePosition() { return pos; }
	void setEyePosition(ofVec3f v) { pos = v; updateTransform(); }
	
	ofQuaternion getRot() { return rot; }
	void setRot(ofQuaternion v) { rot = v; updateTransform(); }
	
	void reset();
	
	void mouseDragged(ofMouseEventArgs& mouse);
	void mouseMoved(ofMouseEventArgs& mouse);
	void mousePressed(ofMouseEventArgs& mouse);
	void mouseReleased(ofMouseEventArgs& mouse);
	
	void keyPressed(ofKeyEventArgs &key);
	void keyReleased(ofKeyEventArgs &key);
	
	void enableInput();
	void disableInput();
	bool getInputEnabled();

protected:

	bool inputEnabled;
	
	float sensitivity;
	
	float focus;
	ofVec3f upVector;
	ofVec3f pos;
	ofQuaternion rot;
	
	bool numkeys[3];
	
	bool getAltKeyState();
	bool getShiftKeyState();
	
	void updateTransform();
	
};
