//
//  CounltyEventQueue.cpp
//  CountlyX
//
//  Created by Junaid on 14/07/2015.
//
//

#include "CounltyEventQueue.h"
#include "CountlyUtils.h"
#include "CountlyConnectionQueue.h"
#include "external/json/writer.h"
#include "external/json/document.h"
#include "external/json/stringbuffer.h"

void CountlyEventQueue::addEvent(CountlyEvent* event) {
  eventQueue.pushBack(event);
}

void CountlyEventQueue::removeEvent(CountlyEvent *event) {
  eventQueue.eraseObject(event);
}

int CountlyEventQueue::eventCount() {
  return (int)eventQueue.size();
}

Vector<CountlyEvent*> CountlyEventQueue::getEvents() {
  return eventQueue;
}

void CountlyEventQueue::recordEvent(string pKey, int pCount) {
  CountlyEvent *event = new CountlyEvent();
  event->populateEvent(pKey, pCount);
  addEvent(event);
  
}
void CountlyEventQueue::recordEvent(string pKey, int pCount, float pSum) {
  CountlyEvent *event = new CountlyEvent();
  event->populateEvent(pKey, pCount, pSum);
  addEvent(event);
  
}
void CountlyEventQueue::recordEvent(string pKey, int pCount, Map<string, __String*> pSegmentation) {
  CountlyEvent *event = new CountlyEvent();
  event->populateEvent(pKey, pCount, pSegmentation);
  addEvent(event);
  
}
void CountlyEventQueue::recordEvent(string pKey, int pCount, float pSum, Map<string, __String*> pSegmentation) {
  CountlyEvent *event = new CountlyEvent();
  event->populateEvent(pKey, pCount, pSum, pSegmentation);
  addEvent(event);
}

string CountlyEventQueue::eventsUrl() {
  rapidjson::StringBuffer s;
  rapidjson::Writer<rapidjson::StringBuffer> writer(s);
  
  writer.StartArray();
  for(CountlyEvent* event : eventQueue)
  {
    event->serializedData(writer);
  }
  writer.EndArray();
  eventQueue.clear();
  log("%s",s.GetString());
  
  string strEncode = CountlyUtils::urlencode(s.GetString());
  
  return strEncode;

}