#include <stdio.h>
#include <time.h>

// Function to find the day of the week for a given date
int day_of_week(int day, int month, int year) {
    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    mktime(&date);

    return date.tm_wday;
}

// Function to print the calendar for a given month and year
void print_calendar(int month, int year) {
    int day, days_in_month, current_day;

    // Array to store the names of the days
    char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    // Array to store the number of days in each month
    int days_in_month_arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month_arr[2] = 29; // February has 29 days in a leap year
    }

    // Calculate the day of the week for the first day of the month
    current_day = day_of_week(1, month, year);

    // Print the header
    printf("Calendar for %d-%02d\n", year, month);
    for (int i = 0; i < 7; i++) {
        printf("%s\t", days[i]);
    }
    printf("\n");

    // Print leading spaces
    for (int i = 0; i < current_day; i++) {
        printf("\t");
    }

    // Print the days of the month
    days_in_month = days_in_month_arr[month];
    for (day = 1; day <= days_in_month; day++) {
        printf("%d\t", day);

        // Move to the next line after Saturday
        if (++current_day > 6) {
            current_day = 0;
            printf("\n");
        }
    }

    // Print a new line at the end
    printf("\n");
}

int main() {
    int month, year;

    // Get input for month and year
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    // Check for valid input
    if (month < 1 || month > 12) {
        printf("Invalid month input.\n");
        return 1;
    }

    // Print the calendar
    print_calendar(month, year);

    return 0;
}
