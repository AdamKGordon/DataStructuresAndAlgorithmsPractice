/*
typedef struct row_col_s {
    int row;
    int col;
} row_col_t;
*/

/*
void debugPrint(row_col_t maxPos, int *grid) {
    int i,j;
    printf("\n");
    for (i=0; i<maxPos.row; i++) { // row
        for (j=0; j<maxPos.col; j++) { // col
            printf("%d", grid[i*(maxPos.col)+j]);
        }
        printf("\n");
    }
    printf("\n");

    return;
}
*/

/*
row_col_t adjacentIndicies(row_col_t curPos, int indexNum) {
    // each square has 4 adj tiles, for the 1st one enter indexNum=0    
    row_col_t retVal = curPos;
    
    switch (indexNum) {
        case 0: ///top
            retVal.row -= 1;        
            break;
        case 1: //right
            retVal.col += 1;        
            break;
        case 2: //bot
            retVal.row += 1;        
            break;
        case 3: //left
            retVal.col -= 1;        
            break;
        default: 
            printf("ERROR\n");
    }  
    //printf("row: %d   col: %d\n", retVal.row, retVal.col);  
    return retVal;
}
*/

void dfsIsland(char **grid, 
               int *exploredGrid,
               int *foundIslands, 
               int curRow,
               int curCol,
               int maxRow,
               int maxCol,
               int numEle) {
    // Finds all adjacent land in grid and plot is on explored_grid with num foundIslands
    int idx = curRow*maxCol+curCol;
    static int depth;
    //printf("01111:  %d %d\n",idx,numEle);
    if(curRow < maxRow && curCol < maxCol // not OOB
       && curRow >= 0 && curCol >= 0 // not OOB
       && idx < numEle // not OOB 
       && grid[curRow][curCol] == '1' // not in water
       && exploredGrid[idx] == 0) { // not visited
        //printf("02222:  %d %d\n",idx,numEle);
        depth++;
        if (depth == 1) { // new island
            (*foundIslands)++;
        }
        exploredGrid[idx] = *foundIslands;

        
        dfsIsland(grid, exploredGrid, foundIslands, curRow-1, curCol, maxRow, maxCol,numEle); // up   
        dfsIsland(grid, exploredGrid, foundIslands, curRow, curCol+1, maxRow, maxCol,numEle); // right
        dfsIsland(grid, exploredGrid, foundIslands, curRow+1, curCol, maxRow, maxCol,numEle); // down
        dfsIsland(grid, exploredGrid, foundIslands, curRow, curCol-1, maxRow, maxCol,numEle); // left
        
        depth--;

    }
    return;
}


int numIslands(char** grid, int gridSize, int* gridColSize){
    // gridSize is num of rows  and  gridColSize is num of cols
    int numIslands = 0;
    int i, j;
    int curRow, curCol;
    curRow = 0;
    curCol = 0;
    int maxRow, maxCol;
    maxRow = gridSize;
    maxCol = *gridColSize;
    int *exploredGrid;
    int numEle=maxRow*maxCol;
    exploredGrid = (int *) malloc(sizeof(int)*gridSize*(*gridColSize));

    
    for (i=0; i<gridSize; i++) { // row
        for (j=0; j<*gridColSize; j++) { // col
            exploredGrid[i*(*gridColSize)+j] = 0;
        }
    }
    

    for (i=0; i<gridSize; i++) { // row
        for (j=0; j<*gridColSize; j++) { // col
            curRow = i;
            curCol = j;
            dfsIsland(grid, exploredGrid, &numIslands, curRow,curCol, maxRow,maxCol,numEle);
        }
    }
    
    //debugPrint(maxPos, exploredGrid);
    
    //printf("ANSWER=%d\n", numIslands);
    printf("%d\n", numIslands);
    free(exploredGrid);
    return numIslands;
}
        
        