#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAX_SEATS 15

int login_details();
int user_details();
int my_profile();
int load_user_balance();
int train_tik_book(),view_trains();
int bus_tik_book();
int search_bus(),view_bus();
int tamil_movie_book(),holly_movie_book();
int view_tamil_movie(),view_holly_movie();
int Events_sports_book();
int search_isl(),view_isl();
int admin();
int admin_seat_num();
int admin_train(),delete_train();
int admin_bus(),delete_bus();
int admin_tamil_movie(),admin_holly_movie();
int admin_sports_event(),admin_isl();
char u_name[20],u_pwd[20];
int retval;

struct travel
{
    char tp_name[20],depart_time[10],arrive_time[10],depart_place[20],arrive_place[20];
    char tp_tm_dur[15];
    int tp_no,tp_av_tic,tp_fare,seat_numbers;
};
struct movie
{
    char mov_name[20],mov_time[10],mov_date[10],mov_theater[20];
    int mov_t_fare,mov_av_tic,seat_numbers;
};
struct sports
{
    char team1[20],team2[20],venue[20],date[20],time[10];
    int t_fare,av_tic,seat_numbers;
};

void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor+bgColor*16);
}

int main()
{                                                                                                         //Main function
    int ch,u,n,m;

    loop:
        system("cls");
        setColor(12,15);
        printf("\n\n\n\n\t\t\t\t**=========Bookiteazy========**\n");
        setColor(15, 0);
        printf("\n\n\t\t\t\t\t1 .LOGIN");
        printf("\n\t\t\t\t\t2. Create account");
        printf("\n\t\t\t\t\t3. Admin login");
        printf("\n\t\t\t\t_____________________________");
        setColor(14,0);
        printf("\n\t\t\t\tEnter the choice :");
        setColor(15,0);
        scanf("%d", &u);

        switch(u){
            case 1:
                retval=login_details(u);
                if(retval==2){
                    goto hloop;
                }else if(retval==1){
                    goto loop;
                }
                break;
            case 2:
                retval=login_details(u);
                if(retval==2){
                    goto loop;
                }
                break;
            case 3:
                retval=login_details(u);
                if(retval==1){
                    retval=admin();
                    if(retval==1){
                        goto loop;
                    }
                }else if(retval==2){
                    goto loop;
                }
            default:
            printf("\n\t\t\t\tPlease Enter valid input...");
            getch();
            goto loop;
        }

        hloop:
        system("cls");
        setColor(9,15);
        printf("\n\t\t\t**=======Bookiteazy=======**\n");
        setColor(15,0);
        printf("\n\t\t\t\t1. Travel                     11. My profile");
        printf("\n\t\t\t\t2. Movies");
        printf("\n\t\t\t\t3. Service");
        printf("\n\t\t\t\t4. Event");
        printf("\n\t\t\t\t5. Touristy");
        printf("\n\t\t\t\t6. Logout");
        printf("\n\t\t\t___________________________");
        setColor(14,0);
        printf("\n\t\t\tEnter the choice :");
        setColor(15,0);
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                tloop:
                system("cls");setColor(9,15);
                printf("\n\t\t\t**=======Travel=======**\n");setColor(15,0);                                   //Travel page
                printf("\n\n\t\t\t1.Train Ticket");
                printf("\n\t\t\t2.Bus Ticket");
                printf("\n\t\t\t3.Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                switch (n){
                    case 1:
                        system("cls");
                        retval=train_tik_book();
                        if(retval==1){
                        goto tloop;
                        }
                        break;
                    case 2:
                        system("cls");
                        retval=bus_tik_book();
                        if(retval==1){
                            goto tloop;
                        }
                        break;
                    case 3:
                        goto hloop;
                        break;
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPlease Enter a valid input...");setColor(15,0);
                        getch();
                        goto tloop;
                }
            case 2:
                mloop:
                system("cls");setColor(9,15);
                printf("\n\t\t\t**=======Movies=======**\n"); setColor(15,0);                                                 //Movie page
                printf("\n\t\t\t1. Tamil Movies");
                printf("\n\t\t\t2. Hindi Movies");
                printf("\n\t\t\t3. Hollywood Movies");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);

                if(n==4){
                    goto hloop;
                }
                switch(n){
                    case 1:
                        retval=tamil_movie_book();
                        if(retval==1){
                            goto mloop;
                        }
                    case 3:
                        retval=holly_movie_book();
                        if(retval==1){
                            goto mloop;
                        }
                        break;
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPleasse Enter a valid input....");setColor(15,0);
                        getch();
                        goto mloop;
                }
                break;
            case 3:
                sloop:
                system("cls");setColor(9,15);
                printf("\n\t\t\t**=======Services=======**\n");setColor(15,0);                                                 //Services page
                printf("\n\t\t\t1.");
                printf("\n\t\t\t2.");
                printf("\n\t\t\t3.");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                if(n==4){
                    goto hloop;
                }else if(n==1 || n==2 || n==3){
                    printf("\n\t\t\tNo Information added....");
                    getch();
                    goto sloop;
                }
                switch(n){
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPleasse Enter a valid input....");setColor(15,0);
                        getch();
                        goto sloop;
                }
                break;
            case 4:
                eloop:
                system("cls");setColor(9,15);
                printf("\n\t\t\t**=======Events=======**\n");setColor(15,0);
                printf("\n\n\t\t\t\t1. Marathon");
                printf("\n\t\t\t\t2. Sports");
                printf("\n\t\t\t\t3. Concerts");
                printf("\n\t\t\t\t4.Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d",&n);

                if(n==4){
                    goto hloop;
                }
                switch(n){
                    case 2:
                        system("cls");
                        retval=Events_sports_book();
                        if(retval==1){
                            goto eloop;
                        }
                        break;
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPleasse Enter a valid input....");setColor(15,0);
                        getch();
                        goto eloop;
                }
                break;
            case 5:
                tyloop:
                system("cls");setColor(9,15);
                printf("\n\t\t\t**=======Touristry=======**\n");setColor(15,0);                                                //Touristry page
                printf("\n\t\t\t1.");
                printf("\n\t\t\t2.");
                printf("\n\t\t\t3.");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                if(n==4){
                    goto hloop;
                }else if(n==1 || n==2 || n==3){
                    printf("\n\t\t\tNo Information added....");
                    getch();
                    goto tyloop;
                }
                switch(n){
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPleasse Enter a valid input....");setColor(15,0);
                        getch();
                        goto tyloop;
                }
                break;
            case 6:
                system("cls");
                printf("\n\n\t\t\tAre sure want to logout....");
                printf("\n\t\t\t1. Yes");
                printf("\n\t\t\t2. No");
                printf("\n\t\t______________________________");
                printf("\n\n\t\t\tEnter the choice   :");
                scanf("%d",&n);
                if(n==1){
                    setColor(2,0);
                    printf("\n\n\n\n\n\t\t\tLogout successfull....");setColor(15,0);
                    getch();
                    goto loop;
                }else{
                    goto hloop;
                }
                break;
            case 11:
                retval= my_profile();
                if(retval==1){
                    goto hloop;
                }
                break;
            default:
                setColor(4,0);
                printf("\n\t\t\tPlease Enter valid Input....");setColor(15,0);
                getch();
                goto hloop;
        }


    getch();
    return 0;
}

int login_details(int n) {
    FILE *fp;
    char i_username[20], i_password[20], username[20], password[20],pwd[10];
    int m,found=0,u_balance=0;
    switch (n) {
    case 1:
        fp = fopen("user.txt", "r");

        loop:
        system("cls");
        setColor(12,15);
        printf("\n\t\t\t**=======LOGIN=======**");
        setColor(15,0);
        printf("\n\n\n\n\n\t\t\t1. Back");
        printf("\n\n\t\t\tEnter the user name  : ");
        scanf("%s", i_username);

        if (strcmp(i_username, "1") == 0) {
            fclose(fp);
            return 1;
        } else {
            printf("\n\t\t\tEnter the Password   : ");
            scanf("%s", i_password);
        }

        while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
             fscanf(fp, "Balance   : %d",&u_balance);
             fscanf(fp, "\n______________________________\n");

            if (strcmp(username, i_username) == 0 && strcmp(password, i_password) == 0) {
                found=1;
                strcpy(u_name,username);
                strcpy(u_pwd,password);
                setColor(2,0);
                printf("\n\n\n\t\t\tLogin Successful........");
                fclose(fp);
                getch();
                setColor(15,0);
                return 2;
            }
        }

        if(found==0){
            setColor(4,0);
            printf("\n\n\t\t\tIncorrect Password or Username....");
            rewind(fp);
            getch();
            setColor(15,0);
            goto loop;
        }
        break;

    case 2:
        system("cls");
        fp = fopen("user.txt", "a");

        printf("\n\t\t\tCreate account...\n");
        printf("\n\t\t\tEnter the user name  : ");
        scanf("%19s", username);
        printf("\n\t\t\tEnter the Password   : ");
        scanf("%19s", password);

        fprintf(fp, "\n username  : %s\n password  : %s", username, password);
        fprintf(fp, "\n Balance   : %d",u_balance);
        fprintf(fp, "\n______________________________");

        setColor(2,0);
        printf("\n\n\t\t\tAccount created successfully....");
        getch();
        fclose(fp);
        setColor(15,0);
        return 2;
    case 3:
        aloop:
        system("cls");
        strcpy(pwd,"asd");
        printf("\n\n\n\n\t\t\t**======Admin login======**\n");
        printf("\n\t\t\tEnter the password  :");
        scanf("%s",i_password);

        if(strcmp(i_password,pwd)==0){
            setColor(2,0);
            printf("\n\t\t\tLogin successfull...");
            getch();
            setColor(15,0);
            return 1;
        }else{
            setColor(4,0);
            printf("\n\n\t\t\tIncorrect password...");
            setColor(15,0);
            printf("\n\n\t\t\t1. Retry");
            printf("\n\t\t\t2. Back");
            printf("\n\t\t_________________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&m);

            if(m==1){
                goto aloop;
            }else if(m==2){
                return 2;
            }
        }
    default:
        printf("\n\t\t\tPlease Enter valid input...");
        getch();
        break;
    }

    return 0;
}

int user_details()
{
    int n,m,c,found=0,u_balance,num=0;
    char i_uname[10],username[10],password[10];
    FILE *fp,*temp;

    loop:
    system("cls");
    printf("\n\t\t\t**=======User details=======**\n");
    printf("\n\t\t\t1. User info");
    printf("\n\t\t\t2. Delete users");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t_________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    if(n==3){
        return 1;
    }

    switch(n){
        case 1:
            fp = fopen("user.txt", "r");
            if(fp==NULL){
                printf("\n\t\t\terror openning the file");
                getch();
                goto loop;
            }
            system("cls");
            printf("\n\t\t\t**=======User Info=======**\n");
            while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                fscanf(fp, "Balance   : %d",&u_balance);
                fscanf(fp, "\n______________________________\n");


                printf("\n\t\t\tUsername     : %s",username);
                printf("\n\t\t\tPassword     : %s",password);
                printf("\n\t\t\tBalance      : %d",u_balance);
                printf("\n\t\t___________________________________________");
            }
            printf("\n\t\tpress Enter to go back.......");
            getch();
            fclose(fp);
            goto loop;
            break;
        case 2:
            loop1:
            fp = fopen("user.txt", "r");
            temp = fopen("temp.txt", "w");
            if(fp==NULL || temp==NULL){
                printf("\n\t\t\terror openning the file");
                getch();
                goto loop;
            }
            system("cls");
            printf("\n\t\t\t**=======Delete User Info=======**\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter the username    :");
            scanf("%s",i_uname);

            if(strcmp(i_uname,"1")==0){
                fclose(fp);
                fclose(temp);
                goto loop;
            }
             while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                fscanf(fp, "Balance   : %d",&u_balance);
                fscanf(fp, "\n______________________________\n");

                num++;
                if(strcmp(username,i_uname)==0){
                    found=1;
                    system("cls");
                    printf("\n\t\t\t**=======Delete User Info=======**\n");
                    printf("\n\t\t%d.      Username     : %s",num,username);
                    printf("\n\t\t\tPassword     : %s",password);
                    printf("\n\t\t\tBalance      : %d",u_balance);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tAre you sure want to delete this info......");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\n\t\t\t3. Next");
                    printf("\n\t\t___________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==1){
                        printf("\n\t\t\tUser info deleted successfully...");
                        strcpy(i_uname,"dummy");
                        getch();
                    }else if(m==2){
                        fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                        fprintf(temp, "Balance   : %d",u_balance);
                        fprintf(temp, "\n______________________________\n");
                        strcpy(i_uname,"dummy");
                    }else if(m==3){
                        found=3;
                        fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                        fprintf(temp, "Balance   : %d",u_balance);
                        fprintf(temp, "\n______________________________\n");
                    }else {
                        fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                        fprintf(temp, "Balance   : %d",u_balance);
                        fprintf(temp, "\n______________________________\n");
                    }
                }else{
                    fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                    fprintf(temp, "Balance   : %d",u_balance);
                    fprintf(temp, "\n______________________________\n");
                }
            }
            if(found==0){
                num=0;
                printf("\n\t\t\tNo details available as %s : i_uname");
                getch();
            }else if(found==3){
                num=0;
                printf("\n\t\t\tNO Users Found Next....");
                printf("\n\t\t\t1. Search again");
                printf("\n\t\t\t2. Back");
                printf("\n\t\t____________________________");
                printf("\n\t\t\tEnter the choice   :");
                scanf("%d",&c);

                if(c==1){
                    fclose(fp);
                    fclose(temp);
                    remove("user.txt");
                    rename("temp.txt","user.txt");
                    goto loop1;
                }
            }
            num=0;
            fclose(fp);
            fclose(temp);
            remove("user.txt");
            rename("temp.txt","user.txt");
            goto loop;
    }

    return 0;
}

