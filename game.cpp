int columnZero(char matrix[5][5])
{
	for (int i = 4; i >= 0; i--)
	{
		if (matrix[i][0] == '/')
		{
			return i;
			break;
		}
	}
	return -1;
}

int columnOne(char matrix[5][5])
{
	for (int i = 4; i >= 0; i--)
	{
		if (matrix[i][1] == '/')
		{
			return i;
			break;
		}
	}
	return -1;
}

int columnTwo(char matrix[5][5])
{
	for (int i = 4; i >= 0; i--)
	{
		if (matrix[i][2] == '/')
		{
			return i;
			break;
		}
	}
	return -1;
}

int columnThree(char matrix[5][5])
{
	for (int i = 4; i >= 0; i--)
	{
		if (matrix[i][3] == '/')
		{
			return i;
			break;
		}
	}
	return -1;
}

int columnFour(char matrix[5][5])
{
	for (int i = 4; i >= 0; i--)
	{
		if (matrix[i][4] == '/')
		{
			return i;
			break;
		}
	}
	return -1;
}