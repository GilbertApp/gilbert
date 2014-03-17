#pragma once

#include "ofMain.h"
#include "fft.h"
#include "ofxUI.h"
#include <vector>

#define BUFFER_SIZE 256
#define NUM_WINDOWS 80

typedef struct soundFeatureSet{
    string id;
    float centroid;
    float rms;
} sfs;

class gilbert : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
    
    //UI
    void setGUI1();
    ofxUICanvas *gui1;
    void guiEvent(ofxUIEventArgs &e);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void audioIn(float *input, int bufferSize, int nChannels);
    void analyseHitBuffer(vector<float>& hitBuffer, string drum);
    float calcVectorSC(vector<float>& shortBuffer, int startPoint);
    float calcVectorRMS(const vector<float>& shortBuffer, int startPoint, int endPoint);
    float* normalizeComplement(float* arr, int size);
    float* normalize(float* arr, int size);
    
    string lookupClosest(sfs input);
    
    int initialBufferSize;
    int sampleRate;
    float * buffer;
    float maxRoomRMS;
    
    float calcRMS();
    float calcRMS(float* b, int size);
    float calcSC();
    void calcRoomRMS(float currRMS);
    Boolean aPressed, bPressed, cPressed, dPressed;
    std::vector<float> aBuffer, bBuffer, cBuffer, dBuffer;
    Boolean audioFinished = false;
    
    std::vector<sfs> inputSfsSet;
    
    // FFT vars
    fft myfft;
    
    ofSoundPlayer snare;
    ofSoundPlayer kick;
    ofSoundPlayer hat;
    ofSoundPlayer crash;
    
    float bufrms = 0;
    
    float * magnitude;
    float * phase;
    float * power;
    float avg_power;
    
    float *kispec;
    float *snspec;
    float *haspec;
    float *crspec;
    
    float freq[NUM_WINDOWS][BUFFER_SIZE/2];
    float freq_phase[NUM_WINDOWS][BUFFER_SIZE/2];
		
};
