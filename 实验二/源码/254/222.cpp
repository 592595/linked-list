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
/*二维*/
class TwoDimShape :public Shape
{
public:
	double Area;
	TwoDimShape *next;

};
/*三维*/
class ThreeShape :public Shape
{
public:
	double Volume;
	ThreeShape *next;
};

/*圆*/
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
		cout << "圆的半径：" << r << "  面积：" << reArea() << endl;
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

/*椭圆*/
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
		cout << "椭圆的长轴长：" << a << "  短轴长：" << b << "  面积：" << reArea() << endl;
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

/*矩形*/
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
		cout << "矩形的长：" << a << "  宽：" << b << "  面积：" << reArea() << endl;
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

/*三角形*/
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
		cout << "三角形的底：" << a << "  高：" << h << "  面积：" << reArea() << endl;
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

/*球*/
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
		cout << "球的半径：" << r << "  体积：" << reVolume() << endl;
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

/*圆柱体*/
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
		cout << "圆柱体的半径：" << r << "  高" << h << "  体积：" << reVolume() << endl;
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

/*长方体*/
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
		cout << "长方体的长：" << a << "  宽" << b << "  高" << c << "  体积：" << reVolume() << endl;
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
	cout << "选择插入类型" << endl << "1.圆 2.椭圆 3.矩形 4.三角形 5.球体 6.圆柱体 7.长方体" << endl;
	cin >> temp;
	if (temp == 1){
		int r;
		cout << "请输入半径" << endl;
		cin >> r;
		p = new Circle(r);
	}
	else if (temp == 2){
		int x, y;
		cout << "请输入长轴和短轴" << endl;
		cin >> x >> y;
		p = new Elipse(x, y);
		
	}
	else if (temp == 3){
		int x, y;
		cout << "请输入长和宽" << endl;
		cin >> x >> y;
		p = new Rectangle(x, y);
		
	}
	else if (temp == 4){
		int x,y;
		cout << "请输入半径和高" << endl;
		cin >> x >> y;
		p = new Triangle(x, y);
		
	}
	else if (temp == 5){
		int r;
		cout << "请输入球体半径" << endl;
		cin >> r;
		p = new Ball(r);
		
	}
	else if (temp == 6){
		int r, h;
		cin >> r >> h;
		cout << "请输入半径和高" << endl;
		p = new Cylider(r, h);
		
	}
	else if (temp == 7){
		int x, y, h;
		cin >> x >> y >> h;
		cout << "请输入长宽高" << endl;
		p = new RectangularParallelepiped(x, y, h);
		
	}
	//倒序插入
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
	cout<<"请输入删除节点的位置：";
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
	cout<<"反转成功！"<<endl;
	
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

			//倒序插入//////////////////////
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
	cout << "请输入数字进行选择操作： 1.插入结点  2.删除结点  3.反转  4.遍历  5.保存  0.退出" << endl;
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

		cout << "请输入数字进行选择操作： 1.插入结点  2.删除结点  3.反转  4.遍历  5.保存  0.退出" << endl;
	}
}

