#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFullscreen(true);
    ofEnableAlphaBlending();
    ofBackground(0, 0, 0);
    
	ofDisableArbTex();
    ofEnableNormalizedTexCoords();
	
	player.loadMovie("movie.mov");
	player.setLoopState(OF_LOOP_NORMAL);
	player.play();
	
	ofxXmlSettings settings;
    settings.loadFile("settings.xml");
    float count = settings.getNumTags("output");
	
	for(int i = 0; i < count; i++){
		settings.pushTag("output",i);
		ofxWarpBlendTool::Controller * output = new ofxWarpBlendTool::Controller();
		ofVec2f size = ofVec2f(player.getWidth(),player.getHeight());
        ofRectangle coordinates(0,0,1.0, 1.0);
        ofPoint corners[4];
        corners[0].x = settings.getValue("x", 0.0f);
        corners[0].y = settings.getValue("y", 0.0f);
        corners[1].x = corners[0].x + settings.getValue("width", 0.0f);
        corners[1].y = corners[0].y;
        corners[2].x = corners[1].x;
        corners[2].y = corners[0].y + settings.getValue("height", 0.0f);
        corners[3].x = corners[0].x;
        corners[3].y = corners[2].y;
        output->setup(
					  &(player.getTextureReference()),
					  size,
					  coordinates,
					  corners,
					  "output"+ofToString(i),
					  400,
					  15
					  );
        output->setScissor(
						   ofRectangle(
									   settings.getValue("x", 0.0f),
									   settings.getValue("y", 0.0f),
									   settings.getValue("width", 0.0f),
									   settings.getValue("height", 0.0f)
									   )
						   );
        output->enableScissor();
        outputs.push_back(output);
		settings.popTag();
		
		
	}
	
	currentOutput = -1;
	
}

//--------------------------------------------------------------
void testApp::update(){
	player.update();

	
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i = 0; i < outputs.size(); i++) {
		outputs[i]->draw();
	}
	if(currentOutput != -1){
		outputs[currentOutput]->drawGui();
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch (key) {
		case '1':
			currentOutput = 0;
			break;
		case '2':
			currentOutput = 1;
			break;
		case '3':
			currentOutput = 2;
			break;
		case '0':
			currentOutput = -1;
			break;
		case ' ':
			ofToggleFullscreen();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
	
}