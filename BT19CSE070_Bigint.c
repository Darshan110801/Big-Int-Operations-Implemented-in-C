#include"BT19CSE070_Bigint.h"

void init_big_int(Big_int* opr)
{
	opr->magn[0] = '\0';
	opr->sign = 0;
	opr->len = 0;
}

void show_big_int(Big_int* opr)
{
	if(opr->sign == PLUS)
	  printf("\n\nResultant Big int is:\n%s\n",opr->magn);
    else
      printf("\n\nResultant Big int is:\n-%s\n",opr->magn);
}

void input_big_int(Big_int* opr,int opr_n)
{
    int i;
	printf("Enter operand %d:\n\n",opr_n);
	scanf("%s",opr->magn);
	
	opr->len = strlen(opr->magn);
	if(opr->magn[0] == '-')
	{
		for(i=1;i<opr->len;i++)
		{
			opr->magn[i-1] = opr->magn[i];
		}
		opr->magn[opr->len-1] = '\0';
		opr->len = opr->len-1;
		opr->sign = MINUS;
	}
	else if(opr->magn[0] == '+')
	{
	    for(i=1;i<opr->len;i++)
		{
			opr->magn[i-1] = opr->magn[i];
		}
		opr->magn[opr->len-1] = '\0';
		opr->len = opr->len-1;
		opr->sign = PLUS;
	}
	else
	{
		opr->sign = PLUS;
	}
	
}

void add(Big_int* opr1,Big_int* opr2,Big_int* result)
{

	int i,j,k,u_sum,carry;
	


	if(opr1->sign == opr2->sign)
	{
		i = opr1->len-1;
		j = opr2->len-1;
		k = 0;
		carry = 0;
		u_sum = 0;
		
		while(i>=0 && j>=0)
		{
			u_sum = char_to_int(opr1->magn[i])+char_to_int(opr2->magn[j]);
			result->magn[k] = int_to_char((u_sum+carry)%10);
			carry = (u_sum+carry)/10;
			i--;
			j--;
			k++;
		}
		while(i>=0)
		{
			u_sum = char_to_int(opr1->magn[i]);
			result->magn[k] = int_to_char((u_sum+carry)%10);
			carry = (u_sum+carry)/10;
			i--;
			k++;
		}
		while(j>=0)
		{
			u_sum = char_to_int(opr2->magn[j]);
			result->magn[k] = int_to_char((u_sum+carry)%10);
			carry = (u_sum+carry)/10;
			j--;
			k++;
		}
		if(carry!=0)
        {
        	result->magn[k++] = int_to_char(carry);
		}
		result->magn[k] = '\0';
		strrev(result->magn);
		result->len = k;
		result->sign = opr1->sign;
	}

	else  if(opr1->sign == PLUS && opr2->sign == MINUS)
	{
		opr2->sign = PLUS;
		sub(opr1,opr2,result);
		opr2->sign = MINUS;
	}
	else
	{
		opr1->sign = PLUS;
		sub(opr2,opr1,result);
		opr1->sign = MINUS;
	}
}

