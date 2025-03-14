// #include <stdio.h> 
// int add(int n) {
// 	int sum = 0;
// 	sum += n;
// 	return sum;
// }

// int main(void) {
// 	int ns[] = {1,2,3,4,5,-1};
// 	int i=0, sum;

// 	while (ns[i] > 0) {
// 		sum = add(ns[i++]);
// 	}
// 	printf("The sum is %d\n", sum);

// 	return 0;
// }

// #include <stdio.h> 
// int add(int n) {
// 	static int sum = 0;
// 	sum += n;
// 	return sum;
// }

// int main(void) {
// 	int ns[] = {1,2,3,4,5,-1};
// 	int i=0, sum;

// 	while (ns[i] > 0) {
// 		sum = add(ns[i++]);
// 	}
// 	printf("The sum is %d\n", sum);

// 	return 0;
// }

// #include <stdio.h> 
// #define END_MARK		-1
// int sum_int_array(int nums[]) {
// 	int i=0, sum=0;
// 	while (nums[i] != END_MARK) {
// 		sum += nums[i];
// 		nums[i++] = 5;
// 	}
// 	return sum;
// }
// int main(void) {
// 	int ns[4] = {1,2,3,END_MARK};

// 	int sum = sum_int_array(ns);

// 	printf("ns [%d, %d, %d]\n",
// 		ns[0],ns[1],ns[2]);

// 	printf("Sum of ns:%d\n", sum);
// 	return 0;
// }

// #include <stdio.h> 
// #include <math.h>
// int main(void) {
// 	double x = 9.0/5;
// 	double y = 6.0/5;
// 	double z = -6.0/5;

// 	printf("ceil(%.2lf)=%.0lf, ceil(%.2lf)=%.0lf, ceil(%.2lf)=%.0lf\n",
// 			x,ceil(x),y,ceil(y),z,ceil(z));
// 	printf("floor(%.2lf)=%.0lf, floor(%.2lf)=%.0lf, floor(%.2lf)=%.0lf\n",
// 			x,floor(x),y,floor(y),z,floor(z));
// 	printf("round(%.2lf)=%.0lf, round(%.2lf)=%.0lf, round(%.2lf)=%.0lf\n",
// 			x,round(x),y,round(y),z,round(z));
// 	printf("trunc(%.2lf)=%.0lf, trunc(%.2lf)=%.0lf, trunc(%.2lf)=%.0lf\n",
// 			x,trunc(x),y,trunc(y),z,trunc(z));

// 	return 0;
// }

// #include <stdio.h> 

// int foo1(char *pstr) {
// 	char *pcur = pstr;
// 	while (*pcur++)
// 		;
// 	return (pcur-pstr); // 포인터끼리의 뺄셈은 인덱스 차이를 반환함
// }

// int foo2(char *pstr) {
// 	char *pcur = pstr;
// 	while (*pcur)
// 		pcur++;
// 	return (pcur-pstr); 
// }

// int main(void) {
// 	char str1[] = "12345678";
// 	char str2[] = "1234";
	
// 	printf("foo1(str1) = %d, foo2(str1) = %d\n", foo1(str1), foo2(str1));
// 	printf("foo1(str2) = %d, foo2(str2) = %d\n", foo1(str2), foo2(str2));
	
// 	return 0;	
// }

#include <stdio.h>
typedef struct student {
	int id;
	char *pname;
	double points;
} STUD;

void stud_print(STUD *ps);
void stud_swap(STUD *a, STUD *b);
STUD * stud_get_last(STUD *ps_array);
int stud_compare_points(STUD *ps1, STUD *ps2);

void stud_bubble_sort(STUD * pnucse) {
	STUD *last = stud_get_last(pnucse);

	for (STUD *p = pnucse; p < last; p++) {
		for (STUD *q = pnucse; q < last - p; q++) {
			if (stud_compare_points(q,q+1) < 0) {
				stud_swap(q,q+1);
			}
		}
	}

	
}
void set_values_of_pnucse(STUD * pnucse, int test) {
	STUD pnucse1[] = { {1, "Choi", 3.9}, {2, "Park", 2.1},
		{3, "Kim", 9.0 }, {4, "Lee", 3.5 }, {5, "Moon", 4.5 },
		{6, "Kang", 2.0 }, {7, "Jeon", 8.9 }, {-1, NULL, 0 } };
	STUD pnucse2[] = { {1, "Choi", 2.5}, {2, "Park", 4.1},
		{3, "Kim", 1.0 }, {4, "Lee", 8.0 }, {5, "Moon", 8.5 },
		{6, "Kang", 5.0 }, {7, "Jeon", 3.9 }, {-1, NULL, 0 } };
	STUD *pnew = (test%2) ? pnucse1 : pnucse2;
	int i=0;
	
	while (i<7) {
		pnucse[i] = pnew[i];
		i++;
	}
}
int main(void) {
	STUD pnucse[] = { {1, "Choi", 9.9}, {2, "Park", 0.1},
		{3, "Kim", 5.0 }, {4, "Lee", 3.0 }, {5, "Moon", 9.5 },
		{6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, NULL, 0 } };
		
	STUD * ps_cur = pnucse;
	int test_id = 0;
	scanf("%d",&test_id);
	if (test_id) set_values_of_pnucse(pnucse, test_id); 
	
	stud_bubble_sort(pnucse);
	
	while (ps_cur->id > 0)
		stud_print(ps_cur++);	

	return 0;
}
void stud_print(STUD *ps) {
    printf("[%d:%s] = %lf\n", ps->id, ps->pname, ps->points);	
}

void stud_swap(STUD *a, STUD *b) {
    STUD buf;
    buf = *a;
    *a = *b;
    *b = buf;
}

STUD * stud_get_last(STUD *ps_array) {
	while (ps_array->id >= 0) {
		ps_array++;
	}
	return --ps_array;
}

int stud_compare_points(STUD *ps1, STUD *ps2) {
	int ret = 1;
	if (ps1->points < ps2->points)
		ret = -1;
	else if (ps1->points == ps2->points)
		ret = 0;
	return ret;
}