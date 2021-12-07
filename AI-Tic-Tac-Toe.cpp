#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>

char markp,mark,choice,tempchoice,markc,namep[30],namec[30];
char check,chtemp,key[3],team[10];
char board[3][3]={'1','2','3','4','5','6','7','8','9'};
int turn,chh,ch,flag;
//FOR EXTREME
char box[9][9]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char box1[3][3]={'1','2','3','4','5','6','7','8','9'};
char box2[3][3]={'1','2','3','4','5','6','7','8','9'};
char box3[3][3]={'1','2','3','4','5','6','7','8','9'};
char box4[3][3]={'1','2','3','4','5','6','7','8','9'};
char box5[3][3]={'1','2','3','4','5','6','7','8','9'};
char box6[3][3]={'1','2','3','4','5','6','7','8','9'};
char box7[3][3]={'1','2','3','4','5','6','7','8','9'};
char box8[3][3]={'1','2','3','4','5','6','7','8','9'};
char box9[3][3]={'1','2','3','4','5','6','7','8','9'};
char winbox[9]={'1','2','3','4','5','6','7','8','9'};


/*********************************************
    FUNCTION TO RETURN GAME STATUS
    X FOR GAME IS OVER WITH X WINNING
    O FOR GAME IS OVER WITH O WINNING
    P FOR GAME IS IN PROGRESS
    D GAME IS OVER AND DRAW
**********************************************/
char checkwin()
{
    for(int i=0;i<3;i++)
    {
	//checks rows
	if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
	    return (board[i][0]);

	//checks columns
	else
	if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
	    return (board[0][i]);
    }

    //checks diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
	return (board[0][0]);

    else
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
	return (board[2][0]);

    //checks for draw
    else
    if (board[0][0]!='1' && board[0][1]!='2' && board[0][2]!='3' &&
	board[1][0]!='4' && board[1][1]!='5' && board[1][2]!='6' &&
	board[2][0]!='7' && board[2][1]!='8' && board[2][2]!='9')
	return ('D');

    else
	return ('P');
}