int my_profile()
{
    int n,m,i_amt,u_balance;
    char username[10],password[20];
    FILE *fp,*temp;

    hloop:
    system("cls");
    printf("\n\t\t\t**=======My Profile Info=======**\n");
    printf("\n\t\t\t\tUsername   : %s",u_name);
    printf("\n\t\t\t\tPasword    : %s",u_pwd);
    printf("\n\n\t\t\t\t1. My Balance");
    printf("\n\n\t\t\t\t2. Back");
    printf("\n\t\t\t____________________________");
    printf("\n\n\t\t\t\tEnter the choice    :");
    scanf("%d",&m);

    if(m==1){
        loop:
        system("cls");
        printf("\n\t\t\t**=======My Balance=======**\n");
        printf("\n\t\t\t1. Add money");
        printf("\n\t\t\t2. Check Balance");
        printf("\n\t\t\t3. Back");
        printf("\n\t\t_________________________________");
        printf("\n\t\t\tEnter the choice  :");
        scanf("%d",&n);

        if(n==1){
            fp=fopen("user.txt","r");
            temp=fopen("temp.txt","w");

            system("cls");
            printf("\n\t\t\t**=======My Balance=======**\n");
            while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                fscanf(fp, "Balance   : %d",&u_balance);
                fscanf(fp, "\n______________________________\n");

                if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
                    printf("\n\t\t\tUsername   : %s",u_name);
                    printf("\n\t\t\tPasword    : %s",u_pwd);
                    printf("\n\n\t\t\tAdd Money  :");
                    scanf("%d",&i_amt);
                    u_balance += i_amt;

                    fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                    fprintf(temp, "Balance   : %d",u_balance);
                    fprintf(temp, "\n______________________________\n");
                    printf("\n\t\t\tMoney added successfully...     Available balance  : %d",u_balance);
                    getch();

                }else{
                    fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                    fprintf(temp, "Balance   : %d",u_balance);
                    fprintf(temp, "\n______________________________\n");
                }
            }
            fclose(fp);
            fclose(temp);
            remove("user.txt");
            rename("temp.txt","user.txt");
            goto loop;

        }else if(n==2){
            fp=fopen("user.txt","r");

            system("cls");
            printf("\n\t\t\t**=======My Balance=======**\n");
            while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                fscanf(fp, "Balance   : %d",&u_balance);
                fscanf(fp, "\n______________________________\n");

                if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
                    printf("\n\t\t\tUsername     : %s",username);
                    printf("\n\t\t\tPassword     : %s",password);
                    printf("\n\t\t\tBalance      : %d Rs",u_balance);
                    printf("\n\t\t_________________________________________");
                    printf("\n\n\t\t\tPress Enter to go back...");
                    getch();
                }

            }
            fclose(fp);
            goto loop;
        }else if(n==3){
            goto hloop;
        }else{
            printf("\n\t\t\tPlease Enter a valid input...");
            getch();
            goto loop;
        }
        goto hloop;

    }else{
        return 1;
    }

    return 1;
}

int load_user_balance(int i_amt,int t_fare,int s_fare)
{
    int u_balance,r_balance,found=0;
    char username[20],password[20];
    FILE *fp,*temp;
    fp = fopen("user.txt","r");
    temp = fopen("utemp.txt","w");

    while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
        fscanf(fp, "Balance   : %d",&u_balance);
        fscanf(fp, "\n______________________________\n");

        if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
           if(s_fare<=u_balance){

              if(u_balance<t_fare){
                found=2;
                fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                fprintf(temp, "Balance   : %d",u_balance);
                fprintf(temp, "\n______________________________\n");
                printf("\n\t\t\tInsufficient money....   Available balance  : %d",u_balance);
                getch();
              }else{
                  u_balance-=i_amt;
                  r_balance=u_balance;
                  fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                  fprintf(temp, "Balance   : %d",u_balance);
                  fprintf(temp, "\n______________________________\n");
              }

            }else{
                found=1;
                fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                fprintf(temp, "Balance   : %d",u_balance);
                fprintf(temp, "\n______________________________\n");
                printf("\n\t\t\tInsufficient money....   Available balance  : %d",u_balance);
                getch();

            }

        }else{
            fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
            fprintf(temp, "Balance   : %d",u_balance);
            fprintf(temp, "\n______________________________\n");
        }
    }
    fclose(fp);
    fclose(temp);
    remove("user.txt");
    rename("utemp.txt","user.txt");

    if(found==1){
        return 1;
    }else if(found==2){
        return 2;
    }else{
        return r_balance;
    }
}

int train_tik_book()                                                                                          //Train tickect booking interface
{
    FILE *fp, *temp;
    struct travel train;
    int found = 0, c, n,m,next=0,tickets_to_book,t_fare,i_amt,num=0,u_balance,t_a_s[MAX_SEATS];
    char itr_dep[20], itr_arr[20],dum_dep[20],dum_arr[20];
    char username[20],password[20];


    tloop:
    system("cls");
    printf("\n\t\t\t**=======Train ticket bookings=======**\n");
    printf("\n\t\t\t1.Search Train ");
    printf("\n\t\t\t2.View Trains");
    printf("\n\t\t\t3.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&n);

    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            system("cls");
            printf("\n\t\t\t**=======Search Train =======**\n");
            printf("\n\t\t\t1. Back");
            printf("\n\n\t\t\t Enter the Departure place    :");
            scanf("%s", itr_dep);

            if (strcmp(itr_dep, "1") == 0) {
                goto tloop;
            }

            printf("\n\n\t\t\t Enter the Arrival place      :");
            scanf("%s", itr_arr);

            if (strcmp(itr_arr, "1") == 0) {
                goto tloop;
            }

            strcpy(dum_dep,itr_dep);
            strcpy(dum_arr,itr_arr);

            dloop:
            if(found==4){
                strcpy(itr_dep,dum_dep);
                strcpy(itr_arr,dum_arr);
            }
            fp = fopen("train_book.txt", "r");
            temp = fopen("temp_book.txt", "w");

            if (fp == NULL || temp == NULL) {
                printf("Error opening file for reading.\n");
                getch();
                goto tloop;
            }

            while (fscanf(fp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                  train.tp_name, &train.tp_no, train.depart_time, train.arrive_time) != EOF) {
                  fscanf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                  train.depart_place, train.arrive_place, &train.tp_fare, train.tp_tm_dur, &train.tp_av_tic,&train.seat_numbers);
                  fscanf(fp, "\n_______________________________________________________________________________________");

                  num++;

                  if(strcmp(train.depart_place, itr_dep) == 0 && strcmp(train.arrive_place, itr_arr) == 0) {
                    found = 1;
                    loop7:
                    system("cls");
                    printf("\n\t\t\t**=======Train Details =======**\n");
                    printf("\n\n\t\t\tTrain ID        : %d", num);
                    printf("\n\n\t\t\tTrain name      : %s Express", train.tp_name);
                    printf("\n\t\t\tTrain number      : %d", train.tp_no);
                    printf("\n\t\t\tDeparture time    : %s", train.depart_time);
                    printf("\n\t\t\tArrival time      : %s", train.arrive_time);
                    printf("\n\t\t\tDeparture place   : %s", train.depart_place);
                    printf("\n\t\t\tArrival place     : %s", train.arrive_place);
                    printf("\n\t\t\tTicket fare       : %d", train.tp_fare);
                    printf("\n\t\t\tTime duration     : %s", train.tp_tm_dur);
                    printf("\n\t\t\tAvailable tickets : %d", train.tp_av_tic);
                    printf("\n\t\t________________________________________________");

                    printf("\n\t\t\t1. Next");
                    printf("\t\t\t\t3. Book this Train");
                    printf("\n\t\t\t2. No");
                    printf("\n\n\t\t\tEnter the choice :");
                    scanf("%d", &c);

                    if (c == 3) {

                                loop5:
                                system("cls");
                                printf("\n\t\t\t**======Train Ticket Booking=======**\n");
                                printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                                scanf("%d", &tickets_to_book);

                                if (tickets_to_book <= train.tp_av_tic) {

                                    t_fare=(tickets_to_book*train.tp_fare);
                                    printf("\n\t\t\t Total ticket price      : %d",t_fare);
                                    printf("\n\t\t\tAre you sure want to book this bus...");
                                    getch();

                                    loop6:
                                    system("cls");
                                    printf("\n\t\t\t\t**=======Payment=======**\n");
                                    printf("\n________________________________");
                                    printf("\n| Total ticket price      : %d\t|",t_fare);
                                    printf("\n|_______________________________|");
                                    printf("\n\n\t\t\t\tEnter the amount  :");
                                    scanf("%d", &i_amt);

                                        if (i_amt == t_fare) {

                                            retval=load_user_balance(i_amt,t_fare,train.tp_fare);
                                            if(retval==1){
                                                goto loop7;
                                            }else if(retval==2){
                                                goto loop5;
                                            }
                                            train.tp_av_tic -= tickets_to_book;

                                            train.seat_numbers++;
                                            for (int i = 0; i < tickets_to_book; i++) {
                                                t_a_s[i] = train.seat_numbers;
                                                train.seat_numbers++;
                                            }
                                            train.seat_numbers--;

                                            system("cls");
                                            printf("\n\n\t\t\tTrain tickets booked successfully for %d tickets!", tickets_to_book);
                                            printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                            printf("\n\t\t_______________________________________________________            Available Balance  : %d",retval);
                                            printf("\n\t\t| Name            :  %s", u_name);
                                            printf("\n\t\t| %s Express        %s To %s", train.tp_name, train.depart_place, train.arrive_place);
                                            printf("\n\t\t| Train number    :  %d", train.tp_no);
                                            printf("\n\t\t| Tickets booked  :  %d", tickets_to_book);
                                            printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tickets_to_book; i++) {
                                                       printf("%d , ", t_a_s[i]);
                                                  }
                                            printf("\n\t\t| Travel duration :  %s", train.tp_tm_dur);
                                            printf("\n\t\t| Departure Time  :  %s", train.depart_time);
                                            printf("\n\t\t| Arrival Time    :  %s", train.arrive_time);
                                            printf("\n\t\t| Total price     :  %d", t_fare);
                                            printf("\n\t\t________________________________________________________");
                                            printf("\n\n\t\t Happy Journey.........");
                                            getch();


                                            fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                                            train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                                            fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                                            train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                                            fprintf(temp, "\n_______________________________________________________________________________________");
                                            strcpy(itr_dep,"dummy");

                                        }else{
                                            printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                            getch();
                                            goto loop6;
                                        }

                                }else{
                                    printf("\n\t\t\tNot enough tickets available....(Available tickets: %d",train.tp_av_tic );
                                    getch();
                                    goto loop5;
                                }
                    }else if(c == 2){
                        found=3;
                        strcpy(itr_dep,"dummy");
                        fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                        train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                        fprintf(temp, "\n_______________________________________________________________________________________");
                    }else{
                        found=2;
                        next=1;
                        fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                        train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                        fprintf(temp, "\n_______________________________________________________________________________________");
                    }

                }else{
                    fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                            train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                    fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                            train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                    fprintf(temp, "\n_______________________________________________________________________________________");
                }

            }

            if(found==0 || found==2){
                if(next==1){
                    printf("\n\t\t\tNo Trains Available Next from %s to %s",dum_dep,dum_arr);
                    printf("\n\t\t_______________________________________________");
                    printf("\n\t\t\t1. Search Next Train");
                    printf("\t\t3. Previous");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_______________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==3){
                        num=0;
                        found=4;
                        fclose(fp);
                        fclose(temp);
                        remove("train_book.txt");
                        rename("temp_book.txt","train_book.txt");
                        goto dloop;
                    }
                }else{
                    printf("\n\t\t\tNo Trains name found from %s to %s",itr_dep,itr_arr);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);
                }

                if(m==1){
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("train_book.txt");
                    rename("temp_book.txt","train_book.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("train_book.txt");
                    rename("temp_book.txt","train_book.txt");
                    goto tloop;
                }
            }else if(found==3){
                printf("\n\t\t\tBooking cancelled.......");
                getch();
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("train_book.txt");
                rename("temp_book.txt","train_book.txt");
                goto tloop;
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("train_book.txt");
                rename("temp_book.txt","train_book.txt");
                goto tloop;
            }
            break;
        case 2:
            system("cls");
            view_trains(1);
            getch();
            goto tloop;
            break;
        default:
            printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
            getch();
            goto tloop;
    }
    return 0;

}

