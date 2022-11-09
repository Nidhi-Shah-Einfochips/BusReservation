
#include<iostream>
#include<memory>
#include"Ticket_IF.h"
#include"Ticket_manager_IF.h"
#include"Ticket_manager.h"
#include"Ticket.h"
#include"BusIF.h"
#include"BusManagerIF.h"
#include"BusManager.h"
#include"Bus.h"
#include<map>
#include<list>
#include<iterator>
#include<vector>
#include"StationCode.h"
std::ostream &operator<<(std::ostream &os, const std::list<std::string> &list)
{
    for (auto const &i: list) {
        os << i << std::endl;
    }
    return os;
}
int main()
{
    int m_s;
    int m_d;
    int i=0;
    int pass_no;
    std::string m_name;
    std::list<stationcode::stCode> stationlist1;
    std::list<stationcode::stCode> stationlist2;
    stationlist1.push_back(stationcode::AHM);
    stationlist1.push_back(stationcode::BHA);
    stationlist1.push_back(stationcode::BOD);
    stationlist2.push_back(stationcode::SUT);
    stationlist2.push_back(stationcode::PUN);
    //TicketIF::Details Details("Nidhi",1,"CNF");
    //TicketIF::Ptr T1 = Ticket::CreateTicket(Details);
    //std::cout<<T1->getPNR()<<std::endl;
   // std::cout<<T1->printDetails()<<std::endl;
    //TicketIF::Details Details1("ABC",1,"CNF");
    //T1->updateDetalis(Details1);
   // std::cout<<T1->printDetails()<<std::endl;
    // Ticket_manager_IF::Ptr T2 =TicketManager::CreateManager(5);
    Ticket_manager_IF::JourneyDetails Journey;
    BusManagerIF::Ptr B1= BusManager::CreateBusManager();
    BusIF::BusDetails details("Bus1",stationlist1,5);
    BusIF::BusDetails details1("Bus2",stationlist2,4);
    B1->AddBus(details);
    B1->AddBus(details1);
    for (auto it = stationcode::Station.begin() ; it != stationcode::Station.end(); ++it)
    {
        std::cout <<i<< "\t" << *it<<std::endl;
        i++;
    }
    std::cout<<"Enter the source"<<std::endl;
    std::cin>>m_s;
    Journey.source = (stationcode::stCode)m_s;
    std::cout<<"Enter the destination"<<std::endl;
    std::cin>>m_d;
    Journey.destination = (stationcode::stCode)m_d;
    std::cout<<"List of bus that go from "<<stationcode::Station[m_s]<<" to "<<stationcode::Station[m_d]<<std::endl;
    std::list <std::string> buslist;
    std::cout<<B1->search((stationcode::stCode)m_s,(stationcode::stCode)m_d);
    std::cout<<"How many passengers do you want to enter"<<std::endl;
    std::cin>>pass_no;
    for(int k=0;k<pass_no;k++)
    {
        std::cout<<"Enter the name "<<std::endl;
        std::cin>>m_name;
        Journey.pass_name.push_back(m_name);
    }
    //std::cout<<T2->BookTicket(Journey);
    std::cout<<std::endl;
   
    
    
   
    std::cout<<std::endl;
    return 0;
}
#if 0

int main()
{
    int expression;
    int ch;
    int choice;
    std::string busid;
    std::string m_source;
    std::string m_destination;
    BusIF::Ptr busptr;
    //Ticket_manager_IF::Ptr tick= TicketManager::CreateManager();
    BusManagerIF::Ptr BusM= BusManager::CreateBusManager();

    
   do
   {
    std::cout<<"------MAIN MENU-----"<<std::endl;
    std::cout<<"1.Admin Access"<<std::endl;
    std::cout<<"2.User Access"<<std::endl;
    std::cout<<"3. Quit"<<std::endl;
    std::cout<<"Enter the choice"<<std::endl;
    std::cin>>expression;
    switch (expression)
    {
        case 1: 
           
            do
            {
                std::cout<<"Welcome to admin access"<<std::endl;
                std::cout<<"1. Add Bus"<<std::endl;
                std::cout<<"2. Delete Bus"<<std::endl;
                std::cout<<"3. Prepared Chart"<<std::endl;
                std::cout<<"4. exit to main menu"<<std::endl;
                
                std::cin>>ch;
                switch (ch)
                {
                    case 1:
                        std::cout<<"------Add bus------"<<std::endl;
                        BusM->AddBus();
                        break;
                    case 2:
                        std::cout<<"---------Delete Bus-----"<<std::endl;
                        BusM->DeleteBus();
                        break;
                    case 3:
                        std::cout<<"---------preparaed chart------"<<std::endl;
                        BusM->PreparedChart();
                        break;
                    case 4:
                        std::cout<<"--------back to main menu------"<<std::endl;
                        break;
                    default:
                        std::cout<<"--------enter the valid choice-----"<<std::endl;
                        break;
                }
              
                
            }while(ch!=4);
            break;
        case 2:
                std::cout<<"---------USER ACCESS---------"<<std::endl;
                    do
                    {
                   
                    
                    std::cout<<"---------1. BOOK TICKET---------"<<std::endl;
                    std::cout<<"---------2. CANCEL TICKET---------"<<std::endl;
                    std::cout<<"---------3. PREPARED CHART---------"<<std::endl;
                    std::cout<<"---------4. QUIT--------------"<<std::endl;
                    std::cout<<"---------ENTER YOUR CHOICE---------"<<std::endl;
                    std::cin>>choice;
                    switch (choice)
                    {
                    case 1:
                        std::cout<<"---------BOOK TICKET---------"<<std::endl;
                        //BusM->ShowBusList();
                        std::cout<<"Enter the the source and destination you want to go "<<std::endl;
                        std::cin>>m_source>>m_destination;
                        busptr=BusM->Search(m_source,m_destination);
                        
                        BusM->BookTicket(busptr);

                        //tick->BookTicket();
                        
                        break;
                    case 2:
                        std::cout<<"---------CANCEL TICKET---------"<<std::endl;
                        //tick->CancelTicket();
                        break;
                    case 3:
                        std::cout<<"---------PREPARED CHART---------"<<std::endl;
                        //tick->PreparedChart();
                        break;
                    case 4:
                        std::cout<<"---------------QUIT--------------"<<std::endl;
                        break;
                    default:
                        std::cout<<"ENTER VALID CHOICE"<<std::endl;
                        break;
                    }
                    } while (choice!=4);
                    break;
        case 3:
            std::cout<<"Quit "<<std::endl;
            break;

                
        default:
            std::cout<<"enter the valid choice"<<std::endl;
             break;
    }
   }while(expression!=3);
   return 0;
    
}
#endif