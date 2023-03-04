#include<iostream>
#include<cstring>
#include<ctime>

using namespace std;

const int N = 8;
const int size = 7;

int map[N][N];

void show_map()
{
	for(int i = 0;i < size;i ++)
	{
		for(int j = 0;j < size;j ++)
		if(map[i][j] == 1)cout << '*';
		else cout << ' ';
		cout << endl;
	}
}
void swap_a()
{
	for(int i = 1;i < size - 1;i ++)
	    map[0][i] *= (-1);
	
	return;
}

void swap_b()
{
	map[1][6] *= (-1);
	map[2][6] *= (-1);
	
	return;
}

void swap_c()
{
	map[4][6] *= (-1);
	map[5][6] *= (-1);
	
	return;
}

void swap_d()
{
	for(int i = 1;i < size -1 ;i ++)
	    map[6][i] *= (-1);
	
	return;
}

void swap_e()
{
	map[4][0] *= (-1);
	map[5][0] *= (-1);
	
	return;
}

void swap_f()
{
	map[1][0] *= (-1);
	map[2][0] *= (-1);
	
	return;
}

void swap_g()
{   
    
	for(int i = 1;i < size -1 ;i ++)
		map[3][i] *= (-1);
	
	return;
}

void init()
{  
   for(int i = 0;i <N;i ++)
   for(int j = 0;j <N;j ++)
	  map[i][j] = 1;
	  
   map[0][0] = -1; map[0][6] = -1;
   map[3][0] = -1; map[3][6] = -1;
   map[6][0] = -1; map[6][6] = -1;
   
   for(int i = 1;i < size -1 ;i ++)
   {
     map[1][i] = -1; map[2][i] = -1;
     map[4][i] = -1; map[5][i] = -1;
   }
   swap_g();
}

void work(int n)
{
	if(n == 0){ swap_f();swap_e();swap_a();swap_d();}
	if(n == 1){ swap_a();swap_g();swap_e();swap_c();swap_d();}
	if(n == 2){ swap_e();swap_c();}
	if(n == 3){ swap_f();swap_a();swap_d();}
	if(n == 4){ swap_d();swap_a();swap_b();}
	if(n == 5){ swap_e();}
	if(n == 6){ swap_b();swap_d();swap_e();swap_f();swap_g();}
	if(n == 7){ swap_d();swap_e();swap_f();swap_g();}
	if(n == 8){swap_e();}
	if(n == 9){ swap_e();swap_g();}
	
	return;
}


int get_time()
{
	time_t timep;
    time(&timep);
    char tmp[256];
    //strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
    //cout << tmp << endl;
    strftime(tmp,sizeof(tmp),"%S",localtime(&timep));
    int tt = tmp[0] - '0'; tt *= 10; tt += tmp[1] - '0';
	 
	return tt;
} 
int main()
{  
   init();
   
   int before = -1;
   
   while(1) if(get_time() == 0) break;
   
    while(1)
    {    
        int t = get_time() % 10;
    	if(t == (before + 1) % 10)
    	{
    		before = t % 10;
    		system("cls");
    		show_map();
    		work(before);
		}
	}
//  show_map();
//   for(int i = 0;i< 10;i ++)
//   {
//   	system("pause");
//   	system("cls");
//   	work(i);
//   	show_map();
//   	
//   }
   
}

//  0123456
//0  *****
//1 *     *
//2 *     *
//3  ***** 
//4 *     *
//5 *     *
//6  *****



