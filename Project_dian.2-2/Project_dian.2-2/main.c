#define _CRT_SECURE_NO_WARNINGS 1
#define x 100
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[x] = "0";
	char grand[x];
	int number[x];
	int price[x];
	int amount[x] = { 0,0,0,0,0,0,0,0 };
	int amo_unt[x][2];
	int i = 0;
	int w = 0;
	int t = 0;


	char str2[x] = "0";
	char grand2[x];
	int number2[x];
	int amount2[x] = { 0,0,0,0,0,0,0,0 };
	int j = 1;
	int k = 0;
	int price2[x] = { 0,0,0,0,0,0,0,0,0 };
	int p = 1;
	int amo_unt2[x][2];
	int sum_price = 0;






	int sum_pay = 0;
	int once_pay[x] = { 0,0,0,0,0,0,0 };
	int back = 0;
	int r = 1;



	char str3[x] = "0";
	int BACK_amount = 0;



	char str4[x] = "0";


	char str5[x] = "0";




	for (; back >= 0;)
	{
		printf("��ܰ��ʾ��������Ʒ�ơ���ţ�1-5�ţ�(ֻ����һλ��)���۸�ֻ����һλ����������ʱ����һ���ո����������������ֻ��Ҫ�س���,ÿ������ͨ����Ų�����ͬ(����ͬ���Զ���Ϊ�������)�������ȫ�������ͨ������END������ǰ����\n");//���������ڱ��������벻ͬ����ʱ��һ���ո������ֻҪ����һ���ո�˴���Ͳ����������У���Ҫ�޸Ĵ��룩
		rewind(stdin);
		gets(str);
	gt9:for (i = 1; strcmp(str, "END") != 0;)//Ϊ��ʹ��һ������Ҳ���ж������Ƿ���࣬��������Ϊi=1
	{

		grand[i] = str[0];
		number[i] = str[2] - 48;
		price[i] = str[4] - 48;
		amo_unt[i][0] = str[6];
		amo_unt[i][1] = str[7];

		if (amo_unt[i][1] == 0)
		{
			amount[i] = amo_unt[i][0] - 48;
		}
		else
		{
			amount[i] = (amo_unt[i][0] - 48) * 10 + amo_unt[i][1] - 48;

		}
		rewind(stdin);//������ջ�����
		for (t = 1; number[i] != number[t] && i > t;)
		{
			t++;
		}
		if (amount[i] > 50 || (str[8] >= 48 && str[8] <= 57))
		{
			printf("�����������࣬�˴�Ͷ����Ч\n");
			rewind(stdin);

			if (number[i] > 5 || number[i] < 1||str[3]!=32||t<i)
			{
				printf("ͨ�����������󣬴˴β�����Ч\n");
				rewind(stdin);
				if (price[i] > 9 || price[i] < 1)
				{
					printf("������ﵥ�۴��󣬴˴β�����Ч\n");
					rewind(stdin);
				}
			}
			else if (price[i] > 9 || price[i] < 1)
			{
				printf("������ﵥ�۴��󣬴˴β�����Ч\n");
				rewind(stdin);
			}
			memset(str, 0, sizeof(str));
			i = i - 1;

		}
		else if (number[i] > 5 || number[i] < 1 || str[3] != 32 || t < i)
		{
			printf("ͨ�����������󣬴˴β�����Ч\n");
			rewind(stdin);

			if (price[i] > 9 || price[i] < 1)
			{
				printf("������ﵥ�۴��󣬴˴β�����Ч\n");
				rewind(stdin);
			}
			i = i - 1;
		}
		else if (price[i] > 9 || price[i] < 1)
		{
			printf("������ﵥ�۴��󣬴˴β�����Ч\n");
			rewind(stdin);
			i = i - 1;
		}
		else
		{
		}

	gt2:gets(str);
		if (strcmp(str, "BACK") == 0)
		{
			if (BACK_amount < 3)
			{
				printf("�ѳ�����һ������\n");
				rewind(stdin);
				amount[i] = 0;
				i--;
				BACK_amount += 1;

				rewind(stdin);
			gt1:gets(str);
			}
			else
			{
				printf("�����������㣬�˴β�����Ч\n");
				rewind(stdin);
			}
		}
		else
		{
			BACK_amount = 0;
		}

		for (; strcmp(str, "END") != 0;)
		{

			i++;

			if (i >= 6)//i=1Ϊ��ʼ����˱�����6Ϊ�߽�
			{
				printf("û�ж���ͨ����,���һ�ε�������Ч\n");
				rewind(stdin);
				break;
			}
			else
			{
				if (strcmp(str, "BACK") == 0)
				{
					if (BACK_amount < 3)
					{
						printf("�ѳ�����һ��\n");
						i = i - 1;
						BACK_amount += 1;
						amount[i] = 0;
						rewind(stdin);
					}
					else
					{
						printf("�����������㣬�˴β�����Ч���벻Ҫ����������BACK\n");
						rewind(stdin);
						i = i - 2;
					}
					gets(str);

				}
				else
				{
					BACK_amount = 0;
					grand[i] = str[0];
					number[i] = str[2] - 48;
					price[i] = str[4] - 48;
					amo_unt[i][0] = str[6];//������������ַ���Ӧ��ASCII��ֵ
					amo_unt[i][1] = str[7];

					if (amo_unt[i][1] == 0)
					{
						amount[i] = amo_unt[i][0] - 48;
					}
					else
					{
						amount[i] = (amo_unt[i][0] - 48) * 10 + amo_unt[i][1] - 48;
					}
					for (w = 1; grand[i] != grand[w] && w < i;)
					{
						w++;
					}
					for (t = 1; number[i] != number[t] && i > t;)
					{
						t++;
					}
					if (amount[i] > 50 || (str[8] >= 48 && str[8] <= 57))
					{
						printf("�����������࣬�˴�Ͷ����Ч\n");
						rewind(stdin);

						if (number[i] > 5 || number[i] < 1 || str[3] != 32||t<i)
						{
							printf("ͨ�����������󣬴˴β�����Ч\n");
							rewind(stdin);
							if (str[5] != 32 || price[i] < 1)
							{
								printf("������ﵥ�۴��󣬴˴β�����Ч\n");
								rewind(stdin);
							}
							if (grand[i] == grand[w] && price[i] != price[w])
							{
								printf("ͬ�ֻ���۸�ͳһ\n");
								rewind(stdin);
							}
						}
						else if (str[5] != 32 || price[i] < 1)
						{
							printf("������ﵥ�۴��󣬴˴β�����Ч\n");
							rewind(stdin);
							if (grand[i] == grand[w] && price[i] != price[w])
							{
								printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
								rewind(stdin);
							}

						}
						else if (grand[i] == grand[w] && price[i] != price[w])
						{
							printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
							rewind(stdin);
						}
						amount[i] = 0;
						i = i - 1;
						memset(str, 0, sizeof(str));
						gets(str);
						if (strcmp(str, "BACK") == 0)
						{
							if (BACK_amount < 3)
							{
							printf("�ѳ�����һ��\n");
							rewind(stdin);
							BACK_amount += 1;
							amount[i] = 0;
							i--;
							goto gt2;
						    }
							else
							{
								printf("�����������㣬�˴β�����Ч���벻Ҫ����������BACK\n");
							}
						}
						else
						{
							BACK_amount = 0;
						}

					}
					else if (number[i] > 5 || number[i] < 1 || str[3] != 32||t<i)
					{
						printf("ͨ�����������󣬴˴β�����Ч\n");
						rewind(stdin);


						if (str[5] != 32 || price[i] < 1)
						{
							printf("������ﵥ�۴��󣬴˴β�����Ч\n");
							rewind(stdin);
							if (grand[i] == grand[w] && price[i] != price[w])
							{
								printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
								rewind(stdin);
							}

						}
						else if (grand[i] == grand[w] && price[i] != price[w])
						{
							printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
							rewind(stdin);

						}
						amount[i] = 0;
						i = i - 1;
						gets(str);
						if (strcmp(str, "BACK") == 0)
						{
							if (BACK_amount < 3)
							{
								printf("�ѳ�����һ��\n");
								rewind(stdin);
								BACK_amount += 1;
								amount[i] = 0;
								i--;
								goto gt2;
							}
							else
							{
								printf("�����������㣬�˴β�����Ч���벻Ҫ����������BACK\n");
							}
						}
						else
						{
							BACK_amount = 0;
						}
					}
					else if (str[5] != 32 || price[i] < 1)
					{
						printf("������ﵥ�۴��󣬴˴β�����Ч\n");
						rewind(stdin);
						if (grand[i] == grand[w] && price[i] != price[w])
						{
							printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
							rewind(stdin);

						}
						amount[i] = 0;
						i = i - 1;
						gets(str);
						if (strcmp(str, "BACK") == 0)
						{
							if (BACK_amount < 3)
							{
								printf("�ѳ�����һ��\n");
								rewind(stdin);
								BACK_amount += 1;
								amount[i] = 0;
								i--;
								goto gt2;
							}
							else
							{
								printf("�����������㣬�˴β�����Ч���벻Ҫ����������BACK\n");
							}
						}
						else
						{
							BACK_amount = 0;
						}
					}
					else if (grand[i] == grand[w] && price[i] != price[w])
					{
						printf("ͬ�ֻ���ĵ��۲�ͳһ���˴β�����Ч\n");
						rewind(stdin);
						amount[i] = 0;
						i = i - 1;
						gets(str);
						if (strcmp(str, "BACK") == 0)
						{
							if (BACK_amount < 3)
							{
								printf("�ѳ�����һ��\n");
								rewind(stdin);
								BACK_amount += 1;
								amount[i] = 0;
								i--;
								goto gt2;
							}
							else
							{
								printf("�����������㣬�˴β�����Ч���벻Ҫ����������BACK\n");
							}
						}
						else
						{
							BACK_amount = 0;
						}
					}


					else
					{
						gets(str);
						if (strcmp(str, "BACK") == 0)
						{
							if (BACK_amount < 3)
							{
								printf("�ѳ�����һ������\n");
								amount[i] = 0;
								i = i - 1;
								BACK_amount += 1;
								rewind(stdin);
								goto gt2;
							}
							else
							{
								printf("�����������㣬�˴β�����Ч\n");
								rewind(stdin);
							}
						}
						else
						{
							BACK_amount = 0;
						}
					}
				}
			}

		}
		break;
	}
	memset(str, 0, sizeof(str));
	printf("�����Ż�����\n");
	rewind(stdin);
















	BACK_amount = 0;
gt8:printf("��ʼȡ������\n");
	rewind(stdin);

gt4:gets(str2);
	if (strcmp(str2, "BACK") == 0)
	{
		if (BACK_amount < 3)
		{
			printf("�ѳ�����һ������\n");
			rewind(stdin);
			BACK_amount += 1;
			goto gt2;
		}
		else
		{
			printf("������������\n");
			rewind(stdin);
		}
	}
	else
	{
		BACK_amount = 0;
		goto gt3;

	}

	j = 1;
	p = 1;


gt3:grand2[j] = str2[0];
	number2[j] = str2[2] - 48;
	amo_unt2[j][0] = str2[4];
	amo_unt2[j][1] = str2[5];
	if (amo_unt2[j][1] == 0)
	{
		amount2[j] = amo_unt2[j][0] - 48;
	}
	else
	{
		amount2[j] = (amo_unt2[j][0] - 48) * 10 + amo_unt2[j][1] - 48;
	}

	for (k = 1; (grand2[j] != grand[k] || number2[j] != number[k]) && k < 6;)
	{
		k++;
	}
	if (k == 6)
	{
		printf("�������Ʒ������ͨ���Ų���Ӧ���˴�������Ч\n");
		rewind(stdin);
		amount2[j] = 0;
		j = j - 1;
		if (str2[6] >= 48 && str2[6] <= 57)
		{
			printf("��Ҫ����Ļ����������㣬�˴β�����Ч\n");
			rewind(stdin);
			memset(str2, 0, sizeof(str2));
		}
		gets(str2);
		if (strcmp(str2, "BACK") == 0)
		{
			if (BACK_amount < 3)
			{
				printf("�ѳ�����һ������\n");
				rewind(stdin);
				BACK_amount += 1;
				goto gt2;
			}
			else
			{
				printf("������������\n");
				rewind(stdin);
			}


		}
		else
		{
			BACK_amount = 0;
			goto gt10;
		}
	}
	else if (amount2[j] > amount[k] || (str2[6] >= 48 && str2[6] <= 57))
	{
		printf("��Ҫ����Ļ����������㣬�˴β�����Ч\n");
		rewind(stdin);
		memset(str2, 0, sizeof(str2));

		amount2[j] = 0;
		j = j - 1;
		;

		gets(str2);
		if (strcmp(str2, "BACK") == 0)
		{
			if (BACK_amount < 3)
			{
				printf("�ѳ�����һ������\n");
				rewind(stdin);
				BACK_amount += 1;
				goto gt2;
			}
			else
			{
				printf("������������\n");
				rewind(stdin);
			}


		}
		else
		{
			BACK_amount = 0;
			goto gt10;
		}


	}
	else
	{
		price2[p] = amount2[j] * price[k];
		sum_price += price2[p];
		amount[k] -= amount2[j];
	}
	gets(str2);

	if (strcmp(str2, "BACK") == 0)
	{
		if (BACK_amount < 3)
		{
			printf("�ѳ�����һ������\n");
			rewind(stdin);
			BACK_amount += 1;
			for (k = 1; grand2[j] != grand[k] || number2[j] != number[k];)
			{
				k++;
			}
			sum_price -= price2[p];
			amount[k] += amount2[j];
			amount2[j] = 0;
			goto gt4;
		}
		else
		{
			printf("������������\n");
			rewind(stdin);
		}



	}
	else
	{
		BACK_amount = 0;
	}
gt10:for (; (amount[1] > 0 || amount[2] > 0 || amount[3] > 0 || amount[4] > 0 || amount[5] > 0);)
{
	for (; strcmp(str2, "END") != 0;)
	{
		j++;
		grand2[j] = str2[0];
		number2[j] = str2[2] - 48;
		amo_unt2[j][0] = str2[4];
		amo_unt2[j][1] = str2[5];
		if (amo_unt2[j][1] == 0)
		{
			amount2[j] = amo_unt2[j][0] - 48;
		}
		else
		{
			amount2[j] = (amo_unt2[j][0] - 48) * 10 + amo_unt2[j][1] - 48;
		}

		for (k = 1; (grand2[j] != grand[k] || number2[j] != number[k]) && k < 6;)
		{
			k++;
		}
		if (k == 6)
		{
			printf("�������Ʒ������ͨ���Ų���Ӧ���˴�������Ч\n");
			rewind(stdin);
			amount2[j] = 0;
			j = j - 1;
			if (amount2[j] > amount[k] || (str2[6] >= 48 && str2[6] <= 57))
			{
				printf("��Ҫ����Ļ����������㣬�˴β�����Ч\n");
				rewind(stdin);
				memset(str2, 0, sizeof(str2));
			}
			gets(str2);
			goto gt7;
		}

		else if (amount2[j] > amount[k] || (str2[6] >= 48 && str2[6] <= 57))
		{
			printf("��Ҫ����Ļ����������㣬�˴β�����Ч\n");
			rewind(stdin);

			amount2[j] = 0;
			j = j - 1;
			memset(str2, 0, sizeof(str2));
			gets(str2);
			goto gt7;//��Ҫֱ����ת����һ��gets��str2���������޷����������ݸ�ֵ�ͽ�����ǰ����
		}
		else
		{
			p++;
			price2[p] = amount2[j] * price[k];
			sum_price += price2[p];
			amount[k] -= amount2[j];

		}
	gt5:gets(str2);
		if (BACK_amount > 0)
		{

			for (k = 1; grand2[j] != grand[k] || number2[j] != number[k];)
			{
				k++;
			}
		}
	gt7:if (strcmp(str2, "BACK") == 0)
	{
		if (BACK_amount < 3)
		{
			printf("�ѳ�����һ������\n");
			rewind(stdin);
			BACK_amount += 1;
			for (k = 1; grand2[j] != grand[k] || number2[j] != number[k];)
			{
				k++;
			}

			amount[k] += amount2[j];
			sum_price -= price2[p];
			amount2[j] = 0;
			p = p - 1;
			j = j - 1;
			if (j >= 0)
			{
				goto gt5;
			}
			else
			{
				goto gt2;
			}
		}
		else
		{
			printf("������������\n");
			rewind(stdin);
		}
	}
	else
	{
		BACK_amount = 0;
	}

	}
	strcpy(str2, "0");







	BACK_amount = 0;


	r = 1;

	printf("��ʼ��Ǯ����Ͷ��1Ԫ��2Ԫ��5Ԫ\n");
	rewind(stdin);
gt6:gets(str4);
	if (strcmp(str4, "BACK") == 0)
	{
		if (BACK_amount < 3)
		{
			printf("�ѳ�����һ������\n");
			rewind(stdin);
			BACK_amount += 1;
			r--;
			sum_pay -= once_pay[r];
			once_pay[r] = 0;
			if (r <= 0)
			{
				goto gt5;
			}
			else
			{
				goto gt11;
			}
		}
		else
		{
			printf("������������\n");
			rewind(stdin);
			goto gt11;
		}

	}

	else
	{
		BACK_amount = 0;
		if (str4[1] != 0)
		{
			printf("���������\n");
			rewind(stdin);
			memset(str4, 0, sizeof(str4));
			r--;
		}
		else
		{
			if (str4[0] != 49 && str4[0] != 50 && str4[0] != 53)
			{
				printf("���������\n");
				rewind(stdin);
				r--;

			}
			else
			{
				once_pay[r] = str4[0] - 48;
				sum_pay += once_pay[r];

			}
		}

	}

	for (; sum_pay < sum_price;)
	{
		r++;
	gt11:printf("��Ͷ��Ǯ\n");
		rewind(stdin);
		gets(str2);
		if (strcmp(str2, "BACK") == 0)
		{
			if (BACK_amount < 3)
			{
				printf("�ѳ�����һ��\n");
				rewind(stdin);
				BACK_amount += 1;
				r--;
				sum_pay -= once_pay[r];
				once_pay[r] = 0;
				if (r >= 1)
				{
					goto gt6;
				}
				else
				{
					goto gt5;
				}
			}
			else
			{
				printf("������������\n");
				rewind(stdin);
			}
		}
		else
		{
			BACK_amount = 0;
			if (str2[1] != 0)
			{
				printf("���������");
				rewind(stdin);
				memset(str2, 0, sizeof(str2));
				r--;
			}
			else
			{
				if (str2[0] != 49 && str2[0] != 50 && str2[0] != 53)
				{
					printf("���������\n");
					rewind(stdin);
					r--;
				}
				else
				{

					once_pay[r] = str2[0] - 48;
					sum_pay += once_pay[r];

				}
			}
		}

	}


	back = sum_pay - sum_price;
	printf("����%d\n", back);
	printf("������ϣ��ۻ�����ʣ��0Ԫ�����Լ�������Ҳ������END����ȫ����\n");

	back = 0;
	sum_price = 0;
	sum_pay = 0;
	rewind(stdin);
	gets(str3);
	if (strcmp(str3, "END") == 0)
	{
		break;
	}
	else
	{
		strcpy(str2, str3);
	}
}
memset(str2, 0, sizeof(str2));
if (amount[1] > 0 || amount[2] > 0 || amount[3] > 0 || amount[4] > 0 || amount[5] > 0)
{
	printf("�������������ѽ������ۻ��������ʣ����Ʒ���������°ڷ�\n");
}
else
{
	printf("�ۻ�����������գ���Ҫ���°ڷŻ���,�˴β�����Ч\n");
}
rewind(stdin);
gets(str5);
if (strcmp(str5, "BACK") == 0)
{
	if (BACK_amount < 3)
	{
		printf("�ѳ�����һ��,���Լ���������Ʒ\n");
		rewind(stdin);
		BACK_amount += 1;
		strcpy(str5, "0");
		goto gt8;
	}
	else
	{
		printf("������������\n");
		rewind(stdin);

	}
}
else
{
	strcpy(str, str5);
	BACK_amount = 0;
	printf("��һ�ְڷŻ��ڵĵ�һ��������������룬������ɹ������Լ����ڶ��ΰڷŻ�������END�����ڷŻ��ڣ�������Ҫ���������һ������\n");
	rewind(stdin);
	goto gt9;

}

	}

}