void colour(char value)
{
    char temp[2];
    temp[0]=value;
    temp[1]='\0';

    if(value=='X')
    {
	textcolor(12);
	cputs("X");
	textcolor(15);
    }

    else
    if(value=='O')
    {
	textcolor(10);
	cputs("O");
	textcolor(15);
    }

    else
    {
	textcolor(8);
	cputs(temp);
	textcolor(15);
    }
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/
void showboard()
{
    gotoxy(19,4);
    textcolor(11);
    cputs("TIC TAC TOE");
    textcolor(13);

    if(ch==1)
	cputs(" (Player VS Player)");

    else
    if(ch==2)
	cputs(" (Easy)");

    else
    if(ch==3)
	cputs(" (Normal)");

    else
    if(ch==4)
	cputs(" (Insane)");

/*if statement to choose find who is playing first(X) name1
  or name2 and display the coreesponding on the screen*/
    gotoxy(18,6);
    textcolor(14);

    if(markp=='X')
    {
	cputs(namep);
	textcolor(8);
	cputs(" (");
	textcolor(4);
	cputs("X");
	textcolor(8);
	cputs(") ");
	textcolor(1);
	cputs("- ");
	textcolor(14);
	cputs(namec);
	textcolor(8);
	cputs(" (");
	textcolor(2);
	cputs("O");
	textcolor(8);
	cputs(") ");
    }

    else
    {
	cputs(namec);
	textcolor(8);
	cputs(" (");
	textcolor(4);
	cputs("X");
	textcolor(8);
	cputs(") ");
	textcolor(15);
	cputs("- ");
	textcolor(14);
	cputs(namep);
	textcolor(8);
	cputs(" (");
	textcolor(2);
	cputs("O");
	textcolor(8);
	cputs(") ");
    }
    gotoxy(20,8);
    textcolor(15);

//Draw the board with respective marks
    cputs("     |     |     ");
    gotoxy(20,9);
    cout<<"  ";
    colour(board[0][0]);
    cout<<"  |  ";
    colour(board[0][1]);
    cout<<"  |  ";
    colour(board[0][2]);
    cout<<"                        SETTINGS ";
    gotoxy(20,10);
    cout << "_____|_____|_____" ;
    cout<<"                     ----------";
    gotoxy(20,11);
    cout << "     |     |     " ;
    cout<<"                 R - RESET THE GAME";
    gotoxy(20,12);
    cout<<"  ";
    colour(board[1][0]);
    cout<<"  |  ";
    colour(board[1][1]);
    cout<<"  |  ";colour(board[1][2]);
    cout<<"                S - SWITCH SYMBOLS AND RESET ";
    gotoxy(20,13);
    cout << "_____|_____|_____";
    cout<<"	                 M - MAIN MENU";
    gotoxy(20,14);
    cout << "     |     |     ";
    gotoxy(20,15);
    cout<<"  ";
    colour(board[2][0]);
    cout<<"  |  ";
    colour(board[2][1]);
    cout<<"  |  ";
    colour(board[2][2]);
    gotoxy(20,16);
    cout << "     |     |     " ;
}


/******************************************************************************
//FUNCTION TO MARK THE BOARD
******************************************************************************/
void play()
{
    //Checks if the paticular choice is empty
    for(int i=0;i<3;i++)
    {
	for(int j=0;j<3;j++)
	{
	    if(choice==board[i][j])
	    {
		board[i][j]=mark;
		return;
	    }
	}
    }
    gotoxy(19,18);
    cout<<"\n\n\t            (INVALID CHOICE)"<<endl;
    cout<<"         PRESS ENTER KEY TO RENETER YOUR CHOICE";
    while(getche()!='\r')
	cout<<"\b \b";

    if(turn<0)
	turn++;

    else
	turn--;
}


/******************************************************************************
//FUNCTION TO ACCEPT ONLY ONE CHARACTER AND RETURN IT TO THE RESPECTIVE VARIABLE
******************************************************************************/
char getone()
{
    char chc,temp;
    int p=1;

    while(p==1)
    {
	chc=getche();

	if(chc=='\b')
	{
	    cout<<" ";
	    continue;
	}
	a:temp=getche();

	if(temp=='\r')
	    p=0;

	else
	{
	    cout<<"\b";
	    cout<<" ";
	    cout<<"\b";

	    if(temp=='\b')
	    {
		cout<<"  ";
		cout<<"\b";
		continue;
	    }
	    goto a;
	}
    }
    return (chc);
}


/******************************************************************************
//FUNCTION TO ALLOT THE SYMBOLS FOR PLAYER VS PLAYER MODE
EXECUTED ONLY ONCE DURING THE BEGINING OF EACH GAME
******************************************************************************/
void markallotp()
{
    clrscr();
    cout<<"PLAYER 1 :-"<<endl;
    cout<<"Enter your name : ";
    gets(namep);
    re:cout<<"Enter your symbol (X/O) : ";
    markp=getone();
    markp=toupper(markp);

    if(markp=='X')
    {
	markc='O';
	turn=1;
    }

    else
    if(markp=='O')
    {
	markc='X';
	turn=-1;
    }

    else
    {
	cout<<endl;
	cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
	cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

	while(getche()!='\r')
	    cout<<"\b \b";
	clrscr();
	cout<<"PLAYER 1 :-"<<endl;
	cout<<"Enter your name : ";
	cout<<namep<<endl;
	goto re;
    }
    cout<<"\n\nPLAYER 2 :-"<<endl;
    cout<<"Enter your name : ";
    gets(namec);
    cout<<"Your symbol is : "<<markc;
}


/******************************************************************************
//FUNCTION TO DECIDE WHICH PLAYER IS PLAYING AND ACCEPT CHOICE AS DECIDED AND GIVE THE MARK AS DECIDED (THIS FUNCTION IS ONLY FOR PLAYER VS PLAYER)
******************************************************************************/
int playturnp()
{
    //when name1 is (X) plays first
    if(turn>0)
    {
	if(turn%2==0)
	{
	    gotoxy(16,18);
	    cout<<namec<<" Enter your choice : ";
	    choice=getone();

	    if(choice=='R'||choice=='r'||choice=='S'||choice=='s'||choice=='M'
	    ||choice=='m')
	    {
		chh=choice;
		return(0);
	    }
	    turn++;
	    mark=markc;
	}

	else
	{
	    gotoxy(16,18);
	    cout<<namep<<" Enter your choice : ";
	    choice=getone();

	    if(choice=='R'||choice=='r'||choice=='S'||choice=='s'||choice=='M'
	    ||choice=='m')
	    {
		chh=choice;
		return(0);
	    }
	    turn++;
	    mark=markp;
	}
    }

//when name1 is (O) plays second
    if(turn<0)
    {
	if(turn%2==0)
	{
	    gotoxy(16,18);
	    cout<<namep<<" Enter your choice : ";
	    choice=getone();

	    if(choice=='R'||choice=='r'||choice=='S'||choice=='s'||choice=='M'
	    ||choice=='m')
	    {
		chh=choice;
		return(0);
	    }
	    turn--;
	    mark=markp;
	}
	else
	{
	    gotoxy(16,18);
	    cout<<namec<<" Enter your choice : ";
	    choice=getone();

	    if(choice=='R'||choice=='r'||choice=='S'||choice=='s'||choice=='M'
	    ||choice=='m')
	    {
		chh=choice;
		return(0);
	    }
	    turn--;
	    mark=markc;
	}
    }
    play();
    return(1);
}


/******************************************************************************
//FUNCTION TO DISPLAY RESULT FOR PLAYER VS PLAYER MODE
******************************************************************************/
void dispresultp()
{
    if(check=='X')
    {
	if(markp=='X')
	{
	    gotoxy(13,18);
	    cout<<namep<<" CONGRATULATIONS YOU WON"<<endl;
	}

	else
	{
	    gotoxy(13,18);
	    cout<<namec<<" CONGRATULATIONS YOU WON"<<endl;
	}
    }

    else
    if(check=='O')
    {
	if(markp=='O')
	{
	    gotoxy(13,18);
	    cout<<namep<<" CONGRATULATIONS YOU WON"<<endl;
	}

	else
	{
	    gotoxy(13,18);
	    cout<<namec<<" CONGRATULATIONS YOU WON"<<endl;
	}
    }

    else
    {
	gotoxy(20,18);
	cout<<"THE GAME IS DRAW";
    }
}


/******************************************************************************
//FUNCTION TO ALLOT THE SYMBOLS FOR PLAYER VS COMPUTER MODE
EXECUTED ONLY ONCE DURING THE BEGINING OF EACH GAME
******************************************************************************/
void markallotc()
{
    clrscr();
    strcpy(namec,"COMPUTER");
    cout<<"PLAYER :-"<<endl;
    cout<<"Enter your name : ";
    gets(namep);
    re:cout<<"Enter your symbol (X/O) : ";
    markp=getone();
    markp=toupper(markp);

    if(markp=='X')
    {
	markc='O';
	turn=1;
    }

    else
    if(markp=='O')
    {
	markc='X';
	turn=-1;
    }

    else
    {
	cout<<endl;
	cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
	cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

	while(getche()!='\r')
	    cout<<"\b \b";
	clrscr();
	cout<<"PLAYER :-"<<endl;
	cout<<"Enter your name : ";
	cout<<namep<<endl;
	goto re;
    }
    cout<<"\n\nCOMPUTER :-"<<endl;
    cout<<"Name : ";
    cout<<namec<<endl;
    cout<<"Symbol : "<<markc;
}


/******************************************************************************
//FUNCTION TO CHOOSE THE CHOICE RANDOMLY FROM THE EMPTY PLACES AVAILABLE
******************************************************************************/
void compeasy()
{
    char ch[9];
    int k=0;

    for(int i=0; i<3; i++)
    {
	for(int j=0; j<3; j++)
	{
	    if (board[i][j]!='X' && board[i][j]!='O')
	    {
		ch[k]=board[i][j];
		k++;
	    }
	}
    }
    choice=ch[random(k)];
}


/******************************************************************************
//FUNCTION TO CHOSE A CHOICE BY CHECKING IF IT CAN WIN WHEN TWO OF ITS SYMBOL
ARE IN THE SAME ROW OR COLUMN OR DIAGONAL AND DO THE SAME THING TO BLOCK THE OPPONENT
******************************************************************************/
void compmedium()
{
    randomize();

//win
    for(int i=0;i<3;i++)
    {
	//row win
	if (board[i][0] == board[i][1] && board[i][1]==markc &&
	board[i][2]!=markp)
	{
	    choice=board[i][2];
	    return;
	}

	else
	if (board[i][0] == board[i][2] && board[i][2]==markc &&
	board[i][1]!=markp)
	{
	    choice=board[i][1];
	    return;
	}

	else
	if (board[i][1] == board[i][2] && board[i][1]==markc &&
	board[i][0]!=markp)
	{
	    choice=board[i][0];
	    return;
	}

	//column win
	else
	if (board[0][i] == board[1][i] && board[0][i]==markc &&
	board[2][i]!=markp)
	{
	    choice=board[2][i];
	    return;
	}

	else
	if (board[0][i] == board[2][i] && board[2][i]==markc &&
	board[1][i]!=markp)
	{
	    choice=board[1][i];
	    return;
	}

	else
	if (board[2][i] == board[1][i] && board[2][i]==markc &&
	board[0][i]!=markp)
	{
	    choice=board[0][i];
	    return;
	}
    }

    //left diagonal win
    if (board[0][0] == board[1][1] && board[0][0]==markc &&
    board[2][2]!=markp)
    {
	choice=board[2][2];
	return;
    }

    else
    if (board[0][0] == board[2][2] && board[0][0]==markc &&
    board[1][1]!=markp)
    {
	choice=board[1][1];
	return;
    }

    else
    if (board[2][2] == board[1][1] && board[1][1]==markc &&
    board[0][0]!=markp)
    {
	choice=board[0][0];
	return;
    }

    //right diagonal win
    else
    if (board[0][2] == board[1][1] && board[1][1]==markc &&
    board[2][0]!=markp)
    {
	choice=board[2][0];
	return;
    }

    else
    if (board[0][2] == board[2][0] && board[0][2]==markc &&
    board[1][1]!=markp)
    {
	choice=board[1][1];
	return;
    }

    else
    if (board[2][0] == board[1][1] && board[1][1]==markc &&
    board[0][2]!=markp)
    {
	choice=board[0][2];
	return;
    }

//block
    else
    {
	for(i=0;i<3;i++)
	{
	    //row block
	    if (board[i][0] == board[i][1] && board[i][0]==markp &&
	    board[i][2]!=markc)
	    {
		choice=board[i][2];
		return;
	    }

	    else
	    if (board[i][0] == board[i][2] && board[i][2]==markp &&
	    board[i][1]!=markc)
	    {
		choice=board[i][1];
		return;
	    }

	    else
	    if (board[i][1] == board[i][2] && board[i][1]==markp &&
	    board[i][0]!=markc)
	    {
		choice=board[i][0];
		return;
	    }

	    //column block
	    else
	    if (board[0][i] == board[1][i] && board[1][i]==markp &&
	    board[2][i]!=markc)
	    {
		choice=board[2][i];
		return;
	    }

	    else
	    if (board[0][i] == board[2][i] && board[0][i]==markp &&
	    board[1][i]!=markc)
	    {
		choice=board[1][i];
		return;
	    }

	    else
	    if (board[2][i] == board[1][i] && board[2][i]==markp &&
	    board[0][i]!=markc)
	    {
		choice=board[0][i];
		return;
	    }
	}

	//left diagonal block
	if (board[0][0] == board[1][1] && board[0][0]==markp &&
	board[2][2]!=markc)
	{
	    choice=board[2][2];
	    return;
	}

	else
	if (board[0][0] == board[2][2] && board[2][2]==markp &&
	board[1][1]!=markc)
	{
	    choice=board[1][1];
	    return;
	}

	else
	if (board[2][2] == board[1][1] && board[1][1]==markp &&
	board[0][0]!=markc)
	{
	    choice=board[0][0];
	    return;
	}

	//right diagonal block
	else
	if (board[0][2] == board[1][1] && board[0][2]==markp &&
	board[2][0]!=markc)
	{
	    choice=board[2][0];
	    return;
	}

	else
	if (board[0][2] == board[2][0] && board[2][0]==markp &&
	board[1][1]!=markc)
	{
	    choice=board[1][1];
	    return;
	}

	else
	if (board[2][0] == board[1][1] && board[2][0]==markp &&
	board[0][2]!=markc)
	{
	    choice=board[0][2];
	    return;
	}
    }

//for perfect moves
    if((turn==-5)&&(ch==4))
    {

//to attack when the comp plays in the side in the first turn and the
//player defends by putting in the adjacent corner and the after the
//player plays his second turn the comp sees for the best move
	if((markc==board[0][1])&&(markp==board[0][0])&&(markc==board[2][0]))
	{
	    if(markp==board[0][2])
	    {
		choice=board[2][1];
		return;
	    }

	    else
	    if((markp==board[1][0])||(markp==board[1][2]))
	    {
		choice=board[1][1];
		return;
	    }

	    else
	    if(markp==board[2][1])
	    {
		choice=board[1][0];
		return;
	    }
	}

	if((markc==board[0][1])&&(markp==board[0][2])&&(markc==board[2][2]))
	{
	    if(markp==board[0][0])
	    {
		choice=board[2][1];
		return;
	    }

	    else
	    if((markp==board[1][0])||(markp==board[1][2]))
	    {
		choice=board[1][1];
		return;
	    }

	    else
	    if(markp==board[2][1])
	    {
		choice=board[1][2];
		return;
	    }
	}

	if((markc==board[1][2])&&(markp==board[2][2])&&(markc==board[2][0]))
	{
	    if(markp==board[0][2])
	    {
		choice=board[1][0];
		return;
	    }

	    else
	    if((markp==board[0][1])||(markp==board[2][1]))
	    {
		choice=board[1][1];
		return;
	    }

	    else
	    if(markp==board[1][0])
	    {
		choice=board[2][1];
		return;
	    }
	}

	if((markc==board[1][2])&&(markp==board[0][2])&&(markc==board[0][0]))
	{
	    if(markp==board[2][2])
	    {
		choice=board[1][0];
		return;
	    }

	    else
	    if((markp==board[0][1])||(markp==board[2][1]))
	    {
		choice=board[1][1];
		return;
	    }

	    else
	    if(markp==board[1][0])
	    {
		choice=board[0][1];
		return;
	    }
	}

	if((markc==board[2][1])&&(markp==board[2][0])&&(markc==board[0][0]))
	{
	    if(markp==board[2][2])
	    {
		choice=board[0][1];
		return;
	    }

	    else
	    if((markp==board[1][2])||(markp==board[1][0]))
	    {
		choice=board[1][1];
		return;
	    }

	    else
	    if(markp==board[0][1])
	    {
		choice=board[1][0];
		return;
	    }
	}

	if((markc==board[2][1])&&(markp==board[2][2])&&(markc==board[0][2]))
	{
	    if(markp==board[2][0])
	    {
		choice=board[0][1];
		return;
	    }

	    else
	    if((markp==board[1][2])||(markp==board[1][0]))
	    {
		choice=board[1][1];
		return;
	    }

	    else
	    if(markp==board[0][1])
	    {
		choice=board[1][2];
		return;
	    }
	}

	if((markc==board[1][0])&&(markp==board[2][0])&&(markc==board[2][2]))
	{
	    if(markp==board[0][0])
	    {
		choice=board[1][2];
		return;
	    }

	    else
	    if((markp==board[2][1])||(markp==board[0][1]))
	    {
		choice=board[1][1];
		return;
	    }

	    else
	    if(markp==board[1][2])
	    {
		 choice=board[2][1];
		 return;
	    }
	}

	if((markc==board[1][0])&&(markp==board[0][0])&&(markc==board[0][2]))
	{
	    if(markp==board[2][0])
	    {
		choice=board[1][2];
		return;
	    }

	    else
	    if((markp==board[2][1])||(markp==board[0][1]))
	    {
		choice=board[1][1];
		return;
	    }

	    else
	    if(markp==board[1][2])
	    {
		choice=board[0][1];
		return;
	    }
	}

	//to attack when the comp plays in the side in the first turn and
	//then the player defends by putting in the centre and the comp
	//sees for the best move
	if((markc==board[0][1])&&(markp==board[1][1])&&(markc==board[2][2]))
	{
	    choice=board[0][2];
	    return;
	}

	if((markc==board[1][0])&&(markp==board[1][1])&&(markc==board[0][2]))
	{
	    choice=board[0][0];
	    return;
	}

	if((markc==board[1][2])&&(markp==board[1][1])&&(markc==board[2][0]))
	{
	    choice=board[2][2];
	    return;
	}

	if((markc==board[2][1])&&(markp==board[1][1])&&(markc==board[0][0]))
	{
	    choice=board[2][0];
	    return;
	}

	//to attack when the player plays in the opp side of that of comps
	//first turn (which is also a side) and the comp plays in the
	//centre then to attack according to the players moves
	if((markc==board[0][1])&&(markp==board[2][1])&&(markc==board[1][1]))
	{
	    if(markp==board[1][2])
	    {
		choice=board[0][0];
		return;
	    }

	    else
	    if(markp==board[1][0])
	    {
		choice=board[0][2];
		return;
	    }

	    else
	    if(markp==board[0][2])
	    {
		choice=board[1][2];
		return;
	    }

	    else
	    if(markp==board[0][0])
	    {
		choice=board[1][0];
		return;
	    }
	}

	if((markc==board[1][2])&&(markp==board[1][0])&&(markc==board[1][1]))
	{
	    if(markp==board[0][2])
	    {
		choice=board[0][1];
		return;
	    }

	    else
	    if(markp==board[2][2])
	    {
		choice=board[2][1];
		return;
	    }

	    else
	    if(markp==board[2][1])
	    {
		choice=board[0][2];
		return;
	    }

	    else
	    if(markp==board[0][1])
	    {
		choice=board[2][2];
		return;
	    }
	}

	if((markc==board[2][1])&&(markp==board[0][1])&&(markc==board[1][1]))
	{
	    if(markp==board[1][0])
	    {
		choice=board[2][2];
		return;
	    }

	    else
	    if(markp==board[1][2])
	    {
		choice=board[2][0];
		return;
	    }

	    else
	    if(markp==board[2][0])
	    {
		choice=board[1][0];
		return;
	    }

	    else
	    if(markp==board[2][2])
	    {
		choice=board[1][2];
		return;
	    }
	}

	if((markc==board[1][0])&&(markp==board[1][2])&&(markc==board[1][1]))
	{
	    if(markp==board[2][1])
	    {
		choice=board[0][0];
		return;
	    }

	    else
	    if(markp==board[0][1])
	    {
		choice=board[0][2];
		return;
	    }

	    else
	    if(markp==board[2][0])
	    {
		choice=board[2][1];
		return;
	    }

	    else
	    if(markp==board[0][0])
	    {
		choice=board[0][1];
		return;
	    }
	}

	//special attack
	if((markc==board[1][1])&&(markp==board[2][2])
	&&(board[1][1]==board[0][0]))
	{
	    if(markp==board[0][1])
		choice=board[2][0];

	    else
	    if(markp==board[1][0])
		choice=board[0][1];
	    return;
	}

	else
	if((markc==board[1][1])&&(markp==board[0][0])&&(board[1][1]==board[2][2]))
	{
	    if(markp==board[1][2])
		choice=board[2][0];

	    else
	    if(markp==board[2][1])
		choice=board[1][2];
	    return;
	}

	else
	if((markc==board[1][1])&&(markp==board[2][0])&&(board[1][1]==board[0][2]))
	{
	    if(markp==board[0][1])
		choice=board[1][2];

	    else
	    if(markp==board[1][2])
		choice=board[0][0];
	    return;
	}

	else
	if((markc==board[1][1])&&(markp==board[0][2])&&(board[1][1]==board[2][0]))
	{
	    if(markp==board[2][1])
		choice=board[1][0];

	    else
	    if(markp==board[1][0])
		choice=board[2][2];
	    return;
	}

	else
	if(tempchoice!=0)
	{
	    choice=tempchoice;
	    return;
	}
    }
    //random move
    compeasy();
}


/******************************************************************************
//FUNCTION TO CHOOSE THE CHOICE AFTER ANALYZING THE OPPONENTS MOVES AND PLAYING
ACOORDINGLY BY CHOOSING THE BEST CHOICE FOR EACH TURN
******************************************************************************/
void comphard()
{
    //when the comp is (O) and the player has played his first turn
    if(turn==2)
    {
	//defense for corners(putting in centre)
	if((board[0][0]==markp)||(board[0][2]==markp)||(board[2][0]==markp)||(board[2][2]==markp))
	{
	    choice=board[1][1];
	    return;
	}

	//defense for center(randomly putting in corner)
	else
	if(board[1][1]==markp)
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    choice=ch[random(k)];
	    return;
	}

	//defense for sides(randomly putting in the opp side,
	//centre or near corner)
	else
	if(board[1][0]==markp)
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][1];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[0][0];
	    choice=ch[random(k)];
	    return;
	}

	else
	if(board[0][1]==markp)
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][1];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[0][0];
	    choice=ch[random(k)];
	    return;
	}

	else
	if(board[1][2]==markp)
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    ch[k]=board[2][2];
	    choice=ch[random(k)];
	    return;
	}

	else
	if(board[2][1]==markp)
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[1][1];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    choice=ch[random(k)];
	    return;
	}
    }

    //when the comp is (O) and the player has played his second turn
    if(turn==4)
    {
	//when the player has played corner in his first turn(computer
	//has defended by putting in the centre
	if(board[1][1]==markc)
	{
	    //when the player has played in a opposite corner of his
	    //first turn the comp will randomly choose a side and play
	    if((board[0][0]==board[2][2])||(board[2][0]==board[0][2]))
	    {
		char ch[4];
		int k=0;
		ch[k]=board[0][1];
		k++;
		ch[k]=board[1][2];
		k++;
		ch[k]=board[2][1];
		k++;
		ch[k]=board[1][0];
		choice=ch[random(k)];
		return;
	    }

	    //when the player has played in a opposite side of his
	    //first turnthe comp will play in the opposite corner
	    //of the players first turn
	    else
	    if((board[0][0]==board[1][2])||(board[0][0]==board[2][1]))
	    {
		choice=board[2][2];
		return;
	    }

	    else
	    if((board[0][2]==board[1][0])||(board[0][2]==board[2][1]))
	    {
		choice=board[2][0];
		return;
	    }

	    else
	    if((board[2][2]==board[1][0])||(board[2][2]==board[0][1]))
	    {
		choice=board[0][0];
		return;
	    }

	    else
	    if((board[2][0]==board[1][2])||(board[2][0]==board[0][1]))
	    {
		choice=board[0][2];
		return;
	    }
	}

	//to defend when the opponent has played in the centre in his
	//first turn and plays to the opp. corner the comp defends
	if((markc==board[0][0])&&(markp==board[2][2])&&(markp==board[1][1]))
	{
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    choice=ch[random(k)];
	    return;
	}

	if((markp==board[0][0])&&(markc==board[2][2])&&(markp==board[1][1]))
	{
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    choice=ch[random(k)];
	    return;
	}

	if((markc==board[0][2])&&(markp==board[2][0])&&(markp==board[1][1]))
	{
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    choice=ch[random(k)];
	    return;
	}

	if((markp==board[0][2])&&(markc==board[2][0])&&(markp==board[1][1]))
	{
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    choice=ch[random(k)];
	    return;
	}

	// to defend when the player plays in adjacent side or opp
	//corner after his first turn is in a side and the comp plays
	//its first turn in the centre or opp side
	if((markp==board[1][0])&&((markc==board[1][1])||(markc==board[1][2]))
	&&((markp==board[0][1])||(markp==board[0][2])))
	{
	    choice=board[0][0];
	    return;
	}

	if((markp==board[1][0])&&((markc==board[1][1])||(markc==board[1][2]))
	&&((markp==board[2][1])||(markp==board[2][2])))
	{
	    choice=board[2][0];
	    return;
	}

	if((markp==board[0][1])&&((markc==board[1][1])||(markc==board[2][1]))
	&&((markp==board[1][2])||(markp==board[2][2])))
	{
	    choice=board[0][2];
	    return;
	}

	if((markp==board[0][1])&&((markc==board[1][1])||(markc==board[2][1]))
	&&((markp==board[1][0])||(markp==board[2][0])))
	{
	    choice=board[0][0];
	    return;
	}

	if((markp==board[1][2])&&((markc==board[1][1])||(markc==board[1][0]))
	&&((markp==board[0][1])||(markp==board[0][0])))
	{
	    choice=board[0][2];
	    return;
	}

	if((markp==board[1][2])&&((markc==board[1][1])||(markc==board[1][0]))
	&&((markp==board[2][1])||(markp==board[2][0])))
	{
	    choice=board[2][2];
	    return;
	}

	if((markp==board[2][1])&&((markc==board[1][1])||(markc==board[0][1]))
	&&((markp==board[1][0])||(markp==board[0][0])))
	{
	    choice=board[2][0];
	    return;
	}

	if((markp==board[2][1])&&((markc==board[1][1])||(markc==board[0][1]))
	&&((markp==board[1][2])||(markp==board[0][2])))
	{
	    choice=board[2][2];
	    return;
	}

	//to attack when the player plays in the opp. side or centre
	//after he plays his first turn in a side and the comp defends
	//him by playing in the centre or opp side
	if((markp==board[1][0])&&((markc==board[1][1])||(markc==board[1][2]))
	&&((markp==board[1][1])||(markp==board[1][2])))
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    choice=ch[random(k)];
	    return;
	}

	if((markp==board[0][1])&&((markc==board[1][1])||(markc==board[2][1]))
	&&((markp==board[1][1])||(markp==board[2][1])))
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    choice=ch[random(k)];
	    return;
	}

	if((markp==board[1][2])&&((markc==board[1][1])||(markc==board[1][0]))
	&&((markp==board[1][1])||(markp==board[1][0])))
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    choice=ch[random(k)];
	    return;
	}

	if((markp==board[2][1])&&((markc==board[1][1])||(markc==board[0][1]))
	&&((markp==board[1][1])||(markp==board[0][1])))
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    choice=ch[random(k)];
	    return;
	}

	//to attack when the player plays in the adjacent side after the
	//comp defends by putting in the corner(SURE WIN)
	if((markp==board[1][0])&&((markc==board[0][0])||(markc==board[2][0])))
	{
	    if((markp==board[2][1])&&(markc==board[0][0]))
	    {
		choice=board[0][2];
		return;
	    }

	    else
	    if((markp==board[0][1])&&(markc==board[2][0]))
	    {
		choice=board[2][2];
		return;
	    }

	    else
	    if(markp==board[1][1])
	    {
		choice=board[1][2];
		return;
	    }

	    else
	    {
		choice=board[1][1];
		return;
	    }
	}

	if((markp==board[0][1])&&((markc==board[0][0])||(markc==board[0][2])))
	{
	    if((markp==board[1][0])&&(markc==board[0][2]))
	    {
		choice=board[2][2];
		return;
	    }

	    else
	    if((markp==board[1][2])&&(markc==board[0][0]))
	    {
		choice=board[2][0];
		return;
	    }

	    else
	    if(markp==board[1][1])
	    {
		choice=board[2][1];
		return;
	    }

	    else
	    {
		choice=board[1][1];
		return;
	    }
	}

	if((markp==board[1][2])&&((markc==board[0][2])||(markc==board[2][2])))
	{
	    if((markp==board[0][1])&&(markc==board[2][2]))
	    {
		choice=board[2][0];
		return;
	    }

	    else
	    if((markp==board[2][1])&&(markc==board[0][2]))
	    {
		choice=board[0][0];
		return;
	    }

	    else
	    if(markp==board[1][1])
	    {
		choice=board[1][0];
		return;
	    }

	    else
	    {
		choice=board[1][1];
		return;
	    }
	}

	if((markp==board[2][1])&&((markc==board[2][0])||(markc==board[2][2])))
	{
	    if((markp==board[1][2])&&(markc==board[2][0]))
	    {
		choice=board[0][0];
		return;
	    }

	    else
	    if((markp==board[1][0])&&(markc==board[2][2]))
	    {
		choice=board[0][2];
		return;
	    }

	    else
	    if(markp==board[1][1])
	    {
		choice=board[0][1];
		return;
	    }

	    else
	    {
		choice=board[1][1];
		return;
	    }
	}
    }

    //when the comp plays as (O) and plays its second turn after player
    //plays his first
    if(turn==-3)
    {
	//to play in the opp corner (adjacent corner to players move)
	//when the comp plays in the side and the player defends by
	//putting in a corner
	if((markc==board[0][1])&&(markp==board[0][2]))
	{
	    choice=board[2][2];
	    return;
	}

	if((markc==board[0][1])&&(markp==board[0][0]))
	{
	    choice=board[2][0];
	    return;
	}

	if((markc==board[1][2])&&(markp==board[2][2]))
	{
	    choice=board[2][0];
	    return;
	}

	if((markc==board[1][2])&&(markp==board[0][2]))
	{
	    choice=board[0][0];
	    return;
	}

	if((markc==board[2][1])&&(markp==board[2][0]))
	{
	    choice=board[0][0];
	    return;
	}

	if((markc==board[2][1])&&(markp==board[2][2]))
	{
	    choice=board[0][2];
	    return;
	}

	if((markc==board[1][0])&&(markp==board[0][2]))
	{
	    choice=board[0][2];
	    return;
	}

	if((markc==board[1][0])&&(markp==board[2][2]))
	{
	    choice=board[2][0];
	    return;
	}

	//to play in the opp corner after the comp plays its first turn
	//in the side and the player blocks by putting it in centre
	if((markc==board[0][1])&&(markp==board[1][1]))
	{
	    choice=board[2][2];
	    return;
	}

	if((markc==board[1][2])&&(markp==board[1][1]))
	{
	    choice=board[2][0];
	    return;
	}

	if((markc==board[2][1])&&(markp==board[1][1]))
	{
	    choice=board[0][0];
	    return;
	}

	if((markc==board[1][0])&&(markp==board[1][1]))
	{
	    choice=board[0][2];
	    return;
	}

	//to attack when the player plays in the opp side of comps
	//first turn
	if((markc==board[0][1])&&(markp==board[2][1]))
	{
	    choice=board[1][1];
	    return;
	}

	if((markc==board[2][1])&&(markp==board[0][1]))
	{
	    choice=board[1][1];
	    return;
	}

	if((markc==board[1][0])&&(markp==board[1][2]))
	{
	    choice=board[1][1];
	    return;
	}

	if((markc==board[1][2])&&(markp==board[1][0]))
	{
	    choice=board[1][1];
	    return;
	}

	//to attack when the player plays in the adjacent side after
	//the comp plays in the side in the first turn
	if((markc==board[1][0])&&((markp==board[0][1])||(markp==board[2][1])))
	{
	    choice=board[1][1];
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    tempchoice=ch[random(k)];
	    return;
	}

	if((markc==board[0][1])&&((markp==board[1][0])||(markp==board[1][2])))
	{
	    choice=board[1][1];
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    tempchoice=ch[random(k)];
	    return;
	}

	if((markc==board[1][2])&&((markp==board[0][1])||(markp==board[2][1])))
	{
	    choice=board[1][1];
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    tempchoice=ch[random(k)];
	    return;
	}

	if((markc==board[2][1])&&((markp==board[1][0])||(markp==board[1][2])))
	{
	    choice=board[1][1];
	    char ch[2];
	    int k=0;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    tempchoice=ch[random(k)];
	    return;
	}

	//to attack when the player plays in the opp. corner after the
	//comp plays in the side in the first turn
	if((markc==board[1][0])&&(markp==board[0][2]))
	{
	    choice=board[0][0];
	    return;
	}

	if((markc==board[0][1])&&(markp==board[2][2]))
	{
	    choice=board[0][2];
	    return;
	}

	if((markc==board[1][2])&&(markp==board[2][0]))
	{
	    choice=board[2][2];
	    return;
	}

	if((markc==board[2][1])&&(markp==board[0][0]))
	{
	    choice=board[2][0];
	    return;
	}

	if((markc==board[1][0])&&(markp==board[2][2]))
	{
	    choice=board[2][0];
	    return;
	}

	if((markc==board[0][1])&&(markp==board[2][0]))
	{
	    choice=board[0][0];
	    return;
	}

	if((markc==board[1][2])&&(markp==board[0][0]))
	{
	    choice=board[0][2];
	    return;
	}

	if((markc==board[2][1])&&(markp==board[0][2]))
	{
	    choice=board[2][2];
	    return;
	}

	//to attack when the player plays in the centre after the comp
	//plays in one of the corners
	if((markc==board[0][0])&&(markp==board[1][1]))
	{
	    choice=board[2][2];
	    return;
	}

	if((markc==board[2][2])&&(markp==board[1][1]))
	{
	    choice=board[0][0];
	    return;
	}

	if((markc==board[0][2])&&(markp==board[1][1]))
	{
	    choice=board[2][0];
	    return;
	}

	if((markc==board[2][0])&&(markp==board[1][1]))
	{
	    choice=board[0][2];
	    return;
	}

	//to attack when the player does not play in the centre after
	//the comp plays in the corner
	//plays in the opp. corner(assured win)
	if((markc==board[0][0])&&(markp==board[2][2]))
	{
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][0])
		tempchoice=board[0][2];

	    else
		tempchoice=board[2][0];
	    return;
	}

	if((markc==board[2][2])&&(markp==board[0][0]))
	{
	    char ch[2];
	    int k=0;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][0])
		tempchoice=board[0][2];

	    else
		tempchoice=board[2][0];
	    return;
	}

	if((markc==board[0][2])&&(markp==board[2][0]))
	{
	    char ch[2];
	    int k=0;
	    ch[k]=board[2][2];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][2])
		tempchoice=board[0][0];

	    else
		tempchoice=board[2][2];
	    return;
	}

	if((markc==board[2][0])&&(markp==board[0][2]))
	{
	    char ch[2];
	    int k=0;
	    ch[k]=board[2][2];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][2])
		tempchoice=board[0][0];

	    else
		tempchoice=board[2][2];
	    return;
	}

	//to attack when the player plays in one of the opp. sides
	//after the comp plays in one corner
	if((markc==board[0][0])&&((markp==board[2][1])||(markp==board[1][2])))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][1];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    choice=ch[random(k)];

	    if((choice==board[2][0])||(choice==board[0][2]))
		tempchoice=board[1][1];
	    return;
	}

	if((markc==board[0][2])&&((markp==board[2][1])||(markp==board[1][0])))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][1];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    choice=ch[random(k)];

	    if((choice==board[0][0])||(choice==board[2][2]))
		tempchoice=board[1][1];
	    return;
	}

	if((markc==board[2][0])&&((markp==board[0][1])||(markp==board[1][2])))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][1];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    choice=ch[random(k)];

	    if((choice==board[0][0])||(choice==board[2][2]))
		tempchoice=board[1][1];
	    return;
	}

	if((markc==board[2][2])&&((markp==board[0][1])||(markp==board[1][0])))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][1];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    choice=ch[random(k)];

	    if((choice==board[2][0])||(choice==board[0][2]))
		tempchoice=board[1][1];
	    return;
	}

	//to attack when the player plays in the adjacent corner
	//after the comp plays in one corner
	if((markc==board[0][0])&&(markp==board[0][2]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][0];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][0])
		tempchoice=board[2][2];

	    else
	    if(choice==board[1][0])
		tempchoice=board[1][1];
	    return;
	}

	if((markc==board[0][0])&&(markp==board[2][0]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[0][1];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[0][2])
		tempchoice=board[2][2];

	    else
	    if(choice==board[0][1])
		tempchoice=board[1][1];
	    return;
	}

	if((markc==board[0][2])&&(markp==board[2][2]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[0][1];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[0][1])
		tempchoice=board[1][1];

	    else
	    if(choice==board[0][0])
		tempchoice=board[2][0];
	    return;
	}

	if((markc==board[0][2])&&(markp==board[0][0]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][2];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[1][2])
		tempchoice=board[1][1];

	    else
	    if(choice==board[2][2])
		tempchoice=board[2][0];
	    return;
	}

	if((markc==board[2][2])&&(markp==board[0][2]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[2][1];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][1])
		tempchoice=board[1][1];

	    else
	    if(choice==board[2][0])
		tempchoice=board[0][0];
	    return;
	}

	if((markc==board[2][2])&&(markp==board[2][0]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][2];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[1][2])
		tempchoice=board[1][1];

	    else
	    if(choice==board[0][2])
		tempchoice=board[0][0];
	    return;
	}

	if((markc==board[2][0])&&(markp==board[0][0]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[2][1];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][1])
		tempchoice=board[1][1];

	    else
	    if(choice==board[2][2])
		tempchoice=board[0][2];
	    return;
	}

	if((markc==board[2][0])&&(markp==board[2][2]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][0];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[1][0])
		tempchoice=board[1][1];

	    else
	    if(choice==board[0][0])
		tempchoice=board[0][2];
	    return;
	}

	//to attack when the player plays in the adjacent side
	//after the comp plays in the corner
	if((markc==board[0][0])&&(markp==board[0][1]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][0];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][0])
		tempchoice=board[2][2];
	    else
	    if(choice==board[1][0])
		tempchoice=board[1][1];

	    else
	    if(choice==board[1][1])
		tempchoice=board[2][0];
	    return;
	}

	if((markc==board[0][0])&&(markp==board[1][0]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[0][1];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[0][2])
		tempchoice=board[2][2];

	    else
	    if(choice==board[0][1])
		tempchoice=board[1][1];

	    else
	    if(choice==board[1][1])
		tempchoice=board[0][2];
	    return;
	}

	if((markc==board[0][2])&&(markp==board[1][2]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[0][1];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[0][1])
		tempchoice=board[1][1];

	    else
	    if(choice==board[0][0])
		tempchoice=board[2][0];

	    else
	    if(choice==board[1][1])
		tempchoice=board[0][0];
	    return;
	}

	if((markc==board[0][2])&&(markp==board[0][1]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][2];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[1][2])
		tempchoice=board[1][1];
	    else
	    if(choice==board[2][2])
		tempchoice=board[2][0];

	    else
	    if(choice==board[1][1])
		tempchoice=board[2][2];
	    return;
	}

	if((markc==board[2][2])&&(markp==board[1][2]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[2][1];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][1])
		tempchoice=board[1][1];

	    else
	    if(choice==board[2][0])
		tempchoice=board[0][0];

	    else
	    if(choice==board[1][1])
		tempchoice=board[2][0];
	    return;
	}

	if((markc==board[2][2])&&(markp==board[2][1]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][2];
	    k++;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[1][2])
		tempchoice=board[1][1];

	    else
	    if(choice==board[0][2])
		tempchoice=board[0][0];

	    else
	    if(choice==board[1][1])
		tempchoice=board[0][2];
	    return;
	}

	if((markc==board[2][0])&&(markp==board[1][0]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[2][1];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[2][1])
		tempchoice=board[1][1];

	    else
	    if(choice==board[2][2])
		tempchoice=board[0][2];

	    else
	    if(choice==board[1][1])
		tempchoice=board[2][2];
	    return;
	}

	if((markc==board[2][0])&&(markp==board[2][1]))
	{
	    char ch[3];
	    int k=0;
	    ch[k]=board[1][0];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[1][1];
	    k++;
	    choice=ch[random(k)];

	    if(choice==board[1][0])
		tempchoice=board[1][1];

	    else
	    if(choice==board[0][0])
		tempchoice=board[0][2];

	    else
	    if(choice==board[1][1])
		tempchoice=board[0][0];
	    return;
	}

	//when comp played in the centre in the first turn and the
	//player played in any of the sides (assured win)
	if((markc==board[1][1])&&(markp==board[1][2]))
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[0][1];
	    k++;
	    ch[k]=board[2][1];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    choice=ch[random(k)];

	    if((choice==board[0][1])||(choice==board[0][2]))
		tempchoice=board[0][0];

	    else
	    if((choice==board[2][1])||(choice==board[2][2]))
		tempchoice=board[2][0];
	    return;
	}

	if((markc==board[1][1])&&(markp==board[2][1]))
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[1][2];
	    k++;
	    ch[k]=board[1][0];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    ch[k]=board[2][2];
	    k++;
	    choice=ch[random(k)];

	    if((choice==board[1][0])||(choice==board[2][0]))
		tempchoice=board[0][0];

	    else
	    if((choice==board[1][2])||(choice==board[2][2]))
		tempchoice=board[0][2];
	    return;
	}

	if((markc==board[1][1])&&(markp==board[1][0]))
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][0];
	    k++;
	    ch[k]=board[0][1];
	    k++;
	    ch[k]=board[2][1];
	    k++;
	    ch[k]=board[2][0];
	    k++;
	    choice=ch[random(k)];

	    if((choice==board[0][1])||(choice==board[0][0]))
		tempchoice=board[0][2];

	    else
	    if((choice==board[2][1])||(choice==board[2][0]))
		tempchoice=board[2][2];
	    return;
	}

	if((markc==board[1][1])&&(markp==board[0][1]))
	{
	    char ch[4];
	    int k=0;
	    ch[k]=board[0][2];
	    k++;
	    ch[k]=board[1][2];
	    k++;
	    ch[k]=board[1][0];
	    k++;
	    ch[k]=board[0][0];
	    k++;
	    choice=ch[random(k)];

	    if((choice==board[1][2])||(choice==board[0][2]))
		tempchoice=board[2][2];

	    else
	    if((choice==board[1][0])||(choice==board[0][0]))
		tempchoice=board[2][0];
	    return;
	}

	//to choose the better choice when the the player  plays in any
	//corner after the comp plays in the centre in the first turn
	if((markc==board[1][1])&&(markp==board[0][0]))
	{
	    choice=board[2][2];
	    return;
	}

	if((markc==board[1][1])&&(markp==board[0][2]))
	{
	    choice=board[2][0];
	    return;
	}

	if((markc==board[1][1])&&(markp==board[2][0]))
	{
	    choice=board[0][2];
	    return;
	}

	if((markc==board[1][1])&&(markp==board[2][2]))
	{
	    choice=board[0][0];
	    return;
	}
    }
    //test for sides
    if(turn==-1)
    {
	char ch[4];
	int k=0;
	ch[k]=board[0][1];
	k++;
	ch[k]=board[1][2];
	k++;
	ch[k]=board[2][1];
	k++;
	ch[k]=board[2][1];
	k++;
	ch[k]=board[1][1];
	k++;
	choice=ch[random(k)];
	return;
    }
    compmedium();
}


