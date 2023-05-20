#include <stdio.h>
#include <string.h>

struct details {
    char username[50];
    char password[30];
    char email[50];
    int mobile[15];
};
struct showroom {
    char showroom[50];
    char first_clothe[20];
    char second_clothe[20];
    char third_clothe[20];
    int first, second, third;
};

struct showroom m[10];
struct details s[100];

void signup();
void account_check();
int valid();
void login();
void chart();
void search_by_showroom();
void search_by_clothe();
void clothe_order(int clothe);
void showroom_initialize();
void showroom(int showroom_choice);

int arp = 1, i, j = 0, c = 0, cap = 0,small = 0, special = 0, numbers = 0,success = 0, p, choice, total = 0,n;
int clothe_choice,showroom_choice, search_choice, confirm, choice, clothe, showroom_id;
char temp_name[100], password1[100],password2[100], temp_email[100], temp_mobile[100];

int main()
{
    while (1) {
        printf("**!!**!!**Welcome To Shopping Zone**!!**!!**\n\n");
        printf("\n1)SIGNUP\n2)LOGIN\n3)EXIT\n\n");
        printf("Enter Your choice\n");
        scanf("%d",&choice);
        switch (choice) {
        case 1:
            signup();
            break;

        case 2: login();
            break;

        case 3: exit(0);
        default: printf("\nPlease Enter valid choice\n");
            break;
        }
    }
}

void signup()
{
    printf("Enter Your name\n");
    scanf("%s",temp_name);

    printf("Enter Your Email\n");
    scanf("%s",temp_email);

    printf("Enter Password\n");
    scanf("%s",password1);

    printf("Confirm Password\n");
    scanf("%s",password2);

    printf("Enter Your Mobile Number\n");
    scanf("%s",temp_mobile);

    p = valid();
    if (p == 1)
        account_check();
}

int valid()
{
    for (i = 0; temp_name[i] != '\0'; i++)
        {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')|| (temp_name[i] >= 'A'&& temp_name[i] <= 'Z')))
            {
            printf("\nPlease Enter the Valid name\n");
            arp = 0;
            break;
        }
    }
    if (arp == 1) {
        c = 0;
     for (i = 0;temp_email[i] != '\0'; i++)
        {
        if (temp_email[i] == '@' || temp_email[i] == '.')
            c++;
        }
        if (c >= 2 && strlen(temp_email) >= 5)
         {
        if (!strcmp(password1,password2))
         {
        if (strlen(password1) >= 8 && strlen(password1) <= 12)
           {
            cap = 0;
            small = 0;
            numbers = 0;
            special = 0;
            for (i = 0; password1[i] != '\0';i++)
              {
                if (password1[i] >= 'A'&& password1[i] <= 'Z')
                  cap++;
                else if (password1[i] >= 'a'&& password1[i]<= 'z')
                  small++;
                else if (password1[i] >= '0'&& password1[i]<= '9')
                  numbers++;
                else if (password1[i] == '@'|| password1[i] == '&'|| password1[i] == '#'|| password1[i]== '*')
                  special++;
                }
                if (cap >= 1 && small >= 1&& numbers >= 1 && special >= 1)
                {
                if (strlen(temp_mobile) == 11)
                {
                for (i = 0; i < 10; i++)
                {
                if (temp_mobile[i]>= '0'&&temp_mobile[i]<= '9')
                {
                success = 1;
                }
                else
                {
                printf("\n\nPlease Enter Valid Mobile Number\n\n");
                return 0;
                break;
                }
                 }

                if (success == 1)
                return 1;
                }
                else {
                printf("\n\nPlease Enter the 11 digit mobile number\n\n");
                return 0;
                     }
                }

            }
                else {
                printf("\n\nPlease Enter the strong password\n");
                printf("\nYour password must contain at least one uppercase,Lowercase, Number and special character\n\n");
                return 0;
                      }
                }
                else {
                printf("\nYour Password is very short\n ");
                printf("\nLength must between 8 to 12\n\n");
                return 0;
                }
            }
            else {
                printf("\nPassword Not match\n\n");
                return 0;
            }
        }
        else {
            printf("\nPlease Enter Valid Email\n\n");
            return 0;
        }
    }
