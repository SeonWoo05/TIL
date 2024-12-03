// #include <stdio.h>

// typedef struct student {
//     int id;
//     char *pname;
//     double points;
// } STUD;

// typedef struct student2 {
//     int id;
//     double points;
//     char *pname;
// } STUD2;

// int main(void) {
//     STUD s1 = {1, "Choi", 9.9}; // 순서로 4 4 8 => 4 + 4 + 8 = 16
//     STUD2 s2 = {2, 0.1, "Park"}; // 4 8 4 인데 하나가 8씩이라 8 + 8 + 8 = 24

//     printf("%p, %d\n", &s1, sizeof(s1));
//     printf("%p, %d\n", &s2, sizeof(s2));
//     printf("[s1 id, pname, points]=%p,%p,%p\n", &s1.id,&s1.pname,&s1.points);
//     printf("[s2 id, points, pname]=%p,%p,%p\n", &s2.id,&s2.points,&s2.pname);
//     return 0;
// }



// #include <stdio.h>

// void foo(char *pstr) {
//     printf("4:%d, %d", sizeof(pstr), sizeof(*pstr));
// }

// int main(void) {
//     char msg[] = "123456789";
//     char *pmsg = msg;
//     int n=0, *pn = &n;

//     printf("0:%d\n", sizeof(pn)); // size of a pointer variable
//     printf("1:%d\n", sizeof(msg)); // size of the array 
//     printf("2:%d\n", sizeof(pmsg)); // size of a pointer variable
//     printf("3:%d\n", sizeof(*pmsg)); // size of ?
    
//     foo(msg); // foo(pmsg);
//     return 0;
// }



// #include <stdio.h>
// typedef struct student {
//     int id;
//     char *pname;
//     double points;
// } STUD;

// void stud_printx(STUD s) {
//     printf("[%d:%s] = %lf\n", s.id, s.pname, s.points);
// }

// void stud_print(STUD *ps) {
//     printf("[%d:%s] = %lf\n", ps->id, ps->pname, ps->points);
// }

// int main(void) {
//     STUD s1 = {1, "Choi", 9.9 };
//     STUD s2 = {2, "Park", 0.1 };
    
//     stud_printx(s1);
//     stud_print(&s2);
//     return 0;
// }


// // Time.h 사용법
// #include <stdio.h>
// #include <time.h>

// int main(void) {
//     time_t tnow = time(NULL);
//     struct tm * pnow;
//     pnow = gmtime(&tnow);
    
//     if (pnow != NULL) {
//         printf("Today is %d.%d.%d and it\'s ",
//         pnow->tm_year+1900, pnow->tm_mon+1, pnow->tm_mday);
    
//         switch (pnow->tm_wday) {
//             case 0 : puts("Sunday"); break;
//             case 1 : puts("Monday"); break;
//             case 2 : puts("Tuesday"); break;
//             case 3 : puts("Wednesday"); break;
//             case 4 : puts("Thursday"); break;
//             case 5 : puts("Friday"); break;
//             case 6 : puts("Saturday"); break;
//             default: break;
//         }
//     }
//     return 0;
// }