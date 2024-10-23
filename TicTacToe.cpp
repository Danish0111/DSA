#include <iostream>
#include <cstdlib>
using namespace std;

char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void printBoard(){
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[1], arr[2], arr[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", arr[4], arr[5], arr[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[7], arr[8], arr[9]);
    printf("     |     |     \n");
}

int checkWin(){
    if ((arr[1]==arr[2] && arr[2]==arr[3]) || (arr[4]==arr[5] && arr[5]==arr[6]) || (arr[7]==arr[8] && arr[8]==arr[9]))
    {
        return 1;
    }

    if ((arr[1]==arr[4] && arr[4]==arr[7]) || (arr[2]==arr[5] && arr[5]==arr[8]) || (arr[3]==arr[6] && arr[6]==arr[9]))
    {
        return 1;
    }
    
    if ((arr[1]==arr[5] && arr[5]==arr[9]) || (arr[3]==arr[5] && arr[5]==arr[7]))
    {
        return 1;
    }
    
    int count = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (arr[i]=='X' || arr[i]=='O')
        {
            count++;
        }
    }
    if (count == 9)
    {
        return 0;
    }

    return -1;
}

void updateBoard(int *t){
    int num;
    char player;
    while (checkWin() == -1)
    {
        player = (*t%2!=0)?'X':'O';
        cout<<player<<"'s chance: ";
        cin>>num;
        if (num > 9)
        {
            cout<<"choose from (0-9)"<<endl;
            continue;
        }
        if (arr[num] == 'X' || arr[num] =='O')
        {
            cout<<"occupied!!"<<endl;
            continue;
        }
        
        arr[num] = player;
        (*t)++;
        system("cls");
        printBoard();
        int result = checkWin();
        if (result == 1)
        {
            cout<<player<<" is the winner"<<endl;
            break;
        }
        else if (result == 0)
        {
            cout<<"It's a Draw"<<endl;
        }
    }
}
int main(){
    printBoard();
    int turn=1;
    updateBoard(&turn);
    return 0;
}