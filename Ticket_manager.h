#ifndef _Ticket_manager_H_
#define _Ticket_manager_H_
#include<iostream>
#include<memory>
#include<map>
#include"Ticket_manager_IF.h"
#include"BusIF.h"
#include"StationCode.h"
#include"Ticket_IF.h"
class TicketManager:public Ticket_manager_IF , public  std::enable_shared_from_this<TicketManager>
{
    private:
        TicketManager(int);
        int LastBookCount=1;
        Ticket_manager_IF::JourneyDetails m_JourneyDetails;
        std::map<std::string,TicketIF::Ptr> m_passanger;
        
    public:
        typedef std::shared_ptr<TicketManager> Ptr;
        static Ticket_manager_IF::Ptr CreateManager(int);
        std::string BookTicket(Ticket_manager_IF::JourneyDetails);
        //void CancelTicket();
        //void PreparedChart();
        virtual ~TicketManager(){};
        

       
    
};
#endif
