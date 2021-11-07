#include <iostream>
#include <conio.h> //chk_pass Function
#include <fstream> //File Handling
#include <vector> //Split to Data Array
#include <sstream> //String Stream
using namespace std;
//Function Declare

//Loading and Login Interface Functions
void splash_screen(); //Loading Screen
int login();//int because return 0

//Main User Menu :: Set Password and Call Sub Menu
void owner();
void supplier();
void buyer();

//Main Users Sub Menu
int owner_menu(); //int because return 0
int supplier_menu(); //int because return 0
int buyer_menu(); //int because return 0

//Owner Menu Function
int stock_view();
int stock_edit();
void buy_request();
void orders();

//Stock Edit Sub Menu
void insert_items();
void update_items();
void delete_items();

//Buyer >> Buyer Menu >> Sell Request
void buy_sell_req();

//Supplier >> Supplier Menu >> Sell Request
void sup_sell_req();

//Stock Show
void show_stock();

//Get File Line Count
int line_count(string file);

//Password Checking
bool chk_pass (string u_name,string u_pass);

void splash_screen()
{
    system("color b");
    cout <<"\t\t\t"<< "                                            "<< endl;
    cout <<"\t\t\t"<< " /$$$$$$       /$$      /$$        /$$$$$$  "<< endl;
    cout <<"\t\t\t"<< "|_  $$_/      | $$$    /$$$       /$$__  $$ "<< endl;
    cout <<"\t\t\t"<< "  | $$        | $$$$  /$$$$      | $$  \__/ "<< endl;
    cout <<"\t\t\t"<< "  | $$        | $$ $$/$$ $$      |  $$$$$$  "<< endl;
    cout <<"\t\t\t"<< "  | $$        | $$  $$$| $$       \____  $$ "<< endl;
    cout <<"\t\t\t"<< "  | $$        | $$\  $ | $$       /$$  \ $$ "<< endl;
    cout <<"\t\t\t"<< " /$$$$$$      | $$ \/  | $$      |  $$$$$$/ "<< endl;
    cout <<"\t\t\t"<< "|______/      |__/     |__/       \______/  "<< endl;
    cout <<"\t\t\t"<< " ------------------------------------------ " <<"\t\t\t"<< endl;
    cout <<"\t\t\t"<< "        Inventory Management System         "<< endl;
    cout << " \n \n Press any key to continue.";
    getch();
    system("cls");
}

int login()
{
    int dpy_chs;
    system("color a");//Set Color To Green
    cout << "\n\t Inventory Management System"<< endl;
    cout << "--------------------------------------------" << endl;
    cout << "\t 1. Owner \n";
    cout << "\t 2. Supplier \n";
    cout << "\t 3. Buyer \n";
    cout << "\t 4. Exit \n";
    cout << "--------------------------------------------" << endl;
    cout << " Enter your choice :- " ;
    cin>>dpy_chs;

    switch(dpy_chs)
    {
    case 1:
        system("cls");
        owner();
        break;
    case 2:
        system("cls");
        supplier();
        break;
    case 3:
        system("cls");
        buyer();
        break;
    case 4:
        system("cls");
        cout << " Program Will Be Terminated.. !" ;
        getch();
        return 0;
        break;

    default:
        cout << " Selection not valid !" ;
        getch();
        return 0;
        break;
    }
}

//Owner Login Menu
void owner()
{
    cout << "          Welcome ! , Owner, For the IMS!         \n"<< endl;
    cout << "                System Time: ";
    system("time /t");
    cout<<endl;
    cout << "        Dear owner, you will have the full access    "<<endl;
    cout << "           to this inventory management system.       \n"<<endl;
    if(chk_pass("owner","owner12")==true )
    {
        getch();
        system("cls");
        owner_menu();
    }
}

//Supplier Login Menu
void supplier()
{
    cout << "          Welcome ! , Supplier, For the IMS!         \n"<< endl;
    cout << "                System Time: ";
    system("time /t");
    cout<<endl;
    if(chk_pass("supplier","supplier12")==true )
    {
        getch();
        system("cls");
        supplier_menu();
    }
}

//Buyer Login Menu
void buyer()
{
    cout << "          Welcome ! , Buyer, For the IMS!         \n"<< endl;
    cout << "                System Time: ";
    system("time /t");
    cout<<endl;

    if(chk_pass("buyer","buyer12")==true )
    {
        getch();
        system("cls");
        buyer_menu();
    }
}

