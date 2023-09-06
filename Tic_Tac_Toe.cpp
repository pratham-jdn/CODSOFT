#include <iostream>
using namespace std;

char space[3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool tie=false;
string n1="";
string n2="";

void functionOne(){       // to create the console of tic tac toe

    

    
   

    cout<< "   |     |  \n";
    cout<< " "<<space[0][0]<<" | "<<space[0][1]<<"   | "<<space[0][2]<<"  \n";
    cout<< "___|_____|__\n";
    cout<< "   |     |  \n";
    cout<< " "<<space[1][0]<<" | "<<space[1][1]<<"   | "<<space[1][2]<<"  \n";
    cout<< "___|_____|__\n";
    cout<< "   |     |  \n";
    cout<< " "<<space[2][0]<<" | "<<space[2][1]<<"   | "<<space[2][2]<<"  \n";
    cout<< "   |     |  \n";
}

void functionTwo(){           //for putting the values of x & 0


    int digit;

    if(token=='x')
    {
        cout<<n1<<" please enter the position where you want to put x ";
        cin>>digit;
    }

    if(token=='0')
    {
        cout<<n2<<" please enter the position where you want to put 0 ";
        cin>>digit;
    }

    if(digit==1)
    {
        row=0;
        column=0;
    }
    if(digit==2)
    {
        row=0;
        column=1;
    }
    if(digit==3)
    {
        row=0;
        column=2;
    }
    if(digit==4)
    {
        row=1;
        column=0;
    }
    if(digit==5)
    {
        row=1;
        column=1;
    }
    if(digit==6)
    {
        row=1;
        column=2;
    }
    if(digit==7)
    {
        row=2;
        column=0;
    }
    if(digit==8)
    {
        row=2;
        column=1;
    }
    if(digit==9)
    {
        row=2;
        column=2;
    }
    else if(digit<1 || digit>9){
        cout<<"Invalid !"<<endl;
    }

    if(token=='x' && space[row][column] !='x' && space[row][column] != '0')
{
    space[row][column]='x';
    token='0';
}
else if(token=='0' && space[row][column] !='x' && space[row][column] != '0')
{
    space[row][column]='0';
    token='x';
}
else{
    cout<<"There is no empty space!"<<endl;
    functionTwo();
}
functionOne();
}

bool functionThree()   // condition of winning the game
{
    for(int i=0;i<3;i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
    {
        return true;
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie=true;
    return false;
}

int main()
{

    cout<<"Enter the name of the first player: \n";
    getline(cin, n1);
    cout<<"Enter the name of the second player: \n";
    getline(cin, n2);
    cout<<n1<< " is player1 so he will play first \n";
    cout<<n2<< " is player2 so he will play second \n";

    while(!functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }

    if(token == 'x' && tie == false)
    {
        cout<<n2<<" Wins the game"<<endl;
    }
    else if(token == '0' && tie == false)
    {
        cout<<n1<<" Wins the game"<<endl;
    }
    else
    {
        cout<<"It is a draw!"<<endl;
    }
}
