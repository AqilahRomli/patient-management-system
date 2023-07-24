#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<unistd.h>
#include <conio.h>
using namespace std;

struct patientinfo //structure bhgn detail
{
  string name;
  int ages;
  long int cont;
  long int Mykad;
};

class Inventory //class bhgn inventory
{
    public:
    string itemName;
    int code;
    int amount;
    double cost;
    void getdata();
    void showdata();
    Inventory();
};

Inventory::Inventory() // class
{
  itemName = "-";
  code= 0;
  amount=0;
  cost = 0;
}

void Inventory :: showdata() //show data
{
    cout<<endl;
    cout.width(15);
    cout.setf(ios::left, ios::adjustfield);
    cout<<itemName;

    cout.width(8);
    cout<<code;
    
    cout.width(8);
    cout<<amount;

    cout.width(15);
    cout.setf(ios::right, ios::adjustfield);
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout<<cost;
}
    
    

void menu();
void choices();
void file();
void displaydetail();
void det();  //function detail
void getpatientinfo (patientinfo *pt_pat); //get data
void invent();
void datamedicine();
void pay();

char oldname[] = "example.txt", newname[]= "file_new.txt", text[]=".txt", user[]="user",k;
string itemName;
int choice,age,numbers=0,i,code,cost,amount,med,newamount,codes;
int choi; //pilihan utk bhgn medicine
int p=100,a=100,c=100,n=100,pr=100; //quantity awal ubat
float payment[5],totalpayment;
long int mykad, con;

int main()
 {
     menu();
     choices();
     
     return 0;
}

void menu()
{
    cout<<"\nWELCOME TO HOSPITAL BAHAGIA\n";
    cout<<"PATIENT MANAGEMENT SYSTEM SYSTEM\n";
    cout<<"\n\n[1] = REGISTER NEW PATIENT";
    cout<<"\n[2] = VIEW EXISTING PATIENT";
    cout<<"\n[3] = PAYMENT";
    cout<<"\n[4] = RESTOCK MEDICINE";
    cout<<"\n[5] = EXIT";
    
    do //loop if enter choice>5 || choice<1
    {
        cout<<"\n\n\nSELECT YOUR CHOICE =  ";
        cin>>choice;
        if (choice>5 || choice<1)
        cout<<"You have entered the wrong number. PLEASE TRY AGAIN!\n";
        
    } while (choice>5 || choice<1);
}
    
void choices()
{
    if (choice==1)
    {
        system("CLS");
        ++numbers;
        det();
        unsigned int microsecond = 1000000;
        usleep(3 * microsecond);//sleeps for 3 second
        cout<<"\nwaiting numbers : "<< setw(4)<<setfill('0')<< numbers << endl;
        cout<<"\nPress ENTER to return to HOMEPAGE...";
        cin.get(k);//holds the screen
        system("CLS");
        main();
    }
    if (choice==2)
    {
        system("CLS");
        ++numbers;
        cout<<"EXISTING PATIENT LOG\n"; //MASUKKAN DLM FILE
        cout<<"\n\nENTER YOUR NICKNAME : ";
        cin>>newname;
        strcat(newname,text);//to combine username with .txt ; newname as variable to file name
        ifstream ifile;
        ifile.open(newname);
        if(ifile)
        {
            cout<<"\nSuccessfully open file";
            cout<<"\n\nPatient detail :\n\n";
            displaydetail(); // keluarkan detail pesakit yang dah daftar
            unsigned int microsecond = 1000000;
            usleep(3 * microsecond);//sleeps for 3 second
            cout<<"waiting numbers : "<< setw(4)<<setfill('0')<< numbers << endl;
            cout<<"\n\nPress ENTER to return to HOMEPAGE...";
            cin.ignore(1,'\n');
            cin.get(k);//holds the screen
            system("CLS");
            main();
        }
        else {
        cout<<"\nPatient is not in the system";
        cout<<"\nPlease register first";
        cout<<"\n\nPress ENTER to return to HOMEPAGE...";
        cin.ignore(1,'\n');
        cin.get(k);//holds the screen
        system("CLS");
        main();
        }
    }
    if (choice==3)
    {
        pay();
        cout<<"\n\nPress ENTER to return to HOMEPAGE...";
        cin.ignore(1,'\n');
        cin.get(k);//holds the screen
        main();
    }
    
    if (choice==4)
    {
        invent();
        cout<<"\n\nPress ENTER to return to HOMEPAGE...";
        cin.ignore(1,'\n');
        cin.get(k);//holds the screen
        system("CLS");
        main();
    }
    
    if (choice==5)
    {
        cout<<"\n\nTHANK YOU FOR USING OUR SYSTEM";
    }
}

void displaydetail()
{
	ifstream myfile (newname);
	while (getline(myfile, profile)) {
    // output the line
    cout <<"\n"<<profile <<endl;
    // now we loop back and get the next line in 'str'
	}
	myfile.close();
}

void det()
{
    cout<<"PATIENT DETAILS\n"; //MASUKKAN DLM FILE
    cout<<"\nNICKNAME  : ";
    cin>>user;
    patientinfo pass;
    getpatientinfo (&pass);
}

