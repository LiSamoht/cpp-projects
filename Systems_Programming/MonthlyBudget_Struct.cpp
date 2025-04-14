/*
 Thomas Li
 Instructor: Sarkar S
 CS10B Spring 2024
 Assignment 7a [15 points] : Designing and implementing a C++ structure data type - Monthly Budget

The program consists of a budget management system that allows users to track their monthly expenses. It defines a MyBudget struct to store budget information
and several functions to interact with it. The main function initializes a budget and spent struct, prompts the user to input monthly expenditures, displays 
a comparison between budgeted and actual expenses for each category, and provides a summary of budget comparisons for a specified month.
*/
#include <iostream>
#include<iomanip>
#include<string>
using namespace std;

// Struct to store user Budget information
struct MyBudget {
    double Housing, Utilities, HouseholdExpenses, Transportation, Food, Medical, Insurance, Entertainment, Clothing, Miscellaneous;
};

//Struct MyBudget related functions: 
void displayMonthlyBudget(const MyBudget& budget);
void getMonthlyExpenses(MyBudget& spent, string& month);
void compareMonthlyExpenses(MyBudget& budget, MyBudget& spent, string month);

//input validations: 
void GetvalidMonth(string& input);
void GetValidSpending(double& input, string category);

int main() {
	MyBudget budget = { 580.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00 };
    MyBudget spent = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    string month;

    displayMonthlyBudget(budget);
    getMonthlyExpenses(spent, month);
    compareMonthlyExpenses(budget, spent, month);
    
    return 0;
}


/*
 The displayMonthlyBudget function takes a constant reference to a MyBudget struct as its parameter. It calculates the total budget by summing up the 
 expenses across all categories. Then, it iterates over each expense category, assigning the corresponding budget amount and category name to variables 
 budgetType and budgetTypeName, respectively. Using a switch-case statement, it formats and prints each category along with its budgeted amount. Finally, 
 it prints the total budget for the month of the year 2023. This function provides a clear and organized display of the monthly budget, breaking down 
 expenses by category and providing a total budget overview.
*/
void displayMonthlyBudget(const MyBudget& budget) {
    //Precondition: 'budget' must be a valid instance of the MyBudget struct, containing budget amounts for each expense category.
    //Postcondition: Displays the monthly budget for the year 2023, broken down by expense category, and calculates the total budget.
    const double TOTALBUDGET = budget.Housing + budget.Utilities + budget.HouseholdExpenses +
        budget.Transportation + budget.Food + budget.Medical + budget.Insurance + budget.Entertainment + budget.Clothing + budget.Miscellaneous;

    cout << "Here is your monthly budget for YEAR 2023:" << endl << endl;
    double budgetType;
    string budgetTypeName;

    for (int i = 0; i < 10; i++) {
        switch (i) {
        case 0:
            budgetType = budget.Housing;
            budgetTypeName = "Housing";
            break;
        case 1:
            budgetType = budget.Utilities;
            budgetTypeName = "Utilities";
            break;
        case 2:
            budgetType = budget.HouseholdExpenses;
            budgetTypeName = "Household";
            break;
        case 3:
            budgetType = budget.Transportation;
            budgetTypeName = "Transportation";
            break;
        case 4:
            budgetType = budget.Food;
            budgetTypeName = "Food";
            break;
        case 5:
            budgetType = budget.Medical;
            budgetTypeName = "Medical";
            break;
        case 6:
            budgetType = budget.Insurance;
            budgetTypeName = "Insurance";
            break;
        case 7:
            budgetType = budget.Entertainment;
            budgetTypeName = "Entertainment";
            break;
        case 8:
            budgetType = budget.Clothing;
            budgetTypeName = "Clothing";
            break;
        case 9:
            budgetType = budget.Miscellaneous;
            budgetTypeName = "Miscellaneous";
            break;
        default:
            break;
        }
        cout << setw(15) << left << budgetTypeName;
        cout << "$" << setw(5) << right << budgetType << endl;
    }

    cout << "=================================================" << endl;
    cout << setw(15) << left << "Total Budgeted" << "$" << setw(5) << right << TOTALBUDGET << endl;
    cout << "=================================================" << endl << endl;
}




