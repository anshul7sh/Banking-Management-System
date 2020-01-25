#define _CRT_SECURE_NO_WARNINGS

// PASSWORD FOR ADMINISTRATION PORTAL IS 123456789 
// PASSWORD FOR ADMINISTRATION PORTAL IS 123456789 
// PASSWORD FOR ADMINISTRATION PORTAL IS 123456789 

#include<iostream>
#include<fstream> 
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>

using namespace std;

int adminchoice();
int choice();
void add_member();
void display_spm();
void delete_member();
void display_allm();
void view_balance();
void issue_loan();
void deposit_loan();
void adminportal();

fstream fp;
char character[1];

int choice()
{
    cout << "\033[2J\033[1;1H";
    cout<<"\t 1.View balance."<<endl;
    cout<<"\t 2.Administration Portal."<<endl;
    cout<<"\t 3.Exit."<<endl;
    cout<<"\n\n\t\t\tEnter your choice number."<<endl;
    int n;
    cin>>n;

    return n;
}

int adminchoice()
{
    cout << "\033[2J\033[1;1H";
    cout<<"\t 1.Add member."<<endl;
    cout<<"\t 2.Remove member."<<endl;
    cout<<"\t 3.Modify member details."<<endl;
    cout<<"\t 4.Show specific member."<<endl;
    cout<<"\t 5.Show all members."<<endl;
    cout<<"\t 6.Issue loan."<<endl;
    cout<<"\t 7.Deposit loan."<<endl;
    cout<<"\t 8.Main menu."<<endl;

    cout<<"\n\n\t\t\tEnter your choice number."<<endl;
    int n;
    cin>>n;

    return n;
}

class member
{
    char name[30];
    char accno[6];
    char phono[10];
    int balance;
    int token;
    float loan;
    int amount;

public:
    void create_member()
    {
        cout << "\033[2J\033[1;1H";
        cout<<"\n NEW MEMBER ENTERY PORTAL...\n";
        cout<<" Enter member name."<<endl;
        cin.getline(character,1);
        cin.getline(name,30);
        cout<<"\n Enter new acc number to alloacte."<<endl;
        cin>>accno;
        cout<<"\n Enter member's contact number."<<endl;
        cin>>phono;
        cout<<"\n Enter initial balance added(Min balance should be Rs.1000)."<<endl;
        cin>>balance;
        while(balance<999)
        {
            cout<<"\nWarning Minimum balance should be Rs.1000."<<endl;
            cout<<"\n Enter initial balance added(Min balance should be Rs.1000).";
            cin>>balance;
        }
        cout<<"\n Is member want loan(Y/N)."<<endl;
        char ch;
        cin>>ch;

        if(ch=='y'||ch=='Y')
        {
            cout<<"Intrest will be 5% Simple intrest."<<endl;
            cout<<"Enter amount of loan to sansation."<<endl;
            cin>>loan;
            cout<<"Enter period of loan."<<endl;
            int period;
            cin>>period;

            loan=loan+(float)loan*period*5/100;

            cout<<"\nAmount paid after "<<period<<" years is "<<loan<<"."<<endl;
            token=1;
            
            cout<<"\n LOAN SANSATION SUCCESSFULLY...\n\n"<<endl;
        }

        else
        {
            token=0;
            loan=0;
        }

        cout<<"\n\n\t\t\tMEMBER ADDED SUCCESSFULLY...\n";
    }

    void show_member()
    {
        cout<<"\n\n\t\tMEMBER DETAILS..."<<endl;
        cout<<"\nAccount number:"<<accno;
        cout<<"\nMember Name: ";
        puts(name);
        cout<<"\nBalance:"<<balance;
        cout<<"\nMember contact number:"<<phono;
        if(token!=0)
            cout<<"\nAmount to paid as loan:"<<loan;

        cout<<"\n\n\t\tMEMBER DETAILS END...\n";
    }

    int modify_member()
    {
        cout<<"\nADD(A) OR REMOVE(R)"<<endl;
        char ch;
        cin>>ch;
        amount=0;
        if(ch=='a'||ch=='A')
        {
            cout<<"\nEnter amount to add."<<endl;
            cin>>amount;

            cout<<"\nFinal Balance is:"<<balance+amount<<endl;

            return 1; 
        }
        else
        {
            while(1)
            {
                cout<<"\nEnter amount to withdrawl."<<endl;
                cin>>amount;
                if(amount<(balance-1000))
                {
                    cout<<"\nFinal Balance is:"<<balance-amount<<endl;
                    return 0;
                }
                else
                    cout<<"\nInsufficient amount.";
            }

        }

        cout<<"\n\n\t\tFinal balance is:"<<balance;
    }