int view_trains(int n)
{
    FILE *fp;
    struct travel train;
    int num=0;

    fp = fopen("train_book.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        getch();
        return 0;
    }

    system("cls");
    printf("\n\t\t\t**=======Train Details=======**\n");

    while (fscanf(fp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                  train.tp_name,&train.tp_no,train.depart_time,train.arrive_time) != EOF){
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
               train.depart_place,train.arrive_place,&train.tp_fare,train.tp_tm_dur,&train.tp_av_tic,&train.seat_numbers);
        fscanf(fp,"\n_______________________________________________________________________________________");

        num++;
        printf("\n\t\t\tTrain ID          : %d", num);
        printf("\n\t\t\tTrain name        : %s", train.tp_name);
        printf("\n\t\t\tTrain number      : %d", train.tp_no);
        printf("\n\t\t\tDeparture time    : %s", train.depart_time);
        printf("\n\t\t\tArrival time      : %s", train.arrive_time);
        printf("\n\t\t\tDeparture place   : %s", train.depart_place);
        printf("\n\t\t\tArrival place     : %s", train.arrive_place);
        printf("\n\t\t\tTicket fare       : %d", train.tp_fare);
        printf("\n\t\t\tTime duration     : %s", train.tp_tm_dur);
        printf("\n\t\t\tAvailable tickets : %d", train.tp_av_tic);
        if(n==2){
        printf("\n\t\t\tSeats Booked      : %d", train.seat_numbers);
        }
        printf("\n\t\t________________________________________________");
    }

    fclose(fp);
    printf("\n\t\tPress enter to Go back");
    getch();
    return 1;
}

int bus_tik_book()                                                                                          //Train tickect booking interface
{
    FILE *fp, *temp,*ub, *utemp;
    struct travel bus;
    int found = 0, c, m,n, tickets_to_book,t_fare,next,i_amt,num=0,b_a_s[MAX_SEATS];
    char itr_dep[20], itr_arr[20];
    char dum_dep[20],dum_arr[20];

    tloop:
    system("cls");
    printf("\n\t\t\t**=======bus ticket bookings=======**\n");
    printf("\n\t\t\t1.Search bus ");
    printf("\n\t\t\t2.View bus");
    printf("\n\t\t\t3.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&n);

    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop:
            system("cls");
            printf("\n\t\t\t**=======Search bus =======**\n");
            printf("\n\t\t\t1. Back");
            printf("\n\n\t\t\t Enter the Departure place    :");
            scanf("%s", itr_dep);

            if (strcmp(itr_dep, "1") == 0) {
                goto tloop;
            }

            printf("\n\n\t\t\t Enter the Arrival place      :");
            scanf("%s", itr_arr);

            if (strcmp(itr_arr, "1") == 0) {
                goto tloop;
            }

            strcpy(dum_dep,itr_dep);
            strcpy(dum_arr,itr_arr);

            dloop:
            if(found==4){
                strcpy(itr_dep,dum_dep);
                strcpy(itr_arr,dum_arr);
            }

            fp = fopen("bus_book.txt", "r");
            temp = fopen("temp_book.txt", "w");

            if (fp == NULL) {
                printf("Error opening file for reading.\n");
                getch();
                goto tloop;
            }

            while (fscanf(fp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                          bus.tp_name, &bus.tp_no, bus.depart_time, bus.arrive_time) != EOF) {
                fscanf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                       bus.depart_place, bus.arrive_place, &bus.tp_fare, bus.tp_tm_dur, &bus.tp_av_tic,&bus.seat_numbers);
                fscanf(fp, "\n_______________________________________________________________________________________");

                num++;
                if (strcmp(bus.depart_place, itr_dep) == 0 && strcmp(bus.arrive_place, itr_arr) == 0) {
                    found = 1;
                    loop7:
                    system("cls");
                    printf("\n\t\t\t**=======Bus Details =======**\n");
                    printf("\n\n\t\t\tBus ID           :%d", num);
                    printf("\n\n\t\t\tBus name         : %s Express", bus.tp_name);
                    printf("\n\t\t\tbus number        : TN-%d", bus.tp_no);
                    printf("\n\t\t\tDeparture time    : %s", bus.depart_time);
                    printf("\n\t\t\tArrival time      : %s", bus.arrive_time);
                    printf("\n\t\t\tDeparture place   : %s", bus.depart_place);
                    printf("\n\t\t\tArrival place     : %s", bus.arrive_place);
                    printf("\n\t\t\tTicket fare       : %d", bus.tp_fare);
                    printf("\n\t\t\tTime duration     : %s", bus.tp_tm_dur);
                    printf("\n\t\t\tAvailable tickets : %d", bus.tp_av_tic);
                    printf("\n\t\t________________________________________________");

                    printf("\n\t\t\t1. Next");
                    printf("\t\t\t\t3. Book this bus");
                    printf("\n\t\t\t2. No");
                    printf("\n\n\t\t\tEnter the choice :");
                    scanf("%d", &c);

                    if (c == 3) {
                        loop5:
                            system("cls");
                            printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                            scanf("%d", &tickets_to_book);

                            if (tickets_to_book <= bus.tp_av_tic) {
                                t_fare=(tickets_to_book*bus.tp_fare);
                                printf("\n\t\t\t Total ticket price      : %d",t_fare);
                                printf("\n\t\t\tAre you sure want to book this Bus...");
                                getch();

                                loop6:
                                system("cls");
                                printf("\n\t\t\t\t**=======Payment=======**\n");
                                printf("\n________________________________");
                                printf("\n| Total ticket price      : %d\t|",t_fare);
                                printf("\n|_______________________________|");
                                printf("\n\n\t\t\t\tEnter the amount  :");
                                scanf("%d", &i_amt);

                                    if (i_amt == t_fare) {
                                        retval=load_user_balance(i_amt,t_fare,bus.tp_fare);
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop5;
                                        }
                                        bus.tp_av_tic -= tickets_to_book;

                                        if(bus.seat_numbers>=60){
                                            bus.seat_numbers=0;
                                        }
                                        bus.seat_numbers++;
                                        for (int i = 0; i < tickets_to_book; i++) {
                                            b_a_s[i] = bus.seat_numbers;
                                            bus.seat_numbers++;
                                        }
                                        bus.seat_numbers--;
                                        system("cls");
                                        printf("\n\n\t\t\tbus tickets booked successfully for %d tickets!", tickets_to_book);
                                        printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                        printf("\n\t\t_______________________________________________________             Available Balance : %d",retval);
                                        printf("\n\t\t| Name            :  %s", u_name);
                                        printf("\n\t\t| %s Express        %s To %s", bus.tp_name, bus.depart_place, bus.arrive_place);
                                        printf("\n\t\t| Bus number      :  %d", bus.tp_no);
                                        printf("\n\t\t| Tickets booked  :  %d", tickets_to_book);
                                        printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tickets_to_book; i++) {
                                                       printf("%d , ", b_a_s[i]);
                                                  }
                                        printf("\n\t\t| Travel duration :  %s", bus.tp_tm_dur);
                                        printf("\n\t\t| Departure Time  :  %s", bus.depart_time);
                                        printf("\n\t\t| Arrival Time    :  %s", bus.arrive_time);
                                        printf("\n\t\t| Total price     :  %d", t_fare);
                                        printf("\n\t\t________________________________________________________");
                                        printf("\n\t\t Happy Journey.........");
                                        getch();

                                        fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                                            bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                                        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                                            bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic,bus.seat_numbers);
                                        fprintf(temp, "\n_______________________________________________________________________________________");
                                        strcpy(itr_dep,"dummy");

                                    }else{
                                        printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                        getch();
                                        goto loop6;
                                    }

                            }else{
                                printf("\n\t\t\tNot enough tickets available. Available tickets: %d", bus.tp_av_tic);
                                getch();
                                goto loop5;
                            }
                } else if (c == 2) {
                    found=3;
                    strcpy(itr_dep,"dummy");
                    fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                    fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic,bus.seat_numbers);
                    fprintf(temp, "\n_______________________________________________________________________________________");
                }else{
                    found=2;
                    next=1;
                    fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                    fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic,bus.seat_numbers);
                    fprintf(temp, "\n_______________________________________________________________________________________");
                }
            }else{
                fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic,bus.seat_numbers);
                fprintf(temp, "\n_______________________________________________________________________________________");
             }

            }

            if(found==0 || found==2){
                if(next==1){
                    printf("\n\t\t\tNo Bus Avaiable Next from %s to %s",dum_dep,dum_arr);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\t\t3. Previous");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==3){
                       num=0;
                       found=4;
                       fclose(fp);
                       fclose(temp);
                       remove("bus_book.txt");
                       rename("temp_book.txt","bus_book.txt");
                       goto dloop;
                    }
                }else{
                    printf("\n\t\t\tNo Bus name found from %s to %s",itr_dep,itr_arr);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);
                }

                if(m==1){
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("bus_book.txt");
                    rename("temp_book.txt","bus_book.txt");
                    goto loop;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("bus_book.txt");
                    rename("temp_book.txt","bus_book.txt");
                    goto tloop;
                }
            }else if(found==3){
                printf("\n\t\t\tBooking cancelled......");
                getch();
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("bus_book.txt");
                rename("temp_book.txt","bus_book.txt");
                goto tloop;
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("bus_book.txt");
                rename("temp_book.txt","bus_book.txt");
                goto tloop;
            }
            break;
        case 2:
            system("cls");
            view_bus(1);
            getch();
            goto tloop;
            break;
        default:
            printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
            getch();
            goto tloop;
    }
    return 0;

}

