#include"pack2.h" 
namespace hex_kurban{
	HexVector::HexVector():AbstractHex(11){
		Cell a;
		HexCells.resize(getSize());//WE RESIZE THE VECTOR
		temp_arrey.resize(getSize());
		for (int i = 0; i < getSize(); i++)
		{
			for (int j = 0; j<getSize(); j++)
			{
				HexCells[i].push_back(a);//WE PUSH BACK THE VECTOR TO CREAT THE 2D VECTOR 
				temp_arrey[i].push_back(a);
			}
		}
	}
	HexVector::HexVector(const int& _size):AbstractHex(_size){
		Cell a;
		HexCells.resize(getSize());//WE RESIZE THE VECTOR
		temp_arrey.resize(getSize());
		for (int i = 0; i < getSize(); i++)
		{
			for (int j = 0; j<getSize(); j++)
			{
				HexCells[i].push_back(a);//WE PUSH BACK THE VECTOR TO CREAT THE 2D VECTOR 
				temp_arrey[i].push_back(a);
			}
		}
	}
	void HexVector::readFromFile(string file_name1){
		ifstream save_load_file;
		save_load_file.open(file_name1);
		char data,free;
		int control=0,control1=0,lastp;
		int num1,num2;
		int i=0 , j=0;
		int size2;
		char currentplayer;
		int lastpoint;
		string line,str,size1; 
		if(!save_load_file.fail()){//for avoiding to open unexist file
			while(!save_load_file.eof()){//to reach end of file
				if(control1==0){
					getline(save_load_file,size1);
					size2=stoi(size1);
					setSize(size2);
					getline(save_load_file,line);
					Cell a;
					HexCells.resize(getSize());
					temp_arrey.resize(getSize());
					for (int i = 0; i < getSize(); i++)
					{
						for (int j = 0; j<getSize(); j++)
						{
							HexCells[i].push_back(a);
							temp_arrey[i].push_back(a);
						}
					}
					control1++;
				}
				if(j==0&&i<9){
					save_load_file>>free;//FOR 1 2 3 4 NUMBERS
				}
				else if(j==0){
					save_load_file>>free;
					save_load_file>>free;
				}
				save_load_file>>data;//we are reading the data from file
				(*this)(i,j).setcell(data);//then we send board size
				if(j==getSize()-1 && i==getSize()-1){ //if we reach end of board size file will end
					moves.clear();
					moves.resize(getSize()*getSize());
					for (int i = 0; i < getSize()*getSize(); i++)
					{
						for (int j = 0; j<2; j++)
						{
							moves[i].push_back(0);
						}
					}
					getline(save_load_file,line);
					getline(save_load_file,str);
					save_load_file>>currentplayer;
					getline(save_load_file,line);
					getline(save_load_file,line);
					save_load_file>>lastp;
					lastpoint=lastp;
					lastpoint=lastp;
					for (int m = 0; m < lastpoint; ++m)
					{
						save_load_file>>data;
						save_load_file>>num1;
						save_load_file>>data;
						save_load_file>>num2;
						save_load_file>>data;
						moves[m][0]=num1;
						moves[m][1]=num2;
					}
					break;
				}
				else if(j==getSize()-1){
					getline(save_load_file,line);//to read space
					i++;
					j=0;
				}
				else{
					j++;
				}
			}
			control=1;
			if(str.compare("USERVSUSER")==0){
				print_function();
				setControl1('u');
				setCurrentPlayer(currentplayer);
			}
			else if(str.compare("USERVSCOMPUTER")==0){
				print_function();
				setControl1('c');
			}
		}
		if(control==0){ 
			cerr<<"İnvalid File! Please enter a file name which has been created before"<<endl<<endl;
		}
		save_load_file.close();
	}
	Cell& HexVector::gettempCell(int i,int j){
		return temp_arrey[i][j];
	}
	Cell& HexVector::operator()(int i,int j){
		try{
			if(size<=i || size<=j) throw bad_index();
			return HexCells[i][j];
		}
		catch(bad_index &e)
		{
			cout<<e.what();
		}
	}
} 