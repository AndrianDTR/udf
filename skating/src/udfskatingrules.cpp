#include "udfskatingrules.h"

#include "udfcommon.h"

udfSkatingRules::udfSkatingRules(int teams, int judges, int** marks)
: m_nTeams(teams)
, m_nJudges(judges)
, m_ppnMarks(0)
, m_ppnResults(0)
{
	int t = 0;
	m_ppnMarks = new int*[teams];
	m_ppnResults = new int*[teams];
	for(t = 0; t < teams; t++)
	{
		int j = 0;
		int r = 0;
		const int rc = teams + 1;

		m_ppnMarks[t] = new int[judges];
		m_ppnResults[t] = new int[rc];

		for(j = 0; j < judges; j++)
		{
			m_ppnMarks[t][j] = marks[t][j];
		}

		for(r = 0; r < rc; r++)
		{
			m_ppnResults[t][r] = 0;
		}
	}
}

udfSkatingRules::~udfSkatingRules()
{
	if(m_ppnMarks)
	{
		int t = 0;
		for(t = 0; t < m_nTeams; t++)
		{
			if(m_ppnMarks)
			{
				delete [] m_ppnMarks[t];
				m_ppnMarks[t] = 0;
			}
		}
		delete [] m_ppnMarks;
		m_ppnMarks = 0;
	}

	if(m_ppnResults)
	{
		int t = 0;
		for(t = 0; t < m_nTeams; t++)
		{
			if(m_ppnResults)
			{
				delete [] m_ppnResults[t];
				m_ppnResults[t] = 0;
			}
		}
		delete [] m_ppnResults;
		m_ppnResults = 0;
	}
}

bool udfSkatingRules::GetMarks(int& nTeams, int*** marks)
{
	Enter();
	bool res = true;

	do
	{
		if(Rule1())
			break;

		if(Rule2())
			break;

		if(Rule3())
			break;

		if(Rule4())
			break;

		if(Rule5())
			break;

		if(Rule6())
			break;

		if(Rule7())
			break;

		if(Rule8())
			break;

		if(Rule9())
			break;

		if(Rule10())
			break;

		if(Rule11())
			break;

		res = false;
	}while(0);

	nTeams = m_nTeams;
	*marks = m_ppnResults;

	Leave();
	return res;
}

/*******************************************************************************
 * Количество пар, которое должно быть отобрано в каждом туре соревнования для
 * участия в следующем, определяется главным судьей (обычно это 2/3 но не менее
 * 1/2 участвующих пар). В соответствии с этим решением судья должен отобрать в
 * каждом танце указанное количество пар. Рекомендация: хотя способ обозначения
 * выбора судьи правилами системы "скейтинг" строго не регламентирован,
 * оптимальным способом обозначения являются:
 * - обозначение положительной оценки для отобранной пары по каждому танцу,
 * - зачеркивание или пропуск № пар, не выводимых судьей в следующий тур,
 * - буква "D" в случае дисквалификации пары.
 *
 * Обычно отбирают по принципу "за - против". Равномерности выбора судьи по
 * заходам может не быть. В следующий тур выводятся пары, имеющие наибольшие
 * значения итоговых сумм. В процессе отбора может возникнуть ситуация, когда
 * несколько пар имеют одинаковое значение итоговых сумм, позволяющее принять
 * участие в следующем туре, но включение этих пар в состав участников
 * следующего этапа проблематично, т.к. общее количество пар превысит заданное
 * число. В этом случае главный судья и оргкомитет соревнований должны принять
 * решение : либо допустить к участию в следующем туре все пары, имеющие
 * одинаковое значение итоговых сумм, либо не допустить ни одну из них.
 * Перетанцовку не допускают.
 ******************************************************************************/
bool udfSkatingRules::Rule1()
{
	return false;
}

/*******************************************************************************
 * В финале соревнующиеся пары должны быть расставлены судьей в каждом танце по
 * местам согласно уровню их исполнительского мастерства.
 ******************************************************************************/
bool udfSkatingRules::Rule2()
{
	return false;
}

/*******************************************************************************
 * Лучшей, по мнению судьи паре, в каждом танце финала, ставится оценка "1"
 * и т.д. Обычно в финальном туре соревнований принимают участие 6-8 пар.
 ******************************************************************************/
bool udfSkatingRules::Rule3()
{
	return false;
}

/*******************************************************************************
 * В финале судьи не имеют права ни в одном из танцев поставить двум или более
 * парам одинаковую оценку.
 ******************************************************************************/
bool udfSkatingRules::Rule4()
{
	return false;
}

