/*
Author: Dylan O'Briem
Assignment: EECS 348 Lab 5 Problem 2
Description: The file's purpose is to fufill given requirements that are necessary to write out every possible score combination of
an NFL game. The user can see the outcomes for as many scores as they want until they click a number less than 1.
*/

#include <stdio.h>
#include <stdbool.h>
//print each combo
void printcombos(int eight, int seven, int six, int three, int two){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", eight, seven, six, three, two);
}
//Function to check each possible score
void scorecaller(int score){
    printf("Possible combinations of scoring plays:\n");
    //Check possibility of each touchdon with a two point conversion. Number of tds with 2pt conversion must be <=score
    for(int eight=0; eight*8<=score; eight++){
        //Check possibility of each touchdon with a fg. Number of tds with a fg must be <=score
        for(int seven=0; seven*7<=score; seven++){
            //Check possibility of each touchdon. Number of tds must be <=score
            for(int six=0; six*6<=score; six++){
                //Check possibility of each fg. Number of fgs must be <=score
                for(int three=0; three*3<=score; three++){
                    //Check possibility of each safety. Number of td with a fg must be <=score
                    for(int two=0; two*2<=score; two++){
                        //Make sure all point totals are equal to score or else something is wrong
                        if(eight*8 + seven*7 + six*6 + three*3 + two*2==score){
                            //Call printcombos with each respective combo
                            printcombos(eight,seven,six,three,two);
                        }
                    }
                }
            }

        }
    }
}

int main(){
    //will be the user's score input
    int userscore;
    bool t = true;
    //if user enters a number<=1 nothing else will be asked
    //Will continue to ask user for a score otherwise
    while(t==true){
        printf("Please enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d",&userscore);
        if(userscore<=1){
            t= false;
            return printf("You have sucessfully stopped\n");
        }
        scorecaller(userscore);
    }
    
    return 0;
    

}


