#include <stdio.h>
#include <string.h>

int main()
{
    // Doctor Variables
    int choice, choice_d, fee;
    char name[100];
    char spec[100];
    char contact[20];

    FILE *fp;   

    // Enter choice

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 2)
    {
        // DOctor Menu
        printf("\n--- Doctor Menu ---\n");
        printf("1. Add Doctor\n");
        printf("2. List Doctor\n");
        printf("3. Back\n");
        printf("Enter Choice: ");
        scanf("%d", &choice_d);

        if (choice_d == 1)
        {
            // Add doctor Info



            getchar();

            printf("Enter Name: ");
            fgets(name, sizeof(name), stdin);

            printf("Specialization: ");
            fgets(spec, sizeof(spec), stdin);

            printf("Fee: ");
            scanf("%d", &fee);

            printf("Contact: ");
            scanf("%s", contact);


            // doctor.txt file creation

            fp = fopen("doctor.txt", "a");

            if (fp == NULL)
            {
                printf("File open error\n");
                return 1;
            }

            fprintf(fp, "Name: %s", name);
            fprintf(fp, "Specialization: %s", spec);
            fprintf(fp, "Fee: %d\n", fee);
            fprintf(fp, "Contact: %s\n", contact);
            fprintf(fp, "--------------------------\n");

            fclose(fp);

            printf("\nDoctor Added Successfully\n");
        }

        else if(choice_d==2)
        {


            // Print all Doctors

            
                char line[200];

            fp = fopen("doctor.txt", "r");

             if (fp == NULL)
            {
             printf("No doctor records found ❌\n");
             return 1;
             }

            printf("\n--- Doctor List ---\n");

            while (fgets(line, sizeof(line), fp) != NULL)
            {
                printf("%s", line);
            }

            fclose(fp);
                }
    }

    return 0;
}