//assigning functions for computer
void compplay()
{
    randomize();
    if(ch==2)
	compeasy();
    else
    if(ch==3)
	compmedium();
    else
    if(ch==4)
	comphard();
}


/******************************************************************************
//FUNCTION TO DECIDE WHETHER PLAYER IS PLAYING OR COMPUTER IS PLAYING AND ACCEPT CHOICE AS DECIDED AND GIVE THE MARK AS DECIDED (THIS FUNCTION IS ONLY FOR PLAYER VS COMPUTER)
******************************************************************************/
int playturnc()
{
    if(turn>0)
    {
	if(turn%2==0)
	{
	    gotoxy(19,18);
	    cout<<namec<<" is PLAYING";
	    delay(500);
	    compplay();
	    turn++;
	    mark=markc;
	}

	else
	{
	    gotoxy(16,18);
	    cout<<namep<<" Enter your choice : ";
	    choice=getone();

	    if(choice=='R'||choice=='r'||choice=='S'||choice=='s'||
	    choice=='M'||choice=='m')
	    {
		chh=choice;
		return(0);
	    }
	    turn++;
	    mark=markp;
	}
    }

    if(turn<0)
    {
	if(turn%2==0)
	{
	    gotoxy(16,18);
	    cout<<namep<<" Enter your choice : ";
	    choice=getone();

	    if(choice=='R'||choice=='r'||choice=='S'||choice=='s'||
	    choice=='M'||choice=='m')
	    {
		chh=choice;
		return(0);
	    }
	    turn--;
	    mark=markp;
	}

	else
	{
	    gotoxy(19,18);
	    cout<<namec<<" is PLAYING";
	    delay(500);
	    compplay();
	    turn--;
	    mark=markc;
	}
    }
    play();
    return(1);
}


