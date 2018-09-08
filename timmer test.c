#include<REGX52.H>
//P2_0

int a[103];
int led,index=1;

void timmer0_10ms(void) interrupt 1
{ led=a[index];
	if(index>=103)index=0;
	else index++;
	
	while(TF1!=1);//can be ommited
	TF0=0;
	TF1=0;
	
	TR0=1; //starting both the timmers again
	TR1=1;
	
}

void timmer1_10us(void) interrupt 3
{
	if(led<=0)P2_0=1;
	else			P2_0=0;
	led=led-1;
	
	//resetting flag and autoreloading
	TF1=0;
	TR1=1;
}

void main()
{	
    int i,b=0;
    for(i=1;i<=103;i++)
    {
        a[i]=b;
        if((i%3)==0)b++;
    }
	
	//Timmer configuration started
	
	TMOD=0x12;
	//enable timmer interupt 
	ET0=1;
	ET1=1;
	
	//clear timmer flag	
	TF0=0;
	TF1=0;
	
	
	TH1=0xf5;
	//TL1=0xf5;
	
	TH0=0xd8;
	TL0=0xef;  //55535
	//timmer configured
	TR0=1;
	TR1=1;
}	