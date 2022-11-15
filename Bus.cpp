#include<iostream>
#include<memory>
#include<list>
#include<bits/stdc++.h>
#include"BusIF.h"
#include"Bus.h"
#include"Ticket_manager_IF.h"
#include"Ticket_manager.h"
#include"StationCode.h"
Bus::Bus(BusIF::BusDetails Details):m_BusDetails(Details),m_TicketManager(TicketManager::CreateManager(Details.m_capacity))
{
}
BusIF::Ptr Bus::CreateBus(BusIF::BusDetails &Details)
{
    Bus::Ptr pbus(new Bus(Details));
    Details.m_BusNo = pbus->GenrateBusID();
    return pbus;
}
void Bus::updateDetalis(BusIF::BusDetails Details)
{
    m_BusDetails=Details;
}
std::string Bus::GenrateBusID()
{
    static int BusNum=0;
    BusNum++;
    std::string mystr="BusID_";
    std::string Id = mystr + std::to_string(BusNum);
    return Id;
}
bool Bus::isStationAvailable(stationcode::stCode s)
{
   auto it = std::find(m_BusDetails.m_station.begin(),m_BusDetails.m_station.end(),s);
   return (it!=m_BusDetails.m_station.end());

   
}
std::string Bus::BookTicket(Ticket_manager_IF::JourneyDetails Journey)
{
    return m_TicketManager->BookTicket(Journey);
}
std::string Bus::PrintBusDetails()
{

    std::stringstream ss;
    ss << "BusNo : " << m_BusDetails.m_BusNo<<" \t";
    auto i= m_BusDetails.m_station.begin();
    int x = *i;
    auto k = m_BusDetails.m_station.end();
    int y =*k;
    ss << "Station : "<<stationcode::Station[x]<<" to "<<stationcode::Station[y]<<" \t";
    ss << "Capacity : " << m_BusDetails.m_capacity<<"\t";
    return ss.str();
}

#if 0
std::string Bus::setDetails()
{
    std::string mystr="BusID_";
    BusNum++;
    BusIF::myBus.BusNo = mystr + std::to_string(BusNum);
    std::cout<<"Enter the source"<<std::endl;
    std::cin>>BusIF::myBus.source;
    std::cout<<"Enter the destination"<<std::endl;
    std::cin>>BusIF::myBus.destination;
    std::cout<<"Enter the total seats you want in bus"<<std::endl;
    std::cin>>BusIF::myBus.Total_avaiable_Seats;
    BusDetails.push_back(myBus);
    return BusIF::myBus.BusNo;
}
void Bus::getDetails()
{
    std::cout<<"BUSID : "<<BusIF::myBus.BusNo<<std::endl;
    std::cout<<"Source : "<<BusIF::myBus.source<<std::endl;
    std::cout<<"Destination : "<<BusIF::myBus.destination<<std::endl;
    std::cout<<"TOTALSEATS : "<<BusIF::myBus.Total_avaiable_Seats<<std::endl;
    
}
std::string Bus::Bus_search(std::string source,std::string destination)
{
    std::string busid;
     for(auto it=BusDetails.begin(); it != BusDetails.end(); it++)
     {
        if(it->source==source && it->destination==destination)
        {
            busid=it->BusNo;
        }
     }

    return busid;
    
}
#endif