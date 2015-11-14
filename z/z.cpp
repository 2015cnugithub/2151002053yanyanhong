#include <graphics.h> // 绘图库头文件，绘图语句需要
#include"Windows.h"
#include"iostream.h"
#include "conio.h"      // 控制台输入输出头文件kbhit()、getch()
#include <time.h> 
#include "dos.h"
#include"math.h"
class Point
{
public:
	int x;
	int y;
	Point(){}
	Point(int a,int b){x=a;y=b;}//点的坐标初始化
	Point(Point &p){x=p.x;y=p.y;}//指向点坐标的指针
	void operator()(int a,int b)
	{
			x=a;y=b;
	}
	
};//点的基类
class Figure
{
protected:
	int style;//线条的样式
	int pattern;//绘图模式
	int width;//线条的宽度
	int fcol;//填充颜色
	int Incol;//线条的颜色
public:
	Figure(){};
	Figure(int s,int p,int w, int f,int I);
	virtual void draw()=0;//画图形
	virtual void erase()=0;//消除图形
	virtual void move(int x, int y)=0;//移动图形
	virtual int  Is_out(){return 0;}//输出边界
};//关于图形的基类
Figure::Figure(int s,int p,int w, int f,int I)
{
	style=s;
	pattern=p;
	width=w;
	fcol=f;
	Incol=I;
};//图形的构造函数
class Circle:public Figure
{
	Point center;//圆心
	int radius;//半径
public:
	Circle(){}
	Circle(Point c,int s,int p,int w, int f,int I,int r):Figure(s, p, w, f, I)
	{
	style=s;
	pattern=p;
	width=w;
	fcol=f;
	Incol=I;
	center=c;
	radius=r;
	}
	virtual void draw();//画圆函数
	virtual void erase();//消圆函数
	virtual void move(int x, int y);//移动圆的函数
};//圆的定义
void Circle::draw()//画圆
 {
	 setfillcolor(RED);
	 setlinestyle(style, width);
	fillcircle (center.x,center.y, radius);
}
 void Circle::erase()//消圆
 {
     setfillcolor(BLACK);
	 setlinestyle(style, width);
	fillcircle (center.x,center.y, radius);
 }
 void Circle::move(int x,int y)//移圆
 {
	 center.x+=x;
	 center.y+=y;
 }
 class Triangle:public Figure
{
	Point pt[3];
public:
	Triangle(){}
	Triangle(Point pp[3],int s,int p,int w, int f,int I);
	virtual void draw();
	virtual void erase();
	virtual void move(int x, int y);
	
};//三角形定义
 Triangle::Triangle(Point pp[3],int s,int p,int w, int f,int I)
 {
	 int i;
	 for(i=0;i<3;i++)
	 {pt[i].x=pp[i].x;pt[i].y=pp[i].y;}
	 style=s;
	pattern=p;
	width=w;
	fcol=f;
	Incol=I;
}//三角形的构造函数
 void Triangle::draw()
 {
    setfillcolor(RED);
	setlinecolor(WHITE);
	setlinestyle(style, width);
	line(pt[0].x,pt[0].y,pt[1].x,pt[1].y);
	line(pt[1].x,pt[1].y,pt[2].x,pt[2].y);
	line(pt[2].x,pt[2].y,pt[0].x,pt[0].y);
	Point tem,tem1;
	tem.x=(pt[0].x+pt[1].x)/2;
	tem.y=(pt[0].y+pt[1].y)/2;
	tem1.x=(tem.x+pt[2].x)/2;
    tem1.y=(tem.y+pt[2].y)/2;
	floodfill(tem1.x,tem1.y,WHITE);
}//画三角形
 void Triangle::erase()
 {
	 setfillcolor(BLACK);
	 setlinecolor(BLACK);
	setlinestyle(style, width);
	line(pt[0].x,pt[0].y,pt[1].x,pt[1].y);
	line(pt[1].x,pt[1].y,pt[2].x,pt[2].y);
	line(pt[2].x,pt[2].y,pt[0].x,pt[0].y);
	Point tem,tem1;
	tem.x=(pt[0].x+pt[1].x)/2;
	tem.y=(pt[0].y+pt[1].y)/2;
	tem1.x=(tem.x+pt[2].x)/2;
    tem1.y=(tem.y+pt[2].y)/2;
	floodfill(tem1.x,tem1.y,BLACK);
}//消三角形
   void Triangle::move(int x,int y)
 {
	  pt[0].x+=x;
	 pt[0].y+=y;
	  pt[1].x+=x;
	 pt[1].y+=y;
	  pt[2].x+=x;
	pt[2].y+=y;
 }//三角形的移动