/******************************************************************************
//FUNCTION TO DISPLAY RESULT FOR PLAYER VS COMPUTER MODE
******************************************************************************/
void dispresultc()
{
    if(check=='X')
    {
	if(markp=='X')
	{
	    gotoxy(13,18);
	    cout<<namep<<" CONGRATULATIONS YOU WON"<<endl;
	}

	else
	{
	    gotoxy(15,18);
	    cout<<namep<<" BETTER LUCK NEXT TIME"<<endl;
	}
    }

    else
    if(check=='O')
    {
	if(markp=='O')
	{
	    gotoxy(13,18);
	    cout<<namep<<" CONGRATULATIONS YOU WON"<<endl;
	}

	else
	{
	    gotoxy(15,18);
	    cout<<namep<<" BETTER LUCK NEXT TIME"<<endl;
	}
    }

    else
    {
	gotoxy(20,18);
	cout<<"THE GAME IS DRAW";
    }
}


//funtion for help and info about the game
void abtgame()
{
    char chhelp='B';

    while(chhelp!='M')
    {
	if(chhelp=='B')
	{
	    B:
	    clrscr();
	    cout<<"     ABOUT THE GAME \n";
	    cout<<" R - Rules \n";
	    cout<<" G - Game modes \n";
	    cout<<" H - History of the game \n";
	    cout<<" C - Combinatorics \n";
	    cout<<" M - Back to Main Menu\n";
	    cout<<" D - Developers Note\n";
	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='R' && chhelp!='H' && chhelp!='C' && chhelp!='M'
	    && chhelp!='G' && chhelp!='D')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto B;

	    }
	}

	if(chhelp=='R')
	{
	    R:
	    clrscr();
	    cout<<"\t\t\t         RULES \n\n";
	    cout<<" þ Tic-tac-toe is a game for two players, X and O, who take turns marking the\n";
	    cout<<"   spaces in a 3*3 grid.\n";
	    cout<<" þ X plays the first turn of the game and O plays the second.\n";
	    cout<<" þ The player who succeeds in placing three of their marks in a horizontal,\n";
	    cout<<"   vertical, or diagonal row is the winner.\n";
	    cout<<"\nEg:     X | O | X "<<endl;
	    cout<<"       -----------"<<endl;
	    cout<<"        X |   | O "<<"   * Here it is seen that X wins by putting its mark"<<endl;
	    cout<<"       -----------"<<"     in the first column"<<endl;
	    cout<<"        X |   | O "<<endl<<endl<<endl;
	    cout<<"G - Game modes (To see the different game\n";
	    cout<<"                modes that can be played)\n";
	    cout<<"B - BACK\n";
	    cout<<"M - MAIN MENU\n";
	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='B' && chhelp!='M' && chhelp!='G')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto R;
	    }
	}

	if(chhelp=='G')
	{
	    G:
	    clrscr();
	    cout<<"\t\t\t     GAME MODES                      page - 1 \n\n\n";
	    cout<<"Here are the following tic-tac-toe modes available in this game:-\n\n"<<endl;
	    cout<<"1. PLAYER VS PLAYER"<<endl;
	    cout<<"   ¯ In the Player vs Player mode two players can play against each other"<<endl;
	    cout<<"     on the computer."<<endl<<endl;
	    cout<<"2. EASY(Player vs Computer)"<<endl;
	    cout<<"   ¯ In the Easy mode a player can play against the computer where the"<<endl;
	    cout<<"     computer randomizes its move among the free spaces available on "<<endl;
	    cout<<"     the board."<<endl<<endl;
	    cout<<endl<<endl<<"\n( PRESS ENTER KEY to go to the Next page )";

	    while(getche()!='\r')
		cout<<"\b \b";

	    clrscr();
	    cout<<"\t\t\t                                     page - 2\n\n";
	    cout<<"3. NORMAL(Player vs Computer)"<<endl;
	    cout<<"   ¯ In this mode a player can play against the computer where the computer"<<endl;
	    cout<<"     blocks the player from winning in some situations and also tries to win"<<endl;
	    cout<<"     in certain situations but cannot handle or create special attacks against"<<endl;
	    cout<<"     the opponents."<<endl<<endl;
	    cout<<"4. INSANE(Player vs Computer)"<<endl;
	    cout<<"   ¯ In this mode a player can play against the computer where the computer"<<endl;
	    cout<<"     analyzes all the permutations and combinations possible and plays the"<<endl;
	    cout<<"     best possible move and hence remains undefeated till date."<<endl;
	    cout<<"   ¯ Yeah you read it right it is undefeatable if you dont believe us why dont"<<endl;
	    cout<<"     you give it a try!!"<<endl<<endl<<endl;
	    cout<<endl<<endl<<"\n( PRESS ENTER KEY to go to the Next page )";

	    while(getche()!='\r')
		cout<<"\b \b";

	    clrscr();
	    cout<<"\t\t\t                                     page - 3\n\n";
	    cout<<"5. EXTREME(Player vs Computer)"<<endl;
	    cout<<"   ¯ In this mode the rules change a bit. Here instead of a normal board "<<endl;
	    cout<<"     you will be presented with a big board. In this big board every square"<<endl;
	    cout<<"     will represent a smaller board. This means that inside a big board there"<<endl;
	    cout<<"     there are 9 boards in each of the squares of the big board. "<<endl;
	    cout<<"   ¯ Now to play this game you will be given a choice at the start as to"<<endl;
	    cout<<"     which board you want to start playing in. Suppose you choose '1', this"<<endl;
	    cout<<"     means you will be starting from the top left board-board 1. Now you will"<<endl;
	    cout<<"     get to choose a square to play in like a normal match. Now its where it"<<endl;
	    cout<<"     starts getting weird. Now suppose you choose to play at '7', your mark"<<endl;
	    cout<<"     will show at '7', but now its computers turn, instead of playing in the"<<endl;
	    cout<<"     same board the computer will first go to box '7' of the big board you saw"<<endl;
	    cout<<"     at the start of the game. After going to that board the computer will"<<endl;
	    cout<<"     randomly choose a square to play. Now the process repeats, whichever"<<endl;
	    cout<<"     square the computer played the small board you will have to go to the"<<endl;
	    cout<<"     same square in the big board."<<endl<<endl<<endl;
	    cout<<endl<<endl<<"\n( PRESS ENTER KEY to go to the Next page )";

	    while(getche()!='\r')
		cout<<"\b \b";

	    clrscr();
	    cout<<"\t\t\t                                     page - 4\n\n";
	    cout<<"   ¯ To win the game you have the see the big picture. To win the game its "<<endl;
	    cout<<"     its normal tic tac toe rules, but for the big board. You have to win in"<<endl;
	    cout<<"     the small board. Every win in the small board means that square is yours"<<endl;
	    cout<<"     in the big board. Now if you win 3 consecutive samll square on the big"<<endl;
	    cout<<"     like a normal game then you win."<<endl;
	    cout<<"   ¯ To summarise:- Whichever square you play in a samll board in your turn,"<<endl;
	    cout<<"     the opponent show play in the same box corresponding to the big board"<<endl;
	    cout<<"     To win the game you should look at the bid board as the whole tic tac"<<endl;
	    cout<<"     toe board and to win a box the the big board to have to win in the "<<endl;
	    cout<<"     corrresponding small board."<<endl<<endl<<endl;

	    cout<<"B - BACK (About Game Menu) \n";
	    cout<<"M - MAIN MENU\n";

	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='B' && chhelp!='M')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"    PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto G;
	    }
	}

	if(chhelp=='H')
	{
	    H:
	    clrscr();
	    cout<<"\t\t\t         HISTORY OF THE GAME \n\n";
	    cout<<" þ Games played on three-in-a-row boards can be traced back to ancient Egypt\n";
	    cout<<"   where such game boards have been found on roofing tiles dating from around\n";
	    cout<<"   1300 BCE."<<endl<<endl;
	    cout<<" þ An early variation of tic-tac-toe was played in the Roman Empire, around\n";
	    cout<<"   the first century BC.\n";
	    cout<<" þ It was called ternilapilli (three pebbles at a time) and instead of having\n";
	    cout<<"   any number of pieces, each player only had three, thus they had to move them\n";
	    cout<<"   around to empty spaces to keep playing.\n";
	    cout<<" þ The game's grid markings have been found chalked all over Rome.\n"<<endl;
	    cout<<" þ Another closely related ancient game is three men's morris which is also\n";
	    cout<<"   played on a simple grid and requires three pieces in a row to finish.\n\n\n";

	    cout<<"C - Combinatorics ( Some facts on the possiblity\n";
	    cout<<"                    on how the game can end ) \n";
	    cout<<"B - BACK\n";
	    cout<<"M - MAIN MENU\n";

	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='B' && chhelp!='M' && chhelp!='C')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"    PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto H;
	    }
	}

	if(chhelp=='C')
	{
	    C:
	    clrscr();
	    cout<<"\t\t\t         COMBINATORICS \n\n";
	    cout<<"  Combinatorics is the study of all the possible distinct ways in  which the\n";
	    cout<<"  game can end. This study helped us to program the unbeatable AI Tic-Tac-Toe\n";
	    cout<<endl<<endl;
	    cout<<" þ When considering only the state of the board, and after taking into account\n";
	    cout<<"   board symmetries (i.e. rotations and reflections), there are only 138\n";
	    cout<<"   terminal board positions. "<<endl;
	    cout<<" þ A combinatorics study of the game shows that when 'X' makes the first move\n";
	    cout<<"   every time, the game is won as follows:-"<<endl;
	    cout<<"    ¯ 91 distinct positions are won by (X)"<<endl;
	    cout<<"    ¯ 44 distinct positions are won by (O)"<<endl;
	    cout<<"    ¯ 3 distinct positions are drawn (often called a \"cat's game\")\n\n\n";

	    cout<<"B - BACK (About the game menu)\n";
	    cout<<"M - MAIN MENU\n";

	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='B' && chhelp!='M')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"    PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto C;
	    }
	}

	if(chhelp=='D')
	{
	    D:
	    clrscr();
	    cout<<"\t\t\t       DEVELOPERS NOTE \n\n";
	    cout<<"  We created this game for various reasons, one was our love for this subject "<<endl;;
	    cout<<"  and the our was the thirst to learn something new and exciting"<<endl;
	    cout<<"  We were interested in the concept of AI and wanted to make a program using"<<endl;
	    cout<<"  the concept that the computer learns with every use, but beacuse of technical"<<endl;
	    cout<<"  reasons we were not able to do so but got pretty close."<<endl;
	    cout<<"  We started with tic tac toe because the game was  complex enough to use this"<<endl;
	    cout<<"  this concept while simple enough for it to not be too hard."<<endl;
	    cout<<"  While making this game we decided that we didn't want to be like those 100's"<<endl;
	    cout<<"  of other programs out there for tic tac toe and we wanted to add something"<<endl;
	    cout<<"  new to this game. So we added to game modes which we think are unique, first"<<endl;
	    cout<<"  is our unbeatable tic tac toe, which means that there is no way for the "<<endl;
	    cout<<"  computer to loose and other is our tic tac toe Extreme, a game mode which"<<endl;
	    cout<<"  pushes the boundries of tic tac toe with a complex rules set and a wholely"<<endl;
	    cout<<"  original game mode."<<endl;
	    cout<<"  Hope you guys enjoy the game!."<<endl<<endl<<endl;

	    cout<<"B - BACK (About the game menu)\n";
	    cout<<"M - MAIN MENU\n";

	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='B' && chhelp!='M')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"    PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto D;
	    }
	}
    }
}

