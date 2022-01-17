#include"BT19CSE070_Bigint.h"
#include<stdlib.h>
#include<conio.h>

int main()
{
   int quit,option;
   
   Big_int opr1;
   Big_int opr2;
   Big_int result;
   
   quit = 0;
   
   while(!(quit))
   {
   	  printf("................................Heyy User....................................\n\n");
   	  printf(".....................Welcome to the \"Wonderland of Big ints\"....................\n\n");
      printf("Enter choice for operation you want to perform:\n\n");
      printf("1.Addition\n\n");
      printf("2.Substraction\n\n");
      printf("3.Multiplication\n\n");
      printf("4.I have done enough math today..Quit it\n\n");
      printf("  Your choice:\t");
      scanf("%d",&option);
      system("cls");
      switch(option)
      {
      	case 1:
      		input_big_int(&opr1,1);
      		input_big_int(&opr2,2);
      		add(&opr1,&opr2,&result);
      		show_big_int(&result);
      		printf("\n\nPress any key to go back to main menu:\n");
      		getch();
      		system("cls");
      		break;
 		case 2:
 			input_big_int(&opr1,1);
      		input_big_int(&opr2,2);
      		sub(&opr1,&opr2,&result);
      		show_big_int(&result);
      		printf("\n\nPress any key to go back to main menu:\n");
      		getch();
      		system("cls");
      		break;
  		case 3:
  			input_big_int(&opr1,1);
      		input_big_int(&opr2,2);
      		mul(&opr1,&opr2,&result);
      		show_big_int(&result);
      		printf("\n\nPress any key to go back to main menu:\n");
      		getch();
      		system("cls");
      		break;
   		case 4:
   			quit = 1;
   			break;
   			
        default:
        	printf("\n\nPerhaps you have chosen invalid option\n");
        	printf("\n\nPress any key to go back to main menu:\n");
      		getch();
      		system("cls");
      		break;
   	 }
   }
   
   

	return 0;
	
}
