#include <graphics.h> // ��ͼ��ͷ�ļ�����ͼ�����Ҫ
#include"Windows.h"
#include"iostream.h"
#include "conio.h"      // ����̨�������ͷ�ļ�kbhit()��getch()
#include <time.h> 
#include "dos.h"
#include"math.h"
class Point
{
public:
	int x;
	int y;
	Point(){}
	Point(int a,int b){x=a;y=b;}//��������ʼ��
	Point(Point &p){x=p.x;y=p.y;}//ָ��������ָ��
	void operator()(int a,int b)
	{
			x=a;y=b;
	}
	
};//��Ļ���
class Figure
{
protected:
	int style;//��������ʽ
	int pattern;//��ͼģʽ
	int width;//�����Ŀ��
	int fcol;//�����ɫ
	int Incol;//��������ɫ
public:
	Figure(){};
	Figure(int s,int p,int w, int f,int I);
	virtual void draw()=0;//��ͼ��
	virtual void erase()=0;//����ͼ��
	virtual void move(int x, int y)=0;//�ƶ�ͼ��
	virtual int  Is_out(){return 0;}//����߽�
};//����ͼ�εĻ���
Figure::Figure(int s,int p,int w, int f,int I)
{
	style=s;
	pattern=p;
	width=w;
	fcol=f;
	Incol=I;
};//ͼ�εĹ��캯��
class Circle:public Figure
{
	Point center;//Բ��
	int radius;//�뾶
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
	virtual void draw();//��Բ����
	virtual void erase();//��Բ����
	virtual void move(int x, int y);//�ƶ�Բ�ĺ���
};//Բ�Ķ���
void Circle::draw()//��Բ
 {
	 setfillcolor(RED);
	 setlinestyle(style, width);
	fillcircle (center.x,center.y, radius);
}
 void Circle::erase()//��Բ
 {
     setfillcolor(BLACK);
	 setlinestyle(style, width);
	fillcircle (center.x,center.y, radius);
 }
 void Circle::move(int x,int y)//��Բ
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
	
};//�����ζ���
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
}//�����εĹ��캯��
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
}//��������
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
}//��������
   void Triangle::move(int x,int y)
 {
	  pt[0].x+=x;
	 pt[0].y+=y;
	  pt[1].x+=x;
	 pt[1].y+=y;
	  pt[2].x+=x;
	pt[2].y+=y;
 }//�����ε��ƶ�
class Rectangler:public Figure//���εĶ���
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
}//���εĹ��캯��
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
}//������
 void Rectangler::move(int x, int y)
 {
	 for(int i=0;i<4;i++)
	 {
		 pt[i].x+=x;
		 pt[i].y+=y;
	 }
 }//�ƶ�
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
}//������
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
	
};//ͼ������

class Vehicle
{
protected:
	FigureLink content;
	FigureLink *head;
public:
	Vehicle(){}
	virtual void draw()=0;//����
	virtual void erase();//����
	virtual void move(int x,int y);//�ƶ���
	virtual int Is_out()=0;//�жϳ��Ƿ�Խ���߽�
};//���Ļ���
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
 }//����
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
 }//�Ƴ�
class Car:public Vehicle
{
public:
	Car(){}
	Car(Figure *a[20],int m);
	virtual void draw();
	virtual void erase();
	virtual int Is_out();
};//С���Ķ���

class Truck :public Vehicle

{
public:
	Truck(){}
	Truck(Figure *b[20],int n);
	void draw();
	virtual void erase();
	virtual int Is_out();
	};//�����Ķ���
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
//С���Ĺ��캯��
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
 }//С����ʵ��
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
 }//С��������
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
}//�����Ĺ��캯��
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
 }//������
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
 }//������
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
     Sleep(100);//����100����
	      if( kbhit()) 
		  {
			 char c=getch();
			 switch(c)
			 {
			 case 'S':	p->move(velo,0); break;//ָʾ��<S>��������㿪ʼ�����ƶ�С�����򿨳���
		     case 'p':velo=velo-velo; break;//��ͣ
			 case 'E':	p->erase();break;//ָʾ��<E>�������������ƶ���
			 case '+': velo+=20; break;//����
			 case '-': if(velo>10) velo-=10; break;//����
		     default : ;break;
			 }
	
		 }
	}

}

int main() 
{  
	initgraph(640, 480);   // ��ʼ��640x480�Ļ�ͼ��Ļ  
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

