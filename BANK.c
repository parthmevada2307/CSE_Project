#include<stdio.h>
#include<string.h>
#include<stdlib.h>



struct detail{
    char phoneNumber[12];
    char accountNumber[16];
    char password[30];
    float balance;
}user,user2;

int main()
{
    int opt,choice,ChooseForReceipt;
    float amount;
    FILE *ptr;
    char filename[50],Phone_number[10],password[30];
    char cont = 'y';
    printf("|==================================================|\n");
    printf("|       ******* WELCOME TO UCO BANK *******        |\n");
    printf("|==================================================|\n");
    printf("|                                                  |\n");
    printf("|  Date : %s     \t",__DATE__);
    printf("  Time : %s  |\n",__TIME__);
    printf("|--------------------------------------------------|\n");
    printf("|                                                  |\n");
    printf("|   [1]. Register an account                       |\n");
    printf("|   [2]. Login to an account                       |\n");
    printf("|--------------------------------------------------|\n");
    printf("|     Press [1] For Registration!                  |\n");
    printf("|     Press [2] For Login!                         |\n");
    printf("|==================================================|\n");

    printf("\n\n");
    printf("|***************************|\n");
    printf("|  Enter your choice:  ");
    scanf("%d",&opt);
    if(opt==1){
        label2:
        system("clear");
        printf("|==================================================|\n");
        printf("|         ******* REGISTRATION FORM *******        |\n");
        printf("|==================================================|\n");
        printf("|                                                  |\n");
        printf("   Enter your Account Number: ");
        scanf("%s",&user.accountNumber);
        printf("   Enter your Phone Number  : ");
        scanf("%s",&user.phoneNumber);
        printf("   Enter a new Password     : ");
        scanf("%s",&user.password);
        user.balance = 0;
        strcpy(filename,user.phoneNumber);
        ptr = fopen(strcat(filename,".dat"),"w");
        fwrite(&user,sizeof(struct detail),1,ptr);
        if(fwrite !=0 ){
            printf("\n\n Account Sucessfully Registered.\n");
        }
        else{
            printf("\n\n Something went wrong please try again.......\n");
        }
        fclose(ptr);
        getchar();
        printf("Do you want to login your account....? [y/n]:\t");
        scanf("%c",&cont);
        if(cont=='y'){
            goto label;
        }
    }
    else if(opt==2){
        label:
        system("clear");
        label1:
        printf("|==================================================|\n");
        printf("|           ******* LOGIN DETAILS *******          |\n");
        printf("|==================================================|\n");
        printf("|                                                  |\n");
        printf("\n   Enter your Phone Number:  ");
        scanf("%s",&Phone_number);
        strcpy(filename,Phone_number);
        ptr = fopen(strcat(filename,".dat"),"r");
        printf("\n   Enter your Password    :  ");
        scanf("%s",&password);

        if(ptr==NULL){
            printf("\n\tAccount number not Registered\n\n");
            getchar();
            printf("Do you want to Register an account......?[y/n]:\t");
            scanf("%c",&cont);
            if(cont=='y'){
                goto label2;
            }
        }
        else{
        fread(&user,sizeof(struct detail),1,ptr);
        fclose(ptr);
        if((strcmp(password,user.password))==0){
            system("clear");
            printf("|============================================|\n");
            printf("|************* Welcome %s ***********|\n",user.phoneNumber);
            printf("|============================================|\n");
            while (cont=='y')
            {
                printf("|                                            |\n");
                printf("|  Press [1] For Balance Inquiry             |\n");
                printf("|  Press [2] For Depositing Cash             |\n");
                printf("|  Press [3] For Cash Withdrawl              |\n");
                printf("|  Press [4] For Online Transaction          |\n");
                printf("|  Press [5] For Password Change             |\n");
                printf("|                                            |\n");
                printf("|--------------------------------------------|\n");
                printf("|\tYour choice:\t");
                scanf("%d",&choice);
                printf("\n");
                switch (choice)
                {
                case 1:
                    system("clear");
                    printf("|============================================|\n");
                    printf("|************* Welcome %s ***********|\n",user.phoneNumber);
                    printf("|============================================|\n");
                    printf("|                                            |\n");
                    strcpy(filename,user.phoneNumber);
                    ptr = fopen(strcat(filename,".dat"),"r");
                    fread(&user2,sizeof(struct detail),1,ptr);
                    printf("    YOUR ACCOUNT NUMBER   : %s   \n\n",user.accountNumber);
                    fclose(ptr);
                    printf("    YOUR CURRENT BALANCE  : Rs. %.2f   \n",user.balance);
                    break;
                case 2:
                    system("clear");
                    printf("|=====================================================|\n");
                    printf("|***************** Welcome %s ****************|\n",user.phoneNumber);
                    printf("|=====================================================|\n");
                    printf("|                                                     |\n\n");
                    printf("    Enter the amount you want to deposit:  ");
                    scanf("%f",&amount);
                    user.balance+=amount;
                    ptr = fopen(filename,"w");
                    fwrite(&user,sizeof(struct detail),1,ptr); 
                    if(fwrite != 0){
                    printf("\n\t       Succesfully deposited.\n");
                    }
                    fclose(ptr);
                    printf("\n Do you want receipt ?.....\t Press [1] for Yes or [0] for No :  ");
                    scanf("%d",&ChooseForReceipt);
                            if(ChooseForReceipt==1){
                                system("clear");
                                printf("\n\n");
                                printf("||============================================================================||\n");
                                printf("||\t\t     ********** WElCOME TO UCO BANK **********                ||\n");
                                printf("||============================================================================||\n");
                                printf("||  Date : %s\t\t\t|\t",__DATE__);
                                printf(" Time : %s              ||\n",__TIME__);
                                printf("||----------------------------------------------------------------------------||\n");
                                strcpy(filename,user.phoneNumber);
                                ptr = fopen(strcat(filename,".dat"),"r");
                                fread(&user2,sizeof(struct detail),1,ptr);
                                printf("||  ACCOUNT NUMBER   : %s                                         ||\n",user.accountNumber);
                                fclose(ptr);
                                
                                printf("||  Deposited Amount : Rs. %.2f                                           ||\n",amount);
                                printf("||  TXN STATUS       : SUCCESSFULLY DEPOSITED                                 ||\n");
                                printf("||----------------------------------------------------------------------------||\n");
                                printf("||  FACING ISSUE RELATED TO THE MONEY DEPOSITION YOU CAN                      ||\n||  CONTACT US BY GIVING MISSED CALL FROM YOUR REGISTRATED MOBILE NUMBER ONLY ||\n");
                                printf("||----------------------------------------------------------------------------||\n");
                                printf("||  \t\t\t    THANK YOU FOR BANKING US                          || \n");
                                printf("||  \t\t\t      PLEASE VISIT AGAIN                              ||\n||   \t\t\t!!!!!!! HAVE A GOOD DAY !!!!!!!                       ||\n");
                                printf("||============================================================================||\n\n\n");
                            }
                    break;
                case 3:
                    system("clear");
                    printf("|=========================================================|\n");
                    printf("|******************* Welcome %s ******************|\n",user.phoneNumber);
                    printf("|=========================================================|\n");
                    printf("|                                                         |\n\n");
                    printf("      Enter the amount you want to withdrawl:\t");
                    scanf("%f",&amount);
                    user.balance-=amount;
                    ptr = fopen(filename,"w");
                    fwrite(&user,sizeof(struct detail),1,ptr); 
                    if(fwrite != 0){
                    printf("\n        Your have withdrawn Rs.%.2f\n",amount);
                    }
                    fclose(ptr);
                    break;
                case 4:
                    system("clear");
                    printf("\n\n");
                    printf("||============================================================================||\n");
                    printf("||*-*-*-*-*-*-*-*-*-*-*-*-*-*-* WElCOME TO UCO BANK *-*-*-*-*-*-*-*-*-*-*-*-* ||\n");
                    printf("||============================================================================||\n");
                    printf("|                                                                              |\n");
                    printf("\tEnter the phone number to transfer the money : ");
                    scanf("%s",&Phone_number);
                    strcpy(filename,Phone_number);
                    printf("\n");
                    printf("\tEnter the amount of money to be transfer: ");
                    scanf("%f",&amount);
                    ptr = fopen(strcat(filename,".dat"),"r"); 
                        if(ptr==NULL){
                            printf("\n Phone number is not registered.\n");
                            return 0;
                        }
                        else{
                           fread(&user2,sizeof(struct detail),1,ptr);
                           fclose(ptr); 
                        }

                    if(amount>user.balance){
                        printf("\n!!!!  Insufficient Balance  !!!!\n\n");
                    }
                    else{
                        user2.balance += amount;
                        ptr = fopen(filename,"w");
                        fwrite(&user2,sizeof(struct detail),1,ptr);
                        if(fwrite != 0){
                            printf("\n You have successfully tranfered Rs %.2f to %s\n\n",amount,Phone_number);
                            strcpy(filename,user.phoneNumber);
                            ptr = fopen(strcat(filename,".dat"),"w");
                            user.balance -=  amount;
                            fwrite(&user,sizeof(struct detail),1,ptr);
                            fclose(ptr);
                            printf("\n Do you want receipt ?.....\t Press [1] for Yes or [0] for No :  ");
                            scanf("%d",&ChooseForReceipt);
                            if(ChooseForReceipt==1){
                                system("clear");
                                printf("\n\n");
                                printf("||============================================================================||\n");
                                printf("||-*-*-*-*-*-*-*-*-*-*-*-*-*-* WElCOME TO UCO BANK *-*-*-*-*-*-*-*-*-*-*-*-*-*||\n");
                                printf("||============================================================================||\n");
                                printf("||  Date : %s\t\t\t|\t",__DATE__);
                                printf(" Time : %s              ||\n",__TIME__);
                                printf("||----------------------------------------------------------------------------||\n");
                                strcpy(filename,user.phoneNumber);
                                ptr = fopen(strcat(filename,".dat"),"r");
                                printf("||  From : %s                                                     ||\n",user.accountNumber);
                                fclose(ptr);
                                strcpy(filename,Phone_number);
                                ptr = fopen(strcat(filename,".dat"),"r");
                                fread(&user2,sizeof(struct detail),1,ptr);
                                printf("||  TO   : %s                                                     ||\n",user2.accountNumber);
                                fclose(ptr);
                                
                                printf("||  Deposited Amount : Rs. %.2f                                           ||\n",amount);
                                printf("||  TXN STATUS       : TRANSACTION COMPLETED                                  ||\n");
                                printf("||----------------------------------------------------------------------------||\n");
                                printf("||  FACING ISSUE RELATED TO THE MONEY TRANSFORMATION YOU CAN                  ||\n||  CONTACT US BY GIVING MISSED CALL FROM YOUR REGISTRATED MOBILE NUMBER ONLY ||\n");
                                printf("||----------------------------------------------------------------------------||\n");
                                printf("||  \t\t\t    THANK YOU FOR BANKING US                          || \n");
                                printf("||  \t\t\t      PLEASE VISIT AGAIN                              ||\n||   \t\t\t!!!!!!! HAVE A GOOD DAY !!!!!!!                       ||\n");
                                printf("||============================================================================||\n\n\n");
                            }
                        }
                    }
                    
                    break;
                case 5: 
                    system("clear");
                    printf("\n\n");
                    printf("||============================================================================||\n");
                    printf("||-*-*-*-*-*-*-*-*-*-*-*-*-*-* WElCOME TO UCO BANK *-*-*-*-*-*-*-*-*-*-*-*-*-*||\n");
                    printf("||============================================================================||\n");
                    printf("|                                                                              |\n");
                    printf("\tEnter your new password : ");
                    scanf("%s",&password);
                    ptr  = fopen(filename,"w");
                    strcpy(user.password,password);
                    fwrite(&user,sizeof(struct detail),1,ptr);
                    if(fwrite!=0){
                    printf("\n\tPassword Successfully Changed......\n");
                    }
                break;
                
                default:
                    printf("\nInvalid option!!!!!\n");
                    break;
                }
                printf("\n\n");
                printf("Do you want to continue the transaction ?....... [y/n] : ");
                scanf("%s",&cont);
                system("clear");
                printf("\n");
            }
            
        }
        else{
            system("clear");

            printf("\n\t Invalid Password!!!!!!!\n\n\n");
            goto label1;
        }
        }

    }
    else{
        printf("Press valid number!!!\n");
    }
    
    return 0;
}


