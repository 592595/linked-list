#include<iostream>
#include<fstream>
using namespace std;
const double PI = 3.14;
class Shape
{
public:
	int type;
	virtual void showData() = 0;
	virtual double reArea() = 0;
	virtual double reVolume() = 0;
	virtual void saveClass(ofstream&out) = 0;
	Shape *next;
};
Shape *head;
/*��ά*/
class TwoDimShape :public Shape
{
public:
	double Area;
	TwoDimShape *next;

};
/*��ά*/
class ThreeShape :public Shape
{
public:
	double Volume;
	ThreeShape *next;
};

/*Բ*/
class Circle :public TwoDimShape
{
public:
	int r;
	Circle(int t)
	{
		r = t;
		type=1;
	}
	void saveClass(ofstream &out){
		out <<type<<" " << r << endl;
	}
	void showData()
	{
		cout << "Բ�İ뾶��" << r << "  �����" << reArea() << endl;
	}
	double reArea()
	{
		Area = PI*r*r;
		return Area;
	}
	double reVolume()
	{
		return 0;
	}


};

/*��Բ*/
class Elipse :public TwoDimShape
{
public:
	int a, b;
	Elipse(int m, int n)
	{
		a = m;
		b = n;
		type=1;
	}
	void saveClass(ofstream &out){
		out <<type<<" " << a<<" "<<b << endl;
	}
	void showData()
	{
		cout << "��Բ�ĳ��᳤��" << a << "  ���᳤��" << b << "  �����" << reArea() << endl;
	}

	double reArea()
	{
		Area = PI*a*b;
		return Area;

	}
	double reVolume()
	{
		return 0;
	}

};

/*����*/
class Rectangle :public TwoDimShape
{
public:
	int a, b;
	Rectangle(int m, int n)
	{
		a = m;
		b = n;
		type=3;
	}
	void saveClass(ofstream &out){
		out <<type<<" " << a<<" "<<b << endl;
	}
	void showData()
	{
		cout << "���εĳ���" << a << "  ��" << b << "  �����" << reArea() << endl;
	}

	double reArea()
	{
		Area = a*b;
		return Area;

	}
	double reVolume()
	{
		return 0;
	}


};

/*������*/
class Triangle :public TwoDimShape
{
public:
	int a, h;
	Triangle(int m,int n)
	{
		a = m;
		h = n;
		type=4;
	}
	void saveClass(ofstream &out){
		out <<type<<" " << a<<" "<<h << endl;
	}
	void showData()
	{
		cout << "�����εĵף�" << a << "  �ߣ�" << h << "  �����" << reArea() << endl;
	}

	double reArea()
	{
		Area = 0.5*a*h;
		return Area;

	}
	double reVolume()
	{
		return 0;
	}

};

/*��*/
class Ball :public ThreeShape
{
public:
	int r;
	Ball(int m)
	{
		r = m;
		type=5;
	}
	void saveClass(ofstream &out){
		out <<type<<" " << r << endl;
	}
	void showData()
	{
		cout << "��İ뾶��" << r << "  �����" << reVolume() << endl;
	}
	double reArea()
	{
		return 0;
	}
	double reVolume()
	{
		Volume = PI*r*r*r * 4 / 3;
		return Volume;

	}
};

/*Բ����*/
class Cylider :public ThreeShape
{
public:
	int r, h;
	Cylider(int m, int n)
	{
		r = m;
		h = n;
		type=6;
	}
	void saveClass(ofstream &out){
		out <<type<<" " << r<<" "<<h << endl;
	}
	void showData()
	{
		cout << "Բ����İ뾶��" << r << "  ��" << h << "  �����" << reVolume() << endl;
	}
	double reArea()
	{
		return 0;
	}
	double reVolume()
	{
		Volume = PI*r*r*h;
		return Volume;

	}


};

/*������*/
class RectangularParallelepiped :public ThreeShape
{
public:
	int a, b, c;
	RectangularParallelepiped(int m, int n, int t)
	{
		a = m;
		b = n;
		c = t;
		type=7;
	}
	void saveClass(ofstream &out){
		out <<type<<" " << a<<" "<<c << endl;
	}
	void showData()
	{
		cout << "������ĳ���" << a << "  ��" << b << "  ��" << c << "  �����" << reVolume() << endl;
	}
	double reArea()
	{
		return 0;
	}
	double reVolume()
	{
		Volume = a*b*c;
		return Volume;

	}

};

