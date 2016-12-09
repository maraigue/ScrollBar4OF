#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#pragma warning(disable: 4819)
#include "ofMain.h"
#pragma warning(default: 4819)
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(400, 300, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