    void sansation_loan()
    {
        if(token!=0)
        {
            cout<<"\nBank can not give loan to you.\n";
            cout<<"\nFirst return previous loan."<<endl;
            return;
        }
        else
        {
            cout<<"Intrest will be 5% Simple intrest."<<endl;
            cout<<"Enter amount of loan to sansation."<<endl;
            cin>>loan;
            cout<<"Enter period of loan."<<endl;
            int period;
            cin>>period;

            loan=loan+(float)loan*period*5/100;

            cout<<"\nAmount paid after "<<period<<" years is "<<loan<<"."<<endl;
            token=1;
            
            cout<<"\n LOAN SANSATION SUCCESSFULLY...\n\n"<<endl;

        }
    }

    void deposit_loan()
    {
        if(token==0)
        {
            cout<<"\nNO LOAN PRESENT."<<endl;
            return;
        }

        cout<<"\nAmount to paid:"<<loan<<endl;
        cout<<"Enter amount paid:";
        cin>>amount;
        while(amount!=loan)
        {
            cout<<"\nInvalid amount .\nPlease enter valid amount."<<endl;
            cin>>amount;
        }
        if(amount==loan)
        {
            cout<<"\n\nLOAN CLEARED SUCCESSFULLY...\n\n"<<endl;
        }
    }

    int returnamount()
    {
        return amount;
    }

    void resetbalance1(int n)
    {
        balance=balance+amount;
    }

    void resetbalance2(int n)
    {
        balance=balance-amount;
    }

    int returnloan()
    {
        return loan;
    }

    char* retaccno()
    {
        return accno;
    }

    int retbalance()
    {
        return balance;
    }

    int rettoken()
    {
        return token;
    }

    int retloan()
    {
        return loan;
    }

    void addtoken()
    {
        token=1;
    }

    void addloan(int n)
    {
        loan=n;
    }

    void resettoken()
    {
        token=0;
    }

    void resetloan()
    {
        loan=0;
    }

    void report()
    {
        cout<<"\n\t"<<accno<<"\t\t\t"<<phono<<"\t\t"<<name<<"\t\t"<<balance<<"\t\t"<<loan<<endl;
    }
};

member mem;

