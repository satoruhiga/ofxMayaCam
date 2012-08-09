#include "ofxMayaCam.h"

ofxMayaCam::ofxMayaCam()
{
	bMouseInputEnabled = false;
	sensitivity = 0.8;
	upVector.set(0, 1, 0);
	
	try {
		enableMouseInput();
	} catch (...) {}
	
	reset();
}

ofxMayaCam::~ofxMayaCam()
{
}

void ofxMayaCam::reset()
{
	eye.set(0, 0, 0);
	pos.set(0, 0, 200);
	rot.set(0, 0, 0, 1);
	
	updateTransform();
}

void ofxMayaCam::updateTransform()
{
	ofMatrix4x4 m;
	m.preMultTranslate(eye);
	m.preMultRotate(rot);
	m.preMultTranslate(-eye);
	
	m.preMultTranslate(pos);
	
	setTransformMatrix(m);
}

void ofxMayaCam::mouseDragged(ofMouseEventArgs& mouse)
{
	if (!getAltKeyState()) return;
	
	ofVec2f last(ofGetPreviousMouseX(), ofGetPreviousMouseY());
	ofVec2f current(ofGetMouseX(), ofGetMouseY());
	ofVec2f d = current - last;
	
	bool updated = false;
	float gain = sensitivity;
	
	if (getShiftKeyState())
	{
		gain *= 0.1;
	}
	
	if (mouse.button == 0)
	{
		rot = ofQuaternion(-d.y * gain, ofVec3f(1, 0, 0)) * rot;
		rot *= ofQuaternion(-d.x * gain, upVector);
		
		updated = true;
	}
	else if (mouse.button == 1)
	{
		ofVec3f a = d;
		a.x *= -1;
		a = rot * a;
		
		a *= gain;
		
		pos += a;
		eye += a;
		
		updated = true;
	}
	else if (mouse.button == 2)
	{
		ofVec3f a;
		a.z = -d.x + -d.y;
		a = rot * a;
		
		a *= gain;
		
		pos += a;
		eye += a;

		updated = true;
	}
	
	if (updated)
		updateTransform();
}

void ofxMayaCam::mousePressed(ofMouseEventArgs& mouse) {}
void ofxMayaCam::mouseMoved(ofMouseEventArgs& mouse) {}
void ofxMayaCam::mouseReleased(ofMouseEventArgs& mouse) {}

void ofxMayaCam::enableMouseInput()
{
	if(!bMouseInputEnabled){
		bMouseInputEnabled = true;
		ofRegisterMouseEvents(this);
	}
}

void ofxMayaCam::disableMouseInput()
{
	if(bMouseInputEnabled){
		bMouseInputEnabled = false;
		ofUnregisterMouseEvents(this);
	}
}

bool ofxMayaCam::getMouseInputEnabled()
{
	return bMouseInputEnabled;
}
