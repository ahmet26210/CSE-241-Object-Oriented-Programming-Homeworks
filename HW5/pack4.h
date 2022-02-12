#ifndef PACK_H4_
#define PACK_H4_
#include<string>
#include<iostream>
#include<fstream>
#include<exception>
#include"pack1.h"
#include<vector>
using namespace std;
namespace hex_kurban{
	template <template<class ...>class T> 
		class HexAdepter:public AbstractHex
		{
		public:
			HexAdepter();
			HexAdepter(const int& _size);
			virtual ~HexAdepter(){};
		private:
			Cell& gettempCell(int i,int j) override;
			Cell& operator()(int i,int j) override;
			void readFromFile(string file_name1) override;
			T<T<Cell> > HexCells;
			T<T<Cell> > temp_arrey;
		};
}
#endif