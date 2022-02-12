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
	explicit HEX(const int& _size); //CONSTRUCTER WİTH EXPLİCİT HEX OBJE=42; DOESNT WORK
	explicit HEX();//CONSTRUCTER
	~HEX();
	HEX(const HEX& copyobject);//COPY CONSTRUCTER	
	int getSize()	const					{return size;}//THIS RETURNS THE SIZE OF BOARD
	char getControl()	const				{return control;}
	char getControl1()	const				{return control1;}
	string getFilename()	const			{return file_name;}
	int getLastp_x()		const			{return lastp_x;}//FOR CONTROLLİNG THE COMPUTER MOVE AND CHECK END GAME FUNCTİON
	int getLastp_y()		const			{return lastp_y;}//FOR CONTROLLİNG THE COMPUTER MOVE AND CHECK END GAME FUNCTİON
	int getlastpoint()		const			{return lastpoint;}//FOR CONTROLLİNG THE COMPUTER MOVE AND CHECK END GAME FUNCTİON
	int getTempi()		const				{return tempi;}//I FIND FİRST X OR FİRST O ON BOARD TO CHECK END GAME FUNCTİON
	int getTempj()		const				{return tempj;}
	int getCounter()		const			{return counter;}//TO CONTROL COMPUTER GAME WHİCH MOVE IT WILL MAKE
	int getfullcell()		const			{return fullcell;}//WE SAVE THE FİLLED CELL OF ALL GAME
	void setfullcell(const int _fullcell)	{fullcell=_fullcell;}
	bool getEndgame()	const 				{return endgame;}		
	int getCounter1()		const			{return counter1;}
	char getCurrentPlayer()		const		{return currentPlayer;}//WE GET THE CURRENT PLAYER TO CHECK PLAY FUNCTİON WHİCH ONE MAKE MOVE
	int getCountUser()		const			{return count;}
	int getScore()		const				{return Score;}
	void operator--(int ignoreMe);
	void operator--();
	friend ostream& operator<<(ostream& output,const HEX& anotherObject);
	friend istream& operator>>(istream& input,HEX& anotherObject);
	static int getCount()					{return Markedcount;}//WE SAVE THE FİLLED CELL OF ONE GAME
	static void setCount(int _markedcount)	{Markedcount=_markedcount;}
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
	void playGame();//MAIN FUNCTİON GAME İS STARTİNG WİTH THİS FUNCTİON
	void play(int number1,int number2);//This function make move for both of user1 and user2
	bool operator==(const HEX& anotherObject) const;
	HEX& operator=(const HEX& assignObject);//ASSIGN OPERATOR 
	void is_valid();
	void findMarked();
	int ReturnScore();
	class Cell//INNER CLASS
	{
	public:
		Cell();//CONSTRUCTER
		int getColumn() const 				{return column;}
		int  getRow() const 				{return row;}
		char getCell() const 				{return charcell;}
		void setcell(char _charcell) 		{charcell=_charcell;}//ENUM
		void setRow(int _row) 				{row=_row;}//ENUM
		void setColumn(int _column) 		{column=_column;}//ENUM
	private:
		char charcell;//WHİCH ENUM HAS THIS CELL
		int column;
		int row;
	};
	HEX::Cell play();//MAKE MOVE FOR COMPUTER
private:
	string file_name;
	static int Markedcount;//ALL FİLLED CELL IN  GAME
	char control,control1;
	int lastp_x,lastp_y;
	int lastpoint;
	int tempi,tempj;
	int counter;
	char currentPlayer;
	int counter1;
	bool endgame;
	int fullcell;//RETURN FILLED CELL SAVED MARKEDCOUNT
	int Score;
	int count;
	Cell ** temp_arrey;//2D dynamic array
	Cell ** hexcells;//2D dynamic array
	int size;//SIZE OF THE GAME
	void setSize(const int _size)			{size=_size;}
	void setControl(const char _control)	{control=_control;}
	void setControl1(const char _control1)	{control1=_control1;}
	void setFilename(const string _file_name){file_name=_file_name;}
	void setLastp_x(const int _lastp_x)		{lastp_x=_lastp_x;}
	void setLastp_y(const int _lastp_y)		{lastp_y=_lastp_y;}
	void setTempi(const int _tempi)			{tempi=_tempi;}
	void setTempj(const int _tempj)			{tempj=_tempj;}
	void setCounter(const int _counter)		{counter=_counter;}
	void setCounter1(const int _counter1)	{counter1=_counter1;}
	void setCurrentPlayer(const char _currentPLayer)	{currentPlayer=_currentPLayer;}
	int ** moves;
};

#endif