int view_bus(int n)                                                                                                           //view buses
{
    FILE *fp;
    struct travel bus;

    fp = fopen("bus_book.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        getch();
        return 0;
    }

    system("cls");
    printf("\n\t\t\t**=======bus Details=======**\n");

    while (fscanf(fp,"\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                  bus.tp_name,&bus.tp_no,bus.depart_time,bus.arrive_time) != EOF){
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d \n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
               bus.depart_place,bus.arrive_place,&bus.tp_fare,bus.tp_tm_dur,&bus.tp_av_tic,&bus.seat_numbers);
        fscanf(fp,"\n_______________________________________________________________________________________");

        printf("\n\t\t\tbus name          : %s Travels", bus.tp_name);
        printf("\n\t\t\tbus number        : TN-%d", bus.tp_no);
        printf("\n\t\t\tDeparture time    : %s", bus.depart_time);
        printf("\n\t\t\tArrival time      : %s", bus.arrive_time);
        printf("\n\t\t\tDeparture place   : %s", bus.depart_place);
        printf("\n\t\t\tArrival place     : %s", bus.arrive_place);
        printf("\n\t\t\tTicket fare       : %d", bus.tp_fare);
        printf("\n\t\t\tTime duration     : %s", bus.tp_tm_dur);
        printf("\n\t\t\tAvailable tickets : %d", bus.tp_av_tic);
        if(n==2){
        printf("\n\t\t\tSeats Booked      : %d", bus.seat_numbers);
        }
        printf("\n\t\t________________________________________________");
    }

    fclose(fp);
    printf("\n\t\tPress enter to exit");
    getch();
    return 0;
}

int tamil_movie_book()
{
    struct movie tamil;
    FILE *fp,*temp,*ub,*utemp;
    int n,c,m,tickets_to_book,t_fare,found=0,num=0,next=0,u_balance,i_amt,tm_a_s[MAX_SEATS];
    char i_mov_name[20],username[20],password[20],dum_mov[20];

    hloop:
    system("cls");
    printf("\n\t\t\t**=======Tamil Movies Booking=======**\n");
    printf("\n\t\t\t1. Search movies");
    printf("\n\t\t\t2. View movies");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t________________________________________");
    printf("\n\t\t\tEnter the choice  :");
    scanf("%d", &n);

    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            system("cls");
            printf("\n\t\t\t**=======Search Tamil Movies=======**\n");
            printf("\n\t\t1. Back ");
            printf("\n\t\t\tMovie name   : ");
            scanf("%s",i_mov_name);

            if(strcmp(i_mov_name,"1")==0){
                fclose(fp);
                fclose(temp);
                goto hloop;
            }

            dloop:
            strcpy(dum_mov,i_mov_name);
            if(found==4){
                strcpy(i_mov_name,dum_mov);
            }

            fp=fopen("tamil_movie.txt","r");
            temp=fopen("temp_book.txt","w");

            if(fp==NULL || temp==NULL){
                printf("\n\t\t\tError openning file....");
                getch();
                goto hloop;
            }

            system("cls");
            printf("\n\t\t\t**=======Tamil Movies=======**\n");
            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&tamil.mov_t_fare,&tamil.mov_av_tic,&tamil.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                num++;
                if(strcmp(i_mov_name,tamil.mov_name)==0){
                    found=1;
                    loop7:
                    system("cls");
                    printf("\n\t\t\t**=======Tamil Movies=======**\n");
                    printf("\n\t\t%d.      Movie name         : %s",num,tamil.mov_name);
                    printf("\n\t\t\tTheater name       : %s",tamil.mov_theater);
                    printf("\n\t\t\tDate               : %s",tamil.mov_date);
                    printf("\n\t\t\tTiming             : %s",tamil.mov_time);
                    printf("\n\t\t\tTicket price       : %d",tamil.mov_t_fare);
                    printf("\n\t\t\tAvailable tickets  : %d",tamil.mov_av_tic);
                    printf("\n\t\t_____________________________________________");

                    printf("\n\t\t\t1. Next");
                    printf("\t\t\t\t3. Book this movie");
                    printf("\n\t\t\t2. No");
                    printf("\n\n\t\t\tEnter the choice :");
                    scanf("%d", &c);

                    if (c == 3) {
                            loop5:
                                system("cls");
                                printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                                scanf("%d", &tickets_to_book);

                                if (tickets_to_book <= tamil.mov_av_tic) {
                                    t_fare=(tickets_to_book*tamil.mov_t_fare);
                                    printf("\n\t\t\t Total ticket price      : %d",t_fare);
                                    printf("\n\t\t\tAre you sure want to book this movie...");
                                    getch();

                                    loop6:
                                    system("cls");
                                    printf("\n\t\t\t\t**=======Payment=======**\n");
                                    printf("\n________________________________");
                                    printf("\n| Total ticket price      : %d\t|",t_fare);
                                    printf("\n|_______________________________|");
                                    printf("\n\n\t\t\t\tEnter the amount  :");
                                    scanf("%d", &i_amt);

                                      if (i_amt == t_fare) {
                                        retval=load_user_balance(i_amt,t_fare,tamil.mov_t_fare);
                                        system("cls");
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop5;
                                        }
                                          tamil.mov_av_tic -= tickets_to_book;

                                          tamil.seat_numbers++;
                                          for (int i = 0; i < tickets_to_book; i++) {
                                                tm_a_s[i] = tamil.seat_numbers;
                                                tamil.seat_numbers++;
                                          }
                                          tamil.seat_numbers--;
                                          printf("\n\n\t\t\tbus tickets booked successfully for %d tickets!", tickets_to_book);
                                          printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                          printf("\n\t\t_______________________________________________________             Available Balance : %d",retval);
                                          printf("\n\t\t| Name            : %s", u_name);
                                          printf("\n\t\t| Movie           : %s", tamil.mov_name);
                                          printf("\n\t\t| Theater name    : %s", tamil.mov_theater);
                                          printf("\n\t\t| Tickets booked  : %d", tickets_to_book);
                                          printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tickets_to_book; i++) {
                                                       printf("%d , ", tm_a_s[i]);
                                                  }
                                          printf("\n\t\t| Date            : %s", tamil.mov_date);
                                          printf("\n\t\t| Time            : %s", tamil.mov_time);
                                          printf("\n\t\t| Total fare      : %d", t_fare);
                                          printf("\n\t\t________________________________________________________");
                                          printf("\n\n\t\t Enjoy Your Movie.........");
                                          getch();

                                          fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                                          fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                                          fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                                          fprintf(temp,"\n_____________________________________________________");
                                          strcpy(i_mov_name,"dummy");

                                       }else{
                                          printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                          getch();
                                          goto loop6;
                                      }
                                }else{
                                    printf("\n\t\t\tNot enough tickets available. Available tickets: %d", tamil.mov_av_tic);
                                    getch();
                                    goto loop5;
                                }

                    } else if (c == 2) {
                            found=3;
                            strcpy(i_mov_name,"dummy");
                            fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                            fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                            fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                            fprintf(temp,"\n_____________________________________________________");
                    }else{
                        found=2;
                        next=1;
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }

                }else{
                   fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                   fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                   fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                   fprintf(temp,"\n_____________________________________________________");
                }
            }
            if(found==0 || found==2){
                if(next==1){
                    printf("\n\t\t\tNo Movies Available Next as %s ",dum_mov);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\t\t3. Previuos");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==3){
                        num=0;
                        found=4;
                        fclose(fp);
                        fclose(temp);
                        remove("tamil_movie.txt");
                        rename("temp_book.txt","tamil_movie.txt");
                        goto dloop;
                    }
                }else{
                    printf("\n\t\t\tNo Movies found as %s ",i_mov_name);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);
                }

                if(m==1){
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("tamil_movie.txt");
                    rename("temp_book.txt","tamil_movie.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("tamil_movie.txt");
                    rename("temp_book.txt","tamil_movie.txt");
                    goto hloop;
                }
            }else if(found==3){
                printf("\n\t\t\tBooking cancelled......");
                getch();
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("tamil_movie.txt");
                rename("temp_book.txt","tamil_movie.txt");
                goto hloop;
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("tamil_movie.txt");
                rename("temp_book.txt","tamil_movie.txt");
                goto hloop;
            }
            break;
        case 2:
            retval=view_tamil_movie(1);
            if(retval==1){
                goto hloop;
            }
        default:
            printf("\n\t\t\tplease Enter a valid input...");
            getch();
            goto hloop;
    }
    return 1;
}

int view_tamil_movie(int n)
{
    struct movie tamil;
    FILE *fp;
    fp=fopen("tamil_movie.txt","r");

    system("cls");
    printf("\n\t\t\t**=======Tamil Movies=======**\n");
    while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater)!=EOF){
        fscanf(fp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
        fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&tamil.mov_t_fare,&tamil.mov_av_tic,&tamil.seat_numbers);
        fscanf(fp,"\n_____________________________________________________");

        printf("\n\t\t\tMovie name         : %s",tamil.mov_name);
        printf("\n\t\t\tTheater name       : %s",tamil.mov_theater);
        printf("\n\t\t\tDate               : %s",tamil.mov_date);
        printf("\n\t\t\tTiming             : %s",tamil.mov_time);
        printf("\n\t\t\tTicket price       : %d",tamil.mov_t_fare);
        printf("\n\t\t\tAvailable tickets  : %d",tamil.mov_av_tic);
        if(n==2){
        printf("\n\t\t\tSeats Booked      : %d", tamil.seat_numbers);
        }
        printf("\n\t\t_____________________________________________");
    }
    fclose(fp);
    printf("\n\t\t\tpress Enter to go back.....");
    getch();
    return 1;
}