//Owner Sub Menu
int owner_menu()
{
    int dpy_chs;
    cout << "-----------------> Owner <------------------"<< endl;
    cout << "\t 1. Stock View  \n";
    cout << "\t 2. Stock Edit  \n";
    cout << "\t 3. Buy Request \n";
    cout << "\t 4. Orders \n";
    cout << "\t 5. Exit \n";
    cout << "--------------------------------------------" << endl;
    cout << " Enter your choice :- " ;
    cin>>dpy_chs;

    switch(dpy_chs)
    {
    case 1:
        system("cls");
        stock_view();
        break;
    case 2:
        system("cls");
        stock_edit();
        break;
    case 3:
        system("cls");
        buy_request();
        break;
    case 4:
        system("cls");
        orders();
        break;
    case 5:
        system("cls");
        cout << " Program Will Be Terminated.. !" ;
        getch();
        return 0;
        break;
    default:
        cout << " Selection not valid !" ;
        getch();
        cout << "\n Program Will Be Terminated.. !" ;
        getch();
        system("cls");
        return 0;
        break;
    }
}
//Supplier Sub Menu
int supplier_menu()
{
    int dpy_chs;
    cout << "-----------------> Supplier <------------------"<< endl;
    cout << "\t 1. Sell Request  \n";
    cout << "\t 2. Exit \n";
    cout << "--------------------------------------------" << endl;
    cout << "Enter your choice :- " ;
    cin>>dpy_chs;
    switch(dpy_chs)
    {
    case 1:
        system("cls");
        sup_sell_req();
        break;
    case 2:
        system("cls");
        cout << " Program Will Be Terminated.. !" ;
        getch();
        return 0;
        break;

    default:
        cout << " Selection not valid !" ;
        getch();
        cout << "\n Program Will Be Terminated.. !" ;
        getch();
        system("cls");
        return 0;
        break;
    }
}
//Buyer Sub Menu
int buyer_menu()
{
    int dpy_chs;
    cout << "-----------------> Buyer <------------------"<< endl;
    cout << "\t 1. Buy Request  \n";
    cout << "\t 2. Exit \n";
    cout << "--------------------------------------------" << endl;
    cout << "Enter your choice :- " ;
    cin>>dpy_chs;
    switch(dpy_chs)
    {
    case 1:
        system("cls");
        buy_sell_req();
        break;
    case 2:
        system("cls");
        cout << " Program Will Be Terminated.. !" ;
        getch();
        return 0;
        break;
    default:
        cout << " Selection not valid !" ;
        getch();
        cout << "\n Program Will Be Terminated.. !" ;
        getch();
        system("cls");
        return 0;
        break;
    }
}

// Owner >> Owner Menu >> Stock View
int stock_view()
{
    show_stock();
    cout << " \n Press any key to continue.";
    getch();
    system("cls");
    owner_menu();
}
// Owner >> Owner Menu >> Stock Edit
int stock_edit()
{
    int dpy_chs;
    cout << "-----------------> Stock Edit <------------------"<< endl;
    cout << "\t 1. Insert New Items  \n";
    cout << "\t 2. Update items  \n";
    cout << "\t 3. Delete items \n";
    cout << "\t 4. Back To Main Menu  \n";
    cout << "-------------------------------------------------" << endl;
    cout << "Enter your choice :- " ;
    cin>>dpy_chs;
    switch(dpy_chs)
    {
    case 1:
        system("cls");
        insert_items();
        break;
    case 2:
        system("cls");
        update_items();
        break;
    case 3:
        system("cls");
        delete_items();
        break;
    case 4:
        system("cls");
        owner_menu();
        break;
    default:
        cout << " Selection not valid !" ;
        getch();
        cout << "\n Program Will Be Terminated.. !" ;
        getch();
        system("cls");
        return 0;
        break;
    }
}
// Owner >> Owner Menu >> Stock Edit >> Insert Items
void insert_items()
{

    int lc =(line_count("stock.csv")+1);
    string id,name,price,qty,m_date,e_date;
    string stock_v[lc][6];
    string line;
    int c=0;
    ifstream datafile ("stock.csv");
    if (datafile.is_open())
    {
        while ( getline (datafile,line) )
        {
            vector<string> result;
            stringstream s_stream(line);
            while(s_stream.good())
            {
                string substr;
                getline(s_stream, substr, ',');
                result.push_back(substr);
            }
            for(int i = 0; i<(result.size()-1); i++)
            {
                stock_v[c][i]=result.at(i);
            }
            c=c+1;
        }
        datafile.close();
    }
    else cout << " Unable to open file";

    cout << "--------------------------> Insert New Items  <--------------------------- \n"<< endl;
    cout << " Enter the product ID : #";
    cin >> id;
    cout << "\n Enter the name of the product : ";
    cin >> name;
    cout << " Enter the price of each product : LKR ";
    cin >> price;
    cout << " Enter the quantity of products : ";
    cin >> qty;
    cout << " Enter the manufacturing date(YYYY-MM-DD) : ";
    cin >> m_date;
    cout << " Enter the expiring date(YYYY-MM-DD) : ";
    cin >> e_date;
    id="#"+id;
    price="LKR "+price;
    stock_v[(lc-1)][0]= id;
    stock_v[(lc-1)][1]=name;
    stock_v[(lc-1)][2]=price;
    stock_v[(lc-1)][3]=qty;
    stock_v[(lc-1)][4]=m_date;
    stock_v[(lc-1)][5]=e_date;

    ofstream update_file;
    update_file.open ("stock.csv");

    for(int c = 0; c<lc; c++)
    {
        string w_line;
        w_line.append(stock_v[c][0]);
        w_line.append(",");
        w_line.append(stock_v[c][1]);
        w_line.append(",");
        w_line.append(stock_v[c][2]);
        w_line.append(",");
        w_line.append(stock_v[c][3]);
        w_line.append(",");
        w_line.append(stock_v[c][4]);
        w_line.append(",");
        w_line.append(stock_v[c][5]);
        w_line.append(",");
        update_file <<w_line<<endl;
    }
    cout << " \n Press any key to continue.";
    getch();

    system("cls");
    stock_view();

}

