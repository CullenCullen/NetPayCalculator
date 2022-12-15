// A program by Cullen Shortt
// NetPayShortt.cpp
// This program calculates the weekly pay for salaried, hourly, and contracted
// employees.
// It also shows the total gross pay and gross tax for the week for all employees combined.
//Program will continue running while the menuChoice variable does not equal q or Q. 

#include <iostream> //The header file for displaying screen content and allowing keyboard input.
#include <iomanip> //allows for formatting of output statements.
using namespace std; 


//Function Prototypes
void menu(char &); //reference variable
double employeePay(double); //figures out the gross pay 
double employeePay(double, double);
double employeePay(double, int);

double employeeTax(double); //figures out the taxes
double employeeTax(double, double); 



int main() //This marks the beginning of a function.
{  //Program Variables
   char menuChoice;
   int    weeks;
   double yearlySalary,
          weeklyGrossPay,
          weeklyTax,
          hourlyRate,
          hoursWorked,
          contractAmount,
          tax = .075, //default tax amount
          grossSalaryPay,
          grossSalaryTax,
          grossHourlyPay,
          grossHourlyTax,
          grossContractPay,
          grossContractTax,
          totalSalaryTax;
          
            
   // set the numeric output formatting 
   cout << fixed << showpoint <<setprecision(2);
   
   //Display the Menu for selection
 do
  {
   cout << "\n\t\t~TCC's Employee Pay Calculator~\n\n"
        << "S"" - Enter 'S' if you are a salaried employee\n"
        << "H"" - Enter 'H' if you are a hourly employee\n"
        << "C"" - Enter 'C' if you are a contracted employee\n"
        << "Q"" - Enter 'Q' if you are finsihed.\n" << endl;
   menu(menuChoice);     
   
   //Get Employee Information
   switch(menuChoice)
   {
      case'S':
      case's': cout << "What is your yearly salary? "<< endl;
      cin >> yearlySalary;
      
      weeklyGrossPay = employeePay(yearlySalary); //sends argument to function
      weeklyTax = employeeTax(weeklyGrossPay);
      
      cout << "\n\t\t~Salaried Employee Weekly Receipt~\n"; //displays employee paystub
      cout << "Gross pay: " << setw(11);
      cout << weeklyGrossPay << endl;
      cout << "Taxes paid: " << setw(10) << weeklyTax << endl;
      cout << "Net Pay: "<< setw(13) << (weeklyGrossPay - weeklyTax) << endl;
       
       grossSalaryPay+=weeklyGrossPay; //accumulators 
       grossSalaryTax+=weeklyTax;
      break;
      
      case'H':
      case'h': 
      do {
      cout << "Please enter in values greater than 0." <<endl;
      cout << "What is your hourly Rate? $ ";
      cin >> hourlyRate;
      cout << "How many hours did you work? ";
      cin >> hoursWorked;
      }while (hourlyRate <= 0 || hoursWorked <= 0);

      weeklyGrossPay = employeePay(hourlyRate, hoursWorked); //sends arguments to function
      weeklyTax = employeeTax(weeklyGrossPay, tax);
      
      cout << "\n\t\t~Hourly Employee Weekly Receipt~\n"; //displays employee paystub
      cout << "Gross pay: " << setw(11);
      cout << weeklyGrossPay << endl;
      cout << "Taxes paid: " << setw(10) << weeklyTax << endl;
      cout << "Net Pay: "<< setw(13) << (weeklyGrossPay - weeklyTax) << endl;
       
       grossHourlyPay+=weeklyGrossPay; //accumulators 
       grossHourlyTax+=weeklyTax;
      break;
      
      case 'C':
      case 'c':
      do {
      cout << "Please enter in values greater than 0." << endl;
      cout << "What is the total contract amount? $ ";
      cin >> contractAmount;
      cout << "How many weeks was it for? ";
      cin >> weeks;
      }while (contractAmount <= 0 || weeks <= 0);

      weeklyGrossPay = employeePay(contractAmount, weeks); //sends arguments to function
      weeklyTax = employeeTax(weeklyGrossPay); //sends argument to function
      
      cout << "\n\t\t~Contracted Employee Weekly Receipt~\n"; //displays employee paystub
      cout << "Gross pay: " << setw(11);
      cout << weeklyGrossPay << endl;
      cout << "Taxes paid: " << setw(10) << weeklyTax << endl;
      cout << "Net Pay: "<< setw(13) << (weeklyGrossPay - weeklyTax) << endl;
       
       grossContractPay+=weeklyGrossPay; //accumulators 
       grossContractTax+=weeklyTax;

      break;   
   }    
   
   
   
 }while (menuChoice != 'q' && 'Q');
 
     //accumulators
     cout << "\n\t\t~Gross Employee Pay Totals~\n";
     cout << "All Employees Combined Gross Pay for the week: $" << setw(9) << (grossSalaryPay + grossHourlyPay + grossContractPay)
     << endl;
     cout << "All Employees Combined Gross Tax for the week: $" << setw(9) << (grossSalaryTax + grossHourlyTax + grossContractTax)    
     << endl;

     
}
      
