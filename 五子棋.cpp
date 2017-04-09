#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define H 15

int map[15][15];			//0为空，1为黑，2为白,3为待选，4为13融合，5为23融合

//光标结构体
struct cursor 
{
	int x;
	int y;
}point;

//棋盘初始化
void ini()		
{
	for (int  i = 0; i <15; i++)
	{
		for (int  j = 0; j < 15; j++)
		{
			map[i][j] = 0;
		}
	}
}

//是否继续		待完善
void go()
{
	printf("是否继续:\n是 y\t否 n");
	system("pause");
	char choose;
	scanf("%c", &choose);
	if (choose=='y')
	{
		ini();
	}
	else
	{
		exit(1);
	}


}

//胜负判断
void check(int x,int y)
{
	int hei = 0, bai = 0;
	for (int i = 0; i < H; i++)			//横向判断
	{
		if ((map[x][i] == 0) || (map[x][i] == 3))
		{
			hei = 0;
			bai = 0;
		}
		if ((map[x][i]==1)||(map[x][i]==4))
		{
			hei++;
			bai = 0;
			if (hei==5)
			{
				printf("\t\t\t********黑方胜***********\n");
				go();

			}
		}
		if ((map[x][i] == 2) || (map[x][i] == 5))
		{
			bai++;
			hei = 0;
			if (bai==5)
			{
				printf("\t\t\t********白方胜***********\n");
				go();
			}
		}

	}

	 hei = 0, bai = 0;
	for (int  i = 0; i < H; i++)			//纵向判断
	{
		
		if ((map[i][y] == 0) ||( map[i][y] == 3))
		{
			hei = 0;
			bai = 0;
		}
		if ((map[i][y] == 1) || (map[i][y] == 4))
		{
			hei++;
			bai = 0;
			if (hei == 5)
			{
				printf("\t\t\t********黑方胜***********\n");
				go();
			}
		}
		if ((map[i][y] == 2) || (map[i][y] == 5))
		{
			bai++;
			hei = 0;
			if (bai == 5)
			{
				printf("\t\t\t********白方胜***********\n");
				go();
			}
		}
	}

	//斜向(\向)判断
	int x1 = x, y1 = y;
	if (x1>y1)
	{
		x1 = x1 - y1;
		y1 = 0;
	}
	else
	{
		y1 = y1 - x1;
		x1 = 0;
	}
	hei = 0, bai = 0;
	while ((x1<H)&&(y1<H))
	{
		if ((map[x1][y1]==0)||(map[x1][y1]==3))
		{
			hei = 0;
			bai = 0;
		}
		if ((map[x1][y1] == 1) || (map[x1][y1] == 4))
		{
			hei++;
			bai = 0;
			if (hei==5)
			{
				printf("\t\t\t********黑方胜***********\n");
				go();
			}
		}
		if ((map[x1][y1] == 2) || (map[x1][y1] == 5))
		{
			bai++;
			hei = 0;
			if (bai==5)
			{
				printf("\t\t\t********白方胜***********\n");
				go();
			}
		}
		x1++;
		y1++;
	}

	//斜向（/向）判断
	int x2 = x, y2 = y;						
	if (x2>y2)
	{
		x2 = (x - (H - y));
		y2 = H-1;
	}
	else
	{
		x2 =0;
		y2 = (y +x);
	}
	hei = 0, bai = 0;
	while ((y2>=0)&&(x2<H))
	{
		if ((map[x2][y2] == 0) || (map[x2][y2] == 3))
		{
			hei = 0;
			bai = 0;
		}
		if ((map[x2][y2] == 1) || (map[x2][y2] == 4))
		{
			hei++;
			bai = 0;
			if (hei == 5)
			{
				printf("\t\t\t********黑方胜***********\n");
				go();
			}
		}
		if ((map[x2][y2] == 2) || (map[x2][y2] == 5))
		{
			bai++;
			hei = 0;
			if (bai == 5)
			{
				printf("\t\t\t********白方胜***********\n");
				go();
			}
		}
		x2++;
		y2--;
	}


}

//打印棋盘
void prin()			
{

	system("cls");
	for (int i = 0; i <15; i++)
	{
		printf("\t\t");
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j]==0)
			{
				printf("╋");
			}
			else
			{
				if ((map[i][j]==1) || (map[i][j] == 4))
				{
					printf("●");
				}
				if ((map[i][j]==2) || (map[i][j] == 5))
				{
					printf("○");
				}
				if ((map[i][j]==3))
				{
					printf("Ⅹ");
				}

			}
			
		}
		printf("\n");
	}
	printf("\n\n————————————————————————————————————————————\n");
	printf("w向上，a向左，s向下，d向右，p确定\n");
	printf("请输入：");
}

