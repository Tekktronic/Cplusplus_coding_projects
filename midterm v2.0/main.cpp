/* 
 * File:   main.cpp
 * Author: Adams, Jonathan - 42450
 * 
 * /////////////MIDTERM///////////////
 *
 * Created on April 22, 2014, 2:19 PM
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
//Global Constants
//Function Prototypes
//Execution
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short choose;
    char exit;
    //Welcome statement to not be looped
    cout<<"Welcome to the CSC5, Class 42450 MidTerm."<<endl;
    //Prompt user for number of problem to execute
    cout<<endl;
    cout<<endl;
    do {                                             ////MAIN MENU DO LOOP BEGIN
    cout<<"Choose from the following list"<<endl;
    cout<<"1. Problem 1: Diagonal"<<endl;
    cout<<"2. Problem 2: Asterisks"<<endl;
    cout<<"3. Problem 3: Bank Account"<<endl;
    cout<<"4. Problem 4: Paycheck"<<endl;
    cout<<"5. Problem 5: ISP"<<endl;
    cout<<"6. Problem 6: Funny Sequence"<<endl;
    cout<<"7. Exit Program"<<endl;
    cin>>choose;
    //Invalid input net-----
    while (!(choose>=1 && choose<=7)) {
        cin.clear();
    	cin.ignore();
        cout<<"Not an option! Please re-enter: "<<endl;
        cin>>choose;
    }
    //End invalid input net-----
    //Utilize switch to implement the menu
    switch(choose) {                                      //Begin switch choose
        
        case 1:{ 
///////////////////////////////Problem 1////////////////////////////////////////
            cout<<"Program 1: Diagonal";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
                //Local variables
                unsigned short numDia;
                //Prompt
                cout<<"Enter a number between 1 & 99 to see the diagonal"<<endl;
                cin>>numDia;
                cout<<endl<<endl;
                //Invalid input net-----
                /* I thought 1 through 99 certainly met the intent of this pro-
                 blem. I wanted to ensure all invalid entries would not cause
                 an error, and this is the only way I have successfully done
                 that. I would like to know how to prevent an issue with an
                 accidental character entry, while accepting ALL possible 
                 integers values, versus a range. */
                while (!(numDia>0&&numDia<=99)) {
                cin.clear();
                cin.ignore();
                cout<<"Not an option! Please re-enter: "<<endl;
                cin>>numDia;
                cout<<endl<<endl;
                }
                //Invalid input net-----
                //Some place holder variables. 
                int a=1, b=0;
                do {
                    //Extracting value of 'a' for internal loop, while allowing a
                    //to hold it's value after the loop.
                    b=a;
                    //Displaying spaces; no space for '1', so row=column is the
                    //location of all numbers.
                    while (b>1){
                        cout<<" ";
                        --b;
                    }
                    //Displaying the value at row=column. Reversing direction to
                    //count up from 1 to the numDia entered.
                    cout<<((numDia-numDia)+(a++))<<endl;
                    --numDia;
                } while (numDia>0);    
            //FINISH CODE///////////////////////////// 
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));      /////////do while loop 
            cout<<endl;
            cout<<endl;
            cout<<"End Program 1"<<endl;break;
        } //End option 1
        
        case 2:{
////////////////////////////////PROBLEM 2///////////////////////////////////////
            cout<<"Program 2: Asterisks";
            cout<<endl;
            unsigned short row, ast;
            do {
            //START CODE//////////////////////////////
                cout<<"Lets display some asterisks rows!\n";
                cout<<"How many times would you like to display asterisk rows?\n";
                cout<<"NOTE: 5 times max!"<<endl;
                cin>>row;
                cout<<endl<<endl;
                while (!(row>0&&row<=5)) {
                cin.clear();
                cin.ignore();
                cout<<"Not an option! Max is 5! Please re-enter: "<<endl;
                cin>>row;
                cout<<endl<<endl;
                }
                do {
                    cout<<"Enter a number between 3 and 27, and you will be\n";
                    cout<<"granted that many asterisk friends, in a row!"<<endl;
                    cout<<"This is your "<<row;
                    if (row==1) {
                        cout<<" and final";
                    }
                    else if (row==2) {
                        cout<<"nd to";
                    }
                    else if (row==3) {
                        cout<<"rd to";
                    }
                    else {
                        cout<<"th to";
                    }
                    cout<<" last chance to have asterisk friends."<<endl;
                    cin>>ast;
                    cout<<endl<<endl;
                    while (!(ast>=3&&ast<=27)) {
                    cin.clear();
                    cin.ignore();
                    cout<<"Not an option! Must be between 3 and 27!"<<endl;
                    cin>>ast;
                    cout<<endl<<endl;
                    }
                    while (ast>=3&&ast<=27) {
                        for(ast; ast>0; ast--)
                            cout<<"*";
                    }
                    cout<<endl<<endl;
                    row--;
                } while (row>0);
                
            //FINISH CODE/////////////////////////////  
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem 2"<<endl;break;
        } //End option 2
////////////////////////////////////////////////////////////////////////////////        
       
        case 3:{
////////////////////////////////PROBLEM 3///////////////////////////////////////
            cout<<"Program 3: Bank Account";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
                unsigned short acct[7], balW=0, balC=0, checksC=0, checksW=0;
                unsigned short deposC=0, deposW=0;
                cout<<"Enter your 6 Digit Account #: "<<endl;
                cout<<"Please key in one digit at a time, only digits"<<endl;
                cout<<"Any accidental character/letter entry will be a zero"<<endl;
                for (int i=1;i<7;i++) {
                    cin.clear();
                    cin.ignore();
                    //Prompts user for which digit it wants.
                    cout<<"Enter Digit "<<i<<" Then Press Return:"<<endl;
                    cin>>acct[i];
                    //Error entry net; ensure entry is a Digit.
                    //I really tried. But with an unsigned short, I cannot
                    //figure out how to correct an accidental character entry.
                        if(acct[i]<0||acct[i]>9){
                            cout<<"Error"<<endl;
                            i--;
                        }
                }
                //Display account #
                cout<<"Account #: ";
                cout<<acct[1]<<acct[2]<<acct[3]<<acct[4]<<acct[5]<<acct[6]<<endl;
                cout<<"Please enter the whole dollar amount of your balance: \n";
                cin>>balW;
                cout<<"Please enter the remaining cents: \n";
                cin>>balC;
                cout<<endl;
                //Display account info
                cout<<"Account #";
                cout<<acct[1]<<acct[2]<<acct[3]<<acct[4]<<acct[5]<<acct[6];
                cout<<" has $"<<balW<<"."<<balC<<endl;
                //Ask for total amount of of money withdrawn from the acct
                cout<<"Please enter the total of all checks written "<<endl;
                cout<<"Whole dollar amount:"<<endl;
                cin>>checksW;
                cout<<"Remaining cents:"<<endl;
                cin>>checksC;
                //Ask for total amount deposited
                cout<<"Please enter the total of all deposits made "<<endl;
                cout<<"Whole dollar amount:"<<endl;
                cin>>deposW;
                cout<<"Remaining cents:"<<endl;
                cin>>deposC;
                //Calculations
                //Set precision for calculations
                cout.setf(ios::fixed);
                cout.setf(ios::showpoint);
                cout.precision(2);
                //Cast total values as floats to access negative balances as 
                //well as combine dollars and cents
                float totB, totC;
                totB=static_cast<float>(balW+deposW-checksW);
                totC=static_cast<float>(balC+deposC-checksC);
                //Display account balance
                cout<<"Balance of Account #";
                cout<<acct[1]<<acct[2]<<acct[3]<<acct[4]<<acct[5]<<acct[6]<<endl;
                cout<<"the end of the month is:\n$";
                cout<<totB+(totC/100)<<endl;
                //Add fee if balance is negative
                if ((totB+(totC/100))<0) {
                    cout<<"You have overdrawn account #";
                    cout<<acct[1]<<acct[2]<<acct[3]<<acct[4]<<acct[5]<<acct[6]<<endl;
                    cout<<"A $12.50 fee has been subtracted from your\n";
                    cout<<"non-existent balance.\n";
                    cout<<"Your new account balance is:$";
                    cout<<((totB+(totC/100))-12.50)<<endl;
                }         
            //FINISH CODE/////////////////////////////
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem"<<endl;break;
        } //End option 3
////////////////////////////////////////////////////////////////////////////////
        
        case 4:{
////////////////////////////////PROBLEM 4///////////////////////////////////////
            cout<<"Program 4: Paycheck";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
            unsigned int hrW, hrP;
            float rate, tot, hrT;
            cout<<"Employee Payroll Application"<<endl;
            cout<<"Enter amount of complete, whole, hours worked by employee."<<endl;
            cin>>hrW;
            //Request partial hours in 15minute increments. Appropriate for the 
            //work force. I could make it by the minute, but I have never 
            //seen that anywhere I have worked per hour. 
            cout<<"Enter remaining partial hours worked, if any: \n";
            cout<<"15 Minute Increments Only"<<endl;
            cout<<"(EX. 15min=1, 30min=2, 45min=3)"<<endl;
            cin>>hrP;
            hrT=static_cast<float>(hrW+(hrP*.25));
            cout<<"Total Hours:"<<hrT<<endl;
            cout<<"Enter the hourly pay rate for employee: \n";
            cout<<"(Ex. 32.50)"<<endl;
            cin>>rate;
            cout<<fixed<<setprecision(2)<<showpoint;
            if (hrT<=20) {
            tot=(hrT*rate);
            cout<<"Gross Pay: \n$"<<tot<<endl;
            }
            else if (hrT>20&&hrT<=40) {
            tot=(rate*20)+((hrT-20)*(rate*1.5));
            cout<<"Gross Pay (Including time and a half): \n$"<<tot<<endl;
            }
            else {
            tot=(rate*20)+((rate*1.5)*20)+((hrT-40)*(rate*2));
            cout<<tot<<endl;
            cout<<"Gross Pay (Including time and a half & double time): \n$"<<tot<<endl;
            }
            //FINISH CODE/////////////////////////////
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem"<<endl;break;
        } //End option 4
////////////////////////////////////////////////////////////////////////////////
        
        case 5:{
////////////////////////////////PROBLEM 5///////////////////////////////////////
            cout<<"Program 5: ISP";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
            short chkM=1;
            char plan;
            float tot=0, hours=0;
            cout<<"Cable TV Company Bill Calculator:"<<endl;
            cout<<"Enter amount of hours watched last month: "<<endl;
            cin>>hours;
            cout<<"Please choose your Cable TV Package: (select option)\n";
            cout<<"Press A for \"Like It\" plan: $29.95 per month, \n";
            cout<<"11 hours access. Additional hours are $2.25  \n";
            cout<<" up to 22 hours. Then $4.95 per hour after that"<<endl;
            cout<<endl;
            cout<<"Press B for \"Love it\" plan: $34.95 per month \n";
            cout<<"22 hours access. Additional hours are $1.25 up to\n";
            cout<<"33 hours, then $2.25 per hour after that."<<endl;
            cout<<endl;
            cout<<"Press C for \"Gotta Have It\" plan: $42.95 per month \n";
            cout<<"Unlimited usage!"<<endl;
            cout<<endl;
            do {
            cout<<fixed<<setprecision(2)<<showpoint;
            chkM=1;
            cout<<endl<<"Enter Option: "<<endl;
            cin>>plan;
            if (plan=='A'||plan=='a') {
                if (hours>11&&hours<=22) {
                    tot=(hours*2.25)+(29.95);
                    cout<<"Total Bill Plan Aa: $"<<tot;   
                }
                else if (hours>22) {
                    tot=(2.25*11)+((hours-22)*4.95)+(29.95);
                    cout<<"Total Bill Plan Ab: $"<<tot;
                }
                else {
                    cout<<"Total Bill is $29.95";
                }
            }
            else if (plan=='B'||plan=='b') {
                if (hours>22&&hours<=33) {
                    tot=((hours-22)*1.25)+(34.95);
                    cout<<"Total Bill Plan Ba: $"<<tot;   
                }
                else if (hours>33) {
                    tot=(1.25*11)+((hours-3)*2.25)+(34.95);
                    cout<<"Total Bill Plan Bb: $"<<tot;
                }
                else {
                    cout<<"Total Bill is $34.95";
                }
            }
            else if (plan=='C'||plan=='c') {
                cout<<"Total Bill is $42.95";
            }
            else {
                cout<<"Not an option!"<<endl;
                cout<<"Choose again"<<endl;
                chkM=0;
            }
            } while (chkM==0);
            
            //FINISH CODE/////////////////////////////
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem"<<endl;break;
        } //End option 5
////////////////////////////////////////////////////////////////////////////////
        
        case 6:{
////////////////////////////////PROBLEM 6///////////////////////////////////////
            cout<<"Program 6: Funny Sequence";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
                unsigned int totNum=7;
                unsigned int corNum=6;
                unsigned int placHld=totNum;
                bool chkVal=false;
           
        for (totNum; corNum<1800; totNum++) {
            chkVal=false;
            placHld=totNum;
             while (totNum%2==0) {                
                    
                    totNum=(totNum/2);
                    
                    if (totNum/2==1){
                       
                       chkVal=true; 
                    }
             }
             while (totNum%3==0&&chkVal!=true)    {
                    
                    totNum=(totNum/3);
                    
                    if (totNum/3==1){
                       
                       chkVal=true; 
                    }
             }
             while (totNum%5==0&&chkVal!=true)    {
                    
                    totNum=(totNum/5);
                    
                    if (totNum==1){
                       
                       chkVal=true; 
                    }
             }
           totNum=placHld;  
             if (chkVal==true) {
                 corNum++;
              cout<<endl<<totNum<<" is the "<<corNum<<"# of the Funny Sequence!"<<endl;   
             }
            
           }
        
                 
                    
            //Output the 1475 corNum that comes out of the loops
            cout<<totNum-1<<" is the "<<corNum<<"th # in the Funny Sequence!";
            
            //FINISH CODE/////////////////////////////
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem"<<endl;break;
        } //End option 6
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////       
        case 7: {
            cout<<"Good Bye!"<<endl;break;
        }
////////////////////////////////////////////////////////////////////////////////  
    }                                 // switch statement end bracket for choose
////////////////////////////////////////////////////////////////////////////////
    } while (choose!=7);                         ////End Main Menu Do While Loop
////////////////////////////////////////////////////////////////////////////////        
//Exit Stage Right
    return 0;
}

