#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//cd /users/arnav/documents/arnav/coding/tictactoe_minimax

char board[10] = {'x',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char marker;
int hpos,r,flag,counter;


int ticboard();
int checkempty();
int checkresult();
int humaninput();
int compinput();


int main(){

    ticboard();

    while(true){
        if(counter == 18){
        printf("It's a tie");
        return 0;
    }
        humaninput();
        if(checkresult() == true ){
            break;
        }
    
        compinput();
        if(checkresult() == true ){
            break;
        }

    }
}


int ticboard(){

    printf(" \n  %c |  %c  |  %c \n ", board[1], board[2], board[3]);
    printf("..............\n");
    printf(" \n  %c |  %c  |  %c \n ", board[4], board[5], board[6]);
    printf("..............\n");
    printf(" \n  %c |  %c  |  %c \n \n", board[7], board[8], board[9]);

    return 0;
}


int checkempty(int pos, char theboard[10]){

    if (theboard[pos] == ' '){
        return true;
    }
    return false;
          
}


int humaninput(){

    marker = 'o'; 

    while(true){
        printf("\nEnter position for your marker\n ");
        scanf("%d",&hpos);


        if( checkempty( hpos , board) == true ){
            printf("\nValid position!\n");
            board[hpos] = 'o';
            ticboard();
            break;
        }
        else{
            printf("Invalid position!\n");
            continue;
        }
    }
}


int checkresult(){
counter++;
    if(marker == 'o'){
        if( (board[1]==board[2] && board[2]==board[3] && board[3]==marker) ||
            (board[4]==board[5] && board[5]==board[6] && board[6]==marker) ||
            (board[7]==board[8] && board[8]==board[9] && board[9]==marker) ||
            (board[1]==board[4] && board[4]==board[7] && board[7]==marker) ||
            (board[2]==board[5] && board[5]==board[8] && board[8]==marker) ||
            (board[3]==board[6] && board[6]==board[9] && board[9]==marker) ||
            (board[1]==board[5] && board[5]==board[9] && board[9]==marker) ||
            (board[3]==board[5] && board[5]==board[7] && board[7]==marker)) {
                printf("\no is the winner!\n");
                return true;
            }
    }
    


     if(marker == 'x'){
        if( (board[1]==board[2] && board[2]==board[3] && board[3]==marker) ||
            (board[4]==board[5] && board[5]==board[6] && board[6]==marker) ||
            (board[7]==board[8] && board[8]==board[9] && board[9]==marker) ||
            (board[1]==board[4] && board[4]==board[7] && board[7]==marker) ||
            (board[2]==board[5] && board[5]==board[8] && board[8]==marker) ||
            (board[3]==board[6] && board[6]==board[9] && board[9]==marker) ||
            (board[1]==board[5] && board[5]==board[9] && board[9]==marker) ||
            (board[3]==board[5] && board[5]==board[7] && board[7]==marker)){
                printf("\nx is the winner!\n");
                return true;
            }
    }
    
    

    /*int i=1;
        
        for(i=1;i<10;i++){
            if(board[i] == ' ')
            flag = 1;
            else{
            flag = 0;
            break;
            }
        }
        if(flag == 0){
            printf("\nIt's a tie!\n");
            return true;
        }
        else{
            printf("flg=%d",flag);
            return false;
        }*/
    
}


int compinput(){

    marker = 'x'; 

    r = arc4random_uniform(8) + 1;
   while(true){

        if( checkempty( r , board) == true ){
            board[r] = 'x';
            ticboard();
            break;
        }
        else{
            continue;
        }
    }
}


