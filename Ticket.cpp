#include <iostream>
#include <memory>
#include <map>
#include <fstream>
#include <list>
#include <sstream>
#include "Ticket.h"
#include "Ticket_IF.h"
#include "Ticket_manager_IF.h"
Ticket::Ticket(TicketIF::Details Details):m_details(Details)
{
}

TicketIF::Ptr Ticket::CreateTicket(TicketIF::Details details)
{
    TicketIF::Ptr pTickit(new Ticket(details));
    return pTickit;
}

void Ticket::updateDetalis(TicketIF::Details details)
{
    m_details=details;
}
std::string Ticket::GenratePNR()
{
    std::string PNR = "TicketPNR_";
    char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < 10; i++)
        PNR = PNR + letters[rand() % 26];
    return PNR;
}
std::string Ticket::getPNR()
{
    return m_details.m_PNR;
}
bool Ticket::isConfromed()
{
    if (m_details.m_status == "CNF")
    {
        return true;
    }
}
bool Ticket::isWaiting()
{
    if (m_details.m_status == "WAITING")
    {
        return true;
    }
}
int Ticket::getSeatNo()
{
    return m_details.m_seatNo;
}
std::string Ticket::printDetails()
{
    std::stringstream ss;
    ss << "PNR : " << m_details.m_PNR<<"\t";
    ss << "SeatNo. : " << m_details.m_seatNo<<"\t";
    ss << "Status : " << m_details.m_status<<"\t";
    return ss.str();
}
