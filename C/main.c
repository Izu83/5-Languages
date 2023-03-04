#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main()
{
    while(true)
    {
        START:
        printf("1. Register\n2. Login\n");
        char option[100];

        scanf("%s", option);
        system("cls");

        if(option[0] == '1')
        {
            printf("Enter the username of your account: ");
            char username[300];
            scanf("%s", username);

            // check if the file exists
            char file_path[304] = "assets/";
            strcat(file_path, username);
            strcat(file_path, ".txt");

            FILE *temp_file;
            temp_file = fopen(file_path, "r");

            if(temp_file != NULL)
            {
                printf("---\n!-- This kind of a account already exists! --!\n---\n");
                goto START;
            }
            fclose(temp_file);
            // want a password
            char password[300];
            printf("Enter password: ");
            scanf("%s", password);

            FILE *file;
            file = fopen(file_path, "w");
            if(file == NULL)
            {
                printf("---\n!-- Failed to open file! --!\n--\n");
                goto START;
            }

            fprintf(file, "%s %s", username, password);

            fclose(file);

        }
        else if(option[0] == '2')
        {
            printf("Enter username: ");
            char username[300];
            scanf("%s", username);

            char file_path[304] = "assets/";
            strcat(file_path, username);
            strcat(file_path, ".txt");

            FILE *file;
            file = fopen(file_path ,"r");
            if(file == NULL)
            {
                printf("---\n!-- There is no user named %s --!\n---\n", username);
                goto START;
            }
            
            char user[300];
            
            fscanf(file, "%s", user);

            printf("Enter password: ");
            char password[300];
            scanf("%s", password);

            char a_password[300];
            fscanf(file, "%s", a_password);

            if(strcmp(password, a_password) == 0)
            {
                printf("Hi, welcome to our program!\n");
                exit(0);
            }
            else
            {
                printf("---\n!-- Not the right password! --!\n---\n");
            }

            fclose(file);            
        }
        else
        {
            printf("Not a option!\n");
        }
    }
    
}