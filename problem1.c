/*
Author: Dylan O'Briem
Assignment: EECS 348 Lab 5 Problem 1
Description: The file's purpose is to fufill given requirements that are necessary in a complete sales report
*/

#include <stdio.h>
#include <stdlib.h>

//Printing month with corresponding sales value
void salesreport(char *months[], double salesvals[]){
    printf("Monthly Sales Report for 2022:\n");
    printf("Month\t\tSales\n");
    for(int i=0; i<12; i++){
        printf("%-10s\t$%.2f\n",months[i],salesvals[i]);
    }
}
//Function to create sales summary
void salessummary(char *months[], double salesvals[]){
    //Variables created to keep track of total sales, minimum sales, max sales, minimum sales month and maximum sales month
    double totalsales=salesvals[0];
    double min1=salesvals[0];
    double max1=salesvals[0];
    int curmonthmin=0;
    int curmonthmax=0;
    //start at first value in list and compare it to the next given value and so on
    for(int i=1; i<12; i++){
        totalsales+=salesvals[i];
        if(salesvals[i]<min1){
            min1=salesvals[i];
            curmonthmin=i;
        }
        if(salesvals[i]>min1){
            max1=salesvals[i];
            curmonthmax=i;
        }
    }
    //compute total average
    double average= totalsales/12.00;
    //Print final values
    printf("Sales Summary:\n");
    printf("Minimum sales: $%.2f \t(%s)\n",min1,months[curmonthmin]);
    printf("Maximum sales: $%.2f \t(%s)\n",max1,months[curmonthmax]);
    printf("Average sales: $%.2f\n",average);
}
//Function to compute iterations of 6 month reports
void sixmonthreport(char* months[], double salesvals[]){
    printf("Six-Month Moving Average Report\n");
    //Nested loop to help move from current month to six months ahead
    for(int i=0; i<=6; i++){
        double sixmonthtotal=0.00;
        for(int j=i; j<i+6; j++){
            double monthsales=salesvals[j];
            sixmonthtotal+=monthsales;
        }
        //print final six month averages
        double avg= sixmonthtotal/6;
        printf("%-10s\t -  %s\t\t $%.2f\n",months[i],months[i+5],avg);
    

    }
}
void sortedsalesreport(char *months[], double salesvals[]){
    //classic selection sorting algorithm used
    //i below is chosen as a value in relation to the sorted section
    for(int i=0;i<11;i++){
        int newmax=i;
        //looking for maximum in unsorted section
        for(int j=i+1;j<12;j++){
            if(salesvals[j]>salesvals[newmax]){
                newmax=j;
            }
        }
        //when a maxium is found the current and max indicies are swapped
        //The values of those indicies are hence swicthed within the salesvals and months arrays
        double tsales=salesvals[i];
        salesvals[i]=salesvals[newmax];
        salesvals[newmax]=tsales;

        char *tmonth=months[i];
        months[i]=months[newmax];
        months[newmax]=tmonth;

    }
    //print sales from highest to lowest with corresponding month
    printf("Sales Report (Highest to Lowest):\n");
    printf("Months\t\tSales\n");
    //Use while loop to do so
    int i=0;
    while(i<12){
        printf("%-10s\t$%.2f\n",months[i],salesvals[i]);
        i++;
    }
    


}



int main(){
    //create array for months array which requires a pointer since its values are strings
    //create array salesvals for the sale values that will come from input file
    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    double salesvals[12];
    int mnum=0;
    //array that will store input file data
    char dafile[250];
    printf("Please enter the file name: ");
    //obtaining file and storing data in dafile
    scanf("%s",dafile);
    //opening file
    FILE *ff= fopen(dafile,"r");
    //making sure file isn't empty or that it exists
    if(ff==NULL){
        printf("Unable to open file");
        return 1;
    }
    //Taking doubles to put into salesvals array from dafile
    //making sure more than 12 doubles aren't obtained
    while(fscanf(ff, "%lf", &salesvals[mnum]) && mnum<12 ==1){
        mnum++;
    }
    //close file reading
    fclose(ff);
    //call all functions
    salesreport(months,salesvals);
    printf("\n");
    salessummary(months,salesvals);
    printf("\n");
    sixmonthreport(months,salesvals);
    printf("\n");
    sortedsalesreport(months,salesvals);
    return 0;

}
