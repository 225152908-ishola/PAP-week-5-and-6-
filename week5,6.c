#include <stdio.h>

#define NUM_EMPLOYEES 50

int main(void)
{
    float salaries[NUM_EMPLOYEES];
    float total = 0, average, highest, lowest, temp;
    float searchSalary;
    int found = 0;

    printf("--- INTEGRATED CHALLENGE ---\n");
    printf("--- Employee Salary Management System ---\n\n");

    for (int i = 0; i < NUM_EMPLOYEES; i++) 
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        
        total += salaries[i];

        if (i == 0) 
        {
            highest = lowest = salaries[i];
        }
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest) lowest = salaries[i];
    }

    average = total / NUM_EMPLOYEES;

    printf("\n--- All Employee Salaries ---\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++) 
    {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    printf("\nTotal Salary Expenditure: %.2f\n", total);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);
    
    for (int i = 0; i < NUM_EMPLOYEES; i++) 
    {
        if (salaries[i] == searchSalary) 
        {
            printf("Salary %.2f found at employee position %d\n", searchSalary, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) 
    {
        printf("Salary not found in the system.\n");
    }

    for (int i = 0; i < NUM_EMPLOYEES - 1; i++) 
    {
        for (int j = 0; j < NUM_EMPLOYEES - i - 1; j++) 
        {
            if (salaries[j] > salaries[j + 1]) 
            {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    printf("\n--- Salaries Sorted (Lowest to Highest) ---\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++) 
    {
        printf("%.2f\n", salaries[i]);
    }

    return 0;
}