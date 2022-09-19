#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofNoFill();
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 30;
	int radius = span * 0.25;
	for (int x = span * 0.5; x <= ofGetWindowWidth(); x += span) {

		for (int y = span * 0.5; y <= ofGetWindowHeight(); y += span) {

			ofPushMatrix();
			ofTranslate(x, y);

			auto noise_y = ofMap(ofNoise(x * 0.0035 + ofGetFrameNum() * 0.03), 0, 1, 100, ofGetWindowHeight() - 100);

			if (abs(noise_y - y) < 100) {

				auto y_1 = ofMap(ofNoise((x - span * 0.5) * 0.0035 + ofGetFrameNum() * 0.03), 0, 1, 100, ofGetWindowHeight() - 100);
				auto y_2 = ofMap(ofNoise((x + span * 0.5) * 0.0035 + ofGetFrameNum() * 0.03), 0, 1, 100, ofGetWindowHeight() - 100);

				auto rad = std::atan2(y_1 - y_2, (x - span * 0.5) - (x + span * 0.5));

				ofRotate(rad * RAD_TO_DEG);

				ofSetColor(255);
				ofDrawCircle(0, 0, radius);
				ofDrawLine(span * -0.45, 0, span * 0.45, 0);
			}
			else {

				ofSetColor(128);
				ofDrawCircle(0, 0, radius);
				ofDrawLine(span * -0.45, 0, span * 0.45, 0);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}