#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

	//string inf_name = "raw_data.txt";
	string inf_name;
	std::cout << "input file name: ";
	std::cin >> inf_name;
	cout << "input: " << inf_name << endl;
	
    fstream inf;
    inf.open(inf_name, ios::in);
	if(!inf) {
        cout << "Error: file not available" << endl;
        return 1;
	}
	cout << "file open success: " << inf_name << endl;
	
	string buff;
	int drop_head = 24;
	int count = 0;
	float read_num = 0;
	float avg = 0;
	while( inf >> buff ) {
        if ( drop_head ) {
        	drop_head--;
        	continue;
		};
		
		inf >> buff >> read_num >> buff >> buff ;
		count++;
		avg += read_num;
	}
	
	avg = avg/count;

	cout << setprecision(10) << "read " << count << " samples , avg = " << avg << endl;	
	
	inf.close();
	inf.open(inf_name, ios::app);
	inf << "\n\navg: " << avg << " ( " << count << " samples )" << endl;
	
	system("pause");
	return 0;
}