#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>


using namespace std;


/*class Bar
{
    Bar();
};
class Foo
{
    Bar* bar;
    void setBar(Bar* _bar)
    {
        bar=_bar;
    }
};*/


class Staff{
    /*Â· Declaring a base class member as protected also means that if a derived
class inherits the base class it will have access to the protected member.*/
protected:
     string name,surname;
     int age;

public:
    Staff(){};
     Staff(string StaffName,string StaffSurname,int StaffAge ){
         //calling setter function to initialize values in constructor parameter list
    setStaff(StaffName,StaffSurname,StaffAge);
    };
   void setStaff(string StaffName,string StaffSurname,int StaffAge ){
name=StaffName;
surname=StaffSurname;
age=StaffAge;
}
};

class Employer:public Staff{
string ID;
public:
Employer(){};
Employer(string EName,string ESurname,int EAge,string EID ){
   //calling setter function to initialize values in constructor parameter list
        setEmployer(EName,ESurname,EAge,EID);

}
void setEmployer(string EName,string ESurname,int EAge,string EID );
void outputDetails();
};
void Employer::setEmployer(string EName,string ESurname,int EAge,string EID ){
name=EName;
surname=ESurname;
age=EAge;
ID=EID;
}
void Employer::outputDetails(){
cout<<"\nName:  "<<name;
cout<<"\nSurname:  "<<surname;
cout<<"\nAge:  "<<age;
cout<<"\nID:  "<<ID;
//classify whether employee or employer
};
class Employees:public Staff{
protected:
 string ID;
public:
Employees(){};
Employees(string EName,string ESurname,int EAge,string EID ){
        setEmployee(EName,ESurname,EAge,EID);

}
void setEmployee(string EName,string ESurname,int EAge,string EID );
void outputDetails();
};
void Employees::setEmployee(string EName,string ESurname,int EAge,string EID ){
name=EName;
surname=ESurname;
age=EAge;
ID=EID;
}
void Employees::outputDetails(){
cout<<"\nName:  "<<name;
cout<<"\nSurname:  "<<surname;
cout<<"\nAge:  "<<age;
cout<<"\nID:  "<<ID;
}
class ComissionWorker:public Employees{
    protected:
float grossSales,comissionRate,wages;
public:
    ComissionWorker(){};
    ComissionWorker(float Gsales,float rate){
setComission(Gsales,rate);
    };
  void setComission(float Gsales,float rate){
  grossSales=Gsales;
  if(rate>0.0&&rate<5.0)
  comissionRate=rate;
  else
    cout<<"commission rate must be >0.0 or <5.0";
    //throw invalid_argument("commission rate must be >0.0 or <5.0");

    }
  double getComission(){
if(comissionRate>0.0){
wages = grossSales*(comissionRate/100);
    return wages;}
  else
    cout<<"invalid commission rate";
  }
};
class SalariedWorker:public Employees{
int hours;
float hourPay;
double salary;
public:
    SalariedWorker(){}
    SalariedWorker(float pay){
    salary=pay;
    }
    SalariedWorker(int hrsWrkd,float thisPay){

    hours=hrsWrkd;
    hourPay=thisPay;
    }
//association
     float operator+(ComissionWorker Comm){
     float total;
     total= salary+Comm.getComission();
     return total;
     }

    void setHourPay(int hrsWrkd,float thisPay){
    hours=hrsWrkd;
    hourPay=thisPay;
    }
    void setPay(float pay){
    salary = pay;
    }
    double getSalary(){
        salary=hours*hourPay;
return salary;
    }
      int getHours(){
return hours;
    }

};
class Calculate{
    int hr;
    float pay;


public:
      float grossSales;
    float commissionRate;
     float total;
void calc(){
    cout<<"enter hours worked: ";
    cin>>hr;
    cout<<"enter Payment as per hour: ";
    cin>>pay;
    SalariedWorker salaried(hr,pay);
    SalariedWorker sal,sala;
    ComissionWorker commission;
 cout<<"enter gross Sales received: ";
    cin>>grossSales;
     cout<<"enter Commission Rate >0.0 or <5.0: ";
        cin>>commissionRate;
  commission.setComission(grossSales,commissionRate);
    sal.setPay(salaried.getSalary());
    total=sal+commission;
cout<<"Salary = $"<<setprecision(2)<<fixed<<salaried.getSalary();
cout<<"\nCommission = $"<<setprecision(2)<<fixed<<commission.getComission();


}

};

int main(int argv,char**argc[]){
Calculate calculate;
    int age,a;
    string name,surname,id;
cout<<"\t\t\tDAIRIBOARD COMPANY"<<endl;

cout<<"Enter [1] Employee  [2] Employer"<<endl;
cin>>a;
if(a==1){
        cout<<"enter employee details"<<endl;
cout<<"Name:";
getline(cin, name);
getline(cin, name);
cout<<"Surname";
getline(cin,surname);
cout<<"ID";
getline(cin,id);
cout<<"age";
cin>>age;
cout<<"Please Select Department "<<endl;
          int c;
 cout<<"[1] Managerial";
 cout<<"\n[2] Till Operate";
 cout<<"\n[3] Cleaning";
 cout<<"\n[4] Security";
 cin>>c;
 switch(c){

 case 1:
        calculate.calc();
  //     cout<<"total salary Payment "<<setprecision(2)<<fixed<<calculate.total;
     break;
 case 2:
calculate.calc();
//cout<<"total salary Payment "<<setprecision(2)<<fixed<<calculate.total;
    break;
    case 3:
calculate.calc();
//cout<<"total salary Payment "<<setprecision(2)<<fixed<<calculate.total;
    break;
    case 4:
calculate.calc();

    break;
 default: cout<<"invalid choice try again"<<endl;}
Employer Employ;

Employ.setEmployer(name,surname,age,id);
Employ.outputDetails();
cout<<"\ntotal Payment on salary + commission "<<setprecision(2)<<fixed<<calculate.total;

 }


if(a==2){
Employees Employee;
        cout<<"enter employer details"<<endl;
cout<<"Name:";
getline(cin, name);
getline(cin, name);
cout<<"Surname";
getline(cin,surname);
cout<<"ID";
getline(cin,id);
cout<<"age";
cin>>age;
calculate.calc();
Employee.setEmployee(name,surname,age,id);
Employee.outputDetails();
cout<<"\ntotal salary Payment "<<setprecision(2)<<fixed<<calculate.total;
}

return 0;
}

