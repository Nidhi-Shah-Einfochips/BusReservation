#include<iostream>
#include<memory>
#include<bits/stdc++.h>
#include<bits/stl_function.h>
#include<map>
#include<list>
#include<iterator>
#include<vector>
#include"BusManagerIF.h"
#include"BusManager.h"
#include"BusIF.h"
#include"Bus.h"
#include"Ticket_manager_IF.h"
#include"Ticket_manager.h"

BusManager::BusManager()
{
    
}
BusManagerIF::Ptr BusManager::CreateBusManager()
{
    BusManagerIF::Ptr pbusManager(new BusManager());
    return pbusManager;
}

void BusManager::AddBus(BusIF::BusDetails BusInfo)
{
    BusIF::Ptr B2;
    B2 = Bus::CreateBus(BusInfo);
    BusList[BusInfo.m_BusNo]=B2;
    B2->updateDetalis(BusInfo);
    
}
std::list<BusIF::Ptr> BusManager::search(stationcode::stCode src,stationcode::stCode des)
{
    std::list<BusIF::Ptr> buslist;
    for(auto it = BusList.begin();it!=BusList.end();it++)
    {
        if(it->second->isStationAvailable(src)==true)
        {
            if(it->second->isStationAvailable(des)==true)
            {
                buslist.push_back(it->second);
            }
        }
        
    }

    return buslist;
}

#if 0
void BusManager::DeleteBus()
{
    std::string BusId;
    std::cout<<"Enter the bus You want delete"<<std::endl;
    std::cin>>BusId;
    //std::map<BusIF::BusInfo,BusIF::Ptr>:: iterator it;
    for(auto it=BusList.begin(); it != BusList.end(); it++)
    {
        if(it->first==BusId)
        {
            it=BusList.erase(it);
        }
    }

}
void BusManager::PreparedChart()
{
    std::map<BusIF::Ptr,std::list<std::string>>::iterator it;
     for(auto it=Bus_PNR.begin(); it != Bus_PNR.end(); it++)
            {
                
                std::cout <<" "<<it->first <<"\n";
                
            }

   

}
void BusManager::ShowBusList()
{
    std::cout<<"Bus List "<<std::endl;
    std::cout<<"--------------------------------"<<std::endl;
    //std::map<BusIF::BusInfo,BusIF::Ptr>:: iterator it;
     for(auto it=BusList.begin(); it != BusList.end(); it++)
            {
               
                 std::cout <<" "<<it->first << "       " << it->second<<"\n";
               
            }
}
BusIF::Ptr BusManager::Search(std::string source, std::string destination)
{
    BusIF::Ptr busptr;
    //std::cout<<source<<" "<<destination<<std::endl;
    std::string busid = bus->Bus_search(source,destination);
    std::cout<<busid<<std::endl;
    auto it = BusList.find(busid);
    if(it!=BusList.end())
    {
        busptr=it->second;
        std::cout<<busptr<<std::endl;
    }
        
    
    return busptr;

   
}
void BusManager::BookTicket(BusIF::Ptr busptr)
{
   // std::cout<<"-----------1-----"<<std::endl;
    for(auto it=BusList.begin(); it !=BusList.end(); it++)
    {
       // std::cout<<"-----------2-----"<<std::endl;
        
       if(it->second==busptr)
       {
           
            tick= TicketManager::CreateManager();
            
            std::string PNR = tick->BookTicket();
            Bus_PNR[busptr].push_back(PNR);
        }
        
   }
    
}
#endif
