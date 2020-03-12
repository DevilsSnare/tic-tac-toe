#include <iostream>
using namespace std;
char PLAYER='X';
char array[]={
                    '-', '-', '-',
                    '-', '-', '-',
                    '-', '-', '-'
                };
int board()
{
  int input;
  cout << "Its "<< PLAYER <<"'s turn.\n";
  cout << "Choose a place on board: ";
  cin >> input;
  if (input<=0 || input>9)
  {
    cout << "The position entered is not even their. Try again.\n";
    board();
  }
  else
  {
    if (array[input-1]!='-')
    {
      cout << "The position is taken. Choose another position.\n";
      board();
    }
  else
    return (input-1);
  }
}
void change_player()
{
  if (PLAYER=='X')
    PLAYER='O';
  else if (PLAYER=='O')
    PLAYER='X';
}
//to check win by row
bool check_row()
{
  for (int i=0;i<3;i++)
  {
    if ((array[3*i+0]==PLAYER) && (array[3*i+1]==PLAYER) && (array[3*i+2]==PLAYER))
    {   
      return true;
      break;
    }
  }
  return false;
}
//to check win by column
bool check_column()
{
  for (int i=0;i<3;i++)
  {
    if ((array[i+0]==PLAYER) && (array[i+3]==PLAYER) && (array[i+6]==PLAYER))
    {
      return true;
      break;
    }  
  }
  return false;
}
//to check win by diagonal
bool check_diagonal()
{
  if (((array[0]==PLAYER) && (array[4]==PLAYER) && (array[8]==PLAYER)) || (array[2]==PLAYER) && (array[4]==PLAYER) && (array[6]==PLAYER))
    return true;
  else
    return false;
}
//to check the win by row or column or diagonal
bool check_win()
{
  if (check_row() || check_column() || check_diagonal())
    return true;
  else
    return false;
}
int main()
{
    int i=0;
    bool win;
    cout << "\n";
    cout << "WELCOME TO TIC TAC TOE\n\n";
    //display initial board
    cout << array[0] << " | " << array[1] << " | " << array[2] << "    ";
    cout << "| 1" << " | " << "2" << " | " << "3 |" << endl;
    cout << array[3] << " | " << array[4] << " | " << array[5] << "    ";
    cout << "| 4" << " | " << "5" << " | " << "6 |" << endl;
    cout << array[6] << " | " << array[7] << " | " << array[8] << "    ";
    cout << "| 7" << " | " << "8" << " | " << "9 |" << endl;
    while (i<9)
    { 
      array[board()]=PLAYER;
      cout << "\n";
      //display the board after every input
      cout << array[0] << " | " << array[1] << " | " << array[2] << "    ";
      cout << "| 1" << " | " << "2" << " | " << "3 |" << endl;
      cout << array[3] << " | " << array[4] << " | " << array[5] << "    ";
      cout << "| 4" << " | " << "5" << " | " << "6 |" << endl;
      cout << array[6] << " | " << array[7] << " | " << array[8] << "    ";
      cout << "| 7" << " | " << "8" << " | " << "9 |" << endl;
      win=check_win();
      if (win==true)
      { 
        cout << "Winner is " << PLAYER << endl;
        break;
      }
      else
        change_player();
      i++;
    }
    if (win!=true)
      cout << "Its a draw!";
}
