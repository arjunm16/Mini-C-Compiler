
int fun(int x)
{
 x=x+1;
return x;
}

int main()
{
	int a;
	int b=5;
	for(a=1;a<10;a=a+1)
	{
	  for(b=10; b>0; b=b-1){
		a = a + 1;
	  }
	printf("%d", a);
	}
	// comment
	if(a>10){
	  printf("%d %d", a, b);
	}
	else
	  {
	  a=a-1;
	  b=b+1;
	  printf("%d %d", a, b);
	  
	  }
	a=fun(10);
	printf("%d",a); 

return 1;
}

