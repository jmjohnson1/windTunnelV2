#ifndef SHAREDDATA_H
#define SHAREDDATA_H

extern "C" {
  #include "getPressure.h"
}
#include <QDebug>

class sharedData {
public:
  sharedData() {
    baroPressure = 0;
    dynamicPressure = 0;
    ts_airspeed = 0;
    density = 0;
  }

  void SetDynamicPressure(double dp) {dynamicPressure = dp;}
  void SetTsAirspeed(double aspd) {ts_airspeed = aspd;}

  double GetDynamicPressure() {return dynamicPressure;}
  double GetTsAirspeed() {return ts_airspeed;}
  double GetDensity() {qDebug() << density; return density;}

  double GetBaroPressure() {
    baroPressure = FetchBaroPressure();
    CalculateDensity();
    qDebug() << baroPressure;
    return baroPressure;
  }

private:
  void CalculateDensity() {
    double T = 22.0 + 273.15;
    density = baroPressure/286.0/T;
  }

  double density;
  double baroPressure;
  double dynamicPressure;
  double ts_airspeed;
};

#endif // SHAREDDATA_H
