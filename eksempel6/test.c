
int main(int argc, char *argv[]) {
	if (argc != 3) {
		return 0;
	}
	char *a = argv[0];
	char *b = argv[1];
	char *c = argv[2];
	int t1 = atoi(b);
	int t2 = atoi(c);
	return t1 + t2;
}

