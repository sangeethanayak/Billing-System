#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;
public:
    void menu();
    void admin();
    void customer();
    void add();
    void edit();
    void rem();
    void list1();
    void receipt();

};
void shopping :: menu()
{
    Menu:
    int choice;
    string email;
    string password;
    cout<<"\n\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (89);
    cout<<"SPAR SUPER MARKET"<<endl;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (85);
    cout<<"1. Admin login"<<endl;
    cout << setw (88);
    cout<<"2. Customer login"<<endl;
    cout << setw (78);
    cout<<"3. Exit"<<endl;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (95);
    cout<<"Please select any options: ";
    cin>>choice;
    cout<<endl<<endl;
    switch(choice)
    {
        case 1:
        cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
        cout << setw (85);
        cout<<"Admin login"<<endl;
        cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
        cout << setw (65);
        cout<<"Enter email: ";
        cin>>email;
        cout << setw (68);
        cout<<"Enter password: ";
        cin>>password;
        cout<<endl<<endl;
        if(email=="1234" && password=="1234")
        {
            admin();
        }
        else
        {
           cout << setw (103);
           cout<<"*WARNING: Invalid email or password. Try again!\n\n";

        }
        break;

    case 2:
        {
            customer();
        }
        break;
    case 3:
        {
            exit(0);
        }
        break;
    default:
        {
            cout<<"Invalid choice! Try again!"<<endl;
            goto Menu;
        }
    }
goto Menu;
}
void shopping :: admin()
{
    Admin:
    int choice;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (85);
    cout<<"Admin Page"<<endl;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (90);
    cout<<"1. Add product details"<<endl;
    cout << setw (93);
    cout<<"2. Modify product details"<<endl;
    cout << setw (93);
    cout<<"3. Delete product details"<<endl;
    cout << setw (91);
    cout<<"4. Go Back to main menu"<<endl<<endl;
    cout << setw (95);
    cout<<"Please enter your option: ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid choice";
    }
   goto Admin;
}
void shopping :: customer()
{
    Customer:
    int choice;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (85);
    cout<<"Customer Page"<<endl;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (85);
    cout<<"1. Buy product"<<endl;
    cout << setw (81);
    cout<<"2. Go Back"<<endl<<endl;
    cout << setw (89);
    cout<<"Enter your option: ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout<<"Invalid Choice"<<endl;
    }
    goto Customer;
}
void shopping :: add()
{

    Add: fstream data;
     int c;
     int token = 0;
     float p;
     float d;
     string n;
     cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
     cout << setw (88);
     cout<<"Add New Product"<<endl;
     cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
     cout << setw (80);
     cout<<"Product code of the product: ";
     cin>>pcode;
     cout << setw (72);
     cout<<"Name of the product: ";
     cin>>pname;
     cout << setw (73);
     cout<<"Price of the product: ";
     cin>>price;
     cout << setw (76);
     cout<<"Discount of the product: ";
     cin>>discount;
     cout<<endl;

     if(!data)
     {
         data.open("database.txt",ios::in);
         data.open("database.txt", ios::app|ios::out);
         data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"%\n";
         data.close();
     }
     else
     {
         data>>c>>n>>p>>d;
         while(!data.eof())
           {
             if(c == pcode)
             {
                 token++;
             }
             data>>c>>n>>p>>d;
           }
        data.close();

     if(token == 1)
        goto Add;
     else
     {
         data.open("database.txt", ios::app|ios::out);
         data<<"\t\t\t"<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<price<<"\t\t\t"<<discount<<"%\n";
         data.close();
     }
 }
  cout << setw (88);
  cout<<"Record inserted"<<endl<<endl;
}
void shopping::rem()
{
    int no;
    cout<<setw(91);
    cout<<"Enter item code to delete: ";
    cin>>no;
    ofstream file2;
    file2.open("new.dat", ios::out|ios::binary);
    data.open("database.dat", ios::in|ios::binary);
    if(!data)
    {
        cout<<setw(88);
        cout<<"File not found";
        exit(0);
    }
    else{
        data.read((char*)&it, sizeof(it));
        while(!data.eof())
        {
            if(no!=it.get_code())
            {
                file2.write((char*)&it, sizeof(it));
            }
            data.read((char*)&it, sizeof(it));
            
        }

    }
    file2.close();
    data.close();
    remove("database.dat");
    rename("new.dat","database.dat");
}
