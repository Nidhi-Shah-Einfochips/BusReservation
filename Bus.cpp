#include<iostream>
#include<memory>
#include<list>
#include<bits/stdc++.h>
#include"BusIF.h"
#include"Bus.h"
#include"Ticket_manager_IF.h"
#include"Ticket_manager.h"
#include"StationCode.h"
Bus::Bus(BusIF::BusDetails Details):m_BusDetails(Details)
{
    Ticket_manager_IF::Ptr T2 =TicketManager::CreateManager(5);
    
}
BusIF::Ptr Bus::CreateBus(BusIF::BusDetails &Details)
{
    Bus::Ptr pbus(new Bus(Details));
    Details.m_BusNo = pbus->GenrateBusID();
    return pbus;
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