// Owner >> Owner Menu >> Stock Edit >> Update Items
void update_items()
{
    string id,name,price,qty,m_date,e_date;
    string stock_v[line_count("stock.csv") ][6];
    string line;
    int c=0;
    ifstream datafile ("stock.csv");
    if (datafile.is_open())
    {
        cout << "ID\tName\t\tU_Price\t\tQty\tM_Date\t\tE_Date\t"<<"\n";
        cout << "-------------------------------------------------------------------------- \n";
        while ( getline (datafile,line) )
        {
            vector<string> result;
            stringstream s_stream(line);
            while(s_stream.good())
            {
                string substr;
                getline(s_stream, substr, ',');
                result.push_back(substr);
            }
            for(int i = 0; i<(result.size()-1); i++)
            {
                stock_v[c][i]=result.at(i);
            }

            cout << stock_v[c][0]<<"\t";
            cout << stock_v[c][1]<<"\t\t";
            cout << stock_v[c][2]<<"\t\t";
            cout << stock_v[c][3]<<"\t";
            cout << stock_v[c][4]<<"\t";
            cout << stock_v[c][5]<<"\t";

            cout <<endl;
            cout << "-------------------------------------------------------------------------- \n";
            c=c+1;
        }
        datafile.close();
    }
    else cout << " Unable to open file";

    cout << " \n \n"<< endl;
    cout << "-------------------------------------------------------------------------- \n"<< endl;
    cout << "-----------------------------> Update items <----------------------------- \n"<< endl;
    cout << " Enter the product ID : #";
    cin >> id;
    cout << "\n Enter the name of the product : ";
    cin >> name;
    cout << " Enter the price of each product : LKR ";
    cin >> price;
    cout << " Enter the quantity of products : ";
    cin >> qty;
    cout << " Enter the manufacturing date(YYYY-MM-DD) : ";
    cin >> m_date;
    cout << " Enter the expiring date(YYYY-MM-DD) : ";
    cin >> e_date;
    id="#"+id;
    price="LKR "+price;
    for(int c = 0; c< (line_count("stock.csv")); c++)
    {
        if ( stock_v[c][0]== id)
        {
            stock_v[c][1]=name;
            stock_v[c][2]=price;
            stock_v[c][3]=qty;
            stock_v[c][4]=m_date;
            stock_v[c][5]=e_date;
        }
    }
    int lc =line_count("stock.csv");

    ofstream update_file;
    update_file.open ("stock.csv");

    for(int c = 0; c<lc; c++)
    {
        string w_line;
        w_line.append(stock_v[c][0]);
        w_line.append(",");
        w_line.append(stock_v[c][1]);
        w_line.append(",");
        w_line.append(stock_v[c][2]);
        w_line.append(",");
        w_line.append(stock_v[c][3]);
        w_line.append(",");
        w_line.append(stock_v[c][4]);
        w_line.append(",");
        w_line.append(stock_v[c][5]);
        w_line.append(",");
        update_file <<w_line<<endl;
    }
    cout << " \n Press any key to continue.";
    getch();

    system("cls");
    stock_view();
}