//**************************************************************************
//class for feedback and files
//**************************************************************************
class FEEDBACK
{
    private:
	char name[20];
	char email[20];
	int ratings;
	char sug[300];

    public:
	void getinfo();
	void showinfo();
	void prntname()
	{
	    cout<<name;
	}
}F;

void FEEDBACK::getinfo()
{
    clrscr();
    char temp;
    cout<<"\n\t\t    FEEDBACK";
    cout<<"\n\nName : ";
    gets(name);
    cout<<"\nE-mail : ";
    gets(email);
    cout<<"\nRatings :  /5\b\b\b";
    temp=getone();
    cout<<"\n";

    if(temp=='1')
	ratings=1;

    if(temp=='2')
	ratings=2;

    if(temp=='3')
	ratings=3;

    if(temp=='4')
	ratings=4;

    if(temp=='5')
	ratings=5;
    cout<<"\nSuggestion Note (300 words max):-\n";
    gets(sug);
    clrscr();
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\tThank You for your Feedback !!!";
    getch();
}

void FEEDBACK::showinfo()
{
    clrscr();
    cout<<"\n\t\t    FEEDBACK";
    cout<<"\n\nName : ";
    cout<<name;
    cout<<"\nE-mail : ";
    cout<<email;
    cout<<"\nRatings : ";
    cout<<ratings;
    cout<<"\n";
    cout<<"\nSuggestion Note:-\n";
    cout<<sug;
}