//ai  待完成

void ai()
{
	int map1[15][15] = { 0 };
	for (int  i = 0; i < 15; i++)
	{
		for (int  j = 0; j < 15; j++)
		{
			if ((map[i][j]==0)||(map[i][j]==3))
			{

				if (((i-3)>-1))				//纵向
				{
					//堵黑棋
					if (((map[i - 3][j] == 1) || (map[i - 3][j] == 4)) && ((map[i - 2][j] == 1) || (map[i - 2][j] == 4)) && ((map[i - 1][j] == 1) || map[i - 1][j] == 4)) 
					{
						map1[i][j]+= 1000;
					}
					if (((map[i - 2][j] == 1) || (map[i - 2][j] == 4)) && ((map[i - 1][j] == 1) || map[i - 1][j] == 4))
					{
						map1[i][j] += 50;
					}
					if (((map[i - 1][j] == 1) || map[i - 1][j] == 4))
					{
						map1[i][j] += 1;
					}
					//下白棋
					if (((map[i - 3][j] == 2) || (map[i - 3][j] == 5)) && ((map[i - 2][j] == 2) || (map[i - 2][j] == 5)) && ((map[i - 1][j] == 2) || map[i - 1][j] == 5))
					{
						map1[i][j] += 1000;
					}
					if (((map[i - 2][j] == 2) || (map[i - 2][j] == 5)) && ((map[i - 1][j] == 2) || map[i - 1][j] == 5))
					{
						map1[i][j] += 50;
					}
					if (((map[i - 1][j] == 2) || map[i - 1][j] == 5))
					{
						map1[i][j] += 10;
					}

				}
				if ((i+3)<H)
				{
					if (((map[i + 3][j] == 1) || (map[i + 3][j] == 4)) && ((map[i + 2][j] == 1) || (map[i + 2][j] == 4)) && ((map[i + 1][j] == 1) || map[i + 1][j] == 4))
					{
						map1[i][j] += 1000;
					}
					if (((map[i + 2][j] == 1) || (map[i + 2][j] == 4)) && ((map[i + 1][j] == 1) || map[i + 1][j] == 4))
					{
						map1[i][j] += 50;
					}
					if (((map[i + 1][j] == 1) || map[i + 1][j] == 4))
					{
						map1[i][j] += 1;
					}
					if (((map[i + 3][j] == 2) || (map[i + 3][j] == 5)) && ((map[i + 2][j] == 2) || (map[i + 2][j] == 5)) && ((map[i + 1][j] == 2) || map[i + 1][j] == 5))
					{
						map1[i][j] += 1000;
					}
					if (((map[i + 2][j] == 2) || (map[i + 2][j] == 5)) && ((map[i + 1][j] == 2) || map[i + 1][j] == 5))
					{
						map1[i][j] += 50;
					}
					if (((map[i + 1][j] == 2) || map[i + 1][j] == 5))
					{
						map1[i][j] += 10;
					}
				}

				if ((j-3)>-1)			//横向
				{
					//堵黑棋
					if (((map[i][j-3] == 1) || (map[i][j-3] == 4)) && ((map[i][j-2] == 1) || (map[i][j - 2] == 4)) && ((map[i][j - 1] == 1) || map[i][j - 1] == 4))
					{
						map1[i][j] += 1000;
					}
					if (((map[i][j - 2] == 1) || (map[i][j - 2] == 4)) && ((map[i][j - 1] == 1) || map[i][j - 1] == 4))
					{
						map1[i][j] += 50;
					}
					if (((map[i][j - 1] == 1) || map[i][j - 1] == 4))
					{
						map1[i][j] += 1;
					}
					//下白棋
					if (((map[i][j - 3] == 2) || (map[i][j - 3] == 5)) && ((map[i][j - 2] == 2) || (map[i][j - 2] == 5)) && ((map[i][j - 1] == 2) || map[i][j - 1] == 5))
					{
						map1[i][j] += 1000;
					}
					if (((map[i][j - 2] == 2) || (map[i][j - 2] == 5)) && ((map[i][j - 1] == 2) || map[i][j - 1] == 5))
					{
						map1[i][j] += 50;
					}
					if (((map[i][j - 1] == 2) || map[i][j - 1] == 5))
					{
						map1[i][j] += 10;
					}
				}
				if ((j +3)<H)			
				{
					if (((map[i][j + 3] == 1) || (map[i][j + 3] == 4)) && ((map[i][j + 2] == 1) || (map[i][j + 2] == 4)) && ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
					{
						map1[i][j] += 1000;
					}
					if (((map[i][j + 2] == 1) || (map[i][j + 2] == 4)) && ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
					{
						map1[i][j] += 50;
					}
					if ( ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
					{
						map1[i][j] += 1;
					}

					if (((map[i][j + 3] == 2) || (map[i][j + 3] == 5)) && ((map[i][j + 2] == 2) || (map[i][j + 2] == 5)) && ((map[i][j + 1] == 2) || map[i][j + 1] == 5))
					{
						map1[i][j] += 1000;
					}
					if (((map[i][j + 2] == 2) || (map[i][j + 2] == 5)) && ((map[i][j + 1] == 2) || map[i][j + 1] == 5))
					{
						map1[i][j] += 50;
					}
					if (((map[i][j + 1] == 2) || map[i][j + 1] == 5))
					{
						map1[i][j] += 10;
					}
				}

				if (((j - 3)>-1)&&((i - 3)>-1))		//  \向
				{
					//堵黑棋
					if (((map[i-3][j - 3] == 1) || (map[i-3][j - 3] == 4)) && ((map[i-2][j - 2] == 1) || (map[i-2][j - 2] == 4)) && ((map[i-1][j - 1] == 1) || map[i-1][j - 1] == 4))
					{
						map1[i][j] += 1000;
					}
					if ( ((map[i - 2][j - 2] == 1) || (map[i - 2][j - 2] == 4)) && ((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
					{
						map1[i][j] += 50;
					}
					if (((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
					{
						map1[i][j] += 1;
					}
					//下白棋
					if (((map[i - 3][j - 3] == 2) || (map[i - 3][j - 3] == 5)) && ((map[i - 2][j - 2] == 2) || (map[i - 2][j - 2] == 5)) && ((map[i - 1][j - 1] == 2) || map[i - 1][j - 1] == 5))
					{
						map1[i][j] += 1000;
					}
					if (((map[i - 2][j - 2] == 2) || (map[i - 2][j - 2] == 5)) && ((map[i - 1][j - 1] == 2) || map[i - 1][j - 1] == 5))
					{
						map1[i][j] += 50;
					}
					if (((map[i - 1][j - 1] == 2) || map[i - 1][j - 1] == 5))
					{
						map1[i][j] += 10;
					}

				}
				if (((j + 3)<H) && ((i + 3)<H))		
				{
					if (((map[i + 3][j + 3] == 1) || (map[i + 3][j + 3] == 4)) && ((map[i + 2][j + 2] == 1) || (map[i + 2][j + 2] == 4)) && ((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
					{
						map1[i][j] += 1000;
					}
					if (((map[i + 2][j + 2] == 1) || (map[i + 2][j + 2] == 4)) && ((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
					{
						map1[i][j] += 50;
					}
					if (((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
					{
						map1[i][j] += 1;
					}

					if (((map[i + 3][j + 3] == 2) || (map[i + 3][j + 3] == 5)) && ((map[i + 2][j + 2] == 2) || (map[i + 2][j + 2] == 5)) && ((map[i + 1][j + 1] == 2) || map[i + 1][j + 1] == 5))
					{
						map1[i][j] += 1000;
					}
					if (((map[i + 2][j + 2] == 2) || (map[i + 2][j + 2] == 5)) && ((map[i + 1][j + 1] == 2) || map[i + 1][j + 1] == 5))
					{
						map1[i][j] += 50;
					}
					if (((map[i + 1][j + 1] == 2) || map[i + 1][j + 1] == 5))
					{
						map1[i][j] += 10;
					}
				}

				if (((i-3)>-1)&&((j+3)<H))		//  /向
				{
					//堵黑棋
					if (((map[i - 3][j + 3] == 1) || (map[i - 3][j + 3] == 4)) && ((map[i - 2][j + 2] == 1) || (map[i - 2][j + 2] == 4)) && ((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
					{
						map1[i][j] += 1000;
					}
					if (((map[i - 2][j + 2] == 1) || (map[i - 2][j + 2] == 4)) && ((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
					{
						map1[i][j] += 50;
					}
					if (((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
					{
						map1[i][j] += 1;
					}
					//下白棋
					if (((map[i - 3][j + 3] == 2) || (map[i - 3][j + 3] == 5)) && ((map[i - 2][j + 2] == 2) || (map[i - 2][j + 2] == 5)) && ((map[i - 1][j + 1] == 2) || map[i - 1][j + 1] == 5))
					{
						map1[i][j] += 1000;
					}
					if (((map[i - 2][j + 2] == 2) || (map[i - 2][j + 2] == 5)) && ((map[i - 1][j + 1] == 2) || map[i - 1][j + 1] == 5))
					{
						map1[i][j] += 50;
					}
					if (((map[i - 1][j + 1] == 2) || map[i - 1][j + 1] == 5))
					{
						map1[i][j] += 10;
					}
				}
				if (((i + 3)<H) && ((j - 3)>-1))		
				{
					if (((map[i + 3][j - 3] == 1) || (map[i + 3][j - 3] == 4)) && ((map[i + 2][j - 2] == 1) || (map[i + 2][j - 2] == 4)) && ((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
					{
						map1[i][j] += 1000;
					}
					if (((map[i + 2][j - 2] == 1) || (map[i + 2][j - 2] == 4)) && ((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
					{
						map1[i][j] += 50;
					}
					if (((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
					{
						map1[i][j] += 1;
					}

					if (((map[i + 3][j - 3] == 2) || (map[i + 3][j - 3] == 5)) && ((map[i + 2][j - 2] == 2) || (map[i + 2][j - 2] == 5)) && ((map[i + 1][j - 1] == 2) || map[i + 1][j - 1] == 5))
					{
						map1[i][j] += 1000;
					}
					if (((map[i + 2][j - 2] == 2) || (map[i + 2][j - 2] == 5)) && ((map[i + 1][j - 1] == 2) || map[i + 1][j - 1] == 5))
					{
						map1[i][j] += 50;
					}
					if (((map[i + 1][j - 1] == 2) || map[i + 1][j - 1] == 5))
					{
						map1[i][j] += 10;
					}
				}
			}
		}
	}

	int x = 0, y = 0;
	do
	{
		x = rand()%H;
		y = rand() % H;
	} while ((map[x][y]==0)||(map[x][y]==3));
	
	int max=map1[0][0];
	for (int  i = 0; i < H; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (map1[i][j]>max)
			{
				max = map1[i][j];
				x = i, y = j;
			}
		}
	}

	map[x][y] = 2;
	check(x, y);
}


//光标移动
struct cursor move(struct cursor pp)
{
	char ch;
	scanf("%c",&ch);
	fflush(stdin);
	if (ch=='p')
	{
		if ((map[pp.x][pp.y]==3))
		{
			map[pp.x][pp.y] = 4;
			check(pp.x,pp.y);
			ai();
		}
	}


	if (map[pp.x][pp.y] == 3)
	{
		map[pp.x][pp.y] = 0;
	}
	if (map[pp.x][pp.y] == 4)
	{
		map[pp.x][pp.y] = 1;
	}
	if (map[pp.x][pp.y] == 5)
	{
		map[pp.x][pp.y] = 2;
	}

	if (ch=='w')
		{	
			pp.x = pp.x - 1;
			if ((pp.x)<0)
			{
				pp.x = 14;
			}
		}
	if (ch=='a')
		{
			pp.y = pp.y - 1;
			if (pp.y<0)
			{
				pp.y = 14;
			}

		}
	if (ch=='s')
		{
			pp.x = pp.x + 1;
			if ((pp.x)>14)
			{
				pp.x =0;
			}
		}
	if (ch=='d')
		{
			pp.y = pp.y + 1;
			if ((pp.y)==14)
			{
				pp.y = 0;
			}
		}

	if (map[pp.x][pp.y] ==0)
	{
		map[pp.x][pp.y] = 3;
	}
	if (map[pp.x][pp.y] == 1)
	{
		map[pp.x][pp.y] = 4;
	}
	if (map[pp.x][pp.y] == 2)
	{
		map[pp.x][pp.y] = 5;
	}

	return pp;
}


//总界面
void m()
{
	point = move(point);
	prin();
}

int main()
{
	ini();
	point.x = 7;
	point.y = 7;
	map[point.x][point.y] = 3;
	prin();
	while (true)
	{
		m();
	}
	system("pause");
}