int holly_movie_book()
{
    struct movie holly;
    FILE *fp,*temp;
    int n,c,m,tickets_to_book,t_fare,found=0,num=0,next=0,i_amt,tm_a_s[MAX_SEATS];
    char i_mov_name[20],dum_mov[20];

    hloop:
    system("cls");
    printf("\n\t\t\t**=======Hollywood Movies Booking=======**\n");
    printf("\n\t\t\t1. Search movies");
    printf("\n\t\t\t2. View movies");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t________________________________________");
    printf("\n\t\t\tEnter the choice  :");
    scanf("%d", &n);

    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            system("cls");
            printf("\n\t\t\t**=======Search Hollywood Movies=======**\n");
            printf("\n\t\t1. Back ");
            printf("\n\t\t\tMovie name   : ");
            scanf("%s",i_mov_name);

            if(strcmp(i_mov_name,"1")==0){
                fclose(fp);
                fclose(temp);
                goto hloop;
            }

            dloop:
            strcpy(dum_mov,i_mov_name);
            if(found==4){
                strcpy(i_mov_name,dum_mov);
            }

            fp=fopen("holly_movie.txt","r");
            temp=fopen("temp_book.txt","w");

            if(fp==NULL || temp==NULL){
                printf("\n\t\t\tError openning file....");
                getch();
                goto hloop;
            }

            system("cls");
            printf("\n\t\t\t**=======Hollywood Movies=======**\n");
            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&holly.mov_t_fare,&holly.mov_av_tic,&holly.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                num++;
                if(strcmp(i_mov_name,holly.mov_name)==0){
                    found=1;
                    loop7:
                    system("cls");
                    printf("\n\t\t\t**=======Hollywood Movies=======**\n");
                    printf("\n\t\t%d.      Movie name         : %s",num,holly.mov_name);
                    printf("\n\t\t\tTheater name       : %s",holly.mov_theater);
                    printf("\n\t\t\tDate               : %s",holly.mov_date);
                    printf("\n\t\t\tTiming             : %s",holly.mov_time);
                    printf("\n\t\t\tTicket price       : %d",holly.mov_t_fare);
                    printf("\n\t\t\tAvailable tickets  : %d",holly.mov_av_tic);
                    printf("\n\t\t_____________________________________________");

                    printf("\n\t\t\t1. Next");
                    printf("\t\t\t\t3. Book this movie");
                    printf("\n\t\t\t2. No");
                    printf("\n\n\t\t\tEnter the choice :");
                    scanf("%d", &c);

                    if (c == 3) {
                            loop5:
                                system("cls");
                                printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                                scanf("%d", &tickets_to_book);

                                if (tickets_to_book <= holly.mov_av_tic) {
                                    t_fare=(tickets_to_book*holly.mov_t_fare);
                                    printf("\n\t\t\t Total ticket price      : %d",t_fare);
                                    printf("\n\t\t\tAre you sure want to book this movie...");
                                    getch();

                                    loop6:
                                    system("cls");
                                    printf("\n\t\t\t\t**=======Payment=======**\n");
                                    printf("\n________________________________");
                                    printf("\n| Total ticket price      : %d\t|",t_fare);
                                    printf("\n|_______________________________|");
                                    printf("\n\n\t\t\t\tEnter the amount  :");
                                    scanf("%d", &i_amt);

                                      if (i_amt == t_fare) {
                                        retval=load_user_balance(i_amt,t_fare,holly.mov_t_fare);
                                        system("cls");
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop5;
                                        }
                                          holly.mov_av_tic -= tickets_to_book;

                                          holly.seat_numbers++;
                                          for (int i = 0; i < tickets_to_book; i++) {
                                                tm_a_s[i] = holly.seat_numbers;
                                                holly.seat_numbers++;
                                          }
                                          holly.seat_numbers--;
                                          printf("\n\n\t\t\tMovie tickets booked successfully for %d tickets!", tickets_to_book);
                                          printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                          printf("\n\t\t_______________________________________________________             Available Balance : %d",retval);
                                          printf("\n\t\t| Name            : %s", u_name);
                                          printf("\n\t\t| Movie           : %s", holly.mov_name);
                                          printf("\n\t\t| Theater name    : %s", holly.mov_theater);
                                          printf("\n\t\t| Tickets booked  : %d", tickets_to_book);
                                          printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tickets_to_book; i++) {
                                                       printf("%d , ", tm_a_s[i]);
                                                  }
                                          printf("\n\t\t| Date            : %s", holly.mov_date);
                                          printf("\n\t\t| Time            : %s", holly.mov_time);
                                          printf("\n\t\t| Total fare      : %d", t_fare);
                                          printf("\n\t\t________________________________________________________");
                                          printf("\n\n\t\t Enjoy Your Movie.........");
                                          getch();

                                          fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                                          fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                                          fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                                          fprintf(temp,"\n_____________________________________________________");
                                          strcpy(i_mov_name,"dummy");

                                       }else{
                                          printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                          getch();
                                          goto loop6;
                                      }
                                }else{
                                    printf("\n\t\t\tNot enough tickets available. Available tickets: %d", holly.mov_av_tic);
                                    getch();
                                    goto loop5;
                                }
                    } else if (c == 2) {
                            found=3;
                            strcpy(i_mov_name,"dummy");
                            fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                            fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                            fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                            fprintf(temp,"\n_____________________________________________________");
                    }else{
                        found=2;
                        next=1;
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }

                }else{
                   fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                   fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                   fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                   fprintf(temp,"\n_____________________________________________________");
                }
            }
            if(found==0 || found==2){
                if(next==1){
                    printf("\n\t\t\tNo Movies Available Next as %s ",dum_mov);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\t\t3. Previuos");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==3){
                        num=0;
                        found=4;
                        fclose(fp);
                        fclose(temp);
                        remove("holly_movie.txt");
                        rename("temp_book.txt","holly_movie.txt");
                        goto dloop;
                    }
                }else{
                    printf("\n\t\t\tNo Movies found as %s ",i_mov_name);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);
                }

                if(m==1){
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("holly_movie.txt");
                    rename("temp_book.txt","holly_movie.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("holly_movie.txt");
                    rename("temp_book.txt","holly_movie.txt");
                    goto hloop;
                }
            }else if(found==3){
                printf("\n\t\t\tBooking cancelled......");
                getch();
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("holly_movie.txt");
                rename("temp_book.txt","holly_movie.txt");
                goto hloop;
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("holly_movie.txt");
                rename("temp_book.txt","holly_movie.txt");
                goto hloop;
            }
            break;
        case 2:
            retval=view_holly_movie(1);
            if(retval==1){
                goto hloop;
            }
        default:
            printf("\n\t\t\tplease Enter a valid input...");
            getch();
            goto hloop;
    }
    return 1;
}

int view_holly_movie(int n)
{
    struct movie holly;
    FILE *fp;
    fp=fopen("holly_movie.txt","r");

    system("cls");
    printf("\n\t\t\t**=======Hollywood Movies=======**\n");
    while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater)!=EOF){
        fscanf(fp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
        fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&holly.mov_t_fare,&holly.mov_av_tic,&holly.seat_numbers);
        fscanf(fp,"\n_____________________________________________________");

        printf("\n\t\t\tMovie name         : %s",holly.mov_name);
        printf("\n\t\t\tTheater name       : %s",holly.mov_theater);
        printf("\n\t\t\tDate               : %s",holly.mov_date);
        printf("\n\t\t\tTiming             : %s",holly.mov_time);
        printf("\n\t\t\tTicket price       : %d",holly.mov_t_fare);
        printf("\n\t\t\tAvailable tickets  : %d",holly.mov_av_tic);
        if(n==2){
        printf("\n\t\t\tSeats Booked      : %d", holly.seat_numbers);
        }
        printf("\n\t\t_____________________________________________");
    }
    fclose(fp);
    printf("\n\t\t\tpress Enter to go back.....");
    getch();
    return 1;
}

int Events_sports_book()                                                                                  // EvenTs Page
{
    int n,m,num=1,found=0;
    char i_team1[20],i_team2[20],i_amt[20];

    FILE *fp,*temp;
    temp=fopen("temp.txt","w");

    hloop:
    system("cls");
    printf("\n\t\t\t**=======Sports Events=======**\n");
    printf("\n\t\t\t1. Football");
    printf("\n\t\t\t2. Cricket");
    printf("\n\t\t\t3. Volleyball");
    printf("\n\t\t\t4. back");
    printf("\n\t\t\t__________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    switch(n){
        case 1:
            loop1:
            system("cls");
            printf("\n\t\t\t**=======Sports Events=======**\n");
            printf("\n\t\t\t1. ISL league                   11. View Matches");
            printf("\n\t\t\t2. Premier league               22. View Matches");
            printf("\n\t\t\t3. Back");
            printf("\n\t\t\t__________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&m);
            if(m==3){
                goto hloop;
            }

            switch(m){
                case 1:
                    retval=search_isl();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                case 11:
                    retval=view_isl(1);
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                case 2:
                    //retval=search_premier();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                case 22:
                    //retval=view_premier();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                default:
                    printf("\n\t\t\tPlease Enter a valid input...");
                    getch();
                    goto loop1;
            }
            break;
        case 4:
            return 1;
            break;
        default:
            printf("\n\t\t\tPlease Enter a valid input...");
            getch();
            goto hloop;
    }

    return 1;
}

int search_isl()
{
    struct sports isl;
    char i_team1[20],i_team2[20];
    int n,c,tic_book,found=0,num=0,tot_fare,i_amt,i_a_s[MAX_SEATS];
    FILE *fp,*temp;

    hloop:
    fp=fopen("isl_book.txt","r");
    temp=fopen("temp_book.txt","w");

    if(fp==NULL || temp == NULL){
        printf("error openning file...");
        getch();
        return 1;
    }
    system("cls");
    printf("\n\t\t\t**======Search Matches=====**\n");
    printf("\n\t\t1. Back");
    printf("\n\t\t\tEnter the team 1 name    :");
    scanf("%s",i_team1);

    if(strcmp(i_team1,"1")==0){
        fclose(fp);
        fclose(temp);
        return 1;
    }
    printf("\n\t\t\tEnter the team 2 name    :");
    scanf("%s",i_team2);
    if(strcmp(i_team2,"1")==0){
        return 1;
    }

    system("cls");
    printf("\n\t\t\t**====Match Details====**\n");
    while(fscanf(fp,"\n Match  %s vs %s",isl.team1,isl.team2)!=EOF){
        fscanf(fp,"\n Venue        : %s",isl.venue);
        fscanf(fp,"\n Date         : %s",isl.date);
        fscanf(fp,"\n Time         : %s",isl.time);
        fscanf(fp,"\n Ticket fare  : %d",&isl.t_fare);
        fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&isl.av_tic,&isl.seat_numbers);
        fscanf(fp,"\n_________________________________");

        num++;
        if(strcmp(i_team1,isl.team1)==0 && strcmp(i_team2,isl.team2)==0 || strcmp(i_team1,isl.team2)==0 && strcmp(i_team2,isl.team1)==0){
            found=1;
            loop7:
            system("cls");
            printf("\n\t\t%d.        Match   %s vs %s",num,isl.team1,isl.team2);
            printf("\n\t\t\t  Venue            : %s stadium",isl.venue);
            printf("\n\t\t\t  Date             : %s",isl.date);
            printf("\n\t\t\t  Time             : %s",isl.time);
            printf("\n\t\t\t  Ticket fare      : %d",isl.t_fare);
            printf("\n\t\t\t Available Tickets : %d",isl.av_tic);
            printf("\n\t\t______________________________________");

            printf("\n\t\t\tAre sure want to book this Match....");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t____________________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&n);

            if(n==1){
                loop1:
                system("cls");
                printf("\n\t\t\t**====Match Ticket Booking====**\n");
                printf("\n\t\t\tEnter the number of Tickets   :");
                scanf("%d",&tic_book);

                    if(tic_book<=isl.av_tic){
                        tot_fare=(tic_book*isl.t_fare);
                        printf("\n\n\t\t\tTotal Fare   : %d\n",tot_fare);
                        printf("\n\t\t\t1. Proceed to payment");
                        printf("\n\t\t\t2. Cancel Booking");
                        printf("\n\t\t____________________________________");
                        printf("\n\t\t\tEnter the choice   :");
                        scanf("%d",&c);

                            if(c==1){
                                loop2:
                                system("cls");
                                printf("\n\t\t\t**====Payment====**\n");
                                printf("\n\t\t\t________________________________");
                                printf("\n\t\t\t| Total ticket fare       : %d  |",tot_fare);
                                printf("\n\t\t\t|_______________________________|");
                                printf("\n\n\t\t\tEnter the amount  :");
                                scanf("%d",&i_amt);

                                    if(i_amt==tot_fare){
                                        retval=load_user_balance(i_amt,tot_fare,isl.t_fare);
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop1;
                                        }
                                        isl.av_tic -= tic_book;
                                        isl.seat_numbers++;
                                        for (int i = 0; i < tic_book; i++) {
                                            i_a_s[i] = isl.seat_numbers;
                                            isl.seat_numbers++;
                                        }
                                        isl.seat_numbers--;
                                        system("cls");
                                        printf("\n\t\t\t**=======Ticket details=======**\n");
                                        printf("\n\t\t\tPayment successfull!!...");
                                        printf("\n\t\t_______________________________________________________         Available Balance : %d",retval);
                                        printf("\n\t\t| Name            :  %s", u_name);
                                        printf("\n\t\t| Match       %s vs %s", isl.team1,isl.team2);
                                        printf("\n\t\t| Venue           :  %s Stadium", isl.venue);
                                        printf("\n\t\t| Date            :  %s", isl.date);
                                        printf("\n\t\t| Timing          :  %s", isl.time);
                                        printf("\n\t\t| Total tickets   :  %d", tic_book);
                                        printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tic_book; i++) {
                                                       printf("%d , ", i_a_s[i]);
                                                  }
                                        printf("\n\t\t| Total fare      :  %d", tot_fare);
                                        printf("\n\t\t|________________________________________________________");
                                        printf("\n\t\t\tHave a nice day......");
                                        getch();

                                        fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                                        fprintf(temp,"\n Venue        : %s",isl.venue);
                                        fprintf(temp,"\n Date         : %s",isl.date);
                                        fprintf(temp,"\n Time         : %s",isl.time);
                                        fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                                        fprintf(temp,"\n_________________________________");

                                    }else{
                                        printf("\n\t\t\tPlease Enter correct amount...");
                                        getch();
                                        goto loop2;
                                    }

                            }else{
                                printf("\n\t\t\tBooking cancelled....");
                                getch();

                                fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                                fprintf(temp,"\n Venue        : %s",isl.venue);
                                fprintf(temp,"\n Date         : %s",isl.date);
                                fprintf(temp,"\n Time         : %s",isl.time);
                                fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                                fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                                fprintf(temp,"\n_________________________________");
                            }
                        }else{
                            printf("\n\t\t\t %d tickets Not Available  (Available tickets %d)",tic_book,isl.av_tic);
                            getch();
                            goto loop1;
                        }

            }else{
                printf("\n\t\t\tBooking cancelled....");
                getch();
                fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                fprintf(temp,"\n Venue        : %s",isl.venue);
                fprintf(temp,"\n Date         : %s",isl.date);
                fprintf(temp,"\n Time         : %s",isl.time);
                fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                fprintf(temp,"\n_________________________________");
            }
        }else{
            fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
            fprintf(temp,"\n Venue        : %s",isl.venue);
            fprintf(temp,"\n Date         : %s",isl.date);
            fprintf(temp,"\n Time         : %s",isl.time);
            fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
            fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
            fprintf(temp,"\n_________________________________");
        }
    }

    if(found==0){
        printf("\n\t\t\tNo Matches found between %s vs %s ",i_team1,i_team2);
        fclose(fp);
        fclose(temp);
        getch();
        goto hloop;
    }else{
        fclose(fp);
        fclose(temp);
        remove("isl_book.txt");
        rename("temp_book.txt","isl_book.txt");
        return 1;
    }
    return 0;
}

