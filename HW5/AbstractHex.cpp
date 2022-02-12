
#include"pack1.h"
namespace hex_kurban{
	AbstractHex::AbstractHex(const int& _size){
		control=' ',control1=' ';
		lastp_x=0,lastp_y=0;
		tempi=0,tempj=0;
		counter=0;
		currentPlayer=' ';
		counter1=0;
		fullcell=0;
		lastpoint=0;
		Markedcount=0;
		Score=0;
		count=0;
		setSize(_size);
		moves.resize(getSize()*getSize());
		for (int i = 0; i < getSize()*getSize(); i++)
		{
			for (int j = 0; j<2; j++)
			{
				moves[i].push_back(0);
			}
		}
	}
	void AbstractHex::is_valid(){
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
	void AbstractHex::iterate_func1(){
		int i;
		decltype(i) j;
		for(i=0;i<getSize();i++){
			for(j=0;j<getSize();j++){
				gettempCell(i,j).setcell(empty);//TO CONTROL IN CHECK FUNCTION NOT GO BACK WAS FILLED  BEFORE
			}
		}
	}
	void AbstractHex::print_function(){//Print BOARD
		cout<<(*this);
	}
	ostream& operator<<(ostream& output,AbstractHex& anotherObject){//OVERLOADED OFSTREAM
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
			output<<anotherObject(i,j).getCell();
			output<<" ";
		}
		output<<endl;
	}
	return output;
}
	void AbstractHex::playGame(){
		int choose=0;
		bool control=false,control1=false,finish=false,control2=false;
		string command1,command2;
		int charcoordinate_temp1;
		bool end_game1=false,end_game2=false;
		Cell cell,cell1;
		char letter;
		int number;
		is_valid();
		print_function();//print first situation
		cout<<"If you play the game with user Please enter 1, If you play the game with computer enter 2"<<endl;
		cin>>choose;
		if(choose==1){
			setControl1('u');//CHECK TO PLAY USER
		}
		else if(choose==2){
			setControl1('c');//CHECK TO PLAY COMPUTER
		}
		while(control2==false){
			if(getControl1()=='u'){//PLAY USER
				finish=false;
				while(finish==false){
					while(control==false){
						cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME  if you want to take back the game one move please enter UNDO GAME-- or UNDO --GAME , Enter RESET GAME to start beginning for user 1"<<endl;
						cin>>command1>>command2;
						setCurrentPlayer(User1);//MAKE MOVE FOR USER1
						if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME" && command1!="UNDO" && command2!="GAME--" && command1!="UNDO" && command2!="--GAME" && command1!="RESET" && command2!="GAME"){
							letter=command1[0];
							number=stoi(command2);
							letter-=17;
							charcoordinate_temp1=letter-'0';
							number--;
							if((*this)(number,charcoordinate_temp1).getCell()==empty){
								Cell a;
								a.setRow(number);
								a.setColumn(charcoordinate_temp1);
								play(a);
								print_function();
								control=true;
							}
							else{
								cerr<<"This place is not empty!Enter Again"<<endl;
							}
							end_game1=end_game_user1();
							if(end_game1==true){ 
								print_function();
								cout<<"User 1 is win !"<<endl;
								control1=true;
								finish=true;
								control2=true;	
							}
						}
						else if(command1=="SAVE"){
							setControl('u');//SAVE THE CURRENT PLAYER TO THE FILE
							setFilename(command2);
							writeToFile(command2);
						}
						else if(command1=="LOAD"){
							setFilename(command2);
							readFromFile(command2);
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
						else if(command1=="RESET" && command2=="GAME"){
							reset_game();
							print_function();
						}
					}
					while(control1==false){
						cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME  if you want to take back the game one move please enter UNDO GAME-- or UNDO --GAME ,Enter RESET GAME to start beginning for user 2"<<endl;
						cin>>command1>>command2;
						setCurrentPlayer(User2);
						if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME" && command1!="UNDO" && command2!="GAME--" && command1!="UNDO" && command2!="--GAME" && command1!="RESET" && command2!="GAME"){
							letter=command1[0];
							number=stoi(command2);
							letter-=17;
							charcoordinate_temp1=letter-'0';
							number--;
							if((*this)(number,charcoordinate_temp1).getCell()==empty){
								control1=true;
								Cell a;
								a.setRow(number);
								a.setColumn(charcoordinate_temp1);
								play(a);
								print_function();
							}
							else{
								cerr<<"This place is not empty!Enter Again"<<endl;
							}
							end_game2=end_game_user2();
							if(end_game2==true){
								print_function();
								cout<<"User 2 is win !"<<endl;
								finish=true;
								control2=true;
							}
						}
						else if(command1=="SAVE"){
							setControl('u');
							setFilename(command2);
							writeToFile(command2);
						}
						else if(command1=="LOAD"){
							setFilename(command2);
							readFromFile(command2);
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
						else if(command1=="RESET" && command2=="GAME"){
							reset_game();
							print_function();
							break;
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
						cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME if you want to take back the game one move please enter UNDO GAME-- or UNDO --GAME ,Enter RESET GAME to start beginning for user 1"<<endl;
						cin>>command1>>command2;
						setCurrentPlayer(User1);
						if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME" && command1!="UNDO" && command2!="GAME--" && command1!="UNDO" && command2!="--GAME" && command1!="RESET" && command2!="GAME"){
							letter=command1[0];
							number=stoi(command2);
							letter-=17;
							charcoordinate_temp1=letter-'0';
							number--;
							if((*this)(number,charcoordinate_temp1).getCell()==empty){
								Cell a;
								a.setRow(number);
								a.setColumn(charcoordinate_temp1);
								play(a);
								cell1=LastMove();
								cout<<"Lastmove is "<<cell1.getCell()<<" at this points "<<cell1.getColumn()<<","<<cell1.getRow()<<endl;
								setLastp_x(number);
								setLastp_y(charcoordinate_temp1);
								print_function();
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
								print_function();
								cout<<"User 1 is win !"<<endl;
								control1=true;
								finish=true;
								control2=true;
							}
						}
						else if(command1=="SAVE"){
							setControl('c');
							setFilename(command2);
							writeToFile(command2);
						}
						else if(command1=="LOAD"){
							setFilename(command2);
							readFromFile(command2);
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
								--(*this);
							}
							else{
								cerr<<"There is no move to go back!"<<endl;
							}
						}
						else if(command1=="RESET" && command2=="GAME"){
							reset_game();
							print_function();
						}
					}
					while(control1==false){
						cell=play();
						cell1=LastMove();
						cout<<"Lastmove is "<<cell1.getCell()<<" at this points "<<cell1.getColumn()<<","<<cell1.getRow()<<endl;
						setCounter(1);
						print_function();
						control1=true;
						end_game2=end_game_computer();
						if(end_game2==true){
							print_function();
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
	void AbstractHex::play(Cell a){
		int number1=a.getColumn();
		int number2=a.getRow();
		if(getCurrentPlayer()==User1){//USER1
			(*this)(number2,number1).setcell(User1);
			cout<<getlastpoint()<<endl;
			moves[getlastpoint()][0]=number2;
			moves[getlastpoint()][1]=number1;
			lastpoint++;
		}
		else if(getCurrentPlayer()==User2){//USER2
			(*this)(number2,number1).setcell(User2);
			moves[getlastpoint()][0]=number2;
			moves[getlastpoint()][1]=number1;
			lastpoint++;
		}
	}
	bool AbstractHex::end_game_user1(){
		int i,j=0;
		bool control=false;
		for(i=0;i<getSize();i++){
			if((*this)(i,j).getCell()==User1){//we find first point and starting the recursion with finding x words
				iterate_func1();// gettempCell is create for control the not returning to passing point with recursion 
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
	bool AbstractHex::end_game_user2(){
		int i=0,j=0;
		bool control=false;
		for(j=0;j<getSize();j++){
			if((*this)(i,j).getCell()==User2){//we find first point and starting the recursion with finding o words
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
	bool AbstractHex::end_game_computer(){
		int i=0,j=0;
		bool control=false,control1=false;
		for(j=0;j<getSize();j++){
			if((*this)(i,j).getCell()==User2){
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
	Cell AbstractHex::play(){
		int charcoordinate_temp2,coordinate2;
		char charcoordinate2;
		bool control=false;
		int computerp_x,computerp_y,i,j;
		int middle;
		Cell tempCell;
		middle=(getSize()+1)/2-1;//we find the middle of board
		if(getCounter()==0){
			if((*this)(middle,middle).getCell()==User1 || (*this)(middle,middle).getCell()==User2){
				(*this)(middle,middle+1).setcell(computer);
				computerp_x=middle+1;
				computerp_y=middle+1;
				moves[getlastpoint()][0]=middle;
				moves[getlastpoint()][1]=middle+1;
				lastpoint++;
				tempCell.setcell(computer);
				tempCell.setRow(middle);
				tempCell.setColumn(middle+1);
				return (tempCell);
			}
			else{
				(*this)(middle,middle).setcell(computer);//computer attend the middle of board always please let it do :)
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
					if((*this)(i,j).getCell()==computer){//we find last o point in board 
						computerp_x=i;
						computerp_y=j;
					}
				}
			}
			if(computerp_x!=getSize()-1){
				if((*this)(computerp_x+1,computerp_y).getCell()==User1 && (*this)(computerp_x+1,computerp_y-1).getCell()!=User1){
					(*this)(computerp_x+1,computerp_y-1).setcell(computer);
					moves[getlastpoint()][0]=computerp_x+1;
					moves[getlastpoint()][1]=computerp_y-1;
					lastpoint++;
					tempCell.setcell(computer);
					tempCell.setRow(computerp_x+1);
					tempCell.setColumn(computerp_y-1);
					return (tempCell);
				}
				else if((*this)(computerp_x+1,computerp_y).getCell()!=User1){
					(*this)(computerp_x+1,computerp_y).setcell(computer);
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
						if((*this)(i,j).getCell()==computer){
							computerp_x=i;
							computerp_y=j;
							control=true;
							break;
						}
					}
					if(control==true) break;
				}
				if((*this)(computerp_x-1,computerp_y).getCell()==User1 && (*this)(computerp_x-1,computerp_y+1).getCell()!=User1){
					(*this)(computerp_x-1,computerp_y+1).setcell(computer);
					moves[getlastpoint()][0]=computerp_x-1;
					moves[getlastpoint()][1]=computerp_y+1;
					lastpoint++;
					tempCell.setcell(computer);
					tempCell.setRow(computerp_x-1);
					tempCell.setColumn(computerp_y+1);
					return (tempCell);	
				}
				else if((*this)(computerp_x-1,computerp_y).getCell()!=User1){
					(*this)(computerp_x-1,computerp_y).setcell(computer);
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
					if((*this)(i,j).getCell()==computer){
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
						if((*this)(i,j).getCell()==computer){
							computerp_x=i;
							computerp_y=j;
							control=true;
							break;
						}
					}
					if(control==true) break;
				}
				if((*this)(computerp_x-1,computerp_y).getCell()==User1 && (*this)(computerp_x-1,computerp_y+1).getCell()!=User1){
					(*this)(computerp_x-1,computerp_y+1).setcell(computer);
					moves[getlastpoint()][0]=computerp_x-1;
					moves[getlastpoint()][1]=computerp_y+1;
					lastpoint++;
					tempCell.setcell(computer);
					tempCell.setRow(computerp_x-1);
					tempCell.setColumn(computerp_y+1);
					return (tempCell);
				}
				else if((*this)(computerp_x-1,computerp_y).getCell()!=User1) {
					(*this)(computerp_x-1,computerp_y).setcell(computer);
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
						if((*this)(i,j).getCell()==computer){//we find last o point in board 
							computerp_x=i;
							computerp_y=j;
						}
					}
				}
				if((*this)(computerp_x+1,computerp_y).getCell()==User1 && (*this)(computerp_x+1,computerp_y-1).getCell()!=User1){
					(*this)(computerp_x+1,computerp_y-1).setcell(computer);
					moves[getlastpoint()][0]=computerp_x+1;
					moves[getlastpoint()][1]=computerp_y-1;
					lastpoint++;
					tempCell.setcell(computer);
					tempCell.setRow(computerp_x+1);
					tempCell.setColumn(computerp_y-1);
					return (tempCell);
				}
				else if((*this)(computerp_x+1,computerp_y).getCell()!=User1) {
					(*this)(computerp_x+1,computerp_y).setcell(computer);
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
	bool AbstractHex::control_moves_x(){
		if(getTempj()+1==size){
			setLastp_x(getTempi()+1);//we keep the last x point to end game
			setLastp_y(getTempj()+1);
			return true;
		}
		if(getTempi()!=0){
			if((*this)(getTempi()-1,getTempj()).getCell()==User1){//kuzey
				if(gettempCell(getTempi()-1,getTempj()).getCell()!=User1){//to avoid of going back to and avoid infinite loop
					gettempCell(getTempi()-1,getTempj()).setcell(User1);
					setTempi(getTempi()-1);
					return control_moves_x(); //recursive to around existing x values
				}
			}
		}
		if(getTempi()!=size-1){
			if((*this)(getTempi()+1,getTempj()).getCell()==User1){//güney
				if(gettempCell(getTempi()+1,getTempj()).getCell()!=User1){
					gettempCell(getTempi()+1,getTempj()).setcell(User1);
					setTempi(getTempi()+1);
					return control_moves_x();
				}
			}
		}
		if(getTempi()!=0 && getTempj()!=size-1){
			if((*this)(getTempi()-1,getTempj()+1).getCell()==User1){//kuzeydoğu
				if(gettempCell(getTempi()-1,getTempj()+1).getCell()!=User1){
					gettempCell(getTempi()-1,getTempj()+1).setcell(User1);
					setTempi(getTempi()-1);
					setTempj(getTempj()+1);
					return control_moves_x();
				}
			}
		}
		if(getTempj()!=size-1){
			if((*this)(getTempi(),getTempj()+1).getCell()==User1){//doğu
				if(gettempCell(getTempi(),getTempj()+1).getCell()!=User1){
					gettempCell(getTempi(),getTempj()+1).setcell(User1);
					setTempj(getTempj()+1);
					return control_moves_x();
				}
			}
		}
		if(getTempj()!=0){
			if((*this)(getTempi(),getTempj()-1).getCell()==User1){//batı
				if(gettempCell(getTempi(),getTempj()-1).getCell()!=User1){
					gettempCell(getTempi(),getTempj()-1).setcell(User1);
					setTempj(getTempj()-1);
					return control_moves_x();
				}
			}
		}
		if(getTempi()!=size-1 && getTempj()!=0){
			if((*this)(getTempi()+1,getTempj()-1).getCell()==User1){//güneybatı
				if(gettempCell(getTempi()+1,getTempj()-1).getCell()!=User1){
					gettempCell(getTempi()+1,getTempj()-1).setcell(User1);
					setTempi(getTempi()+1);
					setTempj(getTempj()-1);
					return control_moves_x();
				}
			}
		}
		return false;
	}
	bool AbstractHex::control_moves_o(){
		if(getTempi()+1==size){
			setLastp_x(getTempi()+1);//we keep the last O point to end game
			setLastp_y(getTempj());
			return true;
		}
		if(getTempi()!=0){
			if((*this)(getTempi()-1,getTempj()).getCell()==User2){//kuzey
				if(gettempCell(getTempi()-1,getTempj()).getCell()!=User2){//to avoid of going back to and avoid infinite loop
					gettempCell(getTempi()-1,getTempj()).setcell(User2);
					setTempi(getTempi()-1);
					return control_moves_o(); //recursive to around existing x values
				}
			}
		}
		if(getTempi()!=size-1){
			if((*this)(getTempi()+1,getTempj()).getCell()==User2){//güney
				setTempi(getTempi()+1);
				return control_moves_o();
			}
		}
		if(getTempi()!=0 && getTempj()!=size-1){
			if((*this)(getTempi()-1,getTempj()+1).getCell()==User2){//kuzeydoğu
				if(gettempCell(getTempi()-1,getTempj()+1).getCell()!=User2){
					gettempCell(getTempi()-1,getTempj()+1).setcell(User2);
					setTempi(getTempi()-1);
					setTempj(getTempj()+1);
					return control_moves_o();
				}
			}
		}
		if(getTempj()!=size-1){
			if((*this)(getTempi(),getTempj()+1).getCell()==User2){//doğu
				if(gettempCell(getTempi(),getTempj()+1).getCell()!=User2){
					gettempCell(getTempi(),getTempj()+1).setcell(User2);
					setTempj(getTempj()+1);
					return control_moves_o();
				}
			}
		}
		if(getTempj()!=0){
			if((*this)(getTempi(),getTempj()-1).getCell()==User2){//batı
				if(gettempCell(getTempi(),getTempj()-1).getCell()!=User2){
					gettempCell(getTempi(),getTempj()-1).setcell(User2);
					setTempj(getTempj()-1);
					return control_moves_o();
				}
			}
		}
		if(getTempi()!=size-1 && getTempj()!=0){
			if((*this)(getTempi()+1,getTempj()-1).getCell()==User2){//güneybatı
				if(gettempCell(getTempi()+1,getTempj()-1).getCell()!=User2){
					gettempCell(getTempi()+1,getTempj()-1).setcell(User2);
					setTempi(getTempi()+1);
					setTempj(getTempj()-1);
					return control_moves_o();
				}
			}
		}
		return false;
	}
	void AbstractHex::up_words_x(){
		if(getLastp_x()!=0){
			if((*this)(getLastp_x()-1,getLastp_y()).getCell()==User1){//kuzey
				if((*this)(getLastp_x()-1,getLastp_y()).getCell()!=User1-32){//to avoid the going back and to avoid infinite loop
					(*this)(getLastp_x()-1,getLastp_y()).setcell(User1-32);//up all connected words
					setLastp_x(getLastp_x()-1);
					up_words_x();//recursive to around existing x values
				}												//this function will end if the all connected x values are up
			}
		}
		if(getLastp_x()!=0 && getLastp_y()!=size-1){
			if((*this)(getLastp_x()-1,getLastp_y()+1).getCell()==User1){//kuzeydoğu
				if((*this)(getLastp_x()-1,getLastp_y()+1).getCell()!=User1-32){
					(*this)(getLastp_x()-1,getLastp_y()+1).setcell(User1-32);
					setLastp_x(getLastp_x()-1);
					setLastp_y(getLastp_y()+1);
					up_words_x();
				}
			}
		}
		if(getLastp_y()!=0){
			if((*this)(getLastp_x(),getLastp_y()-1).getCell()==User1){//batı
				if((*this)(getLastp_x(),getLastp_y()-1).getCell()!=User1-32){
					(*this)(getLastp_x(),getLastp_y()-1).setcell(User1-32);
					setLastp_y(getLastp_y()-1);
					up_words_x();
				}
			}
		}
		if(getLastp_y()!=size-1){
			if((*this)(getLastp_x(),getLastp_y()+1).getCell()==User1){//doğu
				if((*this)(getLastp_x(),getLastp_y()+1).getCell()!=User1-32){
					(*this)(getLastp_x(),getLastp_y()+1).setcell(User1-32);
					setLastp_y(getLastp_y()+1);
					up_words_x();
				}
			}
		}
		if(getLastp_x()!=size-1){
			if((*this)(getLastp_x()+1,getLastp_y()).getCell()==User1){//güney
				if((*this)(getLastp_x()+1,getLastp_y()).getCell()!=User1-32){
					(*this)(getLastp_x()+1,getLastp_y()).setcell(User1-32);
					setLastp_x(getLastp_x()+1);
					up_words_x();
				}
			}
		}
		if(getLastp_x()!=size-1 && getLastp_y()!=0){
			if((*this)(getLastp_x()+1,getLastp_y()-1).getCell()==User1){//güneybatı
				if((*this)(getLastp_x()+1,getLastp_y()-1).getCell()!=User1-32){
					(*this)(getLastp_x()+1,getLastp_y()-1).setcell(User1-32);
					setLastp_x(getLastp_x()+1);
					setLastp_y(getLastp_y()-1);
					up_words_x();
				}
			}
		}
		if(getLastp_x()!=0 && getLastp_y()!=0){
			if((*this)(getLastp_x()-1,getLastp_y()-1).getCell()==User1){//kuzeybatı
				if((*this)(getLastp_x()-1,getLastp_y()-1).getCell()!=User1-32){
					(*this)(getLastp_x()-1,getLastp_y()-1).setcell(User1-32);
					setLastp_x(getLastp_x()-1);
					setLastp_y(getLastp_y()-1);
					up_words_x();
				}
			}
		}
		if(getLastp_x()!=size-1 && getLastp_y()!=size-1){
			if((*this)(getLastp_x()+1,getLastp_y()+1).getCell()==User1){//güneydoğu
				if((*this)(getLastp_x()+1,getLastp_y()+1).getCell()!=User1-32){
					(*this)(getLastp_x()+1,getLastp_y()+1).setcell(User1-32);
					setLastp_x(getLastp_x()+1);
					setLastp_y(getLastp_y()+1);
					up_words_x();
				}
			}
		}
	}
	void AbstractHex::up_words_o(){
		if(getLastp_x()!=0){
			if((*this)(getLastp_x()-1,getLastp_y()).getCell()==User2){//kuzey
				if((*this)(getLastp_x()-1,getLastp_y()).getCell()!=User2-32){//to avoid the going back and to avoid infinite loop
					(*this)(getLastp_x()-1,getLastp_y()).setcell(User2-32);//up all connected words
					setLastp_x(getLastp_x()-1);
					up_words_o();//recursive to around existing x values
				}												//this function will end if the all connected x values are up
			}
		}
		if(getLastp_x()!=0 && getLastp_y()!=size-1){
			if((*this)(getLastp_x()-1,getLastp_y()+1).getCell()==User2){//kuzeydoğu
				if((*this)(getLastp_x()-1,getLastp_y()+1).getCell()!=User2-32){
					(*this)(getLastp_x()-1,getLastp_y()+1).setcell(User2-32);
					setLastp_x(getLastp_x()-1);
					setLastp_y(getLastp_y()+1);
					up_words_o();
				}
			}
		}
		if(getLastp_y()!=0){
			if((*this)(getLastp_x(),getLastp_y()-1).getCell()==User2){//batı
				if((*this)(getLastp_x(),getLastp_y()-1).getCell()!=User2-32){
					(*this)(getLastp_x(),getLastp_y()-1).setcell(User2-32);
					setLastp_y(getLastp_y()-1);
					up_words_o();
				}
			}
		}
		if(getLastp_y()!=size-1){
			if((*this)(getLastp_x(),getLastp_y()+1).getCell()==User2){//doğu
				if((*this)(getLastp_x(),getLastp_y()+1).getCell()!=User2-32){
					(*this)(getLastp_x(),getLastp_y()+1).setcell(User2-32);
					setLastp_y(getLastp_y()+1);
					up_words_o();
				}
			}
		}
		if(getLastp_x()!=size){
			if((*this)(getLastp_x()+1,getLastp_y()).getCell()==User2){//güney
				if((*this)(getLastp_x()+1,getLastp_y()).getCell()!=User2-32){
					(*this)(getLastp_x()+1,getLastp_y()).setcell(User2-32);
					setLastp_x(getLastp_x()+1);
					up_words_o();
				}
			}
		}
		if(getLastp_x()!=size && getLastp_y()!=0){
			if((*this)(getLastp_x()+1,getLastp_y()-1).getCell()==User2){//güneybatı
				if((*this)(getLastp_x()+1,getLastp_y()-1).getCell()!=User2-32){
					(*this)(getLastp_x()+1,getLastp_y()-1).setcell(User2-32);
					setLastp_x(getLastp_x()+1);
					setLastp_y(getLastp_y()-1);
					up_words_o();
				}
			}
		}
		if(getLastp_x()!=0 && getLastp_y()!=0){
			if((*this)(getLastp_x()-1,getLastp_y()-1).getCell()==User2){//kuzeybatı
				if((*this)(getLastp_x()-1,getLastp_y()-1).getCell()!=User2-32){
					(*this)(getLastp_x()-1,getLastp_y()-1).setcell(User2-32);
					setLastp_x(getLastp_x()-1);
					setLastp_y(getLastp_y()-1);
					up_words_o();
				}
			}
		}
		if(getLastp_x()!=size && getLastp_y()!=size-1){
			if((*this)(getLastp_x()+1,getLastp_y()+1).getCell()==User2){//güneydoğu
				if((*this)(getLastp_x()+1,getLastp_y()+1).getCell()!=User2-32){
					(*this)(getLastp_x()+1,getLastp_y()+1).setcell(User2-32);
					setLastp_x(getLastp_x()+1);
					setLastp_y(getLastp_y()+1);
					up_words_o();
				}
			}
		}
	}
	void AbstractHex::writeToFile(string file_name1){
		int i,j,l=1;
		auto firstc='A';
		auto firsti='1';
		ofstream save_load_file;
		save_load_file.open(file_name1);
		save_load_file<<getSize()<<endl;
		save_load_file<<"  ";
		for(i=0;i<getSize();i++,firstc++){
			save_load_file<<" "<<firstc; 
		}
		save_load_file<<"\n";
		for(i=0;i<getSize();i++){
			if(i<9){
				save_load_file<<" "<<i+1;
			}
			else{
				save_load_file<<i+1;
			}
			for(j=0;j<i+1;j++){
				save_load_file<<" ";
			}
			for(j=0;j<getSize();j++){
				save_load_file<<(*this)(i,j).getCell();
				save_load_file<<" ";
			}
			save_load_file<<endl;
		}
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
	bool AbstractHex::operator==(AbstractHex& anotherObject){
		int counter=0,counter1=0;
		if((*this).getSize()!=anotherObject.getSize()) return false;
		else{
			for (int i = 0; i < getSize(); ++i)
			{
				for (int j = 0; j < getSize(); ++j)
				{
					if((*this)(i,j).getCell()!=anotherObject(i,j).getCell()) return false; 
				}
			}
		}
		return true;
	}
	int AbstractHex::NumberOfMoves(){
		for (int i = 0; i < getSize(); ++i)
		{
			for (int j = 0; j < getSize(); ++j)
			{
				if((*this)(i,j).getCell()!=empty){
					Markedcount++;
				}
			}
		}
		return Markedcount;
	}
	void AbstractHex::operator--(int ignoreMe){
		if(getControl1()=='u'){
			(*this)(moves[lastpoint-1][0],moves[lastpoint-1][1]).setcell(empty);
			lastpoint--;
			(*this)(moves[lastpoint-1][0],moves[lastpoint-1][1]).setcell(empty);
			lastpoint--;
			print_function();
		}
		else if(getControl1()=='c'){
			(*this)(moves[lastpoint-1][0],moves[lastpoint-1][1]).setcell(empty);
			lastpoint--;
			(*this)(moves[lastpoint-1][0],moves[lastpoint-1][1]).setcell(empty);
			lastpoint--;
			print_function();
		}
	}
	void AbstractHex::operator--(){
		if(getControl1()=='u'){
			if(getCurrentPlayer()==User1){
				(*this)(moves[lastpoint-1][0],moves[lastpoint-1][1]).setcell(empty);
				lastpoint--;
				print_function();
				setCurrentPlayer(User2);
			}
			else if(getCurrentPlayer()==User2){
				(*this)(moves[lastpoint-1][0],moves[lastpoint-1][1]).setcell(empty);
				lastpoint--;
				print_function();
				setCurrentPlayer(User1);
			}
		}
		else if(getControl1()=='c'){
			(*this)(moves[lastpoint-1][0],moves[lastpoint-1][1]).setcell(empty);
			lastpoint--;
			(*this)(moves[lastpoint-1][0],moves[lastpoint-1][1]).setcell(empty);
			lastpoint--;
			print_function();
		}
	}
	int AbstractHex::ReturnScore(){
		int counter=0;
		for (int i = 0; i < getSize(); ++i)
		{
			counter=0;
			for (int j = 0; j < getSize(); ++j)
			{
				if ((*this)(i,j).getCell()==User1)
				{
					counter++;
					if (counter>getCountUser())
					{
						count=counter; 
					}
				}
			}
		}
		cout<<count<<endl;
		return count;
	}
	Cell AbstractHex::LastMove(){
		int i,j;
		Cell cell;
		try{
			if(lastpoint==0) throw "bad_move for given values";
			i=moves[lastpoint-1][0];
			j=moves[lastpoint-1][1];
			cell.setColumn(i);
			cell.setRow(j);
			if((*this)(i,j).getCell()=='x') cell.setcell(User1);
			else{
				cell.setcell(User2);
			}
			return cell;
		}
		catch(const char *msg)
		{
			cerr<<msg<<endl;
		}
	}
	AbstractHex::AbstractHex(const AbstractHex& anotherObject){
		if(anotherObject.lastpoint>=0){//check the are there any moves
			size=anotherObject.size;
			file_name=anotherObject.file_name;
			control=anotherObject.control,control1=anotherObject.control1;
			Markedcount=anotherObject.Markedcount;
			lastp_x=anotherObject.lastp_x,lastp_y=anotherObject.lastp_y;
			lastpoint=anotherObject.lastpoint;
			tempi=anotherObject.tempi,tempj=anotherObject.tempj;
			endgame=anotherObject.endgame;
			counter=anotherObject.counter,counter1=anotherObject.counter1;
			currentPlayer=anotherObject.currentPlayer;
			fullcell=anotherObject.fullcell;
			Score=anotherObject.Score;
			count=anotherObject.count;
			moves.resize(getSize()*getSize());
			for (int i = 0; i < getSize()*getSize(); i++)
			{
				for (int j = 0; j<2; j++)
				{
					moves[i].push_back(0);
				}
			}	
		}
	}
	AbstractHex& AbstractHex::operator=(const AbstractHex& anotherObject){
		file_name=anotherObject.file_name;
		control=anotherObject.control,control1=anotherObject.control1;
		lastp_x=anotherObject.lastp_x,lastp_y=anotherObject.lastp_y;
		lastpoint=anotherObject.lastpoint;
		tempi=anotherObject.tempi,tempj=anotherObject.tempj;
		counter=anotherObject.counter,counter1=anotherObject.counter1;
		Markedcount=anotherObject.Markedcount;
		currentPlayer=anotherObject.currentPlayer;
		fullcell=anotherObject.fullcell;
		endgame=anotherObject.endgame;
		Score=anotherObject.Score;
		count=anotherObject.count;
		return *this;
	}
	void AbstractHex::reset_game(){
		control=' ',control1=' ';
		lastp_x=0,lastp_y=0;
		tempi=0,tempj=0;
		counter=0;
		Markedcount=0;
		currentPlayer=' ';
		counter1=0;
		fullcell=0;
		lastpoint=0;
		Score=0;
		count=0;
		for (int i = 0; i < getSize()*getSize(); i++)
		{
			for (int j = 0; j<2; j++)
			{
				moves[i].push_back(0);
			}
		}
		for (int i = 0; i < getSize(); ++i)
		{
			for (int j = 0; j < getSize(); ++j)
			{
				(*this)(i,j).setcell(empty);
			}
		}
		for (int i = 0; i < getSize(); ++i)
		{
			for (int j = 0; j < getSize(); ++j)
			{
				gettempCell(i,j).setcell(empty);
			}
		}
	}
	bool GlobalFunction(AbstractHex **arr,int size){
		bool control=true,control2=true;
		int i=0;
		int xcount=0,ycount=0;
		int number=0;
		for (i = 0; i < size; ++i)
		{
			control=true;
			control2=true;
			xcount=0;
			ycount=0;
			if(arr[i]->getSize()<6){
				control=false;
				cout<<"There is wrong thing this board size less than 6-> "<<i+1<<". board"<<endl;
				number++; 
				continue;
			}
			for (int j = 0; j < arr[i]->getSize(); ++j)
			{
				for (int k = 0; k < arr[i]->getSize(); ++k)
				{
					if(arr[i]->operator()(j,k).getCell()!='x'&& arr[i]->operator()(j,k).getCell()!='o'&& arr[i]->operator()(j,k).getCell()!='*'){control=false; control2=false; break;}
					if(arr[i]->operator()(j,k).getCell()=='x') xcount++;
					if(arr[i]->operator()(j,k).getCell()=='o') ycount++;
				}
				if(control==false) break;
			}
			if(xcount-ycount>1 || ycount-xcount>1 ||xcount-ycount<-1 || ycount-xcount<-1){control=false;}//CONTROL X AND O NUMBER DİFFERENCE İS LESS THAN 2
			if(control==false){
				if(control2==false) cout<<"Board dont take any movement except 'x','o','*'-> "<<i+1<<". board"<<endl;
				else{
					cout<<"Play in turn is broken the number x and o are not equal one less or one more-> "<<i+1<<". board"<<endl;
				}
				number++;
			}
		}
		if(number>0) control=false;
		return control;
	}
	void Function(AbstractHex* object){
		int i=0,j=0;
		int numberofmove;
		bool control;
		object->readFromFile("FİLE1.TXT");
		object->print_function();
		object->writeToFile("FİLE.TXT");
		object->play();
		object->print_function();
		object->reset_game();
		object->print_function();
		control=object->end_game_user1();
		if(!control) cout<<"Game was not ended"<<endl;
		object->operator()(i,j).getCell();
		numberofmove=object->NumberOfMoves();
		cout<<"numberofmove: "<<numberofmove<<endl;
		object->LastMove();
	}
}