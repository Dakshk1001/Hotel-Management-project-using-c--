#include <iostream>
#include <fstream>
using namespace std;
class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t_____________________________\n";
    cout << "\t\t\t\t                             \n";
    cout << "\t\t\t\t       Super Market Menu     \n";
    cout << "\t\t\t\t                             \n";
    cout << "\t\t\t\t_____________________________\n";
    cout << "\t\t\t\t                             \n";
    cout << "\t\t\t\t    1) Administrator         \n";
    cout << "\t\t\t\t    2) Buyer                 \n";
    cout << "\t\t\t\t    3) Exit                  \n";
    cout << "\t\t\t\t                             \n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t Please Login\n";
        cout << "\t\t\t\t Enter Email\n";
        cin >> email;
        cout << "\t\t\t\t Enter Password\n";
        cin >> password;

        if (email == "robby@email.com" && password == "robby@123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email/password";
        }

        break;

    case 2:
    {
        buyer();
    }
    break;
    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please select from the given options";
    }
    }
    goto m;
}
void shopping::administrator()
{
    int choice;
    cout << "\n\n\t\t\t\t     Administrator Menu        ";
    cout << "\n\t\t\t\t  1)Add the product           \n";
    cout << "\n\t\t\t\t  2)Modify the product          \n";
    cout << "\n\t\t\t\t  3)Delete the product         \n";
    cout << "\n\t\t\t\t  4)Back to menu          \n";
    cout << "\n\t\t\t Please enter your choice            \n";

    cin >> choice;
    switch (choice)
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
        cout << "invalid choice";
        break;
    }
}
void shopping::buyer()
{
m:
    int choice;
    cout << "\n\n\t\t\t\t     Buyer       ";
    cout << "\n\t\t\t\t          \n";
    cout << "\n\t\t\t\t 1) Buy Product        \n";
    cout << "\n\t\t\t\t          \n";
    cout << "\n\t\t\t\t 2)Go back        \n";

    cout << "\n\t\t\t Please enter your choice            \n";

    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;

    default:
        cout << "invalid choice";
        break;
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t\t     Add New Product        ";
    cout << "\n\t\t\t\t  Enter the product code          \n";
    cin >> pcode;
    cout << "\n\t\t\t\t  Name the product          \n";
    cin >> pname;
    cout << "\n\t\t\t\t  Price the product         \n";
    cin >> price;
    cout << "\n\t\t\t\t  Discount the product          \n";
    cin >> dis;

    data.open("databse.txt", ios::in);
    if (!data)
    {
        data.open("databse.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1)
        goto m;
    else
    {
        data.open("databse.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    cout << "\n\n\t\t Record Inserted";
}
void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t\t     Modify the product       ";
    cout << "\n\t\t\t\t  Enter the product code          \n";
    cin >> pkey;

    data.open("databse.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data.open("databse1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t\t\t  Enter the new product code          \n";
                cin >> pcode;
                cout << "\n\t\t\t\t  Name the product          \n";
                cin >> pname;
                cout << "\n\t\t\t\t  Price the product         \n";
                cin >> price;
                cout << "\n\t\t\t\t  Discount the product          \n";
                cin >> dis;
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                cout << "\n\n\t Record edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
    if (token == 0)

        cout << "\n\n\t\t Record not found!!";
}

void shopping::rem()
{
    fstream data, data1;
    int c;
    int token = 0;
    int pkey;
    cout << "\n\n\t\t\t\t     Delete the product        ";
    cout << "\n\t\t\t\t  Enter the product code          \n";
    cin >> pcode;

    data.open("databse.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data.open("databse1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product delelted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\nRecord not found";
        }
    }
}
void shopping::list()
{
    fstream data;
    data.open("databse.txt", ios::in);
    cout << "\n\n|______________________________________       ";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|______________________________________       ";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t\t";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shopping::receipt()

{
m:
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    int total;
    cout << "\n\n\t\t\t RECEIPT";
    data.open("databse.txt", ios::in);
    if (!data)
    {
        cout << "Data doesn't exist";
    }
    else
    {
        data.close();
        list();
        cout << "\n______________________\n";
        cout << "\n |                     \n";
        cout << "\n     Please place the order \n";
        cout << "\n |                     \n";
        cout << "\n______________________\n";
        do
        {
            cout << "\n\n ENter the product code";
            cin >> arrc[c];

            cout << "\n\n ENter the product quantity";
            cin >> arrc[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product ,please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? if yer then press y else no";
            cin >> choice;
        } while (choice == "y");
        cout << "\n\n\t\t\t ________________RECEIPT_______________";
        cout << "\nProductNo\tProduct Name\tProduct quantity\tprice\tAmount\tAmount with discount\n";
        for (int i = 0; i < c; i++)
        {
            data.open("databse.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n______________________\n";
    cout << "\n Total Amount: " << total;
}
int main()
{
    shopping s;
    s.menu();
}