class Rectangler:public Figure//矩形的定义
{
	Point pt[4];
public:
	Rectangler(){}
	Rectangler(Point pp[4],int s,int p,int w, int f,int I);
	virtual void draw();
	virtual void erase();
	virtual void move(int x, int y);
	virtual int Is_out(){if(pt[0].x>480) return 1; return 0;}
};
 Rectangler::Rectangler(Point pp[4],int s,int p,int w, int f,int I)
 {
	 int i;
	 for(i=0;i<4;i++)
	 {pt[i].x=pp[i].x;pt[i].y=pp[i].y;}
	 style=s;
	pattern=p;
	width=w;
	fcol=f;
	Incol=I;
}//矩形的构造函数
 void Rectangler::draw()
 {
	setlinecolor(WHITE);
	 setfillcolor(RED);
	setlinestyle(style, width);
	line(pt[0].x,pt[0].y,pt[1].x,pt[1].y);
	line(pt[1].x,pt[1].y,pt[2].x,pt[2].y);
	line(pt[2].x,pt[2].y,pt[3].x,pt[3].y);
	line(pt[3].x,pt[3].y,pt[0].x,pt[0].y);
   floodfill(pt[0].x+1,(pt[1].y+pt[2].y)/2,WHITE);
}//画矩形
 void Rectangler::move(int x, int y)
 {
	 for(int i=0;i<4;i++)
	 {
		 pt[i].x+=x;
		 pt[i].y+=y;
	 }
 }//移动
 void Rectangler::erase()
 {
     setlinecolor(BLACK);
	 setfillcolor(BLACK);
	setlinestyle(style, width);
	line(pt[0].x,pt[0].y,pt[1].x,pt[1].y);
	line(pt[1].x,pt[1].y,pt[2].x,pt[2].y);
	line(pt[2].x,pt[2].y,pt[3].x,pt[3].y);
	line(pt[3].x,pt[3].y,pt[0].x,pt[0].y);
	floodfill((pt[0].x+pt[1].x)/2,(pt[1].y+pt[2].y)/2,BLACK);
}//消矩形
class FigureLink
{
	Figure *data;
	FigureLink *next;
public:
	FigureLink(){data=0;next=0;}
	~FigureLink()
	{
		Figure *p,*q;
	}
	void Set(Figure *p)
	{
		data=p;
	}
	void Setnext(FigureLink *q)
	{
		next=q;
	}
	Figure *Get()
	{
		return data;
	}
	FigureLink *GetNext()
	{
		return next;
	}
	
};//图形连接

