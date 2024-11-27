#include <stdio.h>

char * mystrtok(char *str, char delim) {
    static char *psave = 0;
    char *pstr = 0;

    if (str) psave = str;

    if (psave) {
        str = psave;
        while (*str == delim) str++;
        
        if (*str) {
            pstr = str; // 시작은 pstr

            while (*str && *str != delim) str++; // 끝은 str
        
            if (*str) {
                psave = str + 1; // 정적변수인 psave에 구분자 다음으로 pointer 옮겨두고
                *str = 0; // 구분자를 NULL로 만듦
            }

            else {
                return 0;
            }
        }
    }
}

int main(void) {
    char t[] = ", 123.4, he ll o, 12--,%^&*";
    char *pstr = t; // 보내주는거
    char *string; // 받아오는거

    string = mystrtok(pstr, ',');

    while(string) {
        printf("%s\n", string);
        string = mystrtok(0, ',');
    }

    return 0;
}