/*******************************************************************************
 * Победителем в отдельном танце становится пара, которая получает оценку "1"
 * у большинства судей (не менее 3-х судей из 5-ти, 4-х из 6-ти или 7-ми, 5-ти
 * из 8-ми или 9-ти судей). 2-е место присуждается паре, которая получит 2-е и
 * более высокие оценки (т.е. 2-е и 1-е) у большинства судей. Остальные
 * результаты за танец распределяются аналогичным образом.
 * Колонки "оценки 1 - _" заполняются последовательно сверху - вниз и
 * слева - направо, ни одну из них при обучении нельзя пропустить, т.к.
 * в противном случае возникает опасность случайно не заметить претендента на
 * очередной результат.
 *
 * В случае, если ни одна из пар не набрала необходимого большинства голосов
 * судей в рассматриваемой колонке оценок, надо для присвоения очередного места
 * перейти к рассмотрению следующей колонки оценок "1-_". Как только результат,
 * полученный парой в рассматриваемом танце определен, заполнение последующих
 * построчных значений колонок оценок "1-_" для этой пары прекращают.
 *
 * Пример А
 * № 	A 	B 	C 	D 	E 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 10 	3 	3 	3 	2 	3 	- 	1 		5 		- 		- 		- 		3
 * 16 	6 	6 	6 	6 	5 	- 	- 		- 		- 		1 		5 		6
 * 24 	2 	2 	5 	4 	1 	1 	3 		- 		- 		- 		- 		2
 * 31 	4 	4 	2 	3 	4 	- 	1 		2 		5 		- 		- 		4
 * 45 	1 	5 	1 	1 	2 	3 	- 		- 		- 		- 		- 		1
 * 48 	5 	1 	4 	5 	6 	1 	1 		1 		2 		4 		- 		5
 *
 * В примере А пара №45 от 3-х судей из 5-ти получила оценку "1" и вследствие
 * этого становится победителем. Пары №10, №31, №48 не набрали необходимого
 * большинства голосов судей в колонке "1-2" и поэтому их рассмотрение будет
 * продолжено в следующих колонках. Пара №24 получила 2 раза 2-ю и один раз
 * 1-ю оценку (итого 3 из 5-ти в колонке "1-2") и получает 2-й результат.
 * Остальные результаты распределяются аналогично. Еще один пример к правилу 5,
 * для самостоятельного разбора.
 *
 * Пример Б
 * № 	A 	B 	C 	D 	E 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 11 	1 	5 	1 	1 	2 	3 	- 		- 		- 		- 		- 		1
 * 21 	2 	2 	5 	4 	1 	1 	3 		- 		- 		- 		- 		2
 * 32 	3 	3 	3 	2 	3 	- 	1 		5 		- 		- 		- 		3
 * 41 	4 	4 	2 	3 	4 	- 	1 		2 		5 		- 		- 		4
 * 51 	5 	1 	4 	5 	5 	1 	1 		1 		2 		5 		- 		5
 * 61 	6 	6 	6 	6 	6 	- 	- 		- 		- 		- 		5 		6
 * 
 ******************** 5 **********************************************************/
bool udfSkatingRules::Rule5()
{
	Enter();
	bool res = true;
	do
	{
		int t, j, p;
		int jMost = m_nJudges / 2 + 1;

		__msg("most judges = %d", jMost);
		
		for(p = 0; p < m_nTeams; p++)
		{
			for(t = 0; t < m_nTeams; t++)
			{
				m_ppnResults[t][p] = 0;
			}
			
			for(t = 0; t < m_nTeams; t++)
			{
				for(j = 0; j < m_nJudges; j++)
				{
					if(m_ppnMarks[t][j] == p+1)
					{
						m_ppnResults[t][p]++;
					}
				}
			}
		}
		
		for(t = 0; t < m_nTeams; t++)
		{
			for(p = 0; p < m_nTeams; p++)
			{
				if(m_ppnResults[t][p] >= jMost)
					m_ppnResults[t][m_nTeams] = p+1;
				else
				{
					res = false;
				}
			}
		}
	}while(0);

	Leave();
	return res;
}

