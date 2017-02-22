/*******************************************************************************
Program Name: 1 vs. 1 Me Bro

Created by: Ryan Austin Fernandez
Last Edited: June 13, 2013

This program is a simulation of a 1 vs. 1 Turn Based Rendition of League of 
Legends.
*******************************************************************************/

#include <stdio.h>
#include <math.h>

typedef float arrData[12];
typedef char strWord[20];
typedef strWord arrWords[10];

/*this function will take the user's inputted champion code and write that 
champion's stats to the player's array*/
void writeChampionStats( int nChampCode, arrData aPlayer )
{
	/*Elements are as follows: HP, Attack Power, Heal Amount*/
    arrData aGaren = { 900, 100, 150 };
    arrData aHeimerdinger = { 600, 80, 80 };
    arrData aAshe = { 750, 150, 100 };
    
    switch( nChampCode )
    {
    	case 1:
    		/*writes champion code*/
    		aPlayer[0] = nChampCode;
    		
    		/*writes Hit Point data*/
    		aPlayer[1] = aPlayer[9] = aGaren[0];
    		
    		/*writes attack power*/
    		aPlayer[5] = aGaren[1];
    		
    		/*writes heal points*/
    		aPlayer[6] = aGaren[2];
			break;
		case 2:
    		aPlayer[0] = nChampCode;
    		aPlayer[1] = aPlayer[9] = aHeimerdinger[0];
    		aPlayer[5] = aHeimerdinger[1];
    		aPlayer[6] = aHeimerdinger[2];
			break;
		case 3:
    		aPlayer[0] = nChampCode;
    		aPlayer[1] = aPlayer[9] = aAshe[0];
    		aPlayer[5] = aAshe[1];
    		aPlayer[6] = aAshe[2];
			break;
		default:
			break;
    }
}

/*uses champion's normal ability*/
void usePassiveAbility( arrData aOffense, arrData aDefense )
{
	int nChampCode = aOffense[0];
	
	/*determines the specific ability for a champion given its champion code*/
	switch( nChampCode )
	{
		case 1:
			/*restores 10 HP*/
			if( aOffense[1] + 10 > aOffense[9] )
			   aOffense[1] = aOffense[9];
			else
			   aOffense[1] += 10;
			
			printf("Player %.0f Garen restores 10 HP\n", aOffense[10]);
			break;
		case 2:
			/*heals allied turret*/
			if( aOffense[2] > 985 )
			   aOffense[2] = 1000;
			else
			   aOffense[2] += 15;
			printf("Player %.0f Heimerdinger restores 15 HP to allied turret\n", aOffense[10]);
			break;
		case 3:
			/*deals 15 damage to enemy champion*/
			if( aDefense[1] < 15)
			   aDefense[1] = 0;
			else
			   aDefense[1] -= 15;
			printf("Player %.0f Ashe deals 15 damage to enemy champion\n", aOffense[10]);
			break;
		default:
			break;
	}
}

/*This function gets data from the player arrays and kills an opponent minion*/
void killMinion( arrData aOffense, arrData aDefense )
{
	arrWords aChamps = {"\0", "Garen", "Heimerdinger", "Ashe" };
	int nChampCode = aOffense[0];
	
	/*a minion is deducted from the current minion count*/
	if( aDefense[3] < 0 )
       aDefense[3]--;
	
	/*The killed minion is added to the attackers minion kill count*/
	aOffense[4]++;
	
	printf("\nPlayer %.0f %s kills a minion!", aOffense[10], aChamps[nChampCode]);
}

/*This function gets data from the player arrays and deals appropriate damage*/
void attackOpponent( arrData aOffense, arrData aDefense )
{
	arrWords aChamps = { "\0", "Garen", "Heimerdinger", "Ashe" };
	int nChampCode = aOffense[0];
	
	/*Attacked player's champion loses HP equal to attack points of attacker*/
	aDefense[1] -= aOffense[5];
	if(aDefense[1] < 0)
	   aDefense[1] = 0;
	
	/*Attacking player's champion loses HP based on attacked player's troops*/
	aOffense[1] -= 25 * aDefense[3];	
	if(aOffense[1] < 0)
	   aOffense[1] = 0;
	   
	printf("\nPlayer %.0f %s attacks enemy opponent, dealing %.0f%s%.0f recoil from minions!", 
	       aOffense[10], aChamps[nChampCode], aOffense[5], " damage and receiving ", 
		   25 * aDefense[3]);
}

