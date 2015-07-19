//
//  CountlyDeviceInfo.h
//  CountlyX
//
//  Created by Junaid on 08/07/2015.
//
//

#ifndef __CountlyX__CountlyDeviceInfo__
#define __CountlyX__CountlyDeviceInfo__


#include "cocos2d.h"


class CountlyDeviceInfo
{
public:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  
  static const char* getDeviceId();
  static const char* getUserAgent();
  static const char* getDeviceModel();
  static const char* getCarrierName();
  static const char* getDeviceSystemName();
  static const char* getDeviceSystemVersion();
  #else
  static const char* getDeviceId() {return "";};
  static const char* getUserAgent() {return "";};
  static const char* getDeviceModel() {return "";};
  static const char* getCarrierName() {return "";};
  static const char* getDeviceSystemName() {return "";};
  static const char* getDeviceSystemVersion() {return "";};
  #endif
  
};


#endif /* defined(__CountlyX__CountlyDeviceInfo__) */