/*******************************************************************************
 * Применяется в случае, когда 2 или более пар в одной колонке "оценки" имеют
 * необходимое большинство голосов судей для присуждения очередного результата
 * за танец, причем неравное. В этом случае очередной результат за танец
 * присуждается паре, имеющей большее "большинство", следующий результат
 * присуждается паре с меньшим "большинством" и т.д. в порядке убывания.
 *
 * Пример В
 * № 	A 	B 	C 	D 	E 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 12 	1 	1 	1 	4 	4 	3 	-	  	-		-  	  	-		-  	  	1
 * 22 	3 	2 	2 	1 	1 	2 	4 	  	-		-		-  	  	-	  	2
 * 32 	2 	5 	5 	2 	2 	- 	3 	  	-  	  	-  		-		-		3
 * 42 	4 	3 	4 	5 	3 	- 	- 		-		2 		4 	  	-	  	4
 * 52 	5 	4 	3 	3 	5 	- 	- 		2 		3 	  	-		-	  	5
 * 62 	6 	6 	6 	6 	6 	- 	- 		- 		- 		- 		5 		6
 *
 * В примере В Пара №12 получает 1-й результат по абсолютному большинству 1-х
 * оценок. Пары №22 и №32 в колонке "оценки 1-2" набрали необходимое
 * большинство для присвоения следующего 2-го результата. Пара №22 получила у
 * судей четыре "1-2" оценки против 3-х у пары №32. В результате пара №22
 * получает результат 2 в танце, а пара №32 - третий. Аналогично распределяются
 * пятый и четвертый результат между парами №42 и №52 . Еще один пример (Г) к
 * правилу 6, для самостоятельного разбора. Учтите только, что в этом примере
 * выступление пар оценивали 7 судей и, поэтому, необходимое большинство голосов
 * судей должно быть не менее 4-х.
 *
 * Пример Г
 * № 	A 	B 	C 	D 	E 	F 	G 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 12 	3 	1 	5 	3 	1 	2 	3 	2 	3 		6	 	-		-	 	-	  	2
 * 23 	1 	4 	1 	1 	2 	1 	2 	4 	- 		-		-		- 	  	- 	  	1
 * 34 	4 	2 	2 	2 	3 	3 	4 	- 	3 		5		-		-	  	- 	  	3
 * 45 	6 	5 	4 	6 	4 	6 	5 	- 	- 		- 		2 		4 	  	-		5
 * 56 	2 	3 	3 	4 	5 	5 	1 	1 	2 		4 	  	- 	  	-		-		4
 * 67 	5 	6 	6 	5 	6 	4 	6 	- 	- 		- 		1 		3 		7 		6
 *
 ******************************************************************************/
bool udfSkatingRules::Rule6()
{
	Enter();
	bool res = true;
	do
	{
		int jMost = m_nJudges / 2 + 1;
		
		__msg("Rule 6");

		//res = true;
	}while(0);
	Leave();
	return res;
}

