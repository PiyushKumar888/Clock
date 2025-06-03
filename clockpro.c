#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

int set_formate()
{
    int n;
    printf("enter 1 for 24 hour formate\nenter 2 for 12 hour formate\n");
    scanf("%d", &n);
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 0;
    }
    else
    {
        return 0;
    }
}

void _12formate()
{

    char s[100];
    while (1)
    {
        time_t now = time(NULL);
        struct tm *cur_time = localtime(&now);
        strftime(s, sizeof(s), "%A, %d %B %Y %I:%M:%S %p", cur_time);
        printf("\r%s", s);
        fflush(stdout);
        sleep(1);
    }
}
void _24formate()
{
    char s2[100];

    while (1)
    {
        time_t now = time(NULL);
        struct tm *cur_time = localtime(&now);
        strftime(s2, sizeof(s2), "%A, %d %B %Y %H:%M:%S", cur_time);
        printf("\r%s", s2);
        fflush(stdout);
        sleep(1);
    }
}
void trigger_alarm()
{
    for (int i = 0; i < 60; i++)
    {
        Beep(750, 300);
        sleep(1);
    }
}
int alarm()
{
    char alarm_time[12];
    char current_time[12];
    time_t now;
    struct tm *local;

    printf("Set Alarm Time (Format HH:MM:SS AM/PM): ");
    scanf("%s", alarm_time);

    printf("Alarm set for: %s\n", alarm_time);

    while (1)
    {
        time(&now);
        local = localtime(&now);

        strftime(current_time, sizeof(current_time), "%I:%M:%S %p", local);

        if (!strcmp(current_time, alarm_time) == 0)
        {
            trigger_alarm();
            break;
        }

        sleep(1);
    }

    return 0;
}

void display_menu()
{
    printf("\n---- Choose an Option ----\n");
    printf("1. View Clock\n");
    printf("2. Set Alarm\n");
    printf("3. Exit\n");
    printf("Please enter your choice (1-3): ");
}

int main()
{

    int choice, format;

    while (1)
    {
        display_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Choose clock format:\n");
            format = set_formate();
            if (format == 1)
            {
                _24formate();
            }
            else
            {
                _12formate();
            }
            break;
        case 2:
            alarm();
            break;

        case 3:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
