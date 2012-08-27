#include "ofxMayaCam.h"

ofxMayaCam::ofxMayaCam()
{
	mouseInputEnabled = false;
	keyInputEnabled = false;
	sensitivity = 0.8;
	upVector.set(0, 1, 0);
	focus = 200;
	
	try {
		enableMouseInput();
	} catch (...) {}
	
	reset();
	
	for (int i = 0; i < 3; i++)
		numkeys[i] = false;
}

ofxMayaCam::~ofxMayaCam()
{
}

void ofxMayaCam::reset()
{
	pos.set(0, 0, 0);
	rot.set(0, 0, 0, 1);
	
	updateTransform();
}

void ofxMayaCam::updateTransform()
{
	ofMatrix4x4 m;
	m.preMultTranslate(pos);
	m.preMultRotate(rot);
	m.preMultTranslate(-pos);
	
	m.preMultTranslate(pos + ofVec3f(0, 0, focus));
	
	setTransformMatrix(m);
}

void ofxMayaCam::mouseDragged(ofMouseEventArgs& mouse)
{
	bool n = false;
	for (int i = 0; i < 3; i++)
		if (numkeys[i]) n = numkeys[i];
		
	if (!getAltKeyState() && !n) return;
	
	ofVec2f last(ofGetPreviousMouseX(), ofGetPreviousMouseY());
	ofVec2f current(ofGetMouseX(), ofGetMouseY());
	ofVec2f d = current - last;
	
	bool updated = false;
	float gain = sensitivity;
	
	if (getShiftKeyState())
	{
		gain *= 0.1;
	}
	
	if ((mouse.button == 0 && !n)
		|| (mouse.button == 0 && numkeys[2]))
	{
		rot = ofQuaternion(-d.y * gain, ofVec3f(1, 0, 0)) * rot;
		rot *= ofQuaternion(-d.x * gain, upVector);
		
		updated = true;
	}
	else if ((mouse.button == 1 && !n)
			 || (mouse.button == 0 && numkeys[0]))
	{
		ofVec3f a = d;
		a.x *= -1;
		a = rot * a;
		
		a *= gain;
		
		pos += a;
		
		updated = true;
	}
	else if ((mouse.button == 2 && !n)
			 || (mouse.button == 0 && numkeys[1]))
	{
		ofVec3f a;
		a.z = -d.x + -d.y;
		a = rot * a;
		
		a *= gain;
		
		pos += a;

		updated = true;
	}
	
	if (updated)
		updateTransform();
}

void ofxMayaCam::keyPressed(ofKeyEventArgs &key)
{
	if (key.key == '1')
		numkeys[0] = true;
	else if (key.key == '2')
		numkeys[1] = true;
	else if (key.key == '3')
		numkeys[2] = true;
}

void ofxMayaCam::keyReleased(ofKeyEventArgs &key)
{
	if (key.key == '1')
		numkeys[0] = false;
	else if (key.key == '2')
		numkeys[1] = false;
	else if (key.key == '3')
		numkeys[2] = false;
}

void ofxMayaCam::mousePressed(ofMouseEventArgs& mouse) {}
void ofxMayaCam::mouseMoved(ofMouseEventArgs& mouse) {}
void ofxMayaCam::mouseReleased(ofMouseEventArgs& mouse) {}

void ofxMayaCam::enableAllInput()
{
	enableMouseInput();
	enableKeyInput();
}

void ofxMayaCam::disableAllInput()
{
	disableMouseInput();
	disableKeyInput();
}

void ofxMayaCam::enableMouseInput()
{
	if (!mouseInputEnabled)
	{
		ofRegisterMouseEvents(this);
		mouseInputEnabled = true;
	}
}

void ofxMayaCam::disableMouseInput()
{
	if (mouseInputEnabled)
	{
		ofUnregisterMouseEvents(this);
		mouseInputEnabled = false;
	}
}

bool ofxMayaCam::getMouseInputEnabled()
{
	return mouseInputEnabled;
}

void ofxMayaCam::enableKeyInput()
{
	if (!keyInputEnabled)
	{
		ofRegisterKeyEvents(this);
		keyInputEnabled = true;
	}
}

void ofxMayaCam::disableKeyInput()
{
	if (keyInputEnabled)
	{
		ofUnregisterKeyEvents(this);
		keyInputEnabled = false;
	}
}

bool ofxMayaCam::getKeyInputEnabled()
{
	return keyInputEnabled;
}