/*takes the player arrays to process turret attack action*/
void attackTurret( arrData aOffense, arrData aDefense )
{
	float fDamage, fRecoil;
	arrWords aChamps = { "\0", "Garen", "Heimerdinger", "Ashe" };
	int nChampCode = aOffense[0];
	
	/*deals damage to turret*/
	fDamage = ceilf(ceilf(aDefense[2] / 100) / 10 * aOffense[5]);
	
	/*ensures opponent's champion's HP does not drop below zero*/
	if( aDefense[2] < fDamage )
	   aDefense[2] = 0;
	else
	   aDefense[2] -= fDamage;
	   
	/*deals recoil damage to attacker*/
	fRecoil = ceilf( ( 1- floorf(aDefense[2] / 100) / 10 ) * 250 );
	
	/*ensures attacker's champion's HP does not drop below zero*/
	if( aOffense[1] < fRecoil)
	   aOffense[1] = 0;
	else
	   aOffense[1] -= fRecoil;
	   
	printf("\nPlayer %.0f %s attacks enemy turret, dealing %.0f damage and receiving %.0f recoil!", 
	       aOffense[10], aChamps[nChampCode], fDamage, fRecoil);
}

/*uses champion's normal ability*/
void useNormalAbility( arrData aOffense, arrData aDefense )
{
	int nChampCode = aOffense[0];
	arrWords aChamps = { "\0", "Garen", "Heimerdinger", "Ashe" };
	
	printf("\nPlayer %.0f %s uses normal ability, ", 
	       aOffense[10], aChamps[nChampCode]);
	/*determines the specific ability for a champion given its champion code*/
	switch( nChampCode )
	{
		case 1:
			/*attacks enemy turret*/
			if( aDefense[2] < 100)
			   aDefense[2] = 0;
			else
			   aDefense[2] -= 100;
			printf("dealing 100 damage to enemy turret.");
			break;
		case 2:
			/*replenishes allied minions*/
			if( aOffense[3] > 3 )
			   aOffense[3] = 5;
			else
			   aOffense[3] += 2;
			printf("adding 2 allied minions.");
			break;
		case 3:
			/*attacks enemy minions*/
			if( aDefense[3] < 3)
			{
	           aOffense[4] += aDefense[3];
			   aDefense[3] = 0;
		    }   
			else
			{
			   aOffense[4] += 3;
			   aDefense[3] -= 3;
		    }
			printf("killing 3 enemy minions.");
			break;
		default:
			break;
	}
	/*resets cooldown timer*/
	aOffense[7] = 2;
}

/*uses champion's ultimate ability*/
void useUltimateAbility( arrData aOffense, arrData aDefense )
{
	int nChampCode = aOffense[0], nDamage;
	arrWords aChamps = { "\0", "Garen", "Heimerdinger", "Ashe" };
	
	printf("\nPlayer %.0f %s uses ultimate ability, ", 
	       aOffense[10], aChamps[nChampCode]);
	
	/*determines the specific ability for a champion given its champion code*/
	switch( nChampCode )
	{
		case 1:
			/*Deals damage equal to 20% of opponent's lost HP*/
			nDamage = (aDefense[9] - aDefense[1]) * 20 / 100;
			if( aDefense[1] < nDamage)
			   aDefense[1] = 0;
			else
			   aDefense[1] -= nDamage;
			printf("dealing %d damage.", nDamage);
			break;
		case 2:
			/*Heals allied turret by 200 pts.*/
			if( aOffense[2] > 800 )
			   aOffense[2] = 1000;
			else
			   aOffense[2] += 200;
			printf("restoring 200 HP to allied turret.");
			break;
		case 3:
			/*Attacks opponent's champion*/
			if( aDefense[1] < 300)
			   aDefense[1] = 0;
			else
			   aDefense[1] -= 300;
			printf("dealing 300 damage to enemy champion.");
			break;
		default:
			break;
	}
	
	/*resets cooldown timer*/
	aOffense[8] = 5;
}

/*heals champion's HP*/
float healChamp( arrData aPlayer )
{
	int nChampCode = aPlayer[0];
	arrWords aChamps = { "\0", "Garen", "Heimerdinger", "Ashe" };
	
	printf("\nPlayer %.0f %s heals %.0f HP.", 
	       aPlayer[10], aChamps[nChampCode], aPlayer[6]);
	       
	/*ensure's player's champion's HP does not exceed max HP*/
	if( aPlayer[1] + aPlayer[6] > aPlayer[9] )
	   return aPlayer[9];
	else
	   return aPlayer[1] + aPlayer[6];
}

/*displays current status of 1v1 match*/
void displayCurrentStatus( arrWords aStats, arrData aPlayer1, arrData aPlayer2 )
{
	int nCtr;
	
	printf("\nCurrent Status:\n\n");
	
	printf("   Player 1:\n");
	for( nCtr = 1; nCtr <= 4; nCtr++ )
    	printf("     %s: %.0f\n", aStats[nCtr], aPlayer1[nCtr]);
    	
    printf("\n   Player 2:\n");
	for( nCtr = 1; nCtr <= 4; nCtr++ )
    	printf("     %s: %.0f\n", aStats[nCtr], aPlayer2[nCtr]);

	printf("\n\n");
}

