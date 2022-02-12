
#include"pack.h"
int HEX::Markedcount = 0;
HEX::HEX(){
	control=' ',control1=' ';
	lastp_x=0,lastp_y=0;
	tempi=0,tempj=0;
	counter=0;
	currentPlayer=' ';
	counter1=0;
	fullcell=0;
	lastpoint=0;
	endgame=false;
	Score=0;
	count=0;
	size=15;
	hexcells=new Cell*[getSize()];
	for (int i = 0; i < getSize(); ++i)
	{
		hexcells[i]=new Cell[getSize()];
	}
	temp_arrey=new Cell*[getSize()];
	for (int i = 0; i < getSize(); ++i)
	{
		temp_arrey[i]=new Cell[getSize()];
	}
	moves=new int*[getSize()*getSize()];
	for (int i = 0; i < getSize()*getSize(); ++i)
	{
		moves[i]=new int[2];
	}
}
HEX::HEX(const int& _size){
	control=' ',control1=' ';
	lastp_x=0,lastp_y=0;
	tempi=0,tempj=0;
	counter=0;
	currentPlayer=' ';
	counter1=0;
	fullcell=0;
	lastpoint=0;
	endgame=false;
	Score=0;
	count=0;
	setSize(_size);
	hexcells=new Cell*[getSize()];
	for (int i = 0; i < getSize(); ++i)
	{
		hexcells[i]=new Cell[getSize()];
	}
	temp_arrey=new Cell*[getSize()];
	for (int i = 0; i < getSize(); ++i)
	{
		temp_arrey[i]=new Cell[getSize()];
	}
	moves=new int*[getSize()*getSize()];
	for (int i = 0; i < getSize()*getSize(); ++i)
	{
		moves[i]=new int[2];
	}
}
HEX::Cell::Cell(){
	setcell(empty);
}