//class for reporting your problems with the game
class PROBLEM
{
    private:
	char name[20];
	long pno;
	char email[20];
	char detail[500];

    public:
	void getinfo();
	void showinfo();
	void prntname()
	{
	    cout<<name;
	}
}P;

void PROBLEM::getinfo()
{
    clrscr();
    cout<<"\n\t\t    ISSUE REPORT\n";
    cout<<"\n\nName : ";
    gets(name);
    cout<<"\nContact No : ";
    cin>>pno;
    cout<<"\nE-mail : ";
    gets(email);
    cout<<"\nDetailed Note on the Issue (500 words max):-\n";
    gets(detail);
    clrscr();
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\tThank You for Reporting this Issue !!!";
    cout<<"\n We may give you a call to know more details about the Issue you faced";
    getch();
}

void PROBLEM::showinfo()
{
    clrscr();
    cout<<"\n\t\t    ISSUE REPORT\n";
    cout<<"\n\nName : ";
    cout<<name;
    cout<<"\nContact No : ";
    cout<<pno;
    cout<<"\nE-mail : ";
    cout<<email;
    cout<<"\nDetailed Note on the Issue (500 words max):-\n";
    cout<<detail;
}

void help()
{
    clrscr();
    char chhelp='B';

    while(chhelp!='M')
    {
	if(chhelp=='B')
	{
	    B: clrscr();
	    cout<<"\t\t\tHELP MENU"<<endl;
	    cout<<"H - HOW TO PLAY"<<endl;
	    cout<<"C - CUSTOMER SUPPORT ( Feedback and Issues)"<<endl;
	    cout<<"M - MAIN MENU"<<endl;

	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='H' && chhelp!='C' && chhelp!='M')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto B;
	    }
	}

	if(chhelp=='C')
	{
	    C: clrscr();
	    cout<<"\t\t\tCUSTOMER SUPPORT"<<endl;
	    cout<<"F - FEEDBACK / SUGGESTIONS"<<endl;
	    cout<<"@ - REPORT ISSUES IN THE GAME"<<endl;
	    cout<<"B - Back to Help Menu"<<endl;
	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='@' && chhelp!='F'&& chhelp!='B')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"    PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto C;
	    }
	}

	if(chhelp=='F')
	{
	    clrscr();
	    F.getinfo();
	    fstream f;
	    f.open("Feedback.DAT",ios::app|ios::binary);
	    f.write((char *)&F,sizeof(F));
	    f.close();
	    chhelp='C';
	}

	if(chhelp=='@')
	{
	    clrscr();
	    P.getinfo();
	    fstream f;
	    f.open("Problems.DAT",ios::app|ios::binary);
	    f.write((char *)&P,sizeof(P));
	    f.close();
	    chhelp='C';
	}

	if(chhelp=='H')
	{
	    H: clrscr();
	    cout<<"\t\t\tHOW TO PLAY"<<endl;
	    cout<<"R - RULES"<<endl;
	    cout<<"G - GAME MODES"<<endl;
	    cout<<"U - How to USE the Computer and play the game"<<endl;
	    cout<<"B - Back to Help Menu"<<endl;
	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='R' && chhelp!='G'&& chhelp!='U'&& chhelp!='B')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto H;
	    }
	}

	if(chhelp=='R')
	{
	    R:
	    clrscr();
	    cout<<"\t\t\t         RULES \n\n";
	    cout<<" þ Tic-tac-toe is a game for two players, X and O, who take turns marking the\n";
	    cout<<"   spaces in a 3*3 grid.\n";
	    cout<<" þ X plays the first turn of the game and O plays the second.\n";
	    cout<<" þ The player who succeeds in placing three of their marks in a horizontal,\n";
	    cout<<"   vertical, or diagonal row is the winner.\n";

	    cout<<"\nEg:     X | O | X "<<endl;
	    cout<<"       -----------"<<endl;
	    cout<<"        X |   | O "<<"   * Here it is seen that X wins by putting its mark"<<endl;
	    cout<<"       -----------"<<"     in the first column"<<endl;
	    cout<<"        X |   | O "<<endl<<endl<<endl;

	    cout<<"B - HELP Menu\n";
	    cout<<"H - How to Play MENU\n";

	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='B' && chhelp!='H')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto R;
	    }
	}

	if(chhelp=='G')
	{
	    G:
	    clrscr();
	    cout<<"\t\t\t     GAME MODES                      page - 1 \n\n\n";
	    cout<<"Here are the following tic-tac-toe modes available in this game:-\n\n"<<endl;
	    cout<<"1. PLAYER VS PLAYER"<<endl;
	    cout<<"   ¯ In the Player vs Player mode two players can play against each other"<<endl;
	    cout<<"     on the computer."<<endl<<endl;
	    cout<<"2. EASY(Player vs Computer)"<<endl;
	    cout<<"   ¯ In the Easy mode a player can play against the computer where the"<<endl;
	    cout<<"     computer randomizes its move among the free spaces available on "<<endl;
	    cout<<"     the board."<<endl<<endl;
	    cout<<endl<<endl<<"\n( PRESS ENTER KEY to go to the Next page )";

	    while(getche()!='\r')
		cout<<"\b \b";
	    clrscr();
	    cout<<"\t\t\t                                     page - 2\n\n";
	    cout<<"3. NORMAL(Player vs Computer)"<<endl;
	    cout<<"   ¯ In this mode a player can play against the computer where the computer"<<endl;
	    cout<<"     blocks the player from winning in some situations and also tries to win"<<endl;
	    cout<<"     in certain situations but cannot handle or create special attacks against"<<endl;
	    cout<<"     the opponents."<<endl<<endl;
	    cout<<"4. INSANE(Player vs Computer)"<<endl;
	    cout<<"   ¯ In this mode a player can play against the computer where the computer"<<endl;
	    cout<<"     analyzes all the permutations and combinations possible and plays the"<<endl;
	    cout<<"     best possible move and hence remains undefeated till date."<<endl;
	    cout<<"   ¯ Yeah you read it right it is undefeatable if you dont believe us why dont"<<endl;
	    cout<<"     you give it a try!!"<<endl<<endl<<endl;

	    while(getche()!='\r')
		cout<<"\b \b";

	    clrscr();
	    cout<<"\t\t\t                                     page - 3\n\n";
	    cout<<"5. EXTREME(Player vs Computer)"<<endl;
	    cout<<"   ¯ In this mode the rules change a bit. Here instead of a normal board "<<endl;
	    cout<<"     you will be presented with a big board. In this big board every square"<<endl;
	    cout<<"     will represent a smaller board. This means that inside a big board there"<<endl;
	    cout<<"     there are 9 boards in each of the squares of the big board. "<<endl;
	    cout<<"   ¯ Now to play this game you will be given a choice at the start as to"<<endl;
	    cout<<"     which board you want to start playing in. Suppose you choose '1', this"<<endl;
	    cout<<"     means you will be starting from the top left board-board 1. Now you will"<<endl;
	    cout<<"     get to choose a square to play in like a normal match. Now its where it"<<endl;
	    cout<<"     starts getting weird. Now suppose you choose to play at '7', your mark"<<endl;
	    cout<<"     will show at '7', but now its computers turn, instead of playing in the"<<endl;
	    cout<<"     same board the computer will first go to box '7' of the big board you saw"<<endl;
	    cout<<"     at the start of the game. After going to that board the computer will"<<endl;
	    cout<<"     randomly choose a square to play. Now the process repeats, whichever"<<endl;
	    cout<<"     square the computer played the small board you will have to go to the"<<endl;
	    cout<<"     same square in the big board."<<endl<<endl<<endl;
	    cout<<endl<<endl<<"\n( PRESS ENTER KEY to go to the Next page )";

	    while(getche()!='\r')
		cout<<"\b \b";

	    clrscr();
	    cout<<"\t\t\t                                     page - 4\n\n";
	    cout<<"   ¯ To win the game you have the see the big picture. To win the game its "<<endl;
	    cout<<"     its normal tic tac toe rules, but for the big board. You have to win in"<<endl;
	    cout<<"     the small board. Every win in the small board means that square is yours"<<endl;
	    cout<<"     in the big board. Now if you win 3 consecutive samll square on the big"<<endl;
	    cout<<"     like a normal game then you win."<<endl;
	    cout<<"   ¯ To summarise:- Whichever square you play in a samll board in your turn,"<<endl;
	    cout<<"     the opponent show play in the same box corresponding to the big board"<<endl;
	    cout<<"     To win the game you should look at the bid board as the whole tic tac"<<endl;
	    cout<<"     toe board and to win a box the the big board to have to win in the "<<endl;
	    cout<<"     corrresponding small board."<<endl<<endl<<endl;

	    cout<<"B - HELP Menu\n";
	    cout<<"H - How to Play MENU\n";

	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='B' && chhelp!='H')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto G;
	    }
	}

	if(chhelp=='U')
	{
	    U:
	    clrscr();
	    cout<<"\t\t\t     USING THE COMPUTER TO PLAY \n\n";
	    cout<<" þ In the Main Menu enter the respective choice of the game mode you want to\n";
	    cout<<"   play. For example Enter 4 to play the Insane Mode and press Enter.\n";
	    cout<<" þ Then Enter your Name and the symbol you want to use (X to Play First and\n";
	    cout<<"   O to Play Second) and wait for the Game to Load.\n";
	    cout<<" þ Play the Game by Entering the Respective Choice where you want to play.\n";
	    cout<<" þ At any point of the game if you want to Restart the Game, Switch symbols\n";
	    cout<<"   and play or go to the Main Menu you can do so by entering the respective\n";
	    cout<<"   choices while playing (The game is designed to accept such choices).\n";
	    cout<<" þ After the Game is over Press Enter key to Leave and choose from the given\n";
	    cout<<"   options on what you want to do.\n";

	    cout<<"\n\nB - HELP Menu\n";
	    cout<<"H - How to Play MENU\n";

	    cout<<"\n\nEnter your choice : ";
	    chhelp=getone();
	    chhelp=toupper(chhelp);

	    if(chhelp!='B' && chhelp!='H')
	    {
		cout<<"\n\n\t   (INVALID CHOICE)"<<endl;
		cout<<"   PRESS ENTER KEY TO RENETER YOUR CHOICE";

		while(getche()!='\r')
		    cout<<"\b \b";
		goto U;
	    }
	}
    }
}


