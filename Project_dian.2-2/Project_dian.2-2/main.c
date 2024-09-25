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
		printf("温馨提示：在输入品牌、序号（1-5号）(只能输一位数)、价格（只能输一位数）、数量时请用一个空格隔开（输入数量后只需要回车）,每次输入通道序号不能相同(若相同则自动视为输入错误)，若完成全部输入可通过输入END结束当前环节\n");//局限性在于必须在输入不同数据时用一个空格隔开（只要不是一个空格此代码就不能正常运行，需要修改代码）
		rewind(stdin);
		gets(str);
	gt9:for (i = 1; strcmp(str, "END") != 0;)//为了使第一次输入也能判断数量是否过多，必须设置为i=1
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
		rewind(stdin);//彻底清空缓冲区
		for (t = 1; number[i] != number[t] && i > t;)
		{
			t++;
		}
		if (amount[i] > 50 || (str[8] >= 48 && str[8] <= 57))
		{
			printf("放入数量过多，此次投放无效\n");
			rewind(stdin);

			if (number[i] > 5 || number[i] < 1||str[3]!=32||t<i)
			{
				printf("通道序号输入错误，此次操作无效\n");
				rewind(stdin);
				if (price[i] > 9 || price[i] < 1)
				{
					printf("输入货物单价错误，此次操作无效\n");
					rewind(stdin);
				}
			}
			else if (price[i] > 9 || price[i] < 1)
			{
				printf("输入货物单价错误，此次操作无效\n");
				rewind(stdin);
			}
			memset(str, 0, sizeof(str));
			i = i - 1;

		}
		else if (number[i] > 5 || number[i] < 1 || str[3] != 32 || t < i)
		{
			printf("通道序号输入错误，此次操作无效\n");
			rewind(stdin);

			if (price[i] > 9 || price[i] < 1)
			{
				printf("输入货物单价错误，此次操作无效\n");
				rewind(stdin);
			}
			i = i - 1;
		}
		else if (price[i] > 9 || price[i] < 1)
		{
			printf("输入货物单价错误，此次操作无效\n");
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
				printf("已撤销上一步操作\n");
				rewind(stdin);
				amount[i] = 0;
				i--;
				BACK_amount += 1;

				rewind(stdin);
			gt1:gets(str);
			}
			else
			{
				printf("撤销次数不足，此次操作无效\n");
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

			if (i >= 6)//i=1为开始，因此必须以6为边界
			{
				printf("没有多余通道了,最近一次的输入无效\n");
				rewind(stdin);
				break;
			}
			else
			{
				if (strcmp(str, "BACK") == 0)
				{
					if (BACK_amount < 3)
					{
						printf("已撤销上一步\n");
						i = i - 1;
						BACK_amount += 1;
						amount[i] = 0;
						rewind(stdin);
					}
					else
					{
						printf("撤销次数不足，此次操作无效，请不要再连续输入BACK\n");
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
					amo_unt[i][0] = str[6];//输入的是数字字符对应的ASCII码值
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
						printf("放入数量过多，此次投放无效\n");
						rewind(stdin);

						if (number[i] > 5 || number[i] < 1 || str[3] != 32||t<i)
						{
							printf("通道序号输入错误，此次操作无效\n");
							rewind(stdin);
							if (str[5] != 32 || price[i] < 1)
							{
								printf("输入货物单价错误，此次操作无效\n");
								rewind(stdin);
							}
							if (grand[i] == grand[w] && price[i] != price[w])
							{
								printf("同种货物价格不统一\n");
								rewind(stdin);
							}
						}
						else if (str[5] != 32 || price[i] < 1)
						{
							printf("输入货物单价错误，此次操作无效\n");
							rewind(stdin);
							if (grand[i] == grand[w] && price[i] != price[w])
							{
								printf("同种货物的单价不统一，此次操作无效\n");
								rewind(stdin);
							}

						}
						else if (grand[i] == grand[w] && price[i] != price[w])
						{
							printf("同种货物的单价不统一，此次操作无效\n");
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
							printf("已撤销上一步\n");
							rewind(stdin);
							BACK_amount += 1;
							amount[i] = 0;
							i--;
							goto gt2;
						    }
							else
							{
								printf("撤销次数不足，此次操作无效，请不要再连续输入BACK\n");
							}
						}
						else
						{
							BACK_amount = 0;
						}

					}
					else if (number[i] > 5 || number[i] < 1 || str[3] != 32||t<i)
					{
						printf("通道序号输入错误，此次操作无效\n");
						rewind(stdin);


						if (str[5] != 32 || price[i] < 1)
						{
							printf("输入货物单价错误，此次操作无效\n");
							rewind(stdin);
							if (grand[i] == grand[w] && price[i] != price[w])
							{
								printf("同种货物的单价不统一，此次操作无效\n");
								rewind(stdin);
							}

						}
						else if (grand[i] == grand[w] && price[i] != price[w])
						{
							printf("同种货物的单价不统一，此次操作无效\n");
							rewind(stdin);

						}
						amount[i] = 0;
						i = i - 1;
						gets(str);
						if (strcmp(str, "BACK") == 0)
						{
							if (BACK_amount < 3)
							{
								printf("已撤销上一步\n");
								rewind(stdin);
								BACK_amount += 1;
								amount[i] = 0;
								i--;
								goto gt2;
							}
							else
							{
								printf("撤销次数不足，此次操作无效，请不要再连续输入BACK\n");
							}
						}
						else
						{
							BACK_amount = 0;
						}
					}
					else if (str[5] != 32 || price[i] < 1)
					{
						printf("输入货物单价错误，此次操作无效\n");
						rewind(stdin);
						if (grand[i] == grand[w] && price[i] != price[w])
						{
							printf("同种货物的单价不统一，此次操作无效\n");
							rewind(stdin);

						}
						amount[i] = 0;
						i = i - 1;
						gets(str);
						if (strcmp(str, "BACK") == 0)
						{
							if (BACK_amount < 3)
							{
								printf("已撤销上一步\n");
								rewind(stdin);
								BACK_amount += 1;
								amount[i] = 0;
								i--;
								goto gt2;
							}
							else
							{
								printf("撤销次数不足，此次操作无效，请不要再连续输入BACK\n");
							}
						}
						else
						{
							BACK_amount = 0;
						}
					}
					else if (grand[i] == grand[w] && price[i] != price[w])
					{
						printf("同种货物的单价不统一，此次操作无效\n");
						rewind(stdin);
						amount[i] = 0;
						i = i - 1;
						gets(str);
						if (strcmp(str, "BACK") == 0)
						{
							if (BACK_amount < 3)
							{
								printf("已撤销上一步\n");
								rewind(stdin);
								BACK_amount += 1;
								amount[i] = 0;
								i--;
								goto gt2;
							}
							else
							{
								printf("撤销次数不足，此次操作无效，请不要再连续输入BACK\n");
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
								printf("已撤销上一步操作\n");
								amount[i] = 0;
								i = i - 1;
								BACK_amount += 1;
								rewind(stdin);
								goto gt2;
							}
							else
							{
								printf("撤销次数不足，此次操作无效\n");
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
	printf("结束放货环节\n");
	rewind(stdin);
















	BACK_amount = 0;
gt8:printf("开始取货环节\n");
	rewind(stdin);

gt4:gets(str2);
	if (strcmp(str2, "BACK") == 0)
	{
		if (BACK_amount < 3)
		{
			printf("已撤销上一步操作\n");
			rewind(stdin);
			BACK_amount += 1;
			goto gt2;
		}
		else
		{
			printf("撤销次数不足\n");
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
		printf("输入的商品种类与通道号不对应，此次输入无效\n");
		rewind(stdin);
		amount2[j] = 0;
		j = j - 1;
		if (str2[6] >= 48 && str2[6] <= 57)
		{
			printf("所要购买的货物数量不足，此次操作无效\n");
			rewind(stdin);
			memset(str2, 0, sizeof(str2));
		}
		gets(str2);
		if (strcmp(str2, "BACK") == 0)
		{
			if (BACK_amount < 3)
			{
				printf("已撤销上一步操作\n");
				rewind(stdin);
				BACK_amount += 1;
				goto gt2;
			}
			else
			{
				printf("撤销次数不足\n");
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
		printf("所要购买的货物数量不足，此次操作无效\n");
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
				printf("已撤销上一步操作\n");
				rewind(stdin);
				BACK_amount += 1;
				goto gt2;
			}
			else
			{
				printf("撤销次数不足\n");
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
			printf("已撤销上一步操作\n");
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
			printf("撤销次数不足\n");
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
			printf("输入的商品种类与通道号不对应，此次输入无效\n");
			rewind(stdin);
			amount2[j] = 0;
			j = j - 1;
			if (amount2[j] > amount[k] || (str2[6] >= 48 && str2[6] <= 57))
			{
				printf("所要购买的货物数量不足，此次操作无效\n");
				rewind(stdin);
				memset(str2, 0, sizeof(str2));
			}
			gets(str2);
			goto gt7;
		}

		else if (amount2[j] > amount[k] || (str2[6] >= 48 && str2[6] <= 57))
		{
			printf("所要购买的货物数量不足，此次操作无效\n");
			rewind(stdin);

			amount2[j] = 0;
			j = j - 1;
			memset(str2, 0, sizeof(str2));
			gets(str2);
			goto gt7;//需要直接跳转过下一个gets（str2），否则无法给下轮数据赋值就结束当前环节
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
			printf("已撤销上一步操作\n");
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
			printf("撤销次数不足\n");
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

	printf("开始收钱，请投入1元、2元或5元\n");
	rewind(stdin);
gt6:gets(str4);
	if (strcmp(str4, "BACK") == 0)
	{
		if (BACK_amount < 3)
		{
			printf("已撤销上一步操作\n");
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
			printf("撤销次数不足\n");
			rewind(stdin);
			goto gt11;
		}

	}

	else
	{
		BACK_amount = 0;
		if (str4[1] != 0)
		{
			printf("输入金额错误\n");
			rewind(stdin);
			memset(str4, 0, sizeof(str4));
			r--;
		}
		else
		{
			if (str4[0] != 49 && str4[0] != 50 && str4[0] != 53)
			{
				printf("输入金额错误\n");
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
	gt11:printf("请投入钱\n");
		rewind(stdin);
		gets(str2);
		if (strcmp(str2, "BACK") == 0)
		{
			if (BACK_amount < 3)
			{
				printf("已撤销上一步\n");
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
				printf("撤销次数不足\n");
				rewind(stdin);
			}
		}
		else
		{
			BACK_amount = 0;
			if (str2[1] != 0)
			{
				printf("输入金额错误");
				rewind(stdin);
				memset(str2, 0, sizeof(str2));
				r--;
			}
			else
			{
				if (str2[0] != 49 && str2[0] != 50 && str2[0] != 53)
				{
					printf("输入金额错误\n");
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
	printf("找零%d\n", back);
	printf("找零完毕，售货机内剩余0元，可以继续购买，也可输入END结束全流程\n");

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
	printf("本次完整流程已结束，售货机将清空剩余商品，可以重新摆放\n");
}
else
{
	printf("售货机货物已清空，需要重新摆放货物,此次操作无效\n");
}
rewind(stdin);
gets(str5);
if (strcmp(str5, "BACK") == 0)
{
	if (BACK_amount < 3)
	{
		printf("已撤销上一步,可以继续购买商品\n");
		rewind(stdin);
		BACK_amount += 1;
		strcpy(str5, "0");
		goto gt8;
	}
	else
	{
		printf("撤销次数不足\n");
		rewind(stdin);

	}
}
else
{
	strcpy(str, str5);
	BACK_amount = 0;
	printf("新一轮摆放环节的第一组货物数据已输入，若输入成功，可以继续第二次摆放或者输入END结束摆放环节，否则需要重新输入第一组数据\n");
	rewind(stdin);
	goto gt9;

}

	}

}