void account_check()
{
    for (i = 0; i < 100; i++)
        {
        if (!(strcmp(temp_email, s[i].email)&& strcmp(password1,s[i].password))) {
            printf("\n\nAccount already existed ....\n");
            printf("\nPlease Login !!\n\n");
            main();
            break;
        }
    }
    if (i == 100) {
        strcpy(s[j].username, temp_name);
        strcpy(s[j].password, password1);
        strcpy(s[j].email,temp_email);
        strcpy(s[j].mobile,temp_mobile);
        j++;
        printf("\n\n\nAccount successfully created!!\n\n");
    }
}
void login()
{
    printf("\n\nLOGIN\n\n");
    printf("\nEnter Your Email\n");
    scanf("%s", temp_email);
    printf("\nEnter Your Password\n");
    scanf("%s", password1);
    for (i = 0; i < 100; i++) {
        if (!strcmp(s[i].email, temp_email)) {
            if (!strcmp(s[i].password, password1)) {
                printf("\n\n!!Welcome %s!!\n, ", s[i].username);
                printf("\nYour are successfully logged in....\n\n");
                printf("\nWe Provide two ways of clothe search\n");
                printf("\n1.Search By Showrooms name for Clothes list\n2. Search by Clothes\n");
                printf("\n3. Exit\n");
                printf("\nPlease Enter your choice\n");
                scanf("%d",&search_choice);
                switch (search_choice)
                 {
                case 1: search_by_showroom();
                    break;

                case 2: search_by_clothe();
                    break;

                case 3: exit(0);
                default: printf("\nPlease Enter the valid choice\n\n");
                    break;
                }
                break;
            }
            else {
                printf("\n\nInvalid Password!!! ");
                printf("Please Enter the correct password\n\n");
                main();
                break;
            }
        }
        else {
            printf("\n\nAccount doesn't exist ");
            printf("\n\nPlease sign up!!\n\n");
            main();
            break;
        }
    }
}
void showroom_initialize()
{
    strcpy(m[1].showroom, "ARP's style");
    strcpy(m[1].first_clothe, "Men's Suit");
    strcpy(m[1].second_clothe, "Skin Jeans");
    strcpy(m[1].third_clothe, "POLO t-shirt");
    m[1].first = 5000 ;
    m[1].second = 1200 ;
    m[1].third = 350 ;

    strcpy(m[2].showroom, "Sharmin's Art for ladies");
    strcpy(m[2].first_clothe, "Silk shari");
    strcpy(m[2].second_clothe, "Salwar Kamij");
    strcpy(m[2].third_clothe, "ladies Jeans");
    m[2].first = 4000 ;
    m[2].second = 1500 ;
    m[2].third = 900 ;
    strcpy(m[3].showroom, "Saleh's design");
    strcpy(m[3].first_clothe, "Punjabi");
    strcpy(m[3].second_clothe, "Formal Pant");
    strcpy(m[3].third_clothe, "Shirt");
    m[3].first = 2500;
    m[3].second = 1000;
    m[3].third = 700;
}
void search_by_showroom()
{
    showroom_initialize();
    printf("\n\nPlease Choose the Showrooms\n");
    printf("\n\n1) %s\n2) %s\n3) %s",m[1].showroom,m[2].showroom, m[3].showroom);
    printf("\n4) Exit\n ");
    printf("\nPlease select showroom\n");
    scanf("%d", &showroom_choice);
    if (showroom_choice > 4) {
        printf("\nPlease Enter the valid choice\n\n");
        search_by_showroom();
    }
    else if (showroom_choice == 4)
        return;
    else
        showroom(showroom_choice);
}
void showroom(int showroom_choice)
{
total = 0;
while (1) {
printf("\n\nList of Clothes available in %s\n\n1) %s\ntaka: %d\n2)",m[showroom_choice].showroom,m[showroom_choice].first_clothe,m[showroom_choice].first);
printf("%s\ntaka: %d\n3) %s\ntaka: %d\n4)",m[showroom_choice].second_clothe,m[showroom_choice].second,m[showroom_choice].third_clothe,m[showroom_choice].third);
printf("Chart\n5) Exit\n");
printf("\nPlease Enter Your Choice\n");
scanf("%d", &clothe_choice);
    if (clothe_choice == 1) {
        printf("\nPlease Enter the Count of %s\n",m[showroom_choice].first_clothe);
        scanf("%d", &n);
        total = total+ (n * m[showroom_choice].first);
        }
    else if (clothe_choice == 2) {
        printf("\nPlease Enter the Count of %s\n",m[showroom_choice].second_clothe);
        scanf("%d", &n);
        total = total + (n * m[showroom_choice].second);
        }
    else if (clothe_choice == 3) {
        printf("\nPlease Enter the Count of %s\n",m[showroom_choice].third_clothe);
        scanf("%d", &n);
        total = total + (n * m[showroom_choice].third);
        }
    else if (clothe_choice == 4) {
            chart();
        }
    else if (clothe_choice == 5) {
            search_by_showroom();
        }
        else {
            printf("\nPlease Enter the valid Choice\n\n");
        }
    }
}
void search_by_clothe()
{
total = 0;
showroom_initialize();

while (1) {
    printf("\n\nPlease choose the clothe\n");
    printf("\n1) %s\n%d\n2) %s\n%d",m[1].first_clothe, m[1].first,m[1].second_clothe, m[1].second);
    printf("\n3) %s\n%d\n4) %s\n%d\n",m[1].third_clothe, m[1].third,m[2].first_clothe, m[2].first);
    printf("5) %s\n%d\n6) %s\n%d\n",m[2].second_clothe, m[2].second,m[2].third_clothe, m[2].third);
    printf("7) %s\n%d\n8) %s\n%d\n",m[3].first_clothe, m[3].first,m[3].second_clothe, m[3].second);
    printf("9) %s\n%d\n10) Cart\n",m[3].third_clothe,m[3].third);
    printf("11) Exit");
    printf("\nPlease Enter Your Choice : ");
    scanf("%d", &clothe);
    if (clothe > 10) {
        printf("Please Enter the valid choice\n\n");
        search_by_clothe();
        }
        else if (clothe == 10)
            chart();
        else if (clothe == 11)
            return;
        else
            clothe_order(clothe);
    }
}
void clothe_order(int clothe)
{
    if (clothe >= 1 && clothe <= 3)
        showroom_id = 1;
    else if (clothe >= 4 && clothe <= 6)
        showroom_id = 2;
    else
        showroom_id = 3;
    if ((clothe % 3) == 1) {
        printf("Please Enter the Count of %s\n",m[showroom_id].first_clothe);
        scanf("%d", &n);
        total = total + (n * m[showroom_id].first);
    }
    else if ((clothe % 3) == 2) {
        printf("Please Enter the Count of %s\n",m[showroom_id].second_clothe);
        scanf("%d", &n);
        total = total + (n * m[showroom_id].second);
    }
    else if ((clothe % 3) == 0) {
        printf("Please Enter the Count of %s\n",m[showroom_id].third_clothe);
        scanf("%d", &n);
        total = total + (n * m[showroom_id].third);
    }
}
void chart()
{
    printf("\n\nChart!!\n");
    printf("\nYour Total Order Amount is %d\n", total);
    printf("\n\nDo You Want to order (yes=1/no=0):");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\n\nThank You for your order!!");
        printf("Your Clothe is on the way....\n\n");
        printf("Welcome again!!\n\n");
        return;
    }
    else if (choice == 0) {
        printf("Do You want to exit (1) or Go back (0)");
        scanf("%d", &confirm);
        if (confirm == 1) {
            printf("\n\nOops!!! Your order is Canceled!!\n");
            printf("Exiting..");
            printf("\n\nThank You visit again in our Showroom!!\n\n");
            return;
        }
        else {
            printf("\n\nThank You\n\n");
            login();
        }
    }
    else {
        printf("\n\nPlease Enter the correct choice\n\n");
        chart();
    }
}