/*******************************************************************************
 * Применяется в случае, когда 2 или более пар имеют необходимое большинство
 * голосов судей для присвоения очередного результата за танец, причем оно у
 * всех этих пар равное. В этом случае необходим анализ компонентов,
 * составляющих это большинство. ечь идет о суммировании оценок, из которых
 * сложились равные количества в колонках оценок "1-_" у рассматриваемых пар
 * (не путать с общей суммой всех судейских оценок). Полученные суммы
 * записывают в круглых скобках около соответствующих количеств оценок(внизу
 * справа) в той же колонке оценок "1-_". При этом возможны два варианта:
 *
 * 7а). Пары имеют необходимое большинство оценок "1-_", его величина у этих
 * пар в рассматриваемой колонке совпадает, а суммы составляющих не равны.
 * В этом случае очередной результат в танце присуждается той паре, у которой
 * сумма составляющих наименьшая (т.е. составляющие выше), а следующий
 * результат - парам, имеющим большую сумму составляющих в порядке возрастания.
 *
 * Пример Д
 * № 	A 	B 	C 	D 	E 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 15 	4 	6 	6 	6 	6 	- 	- 		- 		1 		1 		5 		6
 * 26 	5 	5 	1 	1 	1 	3 	- 		-		-		- 	  	-  	  	1
 * 37 	6 	1 	3 	3 	4 	1 	1 		3(7) 	-	 	-		-  	  	4
 * 48 	1 	4 	2 	2 	5 	1 	3(5) 	-  	  	-		-		-  	  	2
 * 59 	2 	2 	5 	5 	2 	- 	3(6) 	-		-		-  	  	-  	  	3
 * 70 	3 	3 	4 	4 	3 	- 	-	  	3(9) 	-		-		-  	  	5
 *
 * В примере Д пара №26 получает результат "1" в танце по абсолютному
 * большинству 1-х оценок. Две пары: №48 и №59 имеют необходимое и притом
 * равное большинство 1-2 оценок (3). Сумма составляющих в колонке 1-2 у пары
 * №48: (1+2+2)=5, у пары №59: (2+2+2)=6. Пара №48 получает очередной 2-й
 * результат в танце, т.к. она имеет меньшую сумму составляющих. Пара №59
 * получает результат "3", т.к. она имеет большую сумму составляющих.
 * Аналогично распределяются результаты между парами №37 и №70. Еще один
 * пример (Е), для самостоятельного разбора этого правила.
 *
 * Пример Е
 * № 	A 	B 	C 	D 	E 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 13 	1 	1 	1 	5 	5 	3 	-		-		-		-		-  	  	1
 * 23 	2 	2 	5 	1 	4 	1 	3(5) 	-		-		-  	  	-  	  	2
 * 33 	5 	5 	2 	2 	2 	- 	3(6)	- 	  	-		-		-  	  	3
 * 43 	3 	3 	4 	6 	1 	1 	1 		3(7)	-		- 	  	-  	  	4
 * 53 	4 	4 	3 	3 	3 	- 	- 		3(9) 	-		-  		-  	  	5
 * 63 	6 	6 	6 	4 	6 	- 	- 		- 		1 		1 		5 		6
 *
 * 7б). Применяется в случае, когда пары имеют в рассматриваемой колонке
 * необходимое большинство оценок "1-_", его значение у этих пар совпадает
 * и суммы оценок "1-_" также равны. В этом случае для определения результатов,
 * полученных парами в танце, необходимо учитывать более низкие оценки и снова
 * пытаться обнаружить различие в количестве оценок или сумме их составляющих,
 * но только для спорящих за очередной результат пар, на время "забыв" об
 * остальных парах. После решения вопроса о распределении спорных результатов
 * необходимо восстановить нарушенный порядок рассмотрения колонок
 * оценок "1-_".
 *
 * Пример Ж
 * № 	A 	B 	C 	D 	E 	F 	G 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 10 	5 	3 	5 	4 	6 	5 	2 	- 	1 		2 		3 		6 	  	-		5
 * 11 	3 	1 	4 	3 	5 	1 	1 	3 	3 		5 		-  		-		-  	  	3
 * 12 	1 	4 	2 	2 	2 	3 	4 	1 	4(7) 	5 	  	-		-		-  	  	2
 * 13 	2 	2 	3 	1 	4 	2 	3 	1 	4(7) 	6 	  	-		-		-  	  	1
 * 14 	4 	5 	1 	5 	1 	4 	6 	2 	2 		2 		4 	  	-		-	  	4
 * 15 	6 	6 	6 	6 	3 	6 	5 	- 	- 		1 		1 		2 		7 		6
 *
 * В примере Ж ни одна из пар не набрала необходимого большинства первых
 * оценок. Поэтому, для присвоения результата "1" переходим к рассмотрению
 * колонки "1-2". Две пары №12 и №13 имеют необходимое большинство (по 4).
 * Суммы составляющих у них также равны (1+2+2+2=7, 2+2+1+2=7 ). Заполняем
 * колонку оценок "1-3", но только для этих двух пар. Пара №13 получает
 * результат "1", т.к. она имеет большее большинство в колонке оценок
 * "1-3"= (6). Пара №12 получает следующий результат "2". Заметьте, что
 * пара №11 не вступает в спор с парами №12 и №13 за 1 или 2 место, хотя в
 * колонке "1-3" имеет необходимое большинство наравне с парой №12. Пара №11
 * может претендовать только на следующее после пар №12 и №13 место, не
 * вступая с ними в спор за 1 или 2 место. Еще один пример (З), для
 * самостоятельного разбора.
 *
 * Пример З
 * № 	A 	B 	C 	D 	E 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 14 	2 	1 	5 	1 	1 	3 	-		-		-		-		-  	  	1
 * 24 	1 	2 	2 	5 	5 	1 	3(5) 	3(5) 	3(5) 	5 		-	  	2
 * 34 	5 	6 	1 	2 	2 	1 	3(5) 	3(5) 	3(5) 	4 		-	  	3
 * 44 	3 	3 	3 	3 	6 	- 	- 		4 	 	-		-		-  	  	4
 * 54 	4 	4 	4 	6 	4 	- 	- 		- 		4 		-		-  	  	5
 * 64 	6 	5 	6 	4 	3 	- 	- 		1 		2 		3 	  	-		6
 *
 ******************************************************************************/
bool udfSkatingRules::Rule7()
{
	Enter();
	bool res = true;
	do
	{
		int jMost = m_nJudges / 2 + 1;
		
		__msg("Rule 6");

		//res = true;
	}while(0);
	Leave();
	return res;
}

