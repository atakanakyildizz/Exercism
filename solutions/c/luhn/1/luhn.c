#include "luhn.h"
#include <string.h>
#include <ctype.h> 

bool luhn(const char *num) {
    int length = strlen(num);
    int sum = 0;
    int digit_count = 0;

    for (int i = length - 1; i >= 0; i--) {
        char c = num[i];

        if (c == ' ') {
            continue;
        }

        if (!isdigit(c)) {
            return false;
        }

        int digit = c - '0';


        digit_count++;

        if (digit_count % 2 == 0) {
            int doubled = digit * 2;
            if (doubled > 9) {
                doubled -= 9;
            }
            sum += doubled;
        } else {
            sum += digit;
        }
    }

    if (digit_count < 2) {
        return false;
    }

    return (sum % 10 == 0);
}