int view_isl(int n)                                                                             //view sports
{
    struct sports isl;
    int num=1,found=0,retval;
    FILE *fp;
    fp=fopen("isl_book.txt","r");
    if(fp==NULL){
        printf("error open file");
        fclose(fp);
        return 1;
    }else{

    system("cls");
    printf("\n\t\t\t**====Match Details====**\n");
    while(fscanf(fp,"\n Match  %s vs %s",isl.team1,isl.team2)!=EOF){
        fscanf(fp,"\n Venue        : %s",isl.venue);
        fscanf(fp,"\n Date         : %s",isl.date);
        fscanf(fp,"\n Time         : %s",isl.time);
        fscanf(fp,"\n Ticket fare  : %d",&isl.t_fare);
        fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&isl.av_tic,&isl.seat_numbers);
        fscanf(fp,"\n_________________________________");
        found=1;

        printf("\n\t\t%d.        Match   %s vs %s",num,isl.team1,isl.team2);
        printf("\n\t\t\t  Venue            : %s stadium",isl.venue);
        printf("\n\t\t\t  Date             : %s",isl.date);
        printf("\n\t\t\t  Time             : %s",isl.time);
        printf("\n\t\t\t  Ticket fare      : %d",isl.t_fare);
        printf("\n\t\t\t Available Tickets : %d",isl.av_tic);
        if(n==2){
        printf("\n\t\t\t Seat Booked       : %d",isl.seat_numbers);
        }
        printf("\n\t\t______________________________________");
        num++;
    }
    }
    if(found==0){
        printf("\n\n\t\t\tNo information added");
        fclose(fp);
        getch();
        return 1;
    }else{
        fclose(fp);
        printf("\n\t\t\tPress Enter to Back....");
        getch();
        return 1;
    }

    return 1;
}

int admin()                                                                                  //admin page
{
    int n,t1,m;

    loop1:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\n\t\t\t\t1.Travel");
    printf("\n\t\t\t\t2.Movies");
    printf("\n\t\t\t\t3.Service");
    printf("\n\t\t\t\t4.Events");
    printf("\n\t\t\t\t5.Touristy");
    printf("\n\t\t\t\t6.Back");
    printf("\n\t\t\t\t7. User details");
    printf("\n\t\t\t___________________________");

    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&n);

    loop3:
    if(n == 6){
        system("cls");
        printf("\n\t\t\tAre sure want to logout from admin ?");
        printf("\n\t\t\t1. Yes");
        printf("\n\t\t\t2. No");
        printf("\n\t\t\tEnter the choice :");
        scanf("%d",&m);
        if(m==1){
            return 1;
        }else if(m==2){
            goto loop1;
        }else{
            printf("\n\t\t\tPlease Enter valid input.....");
            getch();
            goto loop3;
        }
    }
    switch(n){
        case 1:
            loop2:
            system("cls");
            printf("\n\t\t\t**=======ADMIN Travel=======**\n");
            printf("\n\n\t\t\t\t1.Trains ticket");
            printf("\n\t\t\t\t2.Bus ticket");
            printf("\n\t\t\t\t3.Back");
            printf("\n\t\t\t___________________________");
            printf("\n\t\t\tEnter the choice :");
            scanf("%d",&t1);

            if(t1==3){
            goto loop1;
            }

            switch(t1){
                case 1:
                    system("cls");
                    retval=admin_train();
                    if(retval==1){
                    goto loop2;
                    }
                    break;
                case 2:
                    system("cls");
                    retval=admin_bus();
                    if(retval==1){
                        goto loop2;
                    }
                default:
                    printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
                    getch();
                    goto loop2;
            }
            break;
        case 2:
            mloop:
            system("cls");
            printf("\n\t\t\t**=======ADMIN Movies=======**\n");
            printf("\n\t\t\t1. Tamil Movies");
            printf("\n\t\t\t2. Hindi Movies");
            printf("\n\t\t\t3. Hollywood Movies");
            printf("\n\t\t\t4. Back");
            printf("\n\t\t\t___________________________");
            printf("\n\t\t\tEnter the choice :");
            scanf("%d", &m);

            if(m==4){
                goto loop1;
            }
            switch(m){
                case 1:
                    system("cls");
                    retval=admin_tamil_movie();
                    if(retval==1){
                        goto mloop;
                    }
                    break;
                case 2:
                    system("cls");
                    printf("\t\t\t\tNo Data Added........");
                    getch();
                    goto mloop;
                    //retval=admin_hindi_movie();
                    if(retval==1){
                        goto mloop;
                    }
                    break;
                case 3:
                    system("cls");
                    retval=admin_holly_movie();
                    if(retval==1){
                        goto mloop;
                    }
                    break;
                default:
                    printf("\n\t\t\tPlease Enter a valid input...");
                    getch();
                    goto mloop;
            }
            break;
        case 4:
            system("cls");
            printf("\n\t\t\t**=======ADMIN Event=======**\n");
            printf("\n\n\t\t\t\t1. Marathon");
            printf("\n\t\t\t\t2. Sports");
            printf("\n\t\t\t\t3. Concerts");
            printf("\n\t\t\t\t4.Back");
            printf("\n\t\t\t___________________________");
            printf("\n\t\t\tEnter the choice :");
            scanf("%d",&t1);

            if(t1==4){
                goto loop1;
            }

            switch(t1){
                case 2:
                    system("cls");
                    retval=admin_sports_event();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
            }
            break;
        case 7:
            retval=user_details();
            if(retval==1){
               goto loop1;
            }
        default:
            printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
            getch();
            goto loop1;

    }
    return 0;
}

int admin_train()                                                                             //Admin train ticket details
{
    int n,c;
    char tr_seat[10];
    struct travel train;
    FILE *fp,*temp;

    admin_train:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\t\t\t\t1. Add train");
    printf("\n\t\t\t\t2. View train details");
    printf("\n\t\t\t\t3. Delete train details");
    printf("\n\t\t\t\t4. Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice: ");
    scanf("%d", &n);

    if (n == 4) {
        return 1;
    }

    switch (n) {
    case 1:

        fp = fopen("train_book.txt", "a");                                                    //Admin train ticket adding

        loop:
        system("cls");
        printf("\n\t\t\t**=======Train Details=======**\n");
        printf("\n\n\t\t\t\tTrain name        : ");
        scanf("%s", train.tp_name);
        printf("\n\t\t\t\tTrain number       : ");
        scanf("%d", &train.tp_no);
        printf("\n\t\t\t\tDeparture time     : ");
        scanf("%s", train.depart_time);
        printf("\n\t\t\t\tArrival time       : ");
        scanf("%s", train.arrive_time);
        printf("\n\t\t\t\tDeparture place    : ");
        scanf("%s", train.depart_place);
        printf("\n\t\t\t\tArrival place      : ");
        scanf("%s", train.arrive_place);
        printf("\n\t\t\t\tTicket fare        : ");
        scanf("%d", &train.tp_fare);
        printf("\n\t\t\t\tTravel duration    : ");
        scanf("%s", train.tp_tm_dur);
        printf("\n\t\t\t\tAvailable tickets  : ");
        scanf("%d", &train.tp_av_tic);
        printf("\n\t\t\t\tSeats Booked       : ");
        scanf("%d", &train.seat_numbers);


        if (fp == NULL) {
            printf("Error opening file for appending.\n");
            getch();
            return 0;
        }else{
            fprintf(fp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                    train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
            fprintf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  : %d\nseat booked  :%d",
                    train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic,train.seat_numbers);
            fprintf(fp, "\n_______________________________________________________________________________________");
        }

        printf("\n\t\t\t__________________________________________");
        printf("\n\t\t\t\tTrain Details stored successfully");
        printf("\n\n\t\t\t\tDo you want to add another? ");
        printf("\n\t\t\t\t1. Yes");
        printf("\n\t\t\t\t2. back");
        printf("\n\t\t\t\tEnter the choice: ");
        scanf("%d",&c);
        if(c==1){
            goto loop;
        }else{
            admin_train;
        }

        fclose(fp);
        goto admin_train;
        break;
    case 2:
        system("cls");
        view_trains(2);
        goto admin_train;
        break;
    case 3:
        system("cls");
        retval=delete_train();
        if(retval==1){
            goto admin_train;
        }else{
            getch();
            goto admin_train;
        }
        break;
    default:
        printf("Please enter valid input");
        goto admin_train;
    }

    return 0;
}

