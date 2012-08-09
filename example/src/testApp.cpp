#include "testApp.h"

vector<ofVec3f> points;

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	ofBackground(30);
	
	for (int i = 0; i < 300; i++)
	{
		points.push_back(ofVec3f(ofRandom(-1000, 1000),
								 ofRandom(-1000, 1000),
								 ofRandom(-1000, 1000)));
	}
	
//	cam.setSensitivity(0.5);
//	cam.setUpVector(ofVec3f(0, 1, 0));
}

//--------------------------------------------------------------
void testApp::update()
{

}

//--------------------------------------------------------------
void testApp::draw()
{
	ofNoFill();
	
	cam.begin();
	
	ofDrawAxis(100);
	
	for (int i = 0; i < points.size(); i++)
	{
		ofBox(points[i], 40);
	}
	
	cam.end();
	
	string str;
	str = "alt + left drag: rotate\n"
	"alt + center drag: translate\n"
	"alt + right drag: zoom";
	ofDrawBitmapString(str, 10, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}