// Owner >> Owner Menu >> Stock Edit >> Delete Items
void delete_items()
{
    string id,name,price,qty,m_date,e_date;
    string stock_v[line_count("stock.csv") ][6];
    string line;
    int c=0;
    ifstream datafile ("stock.csv");
    if (datafile.is_open())
    {
        cout << "ID\tName\t\tU_Price\t\tQty\tM_Date\t\tE_Date\t"<<"\n";
        cout << "-------------------------------------------------------------------------- \n";
        while ( getline (datafile,line) )
        {
            vector<string> result;
            stringstream s_stream(line);
            while(s_stream.good())
            {
                string substr;
                getline(s_stream, substr, ',');
                result.push_back(substr);
            }
            for(int i = 0; i<(result.size()-1); i++)
            {
                stock_v[c][i]=result.at(i);
            }

            cout << stock_v[c][0]<<"\t";
            cout << stock_v[c][1]<<"\t\t";
            cout << stock_v[c][2]<<"\t\t";
            cout << stock_v[c][3]<<"\t";
            cout << stock_v[c][4]<<"\t";
            cout << stock_v[c][5]<<"\t";

            cout <<endl;
            cout << "-------------------------------------------------------------------------- \n";
            c=c+1;
        }
        datafile.close();
    }
    else cout << " Unable to open file";
    cout << "\n \n"<< endl;
    cout << "-----------------------------> Delete items <----------------------------- \n"<< endl;
    cout << " Enter the product ID : #";
    cin >> id;
    id="#"+id;
    for(int c = 0; c< (line_count("stock.csv")); c++)
    {
        if ( stock_v[c][0]== id)
        {
            stock_v[c][0]="Delete";
        }
    }
    int lc =line_count("stock.csv");
    ofstream update_file;
    update_file.open ("stock.csv");

    for(int c = 0; c<lc; c++)
    {
        if(stock_v[c][0]!="Delete")
        {
            string w_line;
            w_line.append(stock_v[c][0]);
            w_line.append(",");
            w_line.append(stock_v[c][1]);
            w_line.append(",");
            w_line.append(stock_v[c][2]);
            w_line.append(",");
            w_line.append(stock_v[c][3]);
            w_line.append(",");
            w_line.append(stock_v[c][4]);
            w_line.append(",");
            w_line.append(stock_v[c][5]);
            w_line.append(",");
            update_file <<w_line<<endl;
        }
    }
    cout << " \n Press any key to continue.";
    getch();
    system("cls");
    stock_view();

}

// Owner >> Owner Menu >> Buy Request
void buy_request()
{
    show_stock();
    ofstream buyreq;
    buyreq.open ("buyreq.csv",std::ios_base::app);
    string r_id,r_qty;
    cout << " \n ----------------------------->New Buy Request<--------------------------- \n";
    cout << " Enter the product ID                    : #";
    cin >> r_id;
    cout << " Enter the Quantity Of Products          :  ";
    cin >> r_qty;

    buyreq << "#"<<r_id <<","<<r_qty<<","<<"\n";
    buyreq.close();


    cout << " \n Insert Successfully .";
    cout << " \n Press any key to continue.";
    getch();
    system("cls");
    owner_menu();
}

// Owner >> Owner Menu >> Orders
void orders()
{
    string id,name,price,qty,m_date,e_date;
    string stock_v[line_count("sellreq.csv") ][6];
    string line;
    int c=0;
    ifstream datafile ("sellreq.csv");
    if (datafile.is_open())
    {
        cout << " ID\t\tQty"<<"\n";
        cout << "-------------------------- \n";
        while ( getline (datafile,line) )
        {
            vector<string> result;
            stringstream s_stream(line);
            while(s_stream.good())
            {
                string substr;
                getline(s_stream, substr, ',');
                result.push_back(substr);
            }
            for(int i = 0; i<(result.size()-1); i++)
            {
                stock_v[c][i]=result.at(i);
            }

            for(int i = 0; i<2; i++)
            {
                cout<<" ";
                cout << stock_v[c][i]<<"\t\t";
            }
            cout <<endl;
            c=c+1;
        }
        datafile.close();
    }

    else cout << "Unable to open file";
    cout << " \n Press any key to continue.";
    getch();
    system("cls");
    owner_menu();
}

