#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

int sort_num = 10000000;
int memory_size = 250000;
//每次只对250k 个小数据量进行排序

int read_data(FILE *fp, int *space)
{
	int index = 0;
	while (index < memory_size && fscanf(fp, "%d ", &space[index]) != EOF)
		index++;
	return index;
}

void write_data(FILE *fp, int *space, int num)
{
	int index = 0;
	while (index < num) {
		fprintf(fp, "%d ", space[index]);
		index++;
	}
}

// check the file pointer whether valid or not.
void check_fp(FILE *fp)
{
	if (fp == NULL) {
		cout << "The file pointer is invalid!" << endl;
		exit(1);
	}
}

int compare(const void *first_num, const void *second_num)
{
	return *(int *)first_num - *(int *)second_num;
}

string new_file_name(int n)
{
	char file_name[20];
	sprintf(file_name, "data%d.txt", n);
	return file_name;
}

int memory_sort()
{
	// open the target file.
	FILE *fp_in_file = fopen("data.txt", "r");
	check_fp(fp_in_file);
	int counter = 0;

	while (true)
	{
		// allocate space to store data read from file.
		int *space = new int[memory_size];
		int num = read_data(fp_in_file, space);
		// the memory sort have finished if not numbers any more.
		if (num == 0)
			break;

		// quick sort.
		qsort(space, num, sizeof(int), compare);
		// create a new auxiliary file name.
		string file_name = new_file_name(++counter);
		FILE *fp_aux_file = fopen(file_name.c_str(), "w");
		check_fp(fp_aux_file);
		// write the orderly numbers into auxiliary file.
		write_data(fp_aux_file, space, num);
		fclose(fp_aux_file);
		delete []space;
	}
	fclose(fp_in_file);

	// return the number of auxiliary files.
	return counter;
}

void merge_sort(int file_num)
{
	if (file_num <= 0)
		return;

	// create a new file to store result.
	FILE *fp_out_file = fopen("result.txt", "w");
	check_fp(fp_out_file);
	// allocate a array to store the file pointer.
	FILE **fp_array = new FILE *[file_num];
	int i;
	for (i = 0; i < file_num; i++) {
		string file_name = new_file_name(i + 1);
		fp_array[i] = fopen(file_name.c_str(), "r");
		check_fp(fp_array[i]);
	}
	int *first_data = new int[file_num];
	//new 出个大小为0.1 亿/250k 数组，由指针first_data 指示数组首地址
	bool *finish = new bool[file_num];
	memset(finish, false, sizeof(bool) * file_num);
	// read the first number of every auxiliary file.
	for (i = 0; i < file_num; i++) 
		fscanf(fp_array[i], "%d ", &first_data[i]);

	while (true) {
		int index = 0;
		while (index < file_num && finish[index])
			index++;
		// the finish condition of the merge sort.
		if (index >= file_num)
			break;
		//主要的修改在上面两行代码，就是merge sort 结束条件。
		//要保证所有文件都读完，必须使得finish[0]...finish[40]都为真
		//July、yansha，555，2011.05.29。
		int min_data = first_data[index];
		// choose the relative minimum in the array of first_data.
		for (i = index + 1; i < file_num; i++) {
			if (min_data > first_data[i] && !finish[i])
			//一旦发现比min_data 更小的数据first_data[i]
			{
			min_data = first_data[i];
			//则置min_data<-first_data[i]index = i;
			//把下标i 赋给index。
			}
		}
		// write the orderly result to file.
		fprintf(fp_out_file, "%d ", min_data);
		if (fscanf(fp_array[index], "%d ", &first_data[index]) == EOF)
			finish[index] = true;
	}
	fclose(fp_out_file);
	delete []finish;
	delete []first_data;

	for (i = 0; i < file_num; i++)
		fclose(fp_array[i]);
	delete [] fp_array;
}

int main()
{
	clock_t start_memory_sort = clock();
	int aux_file_num = memory_sort();
	clock_t end_memory_sort = clock();
	cout << "The time needs in memory sort: " << end_memory_sort - start_memory_sort << endl;

	clock_t start_merge_sort = clock();
	merge_sort(aux_file_num);
	clock_t end_merge_sort = clock();
	cout << "The time needs in merge sort: " << end_merge_sort - start_merge_sort << endl;
	
	//FILE *f = fopen("data.txt","w");
	//if(!f) 
	//	cout<<"cant open the file."<<endl;

	//for(int i=0;i<250000*2;++i) {   //250000   //1024*2 每次写入 单字符 文件的大小是 2KB
	//	fprintf(f,"%d ",rand()%2000);  //2164KB
	//}

	//fclose(f);

	system("pause");

	return 0;
}