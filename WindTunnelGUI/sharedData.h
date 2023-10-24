#ifndef SHAREDDATA_H
#define SHAREDDATA_H

class sharedData {
public:
  sharedData() {
    dynamicPressure = 0;
    ts_airspeed = 0;
  }

  void setDynamicPressure(float dp) {dynamicPressure = dp;}
  void setTsAirspeed(float aspd) {ts_airspeed = aspd;}
  float getDynamicPressure() {return dynamicPressure;}
  float getTsAirspeed() {return ts_airspeed;}

private:
  float dynamicPressure;
  float ts_airspeed;
};

#endif // SHAREDDATA_H
