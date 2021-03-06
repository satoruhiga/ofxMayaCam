#pragma once

#include "ofMain.h"

class ofxMayaCam : public ofCamera
{
public:
	
	ofxMayaCam();
	~ofxMayaCam();
	
	void setSensitivity(float v) { sensitivity = v; }
	float getSensitivity() { return sensitivity; }
	
	void setUpVector(ofVec3f v) { upVector = v; }
	ofVec3f getUpVector() { return upVector; }
	
	void setFocus(float v) { focus = v; }
	float getFocus() { return focus; }
	
	void setEyePosition(ofVec3f v) { pos = v; updateTransform(); }
	ofVec3f getEyePosition() { return pos; }
	
	void setRot(ofQuaternion v) { rot = v; updateTransform(); }
	ofQuaternion getRot() { return rot; }
	
	void reset();
	
	void mouseDragged(ofMouseEventArgs& mouse);
	void mouseMoved(ofMouseEventArgs& mouse);
	void mousePressed(ofMouseEventArgs& mouse);
	void mouseReleased(ofMouseEventArgs& mouse);
	
	void keyPressed(ofKeyEventArgs &key);
	void keyReleased(ofKeyEventArgs &key);
	
	void enableAllInput();
	void disableAllInput();
	
	void enableMouseInput();
	void disableMouseInput();
	bool getMouseInputEnabled();
	
	// default = off
	void enableKeyInput();
	void disableKeyInput();
	bool getKeyInputEnabled();

protected:

	bool mouseInputEnabled;
	bool keyInputEnabled;
	
	float sensitivity;
	
	float focus;
	ofVec3f upVector;
	ofVec3f pos;
	ofQuaternion rot;
	
	ofVec2f last_mouse_pos;
	
	bool numkeys[3];
	
	bool getAltKeyState();
	bool getShiftKeyState();
	
	void updateTransform();
	
	void customDraw();
	
};
