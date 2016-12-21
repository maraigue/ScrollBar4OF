#pragma once

#pragma warning(disable: 4819)
#include "ofMain.h"
#pragma warning(default: 4819)
#include "ScrollBar4OF.hpp"
#include <vector>
#include <Windows.h>
#include <Commdlg.h>

class ofApp : public ofBaseApp{
	private:
		ofImage picture;
		VerticalScrollBar vscroll;
		HorizontalScrollBar hscroll;
		int window_height, window_width;
		int scrollable_height, scrollable_width;

		void updateScrollBars();

	public:
		static const int ScrollBarWidth = 24;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