void getpatientinfo (patientinfo *pt_pat) //get data
{
    file();
    ofstream myfile;
    myfile.open(newname);
    cout<<"\n\nPlease enter you details below : \n"; //ambil maklumat tentang penyakit pesakit
    cout<<"\nFULLNAME : ";
    cin.ignore(1,'\n');
    getline (cin, pt_pat->name); //guna pointer
    myfile << pt_pat->name <<endl;
    cout<<"\nAGE : ";
    cin>>pt_pat->ages;
    myfile <<pt_pat->ages<< endl;
    cout<<"\n MYKAD NO. (00012345678): ";
 	cin>>pt_pat->Mykad;
 	myfile << setw(12)<<setfill('0')<<pt_pat->Mykad << endl;
    cout<<"\nCONTACT NO. (0123456789): ";
    cin>>pt_pat->cont;
    myfile << setw(11)<<setfill('0')<<pt_pat->cont << endl;
    cin.ignore(1,'\n');
    myfile.close();
    cout<<"\n\nPlease wait for you waiting number be assign";
    unsigned int microsecond = 1000000;
    usleep(3 * microsecond);//sleeps for 3 second 
    cout<<"waiting numbers : "<< setw(4)<<setfill('0')<< numbers << endl;
    cout<<"\n\nPress ENTER to return to HOMEPAGE...";
    cin.ignore(1,'\n');
    cin.get(k);//holds the screen
    system("CLS");
    menu();//bagi nombor giliran ke pesakit
    // delay 3 second and waiting number tekeluar
    // waiting()
}


void file()  // Create and open a text file
{
    ofstream myfile;
    myfile.open("example.txt");
    myfile << "Writing this text to a file." << endl;
    myfile.close();
    strcat(user,text);
    strcpy(newname,user); //save new file name as variable newname.
    /* Deletes the file if exists */
    if (rename(oldname, newname) != 0)
    perror("Error renaming file");
    else
    cout << "\nName successful registered";
}

void pay()
{
    datamedicine();
    cout<<"\n\n\n=====PURCHASE OF MEDICINE=====\n";
    cout<<"\nHow many type of medicine to be buy : ";
    cin>>med;
        
    cout<<"Enter "<< med <<" Medicine\n";
    for(i=0;i<med;i++)
        {
            cout<<"Enter code of medicine to be buy :";
            cin>>codes; //codes medicine to be added
            cout<<"Amount of medicine buy :";
            cin>>newamount;
            
            switch(codes)
            {
                case 1:
                p=p-newamount;
                payment[0]=newamount*3.50;
                break;
                case 2:
                a=a-newamount;
                payment[1]=newamount*4.50;
                break;
                case 3:
                c=c-newamount;
                payment[2]=newamount*5.50;
                break;
                case 4:
                n=n-newamount;
                payment[3]=newamount*3.50;
                break;
                case 5:
                pr=pr-newamount;
                payment[4]=newamount*3.50;
                break;
            }
        }
    cout<<"\n=====NEW DATA=====";
    datamedicine();
    totalpayment=payment[0]+payment[1]+payment[2]+payment[3]+payment[4];
    cout<<"\n\n---------- PAYMENT DETAIL----------";
    cout<<"\nTotal payment : RM "<<totalpayment;
    cout<<"\n\n\nPress ENTER to continue...";
	cin.ignore(1,'\n');
	cin.get(k);//holds the screen
	cout<<"payment receive...\n";
	cout<<"THANK YOU, your payment was successful...\n";
	
}


void invent()
{
    cout<<"MEDICINE INVENTORY SYSTEM\n";
        datamedicine();
        cout<<"\n=====Inventory Management=====\n";
        cout<<"\nHow many type of medicine to be added : ";
        cin>>med;
        
        cout<<"Enter "<< med <<" Medicine\n";
        for(i=0;i<med;i++)
        {
            cout<<"Enter code of medicine to be added :";
            cin>>codes; //codes medicine to be added
            cout<<"Amount of medicine added :";
            cin>>newamount;
            switch(codes)
            {
                case 1:
                p=p+newamount;
                break;
                case 2:
                a=a+newamount;
                break;
                case 3:
                c=c+newamount;
                break;
                case 4:
                n=n+newamount;
                break;
                case 5:
                pr=pr+newamount;
                break;
                
            }
        }
        
        cout<<"\n=====NEW DATA=====";
        datamedicine();
}


void datamedicine() //showdata ubat
{
    Inventory new1_Inventory;
    Inventory new2_Inventory;
    Inventory new3_Inventory;
    Inventory new4_Inventory;
    Inventory new5_Inventory;
    
        new1_Inventory.itemName="Parasetamol";
        new1_Inventory.code=1;
        new1_Inventory.amount= p;
        new1_Inventory.cost=3.50;
        
        new2_Inventory.itemName="Aspirin";
        new2_Inventory.code=2;
        new2_Inventory.amount=a;
        new2_Inventory.cost=4.50;
        
        new3_Inventory.itemName="Calcium";
        new3_Inventory.code=3;
        new3_Inventory.amount= c;
        new3_Inventory.cost=5.50;
        
        new4_Inventory.itemName="Neurontin";
        new4_Inventory.code=4;
        new4_Inventory.amount=n;
        new4_Inventory.cost=3.50;
        
        new5_Inventory.itemName="Prinivil";
        new5_Inventory.code=5;
        new5_Inventory.amount= pr;
        new5_Inventory.cost=6.50;
        
    
    cout<<"\n\n------------------Stock Information------------------\n"; //medicine stock
    cout<<"\n"<<setw(8)<<"Item Name"
        <<setw(10)<<"Code"
        <<setw(10)<<"Amount"
        <<setw(17)<<"Cost"<<endl;
    cout<<"-----------------------------------------------------\n";
    
    new1_Inventory.showdata();
    new2_Inventory.showdata();
    new3_Inventory.showdata();
    new4_Inventory.showdata();
    new5_Inventory.showdata();
    cout<<"\n-----------------------------------------------------\n";
}