/*
The function getMonthlyExpenses takes in a reference to a MyBudget struct named spent and a string reference month. It ensures the validity
of the input month using the GetvalidMonth function. Then, it prompts the user to enter actual monthly expenditures for each budget category.
Inside a loop, it iterates over each expense category, assigns the appropriate category name, and validates the user's input for the amount
spent using the GetValidSpending function. Finally, it updates the corresponding expense category in the spent struct with the validated input.
*/
void getMonthlyExpenses(MyBudget& spent, string& month) {
    // Precondition: proper reference to a MyBudget struct named spent and a string reference month. The MyBudget struct must be properly initialized.
    //Postcondition: The function updates the spent struct with the user-entered monthly expenditures for each budget category. The month parameter contains the valid name of the month entered by the user.
    GetvalidMonth(month);

    cout << "Enter actual monthly expenditures for each budget category " << endl << endl;
    double Toinput;
    string spentTypeName;
    for (int i = 0; i < 10; i++) {
        switch (i) {
        case 0:
            spentTypeName = "Housing";
            break;
        case 1:
            spentTypeName = "Utilities";
            break;
        case 2:
            spentTypeName = "Household";
            break;
        case 3:
            spentTypeName = "Transportation";
            break;
        case 4:
            spentTypeName = "Food";
            break;
        case 5:
            spentTypeName = "Medical";
            break;
        case 6:
            spentTypeName = "Insurance";
            break;
        case 7:
            spentTypeName = "Entertainment";
            break;
        case 8:
            spentTypeName = "Clothing";
            break;
        case 9:
            spentTypeName = "Miscellaneous";
            break;
        default:
            break;
        }

        GetValidSpending(Toinput, spentTypeName);
        switch (i) {
        case 0:
            spent.Housing = Toinput;
            break;
        case 1:
            spent.Utilities = Toinput;
            break;
        case 2:
            spent.HouseholdExpenses = Toinput;
            break;
        case 3:
            spent.Transportation = Toinput;
            break;
        case 4:
            spent.Food = Toinput;
            break;
        case 5:
            spent.Medical = Toinput;
            break;
        case 6:
            spent.Insurance = Toinput;
            break;
        case 7:
            spent.Entertainment = Toinput;
            break;
        case 8:
            spent.Clothing = Toinput;
            break;
        case 9:
            spent.Miscellaneous = Toinput;
            break;
        default:
            break;
        }
    }
}



/*
The function GetvalidMonth takes a string reference input and ensures that it contains a valid month name by prompting the user to enter it until a
valid month name is provided. It converts the input to lowercase to make the comparison case-insensitive and checks if it matches any of the valid 
month names. If the input is not valid, it prompts the user with an error message and repeats the process until a valid input is received.
*/
void GetvalidMonth(string& input) {
    //pre: string reference input is passed, clear input buffer
    //post: input contains valid month name
    bool valid;
    do {
        cout << "Enter the month of expenditure: ";
        getline(cin, input);
        string copyinput = input;
        valid = false;

        for (int i = 0; i < input.size(); i++) {
            copyinput.at(i) = tolower(input.at(i));
        }

        if (copyinput == "january" || copyinput == "february" || copyinput == "march" || copyinput == "april" ||
            copyinput == "may" || copyinput == "june" || copyinput == "july" || copyinput == "august" ||
            copyinput == "september" || copyinput == "october" || copyinput == "november" || copyinput == "december") {
            valid = true;
        }
        else {
            cout << "Invalid month." << endl;
        }
    } while (!valid);
}




/*
The function GetValidSpending ensures the validity of a user's input for a specified spending category. It prompts the user to input a value for the given
category and validates whether the input is a positive number. If the input is invalid (either not a number or negative), it displays an error message and
clears the input buffer before prompting the user again. The function continues this loop until a valid input is provided, ensuring that the user enters a 
positive number for the specified spending category.
*/
void GetValidSpending(double& input, string category) {
    //pre: double reference to input, string category defined
    //post: input contains a numerical positive value
    bool valid;
        do {
            cout << setw(15) << left << category << "$ ";
            if (!(cin >> input) || input < 0) {
                cout << "Error: You must enter a positive number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                valid = false;
            }
            else {
                valid = true;
            }
        } while (!valid);
}



