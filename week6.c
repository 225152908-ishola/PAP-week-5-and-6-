#include <stdio.h>
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS 10
#define NUM_VEHICLES 20

int main(void)
{
    float salaries[NUM_SALARIES];
    float totalSalaries = 0, averageSalary, highestSalary, lowestSalary;
    float searchSalary;
    int foundSalary = 0;

    printf("=== PART A: EMPLOYEE SALARIES ===\n");
    for (int i = 0; i < NUM_SALARIES; i++) 
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
        
        totalSalaries += salaries[i];
        
        if (i == 0) 
        {
            highestSalary = lowestSalary = salaries[i];
        }
        if (salaries[i] > highestSalary) highestSalary = salaries[i];
        if (salaries[i] < lowestSalary) lowestSalary = salaries[i];
    }

    averageSalary = totalSalaries / NUM_SALARIES;
    printf("\nAverage Salary: %.2f\n", averageSalary);
    printf("Highest Salary: %.2f\n", highestSalary);
    printf("Lowest Salary: %.2f\n", lowestSalary);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);
    for (int i = 0; i < NUM_SALARIES; i++) 
    {
        if (salaries[i] == searchSalary) 
        {
            printf("Salary found at position %d\n", i + 1);
            foundSalary = 1;
            break;
        }
    }
    if (!foundSalary) printf("Salary not found.\n");


    float budgets[NUM_BUDGETS];
    float totalBudget = 0, averageBudget;
    float temp;

    printf("\n=== PART B: DEPARTMENT BUDGETS ===\n");
    for (int i = 0; i < NUM_BUDGETS; i++) 
    {
        printf("Enter budget %d: ", i + 1);
        scanf("%f", &budgets[i]);
        totalBudget += budgets[i];
    }
    
    averageBudget = totalBudget / NUM_BUDGETS;
    printf("\nTotal Budget: %.2f\n", totalBudget);
    printf("Average Budget: %.2f\n", averageBudget);

    for (int i = 0; i < NUM_BUDGETS - 1; i++) 
    {
        for (int j = 0; j < NUM_BUDGETS - i - 1; j++) 
        {
            if (budgets[j] > budgets[j + 1]) 
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("Sorted Budgets (Lowest to Highest):\n");
    for (int i = 0; i < NUM_BUDGETS; i++) 
    {
        printf("%.2f\n", budgets[i]);
    }

    char registrations[NUM_VEHICLES][20];
    char searchReg[20];
    int foundReg = 0;

    printf("\n=== PART C: VEHICLE REGISTRATIONS ===\n");
    for (int i = 0; i < NUM_VEHICLES; i++) 
    {
        printf("Enter registration for vehicle %d: ", i + 1);
        scanf("%19s", registrations[i]); 
    }

    printf("\nEnter a registration to search for: ");
    scanf("%19s", searchReg);

    for (int i = 0; i < NUM_VEHICLES; i++) 
    {
        if (strcmp(registrations[i], searchReg) == 0) 
        {
            printf("Registration '%s' found at position %d\n", searchReg, i + 1);
            foundReg = 1;
            break;
        }
    }
    if (!foundReg) printf("Registration not found.\n");

    return 0;
}
