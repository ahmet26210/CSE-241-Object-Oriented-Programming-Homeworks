#ifndef PACK_H2_
#define PACK_H2_
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include"pack1.h"
using namespace std;
namespace hex_kurban{
	class HexArray1D:public AbstractHex
	{
	public:
		HexArray1D();
		HexArray1D(const int& _size);
		virtual ~HexArray1D();
		HexArray1D(HexArray1D& anotherObject);
		virtual HexArray1D& operator=(HexArray1D& anotherObject); 
	private:
		Cell& gettempCell(int i,int j) override;
		Cell& operator()(int i,int j) override;
		void readFromFile(string file_name1) override;
		Cell* HexCells;
		Cell* temp_arrey;
	};
}
#endif