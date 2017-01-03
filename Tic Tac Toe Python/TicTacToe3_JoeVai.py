import turtle
import math

"""Made by Joe and Vai, plz don't steal thx"""

class board:
    """Class for all methods relevent to the tic tac toe board."""

    def __init__(self, gridSize = 200, width = 3, winNum = 3):
        """General initialization routine. Sets up all class variables that will be used later.
    most important set up is the cell grid that is a square of parameter width.
    Function arguments:
    gridSize: length of the lines of each box. 200 by default
    width: the number of boxes on that the board is made up of: 3x3, 5x5, etc. 3x3 by default
    winNum: The number of claimed boxes you must have in a row to win the game. 3 by default"""
        
        self.size = gridSize
        self.width = width + (width+1)%2
        self.cells = []
        self.wn = winNum
        if width < winNum:
            self.wn = width
        for i in range(self.width):
            hold = []
            for j in range(self.width):
                hold.append(str(i*self.width + j))
            self.cells.append(hold)

    def setTurtle(self):
        """Initializes the turtle object and screen object, while also setting the speed to the maximum"""
        
        self.t = turtle.Turtle()
        self.s = turtle.Screen()
        self.t.speed(0)
        
    def printGrid(self):
        """Prints the list of cells, for debugging purposes only"""
        
        for i in self.cells:
            print(i)

    def cellNumToCellCoords(self, cell):
        """Converts input of cell number into a set of cell coordinates of the list. Ex: 2 -> [0,2]
    Function arguments:
    cell: The cell number to be converted.
    Returns the coordinate pair"""
        
        return [(cell) % self.width, (cell)//self.width]

    def cellCoordsToCellNum(self, coords):
        """Converts a set of cell coords into a grid number. Ex: [0,2] -> 2
    Function arguments:
    coords: The list coordinates of the cell to be converted
    Returns the cell number"""
        
        return coords[0] + coords[1]*self.width

    def checkWin(self):
        """Scans through the board to determine if either player has won the game yet
    Returns a list of the following format (elements 1/2 are only included if a win has occured)
    [0]: True or False whether a player has won the game
    [1]: The coordinates of the first cell of the winning line
    [2]: The coordinates of the last cell of the winning line"""
    
        for i in range(self.width):
            for j in range(self.width-self.wn+1):
                flags = [True, True]
                for k in range(self.wn):
                    if self.cells[i][j] != self.cells[i][j+k]:
                        flags[0] = False
                    if self.cells[j][i] != self.cells[j+k][i]:
                        flags[1] = False
                if flags[0]:
                    return [True, [i,j], [i, j+self.wn-1]]
                elif flags[1]:
                    return [True, [j,i], [j+self.wn-1, i]]
        for i in range(self.width-self.wn+1):
            for j in range(self.width-self.wn+1):
                flags = [True, True]
                for k in range(self.wn):
                    if self.cells[i][j] != self.cells[i+k][j+k]:
                        flags[0] = False
                    if self.cells[i+self.wn-1][j] != self.cells[i+self.wn-1-k][j+k]:
                        flags[1] = False
                if flags[0]:
                    return [True, [i,j], [i+self.wn-1, j+self.wn-1]]
                elif flags[1]:
                    return [True, [i+self.wn-1,j], [i, j+self.wn-1]]  
        return [False]
    
    def checkDraw(self):
        """Determines whether the game has ended in a draw
    Returns True or False to whether there is a draw"""
        
        num = [str(i) for i in range(self.width*self.width)]
        if self.checkWin()[0]:
            return False
        else:
            for i in range(self.width):
                for j in range(self.width):
                    if self.cells[i][j] in num:
                        return False
            return True

    def drawBoard(self):
        """Draws the game board to the dimensions given as parameters"""
        
        self.setTurtle()
        
        for i in range(2*(self.width-1)):
            self.t.up()
            if i < self.width-1:
                self.t.goto(-self.size//2 + (i-.5*self.width+1.5)*self.size, self.width*self.size//2)
                self.t.setheading(-90)
            else:
                self.t.goto(-self.width*self.size//2,-self.size//2 + (i-1.5*self.width+2.5)*self.size)
                self.t.setheading(0)
            self.t.down()
            self.t.fd(self.size*self.width)
        for i in range(self.width):
            for j in range(self.width):
                self.t.up()
                self.t.goto(-self.width*self.size//2 + j*self.size + self.size//10, self.width*self.size//2 - i*self.size - self.size//5,)
                self.t.down()
                self.t.write(str(j + i * self.width), font = ("Arial", self.size//10+1, "bold"))
        self.t.width(1/20*self.size)

    def drawX(self):
        """Draws an X for player 1"""
        
        self.t.color("red")
        self.t.down()
        self.t.setheading(60)
        for i in range(2):
            self.t.fd(self.size/2)
            self.t.bk(self.size)
            self.t.fd(self.size/2)
            self.t.left(60)
        self.t.setheading(0)

    def drawO(self):
        """Draws an O for player 2"""
        
        radius = (self.size/2)*(math.sqrt(3)/2)
        self.t.color("blue")
        self.t.right(90)
        self.t.fd(radius)
        self.t.left(90)
        self.t.down()
        self.t.circle(radius)

    def drawSymbol(self, turn, gridNumber):
        """Attempts to draw a symbol for the specified player in the chosen cell/grid number
    Function Arguments:
    turn: The turn number that specifies what player chose. 0 for player 1, 1 for player 2
    gridNumber: The cell that the player wants to select
    Returns True or False on whether the draw operation was successful. Fails if the cell is already taken"""
        
        symb = ['X', 'O']
        if self.cells[gridNumber//self.width][gridNumber%self.width] in symb:
            return False
        coordinates = self.cellNumToCellCoords(gridNumber)
        self.t.up()
        self.t.goto((coordinates[0]-(self.width-1)/2)*self.size, ((self.width-1)/2-coordinates[1])*self.size)
        if turn == 0:
            self.cells[gridNumber//self.width][gridNumber%self.width] = "X"
            self.drawX()
        else:
            self.cells[gridNumber//self.width][gridNumber%self.width] = "O"
            self.drawO()
        return True

    def drawLine(self, a, b):
        """Draws a line between two cells
    Function arguments:
    a: The coordinate list of the first cell in the line
    b: The coordinate list of the last cell in the line"""
        
        self.t.color("gold")
        self.t.up()
        self.t.goto((a[1]-(self.width-1)/2)*self.size, ((self.width-1)/2-a[0])*self.size)
        self.t.down()
        self.t.goto((b[1]-(self.width-1)/2)*self.size, ((self.width-1)/2-b[0])*self.size)

class TicTacToe:
    """Class for handeling a game of tic tac toe. Uses board class"""

    def __init__(self, n1, n2, gridSize = 200, width = 3, winNum = 3):
        """Initializes the game of tic tac toe by setting the player names and initializing the game board.
    Function arguments:
    n1: Name of player 1
    n2: Name of player 2
    gridSize: The line length of the sides of each tic tac toe box. Default 200
    width: The dimension of the square board. Ex: 3x3, 5x5, etc. Default 3x3
    winNum: The number of symbols required to be in a line to win the game. Default 3"""
        
        self.players = [n1, n2]
        self.width = width
        self.b = board(gridSize, self.width, winNum)

    def twoPlayer(self):
        """Runs a two player game of tic tac toe using a board object"""
        
        turn = 0
        self.b.drawBoard()
        while (not self.b.checkWin()[0])and(not self.b.checkDraw()):
            cellInput = int(input(self.players[turn] + " choose your cell number:"))
            if cellInput > self.width**2 - 1 or cellInput < 0:
                print("Cell number out of range")
            if not self.b.drawSymbol(turn, cellInput):
                print("Space already taken")
                continue
            turn = (turn+1)%2
        win = self.b.checkWin()
        if win[0]:
            self.b.drawLine(win[1],win[2])
            print(self.players[1-turn]+" won the game")
        else:
            print("There was a draw")

    

    
        
game = TicTacToe("Joe", "BigRussia", 200, 3, 3)
game.twoPlayer()


        
        