/*******************************************************************************
 * Применяется в случае, когда в результате применения предыдущих правил мнение 
 * большинства судей установить не удается. Такая ситуация не является чем-то 
 * необычным и довольно часто встречается на соревнованиях. Она может 
 * возникнуть , например, в случае, если пары от всех судей за танец получили 
 * одинаковые оценки с точностью до перестановки. Тогда у этих пар во всех 
 * колонках оценок "1-_" будет одинаковое количество мест и одинаковая сумма 
 * составляющих и всем парам, в отношении которых не удалось установить мнение 
 * большинства судей, присуждается одинаковый результат, который определяется 
 * как итог деления суммы всех результатов, которые оспаривают пары, на 
 * количество пар, претендующих на эти результаты (т.е. среднее арифметическое).
 * 
 * Пример И
 * № 	A 	B 	C 	D 	E 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 16 	4 	3 	5 	3 	2 	- 	1 		3(8) 	4(12) 	5(17) 	5(17) 	3,5
 * 17 	3 	2 	2 	4 	1 	1 	3(5) 	- 		 -		-		-		2
 * 18 	2 	1 	1 	5 	4 	2 	3(4) 	- 		-		-		-		1
 * 19 	5 	4 	3 	2 	3 	- 	1 		3(8)	4(12) 	5(17) 	5(17) 	3,5
 * 20 	1 	5 	4 	1 	6 	2 	2 		2 		3 		-		-		5
 * 21 	6 	6 	6 	6 	5 	- 	- 		- 		- 		1 		5 		6
 * 
 * В примере И пары №16 и №19 ведут спор за распределение между собой 3 и 4 
 * результатов. Они имеют одинаковые количества оценок и суммы их составляющих 
 * в колонках оценок с "1-3" по "1-6" (до конца). Этим парам присуждается 
 * одинаковый результат, который рассчитывается как итог деления суммы 
 * результатов, на которые претендуют эти пары (3+4=7) на количество 
 * претендующих пар (2), т.е. 3,5 . После распределения результатов между 
 * спорящими парами необходимо восстановить нарушенный порядок рассмотрения 
 * колонок оценок "1-_" для остальных пар (с колонки "1-3"). Паре №20 
 * присваивается очередной (5) результат, с учетом того, что 3 и 4 результаты 
 * уже распределены между парами №16 и №19. Еще один пример (К), для 
 * самостоятельного разбора.
 * 
 * № 	A 	B 	C 	D 	E 	G 	F 	1 	1-2 	1-3 	1-4 	1-5 	1-6 	Рез
 * 81 	1 	2 	3 	4 	5 	6 	7 	  	  		  		  		  		  		4
 * 82 	2 	3 	4 	5 	6 	7 	1 	  	  		  		  		  		  		4
 * 83 	3 	4 	5 	6 	7 	1 	2 	  	  		  		  		  		  		4
 * 83 	4 	5 	6 	7 	1 	2 	3 	  	  		  		  		  		  		4
 * 84 	5 	6 	7 	1 	2 	3 	4 	  	  		  		  		  		  		4
 * 85 	6 	7 	1 	2 	3 	4 	5 	  	  		  		  		  		  		4
 * 86 	7 	1 	2 	3 	4 	5 	6 	  	  		  		  		  		  		4
 *
 ******************************************************************************/
bool udfSkatingRules::Rule8()
{
	Enter();
	bool res = true;
	do
	{
		int jMost = m_nJudges / 2 + 1;
		
		__msg("Rule 6");

		//res = true;
	}while(0);
	Leave();
	return res;
}

/*******************************************************************************
 * После окончания соревнований результаты пар по всем танцам выносятся в 
 * финальную таблицу. Общее место пары в соревновании определяется по сумме 
 * результатов этой пары в отдельных танцах. Первое место займет та пара, 
 * у которой эта итоговая сумма окажется минимальной. Остальные места пар 
 * распределяются от наименьшей итоговой суммы в порядке возрастания до 
 * наибольшей.
 * № пар 	S 	Ch 	R 	Pd 	J 	Сумма 	Место
 * 30 		1 	6 	1 	6 	1 	15 		1
 * 31 		2 	5 	2 	5 	3 	17 		3
 * 32 		3 	4 	3 	4 	4 	18 		4
 * 33 		4 	3 	4 	3 	6 	20 		6
 * 34 		5 	2 	5 	2 	5 	19 		5
 * 35 		6 	1 	6 	1 	2 	16 		2
 * 
 ******************************************************************************/
