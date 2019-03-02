#include<iostream>
#include<vector>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;

char board[21][81],c,z;
int length=4;
class snake
{
	public:
	int x,y;
	char value;
	
};
class food
{
	public:
	int x,y;
	char value;
	
	food()
	{
	value='X';
	}
};
vector<snake> s;
food f;
void foodvalue()
{
f.x=rand()%15;
f.y=rand()%75;	
}
	void insertfood()
{
	board[f.x][f.y]=f.value;
}
void insertsnake()
	{
		int i,j;
		for(i=0;i<length;i++)
		{
			board[s[i].x][s[i].y]=s[i].value;
		}
	}
void makeobject()
{
	snake s1;
	int i,j;
	s1.x=4;
	s1.y=4;
	s1.value='H';
	s.push_back(s1);
	for(i=1;i<3;i++)
	{
	s1.x=4;
	s1.y=4+i;
	s1.value='#';
	s.push_back(s1);	
	}
	s1.x=4;
	s1.y=4+i;
	s1.value='T';
	s.push_back(s1);	
}
void print()
{
	int i,j;
	for(i=0;i<21;i++)
	{
		for(j=0;j<81;j++)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
}
void boundary()
{
	int i,j;
	for(i=0;i<21;i++)
	{
		for(j=0;j<81;j++)
		{
			if(j==0||j==80)
			board[i][j]='*';
			else if(i==0||i==20)
			board[i][j]='*';
		}
		cout<<endl;
	}
}
void snakemodify()
{
	snake s1;
	s[length-1].value='#';
	s1.x=s[length-1].x;
	s1.y=s[length-1].y;
	s1.value='T';
	s.push_back(s1);
	 length++;
}
void snakemove()
{
	int i,j;
	if(c=='w')
	{
	for(i=length-1;i>0;i--)
	{
	s[i].x=s[i-1].x;
	s[i].y=s[i-1].y;
	z='s';	
	}
	s[0].x=s[0].x-1;
	}
	if(c=='s')
	{
		z='w';
	for(i=length-1;i>0;i--)
	{
	s[i].x=s[i-1].x;
	s[i].y=s[i-1].y;	
	}
	s[0].x=s[0].x+1;
	}
	if(c=='a')
	{
		z='d';
	for(i=length-1;i>0;i--)
	{
	s[i].x=s[i-1].x;
	s[i].y=s[i-1].y;	
	}
	s[0].y=s[0].y-1;
	}
	if(c=='d')
	{
		z='a';
	for(i=length-1;i>0;i--)
	{
	s[i].x=s[i-1].x;
	s[i].y=s[i-1].y;	
	}
	s[0].y=s[0].y+1;
	}
	board[20][s[length-1].y]='*';
	board[0][s[length-1].y]='*';
	board[s[length-1].x][80]='*';
	board[s[length-1].x][0]='*';
}
void input()
{
	cin>>c;
}
void boardnull()
{
	int i,j;
	for(i=1;i<20;i++)
	{
		for(j=1;j<80;j++)
		{
			board[i][j]=' ';
		}
	}
}
void delay()
{
	int i,j;
	for (i = 1; i <= 327; i++)
       for (j = 1; j <=32909; j++)
       {}

}
void inputtofile()
{
	int i;
	fout.open("snakefile");
	fout<<length<<endl;
	for(i=0;i<s.size();i++)
	{
		fout<<s[i].x<<endl;
		fout<<s[i].y<<endl;
	}
	fout<<f.x<<endl;
	fout<<f.y;
	fout.close();
}
void outputfromfile()
{
	int i;
	snake s1;
	fin.open("snakefile");
	fin>>length;
		fin>>s1.x;
		fin>>s1.y;
		s1.value='H';
		s.push_back(s1);
	for(i=1;i<length-1;i++)
	{	
		fin>>s1.x;
		fin>>s1.y;
		s1.value='#';
		s.push_back(s1);
	}
		fin>>s1.x;
		fin>>s1.y;
		s1.value='T';
		s.push_back(s1);
		fin>>f.x;
		fin>>f.y;
		fin.close();
}
void changeBoundary()
{
			if(s[0].x==21)
			{
				s[0].x=0;
			}
			else if(s[0].x==0)
			{
				s[0].x=20;
				
			}
			else if(s[0].y==0)
			{
				s[0].y=80;
			}
			else if(s[0].y==81)
			{
				s[0].y=0;
			}
		//	boundary();
}
int main()
{
	int i,b,d;
	char a,temp;
	cout<<"          ............WELCOME TO GAME............"<<endl;
	cout<<"Press 1 to play the game"<<endl;
	cout<<"Press 2 to exit the game"<<endl;
	cout<<"Press 3 to reload the old game"<<endl;
	cin>>b;
	if(b==1||b==3)
	{
		if(b==3)
		{
		outputfromfile();
		}
		else
		{
			foodvalue();
			makeobject();
		}
	boundary();
	insertfood();
	insertsnake();
	print();
c=getch();
//	while(c!='x')
	while(1)
	{
		//input();
		if(kbhit())
		{
		temp=getch();
		if(temp=='w'||temp=='a'||temp=='s'||temp=='d')
		c=temp;
		}
		else
			delay();
		if(z==c)
			break;
		if(c == 'x')
		{
			cout<<endl<<"you want to save the game??"<<endl<<"press 1 to save";
			cin>>b;
			if(b==1)
			{
				inputtofile();
			}
			break;
		}
		system("cls");
		snakemove();
		boardnull();
		insertfood();
		if(f.x==s[0].x && f.y==s[0].y)
		{
			foodvalue();
			snakemodify();
		}
		
		else if(board[s[0].x][s[0].y]=='#'||board[s[0].x][s[0].y]=='T')
		{
			break;
		}
		else if(s[0].x ==21||s[0].y==81||s[0].x==0||s[0].y==0)
		{
		//	ofstream out("snakefile", ofstream::out | ofstream::trunc);
			changeBoundary();
		   // break;
		}
		insertsnake();
		print();
		
	}
	cout<<"          ...........GAME ENDED..........";
}
	return 0;
}
