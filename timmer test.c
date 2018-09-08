#include<REGX52.H>

int a[303];
int led,index=1;
void timmer0_10ms(void) interrupt 1
{ led=a[index]
	if(index>=303)index=0;
	else index++;
	while(TF1!=1);
	TF0=1;
	TF1=1;
	
	TF0=1;
	TF1=1;
	
}

void timmer1_10us(void) interrupt 3
{
	
}

void main()
{	
    int i,b=0;
    for(i=1;i<=303;i++)
    {
        a[i]=b;
        if((i%3)==0)b++;
    }
	
	//Timmer configuration started
	
	TMOD=0X12;
	//enable timmer interupt 
	ET0=1;
	ET1=1;
	
	//clear timmer flag	
	TF0=0;
	TF1=0;
	
	
	TH1=0x000a;
	TL1=0x0000;
	TL0=0xd8ef;  //55535
	//timmer configured
	TR0=1;
	TR1=1;

}
	
	