/*does the actions for the Upkeep phase*/
void upkeepPhase( arrData aPlayer1, arrData aPlayer2, int nTurnCount )
{
	/*calls passive ability function*/
	usePassiveAbility( aPlayer1, aPlayer2 );
	usePassiveAbility( aPlayer2, aPlayer1 );
	
	/*replenishes players minion every seven(7) turns*/
	if( nTurnCount % 7 == 0 )
	{
	   aPlayer1[3] = aPlayer2[3] = 5;
	   printf("A new minion wave approaches. Both player's minion counts have been restored.\n");
    }
}

/*does the actions for selection phase*/
int selectionPhase( arrData aPlayer )
{
	int nChoice, nPass;
	char cNull;
	
	printf("Player %.0f, select your action\n%s\n%s\n%s\n%s\n%s\n%s\n", 
	       aPlayer[10], "   [1] Kill minion", "   [2] Attack champion", 
		   "   [3] Attack Turret", "   [4] Use normal ability", 
		   "   [5] Use ultimate ability", "   [6] Heal" );
	do
	{
	   nPass = 1;
	   scanf("%d%c", &nChoice, &cNull);
	   switch( nChoice )
	   {
	      case 4:
	   		if( aPlayer[7] > 0)
	   		{
	   		   printf("\nWait %.0f more turns to use that.%s", aPlayer[7], 
				      " Choose another action: " );
			   nPass = 0;
		    }
			break;
	      case 5:
			if( aPlayer[8] > 0)
	   		{
	   		   printf("\nWait %.0f more turns to use that.%s", aPlayer[8], 
				      " Choose another action: " );
			   nPass = 0;
		    }
		    break;
	      default:
	      	if( nChoice < 1 || nChoice > 6 )
	      	{
			   printf("Choose a valid action: ");
			   nPass = 0;
		    }
			break;
	   }
    }while( nPass == 0 );
	return nChoice;
}

void actionPhase( arrData aOffense, arrData aDefense )
{
	int nArg = aOffense[11];
	
	switch( nArg )
	{
		case 1:
			killMinion( aOffense, aDefense);
			break;
		case 2:
			attackOpponent( aOffense, aDefense );
			break;
		case 3:
			attackTurret( aOffense, aDefense );
			break;
		case 4:
			useNormalAbility( aOffense, aDefense );
			break;
		case 5:
			useUltimateAbility( aOffense, aDefense );
			break;
		case 6:
			aOffense[1] = healChamp( aOffense );
	}
}

/*resets a player array*/
void resetPlayerArray(arrData aPlayer)
{
	int nCtr;
	
	for( nCtr = 0; nCtr < 10; nCtr++ )
	{
		switch(nCtr)
		{
			case 2:
				aPlayer[nCtr] = 1000;
				break;
			case 3:
				aPlayer[nCtr] = 5;
				break;
			case 7:
				aPlayer[nCtr] = 1;
				break;
			case 8:
				aPlayer[nCtr] = 4;
				break;
			default:
				aPlayer[nCtr] = 0;
				break;
		}
	}
}

