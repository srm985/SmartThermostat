#ifndef DHT_h_
#define DHT_h_

#define DHT_Pin		0x80	//Default D7 (Physical Pin 21)


void initDHT(void);

void pollDHT(unsigned char *climateData);

#endif