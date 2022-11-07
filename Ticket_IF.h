#ifndef _Ticket_IF_H_
#define _Ticket_IF_H_
#include <memory>
#include <list>
class TicketIF
{
public:
    typedef std::shared_ptr<TicketIF> Ptr;

    TicketIF();
    struct Details
    {
        std::string m_PNR;
        std::string m_Name;
        int m_seatNo;
        std::string m_status;
        Details(std::string PNR, int seatNo, std::string status)
        {
            m_PNR = PNR;
            m_seatNo = seatNo;
            m_status = status;
        }
        Details(Details &d)
        {
            m_PNR = d.m_PNR;
            m_seatNo = d.m_seatNo;
            m_status = d.m_status;
        }
    };
    virtual void updateDetalis(TicketIF::Details) = 0;
    virtual std::string getPNR() = 0;
    virtual bool isConfromed() = 0;
    virtual bool isWaiting() = 0;
    virtual int getSeatNo() = 0;
    virtual std::string printDetails() = 0;
    virtual ~TicketIF(){};
};
#endif