HEX::HEX(const HEX& copyobject){//Copy constructer we copies member data of copyobject to another object
	if(copyobject.lastpoint>=0){//check the are there any moves
		size=copyobject.size;
		file_name=copyobject.file_name;
		control=copyobject.control,control1=copyobject.control1;
		lastp_x=copyobject.lastp_x,lastp_y=copyobject.lastp_y;
		lastpoint=copyobject.lastpoint;
		tempi=copyobject.tempi,tempj=copyobject.tempj;
		endgame=copyobject.endgame;
		counter=copyobject.counter,counter1=copyobject.counter1;
		currentPlayer=copyobject.currentPlayer;
		fullcell=copyobject.fullcell;
		Score=copyobject.Score;
		count=copyobject.count;
		hexcells=new Cell*[getSize()];
		for (int i = 0; i < getSize(); ++i)
		{
			hexcells[i]=new Cell[getSize()];
		}
		for (int a = 0; a < getSize(); ++a)
		{
			for (int b = 0; b < getSize(); ++b)
			{
				hexcells[a][b]=copyobject.hexcells[a][b];
			}
		}
		temp_arrey=new Cell*[getSize()];
		for (int i = 0; i < getSize(); ++i)
		{
			temp_arrey[i]=new Cell[getSize()];
		}
		for (int c= 0; c < getSize(); ++c)
		{
			for (int d = 0; d < getSize(); ++d)
			{
				temp_arrey[c][d]=copyobject.temp_arrey[c][d];
			}
		}
		moves=new int*[getSize()*getSize()];
		for (int i = 0; i < getSize()*getSize(); ++i)
		{
			moves[i]=new int[2];
		}
		for (int c = 0; c < copyobject.lastpoint; ++c)
		{
			moves[c][0]=copyobject.moves[c][0];
			moves[c][1]=copyobject.moves[c][1];
		}
		
	}
	else{//if there is no moves we add null
		file_name=' ';
		control=0,control1=0;
		lastp_x=0,lastp_y=0;
		lastpoint=0;
		tempi=0,tempj=0;
		counter=0,counter1=0;
		currentPlayer=' ';
		fullcell=0;
		endgame=false;
		temp_arrey=nullptr;
		hexcells=nullptr;
		moves=nullptr;
		size=12;
		Score=0;
		count=0;
	}
}
HEX::~HEX(){//Destructer delete all dynamic arrays
	if(hexcells){
		for (int i = 0; i < getSize(); ++i)
		{
			delete [] hexcells[i]; 
		}
		delete [] hexcells;
		hexcells=nullptr;
		for (int j = 0; j < getSize(); ++j)
		{
			delete [] temp_arrey[j]; 
		}
		delete [] temp_arrey;
		temp_arrey=nullptr;
		for (int k = 0; k < getSize()*getSize(); k++)
		{
			delete [] moves[k]; 
		}
		delete [] moves;
		moves=nullptr;
	}
}
void HEX::is_valid(){
	bool  valid=false;
	while(valid==false){
		if(getSize()<6){
			cout<<"Please enter the board size ,the size can be bigger than 5*5 "<<endl;
			cin>>size;
			setSize(size);
		}
		valid=true;
	}
}
void HEX::iterate_func1(){
	int i;
	decltype(i) j;
	for(i=0;i<getSize();i++){
		for(j=0;j<getSize();j++){
			temp_arrey[i][j].setcell(empty);//TO CONTROL IN CHECK FUNCTION NOT GO BACK WAS FILLED  BEFORE
		}
	}
}
void HEX::playGame(){
	int choose=0;
	bool control=false,control1=false,finish=false,control2=false;
	string command1,command2;
	int charcoordinate_temp1;
	bool end_game1=false,end_game2=false;
	Cell cell;
	char letter;
	int number;
	is_valid();
	cout<<(*this);//print first situation
	cout<<"If you play the game with user Please enter 1, If you play the game with computer enter 2"<<endl;
	cin>>choose;
	if(choose==1){
		setControl1('u');//CHECK TO PLAY USER
	}
	else if(choose==2){
		setControl1('c');//CHECK TO PLAY COMPUTER
	}
	if(getEndgame()==false){
		while(control2==false){
			if(getControl1()=='u'){//PLAY USER
				finish=false;
				while(finish==false){
					while(control==false){
						cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME  if you want to take back the game one move please enter UNDO GAME-- or UNDO --GAME for user 1"<<endl;
						cin>>command1>>command2;
						setCurrentPlayer(User1);//MAKE MOVE FOR USER1
						if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME" && command1!="UNDO" && command2!="GAME--" && command1!="UNDO" && command2!="--GAME"){
							letter=command1[0];
							number=stoi(command2);
							letter-=17;
							charcoordinate_temp1=letter-'0';
							number--;
							if(hexcells[number][charcoordinate_temp1].getCell()==empty){
								play(charcoordinate_temp1,number);
								cout<<(*this);//PRİNT FUNCTİON OVERLOADED WİTH <<
								control=true;
							}
							else{
								cerr<<"This place is not empty!Enter Again"<<endl;
							}
							end_game1=end_game_user1();
							if(end_game1==true){ 
								cout<<(*this);
								cout<<"User 1 is win !"<<endl;
								endgame=true;
								control1=true;
								finish=true;
								control2=true;	
							}
						}
						else if(command1=="SAVE"){
							setControl('u');//SAVE THE CURRENT PLAYER TO THE FILE
							setFilename(command2);
							save_file();
						}
						else if(command1=="LOAD"){
							setFilename(command2);
							load_file();
							if(getControl1()=='c'){
								control1=true;
								finish=true;
								control=true;
							}
							else if(getCurrentPlayer()==User2){
								break;
							}
						}
						else if(command1=="EXIT" && command2=="GAME"){//TO PASS THE ANOTHER GAME OR QUIT THE GAME
							control1=true;
							finish=true;
							control2=true;
							control=true;
						}
						else if(command1=="UNDO" && command2=="GAME--"){
							if(lastpoint!=0){
								(*this)--;
							}
							else{
								cerr<<"There is no move to go back!"<<endl;
							}
						}
						else if(command1=="UNDO" && command2=="--GAME"){
							if(lastpoint!=0){
								--(*this);
								if(getCurrentPlayer()==User2){
									break;
								}
							}
							else{
								cerr<<"There is no move to go back!"<<endl;
							}
						}
					}
					while(control1==false){
						cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME  if you want to take back the game one move please enter UNDO GAME-- or UNDO --GAME for user 2"<<endl;
						cin>>command1>>command2;
						setCurrentPlayer(User2);
						if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME" && command1!="UNDO" && command2!="GAME--" && command1!="UNDO" && command2!="--GAME"){
							letter=command1[0];
							number=stoi(command2);
							letter-=17;
							charcoordinate_temp1=letter-'0';
							number--;
							if(hexcells[number][charcoordinate_temp1].getCell()==empty){
								control1=true;
								play(charcoordinate_temp1,number);
								cout<<(*this);
							}
							else{
								cerr<<"This place is not empty!Enter Again"<<endl;
							}
							end_game2=end_game_user2();
							if(end_game2==true){
								cout<<(*this);
								endgame=true;
								cout<<"User 2 is win !"<<endl;
								finish=true;
								control2=true;
							}
						}
						else if(command1=="SAVE"){
							setControl('u');
							setFilename(command2);
							save_file();
						}
						else if(command1=="LOAD"){
							setFilename(command2);
							load_file();
							if(getControl1()=='c'){
								finish=true;
								control1=true;
							}
							else if(getCurrentPlayer()==User1){
								break;
							}
						}
						else if(command1=="EXIT" && command2=="GAME"){
							control1=true;
							finish=true;
							control2=true;
						}
						else if(command1=="UNDO" && command2=="GAME--"){
							if(lastpoint!=0 && lastpoint!=1){
								(*this)--;
							}
							else{
								cerr<<"There is no move to go back or User2 didnt make MOVE!"<<endl;
							}
						}
						else if(command1=="UNDO" && command2=="--GAME"){
							if(lastpoint!=0){
								--(*this);
								if(getCurrentPlayer()==User1){
									break;
								}
							}
							else{
								cerr<<"There is no move to go back!"<<endl;
							}
						}
					}
					control=false;
					control1=false;
				}
			}
		 	if(getControl1()=='c'){
		 		setCounter(0);
		 		finish=false;
				while(finish==false){
					while(control==false){
						cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME if you want to take back the game one move please enter UNDO GAME-- or UNDO --GAME for user 1"<<endl;
						cin>>command1>>command2;
						setCurrentPlayer(User1);
						if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME" && command1!="UNDO" && command2!="GAME--" && command1!="UNDO" && command2!="--GAME"){
							letter=command1[0];
							number=stoi(command2);
							letter-=17;
							charcoordinate_temp1=letter-'0';
							number--;
							if(hexcells[number][charcoordinate_temp1].getCell()==empty){
								play(charcoordinate_temp1,number);
								setLastp_x(number);
								setLastp_y(charcoordinate_temp1);
								cout<<(*this);
								control=true;
								Score=ReturnScore();
								if (Score==getSize())
								{
									cout<<"YOU REACH THE MAXIMUM USER POINTS: "<<Score*10<<endl<<endl;
								}
								else{cout<<"USER POINTS IS: "<<Score*10<<endl<<endl;}
								break;
							}
							else{
								cerr<<"This place is not empty!Enter Again"<<endl;
							}
							end_game1=end_game_user1();
							if(end_game1==true){
								cout<<(*this);
								cout<<"User 1 is win !"<<endl;
								endgame=true;
								control1=true;
								finish=true;
								control2=true;
							}
						}
						else if(command1=="SAVE"){
							setControl('c');
							setFilename(command2);
							save_file();
						}
						else if(command1=="LOAD"){
							setFilename(command2);
							load_file();
							if(getControl1()=='u'){
								control1=true;
								finish=true;
								control=true;
							}
						}
						else if(command1=="EXIT" && command2=="GAME"){
							control1=true;
							finish=true;
							control2=true;
							control=true;
						}
						else if(command1=="UNDO" && command2=="GAME--"){
							if(lastpoint!=0){
								(*this)--;
							}
							else{
								cerr<<"There is no move to go back!"<<endl;
							}
						}
						else if(command1=="UNDO" && command2=="--GAME"){
							if(lastpoint!=0){
								--(*this);//-- OPERATOR 
							}
							else{
								cerr<<"There is no move to go back!"<<endl;
							}
						}
					}
					while(control1==false){
						cell=play();
						setCounter(1);
						cout<<(*this);//PRİNT FUNCTİON WE OVERLOAD << OPERATOR
						control1=true;
						end_game2=end_game_computer();
						if(end_game2==true){
							cout<<(*this);
							endgame=true;
							cout<<"Computer Win!"<<endl;
							finish=true;
							control2=true;
						}
					}
					control=false;
					control1=false;
				}
			}
		}
	}
	else{
		cerr<<"THIS GAME WAS ENDED BEFORE SO YOU WİLL PASS THE ANOTHER GAME!"<<endl<<endl;
	}
}
void HEX::play(int number1,int number2){
	if(getCurrentPlayer()==User1){//USER1
		hexcells[number2][number1].setcell(User1);
		moves[getlastpoint()][0]=number2;
		moves[getlastpoint()][1]=number1;
		lastpoint++;//counter for moves 
	}
	else if(getCurrentPlayer()==User2){//USER2
		hexcells[number2][number1].setcell(User2);
		moves[getlastpoint()][0]=number2;
		moves[getlastpoint()][1]=number1;
		lastpoint++;
	}
}
bool HEX::end_game_user1(){
	int i,j=0;
	bool control=false;
	for(i=0;i<getSize();i++){
		if(hexcells[i][j].getCell()==User1){//we find first point and starting the recursion with finding x words
			iterate_func1();// temp_arrey is create for control the not returning to passing point with recursion 
			setTempi(i);
			setTempj(j);
			control=control_moves_x();//lastp_x and lastp_y created for computer game
			if(control==true){//if game end the connected words is up
				up_words_x();
				return true;// to end the game
			}
		}
	}
	return false;
}
bool HEX::end_game_user2(){
	int i=0,j=0;
	bool control=false;
	for(j=0;j<getSize();j++){
		if(hexcells[i][j].getCell()==User2){//we find first point and starting the recursion with finding o words
			iterate_func1();
			setTempi(i);
			setTempj(j);
			control=control_moves_o();
			if(control==true){
				up_words_o();
				return true;
			}
		}
	}
	return false;	
}
bool HEX::end_game_computer(){
	int i=0,j=0;
	bool control=false,control1=false;
	for(j=0;j<getSize();j++){
		if(hexcells[i][j].getCell()==User2){
			iterate_func1();
			setTempi(i);
			setTempj(j);
			control=control_moves_o();
			if(control==true){
				up_words_o();
				return true;
			}
		}
	}
	return false;	
}
HEX::Cell HEX::play(){
	int charcoordinate_temp2,coordinate2;
	char charcoordinate2;
	bool control=false;
	int computerp_x,computerp_y,i,j;
	int middle;
	Cell tempCell;
	middle=(getSize()+1)/2-1;//we find the middle of board
	if(getCounter()==0){
		if(hexcells[middle][middle].getCell()==User1 || hexcells[middle][middle].getCell()==User2){
			hexcells[middle][middle+1].setcell(computer);
			computerp_x=middle+1;
			computerp_y=middle+1;
			moves[getlastpoint()][0]=middle;//WE SAVE THE MOVES
			moves[getlastpoint()][1]=middle+1;
			lastpoint++;
			tempCell.setcell(computer);
			tempCell.setRow(middle);
			tempCell.setColumn(middle+1);
			return (tempCell);
		}
		else{
			hexcells[middle][middle].setcell(computer);//computer attend the middle of board always please let it do :)
			computerp_x=middle;
			computerp_y=middle;
			moves[getlastpoint()][0]=middle;
			moves[getlastpoint()][1]=middle;
			lastpoint++;
			tempCell.setcell(computer);
			tempCell.setRow(middle);
			tempCell.setColumn(middle);
			return (tempCell);
		}
	}
	if(getLastp_x()>middle && getCounter()>=1){	//LASTPX CHECK USER 1 POİNTS IF BIGGER THEN MIDDLE COMPUTER MAKE MOVE TO BOTTOM OTHERWISE MAKE MOVE TO TOP
		for(i=0;i<getSize();i++){
			for(j=0;j<getSize();j++){
				if(hexcells[i][j].getCell()==computer){//we find last o point in board 
					computerp_x=i;
					computerp_y=j;
				}
			}
		}
		if(computerp_x!=getSize()-1){
			if(hexcells[computerp_x+1][computerp_y].getCell()==User1 && hexcells[computerp_x+1][computerp_y-1].getCell()!=User1){
				hexcells[computerp_x+1][computerp_y-1].setcell(computer);
				moves[getlastpoint()][0]=computerp_x+1;
				moves[getlastpoint()][1]=computerp_y-1;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(computerp_x+1);
				tempCell.setColumn(computerp_y-1);
				return (tempCell);
			}
			else if(hexcells[computerp_x+1][computerp_y].getCell()!=User1){
				hexcells[computerp_x+1][computerp_y].setcell(computer);
				moves[getlastpoint()][0]=computerp_x+1;
				moves[getlastpoint()][1]=computerp_y;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(computerp_x+1);
				tempCell.setColumn(computerp_y);
				return (tempCell);
			}
		}
		else if(computerp_x==getSize()-1){
			for(i=0;i<getSize();i++){
				for(j=0;j<getSize();j++){
					if(hexcells[i][j].getCell()==computer){
						computerp_x=i;
						computerp_y=j;
						control=true;
						break;
					}
				}
				if(control==true) break;
			}
			if(hexcells[computerp_x-1][computerp_y].getCell()==User1 && hexcells[computerp_x-1][computerp_y+1].getCell()!=User1){
				hexcells[computerp_x-1][computerp_y+1].setcell(computer);
				moves[getlastpoint()][0]=computerp_x-1;
				moves[getlastpoint()][1]=computerp_y+1;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(computerp_x-1);
				tempCell.setColumn(computerp_y+1);
				return (tempCell);	
			}
			else if(hexcells[computerp_x-1][computerp_y].getCell()!=User1){
				hexcells[computerp_x-1][computerp_y].setcell(computer);
				moves[getlastpoint()][0]=computerp_x-1;
				moves[getlastpoint()][1]=computerp_y;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(computerp_x-1);
				tempCell.setColumn(computerp_y);
				return (tempCell);
			}
		}
	}
	else if(getLastp_x()<=middle && getCounter()>=1){
		for(i=0;i<getSize();i++){
			for(j=0;j<getSize();j++){
				if(hexcells[i][j].getCell()==computer){
					computerp_x=i;
					computerp_y=j;
					control=true;
					break;
				}
			}
			if(control==true) break;
		}
		if(computerp_x!=0){
			for(i=0;i<getSize();i++){
				for(j=0;j<getSize();j++){
					if(hexcells[i][j].getCell()==computer){
						computerp_x=i;
						computerp_y=j;
						control=true;
						break;
					}
				}
				if(control==true) break;
			}
			if(hexcells[computerp_x-1][computerp_y].getCell()==User1 && hexcells[computerp_x-1][computerp_y+1].getCell()!=User1){
				hexcells[computerp_x-1][computerp_y+1].setcell(computer);
				moves[getlastpoint()][0]=computerp_x-1;
				moves[getlastpoint()][1]=computerp_y+1;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(computerp_x-1);
				tempCell.setColumn(computerp_y+1);
				return (tempCell);
			}
			else if(hexcells[computerp_x-1][computerp_y].getCell()!=User1) {
				hexcells[computerp_x-1][computerp_y].setcell(computer);
				moves[getlastpoint()][0]=computerp_x-1;
				moves[getlastpoint()][1]=computerp_y;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(computerp_x-1);
				tempCell.setColumn(computerp_y);
				return (tempCell);
			}
		}
		else if(computerp_x==0){
			for(i=0;i<getSize();i++){
				for(j=0;j<getSize();j++){
					if(hexcells[i][j].getCell()==computer){//we find last o point in board 
						computerp_x=i;
						computerp_y=j;
					}
				}
			}
			if(hexcells[computerp_x+1][computerp_y].getCell()==User1 && hexcells[computerp_x+1][computerp_y-1].getCell()!=User1){
				hexcells[computerp_x+1][computerp_y-1].setcell(computer);
				moves[getlastpoint()][0]=computerp_x+1;
				moves[getlastpoint()][1]=computerp_y-1;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(computerp_x+1);
				tempCell.setColumn(computerp_y-1);
				return (tempCell);
			}
			else if(hexcells[computerp_x+1][computerp_y].getCell()!=User1) {
				hexcells[computerp_x+1][computerp_y].setcell(computer);
				moves[getlastpoint()][0]=computerp_x+1;
				moves[getlastpoint()][1]=computerp_y;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(computerp_x+1);
				tempCell.setColumn(computerp_y);
				return (tempCell);
			}
		}
	}
}
bool HEX::control_moves_x(){
	if(getTempj()+1==size){
		setLastp_x(getTempi()+1);//we keep the last x point to end game
		setLastp_y(getTempj()+1);
		cerr<<"a"<<endl;
		return true;
	}
	if(getTempi()!=0){
		if(hexcells[getTempi()-1][getTempj()].getCell()==User1){//kuzey
			if(temp_arrey[getTempi()-1][getTempj()].getCell()!=User1){//to avoid of going back to and avoid infinite loop
				temp_arrey[getTempi()-1][getTempj()].setcell(User1);
				setTempi(getTempi()-1);
				return control_moves_x(); //recursive to around existing x values
			}
		}
	}
	if(getTempi()!=size-1){
		if(hexcells[getTempi()+1][getTempj()].getCell()==User1){//güney
			if(temp_arrey[getTempi()+1][getTempj()].getCell()!=User1){
				temp_arrey[getTempi()+1][getTempj()].setcell(User1);
				setTempi(getTempi()+1);
				return control_moves_x();
			}
		}
	}
	if(getTempi()!=0 && getTempj()!=size-1){
		if(hexcells[getTempi()-1][getTempj()+1].getCell()==User1){//kuzeydoğu
			if(temp_arrey[getTempi()-1][getTempj()+1].getCell()!=User1){
				temp_arrey[getTempi()-1][getTempj()+1].setcell(User1);
				setTempi(getTempi()-1);
				setTempj(getTempj()+1);
				return control_moves_x();
			}
		}
	}
	if(getTempj()!=size-1){
		if(hexcells[getTempi()][getTempj()+1].getCell()==User1){//doğu
			if(temp_arrey[getTempi()][getTempj()+1].getCell()!=User1){
				temp_arrey[getTempi()][getTempj()+1].setcell(User1);
				setTempj(getTempj()+1);
				return control_moves_x();
			}
		}
	}
	if(getTempj()!=0){
		if(hexcells[getTempi()][getTempj()-1].getCell()==User1){//batı
			if(temp_arrey[getTempi()][getTempj()-1].getCell()!=User1){
				temp_arrey[getTempi()][getTempj()-1].setcell(User1);
				setTempj(getTempj()-1);
				return control_moves_x();
			}
		}
	}
	if(getTempi()!=size-1 && getTempj()!=0){
		if(hexcells[getTempi()+1][getTempj()-1].getCell()==User1){//güneybatı
			if(temp_arrey[getTempi()+1][getTempj()-1].getCell()!=User1){
				temp_arrey[getTempi()+1][getTempj()-1].setcell(User1);
				setTempi(getTempi()+1);
				setTempj(getTempj()-1);
				return control_moves_x();
			}
		}
	}
	return false;
}
bool HEX::control_moves_o(){
	if(getTempi()+1==size){
		setLastp_x(getTempi()+1);//we keep the last O point to end game
		setLastp_y(getTempj());
		return true;
	}
	if(getTempi()!=0){
		if(hexcells[getTempi()-1][getTempj()].getCell()==User2){//kuzey
			if(temp_arrey[getTempi()-1][getTempj()].getCell()!=User2){//to avoid of going back to and avoid infinite loop
				temp_arrey[getTempi()-1][getTempj()].setcell(User2);
				setTempi(getTempi()-1);
				return control_moves_o(); //recursive to around existing x values
			}
		}
	}
	if(getTempi()!=size-1){
		if(hexcells[getTempi()+1][getTempj()].getCell()==User2){//güney
			setTempi(getTempi()+1);
			return control_moves_o();
		}
	}
	if(getTempi()!=0 && getTempj()!=size-1){
		if(hexcells[getTempi()-1][getTempj()+1].getCell()==User2){//kuzeydoğu
			if(temp_arrey[getTempi()-1][getTempj()+1].getCell()!=User2){
				temp_arrey[getTempi()-1][getTempj()+1].setcell(User2);
				setTempi(getTempi()-1);
				setTempj(getTempj()+1);
				return control_moves_o();
			}
		}
	}
	if(getTempj()!=size-1){
		if(hexcells[getTempi()][getTempj()+1].getCell()==User2){//doğu
			if(temp_arrey[getTempi()][getTempj()+1].getCell()!=User2){
				temp_arrey[getTempi()][getTempj()+1].setcell(User2);
				setTempj(getTempj()+1);
				return control_moves_o();
			}
		}
	}
	if(getTempj()!=0){
		if(hexcells[getTempi()][getTempj()-1].getCell()==User2){//batı
			if(temp_arrey[getTempi()][getTempj()-1].getCell()!=User2){
				temp_arrey[getTempi()][getTempj()-1].setcell(User2);
				setTempj(getTempj()-1);
				return control_moves_o();
			}
		}
	}
	if(getTempi()!=size-1 && getTempj()!=0){
		if(hexcells[getTempi()+1][getTempj()-1].getCell()==User2){//güneybatı
			if(temp_arrey[getTempi()+1][getTempj()-1].getCell()!=User2){
				temp_arrey[getTempi()+1][getTempj()-1].setcell(User2);
				setTempi(getTempi()+1);
				setTempj(getTempj()-1);
				return control_moves_o();
			}
		}
	}
	return false;
}
void HEX::up_words_x(){
	if(getLastp_x()!=0){
		if(hexcells[getLastp_x()-1][getLastp_y()].getCell()==User1){//kuzey
			if(hexcells[getLastp_x()-1][getLastp_y()].getCell()!=User1-32){//to avoid the going back and to avoid infinite loop
				hexcells[getLastp_x()-1][getLastp_y()].setcell(User1-32);//up all connected words
				setLastp_x(getLastp_x()-1);
				up_words_x();//recursive to around existing x values
			}												//this function will end if the all connected x values are up
		}
	}
	if(getLastp_x()!=0 && getLastp_y()!=size-1){
		if(hexcells[getLastp_x()-1][getLastp_y()+1].getCell()==User1){//kuzeydoğu
			if(hexcells[getLastp_x()-1][getLastp_y()+1].getCell()!=User1-32){
				hexcells[getLastp_x()-1][getLastp_y()+1].setcell(User1-32);
				setLastp_x(getLastp_x()-1);
				setLastp_y(getLastp_y()+1);
				up_words_x();
			}
		}
	}
	if(getLastp_y()!=0){
		if(hexcells[getLastp_x()][getLastp_y()-1].getCell()==User1){//batı
			if(hexcells[getLastp_x()][getLastp_y()-1].getCell()!=User1-32){
				hexcells[getLastp_x()][getLastp_y()-1].setcell(User1-32);
				setLastp_y(getLastp_y()-1);
				up_words_x();
			}
		}
	}
	if(getLastp_y()!=size-1){
		if(hexcells[getLastp_x()][getLastp_y()+1].getCell()==User1){//doğu
			if(hexcells[getLastp_x()][getLastp_y()+1].getCell()!=User1-32){
				hexcells[getLastp_x()][getLastp_y()+1].setcell(User1-32);
				setLastp_y(getLastp_y()+1);
				up_words_x();
			}
		}
	}
	if(getLastp_x()!=size-1){
		if(hexcells[getLastp_x()+1][getLastp_y()].getCell()==User1){//güney
			if(hexcells[getLastp_x()+1][getLastp_y()].getCell()!=User1-32){
				hexcells[getLastp_x()+1][getLastp_y()].setcell(User1-32);
				setLastp_x(getLastp_x()+1);
				up_words_x();
			}
		}
	}
	if(getLastp_x()!=size-1 && getLastp_y()!=0){
		if(hexcells[getLastp_x()+1][getLastp_y()-1].getCell()==User1){//güneybatı
			if(hexcells[getLastp_x()+1][getLastp_y()-1].getCell()!=User1-32){
				hexcells[getLastp_x()+1][getLastp_y()-1].setcell(User1-32);
				setLastp_x(getLastp_x()+1);
				setLastp_y(getLastp_y()-1);
				up_words_x();
			}
		}
	}
	if(getLastp_x()!=0 && getLastp_y()!=0){
		if(hexcells[getLastp_x()-1][getLastp_y()-1].getCell()==User1){//kuzeybatı
			if(hexcells[getLastp_x()-1][getLastp_y()-1].getCell()!=User1-32){
				hexcells[getLastp_x()-1][getLastp_y()-1].setcell(User1-32);
				setLastp_x(getLastp_x()-1);
				setLastp_y(getLastp_y()-1);
				up_words_x();
			}
		}
	}
	if(getLastp_x()!=size-1 && getLastp_y()!=size-1){
		if(hexcells[getLastp_x()+1][getLastp_y()+1].getCell()==User1){//güneydoğu
			if(hexcells[getLastp_x()+1][getLastp_y()+1].getCell()!=User1-32){
				hexcells[getLastp_x()+1][getLastp_y()+1].setcell(User1-32);
				setLastp_x(getLastp_x()+1);
				setLastp_y(getLastp_y()+1);
				up_words_x();
			}
		}
	}
}
void HEX::up_words_o(){
	if(getLastp_x()!=0){
		if(hexcells[getLastp_x()-1][getLastp_y()].getCell()==User2){//kuzey
			if(hexcells[getLastp_x()-1][getLastp_y()].getCell()!=User2-32){//to avoid the going back and to avoid infinite loop
				hexcells[getLastp_x()-1][getLastp_y()].setcell(User2-32);//up all connected words
				setLastp_x(getLastp_x()-1);
				up_words_o();//recursive to around existing x values
			}												//this function will end if the all connected x values are up
		}
	}
	if(getLastp_x()!=0 && getLastp_y()!=size-1){
		if(hexcells[getLastp_x()-1][getLastp_y()+1].getCell()==User2){//kuzeydoğu
			if(hexcells[getLastp_x()-1][getLastp_y()+1].getCell()!=User2-32){
				hexcells[getLastp_x()-1][getLastp_y()+1].setcell(User2-32);
				setLastp_x(getLastp_x()-1);
				setLastp_y(getLastp_y()+1);
				up_words_o();
			}
		}
	}
	if(getLastp_y()!=0){
		if(hexcells[getLastp_x()][getLastp_y()-1].getCell()==User2){//batı
			if(hexcells[getLastp_x()][getLastp_y()-1].getCell()!=User2-32){
				hexcells[getLastp_x()][getLastp_y()-1].setcell(User2-32);
				setLastp_y(getLastp_y()-1);
				up_words_o();
			}
		}
	}
	if(getLastp_y()!=size-1){
		if(hexcells[getLastp_x()][getLastp_y()+1].getCell()==User2){//doğu
			if(hexcells[getLastp_x()][getLastp_y()+1].getCell()!=User2-32){
				hexcells[getLastp_x()][getLastp_y()+1].setcell(User2-32);
				setLastp_y(getLastp_y()+1);
				up_words_o();
			}
		}
	}
	if(getLastp_x()!=size){
		if(hexcells[getLastp_x()+1][getLastp_y()].getCell()==User2){//güney
			if(hexcells[getLastp_x()+1][getLastp_y()].getCell()!=User2-32){
				hexcells[getLastp_x()+1][getLastp_y()].setcell(User2-32);
				setLastp_x(getLastp_x()+1);
				up_words_o();
			}
		}
	}
	if(getLastp_x()!=size && getLastp_y()!=0){
		if(hexcells[getLastp_x()+1][getLastp_y()-1].getCell()==User2){//güneybatı
			if(hexcells[getLastp_x()+1][getLastp_y()-1].getCell()!=User2-32){
				hexcells[getLastp_x()+1][getLastp_y()-1].setcell(User2-32);
				setLastp_x(getLastp_x()+1);
				setLastp_y(getLastp_y()-1);
				up_words_o();
			}
		}
	}
	if(getLastp_x()!=0 && getLastp_y()!=0){
		if(hexcells[getLastp_x()-1][getLastp_y()-1].getCell()==User2){//kuzeybatı
			if(hexcells[getLastp_x()-1][getLastp_y()-1].getCell()!=User2-32){
				hexcells[getLastp_x()-1][getLastp_y()-1].setcell(User2-32);
				setLastp_x(getLastp_x()-1);
				setLastp_y(getLastp_y()-1);
				up_words_o();
			}
		}
	}
	if(getLastp_x()!=size && getLastp_y()!=size-1){
		if(hexcells[getLastp_x()+1][getLastp_y()+1].getCell()==User2){//güneydoğu
			if(hexcells[getLastp_x()+1][getLastp_y()+1].getCell()!=User2-32){
				hexcells[getLastp_x()+1][getLastp_y()+1].setcell(User2-32);
				setLastp_x(getLastp_x()+1);
				setLastp_y(getLastp_y()+1);
				up_words_o();
			}
		}
	}
}
void HEX::save_file(){
	int i,j,l=1;
	ofstream save_load_file;
	save_load_file.open(getFilename());
	save_load_file<<getSize()<<endl;
	save_load_file<<(*this);
	if(getControl()=='u'){
		save_load_file<<"USERVSUSER"<<endl;
	}
	else if(getControl()=='c'){
		save_load_file<<"USERVSCOMPUTER"<<endl;
	}
	save_load_file<<getCurrentPlayer()<<endl;
	save_load_file<<"---------------MOVES----------------"<<endl;
	save_load_file<<lastpoint<<endl;
	for (int k = 0; k < getlastpoint(); ++k)
	{
		save_load_file<<'(';
		save_load_file<<moves[k][0];
		save_load_file<<',';
		save_load_file<<moves[k][1];
		save_load_file<<')';
	}
	save_load_file.close();
}
void HEX::load_file(){
	for (int m = 0; m < getSize(); ++m)
	{
		delete [] hexcells[m]; 
	}
	delete [] hexcells;
	hexcells=nullptr;
	for (int n = 0; n < getSize(); ++n)
	{
		delete [] temp_arrey[n]; 
	}
	delete [] temp_arrey;
	temp_arrey=nullptr;
	for (int a = 0; a < getSize()*getSize(); ++a)
	{
		delete [] moves[a]; 
	}
	delete [] moves;
	moves=nullptr;
	ifstream save_load_file;
	save_load_file.open(getFilename());
	save_load_file>>(*this);
	save_load_file.close();
}
bool HEX::operator==(const HEX& anotherObject)const{//WE OVERLOAD THE == OPERATOR FOR COMPARESİON
	int counter=0,counter1=0;
	if(getControl1()=='u'){
		for (int i = 0; i < getSize(); ++i)
		{
			for (int j = 0; j < getSize(); ++j)
			{
				if(hexcells[i][j].getCell()==User1){
					counter++;
				}
				if(hexcells[i][j].getCell()==User2){
					counter++;
				}
			}
		}
	}
	else if(getControl1()=='c'){
		for (int a = 0; a < getSize(); ++a)
		{
			for (int b = 0; b < getSize(); ++b)
			{
				if(hexcells[a][b].getCell()==User1){
					counter++;
				}
			}
		}
	}
	if(anotherObject.getControl1()=='u'){
		for (int f = 0; f < anotherObject.getSize(); ++f)
		{
			for (int k = 0; k < anotherObject.getSize(); ++k)
			{
				if(anotherObject.hexcells[f][k].getCell()==User1){
					counter1++;
				}
				if(anotherObject.hexcells[f][k].getCell()==User2){
					counter1++;
				}
			}
		}
	}
	else if(anotherObject.getControl1()=='c'){
		for (int l = 0; l < anotherObject.getSize(); ++l)
		{
			for (int m = 0; m < anotherObject.getSize(); ++m)
			{
				if(anotherObject.hexcells[l][m].getCell()==User1){
					counter1++;
				}
			}
		}
	}
	if(counter>counter1){
		return true;
	}
	else{
		return false;
	}
}
void HEX::findMarked(){
	for (int i = 0; i < getSize(); ++i)
	{
		for (int j = 0; j < getSize(); ++j)
		{
			if(hexcells[i][j].getCell()!=empty){
				Markedcount++;
			}
		}
	}
}
void HEX::operator--(int ignoreMe){//POST DECREMENT
	if(getControl1()=='u'){
		hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell(empty);//WE DİD EMPTY
		lastpoint--;//DCREMENT THE COUNTER OF MOVES 
		hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell(empty);
		lastpoint--;
		cout<<(*this);	}
	else if(getControl1()=='c'){
		hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell(empty);
		lastpoint--;
		hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell(empty);
		lastpoint--;
		cout<<(*this);
	}
}
void HEX::operator--(){//PRE DECREMENT İF YOU PLAY USERVSUSER TAKE BACK ONE POİNT AND THE ORDER PASS THE ONETHER USER
	if(getControl1()=='u'){
		if(getCurrentPlayer()==User1){
			hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell(empty);
			lastpoint--;
			cout<<(*this);
			setCurrentPlayer(User2);
		}
		else if(getCurrentPlayer()==User2){
			hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell(empty);
			lastpoint--;
			cout<<(*this);
			setCurrentPlayer(User1);
		}
	}
	else if(getControl1()=='c'){
		hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell(empty);
		lastpoint--;
		hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell(empty);
		lastpoint--;
		cout<<(*this);
	}
}
ostream& operator<<(ostream& output,const HEX& anotherObject){//OVERLOADED OFSTREAM
	int i,j;
	auto firstc='A';
	auto firsti='1';
	output<<"  ";
	for(i=0;i<anotherObject.getSize();i++,firstc++){
		output<<" "<<firstc; 
	}
	output<<"\n";
	for(i=0;i<anotherObject.getSize();i++){
		if(i<9){
			output<<" "<<i+1;
		}
		else{
			output<<i+1;
		}
		for(j=0;j<i+1;j++){
			output<<" ";
		}
		for(j=0;j<anotherObject.getSize();j++){
			output<<anotherObject.hexcells[i][j].getCell();
			output<<" ";
		}
		output<<endl;
	}
	return output;
}
istream& operator>>(istream& input,HEX& anotherObject){
	char data,free;
	int control=0,control1=0,lastp;
	int num1,num2;
	int i=0 , j=0;
	int size2;
	char currentplayer;
	int lastpoint;
	string line,str,size1; 
	if(!input.fail()){//for avoiding to open unexist file
		while(!input.eof()){//to reach end of file
			if(control1==0){
				getline(input,size1);
				size2=stoi(size1);
				anotherObject.setSize(size2);
				getline(input,line);
				anotherObject.hexcells=new HEX::Cell*[anotherObject.getSize()];//CREATE A NEW PLACE
				for (int k = 0; k < anotherObject.getSize(); ++k)
				{
					anotherObject.hexcells[k]=new HEX::Cell[anotherObject.getSize()];
				}
				anotherObject.temp_arrey=new HEX::Cell*[anotherObject.getSize()];
				for (int l = 0; l < anotherObject.getSize(); ++l)
				{
					anotherObject.temp_arrey[l]=new HEX::Cell[anotherObject.getSize()];
				}
				control1++;
			}
			if(j==0&&i<9){
				input>>free;//FOR 1 2 3 4 NUMBERS
			}
			else if(j==0){
				input>>free;
				input>>free;
			}
			input>>data;//we are reading the data from file
			anotherObject.hexcells[i][j].setcell(data);//then we send board size
			if(j==anotherObject.getSize()-1 && i==anotherObject.getSize()-1){ //if we reach end of board size file will end
				anotherObject.moves=new int*[anotherObject.getSize()*anotherObject.getSize()];
				for (int l = 0; l < anotherObject.getSize()*anotherObject.getSize(); ++l)
				{
					anotherObject.moves[l]=new int[2];
				}
				getline(input,line);
				getline(input,str);
				input>>currentplayer;
				getline(input,line);
				getline(input,line);
				input>>lastp;
				lastpoint=lastp;
				anotherObject.lastpoint=lastp;
				for (int m = 0; m < anotherObject.lastpoint; ++m)
				{
					input>>data;
					input>>num1;
					input>>data;
					input>>num2;
					input>>data;
					anotherObject.moves[m][0]=num1;
					anotherObject.moves[m][1]=num2;
				}
				break;
			}
			else if(j==anotherObject.getSize()-1){
				getline(input,line);//to read space
				i++;
				j=0;
			}
			else{
				j++;
			}
		}
		control=1;
		if(str.compare("USERVSUSER")==0){
			cout<<anotherObject;
			anotherObject.setControl1('u');
			anotherObject.setCurrentPlayer(currentplayer);
		}
		else if(str.compare("USERVSCOMPUTER")==0){
			cout<<anotherObject;
			anotherObject.setControl1('c');
		}
	}
	if(control==0){ 
		cerr<<"İnvalid File! Please enter a file name which has been created before"<<endl<<endl;
	}
	return input;
}
int HEX::ReturnScore(){
	int counter=0;
	for (int i = 0; i < getSize(); ++i)
	{
		counter=0;
		for (int j = 0; j < getSize(); ++j)
		{
			if (hexcells[i][j].getCell()==User1 && j==0)
			{
				counter++;
				if (counter>getCountUser())
				{
					count=counter; 
				}
			}
			else if (hexcells[i][j].getCell()==User1 && hexcells[i][j-1].getCell()==User1)
			{
				counter++;
				if (counter>getCountUser())
				{
					count=counter; 
				}
			}
		}
	}
	return count;
}
HEX& HEX::operator=(const HEX& assignObject){//ASSİGN OPERATOR OVERLOADİNG
	if (this==&assignObject)//İF SAME OBJECT
	{
		return *this;
	}
	else{
		file_name=assignObject.file_name;
		control=assignObject.control,control1=assignObject.control1;
		lastp_x=assignObject.lastp_x,lastp_y=assignObject.lastp_y;
		lastpoint=assignObject.lastpoint;
		tempi=assignObject.tempi,tempj=assignObject.tempj;
		counter=assignObject.counter,counter1=assignObject.counter1;
		currentPlayer=assignObject.currentPlayer;
		fullcell=assignObject.fullcell;
		endgame=assignObject.endgame;
		Score=assignObject.Score;
		count=assignObject.count;

		for (int m = 0; m < getSize(); ++m)
		{
			delete [] hexcells[m]; 
		}
		delete [] hexcells;
		for (int n = 0; n < getSize(); ++n)
		{
			delete [] temp_arrey[n]; 
		}
		delete [] temp_arrey;
		for (int k = 0; k < getSize()*getSize(); ++k)
		{
			delete [] moves[k]; 
		}
		delete [] moves;
		size=assignObject.size;

		hexcells=new Cell*[getSize()];
		for (int i = 0; i < getSize(); ++i)
		{
			hexcells[i]=new Cell[getSize()];
		}
		for (int a = 0; a < getSize(); ++a)
		{
			for (int b = 0; b < getSize(); ++b)
			{
				hexcells[a][b]=assignObject.hexcells[a][b];
			}
		}
		temp_arrey=new Cell*[getSize()];
		for (int i = 0; i < getSize(); ++i)
		{
			temp_arrey[i]=new Cell[getSize()];
		}
		for (int c= 0; c < getSize(); ++c)
		{
			for (int d = 0; d < getSize(); ++d)
			{
				temp_arrey[c][d]=assignObject.temp_arrey[c][d];
			}
		}
		moves=new int*[getSize()*getSize()];
		for (int i = 0; i < getSize()*getSize(); ++i)
		{
			moves[i]=new int[2];
		}
		for (int c= 0; c < assignObject.lastpoint; ++c)
		{
			moves[c][0]=assignObject.moves[c][0];
			moves[c][1]=assignObject.moves[c][1];
		}
	}
	return *this;
}