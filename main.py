board=[
        "-", "-", "-",
        "-", "-", "-",
        "-", "-", "-",
]
current_player="X"
win=False
def display_board():
    print("\n")
    print(board[0] + " | " + board[1] + " | " + board[2] + "    1 | 2 | 3")
    print(board[3] + " | " + board[4] + " | " + board[5] + "    4 | 5 | 6")
    print(board[6] + " | " + board[7] + " | " + board[8] + "    7 | 8 | 9")
    print("\n")

def game():
    display_board()
    i=0
    while i<9:
        handle_turns()
        display_board()
        check_win()
        if (win==True):
            print("The winner is " + current_player + ". Congrats!")
            break
        else:
            change_player()
        i=i+1
    if (win==False):
        print("Its a draw!")

def change_player():
    global current_player
    if (current_player=="X"):
        current_player="O"
    elif (current_player=="O"):
        current_player="X"

def handle_turns():
    global current_player
    print("Its " + current_player + "'s turn.")
    location=input("Choose a place on board: ")
    if (int(location)<=0 or int(location)>9):
        print("The position entered is not even their. Try again.\n")
        handle_turns()
    else:
        location=int(location)-1
        if board[location]!="-":
            print("The position is taken. Choose another position.\n")
            handle_turns()
        else:
            board[location]=current_player

def check_win():
    global win
    if (check_row() or check_column() or check_diagonal()):
        win=True

def check_row():
    for i in range(0,3):
        if ((board[3*i+0]==current_player) and (board[3*i+1]==current_player) and (board[3*i+2]==current_player)):
            return True

    return False

def check_column():
    for i in range(0,3):
        if ((board[i+0]==current_player) and (board[i+3]==current_player) and (board[i+6]==current_player)):
            return True
    
    return False

def check_diagonal():
    if (((board[0]==current_player) and (board[4]==current_player) and (board[8]==current_player)) or ((board[2]==current_player) and (board[4]==current_player) and (board[6]==current_player))):
        return True
    else:
        return False

game()