bool udfSkatingRules::Rule9()
{
	Enter();
	bool res = true;
	do
	{
		int jMost = m_nJudges / 2 + 1;
		
		__msg("Rule 6");

		//res = true;
	}while(0);
	Leave();
	return res;
}

/*******************************************************************************
 *  Применяется в случае, когда несколько пар претендуют на одно и то же место 
 * в финале, имея одинаковую итоговую сумму оценок за все танцы. Оспариваемое 
 * место присуждается паре, занявшей большее количество раз рассматриваемый и 
 * выше результат в отдельных танцах - "коэффициент эффективности". Результаты 
 * за танец с половинками при этом округляют до следующего большего целого 
 * числа. Например, результат 3.5 должен учитываться как 4-й результат при 
 * подсчете коэффициента эффективности в колонке "1-4" и не должен учитываться 
 * при подсчете в колонке "1-3". Если подсчитанные таким образом коэффициенты 
 * эффективности у нескольких пар окажутся одинаковыми, то в этом случае 
 * необходимо определить сумму составляющих эти коэффициенты эффективности 
 * результатов. Место, на которое претендовали спорящие пары, присуждается 
 * той, у которой сумма составляющих "коэффициента эффективности" минимальная. 
 * При подсчете сумм результаты с половинками не округляются.
 * 
 * После того, как очередное место присвоено одной из пар, все остальные пары 
 * будут рассматриваться как равные претенденты на присвоение следующего места.
 * 
 * Еще раз обратим внимание на очень важные особенности применения правила 10:
 * 
 * а) коэффициент эффективности рассчитывается сразу по оспариваемому и выше 
 * результатам, а не с первых оценок, как в правилах №№5 - 8;
 * б) не устанавливается минимальное значение, которое может быть принято 
 * к рассмотрению, как в правилах №№5 - 8. Важно лишь его ненулевое значение 
 * (см. ниже правило №11);
 * в) в случае равенства коэффициентов эффективности и сумм их составляющих 
 * по оспариваемому и выше результатам необходимо сразу обращаться для 
 * разрешения спора пар к правилу №11, а не переходить к рассмотрению более 
 * низких результатов за танцы, как в правилах №№7 - 8.
 * 
 * № пар 	W 	T 	F 	Q 	Сумма 	Коэффициент эффективности 	Место
 * 1 	1-3 	1-5
 * 17 	1 	1 	2 	5 	9 	2 	  	  	1
 * 27 	3 	3 	1 	2 	9 	1 	  	  	2
 * 37 	2 	5 	4 	4 	15 	  	1 	  	4
 * 47 	4 	2 	3 	6 	15 	  	2 	  	3
 * 57 	6 	6 	5 	1 	18 	  	  	2 	6
 * 67 	5 	4 	6 	3 	18 	  	  	3 	5
 * 
 * Пары №17 и №27 имеют равную наименьшую сумму для занятия первого места. 
 * Пара №17 два раза выиграла отдельные танцы, а пара №27 только один. Поэтому, 
 * пара №17 занимает 1-е место, а пара №27 - второе. Пары № 37 и №47 имеют 
 * равную сумму для занятия третьего места. Пара №37 один раз занимала в 
 * танцах результаты с 1-го по 3-е (W - 2), а пара №47 - два раза 
 * (T - 2 , F - 3). Поэтому, пара №47 занимает третье место, а пара №37 - 
 * четвертое. Аналогично распределяются места между парами №57 и №67, но 
 * распределение происходит уже по "1 - 5" результатам. Еще один пример к 
 * правилу 10 :
 * 
 * 
№ пар 	W 	T 	Vw 	Q 	Сумма 	Коэффициент эффективности 	Место
1 	1-3 	1-5
30 	5 	5,5 	2 	5 	17,5 	  	  	3(12) 	6
31 	4 	3,5 	6 	4 	17,5 	  	  	3(11,5) 	5
32 	2 	2 	3 	1 	8 	1 	  	  	2
33 	3 	1 	1 	3 	8 	2 	  	  	1
34 	1 	5,5 	4 	6 	16,5 	  	1(1) 	  	3
35 	6 	3,5 	5 	2 	16,5 	  	1(2) 	  	4

Пары №32 и №33 по итоговой сумме претендуют на 1-е место. Коэффициент эффективности по 1-м результатам у пары №33 (2) выше, чем у пары №32 (1), поэтому паре №33 присуждается 1-е место, а паре №32 - второе.

Пары №34 и №35 по итоговой сумме претендуют на 3-е место. Коэффициент эффективности по "1-3" результатам у них одинаковый (1). Сумма составляющих коэффициента у пары №34 (1) ниже, чем у пары №35 (2), поэтому паре №34 присуждается 3-е место, а паре №35 - четвертое. Пары №30 и №31 по итоговой сумме претендуют на 5-е место. Коэффициент эффективности по "1-5" результатам у них одинаковый (3). Сумма составляющих коэффициента эффективности у пары №31 (11.5) ниже, чем у пары №30 (12), поэтому паре №31 присуждается 5-е место, а паре №30 - шестое. Еще один пример применения правила 10 в случае, если несколько пар набирают одинаковую итоговую сумму:
№ пар 	W 	T 	F 	Q 	Сумма 	Коэффициент эффективности 	Место
1 	1-2 	1-3 	1-5
20 	1 	5 	6 	1 	13 	2 	  	  	  	1
21 	2 	3 	2 	6 	13 	- 	2(4) 	3(7)
22 	6 	1 	4 	2 	13 	1 	2(3) 	  	  	2
23 	5 	2 	3 	3 	13 	- 	1 	3(8)
24 	4 	6 	1 	5 	16 	  	  	  	3 	6
25 	3 	4 	5 	4 	16 	  	  	  	4 	5

Четыре пары (№20, № 21, №22, № 23) по итоговой сумме претендуют на 1-е место. Пара №20 имеет наибольший из четырех пар коэффициент эффективности по 1-м местам. Ей присуждается 1-е место. Оставшиеся пары (№21, №22, №23) становятся равными претендентами на 2-е место. Две пары (№21, №22) имеют наибольший из трех и притом равный коэффициент эффективности по "1-2" результатам (2). У пары №22 сумма составляющих коэффициента меньше (1+2=3), чем у пары №21 (2+2=4). Поэтому паре №22 присуждается 2-е место. Две оставшиеся пары становятся равными претендентами на 3-е место. Коэффициенты эффективности и суммы их составляющих по "1-3" результатам у них равны. Поэтому решение спора о распределении 3 и 4 мест для этих пар возможно только с применением правила №11.
 ******************************************************************************/
