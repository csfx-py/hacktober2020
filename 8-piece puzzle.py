from copy import deepcopy
from collections import deque

class EightPuzzle:
    def __init__(self,parent):
        #state_lst now holds the root, the parent state
        self.state_lst = [[row for row in parent]]

    #displays all states in state_lst
    def display(self):
        i = 0
        for state in self.state_lst:
            print('Node: ' + str(i))
            i = i + 1
            for row in state[0]:
                print (row)
            print (" ")
        
    #returns (row,col) of value in state indexed by state_idx  
    def find_coord(self, value, state_idx):
        for row in range(3):
            for col in range(3):
                if state_idx[row][col] == value:
                    return (row,col)
        
                
    #returns list of (row, col) tuples which can be swapped for blank
    #these form the legal moves of the state indexed by state_idx
    def get_new_moves(self, state_idx):
        row, col = self.find_coord(0,state_idx) #get row, col of blank
        
        moves = []
        if col > 0:
            moves.append((row, col - 1))    #go left
        if row > 0:
            moves.append((row - 1, col))    #go up
        if col < 2:
            moves.append((row, col + 1))    #go right
        if row < 2:
            moves.append((row + 1, col))    #go down
       
        return moves

    #Generates all child states for the state indexed by state_idx
    #in state_lst.  Appends child states to the list
    def best_first(self,state_idx,goal):
        #create queues
        open_queue = deque()
        closed_queue = deque()
        children_queue = deque()

        #creates the hurristic for the original state
        hur_val = self.huristic(self.state_lst[0],goal)
        fvalue = state_idx + hur_val
        #appends the original state and its coresponding huristic value to open
        open_queue.append((self.state_lst[0],fvalue))
        
        #increment the currnet level
        state_idx = state_idx + 1
        
        #while the open queue is not empty
        while open_queue and state_idx < 6:
            #remove the left most item
            cs = open_queue.popleft()
            closed_queue.append(cs)
            #if the current item child is our goal, return true
            if cs[0] == goal:
                return closed_queue
            
            #append new moves to the open queue
            #open_queue.append(self.get_new_moves(state_idx))
            move = self.gen_states(state_idx,cs[0])
            for state in move:
                children_queue.append(state)

            #while the children queue is not empty, deque the child 
            while children_queue:
                kiddo = children_queue.popleft()
                #if the dequed kiddo is not already in the lists, find huristic and add it
                if kiddo not in[temp[0] for temp in open_queue] and kiddo not in[temp2[0] for temp2 in closed_queue]:
                    hur_val = self.huristic(kiddo,goal)
                    fvalue = (state_idx) + hur_val
                    open_queue.append((kiddo,fvalue))
                
                #if the kiddo is already in the open que, check to see if it's huristic value is less than the one already
                #stored in the open queue, if its less take remove the old and append new
                if kiddo in [temp[0] for i, temp in enumerate(open_queue)]:
                    if self.huristic(kiddo,goal) < self.huristic(temp[0],goal):
                        del open_queue[i]
                        hur_val = self.huristic(kiddo,goal)
                        fvalue = (state_idx) + hur_val
                        open_queue.append((kiddo,fvalue))
                        
                #if the kiddo is already in the closed queue and the current state has a better 
                #huristic, remove the old one and append the new one          
                if kiddo in [temp[0]for i, temp in enumerate(closed_queue)]:
                    if self.huristic(kiddo,goal) < self.huristic(temp[0],goal):
                        del closed_queue[i]
                        hur_val = self.huristic(kiddo,goal)
                        fvalue = (state_idx) + hur_val
                        open_queue.append((kiddo,fvalue))
               
            #append the item to the closed queue if it is not the goal
            #closed_queue.append(cs)
            temp_lst = sorted(open_queue, key = lambda x: x[1])
            #clears the old un sorted queue
            while open_queue:
                open_queue.popleft()
            #re creates the queue in the sorted manner
            for item in temp_lst:
                open_queue.append(item) 
    

    #Creates the new states from a given parent
    def gen_states(self,state_idx, state):
        new_moves = []
        
        #get the new legal moves from the given state
        move_lst = self.get_new_moves(state)
        
        # blank is a tuple, holding coordinates of the blank tile
        blank = self.find_coord(0, state)
        
        # tile is a tuple, holding coordinates of the tile to be swapped
        # with the blank
        
        for tile in move_lst:
            
            # create a new state using deep copy
            # ensures that matrices are completely independent
            child = deepcopy(state)

            # move tile to position of the blank
            child[blank[0]][blank[1]] = child[tile[0]][tile[1]]
            # set tile position to 0
            child[tile[0]][tile[1]] = 0
            # append child state to the list of states.

            new_moves.append(child)
        return new_moves
    

    #Creates the hurristic value of a given state and returns a vlaue dependent on how many are 
    #wrong in the current state
    def huristic(self, cur, goal):
        error = 0
        for i in range(0,3):
            for j in range(0,3):
                if cur[i][j] != goal[i][j]:
                    error += 1
        return error

        
def main():
    #nested list representation of 8 puzzle. 0 is the blank.
    #This configuration is found on slide 8, E: Two Search Algorithms
    parent = [[2,8,3],
              [1,6,4],
              [7,0,5]]
    #creates the goal state of the 8-puzzle
    goal = [[1,2,3],
            [8,0,4],
            [7,6,5]]
    
    #the initial level of the puzzle to check
    level = 0

    #initialize the list of states (state_lst) with the parent
    p = EightPuzzle(parent)
    
    #Generate the states reachable from the parent
    p.state_lst = p.best_first(level,goal)
    
    #display all states in state_lst                    
    p.display()

main()
