#include "Watchy_7_SEG.h"

#define DARKMODE false

const uint8_t BATTERY_SEGMENT_WIDTH = 7;
const uint8_t BATTERY_SEGMENT_HEIGHT = 11;
const uint8_t BATTERY_SEGMENT_SPACING = 9;
const uint8_t WEATHER_ICON_WIDTH = 48;
const uint8_t WEATHER_ICON_HEIGHT = 32;

void Watchy7SEG::drawWatchFace(){
    display.fillScreen(DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);
    display.setTextColor(DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    drawTime();
    drawDate();
    drawBattery();
    drawWeather();
    
    // if(WIFI_CONFIGURED){
    //     display.drawBitmap(120, 77, wifi, 26, 18, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    // }

}

void Watchy7SEG::drawTime(){
    display.setFont(&DSEG7_Classic_Bold_53);
    display.setCursor(5, 53+5);
    int displayHour;
    if(HOUR_12_24==12){
      displayHour = ((currentTime.Hour+11)%12)+1;
    } else {
      displayHour = currentTime.Hour;
    }
    if(displayHour < 10){
        display.print("0");
    }
    display.print(displayHour);
    display.print(":");
    if(currentTime.Minute < 10){
        display.print("0");
    }
    display.println(currentTime.Minute);
}

void Watchy7SEG::drawDate(){
    display.setFont(&Seven_Segment10pt7b);

    int16_t  x1, y1;
    uint16_t w, h;

    String dayOfWeek = dayStr(currentTime.Wday);
    display.getTextBounds(dayOfWeek, 5, 85, &x1, &y1, &w, &h);
    if(currentTime.Wday == 4){
        w = w - 5;
    }
    display.setCursor(85 - w, 85);
    display.println(dayOfWeek);

    String month = monthShortStr(currentTime.Month);
    display.getTextBounds(month, 60, 110, &x1, &y1, &w, &h);
    display.setCursor(85 - w, 110);
    display.println(month);

    display.setFont(&DSEG7_Classic_Bold_25);
    display.setCursor(5, 120);
    if(currentTime.Day < 10){
    display.print("0");
    }
    display.println(currentTime.Day);
    display.setCursor(5, 150);
    display.println(tmYearToCalendar(currentTime.Year));// offset from 1970, since year is stored in uint8_t
}


void Watchy7SEG::drawBattery(){
    float VBAT = getBatteryVoltage();
    int percent = (VBAT-3.4)*100L/(4.2-3.4);
    percent = min(percent,100);
    percent = max(percent,0);
    int16_t  x1, y1;
    uint16_t w, h;

    String battery_percentage = String(percent)+"%";
    display.setFont(&Seven_Segment10pt7b);
    display.getTextBounds(battery_percentage, 100, 80, &x1, &y1, &w, &h);
    display.setCursor((195-w), 85);
    display.println(battery_percentage);
}


void Watchy7SEG::drawWeather(){

//     weatherData currentWeather = getWeatherData();

//     int8_t temperature = currentWeather.temperature;
//     int16_t weatherConditionCode = currentWeather.weatherConditionCode;

//     display.setFont(&DSEG7_Classic_Regular_39);
//     int16_t  x1, y1;
//     uint16_t w, h;
//     display.getTextBounds(String(temperature), 0, 0, &x1, &y1, &w, &h);
//     if(159 - w - x1 > 87){
//         display.setCursor(159 - w - x1, 150);
//     }else{
//         display.setFont(&DSEG7_Classic_Bold_25);
//         display.getTextBounds(String(temperature), 0, 0, &x1, &y1, &w, &h);
//         display.setCursor(159 - w - x1, 136);
//     }
//     display.println(temperature);
//     display.drawBitmap(165, 110, currentWeather.isMetric ? celsius : fahrenheit, 26, 20, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
//     const unsigned char* weatherIcon;

//     //https://openweathermap.org/weather-conditions
//     if(weatherConditionCode > 801){//Cloudy
//     weatherIcon = cloudy;
//     }else if(weatherConditionCode == 801){//Few Clouds
//     weatherIcon = cloudsun;
//     }else if(weatherConditionCode == 800){//Clear
//     weatherIcon = sunny;
//     }else if(weatherConditionCode >=700){//Atmosphere
//     weatherIcon = atmosphere;
//     }else if(weatherConditionCode >=600){//Snow
//     weatherIcon = snow;
//     }else if(weatherConditionCode >=500){//Rain
//     weatherIcon = rain;
//     }else if(weatherConditionCode >=300){//Drizzle
//     weatherIcon = drizzle;
//     }else if(weatherConditionCode >=200){//Thunderstorm
//     weatherIcon = thunderstorm;
//     }else
//     return;
//     display.drawBitmap(145, 158, weatherIcon, WEATHER_ICON_WIDTH, WEATHER_ICON_HEIGHT, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
}