//**********************************************************************
//its for the developer to get the info the user gives
//**********************************************************************
void developer()
{
    char chd,temp[200];
    int fno,pno;
    fstream f,p,l,t;
    MAIN:
    f.open("Feedback.DAT",ios::in|ios::binary);
    p.open("Problems.DAT",ios::in|ios::binary);
    f.seekg(0,ios::end);
    p.seekg(0,ios::end);
    fno=f.tellg()/sizeof(F);
    pno=p.tellg()/sizeof(P);
    clrscr();
    cout<<"DEVELOPER MENU\n";
    cout<<"1.Suggestions -- "<<fno<<endl;
    cout<<"2.Issues -- "<<pno<<endl;
    cout<<"0.Exit\n";

    f.seekg(0,ios::beg);
    p.seekg(0,ios::beg);

    chd=getone();

    if(chd=='0')
	exit(0);

    else
    if(chd=='1')
    {
	while(!f.eof())
	{
	    f.read((char*)&F,sizeof(F));
	    F.showinfo();
	    cout<<"\n\nEnter to continue"<<endl;
	    getch();
	}
	clrscr();
	cout<<"\n\n\n\tEND OF FEEDBACKS";
	getch();
	f.close();
	goto MAIN;
    }

    else
    if(chd=='2')
    {
	while(!p.eof())
	{
	    p.read((char*)&P,sizeof(P));
	    P.showinfo();
	    cout<<"\n\nEnter to continue"<<endl;
	    getch();
	}
	clrscr();
	cout<<"\n\n\n\tEND OF REPORTS/ISSUES";
	getch();
	p.close();
	goto MAIN;
    }
}