void add_member()
{
    char ch;
    fp.open("member.dat",ios::out|ios::app);
    do
    {
        cout << "\033[2J\033[1;1H";
        mem.create_member();
        fp.write((char*)&mem,sizeof(member));
        cout<<"\nDo you want to add more reord..(y/n)?";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();

    cout<<"\n\n\t\t MEMBERS ADDED SUCCSSFULLY...";

    printf("\nEnter any character to exit followed by enter.");
    cin>>character;
}

void display_spm()
{
    cout<<"\n\n\t\tMEMBER DETAILS...\n\n";
    char n[5];
    cout<<"\nEnter account number.";
    cin>>n;
    int flag=0;
    fp.open("member.dat",ios::in);
    while(fp.read((char*)&mem,sizeof(member)))
    {
        if(strcmp(mem.retaccno(),n)==0)
        {
            mem.show_member();
            flag=1;
            break;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\nNO SUCH MEMBER EXIST.";

    printf("\nEnter any character to exit followed by enter.");        
    cin>>character;
}

void delete_member()
{
    char n[5];
    int flag=0;
    cout << "\033[2J\033[1;1H";
    cout<<"\n\n\t\tPORTAL TO REMOVE MEMBER...\n"<<endl;
    cout<<"\nEnter account number:";
    cin>>n;
    fp.open("member.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&mem,sizeof(member)))
    {
        if(strcmp(mem.retaccno(),n)!=0)
        {
            fp2.write((char*)&mem,sizeof(member));
        }
        else
            flag=1;
        
    }
    fp2.close();
    fp.close();
    remove("member.dat");
    rename("temp.dat","member.dat");
    if(flag!=1)
        cout<<"\n\n\t\tNO RECORD FOUND...";
    else
        cout<<"\nMember deleted Successfully...";

    printf("\nEnter any character to exit followed by enter.");
    cin>>character;

}

void display_allm()
{
    cout << "\033[2J\033[1;1H";
    fp.open("member.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        printf("\nEnter any character to exit followed by enter.");
        cin>>character;
        return;
    }

    cout<<"\n\n\t\tMEMBER LIST...\n\n";
    cout<<"==================================================================\n";
    cout<<"\tACCOUNT NUMBER"<<"\t\t"<<"CONTACT NUMBER"<<"\t\t"<<"NAME"<<"\t\t\t"<<"BALANCE"<<"\t\t"<<"LOAN AMOUNT"<<endl;
    cout<<"==================================================================\n";

    while(fp.read((char*)&mem,sizeof(member)))
    {
        mem.report();
    }
    fp.close();
    printf("\nEnter any character to exit followed by enter.");
    cin>>character;
}

void view_balance()
{
    char n[5];
    cout << "\033[2J\033[1;1H";
    cout<<"\nEnter account number";
    cin>>n;
    int flag=0;
    fp.open("member.dat",ios::in);
    while(fp.read((char*)&mem,sizeof(member)))
    {
        if(strcmp(mem.retaccno(),n)==0)
        {
            cout<<"\nBalance is:"<<mem.retbalance();
            flag=1;
            break;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\nInvalid account number.";

    printf("\nEnter any character to exit followed by enter.");
    cin>>character;

}

void issue_loan()
{
    cout << "\033[2J\033[1;1H";
    char n[5];
    int flag=0;
    cout<<"\n\n\t\tLOAN ISSUE PORTAL...\n\n";
    cout<<"\nEnter account number."<<endl;
    cin>>n;
    fp.open("member.dat",ios::in|ios::out);
    while(fp.read((char*)&mem,sizeof(member)))
    {
        if(strcmp(mem.retaccno(),n)==0)
        {
            mem.sansation_loan();
            flag=1;
            mem.addtoken();
            mem.addloan(mem.returnloan());
            int temp=sizeof(mem);
            int pos=-temp;
            fp.seekp(pos,ios::cur);
            fp.write((char*)&mem,sizeof(member));
        }
    }
    if(flag==0)
        cout<<"\nInvalid account number.";

    fp.close();

    printf("\nEnter any character to exit followed by enter.");
    cin>>character;
}

void deposit_loan()
{
    cout << "\033[2J\033[1;1H";
    char n[5];
    int flag=0;
    cout<<"\n\n\t\tLOAN DEPOSIT PORTAL...\n\n";
    cout<<"\nEnter account number."<<endl;
    cin>>n;
    fp.open("member.dat",ios::in|ios::out);
    while(fp.read((char*)&mem,sizeof(member)))
    {
        if(strcmp(mem.retaccno(),n)==0)
        {
            mem.deposit_loan();
            flag=1;
            mem.resettoken();
            mem.resetloan();
            int temp=sizeof(mem);
            int pos=-temp;
            fp.seekp(pos,ios::cur);
            fp.write((char*)&mem,sizeof(member));
        }
    }
    if(flag==0)
        cout<<"\nInvalid account number.";

    fp.close();

    printf("\nEnter any character to exit followed by enter.");
    cin>>character;   
}

void modify_member()
{
    cout << "\033[2J\033[1;1H";
    char n[5];
    int flag=0;
    cout<<"\n\n\t\tACCOUNT MODIFICATION PORTAL...\n";
    cout<<"\nEnter account number."<<endl;
    cin>>n;
    fp.open("member.dat",ios::in|ios::out);
    while(fp.read((char*)&mem,sizeof(member)))
    {
        if(strcmp(mem.retaccno(),n)==0)
        {
            int local=mem.modify_member();
            flag=1;
            if(local==1)
            mem.resetbalance1(mem.returnamount());
            else
            mem.resetbalance2(mem.returnamount());
            int temp=sizeof(mem);
            int pos=-temp;
            fp.seekp(pos,ios::cur);
            fp.write((char*)&mem,sizeof(member));
        }
    }
    if(flag==0)
        cout<<"\nInvalid account number.";

    fp.close();

    printf("\nEnter any character to exit followed by enter.");
    cin>>character;   
}


int main()
{
    cout << "\033[2J\033[1;1H";
    while(1)
    {
        switch(choice())
        {
            case 1:
                    view_balance();
                    break;

            case 2:
                    adminportal();
                    break;

            case 3:
                    exit(0);
            default:
                    cout<<"\nInvalid choice.\nPlease enter a valid choice.\n";
        }
    }

    return 0;
}

void adminportal()
{
    int password,n=3;
    while(n>0)
    {
        cout<<"\n\n\t\tENTER PASSWORD...";
        cin>>password;
        if(password==123456789)
        {
            cout<<"\nPASSWORD MATCH...\n";
            break;
        }
        else
        {
            if(n==1)
            {
                cout<<"\n\n\t\tTO MANY ATTEMPTS..."<<endl;
                exit(0);
            }

            cout<<"\nPASSWORD DID NOT MATCH.YOU HAVE "<<--n<<" MORE CHANCES.BE CAREFUL..."<<endl;
        }
    }
    if(n==0)
    {
        exit(0);
    }
    while(n)
    {
     switch(adminchoice())
     {
        case 1:
            add_member();
            break;

        case 2:
            delete_member();
            break;

        case 3:
            modify_member();
            break;

        case 4:
            display_spm();
            break;

        case 5:
            display_allm();
            break;
                            
        case 6:
            issue_loan();
            break;

        case 7:
            deposit_loan();
            break;

        case 8:
            return;

        default:
            cout<<"\nInvalid choice.\nPlease enter a valid choice.\n";        
     }
    }
}