#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void regester();
void login();
void forgotpass();

int main()
{
    int choice;
    cout<<"enter your choice\n";
    cout<<"1.Login\n";
    cout<<"2.Regester\n";
    cout<<"3.forgot password\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        login();
        break;
        case 2:
        regester();
        break;
        case 3:
        forgotpass();
        break;
        default:
        system("CLS");
        cout<<"invalid input\n";
        
        main();
        

    }
}

void regester()
{
    string username,password;
    cout<<"Enter your username\n"; 
    cin>>username;
    cout<<"enter password\n";
    cin>>password;
    

    ofstream reg;
    reg.open("database.txt",ios::app);
    reg<<username<<" "<<password<<'\n';
    reg.close();
    system("CLS");
    cout<<"Regestration successful\n";
    
    main();

}
void login()
{
    string usernm,pass,lu,lp;
    int count=0;
    cout<<"Enter username\n";
    cin>>usernm;
    cout<<"enter password\n";
    cin>>pass;

    ifstream entered;
    entered.open("database.txt");
    while(entered>>lu>>lp)
    {
        if(usernm==lu && pass==lp)
        {
            count=1;
        }
    }
    entered.close();
    if(count==1)
    {
        system("CLS");
        cout<<"You have successfully loged in\n";
        
        //main();
    }
    else
    {
        system("CLS");
        cout<<"Invalid username or password\n";
        
        main();
    }

}
void forgotpass()
{
    string user,pass1,ur,pa;
    cout<<"enter username\n";
    cin>>user;
    int count=0;
    fstream user1;
    user1.open("database.txt");
    while(user1>>ur>>pa)
    {
        if(user==ur)
        { 
            count=1;
            break;
        }
    }
    if(count==1)
    {
        cout<<"user found\n";
        cout<<"enter a new password\n";
        cin>>pass1;
        
         
        user1<<user<<" "<<pass1<<'\n';
        
        cout<<"password changed successfully\n";
        
    }
    else
    {
        cout<<"user not found\n";
    }
    user1.close();
    main();
}