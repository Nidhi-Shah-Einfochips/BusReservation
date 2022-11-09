#ifndef _Bus_H_
#define _Bus_H_
#include<iostream>
#include<memory>
#include<list>
#include<bits/stdc++.h>
#include"BusIF.h"

class Bus:public BusIF,public std::enable_shared_from_this<Bus>
{
    private:
        Bus(BusIF::BusDetails);
        BusIF::BusDetails m_BusDetails;
        std::string GenrateBusID();
    public:
        typedef std::shared_ptr<Bus> Ptr;
        static BusIF::Ptr CreateBus(BusIF::BusDetails &);
        bool isStationAvailable(stationcode::stCode);
        virtual ~Bus(){};


};
#endif
