#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 64

static int read_positive_minutes(int *minutes) {
    char input[INPUT_SIZE];
    char *end = NULL;
    long value;

    printf("Parking duration in minutes (1-1440): ");
    if (fgets(input, sizeof(input), stdin) == NULL) return 0;
    if (strchr(input, '\n') == NULL && !feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }
    }

    errno = 0;
    value = strtol(input, &end, 10);
    if (end == input || errno == ERANGE || value < 1 || value > 1440) return 0;
    while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') end++;
    if (*end != '\0') return 0;

    *minutes = (int)value;
    return 1;
}

int main(void) {
    int minutes;
    if (!read_positive_minutes(&minutes)) {
        puts("Please enter a whole number of minutes from 1 to 1440.");
        return EXIT_FAILURE;
    }

    int billed_hours = (minutes + 59) / 60;
    int fee = 30 + (billed_hours - 1) * 15;
    int capped = fee > 200;
    if (capped) fee = 200;

    printf("Billed hours: %d\n", billed_hours);
    printf("Parking fee: Rs. %d.00%s\n", fee, capped ? " (daily maximum applied)" : "");
    return EXIT_SUCCESS;
}
