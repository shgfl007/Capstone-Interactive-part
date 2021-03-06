//
//  LeapMotion.h
//  LeapMotion
//
//  Created by Danning Lu on 13-11-3.
//
//

#ifndef LeapMotion_LeapMotion_h
#define LeapMotion_LeapMotion_h

#include <iostream>
#include "../ofMain.h"
#include "Leap.h"

class LeapMotion : public Leap::Listener{
public:
    LeapMotion();
    ~LeapMotion();
    virtual void onInit(const Leap::Controller&);
    virtual void onConnect(const Leap::Controller&);
    virtual void onDisConnect(const Leap::Controller&);
    virtual void onFrame(const Leap::Controller&);
    virtual void onExit(const Leap::Controller&);
    
    vector<Leap::FingerList> getFingers();
private:
    Leap::HandList handList;
    vector<Leap::FingerList> fingers;
    
    Poco::FastMutex mutex;
};


#endif
