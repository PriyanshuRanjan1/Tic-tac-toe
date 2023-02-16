#include<stdio.h>
#include<conio.h>

void printboard();
int checkwin();

char board[]={ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void printboard()
{
    printf("== Tick-Tack-Toe ==\n");
    printf("    |     |   \n");
    printf(" %c  |  %c  | %c\n",board[1],board[2],board[3]);
    printf("____|_____|___\n");
    printf("    |     |   \n");
    printf(" %c  |  %c  | %c\n",board[4],board[5],board[6]);
    printf("____|_____|___\n");
    printf("    |     |   \n");
    printf(" %c  |  %c  | %c\n",board[7],board[8],board[9]);
}
int checkwin()
{

    // Winning condition :-
    if (board[1]==board[2] && board[2]==board[3])
    {
        return 1;
    }

    if (board[4]==board[5] && board[5]==board[6])
    {
        return 1;
    }

    if (board[7]==board[8] && board[8]==board[9])
    {
        return 1;
    }

    if (board[1]==board[4] && board[4]==board[7])
    {
        return 1;
    }

    if (board[2]==board[5] && board[5]==board[8])
    {
        return 1;
    }

    if (board[3]==board[6] && board[6]==board[9])
    {
        return 1;
    }

    if (board[1]==board[5] && board[5]==board[9])
    {
        return 1;
    }

    if (board[3]==board[5] && board[5]==board[7])
    {
        return 1;
    }

    // Draw condition 

    int count=0;
    for(int i = 1;i <= 9; i++)
    {
        if(board[i]== 'X' || board[i]== 'O')
        {
            count++;

        }

        if(count==9)
        {
            return 0;
        }
    }

    return -1; // play again

    
}


int main()
{

    
    int player=1, input, status = -1;
    printboard();
   
   while (status==-1)
   {
      player=(player%2==0) ? 2 : 1 ;
      char mark = (player==1) ? 'X' : 'O';
      printf("Enter the number For player %d\n",player);
      scanf("%d", &input); 
      if(board[input]=='X'||board[input]=='O') // this line is used to check if a position on the board is already occupied
      {
        printf("Position aleredy occupied please try again \n");
        continue;
      }
      if(input<1 || input>9)
        {
          printf("Inavlid input\n1");
        }

        
      board[input]=mark;
      printboard();

      int result = checkwin();
      
      if(result == 1)
      {
        printf("Player %d is a Winner\n",player);
        return ;
      }
      else if (result == 0)
      {
        printf("Match is draw\n");
        return;
        
        
      }
      player++;
   }
   
}