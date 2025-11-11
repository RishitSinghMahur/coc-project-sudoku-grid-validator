#include <stdio.h>


/*
check_rows - Explaination
flag --> 1-true , 0-false

loop 1 outerloop - iterates over every row

innerloop - iterates over every value of a row and storing it into a variable num
            
            a value to array based checklist is incremented at the index of num

            since there are 9 distinct values and 9 row that should have those 9 values exactly once
            we get an array of 9 with each value 9


loop 2  checks the array ,if any value is not 9 flag is changed
*/
int check_rows(int arr[9][9]){
    int flag = 1; // By default we assume the rows have non repeating values
    int checklist [9] = {0,0,0,0,0,0,0,0,0}; // array based checklist
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int num = arr[i][j]-1;
            checklist[num]++;
        }
    }

    for(int i=0;i<9;i++){
        if(checklist[i] != 9){
            flag = 0;
            break;
        }
        
    }

    return flag;
}



/*
check_duplicate - Explaination
flag --> 1-true , 0-false

same as check_rows but this time for columns

*/



int check_cols(int arr[9][9]){
    int flag = 1;// by default we assume columns have no repeating values
    int checklist [9] = {0,0,0,0,0,0,0,0,0}; // array based checklist
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int num = arr[j][i]-1;
            checklist[num]++;
        }
    }

    for(int i=0;i<9;i++){
        if(checklist[i] != 9){
            flag = 0;
            break;
        }
        
    }

    return flag;
}



/*
check_duplicate - Explaination
Aim - check duplicate
flag --> 1-true , 0-false

outerloop - runs nine time to check the nine values of array
            has a counter that resets every iteration.

            num has range 1 to 9 (the values which should occur exactly once)

            if statement to check counter value after inner loop completes

innerloop - iterates over array with num from outer loop as target value and
            j as the innerloop pointer pointing at every value ,if value matches
            counter is incremented by 1

*/
int check_duplicate(int arr[9]){
    int flag = 1;//default case - does not contain duplicate

    for(int num=1;num<=9;num++){
        int count = 0;
        for(int j=0;j<9;j++){
            if(num==arr[j]){
                count++;
            }else{
                continue;
            }
        }
        if(count!=1){
            //if count is not one then we encountered duplicate value --> switch flag to flase(0);
            flag = 0;
            break;
        }
        
    }

    return flag;
}


/*
getSubgrid - Explaination
Aim - extract a 3x3 subgrid from a 9x9 2d array and decay it into 1d array of 9 values

row and col variable define the index parameter for the subgrid

count is used as a index for checklist

outerloop - runs 3 times to iterate over every row


innerloop - runs 3 time to iterate overy every column
            value retrived is stored in checklist at index count 
            counter is incremented


col = colend-3 is used to reset the column so it starts from initial value

*/

int getSubgrid(int arr[9][9],int row,int col){
    // here --> 3x3 logic
    int checklist[9]; // array-based checklist , 2d array decays into 1d array
    int count=0;
    // adding 3 to set the parameters for 3x3 subgrid
    int rowend=row+3;
    int colend=col+3;
    for(;row<rowend;row++){
        for(;col<colend;col++){
            checklist[count] = arr[row][col];
            count++;
        }
        col=colend-3;
    }
    // to here
    return check_duplicate(checklist);

    
}


/*
check_subGrid - Explaination
isDistinct --> 1-true , 0-false

outerloop - runs 3 times at interval of 3

innerloop - runs 3 times at interval of 3
            calls --> getSubgrid() --> check_Duplicate which return either 0 or 1
            
            getSubgrid() extracts a 3x3 and decays it into 1d array and passes it as a parameter into check_Duplicate()
            returning an int value which is stored in isDistinct

*/
int check_subgrid(int arr[9][9]){
    int isDistinct  = 1;
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            
            int isDistinct = getSubgrid(arr,i,j);
            if(isDistinct!=1){
                return isDistinct;

            }    

        }
    }
}





int main(){



    int solved[9][9] = {
    {5,3,4, 6,7,8, 9,1,2},
    {6,7,2, 1,9,5, 3,4,8},
    {1,9,8, 3,4,2, 5,6,7},

    {8,5,9, 7,6,1, 4,2,3},
    {4,2,6, 8,5,3, 7,9,1},
    {7,1,3, 9,2,4, 8,5,6},

    {9,6,1, 5,3,7, 2,8,4},
    {2,8,7, 4,1,9, 6,3,5},
    {3,4,5, 2,8,6, 1,7,9}

    };


    if(check_cols(solved) == 1 && check_rows(solved) == 1 && check_subgrid(solved) == 1){
        printf("VALID SOLUTION");
    }else{
        printf("INVALID SOLUTION");
    }






}