void add(){
	int temp;
	Shape *p = NULL;
	cout << "ѡ���������" << endl << "1.Բ 2.��Բ 3.���� 4.������ 5.���� 6.Բ���� 7.������" << endl;
	cin >> temp;
	if (temp == 1){
		int r;
		cout << "������뾶" << endl;
		cin >> r;
		p = new Circle(r);
	}
	else if (temp == 2){
		int x, y;
		cout << "�����볤��Ͷ���" << endl;
		cin >> x >> y;
		p = new Elipse(x, y);
		
	}
	else if (temp == 3){
		int x, y;
		cout << "�����볤�Ϳ�" << endl;
		cin >> x >> y;
		p = new Rectangle(x, y);
		
	}
	else if (temp == 4){
		int x,y;
		cout << "������뾶�͸�" << endl;
		cin >> x >> y;
		p = new Triangle(x, y);
		
	}
	else if (temp == 5){
		int r;
		cout << "����������뾶" << endl;
		cin >> r;
		p = new Ball(r);
		
	}
	else if (temp == 6){
		int r, h;
		cin >> r >> h;
		cout << "������뾶�͸�" << endl;
		p = new Cylider(r, h);
		
	}
	else if (temp == 7){
		int x, y, h;
		cin >> x >> y >> h;
		cout << "�����볤���" << endl;
		p = new RectangularParallelepiped(x, y, h);
		
	}
	//�������
	if (head == NULL){
		head = p;
		p->next = NULL;
	}
	else{
		p->next = head;
		head = p;
	}

}

void show()
{
	Shape *p=head;
	while (p)
	{
		p->showData();
		p = p->next;

	}
}

void del()
{
	cout<<"������ɾ���ڵ��λ�ã�";
	int k;
	cin>>k;
	Shape *p=NULL,*q;
	if(k==1)
	{
		p=head;
		head=head->next;
		delete p;
		return;
	}
	int s=1;
	for(q=head,p=head->next;p;q=p,p=p->next)
	{
		s++;
		if(k==s)
		{
			q->next=p->next;
			delete p;
			return;
		}
	}
	delete p;
	return;
}

void turn()
{
	Shape *p=NULL;
	Shape *tmp = NULL;

	if(head == NULL)
	{
		return;
	}
	tmp = head -> next;
	while (tmp->next != NULL)
    {
        p = tmp->next;
        tmp->next = p->next;
        p->next = head->next;
        head->next = p;
    }
	p=head;
	head=head->next;
	tmp->next=p;
	p->next=NULL;
	cout<<"��ת�ɹ���"<<endl;
	
	show();
}

void get(){
	int type;
	Shape *p ;
	p = NULL;
	ifstream creatList("22.txt", ios::in);
	{
		while (creatList>>type)
		{
			if (type == 1){
				int r;
				creatList >> r;
				p = new Circle(r);
			}
			else if (type==2){
				int x, y;
				creatList >> x >> y;
				p = new Elipse(x, y);
				
			}
			else if (type == 3){
				int x, y;
				creatList >> x >> y;
				p = new Rectangle(x, y);
			
			}
			else if (type == 4){
				int x, y;
				creatList >> x >> y;
				p = new Triangle(x, y);
				
			}
			else if (type == 5){
				int r;
				creatList >> r;
				p = new Ball(r);
				
			}
			else if (type == 6){
				int r, h;
				creatList >> r >> h;
				p = new Cylider(r, h);
				
			}
			else if (type == 7){
				int x, y, h;
				creatList >> x >> y >> h;
				p = new RectangularParallelepiped(x, y, h);
				
			}

			//�������//////////////////////
			if (head == NULL)
			{
				head = p;
				p->next = NULL;
			}
			else
			{
				p->next = head;
				head = p;
			}
			

		}
	}
}

void save()
{
	Shape *p = head;
	ofstream myList("22.txt",ios::out);
	while (p){
		p->saveClass(myList);

		p = p->next;
	}
	myList.close();
}


int main()
{

	get();
	int t;
	cout << "���������ֽ���ѡ������� 1.������  2.ɾ�����  3.��ת  4.����  5.����  0.�˳�" << endl;
	while (cin >> t)
	{
		if (t == 1)
		{
			add();

		}
		else if(t==2)
		{
			del();
		}
		else if(t==3)
		{
			turn();
		}
		else if (t == 4)
		{
			show();
		}

		else if (t == 5)
		{
			save();
		}
		else if (t == 0)
		{
			return 0;
		}

		cout << "���������ֽ���ѡ������� 1.������  2.ɾ�����  3.��ת  4.����  5.����  0.�˳�" << endl;
	}
}

