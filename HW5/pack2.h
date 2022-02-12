#ifndef PACK_H1_
#define PACK_H1_
#include<string>
#include<iostream>
#include<fstream>
#include<exception>
#include<vector>
#include"pack1.h"
using namespace std;
namespace hex_kurban{
	class HexVector:public AbstractHex
	{
	public:
		HexVector();
		HexVector(const int& _size);
		virtual ~HexVector(){};
	private:
		Cell& gettempCell(int i,int j) override;
		Cell& operator()(int i,int j) override;
		void readFromFile(string file_name1) override;
		vector<vector<Cell> > HexCells;
		vector<vector<Cell> > temp_arrey;
	};
}
#endif