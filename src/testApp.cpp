#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    leapController.addListener(leap);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
 
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight());
    ofSetColor(255, 255, 255);
    
    if (phase1) {
        ofBox(50, -200, 4, 40, 40, 40);
    }

    Leap::Frame frame = leapController.frame();
    Leap::HandList hands = frame.hands();
    
    if (!hands.isEmpty()) {
        ofLogNotice("hand detected");
    }
    
    vector<Leap::FingerList> fingers = leap.getFingers();
    if (!fingers.empty()) {
        phase1 = true;
        //ofLogNotice("finger detected",ofToString(!fingers.empty()));

        
        for (int cnt = 0; cnt < fingers.size(); cnt++) {
            for (int fingerNum = 0; fingerNum < fingers[cnt].count(); fingerNum++) {
                Leap::Vector pt = fingers[cnt][fingerNum].tipPosition();
                Leap::Vector vpt = fingers[cnt][fingerNum].tipVelocity();
                pt.x = pt.x*2;
                pt.y = (pt.y * -1)*2;
                pt.z = pt.z *2;
                //ofLogNotice("finger number is " + ofToString(cnt) + ofToString(fingerNum));
                ofSphere(pt.x,pt.y,pt.z, 10);
                //ofLogNotice("position is " + ofToString(pt.x) + " " + ofToString(pt.y) + " " + ofToString(pt.z));
                //ofLogNotice("velocity is " + ofToString(vpt.x) + " " + ofToString(vpt.y) + " " + ofToString(vpt.z));
            }
        }
        Leap::Vector tpt = fingers[0][0].tipPosition();
         //ofBox(100, -200, 4, 40, 40, 40);
        
        
    }
    ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::exit(){
    leapController.removeListener(leap);
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
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