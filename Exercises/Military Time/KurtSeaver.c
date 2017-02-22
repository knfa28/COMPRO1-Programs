/********************************************************************************
Program name: Time Converter version 3

Programmed by: Kurt Aquino & Seaver Choy
Section: S21A

Last edited on: 07/10/2013

This program will ask the user to input a time in military format, then the
program will convert it to a 12 hr format and display it in words.
********************************************************************************/
#include<stdio.h>

/* checks if input hour value is valid */
int isValidHour(int nHrs)
{
    if(nHrs < 0 || nHrs > 23)
       return 0;
    else
       return 1;
}

/* checks if input minute value is valid */
int isValidMinutes(int nMins)
{
    if(nMins < 0 || nMins > 59)
       return 0 ;
    else
	   return 1;
}

/*converts military time to 12 hr format*/
int format12Hr(int nHour, int nMinute, int *nHrs, char *cAMPM)
{    
	 /*checks if the hour value and the minute value is valid*/
     if(nHour == 1 && nMinute == 1)
     {   
         if(*nHrs == 0)         /*if input time is 0*/
         {
         	*nHrs += 12;        /*converts the value of nHrs to 12*/
         	*cAMPM = 'a';       /*displays am*/
         } 

		 else if(*nHrs == 12)   /*if military time input is equal to 12*/
            *cAMPM = 'p';       /*displays pm*/        

         else if(*nHrs > 12)    /*if military time input is greater than 12*/
         {
            *nHrs = *nHrs % 12; /*converts the input hour value to 12 hr format*/
            *cAMPM = 'p';       /*displays pm*/
         }		 

         else
            *cAMPM = 'a';       /*displays am*/
			        
		 return 1;
     }
     else
        return 0;   
}

/*displays the 12 hr format of the given time*/
void toTime(int nHrs,int nMins, char cAMPM)
{
     if(nMins<10)/*if minutes is less than 10*/
        printf("%d:0%d %cm", nHrs, nMins, cAMPM);/*add 0 to the display*/
     else
        printf("%d:%d %cm", nHrs, nMins, cAMPM);
}
     
/*displays the written equivalent of the given time*/
void toWord(int nHrs, int nMins)
{
	switch(nHrs) /*gets the written equivalent of the hours*/
	{
		case 1:
		    printf("\nIt is one");
			break;		
		case 2:
			printf("\nIt is two");
			break;
		case 3:
			printf("\nIt is three");
			break;
		case 4:
			printf("\nIt is four");
			break;
		case 5:
			printf("\nIt is five");
			break;
		case 6:
			printf("\nIt is six");
			break;
		case 7:
			printf("\nIt is seven");
			break;
		case 8:
			printf("\nIt is eight");
			break;
		case 9:
			printf("\nIt is nine");
			break;
		case 10:
			printf("\nIt is ten");
			break;
		case 11:
			printf("\nIt is eleven");
			break;
		case 12:	
		    printf("\nIt is twelve");
		    break;
	}
	
	/*gets the written equivalent of the minutes*/
	if( nMins >= 10 && nMins < 20)/*displays the minutes greater than
	                                or equal to 10 and less than 20*/
	{
		switch(nMins % 10)
        {
        	case 1:
			    printf(" eleven");
			    break;
		    case 2:
			    printf(" twelve");
			    break;
		    case 3:
			    printf(" thirteen");
			    break;
		    case 4:
		    	printf(" fourteen");
		    	break;
		    case 5:
			    printf(" fifteen");
			    break;
		    case 6:
		     	printf(" sixteen");
		     	break;
	 	    case 7:
			    printf(" seventeen");
			    break;
		    case 8:
			    printf(" eighteen");
			    break;
		    case 9:
			    printf(" nineteen");
			    break;
			default:
				printf(" ten");
        }
	}
    
	/*displays the tens unit of the minutes greater
	  than or equal to 20 and less than 60*/  
    if(nMins >= 20 && nMins < 30)
        printf(" twenty");
    
	else if(nMins >= 30 && nMins < 40)
        printf(" thirty");
    
	else if(nMins >= 40 && nMins < 50)
        printf(" forty");
    
	else if(nMins >= 50 && nMins < 60)
        printf(" fifty");
        
    if(nMins > 0 && nMins < 10)/*displays "o' <minute>" for single digit minutes*/
	       printf(" o' ");
	
	else if(nMins >= 20 && nMins % 10 != 0)/*displays "<tens>-<ones>"
	                                        for two digit minutes*/
	       printf("-"); 
		      
	if(nMins >= 0 && nMins < 60)/*displays the ones unit of the minutes*/
	{	
	    if(nMins < 10 || nMins > 20)
	    {
	    	switch(nMins % 10)
	        {
		       case 1:
			       printf("one");
			       break;
		       case 2:
			       printf("two");
			       break;
		       case 3:
			       printf("three");
			       break;
	           case 4:
			       printf("four");
			       break;
	    	   case 5:
	    		   printf("five");
	    		   break;
			   case 6:
				   printf("six");
			   	   break;
		       case 7:
				   printf("seven");
				   break;
			   case 8:
				   printf("eight");
				   break;
			  case 9:
				   printf("nine");
				   break;
	       }
	    }		
   } 
}
    
int main()
{
    /*variable declaration*/
	int nTime,   /*input time*/
	    nHrs,    /*hour value*/
		nMins,   /*minute value*/
		nHour,   /*stores the result of isValidHour*/
		nMinute, /*stores the result of isValidMinutes*/
		nFrmt;   /*stores the result of format12Hr*/
    char cAMPM;  /*am or pm*/
    
    /*asks for user input*/
    printf("Please input time in military format: ");
    scanf("%d", &nTime);
    
	nHrs = nTime / 100;  /*gets the hour value of the input time*/
    nMins = nTime % 100; /*gets the minute value of the input time*/

    nHour = isValidHour(nHrs);       /*stores the result of isValidHour*/
    nMinute = isValidMinutes(nMins); /*stores the result of isValidMinutes*/
    
    /*stores the result of format12Hr*/
    nFrmt = format12Hr(nHour, nMinute, &nHrs, &cAMPM);
    
    if(nFrmt == 0)
       printf("\nInvalid Input"); /*displays error message*/
    else
    {
        /*displays results*/
        toTime(nHrs, nMins, cAMPM);
		toWord(nHrs, nMins);
		printf(" %cm\n", cAMPM);
    }

    return 0;
}        
