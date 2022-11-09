#include<iostream>
#include<memory>
#include<functional>
#include<map>
#include<list>
#include<bits/stdc++.h>
#include"StationCode.h"
#include"Ticket_manager_IF.h"
#include"Ticket_manager.h"
#include"Ticket.h"
#include"Ticket_IF.h"
#include"BusIF.h"
#include"BusManager.h"
#include"BusManagerIF.h"
TicketManager::TicketManager(int TotalSeats)
{
    Total_seats=TotalSeats;
}
Ticket_manager_IF::Ptr TicketManager::CreateManager(int TotalSeats)
{
    Ticket_manager_IF::Ptr pManager(new TicketManager(TotalSeats));
    return pManager;
   
    
}
std::string TicketManager::BookTicket(Ticket_manager_IF::JourneyDetails JourneyDetails)
{
    TicketIF::Ptr T1;
    std::string Success;
    static int seat=1;
    std::string status;
    if(seat<=Total_seats)
    {
        status = "CNF";
    }
    else
    {
        status = "waiting";
    }
    for(auto it = JourneyDetails.pass_name.begin();it!=JourneyDetails.pass_name.end();it++)
    {
        TicketIF::Details Details("ticket",seat,status,*it);
        T1 = Ticket::CreateTicket(Details);
        seat++;
        Success = T1->printDetails(); 
        return Success;
    }
    
   

}