int main()
{
   /*variable declaration*/
    
   /*Array Declaration: Elements are as follows: Champion Code, HP, Turret HP, 
   Minion Count, Minions Killed, Attack Power, Heal Amount, Normal Ability 
   Cooldown Time, Ultimate Ability Cooldown Time, Champ Full Health, Player index, 
   and Action Choice Code*/
   arrWords aPArray = { "", "Champion HP", "Turret HP", "Minion Count", 
                       "Minions Killed"};
   arrData aPlayer1 = { 0, 0, 1000, 5, 0, 0, 0, 2, 5, 0, 1, 0 };
   arrData aPlayer2 = { 0, 0, 1000, 5, 0, 0, 0, 2, 5, 0, 2, 0 };
   
   int nChampCode, nTurnCount, nP1Win = 0, nP2Win = 0;
   char cCont, cNull;
   
   do
   {
   	/*resets player arrays*/
   	resetPlayerArray(aPlayer1);
   	resetPlayerArray(aPlayer2);
   	
	printf("**********1 vs. 1 Me Bro!**********");
   	
   	/*character selection*/
   	printf("\n\nChampion Selection Screen\n");
   	
   	/*Player 1 champion selection*/
   	printf("\nPlayer 1, choose your champion\n%s%s%s", "   1. Garen\n", 
	       "   2. Heimerdinger\n", "   3. Ashe\n");
	printf("Enter your chosen champion's number: ");
	do
	{
	   scanf("%d%c", &nChampCode, &cNull);
	   if( nChampCode < 1 || nChampCode > 3 )
	     printf("\nPlease enter valid Champion Code: ");
    }while( nChampCode < 1 || nChampCode > 3 );
    writeChampionStats( nChampCode, aPlayer1 );
    
    /*Player 2 champion Selection*/
   	printf("\nPlayer 2, choose your champion\n%s%s%s", "   1. Garen\n", 
	       "   2. Heimerdinger\n", "   3. Ashe\n");
	printf("Enter your chosen champion's number: ");
	do
	{
	   scanf("%d%c", &nChampCode, &cNull);
	   if( nChampCode < 1 || nChampCode > 3 )
	     printf("\nPlease enter valid Champion Code: ");
    }while( nChampCode < 1 || nChampCode > 3 );
    writeChampionStats( nChampCode, aPlayer2 );
    
    /*Game proper*/
    nTurnCount = 1;\
    printf("\nGAME STARTING");
    do
    {
    	printf("\n");
        system("pause");
   	
    	/*if game moves on to subsequent turns, it alerts the players that 
		there is still no winner*/
    	if (nTurnCount >= 2)
    	  printf("No winner yet");
    	  
    	printf("\nTurn %d\n\n", nTurnCount);
    	
    	/*UPKEEP PHASE*/
    	printf("Upkeep Phase: \n");
    	upkeepPhase( aPlayer1, aPlayer2, nTurnCount);
    	
    	/*calls function to display current player stats*/
    	displayCurrentStatus( aPArray, aPlayer1, aPlayer2 );
    	
    	/*SELECTION PHASE*/
    	printf("\nSelection Phase: \n");
    	aPlayer1[11] = selectionPhase(aPlayer1);
    	aPlayer2[11] = selectionPhase(aPlayer2);
    	
    	/*ACTION PHASE*/
    	printf("\nAction Phase: \n");
    	actionPhase( aPlayer1, aPlayer2 );
    	actionPhase( aPlayer2, aPlayer1 );
    	
    	/*END PHASE*/
    	printf("\n\nEnd Phase: ");
    	displayCurrentStatus( aPArray, aPlayer1, aPlayer2 );

    	
    	/*Increments turn counter*/
    	nTurnCount++;
    	
    	/*decreases cooldown time*/
    	if( aPlayer1[7] > 0)
    	   aPlayer1[7]--;
    	   
    	if( aPlayer1[8] > 0)
    	   aPlayer1[8]--;
    	   
    	if( aPlayer2[7] > 0)
    	   aPlayer2[7]--;
    	   
    	if( aPlayer2[8] > 0)
    	   aPlayer2[8]--;
    	
    }while( aPlayer1[1] != 0 && aPlayer2[1] != 0 && aPlayer1[2] != 0 && 
	        aPlayer2[2] != 0 && aPlayer1[4] != 100 && aPlayer2[4] != 100);
	
	/*determines who is the winner*/
	if( aPlayer1[1] == 0 )  
	{
	   nP2Win = 1;
	   printf("\nPlayer 1's champion was killed...");
    } 
	if( aPlayer2[1] == 0 )
	{
		nP1Win = 1;
		printf("\nPlayer 2's champion was killed...");
	}
	if( aPlayer1[2] == 0 )
	{
		nP2Win = 1;
		printf("\nPlayer 2 destroyed Player 1's turret...");
	}
	if( aPlayer2[2] == 0 )
	{
		nP1Win = 1;
		printf("\nPlayer 1 destroyed Player 2's turret...");
	}
	if( aPlayer1[4] == 100 )
	{
		nP1Win = 1;
		printf("Player 1 killed 100 minions.");
	}
	if( aPlayer2[4] == 100 )
	{
		nP2Win = 1;
		printf("Player 2 killed 100 minions");
	}
	
	if( nP1Win == 1 && nP2Win == 0 )
	   printf("\nPLAYER 1 WINS!");
	else if( nP2Win == 1 && nP1Win == 0 )
	   printf("\nPLAYER 2 WINS!");
	else
	   printf("\nIT'S A TIE!");
	
	/*determines if game will run again*/
	printf("\nDo you want to play again(Y/N)?: ");
	/*ensures valid input*/
	do
	{
    	scanf("%c%c", &cCont, &cNull);
    	if( !( cCont == 'Y' || cCont == 'y' || cCont == 'N' || cCont == 'n' ) )
    	   printf("\nPlease enter a valid input(Y/N): ");
    }while( !( cCont == 'Y' || cCont == 'y' || cCont == 'N' || cCont == 'n' ) );
    
    printf("\n\n");
    
   }while( cCont != 'n' && cCont != 'N' );
   
   return 0;
}
