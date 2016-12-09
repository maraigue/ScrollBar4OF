#include "ofApp.h"

//--------------------------------------------------------------
// Update the displayed size, scroll size, etc. of the scroll bars
// (Called when the window size or the image size is changed)

void ofApp::updateScrollBars() {

	vscroll.bar_length(window_height - ScrollBarWidth);
	hscroll.bar_length(window_width - ScrollBarWidth);
	if (picture.isAllocated()) {
		vscroll.max(std::max<float>(picture.getHeight() - vscroll.bar_length(), 0));
		hscroll.max(std::max<float>(picture.getWidth() - hscroll.bar_length(), 0));
		vscroll.change_by_bar(vscroll.max() / 10);
		hscroll.change_by_bar(hscroll.max() / 10);
	}
	else {
		vscroll.max(0);
		hscroll.max(0);
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Picture Viewer Sample");

	vscroll.min(0);
	vscroll.bar_width(ScrollBarWidth);
	vscroll.bar_pos_widthdir(0);
	vscroll.bar_pos_lengthdir(ScrollBarWidth);
	vscroll.change_by_button(1);
	hscroll.min(0);
	hscroll.bar_width(ScrollBarWidth);
	hscroll.bar_pos_widthdir(0);
	hscroll.bar_pos_lengthdir(ScrollBarWidth);
	hscroll.change_by_button(1);
}

//--------------------------------------------------------------
void ofApp::update(){
	hscroll.update();
	vscroll.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	// If picture is not loaded:
	if (!picture.isAllocated()) {
		ofSetColor(0, 0, 0);
		ofFill();
		ofRect(0, 0, ofGetWidth(), ofGetHeight());
		ofSetColor(255, 0, 0);
		ofDrawBitmapString("Image not loaded; Click the window to load", 0, ofGetHeight() * 0.5);
		return;
	}

	// Displays the picture
	ofSetColor(255);
	picture.draw(ScrollBarWidth - hscroll.current(), ScrollBarWidth - vscroll.current());

	ofSetColor(0);
	ofFill();
	ofDrawRectangle(0, 0, ScrollBarWidth, ScrollBarWidth);

	// Displays the scroll bars
	vscroll.draw();
	hscroll.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (vscroll.mouseDragged(x, y)) {
		// do nothing else
		return;
	}
	else if (hscroll.mouseDragged(x, y)) {
		// do nothing else
		return;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (vscroll.mousePressed(x, y)) {
		// do nothing else
		return;
	}
	else if (hscroll.mousePressed(x, y)) {
		// do nothing else
		return;
	}

	// Selects the picture to show
	std::vector<char> fileName;
	fileName.reserve(MAX_PATH + 1);
	fileName[0] = '\0';

	OPENFILENAMEA ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = ofGetWin32Window();
	ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	ofn.lpstrFile = fileName.data();
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = 0;

	if (GetOpenFileNameA(&ofn)) {
		if (picture.load(fileName.data())) {
			updateScrollBars();
			hscroll.current(0);
			vscroll.current(0);
			draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (vscroll.mouseReleased(x, y)) {
		// do nothing else
		return;
	}
	else if (hscroll.mouseReleased(x, y)) {
		// do nothing else
		return;
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	window_width = w;
	window_height = h;
	updateScrollBars();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