/********************End of Main*****************************/      
     
      //Program Functions
      
     void menu (char &letterChoice) 
      //Gathers User Input and checks for validation
     {
      cout << "Please enter S, H, C, or Q ";
      cin >> letterChoice;
     
       while (letterChoice != 'S' && letterChoice != 's' &&
              letterChoice != 'H' && letterChoice != 'h' &&
              letterChoice != 'C' && letterChoice != 'c' &&
              letterChoice != 'Q' && letterChoice != 'q')
      {        
       cout << "I'm sorry, please enter S, H, C, or Q ";
       cin >> letterChoice;
      }
     }
     
     //**OVERLOADED FUNCTIONS FOR WEEKLY PAY**
     
     double employeePay(double salary) //salaried employee gross pay
     {
         while(salary <= 0)
         {
           cout << "Your salary cannot be 0 or less" <<endl;
           cout << "What is your yearly salary? ";
           cin >> salary;
         }
         
         return salary = salary / 52;
     
     }
     
     double employeePay(double rate, double hours) //hourly employee gross pay. 2 parameters
     {   
         double weeklyPay;
         if( hours > 40)
         {
            double overTime = (hours - 40) * (rate * 1.5);
            weeklyPay = (rate * hours) + overTime; 
            return weeklyPay;     
         } else
          
          weeklyPay = (rate * hours);
         
      return weeklyPay;
     }
     
     
     double employeePay(double pay, int weeks) //contract employee gross pay. 2 parameters.
     {
       double weeklyPay = pay / weeks;
       return weeklyPay;
     }
     
     
     //**OVERLOADED FUNCTIONS Calculating Tax**
     
     double employeeTax(double taxedSalary) //Figures out tax rate for Salaried and Contract employees. 1 parameter.
     {
       double taxRate = .075;
       if(taxedSalary > 3000)
       {
         taxedSalary = taxedSalary * taxRate;
         return taxedSalary;
       } else
       
       do{
       cout << "What is your tax rate? ";
       cin  >> taxRate;
       }while(taxRate < 0);
       
       taxedSalary = taxedSalary * taxRate;
       return taxedSalary;
     }
     
     //Overloaded Function with 2 parameters
     double employeeTax(double taxedPay, double defaultTax) //Figures out tax rate for hourly employee.
     {
      double  taxRate = defaultTax; 
       int yesOrNo;
       do{
       cout << "Do you want to use the standard Tax Rate of 7.5%?"<< endl;
       cout << "Plese enter in '1' for yes or '2' to enter your own " << endl; 
       cin  >> yesOrNo;
       }while( yesOrNo != 1 && yesOrNo != 2);
       
       if (yesOrNo == 1)
       {
         taxedPay = taxedPay * taxRate;
         return taxedPay;
         
       } else 
       do{
       cout << "What is your tax rate? ";
       cin  >> taxRate;
       }while(taxRate < 0); 
       
       taxedPay = taxedPay * taxRate;
       return taxedPay;
     }