int magn_compare(Big_int* opr1,Big_int* opr2)
{
	int  ret_val; 
	
	if(opr1->len>opr2->len)
	{
		ret_val =  1;
	}
	else if(opr1->len<opr2->len)
	{
		ret_val =  -1;
	}
	else
	{
		int i,j,flag;
		
		i = 0;
		j = 0;
		flag = 1;
		
		while(i<opr1->len && flag)
		{
			if(opr1->magn[i]>opr2->magn[j])
			{
			  ret_val = 1;
		      flag = 0;
       	    }
	        else if(opr1->magn[i]<opr2->magn[j])
	        {
        	  ret_val = -1;
        	  flag = 0;
			}
			else
			{
				i++;
				j++;
			}
		}
		if(flag) ret_val = 0;
	
	}
	
	return ret_val;
}
void magn_sub(Big_int* opr1,Big_int* opr2,Big_int* result)
{

	int i = opr1->len-1;
	int j = opr2->len-1;
	int k = 0;
	int borrow = 0,dig1,dig2;
	
	while(j>=0) //As function is only called if (magnitude of opr1)>(magnitude of opr2)
	{
		dig1 = char_to_int(opr1->magn[i]);
		dig2 = char_to_int(opr2->magn[j]);
		
		if(dig1>=(dig2+borrow))
		{
			result->magn[k] = int_to_char(dig1-dig2-borrow);
			borrow = 0;
		}
		else
		{
			result->magn[k] = int_to_char(10+dig1-dig2-borrow);
			borrow = 1;
		}
		i--;
		j--;
		k++;
		
	}
	while(i>=0)
	{
		dig1 = char_to_int(opr1->magn[i]);
		if(dig1>=borrow)
		{
			result->magn[k] = int_to_char(dig1-borrow);
			borrow = 0;
		}
		else
		{
			result->magn[k] = int_to_char(10+dig1-borrow);
			borrow = 1;
		}
		i--;
		k++;
	}
	result->magn[k] = '\0';
	strrev(result->magn);
	result->len = k;
	
	// getting rid of leading zeroes and updating structure accordingly......
	
	int first_non_zero = 0,flag = 1;
	i = 0;
	while(flag && i<result->len)
	{
	   if(result->magn[i]!='0')
	   {
	   	 flag = 0;
       }
	   else
	   {
	   	i++;
	   }	
	}
	
	if(i!=0)
	{
		for(j = i;j<result->len;j++)
		{
			result->magn[j-i] = result->magn[j];
		}
		result->magn[j-i] = '\0';  //ensuring string ends with null
		result->len = result->len-i;
	}
	
}
void sub(Big_int* opr1,Big_int* opr2,Big_int* result)
{
     if(opr1->sign == MINUS && opr2->sign == PLUS)
     {
     	opr2->sign = MINUS;
     	add(opr1,opr2,result);
     	opr2->sign = PLUS;
	 }
	 else if(opr1->sign == PLUS && opr2->sign == MINUS)
	 {
	 	opr2->sign = PLUS;
	 	add(opr1,opr2,result);
	 	opr2->sign = MINUS;
	 }
	 else if(opr1->sign == PLUS && opr2->sign == PLUS)
	 {
	 	if(magn_compare(opr1,opr2)==0)
	 	{
	 	  result->magn[0] = '0';
		  result->magn[1] = '\0';
		  result->len = 0;
		  result->sign = PLUS;
	    }
	    else if(magn_compare(opr1,opr2)==1)
	    {
    	  magn_sub(opr1,opr2,result);
    	  result->sign = PLUS;
		}
		else
		{
		  magn_sub(opr2,opr1,result);
		  result->sign = MINUS;
		}
		
	 }
	 else                        //if both signs are MINUS
	 {
	 	if(magn_compare(opr1,opr2)==0)
	 	{
	 	  result->magn[0] = '0';
		  result->magn[1] = '\0';
		  result->len = 0;
		  result->sign = PLUS;
	    }
	    else if(magn_compare(opr1,opr2)==1)
	    {
    	  magn_sub(opr1,opr2,result);
    	  result->sign = MINUS;
		}
		else
		{
		  magn_sub(opr2,opr1,result);
		  result->sign = PLUS;
		}
	 }
}
void mul_with_dig(Big_int* opr1,int digit,Big_int* result,int dig_pos)
{
	int i = 0,j,carry,un_mul;
	for(i=0;i<dig_pos;i++)
	{
		result->magn[i] = '0';
		
	}
	carry = 0;
	for(j=opr1->len-1;j>=0;j--)
	{
		un_mul = char_to_int(opr1->magn[j])*digit+carry;
		result->magn[i] = int_to_char(un_mul%10);
		carry = un_mul/10;
		i++;
	}
	if(carry != 0)
	{
		result->magn[i] = int_to_char(carry);
		i++;
	}
	result->magn[i] ='\0';
	strrev(result->magn);
	result->sign = PLUS;
	result->len = i;
}
void magn_mul(Big_int* opr1,Big_int* opr2,Big_int* result)
{
	int i,digit;
	if(strcmp(opr1->magn,"0") == 0 || strcmp(opr2->magn,"0") == 0)
     {
     	strcpy(result->magn,"0");
        result->sign = PLUS;
     	result->len = 1;
	 }
    else
     {
     	Big_int temp;
     	strcpy(temp.magn,"0");
     	temp.sign = PLUS;
     	temp.len = 1;
     	
     	strcpy(result->magn,"0");
     	result->sign = PLUS;
     	result->len = 1;
     	
     	Big_int dig_mul;
     	for(i=opr2->len-1;i>=0;i--)
     	{
     		digit = char_to_int(opr2->magn[i]);
     	  	mul_with_dig(opr1,digit,&dig_mul,opr2->len-1-i);
     	  	add(result,&dig_mul,&temp);
     	  	strcpy(result->magn,temp.magn);
     	  	result->sign = temp.sign;
     	  	result->len = temp.len;
   	  	    
     	  	
	    }
     	
	 }
}

void mul(Big_int* opr1,Big_int* opr2,Big_int* result)
{
	magn_mul(opr1,opr2,result);
	if((opr1->sign == opr2->sign) || strcmp(opr1->magn,"0")== 0 || strcmp(opr2->magn,"0")==0)
	{
		result->sign = PLUS;
	}
	else
	{
		result->sign = MINUS;
	}
}
int char_to_int(char ch)
{
	return ((int)ch-48);
}

char int_to_char(int i)
{
	return ((char)(i+48));
}
