#ifndef PACK_H_
#define PACK_H_

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
enum cells{User1='x',User2='o',empty='*',computer='o'};
class HEX
{
public:
	HEX(const int& _size); //CONSTRUCTER
	HEX();//CONSTRUCTER
	inline int getSize()	const					{return size;}//THIS RETURNS THE SIZE OF BOARD
	inline void setSize(const int _size)			{size=_size;}//THIS SET SIZE OF THE BOARD
	inline char getControl()	const				{return control;}
	inline void setControl(const char _control)		{control=_control;}
	inline char getControl1()	const				{return control1;}
	inline void setControl1(const char _control1)	{control1=_control1;}
	inline string getFilename()	const				{return file_name;}
	inline void setFilename(const string _file_name){file_name=_file_name;}
	inline int getLastp_x()		const				{return lastp_x;}//FOR CONTROLLİNG THE COMPUTER MOVE AND CHECK END GAME FUNCTİON
	inline void setLastp_x(const int _lastp_x)		{lastp_x=_lastp_x;}
	inline int getLastp_y()		const				{return lastp_y;}//FOR CONTROLLİNG THE COMPUTER MOVE AND CHECK END GAME FUNCTİON
	inline void setLastp_y(const int _lastp_y)		{lastp_y=_lastp_y;}
	inline int getTempi()		const				{return tempi;}//I FIND FİRST X OR FİRST O ON BOARD TO CHECK END GAME FUNCTİON
	inline void setTempi(const int _tempi)			{tempi=_tempi;}
	inline int getTempj()		const				{return tempj;}
	inline void setTempj(const int _tempj)			{tempj=_tempj;}
	inline int getCounter()		const				{return counter;}//TO CONTROL COMPUTER GAME WHİCH MOVE IT WILL MAKE
	inline void setCounter(const int _counter)		{counter=_counter;}
	inline int getfullcell()		const			{return fullcell;}//WE SAVE THE FİLLED CELL OF ALL GAME
	inline void setfullcell(const int _fullcell)	{fullcell=_fullcell;}
	inline int getCounter1()		const			{return counter1;}
	inline void setCounter1(const int _counter1)	{counter1=_counter1;}
	inline char getCurrentPlayer()		const		{return currentPlayer;}//WE GET THE CURRENT PLAYER TO CHECK PLAY FUNCTİON WHİCH ONE MAKE MOVE
	inline void setCurrentPlayer(const char _currentPLayer)	{currentPlayer=_currentPLayer;}
	inline static int getCount()					{return Markedcount;}//WE SAVE THE FİLLED CELL OF ONE GAME
	inline static void setCount(int _markedcount)	{Markedcount=_markedcount;}
	void save_file();
	void load_file();
	void up_words_o();
	void up_words_x(); //in this function we are starting the last point of board_size of x words
						//we check all connected points and we recursive function that points by one by
					   //All connected words is up the function will end 
	bool control_moves_o();
	bool control_moves_x();//In this function we start the first point and we check all directions if there is a 'x' we will recursive that point
						 	//This situation is to be continued all horizontal points are filled and return last point to call up_words funcion
							 //of course this points have to be connected to each other
	bool end_game_computer();//CHECK THE GAME END OR CONTINUE
	bool end_game_user2();
	bool end_game_user1();
	void iterate_func1();//FOR TEMP_ARREY VECTOR
	void play();//MAKE MOVE FOR COMPUTER
	void playGame();//MAIN FUNCTİON GAME İS STARTİNG WİTH THİS FUNCTİON
	void play(int number1,int number2);//This function make move for both of user1 and user2
	bool compareGame(const HEX& anotherObject);
	void is_valid();
	void print_function();//This function is printing the current board_size arrey to see current situation
	void findMarked();
private:
	string file_name;
	static int Markedcount;//ALL FİLLED CELL IN  GAME
	char control,control1;
	int lastp_x,lastp_y;
	int tempi,tempj;
	int counter;
	char currentPlayer;
	int counter1;
	int fullcell;//RETURN FILLED CELL SAVED MARKEDCOUNT
	class Cell//INNER CLASS
	{
	public:
		Cell();//CONSTRUCTER
		inline char getColumn() const 				{return row;}
		inline int  getRow() const 					{return column;}
		inline char getCell() const 				{return charcell;}
		inline void setcell(char _charcell) 		{charcell=_charcell;}//ENUM
		inline void setColumn(char _column)  		{column=_column;}
		inline void setRow(int _row) 				{row=_row;}
	private:
		char charcell;//WHİCH ENUM HAS THIS CELL
		char column;
		int row;
	};
	vector<vector<Cell>> temp_arrey;//2D VECTOR
	vector<vector<Cell>> hexcells;//2D VECTOR
	int size;//SIZE OF THE GAME
};

#endif