/*
The function compareMonthlyExpenses generates a comparison between the budgeted amounts and the actual expenditures for various categories over a
specified month. It iterates through each budget category, printing the budgeted and spent amounts along with their differences. After computing the
total budget and total spent amounts, it displays the overall summary, including the total difference. Finally, it provides a message indicating whether
the user was under or over budget for the specified month, based on the total difference.
*/
void compareMonthlyExpenses(MyBudget& budget, MyBudget& spent, string month) {
    //pre: budget and spent contain valid data, month is a valid month
    //post: total budget, spent, and difference table calculated and displayed, as well as 
    //summary of budget comparisons and a message indicating the user's budget status.
    cout << setw(25) << right << "Budgeted" << setw(10) << right << "Spent" << setw(16) << right << "Difference" << endl;
    cout << "=================================================" << endl;

    string TypeName;
    double budgetType;
    double spentType;

    for (int i = 0; i < 10; i++) {
        switch (i) {
        case 0:
            TypeName = "Housing";
            spentType = spent.Housing;
            budgetType = budget.Housing;
            break;
        case 1:
            TypeName = "Utilities";
            spentType = spent.Utilities;
            budgetType = budget.Utilities;
            break;
        case 2:
            TypeName = "Household";
            spentType = spent.HouseholdExpenses;
            budgetType = budget.HouseholdExpenses;
            break;
        case 3:
            TypeName = "Transportation";
            spentType = spent.Transportation;
            budgetType = budget.Transportation;
            break;
        case 4:
            TypeName = "Food";
            spentType = spent.Food;
            budgetType = budget.Food;
            break;
        case 5:
            TypeName = "Medical";
            spentType = spent.Medical;
            budgetType = budget.Medical;
            break;
        case 6:
            TypeName = "Insurance";
            spentType = spent.Insurance;
            budgetType = budget.Insurance;
            break;
        case 7:
            TypeName = "Entertainment";
            spentType = spent.Entertainment;
            budgetType = budget.Entertainment;
            break;
        case 8:
            TypeName = "Clothing";
            spentType = spent.Clothing;
            budgetType = budget.Clothing;
            break;
        case 9:
            TypeName = "Miscellaneous";
            spentType = spent.Miscellaneous;
            budgetType = budget.Miscellaneous;
            break;
        default:
            break;
        }
        cout << setw(18) << left << TypeName << setw(6) << right << fixed << setprecision(2) << budgetType;
        cout << setw(12) << right << fixed << setprecision(2) << spentType;
        cout << setw(12) << right << fixed << setprecision(2) << spentType - budgetType << endl;
    }

    double totalBudget = budget.Housing + budget.Utilities + budget.HouseholdExpenses +
        budget.Transportation + budget.Food + budget.Medical + budget.Insurance + budget.Entertainment + budget.Clothing + budget.Miscellaneous;
    double totalSpent = spent.Housing + spent.Utilities + spent.HouseholdExpenses +
        spent.Transportation + spent.Food + spent.Medical + spent.Insurance + spent.Entertainment + spent.Clothing + spent.Miscellaneous;
    double totalDiff = totalBudget - totalSpent;
    cout << "=================================================" << endl;
    cout << setw(15) << left << "Total" << setw(7) << right << fixed << setprecision(2) << totalBudget << setw(12) << totalSpent
        << setw(12) << totalDiff << endl;
    cout << "=================================================" << endl << endl;
    
    if (totalDiff >= 0)
        cout << "Congratulations! You were $" << fixed << setprecision(2) << totalDiff << " under budget in " << month << " 2023" << endl;
    else
        cout << "Oops! You were $" << fixed << setprecision(2) << totalDiff * -1 << " above budget in " << month << " 2023" << endl;
}

