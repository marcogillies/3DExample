#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // if we don't do this things get weird
    // things that are supposed to be behind will
    // in front
    ofEnableDepthTest();
    
    // set the size of the box
    box.set( 100 );
    
    // set the size fo the sphere
    sphere.setRadius(200);
    
    // position the camera
    camera.setPosition(ofGetWidth()/2,
                       ofGetHeight()/2, 700);
    
    // two things we need to enable for it to work
    // turn on lighting
    ofEnableLighting();
    // set texture coordinates from 0-1 rather
    // than in actual pixels (otherwise it is
    // really hard to get the texturing right)
    ofEnableNormalizedTexCoords();
    
    // set up the parameters of the light
    light.setPointLight();
    light.setAmbientColor(ofFloatColor(0.3, 0.3, 0.3));
    light.setDiffuseColor(ofFloatColor(1.0, 0.5, 0.0));
    light.setPosition(ofGetWidth()*.5,
                      ofGetHeight()*.7, 300);
    
    // diffues colour is the basic colour
    material.setDiffuseColor(ofFloatColor(1.0, 0, 0));
    
    // load up a texture and flip it
    texture.load("Equirectangular_projection_SW.jpg");
    texture.mirror(true, false);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    
    // position on the box at hte middle of the screen
    // and spin it around x and y
    box.setPosition(ofGetWidth()*.5 - 200,
                    ofGetHeight()*.5, 0);
    box.rotate(0.1, 1.0, 0.0, 0.0);
    box.rotate(0.2, 0, 1.0, 0.0);
    
    // same for the sphere
    sphere.setPosition(ofGetWidth()*.5 + 200,
                    ofGetHeight()*.5, 0);
    sphere.rotate(0.1, 1.0, 0.0, 0.0);
    sphere.rotate(0.2, 0, 1.0, 0.0);
    
    
    // turn the lights on
    light.enable();
    
    // drawing code
    // camera.begin/end will start drawing from
    // the position of the camera
    camera.begin();
    material.begin();  // start the material
                       // all objects between begin and
                       // end will be drawn with this texture
    box.draw();
    material.end();
    
    texture.getTexture().bind(); // start the textures
                                 // all objects between bind and unbind
                                 // will be drawn with the texture
    // draw the object
    
    sphere.draw();
    texture.getTexture().unbind();
    camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'w'){
        camera.dolly(-10);
    }
    if(key == 's'){
        camera.dolly(10);
    }
    if(key == 'a'){
        camera.pan(1);
    }
    if(key == 'd'){
        camera.pan(-1);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
