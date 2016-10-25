#ifndef RTC_h_
#define RTC_h_

#define thermoAddress_Write			0xD0
#define thermoAddress_Read			0xD1

void initRTC(void);

void readRTC(unsigned char *timeData);

void writeRTC(unsigned char *timeData);

#endif