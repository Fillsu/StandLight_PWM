#ifndef __DHT11_H__
#define __DHT11_H__

class DHT_Data
{
public:
    int RH;
    int RHDec;
    int Temp;
    int TempDec;
    int checksum;
    int error;
};

class DHT11
{
private:
    int pinNumber;
    int data[5];
    

    void startTrigger();
    void waitResponse();
    void clearData();

public:
    DHT11(int pin);
    virtual ~DHT11();
    void readData();
    DHT_Data dhtData;
};

#endif /* __DHT11_H__ */