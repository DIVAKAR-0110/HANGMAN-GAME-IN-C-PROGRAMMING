#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

#define MAX 100

using namespace std;

string items[MAX];
int price[MAX];
int quantities[MAX]={0};

const double SGST_RATE =0.09;
const double CGST_RATE = 0.09;

class food
{
    public:
    food(){}



  void displayBill(int n,ofstream &obj)
  {
    double total=0.0;
    string currentDate =__DATE__;
    string currentTime =__TIME__;

    cout<<setw(69)<<endl<<endl<<"\e[1m KRISHNA FAST FOODS"<<endl;
    cout<<setw(71)<<"Avainashi Road, Hope college."<<endl<<endl;
    cout<<setw(40)<<"\e[1m DATE: "<<setw(50)<<currentDate<<endl;
    cout<<setw(40)<<"\e[1m TIME: "<<setw(48)<<currentTime<<endl;

    cout<<endl<<setw(30)<<"                              =============================================================";
    cout<<endl<<setw(47)<<"MY ORDERS |"<<setw(15)<<"QUANTITY |"<<setw(10)<<"PRICE |"<<setw(10)<<"TOTAL |";
    cout<<endl<<setw(30)<<"                              ============================================================"<<endl;

    obj<<setw(69)<<endl<<endl<<"\e[1m KRISHNA FAST FOODS" << endl;
    obj<<setw(71)<<"  Avainashi Road, Hope college." << endl << endl;
    obj<<setw(40)<<"\e[1m DATE: "<<setw(50)<<currentDate<<endl;
    obj<<setw(40)<<"\e[1m TIME: "<<setw(48)<<currentTime<<endl;

    obj<<endl<<setw(30)<<"                              =============================================================";
    obj<<endl<<setw(47)<<"MY ORDERS |"<<setw(15)<<"QUANTITY |"<<setw(10)<<"PRICE |"<<setw(10)<<"TOTAL |";
    obj<<endl<<setw(30)<<"                              ============================================================"<<endl;

    for(int i=0;i<n;++i)
    {
        if (quantities[i]>0)
        {
            double itemTotal=quantities[i]*price[i];
            total+=itemTotal;
            cout<<setw(43)<<items[i]<<setw(15)<<quantities[i]<<setw(10)<<price[i]<<setw(10)<<itemTotal<<endl;
            obj<<setw(43)<<items[i]<<setw(15)<<quantities[i]<<setw(10)<<price[i]<<setw(10)<<itemTotal<<endl;
        }
    }

    double sgst=total*SGST_RATE;
    double cgst=total*CGST_RATE;
    double grandTotal=total+sgst+cgst;

    cout<<setw(10)<<"                              _____________________________________________________________";
    cout<<endl<<setw(45)<<"SUBTOTAL"<<setw(35)<<total<<endl;
    cout<<setw(10)<<"                              _____________________________________________________________"<<endl;
    cout<<setw(45)<<"SGST @9%"<<setw(35)<<sgst<<endl;
    cout<<setw(45)<<"CGST @9%"<<setw(35)<<cgst<<endl<<endl;

    cout<<setw(45)<<"GRAND TOTAL"<<setw(35)<<grandTotal<<endl;
    cout<<setw(45)<<"                              =============================================================" <<endl<<endl;
    cout<<setw(50)<<"\t\t\t       \u00A9 Good food Good life \u00A9 \n"<<endl<<endl;

    obj<<setw(10)<<"                              _____________________________________________________________";
    obj<<endl<<setw(45)<<"SUBTOTAL"<<setw(35)<<total<<endl;
    obj<<setw(10)<<"                              _____________________________________________________________"<<endl;
    obj<<setw(45)<<"SGST @9%"<<setw(35)<<sgst<<endl;
    obj<<setw(45)<<"CGST @9%"<<setw(35)<<cgst<<endl<<endl;

    obj<<setw(45)<<"GRAND TOTAL"<<setw(35)<<grandTotal<<endl;
    obj<<setw(45)<<"                              =============================================================" <<endl<<endl;
    obj<<setw(70)<<"\t\t\t     \t\u00A9 Good food Good life \u00A9 \n"<<endl<<endl;
  }

  void resetQuantities(int n)
  {
    for(int i=0;i<n;++i)
    {
        quantities[i]=0;
    }
  }

};
int main()
{
    char choice;
    char bag;
    ofstream obj("fastfood.dat",ios::out|ios::trunc);
    int n,itemNumber;

    if(!obj)
    {
        cout<<"Error opening file!"<<endl;
        return 1;
    }

    cout<<"ENTER THE NUMBER OF ITEMS: ";
    cin>>n;
    obj<<"ENTER THE NUMBER OF ITEMS: "<<n<<endl;
    if(n>MAX)
    {
        cout<<"Number of items exceeds the maximum limit!"<<endl;
        return 1;
    }

    cout<<"ENTER YOUR TODAY'S LIST:"<<endl;
    obj<<"ENTER YOUR TODAY'S LIST:"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<"ITEM "<<i+1<<": ";
        cin>>items[i];
        obj<<"ITEM "<<i+1<<": "<<items[i]<<endl;
        cout<<"PRICE "<<i+1<<": ";
        cin>>price[i];
        obj<<"PRICE "<<i+1<<": "<<price[i]<<endl;
        cout<<endl<<endl;
        obj<<endl<<endl;
    }

    cout<<setw(71)<<"\e[1m   MENU CARD"<<endl<<setw(77)<<"============================"<<endl;
    cout<<setw(57)<<"FOODS"<<setw(8)<<"|"<<setw(10)<<"RATE"<<endl;
    cout<<setw(77)<<"============================"<<endl;
    obj<<setw(71)<<"\e[1m   MENU CARD"<<endl<<setw(77)<<"============================"<<endl;
    obj<<setw(57)<<"FOODS"<<setw(8)<<"|"<<setw(10)<<"RATE"<<endl;
    obj<<setw(77)<<"============================"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<setw(52)<<i+1<<"."<<items[i]<<setw(7)<<"|"<<setw(8)<<price[i]<<endl;
        obj<<setw(52)<<i+1<<"."<<items[i]<<setw(7)<<"|"<<setw(8)<<price[i]<<endl;
    }
    cout<<setw(77)<<"============================"<<endl;
    cout<<endl<<endl;
    obj<<setw(77)<<"============================"<<endl;
    obj<<endl<<endl;

    do {
        do {
             cout<<"ENTER MY ORDER as DISPLAYED NUMBER: ";
             cin>>itemNumber;

              if(itemNumber>0&&itemNumber<=n)
              {
                 int num=itemNumber;
                 if (num>=1&&num<=MAX)
                 {
                   int quantity;
                   cout<<"ENTER THE QUANTITY OF "<<items[num-1]<<" YOU NEED: ";
                   while(!(cin>>quantity)||quantity<=0)
                   {
                        cout<<"Invalid quantity! Please enter a positive integer: ";
                        cin.clear();
                        while(cin.get()!='\n');
                   }
                   quantities[num-1]+=quantity;
                }
                else
                {
                  cout <<"Invalid item number!"<<endl;
                }
             }
             else
             {
                cout<<"Invalid item number!"<<endl;
                obj<<"Invalid item number!"<<endl;
             }

            cout<<endl<<"ADD ANOTHER ? (Y/N): ";
            cin>>choice;
        }while(choice=='y'||choice=='Y');
        food f;
        f.displayBill(n,obj);
        f.resetQuantities(n);
        cout<<endl<<"BILL AGAIN (Y/N): ";
        cin>>bag;
    }while(bag=='Y'||bag=='y');

    obj.close();
    return 0;
}