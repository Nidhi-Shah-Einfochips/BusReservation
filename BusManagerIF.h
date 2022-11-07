#ifndef _BusManagerIF_H_
#define _BusManagerIF_H_
#include<iostream>
#include<memory>
#include<map>
#include<vector>
#include<list>
#include"BusIF.h"
#include"StationCode.h"
class BusManagerIF
{
public:
    
    typedef std::shared_ptr<BusManagerIF> Ptr;
    BusManagerIF(){};
    virtual ~BusManagerIF(){};
    
    virtual void AddBus(BusIF::BusDetails)=0;
    virtual std::list<std::string> search(stationcode::stCode,stationcode::stCode)=0;
    // virtual void DeleteBus()=0;
    // virtual void PreparedChart()=0;
    // virtual void ShowBusList()=0;
    //virtual BusIF::Ptr Search()=0;
    //virtual void BookTicket(BusIF::Ptr)=0;
};
#endif