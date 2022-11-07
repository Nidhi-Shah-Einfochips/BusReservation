#ifndef _BusIF_H_
#define _BusIF_H_
#include<memory>
#include<iostream>
#include"StationCode.h"
class BusIF
{
public:
    BusIF(){};
    typedef std::shared_ptr<BusIF> Ptr;
    struct BusDetails
    {
        std::string m_BusNo;
        std::list<stationcode::stCode> m_station;
        int m_capacity;
        BusDetails(std::string BusNo, std::list<stationcode::stCode> station, int capacity)
        {
            m_BusNo=BusNo;
            m_station=station;
            m_capacity=capacity;
        }
        BusDetails(BusDetails &bus)
        {
            m_BusNo=bus.m_BusNo;
            m_station=bus.m_station;
            m_capacity=bus.m_capacity;
        }

    };
    virtual bool isStationAvailable(stationcode::stCode)=0;
    

    virtual ~BusIF(){};

};
#endif
