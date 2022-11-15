#ifndef _Ticket_manager_IF_H_
#define _Ticket_manager_IF_H_
#include<iostream>
#include<memory>
#include<map>
#include<list>
#include"Ticket_IF.h"
#include"StationCode.h"

class Ticket_manager_IF
{
public:
    struct JourneyDetails
    {
        stationcode::stCode source;
        stationcode::stCode destination;
        std::list<std::string> pass_name;
    };
    typedef std::shared_ptr<Ticket_manager_IF> Ptr;
    Ticket_manager_IF(){};
    virtual ~Ticket_manager_IF(){};
    virtual std::string BookTicket(Ticket_manager_IF::JourneyDetails)=0;
    //virtual void CancelTicket()=0;
    //virtual void PreparedChart()=0;
    
};
#endif