//Supplier >> Supplier Menu >> Sell Request
void sup_sell_req()
{

    string id,name,price,qty,m_date,e_date;
    string stock_v[line_count("buyreq.csv") ][6];
    string line;
    int c=0;
    ifstream datafile ("buyreq.csv");
    if (datafile.is_open())
    {
        cout << " ID\t\tQty"<<"\n";
        cout << "-------------------------- \n";
        while ( getline (datafile,line) )
        {
            vector<string> result;
            stringstream s_stream(line);
            while(s_stream.good())
            {
                string substr;
                getline(s_stream, substr, ',');
                result.push_back(substr);
            }
            for(int i = 0; i<(result.size()-1); i++)
            {
                stock_v[c][i]=result.at(i);
            }

            for(int i = 0; i<2; i++)
            {
                cout<<" ";
                cout << stock_v[c][i]<<"\t\t";
            }
            cout <<endl;
            c=c+1;
        }
        datafile.close();
    }

    else cout << "Unable to open file";
    cout << " \n Press any key to continue.";
    getch();
    system("cls");
    supplier_menu();

}

//Buyer >> Buyer Menu >> Sell Request
void buy_sell_req()
{
    show_stock();
    ofstream sellreq;
    sellreq.open ("sellreq.csv",std::ios_base::app);
    string r_id,r_qty;
    cout << "\n---------------------------->New Buy Request<----------------------------- \n";
    cout << " Enter the product ID                    : #";
    cin >> r_id;
    cout << " Enter the Quantity Of Products          : ";
    cin >> r_qty;

    sellreq <<"#1"<< r_id <<","<<r_qty<<","<<"\n";
    sellreq.close();

    cout << " \n Insert Successfully .";
    cout << " \n Press any key to continue.";
    getch();
    system("cls");
    buyer_menu();
}


void show_stock()
{
    string stock_v[line_count("stock.csv") ][6];
    string line;
    int c=0;
    ifstream datafile ("stock.csv");
    if (datafile.is_open())
    {
        cout << "ID\tName\t\tU_Price\t\tQty\tM_Date\t\tE_Date\t"<<"\n";
        cout << "-------------------------------------------------------------------------- \n";
        while ( getline (datafile,line) )
        {
            vector<string> result;
            stringstream s_stream(line);
            while(s_stream.good())
            {
                string substr;
                getline(s_stream, substr, ',');
                result.push_back(substr);
            }
            for(int i = 0; i<(result.size()-1); i++)
            {
                stock_v[c][i]=result.at(i);
            }

            cout << stock_v[c][0]<<"\t";
            cout << stock_v[c][1]<<"\t\t";
            cout << stock_v[c][2]<<"\t\t";
            cout << stock_v[c][3]<<"\t";
            cout << stock_v[c][4]<<"\t";
            cout << stock_v[c][5]<<"\t";

            cout <<endl;
            cout << "-------------------------------------------------------------------------- \n";
            c=c+1;
        }
        datafile.close();
    }
    else cout << " Unable to open file";
}

//Get File Line Count
int line_count(string file)
{
    string line;
    int i;
    ifstream count_file (file);
    if (count_file.is_open())
    {
        while ( getline (count_file,line) )i++;
        return i;
        count_file.close();
    }
    else cout << "Unable to Open File";
}

//Password Checking [u_name = user Name , u_pass = User Password ]
//We Use Bool For Function return Data Type
bool chk_pass (string u_name,string u_pass)
{
    string input_uname;
    char eoc;//exit or continue
    cout << "Please Enter Your UserName -  : " ;
    //User Name input
    cin >>input_uname;
    cout << "Please Enter Your Password  -  : " ;
    //Password length
    int pl=u_pass.length();
    char p[(pl)] ;
    for (int i = 0; i < pl; i++)
    {
        p[i] = getch();
        putch('*');
        //If password length = to char array;
        if (p[i] == pl) break;
    };
    //Put The Line Break
    cout<<endl;
    //P - Typed word = password And input username = input uname
    if ((p==u_pass)&& (input_uname==u_name))
    {
        //Send Value true
        return true;
    }
    //If Username is incorrect
    else if (input_uname!=u_name)
    {
        //Retry Or Exit
        cout<<"Username  is incorrect. Press 'y' to Retry or Press any key to Exit -: ";
        cin>>eoc;
        cout<<endl;

        if (eoc == 'y') return chk_pass(u_name,u_pass);
        else return 0;
    }
    //If Password is incorrect
    else if (p!=u_pass)
    {
        //Retry Or Exit
        cout<<"Password is incorrect. Press 'y' to Retry or Press any key to Exit -: ";
        cin>>eoc;
        cout<<endl;

        if (eoc == 'y') return chk_pass(u_name,u_pass);
        else return 0;
    }
}

int main()
{
    splash_screen();
    login();
    return 0;
}