int delete_train()
{
    FILE *fp, *temp;
    struct travel train;
    int found = 0, c,m,num=0;
    char itr_name[20];

    loop1:
    system("cls");
    printf("\n\t\t\t**=======Delete Train Details=======**\n");
    printf("\n\t1. Back");
    printf("\n\t\t\tEnter the train name    :");
    scanf(" %s", itr_name);

    if (strcmp(itr_name, "1") == 0)
    {
        fclose(fp);
        fclose(temp);
        return 1;
    }

    fp = fopen("train_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL || temp == NULL){
        printf("Error opening file for appending.\n");
        getch();
        return 0;
    }

    while (fscanf(fp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                  train.tp_name,&train.tp_no,train.depart_time,train.arrive_time) != EOF){
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
               train.depart_place,train.arrive_place,&train.tp_fare,train.tp_tm_dur,&train.tp_av_tic,&train.seat_numbers);
        fscanf(fp,"\n_______________________________________________________________________________________");

        num++;
        if (strcmp(train.tp_name, itr_name) == 0){
            found = 1;
            system("cls");
            printf("\n\t\t\t**=======Train Details to Delete=======**\n");
            printf("\n\n\t\t\tTrain Id         : %d", num);
            printf("\n\t\t\tTrain name        : %s Express", train.tp_name);
            printf("\n\t\t\tTrain number      : %d", train.tp_no);
            printf("\n\t\t\tDeparture time    : %s", train.depart_time);
            printf("\n\t\t\tArrival time      : %s", train.arrive_time);
            printf("\n\t\t\tDeparture place   : %s", train.depart_place);
            printf("\n\t\t\tArrival place     : %s", train.arrive_place);
            printf("\n\t\t\tTicket fare       : %d", train.tp_fare);
            printf("\n\t\t\tTime duration     : %s", train.tp_tm_dur);
            printf("\n\t\t\tAvailable tickets : %d", train.tp_av_tic);
            printf("\n\t\t________________________________________________");

            printf("\n\t\t\tAre you sure you want to delete this train?");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\t\t\t3. Next");
            printf("\n\t\t_______________________________________");
            printf("\n\t\t\t Enter the choice  :");
            scanf("%d", &c);

            if (c == 1){
                strcpy(itr_name,"dummy");
                printf("\n\t\t\tTrain details deleted successfully...");
                getch();
            }else if(c==2){
                strcpy(itr_name,"dummy");
                fprintf(temp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                        train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
                fprintf(temp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic,train.seat_numbers);
                fprintf(temp,"\n_______________________________________________________________________________________");
            }else{
                found=2;
                fprintf(temp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                        train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
                fprintf(temp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic,train.seat_numbers);
                fprintf(temp,"\n_______________________________________________________________________________________");
            }
        }else{
            fprintf(temp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                    train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
            fprintf(temp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic,train.seat_numbers);
            fprintf(temp,"\n_______________________________________________________________________________________");
        }
    }

    if(found==0 || found==2){
        printf("\n\t\t\tNo Train name found as %s",itr_name);
        printf("\n\t\t_________________________________________");
        printf("\n\t\t\t1. Search again");
        printf("\n\t\t\t2. Back");
        printf("\n\t\t_________________________________________");
        printf("\n\t\t\tEnter the choice   :");
        scanf("%d",&m);

        if(m==1){
            num=0;
            found=0;
            fclose(fp);
            fclose(temp);
            remove("train_book.txt");
            rename("temp_book.txt","train_book.txt");
            goto loop1;
        }else{
            num=0;
            found=0;
            fclose(fp);
            fclose(temp);
            remove("train_book.txt");
            rename("temp_book.txt","train_book.txt");
            return 1;
        }
    }else{
        num=0;
        found=0;
        fclose(fp);
        fclose(temp);
        remove("train_book.txt");
        rename("temp_book.txt","train_book.txt");
        return 1;
    }

    return 0;
}

int admin_bus()                                                                                                   //Admin bus
{
    int n,c;
    struct travel bus;
    FILE *fp,*temp;

    admin_bus:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\t\t\t\t1. Add Bus");
    printf("\n\t\t\t\t2. View bus details");
    printf("\n\t\t\t\t3. Delete bus details");
    printf("\n\t\t\t\t4. Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice: ");
    scanf("%d", &n);

    if (n == 4) {
        return 1;
    }

    switch (n) {
    case 1:

        fp = fopen("bus_book.txt", "a");                                                                         //Admin bus ticket adding

        loop:
        system("cls");
        printf("\n\t\t\t**=======Train Details=======**\n");
        printf("\n\n\t\t\t\tBus name          : ");
        scanf("%s", bus.tp_name);
        printf("\n\t\t\t\tbus number         : ");
        scanf("%d", &bus.tp_no);
        printf("\n\t\t\t\tDeparture time     : ");
        scanf("%s", bus.depart_time);
        printf("\n\t\t\t\tArrival time       : ");
        scanf("%s", bus.arrive_time);
        printf("\n\t\t\t\tDeparture place    : ");
        scanf("%s", bus.depart_place);
        printf("\n\t\t\t\tArrival place      : ");
        scanf("%s", bus.arrive_place);
        printf("\n\t\t\t\tTicket fare        : ");
        scanf("%d", &bus.tp_fare);
        printf("\n\t\t\t\tTravel duration    : ");
        scanf("%s", bus.tp_tm_dur);
        printf("\n\t\t\t\tAvailable tickets  : ");
        scanf("%d", &bus.tp_av_tic);
        printf("\n\t\t\t\tSeats Booked       : ");
        scanf("%d", &bus.seat_numbers);


        if (fp == NULL) {
            printf("Error opening file for appending.\n");
            getch();
            return 0;
        }else{
            fprintf(fp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
            fprintf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic,bus.seat_numbers);
            fprintf(fp, "\n_______________________________________________________________________________________");
        }

        printf("\n\t\t\t__________________________________________");
        printf("\n\t\t\t\t Bus Details stored successfully");
        printf("\n\n\t\t\t\tDo you want to add another? ");
        printf("\n\t\t\t\t1. Yes");
        printf("\n\t\t\t\t2. back");
        printf("\n\t\t\t\tEnter the choice : ");
        scanf("%d",&c);
        if(c==1){
            goto loop;
        }else{
            fclose(fp);
           goto admin_bus;
        }
        break;
    case 2:
        system("cls");
        view_bus(2);
        goto admin_bus;
        break;
    case 3:
        system("cls");
        retval=delete_bus();
        if(retval==1){
            goto admin_bus;
        }else{
            getch();
            goto admin_bus;
        }
        break;
    default:
        printf("Please enter valid input");
        goto admin_bus;
    }

    return 0;
}

int delete_bus()
{
    FILE *fp, *temp;
    struct travel bus;
    int found = 0, c,m,num=0;
    char ibs_name[20];

    loop1:
    system("cls");
    printf("\n\t\t\t**=======Delete bus Details=======**\n");
    printf("\n\t1. Back");
    printf("\n\t\t\tEnter the bus name    :");
    scanf("%s", ibs_name);

    if (strcmp(ibs_name, "1") == 0)
    {
        return 1;
    }
    fp = fopen("bus_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file for appending.\n");
        getch();
        return 0;
    }

    while (fscanf(fp,"\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                  bus.tp_name,&bus.tp_no,bus.depart_time,bus.arrive_time) != EOF){
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
               bus.depart_place,bus.arrive_place,&bus.tp_fare,bus.tp_tm_dur,&bus.tp_av_tic,&bus.seat_numbers);
        fscanf(fp,"\n_______________________________________________________________________________________");

        num++;
        if (strcmp(bus.tp_name, ibs_name) == 0)
        {
            found = 1;
            system("cls");
            printf("\n\t\t\t**=======Bus Details to Delete=======**\n");
            printf("\n\n\t\t\tBus Id           : %d", num);
            printf("\n\t\t\tBus name          : %s ", bus.tp_name);
            printf("\n\t\t\t Bus number       : %d", bus.tp_no);
            printf("\n\t\t\tDeparture time    : %s", bus.depart_time);
            printf("\n\t\t\tArrival time      : %s", bus.arrive_time);
            printf("\n\t\t\tDeparture place   : %s", bus.depart_place);
            printf("\n\t\t\tArrival place     : %s", bus.arrive_place);
            printf("\n\t\t\tTicket fare       : %d", bus.tp_fare);
            printf("\n\t\t\tTime duration     : %s", bus.tp_tm_dur);
            printf("\n\t\t\tAvailable tickets : %d", bus.tp_av_tic);
            printf("\n\t\t________________________________________________");

            printf("\n\t\t\tAre you sure you want to delete this bus?");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\t\t\t3. Next");
            printf("\n\t\t_________________________________");
            printf("\n\n\t\t\tEnter the choice :");
            scanf("%d", &c);

            if (c == 1){
                strcpy(ibs_name,"dummy");
                printf("\n\t\t\t bus details deleted successfully...");
                getch();
            }else if(c==2){
                strcpy(ibs_name,"dummy");
                fprintf(temp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",
                        bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic,bus.seat_numbers);
                fprintf(temp, "\n_______________________________________________________________________________________");
            }else{
                found=2;
                fprintf(temp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",
                        bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic,bus.seat_numbers);
                fprintf(temp, "\n_______________________________________________________________________________________");
            }
        }
        else
        {
            fprintf(temp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
            fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic,bus.seat_numbers);
            fprintf(temp, "\n_______________________________________________________________________________________");
        }
    }
    if(found==0 || found==2){
        printf("\n\t\t\tNo Buses name found as %s",ibs_name);
        printf("\n\t\t_________________________________________");
        printf("\n\t\t\t1. Search again");
        printf("\n\t\t\t2. Back");
        printf("\n\t\t_________________________________________");
        printf("\n\t\t\tEnter the choice   :");
        scanf("%d",&m);

        if(m==1){
            num=0;
            found=0;
            fclose(fp);
            fclose(temp);
            remove("bus_book.txt");
            rename("temp_book.txt","bus_book.txt");
            goto loop1;
        }else{
            num=0;
            found=0;
            fclose(fp);
            fclose(temp);
            remove("bus_book.txt");
            rename("temp_book.txt","bus_book.txt");
            return 1;
        }
    }else{
        num=0;
        found=0;
        fclose(fp);
        fclose(temp);
        remove("bus_book.txt");
        rename("temp_book.txt","bus_book.txt");
        return 1;
    }

    return 0;
}

int admin_tamil_movie()
{
    struct movie tamil;
    FILE *fp,*temp;
    int n,m,c,found=0;
    char i_mov_name[20];

    hloop:
    system("cls");
    printf("\n\t\t\t=====Admin Tamil Movies=====\n");
    printf("\n\t\t\t1. Add Movies");
    printf("\n\t\t\t2. View Movies");
    printf("\n\t\t\t3. Delete Movies");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t______________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    if(n==4){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            fp=fopen("tamil_movie.txt","a");

            system("cls");
            printf("\n\t\t\t=====Add Tamil Movies=====\n");
            printf("\n\t\t\tMovie name   : ");
            scanf("%s",tamil.mov_name);
            printf("\n\t\t\tTheater name : ");
            scanf("%s",tamil.mov_theater);
            printf("\n\t\t\tMovie Date   : ");
            scanf("%s",tamil.mov_date);
            printf("\n\t\t\tMovie Time   : ");
            scanf("%s",tamil.mov_time);
            printf("\n\t\t\tTicket price : ");
            scanf("%d",&tamil.mov_t_fare);
            printf("\n\t\t\tAvailable ticket : ");
            scanf("%d",&tamil.mov_av_tic);
            printf("\n\t\t\tSeats Booked : ");
            scanf("%d",&tamil.seat_numbers);

            fprintf(fp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
            fprintf(fp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
            fprintf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
            fprintf(fp,"\n_____________________________________________________");
            printf("\n\t\t\tMovie details added successfully....");
            getch();
            printf("\n\t\t\tDo you want to add another....");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t________________________________");
            printf("\n\t\t\tEnter the choice  : ");
            scanf("%d",&m);

            if(m==1){
                fclose(fp);
                goto loop1;
            }else{
                fclose(fp);
                goto hloop;
            }
            break;
        case 2:
            retval=view_tamil_movie(2);
            if(retval==1){
                goto hloop;
            }
            break;
        case 3:
            loop2:
            system("cls");
            printf("\n\t\t\t=====Delete Tamil Movies=====\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter name of movie   :");
            scanf("%s",i_mov_name);

            if(strcmp(i_mov_name,"1")==0){
                goto hloop;
            }
            fp=fopen("tamil_movie.txt","r");
            temp=fopen("temp.txt","w");

            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&tamil.mov_t_fare,&tamil.mov_av_tic,&tamil.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                system("cls");
                printf("\n\t\t\t=====Delete Tamil Movies=====\n");
                if(strcmp(tamil.mov_name,i_mov_name)==0){
                    found=1;
                    printf("\n\t\t\t**=======Tamil Movies=======**\n");
                    printf("\n\t\t\tMovie name         : %s",tamil.mov_name);
                    printf("\n\t\t\tTheater name       : %s",tamil.mov_theater);
                    printf("\n\t\t\tDate               : %s",tamil.mov_date);
                    printf("\n\t\t\tTiming             : %s",tamil.mov_time);
                    printf("\n\t\t\tTicket price       : %d",tamil.mov_t_fare);
                    printf("\n\t\t\tAvailable tickets  : %d",tamil.mov_av_tic);
                    printf("\n\t\t_____________________________________________");

                    printf("\n\t\t\tAre sure want to Delete movie details");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\t\t\t3. Next");
                    printf("\n\t\t_____________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==1){
                        strcpy(i_mov_name,"dummy");
                        printf("\n\t\t\tMovie deleted successfully....");
                        getch();
                    }else if(m==2){
                        strcpy(i_mov_name,"dummy");
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }else{
                        found=2;
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }
                }else{
                   fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                   fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                   fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                   fprintf(temp,"\n_____________________________________________________");
                }
            }
            if(found==0 || found==2){
                printf("\n\t\t\tNo movie name found as %s",i_mov_name);
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\t1. Search again");
                printf("\n\t\t\t2. Back");
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\tEnter the choice   :");
                scanf("%d",&c);

                if(c==1){
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("tamil_movie.txt");
                    rename("temp.txt","tamil_movie.txt");
                    goto loop2;
                }else{
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("tamil_movie.txt");
                    rename("temp.txt","tamil_movie.txt");
                    goto hloop;
                }
            }else{
                found=0;
                fclose(fp);
                fclose(temp);
                remove("tamil_movie.txt");
                rename("temp.txt","tamil_movie.txt");
                goto hloop;
            }
            break;
        default:
            printf("\n\t\t\tPlease Enter a valid input....");
            getch();
            goto hloop;
    }
    getch();

    return 1;
}

int admin_holly_movie()
{
    struct movie holly;
    FILE *fp,*temp;
    int n,m,c,found=0;
    char i_mov_name[20];

    hloop:
    system("cls");
    printf("\n\t\t\t=====Admin Hollywood Movies=====\n");
    printf("\n\t\t\t1. Add Movies");
    printf("\n\t\t\t2. View Movies");
    printf("\n\t\t\t3. Delete Movies");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t______________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    if(n==4){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            fp=fopen("holly_movie.txt","a");

            system("cls");
            printf("\n\t\t\t=====Add Hollywood Movies=====\n");
            printf("\n\t\t\tMovie name   : ");
            scanf("%s",holly.mov_name);
            printf("\n\t\t\tTheater name : ");
            scanf("%s",holly.mov_theater);
            printf("\n\t\t\tMovie Date   : ");
            scanf("%s",holly.mov_date);
            printf("\n\t\t\tMovie Time   : ");
            scanf("%s",holly.mov_time);
            printf("\n\t\t\tTicket price : ");
            scanf("%d",&holly.mov_t_fare);
            printf("\n\t\t\tAvailable ticket : ");
            scanf("%d",&holly.mov_av_tic);
            printf("\n\t\t\tSeats Booked : ");
            scanf("%d",&holly.seat_numbers);

            fprintf(fp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
            fprintf(fp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
            fprintf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
            fprintf(fp,"\n_____________________________________________________");
            printf("\n\t\t\tMovie details added successfully....");
            getch();
            printf("\n\t\t\tDo you want to add another....");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t________________________________");
            printf("\n\t\t\tEnter the choice  : ");
            scanf("%d",&m);

            if(m==1){
                fclose(fp);
                goto loop1;
            }else{
                fclose(fp);
                goto hloop;
            }
            break;
        case 2:
            retval=view_holly_movie(2);
            if(retval==1){
                goto hloop;
            }
            break;
        case 3:
            loop2:
            system("cls");
            printf("\n\t\t\t=====Delete Hollywood Movies=====\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter name of movie   :");
            scanf("%s",i_mov_name);

            if(strcmp(i_mov_name,"1")==0){
                goto hloop;
            }
            fp=fopen("holly_movie.txt","r");
            temp=fopen("temp.txt","w");

            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&holly.mov_t_fare,&holly.mov_av_tic,&holly.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                system("cls");
                printf("\n\t\t\t=====Delete Hollywod Movies=====\n");
                if(strcmp(holly.mov_name,i_mov_name)==0){
                    found=1;
                    printf("\n\t\t\t**=======Hollywood Movies=======**\n");
                    printf("\n\t\t\tMovie name         : %s",holly.mov_name);
                    printf("\n\t\t\tTheater name       : %s",holly.mov_theater);
                    printf("\n\t\t\tDate               : %s",holly.mov_date);
                    printf("\n\t\t\tTiming             : %s",holly.mov_time);
                    printf("\n\t\t\tTicket price       : %d",holly.mov_t_fare);
                    printf("\n\t\t\tAvailable tickets  : %d",holly.mov_av_tic);
                    printf("\n\t\t_____________________________________________");

                    printf("\n\t\t\tAre sure want to Delete movie details");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\t\t\t3. Next");
                    printf("\n\t\t_____________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==1){
                        strcpy(i_mov_name,"dummy");
                        printf("\n\t\t\tMovie deleted successfully....");
                        getch();
                    }else if(m==2){
                        strcpy(i_mov_name,"dummy");
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }else{
                        found=2;
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }
                }else{
                   fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                   fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                   fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                   fprintf(temp,"\n_____________________________________________________");
                }
            }
            if(found==0 || found==2){
                printf("\n\t\t\tNo movie name found as %s",i_mov_name);
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\t1. Search again");
                printf("\n\t\t\t2. Back");
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\tEnter the choice   :");
                scanf("%d",&c);

                if(c==1){
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("holly_movie.txt");
                    rename("temp.txt","holly_movie.txt");
                    goto loop2;
                }else{
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("holly_movie.txt");
                    rename("temp.txt","holly_movie.txt");
                    goto hloop;
                }
            }else{
                found=0;
                fclose(fp);
                fclose(temp);
                remove("holly_movie.txt");
                rename("temp.txt","holly_movie.txt");
                goto hloop;
            }
            break;
        default:
            printf("\n\t\t\tPlease Enter a valid input....");
            getch();
            goto hloop;
    }
    getch();

    return 1;
}

int admin_sports_event()
{
    int n,m,c;
    char team1[20],team2[20],venue[20],date[20],time[10],price[10];

    hloop:
    system("cls");
    printf("\n\t\t\t=====Sports=====\n");
    printf("\n\t\t\t1. Football");
    printf("\n\t\t\t2. Cricket");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t\t_____________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);
    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop:
            system("cls");
            printf("\n\t\t\t=====Football Sports=====\n");
            printf("\n\t\t1. ISL League");
            printf("\n\t\t2. Premier league");
            printf("\n\t\t3. chennai league");
            printf("\n\t\t4. Back");
            printf("\n\t\t_________________________________");
            printf("\n\t\tEnter the choice   :");
            scanf("%d",&m);
            switch(m){
                case 1:
                    retval=admin_isl();
                    if(retval==1){
                        goto loop;
                    }
                    break;
                case 2:
                    if(retval==1){
                        goto hloop;
                    }
                    break;
                case 3:
                    if(retval==1){
                        goto hloop;
                    }
                    break;
                case 4:
                    goto hloop;
                default:
                    printf("");
            }
            break;
        default:
            printf("\n\t\t\tInvalid input....");
            getch();
            goto hloop;

    }
    return 0;
}

int admin_isl()
{
    struct sports isl;
    FILE *fp,*temp;
    int n,m,c,found=0,num=0;
    char i_team1[20],i_team2[20];

    hloop:
    system("cls");
    printf("\n\t\t\t=====ISL League=====\n");
    printf("\n\t\t\t1. Add Matches ");
    printf("\n\t\t\t2. View Matches");
    printf("\n\t\t\t3. Delete Matches");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t_______________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&m);

    if(m==4){
        return 1;
    }

    switch(m){
        case 1:
            fp=fopen("isl_book.txt","a");
            loop:
            system("cls");
            printf("\n\t\t\t=====Add ISL Matches=====\n");
            printf("\n\t\t\t1. Team 1        :");
            scanf("%s",isl.team1);
            printf("\n\t\t\t2. Team 2        :");
            scanf("%s",isl.team2);
            printf("\n\t\t\t3. Venue         :");
            scanf("%s",isl.venue);
            printf("\n\t\t\t4. Date          :");
            scanf("%s",isl.date);
            printf("\n\t\t\t5. Time          :");
            scanf("%s",isl.time);
            printf("\n\t\t\t6. Ticket fare   :");
            scanf("%d",&isl.t_fare);
            printf("\n\t\t\t7. Available Tickets :");
            scanf("%d",&isl.av_tic);
            printf("\n\t\t\t8. Seats Booked :");
            scanf("%d",&isl.seat_numbers);

            fprintf(fp,"\n Match  %s vs %s",isl.team1,isl.team2);
            fprintf(fp,"\n Venue        : %s",isl.venue);
            fprintf(fp,"\n Date         : %s",isl.date);
            fprintf(fp,"\n Time         : %s",isl.time);
            fprintf(fp,"\n Ticket fare  : %d",isl.t_fare);
            fprintf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
            fprintf(fp,"\n_________________________________");

            system("cls");
            printf("\n\t\t_________________________________________________");
            printf("\n\n\t\t\tDo you want to add another...");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t_______________________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&n);
            if(n==1){
                goto loop;
            }else{
                fclose(fp);
                goto hloop;
            }
            break;
        case 2:
            retval=view_isl(2);
            if(retval==1){
                goto hloop;
            }
            break;
        case 3:
            loop1:
            system("cls");
            printf("\n\t\t\t=====Delete ISL Matches=====\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter team 1 name    :");
            scanf("%s",i_team1);

            if(strcmp(i_team1,"1")==0){
                goto hloop;
            }
            printf("\n\t\t\tEnter team 2 name    :");
            scanf("%s",i_team2);

            fp=fopen("isl_book.txt","r");
            temp=fopen("temp.txt","w");

            while(fscanf(fp,"\n Match  %s vs %s",isl.team1,isl.team2)!= EOF){
                fscanf(fp,"\n Venue        : %s",isl.venue);
                fscanf(fp,"\n Date         : %s",isl.date);
                fscanf(fp,"\n Time         : %s",isl.time);
                fscanf(fp,"\n Ticket fare  : %d",&isl.t_fare);
                fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&isl.av_tic,&isl.seat_numbers);
                fscanf(fp,"\n_________________________________");

                system("cls");
                printf("\n\t\t\t=====Delete ISL Matches=====\n");
                 num++;
                 if ((strcmp(i_team1, isl.team1) == 0 && strcmp(i_team2, isl.team2) == 0) || (strcmp(i_team1, isl.team2) == 0 && strcmp(i_team2, isl.team1) == 0)) {
                    found=1;
                    printf("\n\t\t%d.        Match   %s vs %s",num,isl.team1,isl.team2);
                    printf("\n\t\t\t  Venue       : %s stadium",isl.venue);
                    printf("\n\t\t\t  Date        : %s",isl.date);
                    printf("\n\t\t\t  Time        : %s",isl.time);
                    printf("\n\t\t\t  Ticket fare  : %d",isl.t_fare);
                    printf("\n\t\t______________________________________\n");

                    printf("\n\t\t\tAre you sure want to delete....");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\t\t\t3. Next");
                    printf("\n\t\t_______________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&n);

                    if(n==1){
                        strcpy(i_team1,"dummy");
                        printf("\n\t\t\t Match %s vs %s deleted successfully...",isl.team1,isl.team2);
                        getch();
                    }else if(n==2){
                        strcpy(i_team1,"dummy");
                        fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                        fprintf(temp,"\n Venue        : %s",isl.venue);
                        fprintf(temp,"\n Date         : %s",isl.date);
                        fprintf(temp,"\n Time         : %s",isl.time);
                        fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                        fprintf(temp,"\n_________________________________");
                    }else{
                        fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                        fprintf(temp,"\n Venue        : %s",isl.venue);
                        fprintf(temp,"\n Date         : %s",isl.date);
                        fprintf(temp,"\n Time         : %s",isl.time);
                        fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                        fprintf(temp,"\n_________________________________");
                        found=2;
                    }

                 }else{
                    fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                    fprintf(temp,"\n Venue        : %s",isl.venue);
                    fprintf(temp,"\n Date         : %s",isl.date);
                    fprintf(temp,"\n Time         : %s",isl.time);
                    fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                    fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                    fprintf(temp,"\n_________________________________");
                }
            }

            if(found==0 || found==2){
                printf("\n\t\t\tNo Matches found as %s vs %s",i_team1,i_team2);
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\t1. Search again");
                printf("\n\t\t\t2. Back");
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\tEnter the choice   :");
                scanf("%d",&m);

                if(m==1){
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("isl_book.txt");
                    rename("temp.txt","isl_book.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("isl_book.txt");
                    rename("temp.txt","isl_book.txt");
                    goto hloop;
                }
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("isl_book.txt");
                rename("temp.txt","isl_book.txt");
                goto hloop;
            }
            break;
        default:
            printf("\n\t\t\tplease Enter a valid Input....");
            getch();
            goto hloop;
    }
    return 1;
}

