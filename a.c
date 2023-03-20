void	adr(int *a)
{
	*a = 1;
}

int main(int argc, char const *argv[])
{
	int i = 7;

	adr(&i);

	printf("%d\n", i);
	return 0;
}
