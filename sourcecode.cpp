#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <conio.h>
using namespace std;

void item :: get_item(void)
{
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
     cout << setw (88);
     cout<<"Add New Product"<<endl;
     cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
     cout << setw (80);
     cout<<"Product code of the product: ";
     cin>>pcode;
     cout << setw (72);
     cout<<"Name of the product: ";
     cin>>name;
     cout << setw (73);
     cout<<"Price of the product: ";
     cin>>price;
     cout << setw (76);
     cout<<"Discount of the product: ";
     cin>>discount;
     cout<<endl;
}
void item :: put_item (void)
{

    cout<<setw(65)<<pcode<<setw(10)<<name<<setw(10)<<price<<setw(12)<<discount<<endl;

}
item it;
fstream file;

void item:: add_record()
{
    char ch='y';
    file.open("stock.dat", ios::app | ios::binary);
    while(ch=='y'||ch=='Y')
    {
    it.get_item();

    file.write((char*)&it, sizeof(it));
    cout<<setw(85);
    cout<<"Add more records..(y/n)? ";
    cin>>ch;
    cout<<endl;
}
file.close();
}
void item::show_all(void)
{
    file.open("stock.dat", ios::in | ios::binary);
    if(!file)
    {
        cout<<setw(85);
        cout<<"File not found";
        exit(0);
    }
    else
    {
        file.read((char*)&it, sizeof(it));
        cout<<endl;
        cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
        cout << setw (88);
        cout<<"Product Details"<<endl;
        cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
        cout<<setw(67)<<"CODE"<<setw(10)<<"NAME"<<setw(10)<<"PRICE"<<setw(12)<<"DISCOUNT"<<endl;
        while(! file.eof())
        {

            it.put_item();
            file.read((char*)&it, sizeof(it));
        }
        cout<<endl;
    }
    file.close();
}
void item:: show_record(void)
{
    int no, flag=0;
    file.open("stock.dat", ios::in|ios::binary);
    if(!file)
    {
        cout<<setw(85);
        cout<<"File not found";
        exit(0);
    }
    else
    {
        cout<<setw(95);
        cout<<"Enter Product code to search: ";
        cin>>no;
        file.read((char*)&it, sizeof(it));
        while(!file.eof())
        {
            if(no==it.get_code())
            {
                flag=1;
                cout<<endl;
                cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
                cout << setw (88);
                cout<<"Product Details"<<endl;
                cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
                cout<<setw(67)<<"CODE"<<setw(10)<<"NAME"<<setw(10)<<"PRICE"<<setw(12)<<"DISCOUNT"<<endl;
                it.put_item();
                break;
            }
            file.read((char*)&it, sizeof(it));
        }
        if(flag==0)
        {
            cout<<endl;
            cout<<setw(88);
            cout<<"Product not found!\n";
            cout<<endl;
        }
    }
    file.close();
}

void item :: delete_record()
{
    int no,flag=0;
    cout<<setw(95);
    cout<<"Enter Product code to delete: ";
    cin>>no;
    ofstream file2;
    file2.open("new.dat", ios::out|ios::binary);
    file.open("stock.dat", ios::in|ios::binary);
    if(!file)
    {
        cout<<setw(85);
        cout<<"File not found";
        exit(0);
    }
    else{
        file.read((char*)&it, sizeof(it));
        while(!file.eof())
        {
            if(no!=it.get_code())
            {
                flag=1;
                file2.write((char*)&it, sizeof(it));
            }
            file.read((char*)&it, sizeof(it));
        }
    }

    file2.close();
    file.close();
    remove("stock.dat");
    rename("new.dat","stock.dat");

}






void item :: admin()
{
    Admin:
    int choice;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (85);
    cout<<"Admin Page"<<endl;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (83);
    cout<<"1. Add product details"<<endl;
    cout << setw (87);
    cout<<"2. Display product details"<<endl;
    cout << setw (97);
    cout<<"3. Display particular product detail"<<endl;
    cout << setw (86);
    cout<<"4. Modify product details"<<endl;
    cout << setw (86);
    cout<<"5. Delete product details"<<endl;
    cout << setw (84);
    cout<<"6. Go Back to main menu"<<endl<<endl;
    cout << setw (93);
    cout<<"Please enter your option: ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        add_record();
        break;
    case 2:
        show_all();
        break;
    case 3:
        show_record();
        break;
    case 4:
        modify_record();
        break;
    case 5:
        delete_record();
        break;
    case 6:
        menu();
        break;
    default:
        cout<<setw(85);
        cout<<"Invalid choice";
    }
   goto Admin;
}
void item :: customer()
{
    Customer:
    int choice;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (85);
    cout<<"Customer Page"<<endl;
    cout<<"\t\t\t\t\t\t--------------------------------------------------------------"<<endl;
    cout << setw (85);
    cout<<"1. Buy product"<<endl;
    cout<<setw(85);
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
void item :: menu()
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
