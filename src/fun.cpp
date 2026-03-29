// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    if (!str) {
        return 0;
    }

    int counter = 0;
    size_t len = strlen(str);
    bool isWord = false;
    bool hasDigit = false;

    for (size_t i = 0; i <= len; i++) {
        char ch = str[i];
        if (ch == ' ' || ch == '\0') {
            if (isWord && !hasDigit) {
                counter++;
            }
            isWord = false;
            hasDigit = false;
        } else {
            isWord = true;
            if (isdigit(static_cast<unsigned char>(ch))) {
                hasDigit = true;
            }
        }
    }
    return counter;
}

unsigned int faStr2(const char* str) {
    if (!str) {
        return 0;
    }

    int counter = 0;
    size_t len = strlen(str);
    bool firstChar = false;
    bool fail = false;

    for (size_t i = 0; i <= len; i++) {
        char ch = str[i];
        if (ch == ' ' || ch == '\0') {
            if (!fail && firstChar) {
                counter++;
            }
            firstChar = false;
            fail = false;
        } else {
            if (!firstChar) {
                firstChar = true;
                if (!(ch >= 'A' && ch <= 'Z')) {
                    fail = true;
                }
            } else {
                if (!(ch >= 'a' && ch <= 'z')) {
                    fail = true;
                }
            }
        }
    }
    return counter;
}

unsigned int faStr3(const char* str) {
    if (!str) {
        return 0;
    }

    size_t len = strlen(str);
    unsigned int length = 0;
    int Wordcounter = 0;
    unsigned answer = 0;

    for (size_t i = 0; i <= len; i++) {
        char ch = str[i];
        if (ch == '\0') {
            if (Wordcounter != 0) {
                answer = (length + Wordcounter / 2) / Wordcounter;
            } else {
                return 0;
            }
        } else {
            if (ch != ' ') {
                length++;
            } else {
                Wordcounter++;
            }
        }
    }
    return answer;
}
