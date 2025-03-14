if (argc < 2) {
	printf("Usage: bankint <deposit_money> <interest_rate(%)> <term(year(s))>\n");
	printf("Default interest = 1.8%, Default term = 1 year");
	exit(1); // 프로그램 전체를 종료 => 잘못된 상태임
}
else if (argc == 2) {
	deposit = atoi(argv[1]);
}
else if (argc == 3) {
	deposit = atoi(argv[1]);
	rate = atof(argv[2] / 100); // argument 입장에서는 세번째
}
else if (argc == 2) {
	deposit = atoi(argv[1]);
}
else if (argc == 3) {
	deposit = atoi(argv[1]);
	rate = atof(argv[2] / 100);
	term = atoi(argv[3]);
}