bool udfSkatingRules::Rule10()
{
	Enter();
	bool res = true;
	do
	{
		int jMost = m_nJudges / 2 + 1;
		
		__msg("Rule 6");

		//res = true;
	}while(0);
	Leave();
	return res;
}

/*******************************************************************************
 * Применяется в случае, если после применения правил 9 и 10 несколько пар продолжают спор между собой на присвоение очередного места. Такая ситуация может возникнуть, если:

а) "коэффициенты эффективности" по оспариваемому и выше результатам, а также сумма их составляющих у нескольких пар равны;

б) "коэффициент эффективности" по оспариваемому и выше результатам у нескольких пар равен нулю (отсутствует). Этот вариант можно рассматривать, как частный случай варианта а).
№ пар 	W 	T 	F 	Q 	Сумма 	Коэффициент эффективности 	Место
1 	1-3 	1-5
12 	1 	3 	1 	1,5 	6,5 	2 	  	  	1
13 	2 	1 	2 	1,5 	6,5 	1 	  	  	2
14 	4 	4 	6 	3,5 	17,5 	  	- 	  	?
15 	5 	5 	4 	3,5 	17,5 	  	- 	  	?
16 	6 	2 	5 	5 	18 	  	  	3 	5
17 	3 	6 	3 	6 	18 	  	  	2 	6

Две пары (№14 и №15), претендуя по итоговой сумме на 3-е место, не имеют в результатах за танцы ни одного результата 1-3. В этом случае обращаются к правилу №11 и учитывают все оценки, поставленные судьями претендующим на присвоение очередного места парам во всех танцах (т.е. рассматриваются все танцы финала как один), и к этим оценкам, начиная с колонки оспариваемой и выше оценки, применяют правила №№5-8. Под необходимым большинством при этом понимается более половины числа, получаемого в результате умножения количества судей на количество танцев в финале. (Пример: 4 танца оценивались 5-ю судьями, необходимое большинство = 11. Еще пример: 5 танцев оценивались 7-ю судьями, необходимое большинство =18).

Пример применения правила 11:
  	Самба 	  	Ча-ча-ча 	  	Румба 	  	Джайв
№ 	A 	B 	C 	D 	E 	Рез 	  	A 	B 	C 	D 	E 	Рез 	  	A 	B 	C 	D 	E 	Рез 	  	A 	B 	C 	D 	E 	Рез
71 	2 	6 	4 	4 	5 	6 	  	6 	6 	6 	6 	6 	6 	  	1 	4 	4 	5 	4 	5 	  	5 	4 	3 	3 	6 	5
72 	3 	5 	2 	1 	1 	1 	  	4 	3 	2 	2 	1 	1 	  	5 	1 	5 	2 	2 	2 	  	1 	6 	2 	6 	2 	2
73 	5 	2 	5 	2 	2 	2 	  	2 	2 	1 	3 	5 	2 	  	2 	5 	2 	1 	1 	1 	  	2 	5 	1 	5 	1 	1
74 	4 	4 	1 	6 	6 	5 	  	5 	5 	5 	5 	2 	5 	  	4 	6 	6 	4 	6 	6 	  	6 	3 	6 	4 	4 	6
75 	1 	1 	3 	5 	4 	3 	  	3 	1 	3 	1 	3 	3 	  	3 	2 	3 	6 	5 	4 	  	4 	2 	4 	2 	3 	4
76 	6 	3 	6 	3 	3 	4 	  	1 	4 	4 	4 	4 	4 	  	6 	3 	1 	3 	3 	3 	  	3 	1 	5 	1 	5 	3

№ пар 	S 	C 	R 	J 	Сумма 	Правило 10 	Правило 11 	Место
1 	1-3 	1-5 	(1) 	(1-2) 	(1-3) 	(1-5)
71 	6 	6 	5 	5 	22 	  	  	2(10) 	  	  	  	13(48) 	5
72 	1 	1 	2 	2 	6 	2(2) 	  	  	5 	12 	  	  	2
73 	2 	2 	1 	1 	6 	2(2) 	  	  	5 	13 	  	  	1
74 	5 	5 	6 	6 	22 	  	  	2(10) 	  	  	  	13(50) 	6
75 	3 	3 	4 	4 	14 	  	2(6) 	  	  	  	14 	  	3
76 	4 	4 	3 	3 	14 	  	2(6) 	  	  	  	11 	  	4

Пары №72 и №73 по итоговой сумме претендуют на 1-е место. Коэффициенты эффективности по 1-м результатам и суммы составляющих у них также равны. Возникает необходимость обратиться ко всем оценкам пар во всех танцах. Необходимое большинство: (4танца * 5судей)+1=11. Количество судейских оценок "1" у обеих пар (5) меньше необходимого большинства (11), поэтому переходим к колонке оценок "1-2". У пары №73 "1-2" оценок больше (13), чем у пары №72(12), поэтому, паре №73 присуждается 1-е место, а паре №72 - второе. Аналогично распределяются 3 и 4 места между парами №75 и №76. Для решения вопроса о распределении 5 и 6 мест между парами №71 и №74 необходимо не только посчитать коэффициенты эффективности, сумму их составляющих, обратиться к "большому скейтингу" всех оценок этих пар за все танцы по "1-5" оценкам, но и посчитать сумму составляющих "1-5" оценок по всем танцам. 71-ей паре с меньшей суммой составляющих (48) присуждается 5-е место, 74-ой 6-е место (50).

До тех пор, пока не распределены места в группе пар, к которым при меняется правило №11, нельзя переходить к распределению мест для остальных пар (т.е. эти пары этой группы получают приоритет перед остальными при распределении оспариваемых ими мест).

Как только одной из пар этой группы будет присвоено очередное место, оставшиеся пары из этой группы станут равными претендентами на присвоение следующего места ( с повторным применением правила №10, но уже по следующему за присужденным месту).

Еще раз обратим внимание на очень важную особенность применения правила №11:

а) решение спора пар об очередном месте в №11 правиле сразу начинается с заполнения колонки оспариваемой и выше оценок, а не с колонки первых и т.д., как в правилах №№5 - 8.

б) дальнейший ход расчета аналогичен расчету по правилам №№5 - 8 (НО С ДРУГИМ ЗНАЧЕНИЕМ НЕОБХОДИМОГО БОЛЬШИНСТВА).

Если применение правила №11 не дает ответа на вопрос о распределении мест между парами (такой случай маловероятен, но все же возможен. Например, пары получат у судей во всех танцах финала одинаковое количество одинаковых оценок с точностью до перестановки), то в этом случае организаторы соревнований и главный судья решают, присудить ли место, на которое претендуют эти пары, всем парам, либо провести перетанцовку.
 ******************************************************************************/
bool udfSkatingRules::Rule11()
{
	Enter();
	bool res = true;
	do
	{
		int jMost = m_nJudges / 2 + 1;
		
		__msg("Rule 6");

		//res = true;
	}while(0);
	Leave();
	return res;
}
