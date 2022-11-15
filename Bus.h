#ifndef _Bus_H_
#define _Bus_H_
#include<iostream>
#include<memory>
#include<list>
#include<map>
#include<bits/stdc++.h>
#include"BusIF.h"
#include"Ticket_manager_IF.h"

class Bus:public BusIF,public std::enable_shared_from_this<Bus>
{
    private:
        Bus(BusIF::BusDetails);
        BusIF::BusDetails m_BusDetails;
        std::string GenrateBusID();
        Ticket_manager_IF::Ptr m_TicketManager;
    public:
        typedef std::shared_ptr<Bus> Ptr;
        static BusIF::Ptr CreateBus(BusIF::BusDetails &);
        bool isStationAvailable(stationcode::stCode);
        std::string BookTicket(Ticket_manager_IF::JourneyDetails);
        void updateDetalis(BusIF::BusDetails);
        std::string PrintBusDetails();
        virtual ~Bus(){};


};
#endif