class Vehicle
{
protected:
	FigureLink content;
	FigureLink *head;
public:
	Vehicle(){}
	virtual void draw()=0;//画车
	virtual void erase();//消车
	virtual void move(int x,int y);//移动车
	virtual int Is_out()=0;//判断车是否越过边界
};//车的基类
void Vehicle::erase()
{ 
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(/*p->GetNext()!=NULL*/1)
	 {
		 cast=p->Get();
		 cast->erase();
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }//消车
void Vehicle::move(int x,int y)
{
	FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(p->GetNext()!=NULL)
	 {
		 cast=p->Get();
		 cast->move(x,y);
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }//移车
class Car:public Vehicle
{
public:
	Car(){}
	Car(Figure *a[20],int m);
	virtual void draw();
	virtual void erase();
	virtual int Is_out();
};//小车的定义

class Truck :public Vehicle

{
public:
	Truck(){}
	Truck(Figure *b[20],int n);
	void draw();
	virtual void erase();
	virtual int Is_out();
	};//卡车的定义
  Car::Car(Figure *a[20],int m)
 {
	 int i=0;
	 head=&content;
	 FigureLink *p=head;
	for(;i<m;i++)
	{
    head=new FigureLink;
	head->Set(a[i]);
	p->Setnext(head);
	p=head;
	}
}
//小车的构造函数
 void Car::draw()
 {
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(p->GetNext()!=NULL)
	 {
		 cast=p->Get();
		 cast->draw();
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }//小车的实现
 void Car::erase()
{ 
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(p->GetNext()!=NULL)
	 {
		 cast=p->Get();
		 cast->erase();
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }//小车的消除
 int Car::Is_out()
 {
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 cast=p->Get();
	 return 0;
 }

 Truck:: Truck(Figure *b[20],int n)
 {
	 int i=0;
	 head=&content;
	 FigureLink *p=head;
	for(;i<n;i++)
	{
    head=new FigureLink;
	head->Set(b[i]);
	p->Setnext(head);
	p=head;
	}
}//卡车的构造函数
void Truck::draw()
 {
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(p->GetNext()!=NULL)
	 {
		 cast=p->Get();
		 cast->draw();
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }//画卡车
void Truck::erase()
{ 
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(p->GetNext()!=NULL)
	 {
		 cast=p->Get();
		 cast->erase();
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }//消卡车
int Truck::Is_out()
{
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 cast=p->Get();
	 return 0;
 }
 
   void animate(Vehicle *p, int velo)
{
	while(!p->Is_out())
	{
		p->erase();
		p->move(velo,0);
		p->draw();
     Sleep(100);//挂起100毫秒
	      if( kbhit()) 
		  {
			 char c=getch();
			 switch(c)
			 {
			 case 'S':	p->move(velo,0); break;//指示按<S>键，从起点开始动画移动小汽车或卡车；
		     case 'p':velo=velo-velo; break;//暂停
			 case 'E':	p->erase();break;//指示按<E>键，结束动画移动；
			 case '+': velo+=20; break;//加速
			 case '-': if(velo>10) velo-=10; break;//减速
		     default : ;break;
			 }
	
		 }
	}

}

int main() 
{  
	initgraph(640, 480);   // 初始化640x480的绘图屏幕  
	Point p1(22.5,450),p2(12.5,460),p3(22.5,460),p4(57.5,450),p5(57.5,460),p6(67.5,460);
	Point p7(0,460),p8(80,460),p9(0,470),p10(80,470),p11(17.5,475),p12(62.5,475);
	Point k[4],x[4],s[3],d[3];
  	      k[0]=p1,k[1]=p3,k[2]=p5,k[3]=p4,x[0]=p7,x[1]=p8,x[2]=p10,x[3]=p9;
          d[0]=p4,d[1]=p6,d[2]=p5,s[0]=p1,s[1]=p2,s[2]=p3;
		  Triangle t1(s,PS_SOLID,0,1,0,0x00AA00),t2(d,PS_SOLID,0,1,0,0x00AA00);
		Rectangler c1(k,PS_SOLID,0,1,0,0xAA0000),c2(x,PS_SOLID,0,1,0,0xAA0000);
		Circle r1(p11,PS_SOLID,0,1,0,0x5555FF,5),r2(p12,PS_SOLID,0,1,0,0x5555FF,5);
	Figure *xc[6];
	xc[0]=&c1;
	xc[1]=&c2;
	xc[2]=&r1;
	xc[3]=&r2;
	xc[4]=&t1;
	xc[5]=&t2;
	Car c(xc,6);
	Vehicle *p=&c;
	p->draw();
	p->erase();
	animate(p,12);   
/*	Point p1(0,430),p2(0,470),p3(90,470),p4(90,430);
	Point p5(90,440),p6(110,440),p7(110,470);
	Point p8(17.5,475),p9(19.5,475),p10(64.5,475),p11(66.5,475),p12(100,475);
	Point k[4];
  	      k[0]=p1,k[1]=p2,k[2]=p3,k[3]=p4;
		  Point x[4];
		  x[0]=p3,x[1]=p5,x[2]=p6,x[3]=p7;
     	Rectangler r1(k,PS_SOLID,0,2,0,0xAA0000),r2(x,PS_SOLID,0,2,0,0xAA0000);
		Circle c1(p8,PS_SOLID,0,2,0,0x5555FF,5),c2(p9,PS_SOLID,0,2,0,0x5555FF,5),c3(p10,PS_SOLID,0,2,0,0x5555FF,5);
		Circle c4(p11,PS_SOLID,0,2,0,0x5555FF,5),c5(p12,PS_SOLID,0,2,0,0x5555FF,5);
	 Figure *xc[7];
	xc[0]=&c1;
	xc[1]=&c2;
	xc[2]=&c3;
	xc[3]=&c4;
	xc[4]=&c5;
	xc[5]=&r1;
	xc[6]=&r2;
	Truck c(xc,7);
	Vehicle *p=&c;
	p->draw();
	p->erase();
	animate(p,12);*/
	getch();
    closegraph();

 return 0;
}

