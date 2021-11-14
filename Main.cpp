#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

//Назарчук Сергій ТК-32
//ДЗ 3, 4
//Варіант 32

string Funk(string str)
{
	cmatch result;
	regex regular1(
		"([0-9]+\.[0-9])"                         //відносна вологість
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"(0?[1-9]|[12][0-9]|3[01])"               //день
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"(0?[1-9]|1[012])"                        //місяць
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"([A-Za-z0-9]{4,6})"                      //код метеостанції
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"([0-9]+\.[0-9])"                         //сила вітру
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"([0-9]+)"                                //кількість опадів
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"([0-9]{4})"                              //рік
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"([-]?[0-9]+\.[0-9])"                     //максимальна денна температура
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"([-]?[0-9]+\.[0-9])"                     //середня денна температура
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"([-]?[0-9]+\.[0-9])"                     //мінімальна денна температура
	);
	regex regular2("([A-Za-z0-9]{4,6})");
	regex regular3("[:?]");
	regex regular4(
		"([0-9]+\.[0-9])"                     //відносна вологість
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"(0?[1-9]|[12][0-9]|3[01])"           //день
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"(0?[1-9]|1[012])"                    //місяць
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
		"([A-Za-z0-9]{4,6})"                  //код метеостанції
		"([ |\t]*)"
		"([;:?])"
		"([ |\t]*)"
	);
	cmatch result1;
	string str2 = "";
	if (regex_match(str.c_str(), result, regular1))
	{
		bool is = regex_search(str.c_str(), result1, regular4);
		for (int i = 1; i < result1.size(); i++)
			str2 += result[i];
		string str3 = regex_replace(str2.c_str(), regular2, "*****");
		string str4 = regex_replace(str.c_str(), regular4, str3);
		return regex_replace(str4.c_str(), regular3, ";");
	}
	return str;
}

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	if (fin.is_open()) {
		string str;
		while (getline(fin, str))
		{
			fout << Funk(str) << endl;
		}
		system("pause");
	}
	else {
		cout << "File not found" << endl;
		system("pause");
	}
	return 0;
}