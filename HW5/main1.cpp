#include"pack2.h"
#include"pack1.h"
#include"pack3.h"
#include"pack4.h"
#include"hexadepter.cpp"
#include<deque>
using namespace hex_kurban;
int main()
{
	int number;
	HexVector h1(11);//CREAT OBJECT
	h1.playGame();//START GAME
	number=h1.NumberOfMoves();
	cout<<"There is "<< number <<" moves this board made"<<endl;
	HexArray1D h2(12);
	h2.playGame();
	number=h2.NumberOfMoves();
	cout<<"There is "<< number <<" moves this board made"<<endl;
	HexArray1D h3(h2);
	h3.playGame();
	number=h3.NumberOfMoves();
	cout<<"There is "<< number <<" moves this board made"<<endl;
	HexArray1D h4;
	h4=h2;
	h4.playGame();
	number=h4.NumberOfMoves();
	cout<<"There is "<< number <<" moves this board made"<<endl;
	bool o=h4==h2;
	if(o==1) cout<<"Two boards are equal"<<endl;
	else{cout<<"Two boards are not equal"<<endl;}
	bool k=h4==h1;
	if(k==1)cout<<"Two boards are equal"<<endl;
	else{cout<<"Two boards are not equal"<<endl;}
	HexAdepter<vector> h5(11);
	h5.playGame();
	number=h5.NumberOfMoves();
	cout<<"There is "<< number <<" moves this board made"<<endl;
	HexAdepter<deque> h6(12);
	h6.playGame();
	number=h6.NumberOfMoves();
	cout<<"There is "<< number <<" moves this board made"<<endl;
	HexVector h7(11);
	HexArray1D h8(12);
	HexArray1D h11(9);
	HexAdepter<vector> h9(11);
	HexAdepter<deque> h10(12);
	AbstractHex* arr[5];
	arr[0]=&h7;
	arr[1]=&h8;
	arr[2]=&h9;
	arr[3]=&h10;
	arr[4]=&h11;
	GlobalFunction(arr,5);
	cout<<"GLOBAL FUNCTİON TEST IS STARTING HERE------------------"<<endl;
	cout<<"FIRST GAME TEST FUNCTION----------------------------------"<<endl;
	Function(&h7);
	cout<<"SECOND GAME TEST FUNCTION----------------------------------"<<endl;
	Function(&h8);
	cout<<"THIRD GAME TEST FUNCTION----------------------------------"<<endl;
	Function(&h9);
	cout<<"FOURTH GAME TEST FUNCTION----------------------------------"<<endl;
	Function(&h10);
	return 0;
}