#if 0
std::string TicketManager::BookTicket()
{
    ticket=Ticket::CreateTicket();
    std::string PNR;
    int book;
    std::cout<<"-------Intrested booking type--------"<<std::endl;
    std::cout<<"--------1. Normal booking ---------"<<std::endl;
    std::cout<<"--------2. Partial Booking -----------"<<std::endl;
    std::cout<<"Enter the choice"<<std::endl;
    std::cin>>book;
    switch(book)
    {
        case 1:
            std::cout<<"----------Normal booking--------"<<std::endl;
            
            PNR = ticket->setDetails();
            ticket->getDetails();
            passanger[PNR]=ticket;
            if(bookingNo<=Totalseats)
            {
                CNF_list.push_back(ticket);
            
            }
            else
            {
                Waiting_list.push_back(ticket);
                
            }
            bookingNo++;
            break;
        
        case 2:
            std::cout<<"-------partial booking-------"<<std::endl;
            //std::cout<<"Check avaiblity for partial booking"<<std::endl;
            // if(partialFlag==0)
            // {
                
                //std::cout<<"Yes "<<std::endl;
                std::cout<<"Enter the source"<<std::endl;
                std::cin>>src;
                std::cout<<"ENter the destination"<<std::endl;
                std::cin>>des;
                std::cout<<"booking ticket "<<src<<" to "<<des<<std::endl;

                PNR = ticket->setDetails_1(src);
                ticket->getDetails();
                passanger[PNR]=ticket;
                partial[PNR]=ticket;
                partialflag++;
                if(des==.back())
                {
                    bookingNo++;
                    if(bookingNo<=Totalseats)
                    {
                        CNF_list.push_back(ticket);
                    
                    }
                    else
                    {
                        Waiting_list.push_back(ticket);
                        
                    }
                }
                else
                {
                    if(bookingNo<=Totalseats)
                    {
                        CNF_list.push_back(ticket);
                    
                    }
                    else
                    {
                        Waiting_list.push_back(ticket);
                        
                    }
                }
                
                    
             break;
            
           
        default:
            break;
    }
    return PNR;
  
}
void TicketManager::CancelTicket()
{
    std::string PNR;
    std::cout<<"Enter the PNR no. "<<std::endl;
    std::cin>>PNR;
    std::map<std::string,TicketIF::Ptr>:: iterator it;
    for(auto it= passanger.begin(); it != passanger.end(); it++)
    {
        
        if(it->first==PNR)
        {
            auto tick=it->second;
            it=passanger.erase(it);
            std::map<std::string,TicketIF::Ptr>:: iterator itr;
            for(auto itr= partial.begin(); itr != partial.end(); itr++)
            {
        
                if(itr->first==PNR)
                {
                    itr=partial.erase(itr);
                    auto src.begin();
                    --idx;
                    std::advance(src,idx);
                    std::cout<<*src<<std::endl;
                    if(src==.begin())
                    {
                        bookingNo--;
                    }
                    std::list<TicketIF::Ptr>:: iterator itr2 = CNF_list.begin();
                    while (itr2 != CNF_list.end())
                    {
                        if (*itr2==tick) 
                        {
                            itr2 = CNF_list.erase(itr2);
                            std::cout<<"cancel"<<std::endl;
                            
                        }
                        else 
                        {
                            std::list<TicketIF::Ptr>:: iterator itr1 = Waiting_list.begin();
                            while (itr1 != Waiting_list.end())
                            {
                                if(*itr1==tick)
                                {
                                    itr1=Waiting_list.erase(itr1);
                                }
                                else
                                {
                                    itr1++;
                                }
                            }
                            itr2++;
                        }
                    }
                }
                else
                {
                    std::cout<<"in else part"<<std::endl;
                    std::list<TicketIF::Ptr>:: iterator itr2 = CNF_list.begin();
                    bookingNo--;
                    while (itr2 != CNF_list.end())
                    {
                        if (*itr2==tick) 
                        {
                            std::cout<<"cancel"<<std::endl;
                            itr2 = CNF_list.erase(itr2);
                        }
                        else 
                        {
                            std::list<TicketIF::Ptr>:: iterator itr1 = Waiting_list.begin();
                            while (itr1 != Waiting_list.end())
                            {
                                if(*itr1==tick)
                                {
                                    itr1=Waiting_list.erase(itr1);
                                }
                                else
                                {
                                    itr1++;
                                }
                            }
                            ++itr2;
                        }
                    }

                }
            }
        }
    }
    
    
            
    

        
}
void TicketManager::PreparedChart()
{
    do
    {
            
        if(bookingNo<=Totalseats)
        {
            auto wait = Waiting_list.front();
            CNF_list.push_back(wait);
            Waiting_list.erase(Waiting_list.begin());
            bookingNo++;
        }
        else
        {
            std::cout<<"No seats are avaiable"<<std::endl;
        }
    }while(bookingNo==Totalseats);
    std::cout<<"1 Booking list and partial list"<<std::endl;
    std::cout<<"2 Confrom list and waiting list"<<std::endl;
    int list;
    std::cout<<"Enter the list you want to see"<<std::endl;
    std::cin>>list;
    switch(list)
    {
        case 1:
            //std::map<std::string,TicketIF::Ptr>:: iterator it;
            int i;
            std::cout<<"--------- booking list --------"<<std::endl;
            std::cout<<"  PNR         "<<std::endl;
            i=0;
            for(auto it= passanger.begin(); it != passanger.end(); it++)
            {
                i++;
                std::cout <<i<<" "<<it->first << "       " << it->second<<"\n";
                std::cout<<"--------------------------------"<<std::endl;
            }


            std::cout<<"----------partial booking list--------"<<std::endl; 
            std::cout<<"  PNR         "<<std::endl;
            i=0;
            for(auto it= partial.begin(); it != partial.end(); it++)
            {
                i++;
                std::cout <<i<<" "<<it->first << "       " << it->second<<"\n";
                std::cout<<"--------------------------------"<<std::endl;
            }
            break;
        case 2:
            std::cout<<"---------------------"<<std::endl; 
            std::cout<<"Confromed list"<<std::endl;
            for (auto v : CNF_list)
                std::cout << v << "\n";
            // for(auto v : P_CNF_list)
            //     std::cout << v<<"\n";

        
            std::cout<<"----------------------------"<<std::endl;
            std::cout<<"Waiting list"<<std::endl;
            for (auto v : Waiting_list)
                std::cout << v << "\n";
            // for(auto v : P_Waiting_list)
            //     std::cout<<v<<"\n"; 
        break;

    }

   


            
           

          


    
            
}
#endif
