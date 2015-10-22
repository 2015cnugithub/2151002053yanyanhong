#include<iostream>
#include<string>
using namespace std;
class Worker
{protected:
string name;int age;char sex;double salary; double hours;
public:
	Worker() ;
	void getHour(double hours);
	~Worker();
	virtual void print() =0;
    virtual	void Compute_pay(double hours)=0;//计算周薪成员函数
	//显示工人的基本信息的标准输出运算符
//	friend void ostream& operator<<(ostream&out,Worker&worker) = 0;
 };
//计时工人类
class HourlyWorker: public Worker
{private:
    char sort;int rank;
	int pay_per_hour;//小时工资额
    double hours;//实际工作数
public:
	HourlyWorker();
	void getHour(double hours);
	void Compute_pay(double hours);
	void print();
};
class SalariedWorker:public Worker
{private:
    char sort;int rank;
	int pay_per_hour;//小时工资额
	double hours;//实际工作数 
public:
    SalariedWorker();
	void getHour(double hours);
	void Compute_pay(double hours);
	void print();
};
//类的实现
Worker::Worker()
{salary=0.0;
cout<<"intput the name of the person:";
cin>>name;
cout<<"intput the name of the age:";
cin>>age;
cout<<"intput the name of the sex:";
cin>>sex;
cout<<"实际工作时数：";
cin>>hours;
}
Worker::~Worker(){}
HourlyWorker::HourlyWorker(){
		if (rank ==1)
		pay_per_hour = 10;
	else if(rank ==2)
		pay_per_hour = 20;
		else if (rank ==3)
			pay_per_hour = 40;
		cout<<"小时工资额："<<pay_per_hour<<endl;
}
void HourlyWorker::Compute_pay(double hours)
{ if (hours<=40)
	{ if(rank == 1)
	salary= pay_per_hour*hours;
	
	else if(rank ==2)
	salary= pay_per_hour*hours;
		else if (rank ==3)
		salary= pay_per_hour*hours;
	}
  else{ if (rank ==1)
		salary= pay_per_hour *40+1.5*10*(hours-40);
	else if(rank ==2)
		salary= pay_per_hour*40+1.5*20*(hours-40);
       
		else if(rank == 3)
			salary=pay_per_hour*40+1.5*40*(hours-40);
       	}
 
}
void HourlyWorker::print()
{    cout<<"他的姓名："<<name<<endl;
	cout<<"工资是"<<salary<<endl;}

 SalariedWorker::SalariedWorker(){
	 	 hours=0.0;
	if (rank ==1)
		pay_per_hour = 30;
	else if(rank ==2)
		pay_per_hour = 50;
		cout<<"小时工资额："<<pay_per_hour<<endl;
	}
void SalariedWorker::Compute_pay(double hours)
{ 	if (hours<35)
	{ if(rank == 1)
		salary= pay_per_hour*hours+0.5*pay_per_hour*(35-hours);
	
	else if(rank ==2)
	    salary=pay_per_hour*hours+0.5*pay_per_hour*(35-hours);
		
	}
	else { if (rank ==1)
		salary=pay_per_hour*hours;
	else if(rank ==2)
	salary=pay_per_hour*hours;
       
		else if(rank == 3)
			salary=pay_per_hour*40+1.5*pay_per_hour*(hours-40);
       	}
}
void SalariedWorker::print()
{    cout<<"他的姓名："<<name<<endl;
	cout<<"工资是"<<salary<<endl;
}

int  main()
{double hours;
HourlyWorker   hworker;
SalariedWorker sworker;
Worker *worker;
worker=&hworker;
worker->Compute_pay(hours);
worker->print();

worker=&sworker;
worker->Compute_pay(hours);
worker->print();
return 0;
}