//***************************************************************************
//to show the whole board along with the numbers
//***************************************************************************
void choosebox(char choose,char lboard[9][9])
{

    if(choose=='1')
    {
	for(int o=0,k=0;o<3;o++,k++)
	{
	    for(int p=0, l=0;p<3;p++,l++)
	    {
		lboard[k][l]=box1[o][p];
	    }
	}
    }

    else
    if(choose=='2')
    {
	for(int o=0,k=0;o<3;o++,k++)
	{
	    for(int p=0,l=3;p<3;p++,l++)
	    {
		lboard[k][l]=box2[o][p];
	    }
	}
    }

    else
    if(choose=='3')
    {
	for(int o=0,k=0;o<3;o++,k++)
	{
	    for(int p=0,l=6;p<3;p++,l++)
	    {
		lboard[k][l]=box3[o][p];
	    }
	}
    }


    else
    if(choose=='4')
    {
	for(int o=0,k=3;o<3;o++,k++)
	{
	    for(int p=0,l=0;p<3;p++,l++)
	    {
		lboard[k][l]=box4[o][p];
	    }
	}
    }


    else
    if(choose=='5')
    {
	for(int o=0,k=3;o<3;o++,k++)
	{
	    for(int p=0,l=3;p<3;p++,l++)
	    {
		lboard[k][l]=box5[o][p];
	    }
	}
    }


    else
    if(choose=='6')
    {
	for(int o=0,k=3;o<3;o++,k++)
	{
	    for(int p=0,l=6;p<3;p++,l++)
	    {
		lboard[k][l]=box6[o][p];
	    }
	}
    }

    else
    if(choose=='7')
    {
	for(int o=0,k=6;o<3;o++,k++)
	{
	    for(int p=0,l=0;p<3;p++,l++)
	    {
		lboard[k][l]=box7[o][p];
	    }
	}
    }


    else
    if(choose=='8')
    {
	for(int o=0,k=6;o<3;o++,k++)
	{
	    for(int p=0,l=3;p<3;p++,l++)
	    {
		lboard[k][l]=box8[o][p];
	    }
	}
    }


    else
    if(choose=='9')
    {
	for(int o=0,k=6;o<3;o++,k++)
	{
	    for(int p=0,l=6;p<3;p++,l++)
	    {
		lboard[k][l]=box9[o][p];
	    }
	}
    }


 //to display the number full board
 clrscr();
 cout<<"     "<<lboard[0][0]<<"  |  "<<lboard[0][1]<<"  |  "<<lboard[0][2]<<"   |   "<<lboard[0][3]<<"  |  "<<lboard[0][4]<<"  |  "<<lboard[0][5]<<"   |   "<<lboard[0][6]<<"  |  "<<lboard[0][7]<<"  |  "<<lboard[0][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<lboard[1][0]<<"  |  "<<lboard[1][1]<<"  |  "<<lboard[1][2]<<"   |   "<<lboard[1][3]<<"  |  "<<lboard[1][4]<<"  |  "<<lboard[1][5]<<"   |   "<<lboard[1][6]<<"  |  "<<lboard[1][7]<<"  |  "<<lboard[1][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<lboard[2][0]<<"  |  "<<lboard[2][1]<<"  |  "<<lboard[2][2]<<"   |   "<<lboard[2][3]<<"  |  "<<lboard[2][4]<<"  |  "<<lboard[2][5]<<"   |   "<<lboard[2][6]<<"  |  "<<lboard[2][7]<<"  |  "<<lboard[2][8]<<endl;
 cout<<"_____________________|___________________|_____________________"<<endl;
 cout<<"     "<<lboard[3][0]<<"  |  "<<lboard[3][1]<<"  |  "<<lboard[3][2]<<"   |   "<<lboard[3][3]<<"  |  "<<lboard[3][4]<<"  |  "<<lboard[3][5]<<"   |   "<<lboard[3][6]<<"  |  "<<lboard[3][7]<<"  |  "<<lboard[3][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<lboard[4][0]<<"  |  "<<lboard[4][1]<<"  |  "<<lboard[4][2]<<"   |   "<<lboard[4][3]<<"  |  "<<lboard[4][4]<<"  |  "<<lboard[4][5]<<"   |   "<<lboard[4][6]<<"  |  "<<lboard[4][7]<<"  |  "<<lboard[4][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<lboard[5][0]<<"  |  "<<lboard[5][1]<<"  |  "<<lboard[5][2]<<"   |   "<<lboard[5][3]<<"  |  "<<lboard[5][4]<<"  |  "<<lboard[5][5]<<"   |   "<<lboard[5][6]<<"  |  "<<lboard[5][7]<<"  |  "<<lboard[5][8]<<endl;
 cout<<"_____________________|___________________|____________________"<<endl;
 cout<<"     "<<lboard[6][0]<<"  |  "<<lboard[6][1]<<"  |  "<<lboard[6][2]<<"   |   "<<lboard[6][3]<<"  |  "<<lboard[6][4]<<"  |  "<<lboard[6][5]<<"   |   "<<lboard[6][6]<<"  |  "<<lboard[6][7]<<"  |  "<<lboard[6][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<lboard[7][0]<<"  |  "<<lboard[7][1]<<"  |  "<<lboard[7][2]<<"   |   "<<lboard[7][3]<<"  |  "<<lboard[7][4]<<"  |  "<<lboard[7][5]<<"   |   "<<lboard[7][6]<<"  |  "<<lboard[7][7]<<"  |  "<<lboard[7][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<lboard[8][0]<<"  |  "<<lboard[8][1]<<"  |  "<<lboard[8][2]<<"   |   "<<lboard[8][3]<<"  |  "<<lboard[8][4]<<"  |  "<<lboard[8][5]<<"   |   "<<lboard[8][6]<<"  |  "<<lboard[8][7]<<"  |  "<<lboard[8][8]<<endl;
}


//Function to choose which board to start from
void chooseExtreme()
{clrscr();
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"        |  1  |      |      |  2  |      |      |  3  |      "<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"_____________________|___________________|_____________________"<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"        |  4  |      |      |  5  |      |      |  6  |      "<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"_____________________|___________________|_____________________"<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"        |  7  |      |      |  8  |      |      |  9  |      "<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 }

 //to print the choices on the big board
void CalExtreme()
{
    //initialising box
    int l,h;
    for(l=0;l<9;l++)
    {
	for(h=0;h<9;h++)
	    box[l][h]=' ';
    }

    //inserting the played moves
    int i,j,k,p,q,r;
    for(i=0,j=3,k=6;i<3; i++,j++,k++)
    {
	for(p=0,q=3,r=6;p<3;p++,q++,r++)
	{
	    if(box1[i][p]=='X'||box1[i][p]=='O')
		box[i][p]=box1[i][p];

	    if(box2[i][p]=='X'||box2[i][p]=='O')
		box[i][q]=box2[i][p];

	    if(box3[i][p]=='X'||box3[i][p]=='O')
		box[i][r]=box3[i][p];

	    if(box4[i][p]=='X'||box4[i][p]=='O')
		box[j][p]=box4[i][p];

	    if(box5[i][p]=='X'||box5[i][p]=='O')
		box[j][q]=box5[i][p];

	    if(box6[i][p]=='X'||box6[i][p]=='O')
		box[j][r]=box6[i][p];

	    if(box7[i][p]=='X'||box7[i][p]=='O')
		box[k][p]=box7[i][p];

	    if(box8[i][p]=='X'||box8[i][p]=='O')
		box[k][q]=box8[i][p];

	    if(box9[i][p]=='X'||box9[i][p]=='O')
		box[k][r]=box9[i][p];
	}
    }
}


//***************************************************************************
//To display the whole board
//***************************************************************************
void showExtreme()
{
 cout<<"     "<<box[0][0]<<"  |  "<<box[0][1]<<"  |  "<<box[0][2]<<"   |   "<<box[0][3]<<"  |  "<<box[0][4]<<"  |  "<<box[0][5]<<"   |   "<<box[0][6]<<"  |  "<<box[0][7]<<"  |  "<<box[0][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<box[1][0]<<"  |  "<<box[1][1]<<"  |  "<<box[1][2]<<"   |   "<<box[1][3]<<"  |  "<<box[1][4]<<"  |  "<<box[1][5]<<"   |   "<<box[1][6]<<"  |  "<<box[1][7]<<"  |  "<<box[1][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<box[2][0]<<"  |  "<<box[2][1]<<"  |  "<<box[2][2]<<"   |   "<<box[2][3]<<"  |  "<<box[2][4]<<"  |  "<<box[2][5]<<"   |   "<<box[2][6]<<"  |  "<<box[2][7]<<"  |  "<<box[2][8]<<endl;
 cout<<"_____________________|___________________|_____________________"<<endl;
 cout<<"     "<<box[3][0]<<"  |  "<<box[3][1]<<"  |  "<<box[3][2]<<"   |   "<<box[3][3]<<"  |  "<<box[3][4]<<"  |  "<<box[3][5]<<"   |   "<<box[3][6]<<"  |  "<<box[3][7]<<"  |  "<<box[3][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<box[4][0]<<"  |  "<<box[4][1]<<"  |  "<<box[4][2]<<"   |   "<<box[4][3]<<"  |  "<<box[4][4]<<"  |  "<<box[4][5]<<"   |   "<<box[4][6]<<"  |  "<<box[4][7]<<"  |  "<<box[4][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<box[5][0]<<"  |  "<<box[5][1]<<"  |  "<<box[5][2]<<"   |   "<<box[5][3]<<"  |  "<<box[5][4]<<"  |  "<<box[5][5]<<"   |   "<<box[5][6]<<"  |  "<<box[5][7]<<"  |  "<<box[5][8]<<endl;
 cout<<"_____________________|___________________|____________________"<<endl;
 cout<<"     "<<box[6][0]<<"  |  "<<box[6][1]<<"  |  "<<box[6][2]<<"   |   "<<box[6][3]<<"  |  "<<box[6][4]<<"  |  "<<box[6][5]<<"   |   "<<box[6][6]<<"  |  "<<box[6][7]<<"  |  "<<box[6][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<box[7][0]<<"  |  "<<box[7][1]<<"  |  "<<box[7][2]<<"   |   "<<box[7][3]<<"  |  "<<box[7][4]<<"  |  "<<box[7][5]<<"   |   "<<box[7][6]<<"  |  "<<box[7][7]<<"  |  "<<box[7][8]<<endl;
 cout<<"   _____|_____|_____ | _____|_____|_____ | _____|_____|_____ "<<endl;
 cout<<"        |     |      |      |     |      |      |     |      "<<endl;
 cout<<"     "<<box[8][0]<<"  |  "<<box[8][1]<<"  |  "<<box[8][2]<<"   |   "<<box[8][3]<<"  |  "<<box[8][4]<<"  |  "<<box[8][5]<<"   |   "<<box[8][6]<<"  |  "<<box[8][7]<<"  |  "<<box[8][8]<<endl;
 getch();
}


//checks for win
int checkwin(char board[9])
{
    //checks rows
    if(board[0]==board[1] && board[1]==board[2])
	return 1;

    else
    if(board[3]==board[4] && board[4]==board[5])
	return 1;

    else
    if(board[6]==board[7] && board[7]==board[8])
	return 1;

    //checks columns
    else
    if(board[0]==board[3] && board[3]==board[6])
	return 1;

    else
    if(board[1]==board[4] && board[4]==board[7])
	return 1;

    else
    if(board[2]==board[5] && board[5]==board[8])
	return 1;

    //checks diagonals
    if (board[0]==board[4] && board[4]==board[8])
	return 1;

    else
    if (board[2]==board[4] && board[4]==board[6])
	return 1;

    //checks for draw
    else
    if (board[0]!='1' && board[1]!='2' && board[2]!='3' &&
	board[3]!='4' && board[4]!='5' && board[5]!='6' &&
	board[6]!='7' && board[7]!='8' && board[8]!='9')
	return 0;

    else
	return -1;
}


/******************************************************************************
//FUNCTION TO MARK THE BOARD
******************************************************************************/
void play(char choice,char mark,char board[3][3])
{
    start:
    for(int i=0;i<3;i++)
    {
	for(int j=0;j<3;j++)
	{
	    if(choice==board[i][j])
	    {
		board[i][j]=mark;
		return;
	    }
	}
    }
    cout<<"Invalid move "<<endl;
    cout<<"Press a key to retry"<<endl;
    getch();
    clrscr();
    choosebox(choice,box);
    cout<<"Enter your choice: ";
    choice=getone();
    goto start;
}


/*****************************************************************************
// A function to play Tic-Tac-Toe Easy
//*****************************************************************************/
char CompEasy(char board[3][3])
{
    char ch[9];
    char mark='O';
    int k=0;
    randomize();

    for(int i=0; i<3; i++)
    {
	for(int j=0; j<3; j++)
	{
	    if (board[i][j]!='X' && board[i][j]!='O')
	    {
		ch[k]=board[i][j];
		k++;
	    }
	}
    }
    char val=ch[random(k)];

    //play(val,mark,board);
    return val;
}


//***************************************************************************
//to place a mark if the player wins a box
//***************************************************************************
void PlaceMark(char board[3][3], int choice)
{
    while(winbox[choice]!='X' && winbox[choice]!='O')
    {
	for(int i=0;i<3;i++)
	{
	    //checks rows
	    if(board[i][0]==board[i][1] && board[i][1]==board[i][2] )
		winbox[choice]=board[i][2];

	    //checks columns
	    else
	    if(board[0][i]==board[1][i] && board[1][i]==board[2][i] )
		winbox[choice]=board[2][i];
	}
	//checks diagonals
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2] )
	    winbox[choice]=board[2][2];

	else
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0] )
	    winbox[choice]=board[2][0];

	return;
    }
}


//**********************************************************************
//Main function where the player choses what he plays
//**********************************************************************
void main()
{
    MENU:
    flag=0;
    clrscr();
    cout<<endl<<"                        MAIN MENU"<<endl;
    cout<<"                       -----------"<<endl;
    cout<<"                   1. Player vs Player"<<endl<<endl;
    cout<<"\n                     Player vs computer"<<endl<<endl;
    cout<<"                   2. Easy"<<endl<<endl;         //random moves
    cout<<"                   3. Normal"<<endl<<endl;     //tries to block
    cout<<"                   4. Insane"<<endl<<endl;    //pre planned moves
    cout<<"                   5. Extreme"<<endl;
    cout<<"\n\n               ? - HELP"<<endl;
    cout<<"               ! - ABOUT THE GAME"<<endl;
    cout<<"\n\n    Enter your choice : ";
    chtemp=getone();

    if(chtemp=='?')
    {
	help();
	goto MENU;
    }

    if(chtemp=='!')
    {
	abtgame();
	goto MENU;
    }

    if(chtemp=='1')
	ch=1;

    else
    if(chtemp=='2')
	ch=2;
    else
    if(chtemp=='3')
	ch=3;

    else
    if(chtemp=='4')
	ch=4;

    else
    if(chtemp=='5')
	ch=5;

    else
    {
	if(chtemp=='0')
	{
	    gets(key);
	    if(strcmp(key,"SETTINGS")==0)
	    {
		clrscr();
		gets(team);

		if(strcmp(team,"@DEVELOPER")==0)
		{
		    clrscr();
		    gets(key);

		    if(strcmp(key,"S")==0)
			developer();
		    goto MENU;
		}
		goto MENU;
	    }
	    cout<<endl<<endl<<"       (INVALID CHOICE)"<<endl;
	    cout<<"        PRESS ANY ENTER KEY TO REENTER YOUR CHOICE";
	}

	while(getche()!='\r')
	    cout<<"\b \b";
	goto MENU;
    }
    PLAYAGAIN:

    switch(ch)
    {
	case 1:
	    check='P';

	    if(flag==0)
		markallotp();
	    cout<<"\n\nLOADING";

	    for(int i=0;i<=5;i++)
	    {
		delay(350);
		cout<<".";
	    }

	    while(check=='P')
	    {
		clrscr();
		showboard();

		if(playturnp()==0)
		    goto DIRECT;
		check=checkwin();
	    }
	    clrscr();
	    showboard();
	    dispresultp();
	    break;

	case 2:
	    check='P';

	    if(flag==0)
		markallotc();
	    cout<<"\n\nLOADING";

	    for(i=0;i<=5;i++)
	    {
		delay(350);
		cout<<".";
	    }

	    while(check=='P')
	    {
		clrscr();
		showboard();

		if(playturnc()==0)
		    goto DIRECT;
		check=checkwin();
	    }
	    clrscr();
	    showboard();
	    dispresultc();
	    break;

	case 3:
	    check='P';

	    if(flag==0)
		markallotc();
	    cout<<"\n\nLOADING";

	    for(i=0;i<=5;i++)
	    {
		delay(350);
		cout<<".";
	    }

	    while(check=='P')
	    {
		clrscr();
		showboard();

		if(playturnc()==0)
		    goto DIRECT;
		check=checkwin();
	    }
	    clrscr();
	    showboard();
	    dispresultc();
	    break;

	case 4:
	    check='P';

	    if(flag==0)
		markallotc();
	    cout<<"\n\nLOADING";

	    for(i=0;i<=5;i++)
	    {
		delay(350);
		cout<<".";
	    }

	    while(check=='P')
	    {
		clrscr();
		showboard();

		if(playturnc()==0)
		    goto DIRECT;
		check=checkwin();
	    }
	    clrscr();
	    showboard();
	    dispresultc();
	    break;

	case 5:
	    cout<<"Extreme:"<<endl;
	    int c;
	    int m;
	    int game=0;
	    char mark;
	    char choose;
	    chooseExtreme();
	    cout<<"Enter your choice: ";
	    choose=getone();

	    do
	    {
		if (game%2==0)
		{
		    mark='X';
		    choosebox(choose,box);

		    if(choose=='1')
		    {
			m=0 ;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box1);
			  PlaceMark(box1,m);
		    }

		    else
		    if(choose=='2')
		    {
			m=1;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box2);
			  PlaceMark(box2,m);
		    }

		    else
		    if(choose=='3')
		    {
			m=2;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box3);
			  PlaceMark(box3,m);
		    }

		    else
		    if(choose=='4')
		    {
			  m=3;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box4);
			  PlaceMark(box4,m);
		    }

		    else
		    if(choose=='5')
		    {
			  m=4;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box5);
			  PlaceMark(box5,m);
		    }

		    else
		    if(choose=='6')
		    {
			  m=5;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box6);
			  PlaceMark(box6,m);
		    }

		    else
		    if(choose=='7')
		    {
			  m=6;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box7);
			  PlaceMark(box7,m);
		    }

		    else
		    if(choose=='8')
		    {
			  m=7;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box8);
			  PlaceMark(box8,m);
		    }

		    else
		    if(choose=='9')
		    {
			  m=8;
			  cout<<"Enter your choice ";
			  choose=getone();
			  play(choose,mark,box9);
			  PlaceMark(box9,m);
		    }
		}

		else
		{
		    mark='O';
		    choosebox(choose,box);
		    if(choose=='1')
		    {
			m=0;
			  choose=CompEasy(box1);
			  play(choose,mark,box1);
			  PlaceMark(box1,m);
		    }

		    else
		    if(choose=='2')
		    {
			  m=1;
			  choose=CompEasy(box2);
			  play(choose,mark,box2);
			  PlaceMark(box2,m);
		    }

		    else
		    if(choose=='3')
		    {
			  m=2;
			  choose=CompEasy(box3);
			  play(choose,mark,box3);
			  PlaceMark(box3,m);
		    }

		    else
		    if(choose=='4')
		    {
			  m=4;
			  choose=CompEasy(box4);
			  play(choose,mark,box4);
			  PlaceMark(box4,m);
		    }

		    else
		    if(choose=='5')
		    {
			  m=4;
			  choose=CompEasy(box5);
			  play(choose,mark,box5);
			  PlaceMark(box5,m);
		    }

		    else
		    if(choose=='6')
		    {
			  m=5;
			  choose=CompEasy(box6);
			  play(choose,mark,box6);
			  PlaceMark(box6,m);
		    }

		    else
		    if(choose=='7')
		    {
			  m=6;
			  choose=CompEasy(box7);
			  play(choose,mark,box7);
			  PlaceMark(box7,m);
		    }

		    else
		    if(choose=='8')
		    {
			  m=7;
			  choose=CompEasy(box8);
			  play(choose,mark,box8);
			  PlaceMark(box8,m);
		    }

		    else
		    if(choose=='9')
		    {
			  m=8;
			  choose=CompEasy(box9);
			  play(choose,mark,box9);
			  PlaceMark(box9,m);
		    }
		}
		CalExtreme();
		game++;
		c=checkwin(winbox);
	    }

	    while(c==-1);
		showExtreme();

	    if(c==1)
	    {
		if (game%2==0)
		    cout<<"Computer Wins! "<<endl;

		else
		    cout<<"You Win!"<<endl;
	    }

	    else
		cout<<"==>\aThe Game is a draw";
	    getch();
	    break;
    }

    while(getche()!='\r')
	cout<<"\b \b";
    REDO:
    clrscr();
    cout<<"P-Play Again"<<endl;
    cout<<"S-Switch symbols"<<endl;
    cout<<"M-Main Menu"<<endl;
    cout<<"Enter your choice : ";
    chh=getone();
    DIRECT:
    chh=toupper(chh);

    if(chh=='R')
	chh='P';

    if(chh=='S')
    {
	char tempo;
	tempo=markc;
	markc=markp;
	markp=tempo;
    }
    tempchoice=0;
    check='P';

    if(markc=='X')
	turn=-1;

    else
	turn=1;

    board[0][0]='1';
    board[0][1]='2';
    board[0][2]='3';
    board[1][0]='4';
    board[1][1]='5';
    board[1][2]='6';
    board[2][0]='7';
    board[2][1]='8';
    board[2][2]='9';

    if(chh=='M')
	goto MENU;

    else
    if((chh=='P')||(chh=='S'))
    {
	flag=1;
	goto PLAYAGAIN;
    }

    else
    {
	cout<<"\n\n            (INVALID CHOICE)"<<endl;
	cout<<"       PRESS ENTER KEY TO RENETER YOUR CHOICE";

	while(getche()!='\r')
	    cout<<"\b \b";
	goto REDO;
    }
}
