#include <bits/stdc++.h>

using namespace std;

//Function for extraction money and return the balance amount after the transaction
//returns -1 for unsuccessfull transation
int extract_money(int balance,int value)
{
   if(value%500==0)
   {
       if(balance>=value)         //checking the condition of debit amount is less than balance
       {
           balance=balance-value;
           return balance;
       }
       else
       {
           return -1;
       }
   }
   else
   {
       return -1;
   }
}


//Function for adding money and returns the balance amount after the transaction
int add_money(int balance,int value)
{
    if(value%500==0)
    {
        balance=balance+value;
        return balance;
    }
    else
    {
        return -1;
    }
}


int main() 
{
    //variable for storing current balance of both account
    int checking_balance,saving_balance;
    
    //data structure to store our successfull transaction history
    vector< pair < string,pair<string,int> > > saving_record,checking_record;
    
    cout<<"Enter the initial balance of Savings account:"<<endl;
    cin>>saving_balance;
    
    cout<<"Enter the initial balance of Checking account:"<<endl;
    cin>>checking_balance;
    
    char flag='y';
    cout<<"Do you want to do transaction for Savings account(y OR n):"<<endl;
    cin>>flag;
    
    while(flag=='y')
    {
        string date,type;
        int value;
        cout<<"Enter the date of transation:"<<endl;
        cin>>date;
        
        cout<<"debit or credit:"<<endl;
        cin>>type;
        
        cout<<"Enter the value of money(multiple of 500 only):"<<endl;
        cin>>value;
        
        if(value%500!=0)   //if value is not multiple of 500, transaction will not be allowed
        {
            cout<<"Can not do this type of transaction"<<endl;
        }
        else
        {
            if(type=="debit")
            {
                int tmp=extract_money(saving_balance,value);
                if(tmp==-1)             //checking the corner case of debit amount is less than balance
                {
                    cout<<"Can not do this transation:"<<endl;
                }
                else
                {
                    saving_balance=tmp;
                    saving_record.push_back({date,{type,value}});       //saving our record and telling user that transaction is successfull
                    cout<<"Successfull Transaction"<<endl;
                }
                
            }
            else if(type=="credit")
            {
                saving_balance=add_money(saving_balance,value);
                saving_record.push_back({date,{type,value}});
                cout<<"Successfull Transaction"<<endl;
            }
        }
        cout<<"Do you want to do more transaction for Savings account(y OR n):"<<endl;
        cin>>flag;
    }
    
    flag='y';
    cout<<"Do you want to do transaction for Checking account(y OR n):"<<endl;
    cin>>flag;
    while(flag=='y')
    {
        string date,type;
        int value;
        
        cout<<"Enter the date of transation:"<<endl;
        cin>>date;
        
        cout<<"debit or credit:"<<endl;
        cin>>type;
        
        cout<<"Enter the value of money(multiple of 500 only):"<<endl;
        cin>>value;
        
        if(value%500!=0)               //if value is not multiple of 500, transaction will not be allowed
        {
            cout<<"Can not do this type of transaction"<<endl;
        }
        else
        {
            if(type=="debit")
            {
                int tmp=extract_money(checking_balance,value);
                if(tmp==-1)                   //checking the corner case of debit amount is less than balance
                {
                    cout<<"Can not do this transation:"<<endl;
                }
                else
                {
                    checking_balance=tmp;
                    checking_record.push_back({date,{type,value}});   //saving our record and telling user that transaction is successfull
                    cout<<"Successfull Transaction"<<endl;
                }
                
            }
            else if(type=="credit")
            {
                checking_balance=add_money(checking_balance,value);
                checking_record.push_back({date,{type,value}});
                cout<<"Successfull Transaction"<<endl;
            }
        }
        cout<<"Do you want to do more transaction for Checking account(y OR n):"<<endl;
        cin>>flag;
    }
    
    //Showing history of Savings account
    cout<<"Savings"<<endl<<"Account transactions"<<endl;
    if(saving_record.size()==0)         //If no transactions happened
    {
        cout<<"No Transactions"<<endl;
    }
    
    for(int i=0;i<saving_record.size();i++)
    {
        cout<<saving_record[i].first<<" "<<saving_record[i].second.first<<" "<<saving_record[i].second.second<<endl;
    }
    
    cout<<"Final Balance = "<<saving_balance<<endl;
    
    //Showing history of checking account
    cout<<"Checking"<<endl<<"Account transactions"<<endl;
    
    if(checking_record.size()==0)     //If no transactions happened
    {
        cout<<"No Transactions"<<endl;
    }
    
    for(int i=0;i<checking_record.size();i++)
    {
        cout<<checking_record[i].first<<" "<<checking_record[i].second.first<<" "<<checking_record[i].second.second<<endl;
    }
    
    cout<<"Final Balance = "<<checking_balance<<endl;
    
}