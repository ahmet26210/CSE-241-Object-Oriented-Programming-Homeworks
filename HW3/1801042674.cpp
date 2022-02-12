
#include"pack.h"
int HEX::Markedcount = 0;
int main()
{
	bool control=false;
	int lastfullcell=0;
	HEX h1(11),h2(11),h3(10),h4(8),h5(14);//CREAT OBJECT
	control=false;
	lastfullcell=0;//LAST FILLED CELL OF ALL GAME
	h1.playGame();//START GAME
	h1.findMarked();//FIND HOW MANY  CELL HAS FILLED
	h1.setfullcell(h1.getCount());//FILLED CELL OF THIS GAME
	h1.setCount(0);//TO MAKE STATIC MEMBER ZERO FOR THE OTHER GAME STARTING WITH ZERO FILLED CELL TO CALCULATED TRUE 
	cout<<"---------------	NEXT GAME ------------------"<<endl;
	h2.playGame();
	h2.findMarked();
	h2.setfullcell(h2.getCount());
	h2.setCount(0);
	cout<<"--------------	NEXT GAME -------------------"<<endl;
	control=h1.compareGame(h2);//COMPARE TWO GAME AND IF FİRST GAME HAS FILLED CELL MORE THEN SECOND GAME IT RETURNS TRUE OTHERWISE IT RETURNS FALSE
	if(control==false){
		cout<<"h2 has more marked cell only user "<<endl;
	}
	else if(control==true){
		cout<<"h1 has more marked cell only user "<<endl;
	}
	control=false;
	h3.playGame();
	h3.findMarked();
	h3.setfullcell(h3.getCount());
	h3.setCount(0);
	cout<<"---------------- NEXT GAME --------------"<<endl;
	h4.playGame();
	h4.findMarked();
	h4.setfullcell(h4.getCount());
	control=h3.compareGame(h4);
	h4.setCount(0);
	if(control==false){
		cout<<"h3 has more marked cell only user "<<endl;
	}
	else if(control==true){
		cout<<"h4 has more marked cell only user "<<endl;
	}
	cout<<"--------------  NEXT GAME ----------------"<<endl;
	h5.playGame();
	h5.findMarked();
	h5.setfullcell(h5.getCount());
	h5.setCount(0);
	lastfullcell=h1.getfullcell()+h2.getfullcell()+h3.getfullcell()+h4.getfullcell()+h5.getfullcell();//LASTFULLCELL OF ALL GAME 
	cout<<"The number of marked cell (NOT empty) of all game = "<<lastfullcell<<endl;
	return 0;
}
HEX::HEX(){
	control=' ',control1=' ';
	lastp_x=0,lastp_y=0;
	tempi=0,tempj=0;
	counter=0;
	currentPlayer=' ';
	counter1=0;
	fullcell=0;
}
HEX::HEX(const int& _size){
	setSize(_size);
}
HEX::Cell::Cell(){
	setcell(empty);
}
void HEX::is_valid(){
	bool  valid=false;
	while(valid==false){
		if(getSize()<6){
			cout<<"Please enter the board size ,the size can be bigger than 5*5 "<<endl;
			cin>>size;
			setSize(size);
		}
		else{
			Cell a;
			hexcells.resize(getSize());//WE RESIZE THE VECTOR
			temp_arrey.resize(getSize());
			for (int i = 0; i < getSize(); i++)
			{
				for (int j = 0; j<getSize(); j++)
				{
					hexcells[i].push_back(a);//WE PUSH BACK THE VECTOR TO CREAT THE 2D VECTOR 
					temp_arrey[i].push_back(a);
				}
			}
			valid=true;
		}
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
void HEX::print_function(){//Print BOARD
	int i,j;
	auto firstc='A';
	auto firsti='1';
	cout<<"  ";
	for(i=0;i<getSize();i++,firstc++){
		cout<<" "<<firstc; 
	}
	cout<<"\n";
	for(i=0;i<getSize();i++){
		if(i<9){
			cout<<" "<<i+1;
		}
		else{
			cout<<i+1;
		}
		for(j=0;j<i+1;j++){
			cout<<" ";
		}
		for(j=0;j<getSize();j++){
			cout<<hexcells[i][j].getCell();
			cout<<" ";
		}
		cout<<endl;
	}
}
void HEX::playGame(){
	int choose=0;
	bool control=false,control1=false,finish=false,control2=false;
	string command1,command2;
	int charcoordinate_temp1;
	bool end_game1=false,end_game2=false;
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
					cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME for user 1"<<endl;
					cin>>command1>>command2;
					if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME"){
						letter=command1[0];
						number=stoi(command2);
						letter-=17;
						charcoordinate_temp1=letter-'0';
						number--;
						if(hexcells[number][charcoordinate_temp1].getCell()==empty){
							setCurrentPlayer(User1);//MAKE MOVE FOR USER1
							play(charcoordinate_temp1,number);
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
					}
					else if(command1=="EXIT" && command2=="GAME"){//TO PASS THE ANOTHER GAME OR QUIT THE GAME
						control1=true;
						finish=true;
						control2=true;
						control=true;
					}
				}
				while(control1==false){
					cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME  for user 2"<<endl;
					cin>>command1>>command2;
					if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME"){
						letter=command1[0];
						number=stoi(command2);
						letter-=17;
						charcoordinate_temp1=letter-'0';
						number--;
						if(hexcells[number][charcoordinate_temp1].getCell()==empty){
							control1=true;
							setCurrentPlayer(User2);
							play(charcoordinate_temp1,number);
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
						save_file();
					}
					else if(command1=="LOAD"){
						setFilename(command2);
						load_file();
						if(getControl1()=='c'){
							finish=true;
							control1=true;
						}
					}
					else if(command1=="EXIT" && command2=="GAME"){
						control1=true;
						finish=true;
						control2=true;
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
					cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter like SAVE FİLE.TXT or LOAD FİLE.TXT if you want to exıt game please enter EXIT GAME for user 1"<<endl;
					cin>>command1>>command2;
					if(command1!="SAVE" && command1!="LOAD" && command1!="EXIT" && command2!="GAME"){
						letter=command1[0];
						number=stoi(command2);
						letter-=17;
						charcoordinate_temp1=letter-'0';
						number--;
						if(hexcells[number][charcoordinate_temp1].getCell()==empty){
							setCurrentPlayer(User1);
							play(charcoordinate_temp1,number);
							setLastp_x(number);
							setLastp_y(charcoordinate_temp1);
							print_function();
							control=true;
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
				}
				while(control1==false){
					play();
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
void HEX::play(int number1,int number2){
	if(getCurrentPlayer()==User1){//USER1
		hexcells[number2][number1].setcell(User1);
	}
	else if(getCurrentPlayer()==User2){//USER2
		hexcells[number2][number1].setcell(User2);
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
void HEX::play(){
	int charcoordinate_temp2,coordinate2;
	char charcoordinate2;
	bool control=false;
	int computerp_x,computerp_y,i,j;
	int middle;
	middle=(getSize()+1)/2-1;//we find the middle of board
	if(getCounter()==0){
		if(hexcells[middle][middle].getCell()==User1 || hexcells[middle][middle].getCell()==User2){
			hexcells[middle][middle+1].setcell(computer);
			computerp_x=middle+1;
			computerp_y=middle+1;
		}
		else{
			hexcells[middle][middle].setcell(computer);//computer attend the middle of board always please let it do :)
			computerp_x=middle;
			computerp_y=middle;
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
			if(hexcells[computerp_x+1][computerp_y].getCell()==User1 && hexcells[computerp_x+1][computerp_y-1].getCell()!=User1) hexcells[computerp_x+1][computerp_y-1].setcell(computer);
			else if(hexcells[computerp_x+1][computerp_y].getCell()!=User1){hexcells[computerp_x+1][computerp_y].setcell(computer);}
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
			if(hexcells[computerp_x-1][computerp_y].getCell()==User1 && hexcells[computerp_x-1][computerp_y+1].getCell()!=User1) hexcells[computerp_x-1][computerp_y+1].setcell(computer);
			else if(hexcells[computerp_x-1][computerp_y].getCell()!=User1){hexcells[computerp_x-1][computerp_y].setcell(computer);}
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
			if(hexcells[computerp_x-1][computerp_y].getCell()==User1 && hexcells[computerp_x-1][computerp_y+1].getCell()!=User1) hexcells[computerp_x-1][computerp_y+1].setcell(computer);
			else if(hexcells[computerp_x-1][computerp_y].getCell()!=User1) { hexcells[computerp_x-1][computerp_y].setcell(computer); }
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
			if(hexcells[computerp_x+1][computerp_y].getCell()==User1 && hexcells[computerp_x+1][computerp_y-1].getCell()!=User1) hexcells[computerp_x+1][computerp_y-1].setcell(computer);
			else if(hexcells[computerp_x+1][computerp_y].getCell()!=User1) {hexcells[computerp_x+1][computerp_y].setcell(computer); }
		}
	}
}
bool HEX::control_moves_x(){
	if(getTempj()+1==size){
		setLastp_x(getTempi()+1);//we keep the last x point to end game
		setLastp_y(getTempj()+1);
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
	int i,j;
	ofstream save_load_file;
	save_load_file.open(getFilename());
	save_load_file<<getSize()<<endl;
	for(i=0;i<getSize();i++){
		for(j=0;j<getSize();j++){
			save_load_file<<hexcells[i][j].getCell();
		}
		save_load_file<<endl;
	}
	if(getControl()=='u'){
		save_load_file<<"USERVSUSER"<<endl;
	}
	else if(getControl()=='c'){
		save_load_file<<"USERVSCOMPUTER"<<endl;
	}
	save_load_file.close();
}
void HEX::load_file(){
	char data;
	int control=0,control1=0;
	int i=0 , j=0;
	int size2;
	string line,str,size1;
	ifstream save_load_file;//Create function 
	save_load_file.open(getFilename());
	if(!save_load_file.fail()){//for avoiding to open unexist file
		while(!save_load_file.eof()){//to reach end of file
			if(control1==0){
				getline(save_load_file,size1);
				size2=stoi(size1);
				setSize(size2);
				Cell a;
				hexcells.resize(getSize());
				temp_arrey.resize(getSize());
				for (int i = 0; i < getSize(); i++)
				{
					for (int j = 0; j<getSize(); j++)
					{
						hexcells[i].push_back(a);
						temp_arrey[i].push_back(a);
					}
				}
				//getline(save_load_file,line);
				control1++;
			}
			save_load_file.get(data);//we are reading the data from file
			hexcells[i][j].setcell(data);//then we send board size
			if(j==getSize()-1 && i==getSize()-1){ //if we reach end of board size file will end
				getline(save_load_file,line);
				getline(save_load_file,str);
				save_load_file.close();
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
		}
		else if(str.compare("USERVSCOMPUTER")==0){
			print_function();
			setControl1('c');
		}
	}
	if(control==0){ 
		cerr<<"İnvalid File! Please enter a file name which has been created before"<<endl<<endl;
	}
}
bool HEX::compareGame(const HEX& anotherObject){
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