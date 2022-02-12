#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;
#include"pack.h"
int main(){
	int choose=0;
	decltype(choose) size;
	size=is_valid();
	char board_size[12][12];
	iterate_func(board_size,size);//fill arrey with '*'
	print_function(board_size,size);//print first situation
	cout<<"If you play the game with computer Please enter 1, If you play the game with user2 enter 2"<<endl;
	cin>>choose;
	if(choose==1){
		play_computer(board_size,size);
	}
	else if(choose==2){
		play_user2(board_size,size);
	}
	else{
		cout<<"invalid input ,Try Again!"<<endl;
	}
}
int is_valid(){
	int size;
	auto valid=false;
	while(valid==false){
		cout<<"Please enter the board size ,the size can be 6*6 7*7 8*8 9*9 10*10 11*11 and 12*12!"<<endl;
		cout<<"İf you play with computer please enter size 7*7 or 11*11 the others size can not work!"<<endl;
		cin>>size;
		if(size<6 || size>12){
			cout<<"The board size is invalid ,Try Again!"<<endl;
		}
		else{
			valid=true;
		}
	}
	return size; //return valid size
}
void iterate_func(char board_size[12][12],const int& size){
	int i;
	decltype(i) j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			board_size[i][j]=empty;
		}
	}
}
void iterate_func1(char temp_arrey[12][12],const int& size){
	int i;
	decltype(i) j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			temp_arrey[i][j]=empty;
		}
	}
}
void iterate_func2(char bridge[20][20],const int& size){
	int i;
	decltype(i) j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			bridge[i][j]=empty;
		}
	}
}
void print_function(char board_size[12][12],const int& size){//Print BOARD
	int i,j;
	auto firstc='A';
	auto firsti='1';
	cout<<"  ";
	for(i=0;i<size;i++,firstc++){
		cout<<" "<<firstc; 
	}
	cout<<"\n";
	for(i=0;i<size;i++){
		if(i<9){
			cout<<" "<<i+1;
		}
		else{
			cout<<i+1;
		}
		for(j=0;j<i+1;j++){
			cout<<" ";
		}
		for(j=0;j<size;j++){
			cout<<board_size[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
}
void play_user2(char board_size[12][12],const int& size){
	bool finish=false; //for controlling the end of game
	bool end_game1,end_game2;
	while(finish==false){
		move_inboard_user1(board_size,size);
		print_function(board_size,size);
		end_game1=end_game_user1(board_size,size);
		if(end_game1==true){ 
			print_function(board_size,size);
			cout<<"User 1 is win !"<<endl;
			finish=true;
			break;
		}
		move_inboard_user2(board_size,size);
		print_function(board_size,size);
		end_game2=end_game_user2(board_size,size);
		if(end_game2==true){
			print_function(board_size,size);
			cout<<"User 2 is win !"<<endl;
			finish=true;
			break;
		}
	}
}
void move_inboard_user1(char board_size[12][12],const int& size){
	int charcoordinate_temp1,coordinate1;
	char charcoordinate1;
	string command1,command2;
	char control2='u';
	bool control=false,control1=false;
	while(control==false && control1==false){
		cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter SAVE or LOAD for user 1"<<endl;
		cin>>command1>>command2;
		if(command1!="SAVE" && command1!="LOAD"){
			charcoordinate1=command1[0];
			coordinate1=stoi(command2);
		}
		else if(command1=="SAVE"){
			save_file(board_size,size,command2,control2);
		}
		else if(command1=="LOAD"){
			load_file(board_size,size,command2);
		}
		if(command1!="SAVE" && command1!="LOAD"){
			if(coordinate1<=size && coordinate1>0){
				control=true; // control the x axis
				charcoordinate1-=17;
				charcoordinate_temp1=charcoordinate1-'0';
				coordinate1--;
			}
			else{cout<<"invalid input try again!"<<endl;}
			if(board_size[coordinate1][charcoordinate_temp1]==empty){
				board_size[coordinate1][charcoordinate_temp1]=User1;
				control1=true;//control the point is filled or not 
			}
			else{
				cout<<"this place is not empty.Try again!"<<endl;
			}
		}
	}
}
void move_inboard_user2(char board_size[12][12],const int& size){
	int charcoordinate_temp2,coordinate2;
	char charcoordinate2;
	string command1,command2;
	char control2='u';
	bool control=false,control1=false;
	fstream save_load_file;
	while(control1==false && control==false){
		cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter SAVE or LOAD for user 2"<<endl;
		cin>>command1>>command2;
		if(command1!="SAVE" && command1!="LOAD"){
			save_load_file.open(command2);
			charcoordinate2=command1[0];
			coordinate2=stoi(command2);
		}
		else if(command1=="SAVE"){
			save_file(board_size,size,command2,control2);
		}
		else if(command1=="LOAD"){
			load_file(board_size,size,command2);
		}
		if(command1!="SAVE" && command1!="LOAD"){
			if(coordinate2<=size && coordinate2>0){
				control=true;
				charcoordinate2-=17;
				charcoordinate_temp2=charcoordinate2-'0';
				coordinate2--;
			}
			else{cout<<"invalid input try again!"<<endl;}
			if(board_size[coordinate2][charcoordinate_temp2]==empty){
				board_size[coordinate2][charcoordinate_temp2]=User2;
				control1=true;
			}
			else{
				cout<<"this place is not empty.Try again!"<<endl;
			}
		}
	}
}
bool end_game_user1(char board_size[12][12],const int& size){
	int i,tempi,j=0;
	int lastp_x,lastp_y;
	bool control;
	char temp_arrey[12][12];
	iterate_func1(temp_arrey,size);// temp_arrey is create for control the not returning to passing point with recursion 
	for(i=0;i<size;i++){
		if(board_size[i][j]==User1){//we find first point and starting the recursion with finding x words
			tempi=i;
			control=control_moves_x(board_size,size,tempi,j,temp_arrey,&lastp_x,&lastp_y);//lastp_x and lastp_y created for computer game
			if(control==true){//if game end the connected words is up
				up_words_x(board_size,size,lastp_x,lastp_y);
				cout<<lastp_x<<lastp_y<<endl;
				return true;// to end the game
			}
		}
	}
	return false;
}
bool end_game_user2(char board_size[12][12],const int& size){
	int i=0,tempi,j=0;
	bool control=false;
	int lastp_x,lastp_y;
	char temp_arrey[12][12];
	iterate_func1(temp_arrey,size);
	for(j=0;j<size;j++){
		if(board_size[i][j]==User2){//we find first point and starting the recursion with finding o words
			tempi=j;
			control=control_moves_o(board_size,size,tempi,j,temp_arrey,&lastp_x,&lastp_y);
			if(control==true){
				up_words_o(board_size,size,lastp_x,lastp_y);
				return true;
			}
		}
	}
	return false;	
}
bool end_game_computer(char board_size[12][12],const int& size){
	int i=0,tempi,j=0;
	bool control=false;
	int lastp_x,lastp_y;
	char temp_arrey[12][12];
	iterate_func1(temp_arrey,size);
	for(j=0;j<size;j++){
		if(board_size[i][j]==User2){
			tempi=j;
			control=control_moves_o(board_size,size,tempi,j,temp_arrey,&lastp_x,&lastp_y);
			if(control==true){
				up_words_o(board_size,size,lastp_x,lastp_y);
				return true;
			}
		}
	}
	return false;	
}
bool control_moves_x(char board_size[12][12],const int& size,const int& tempi,const int& tempj,char temp_arrey[12][12],int *lastp_x,int *lastp_y){
	int i=0;
	if(tempj+1==size){
		*lastp_x=tempi+1;//we keep the last x point to end game
		*lastp_y=tempj+1;
		return true;
	}
	if(board_size[tempi-1][tempj]==User1){//kuzey
		if(temp_arrey[tempi-1][tempj]!=User1){//to avoid of going back to and avoid infinite loop
			temp_arrey[tempi-1][tempj]=User1;
			return control_moves_x(board_size,size,tempi-1,tempj,temp_arrey,lastp_x,lastp_y); //recursive to around existing x values
		}
	}
	if(board_size[tempi+1][tempj]==User1){//güney
		if(temp_arrey[tempi+1][tempj]!=User1){
			temp_arrey[tempi+1][tempj]=User1;
			return control_moves_x(board_size,size,tempi+1,tempj,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi-1][tempj+1]==User1){//kuzeydoğu
		if(temp_arrey[tempi-1][tempj+1]!=User1){
			temp_arrey[tempi-1][tempj+1]=User1;
			return control_moves_x(board_size,size,tempi-1,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi][tempj+1]==User1){//doğu
		if(temp_arrey[tempi][tempj+1]!=User1){
			temp_arrey[tempi][tempj+1]=User1;
			return control_moves_x(board_size,size,tempi,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi][tempj-1]==User1){//batı
		if(temp_arrey[tempi][tempj-1]!=User1){
			temp_arrey[tempi][tempj-1]=User1;
			return control_moves_x(board_size,size,tempi,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi+1][tempj-1]==User1){//güneybatı
		if(temp_arrey[tempi+1][tempj-1]!=User1){
			temp_arrey[tempi+1][tempj-1]=User1;
			return control_moves_x(board_size,size,tempi+1,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	return false;
}
bool control_moves_o(char board_size[12][12],const int& size,const int& tempi,const int& tempj,char temp_arrey[12][12],int *lastp_x,int *lastp_y){
	int i=0;
	if(board_size[tempi-1][tempj]==User2){//kuzey
		if(temp_arrey[tempi-1][tempj]!=User2){
			temp_arrey[tempi-1][tempj]=User2;
		return control_moves_o(board_size,size,tempi-1,tempj,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi+1][tempj]==User2){//güney
		if(temp_arrey[tempi+1][tempj]!=User2){
			temp_arrey[tempi+1][tempj]=User2;
		return control_moves_o(board_size,size,tempi+1,tempj,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi-1][tempj+1]==User2){//kuzeydoğu
		if(temp_arrey[tempi-1][tempj+1]!=User2){
			temp_arrey[tempi-1][tempj+1]=User2;
		return control_moves_o(board_size,size,tempi-1,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi][tempj+1]==User2){//doğu
		if(temp_arrey[tempi][tempj+1]!=User2){
			temp_arrey[tempi][tempj+1]=User2;
			return control_moves_o(board_size,size,tempi,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi][tempj-1]==User2){//batı
		if(temp_arrey[tempi][tempj-1]!=User2){
			temp_arrey[tempi][tempj-1]=User2;
		return control_moves_o(board_size,size,tempi,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi+1][tempj-1]==User2){//güneybatı
		if(temp_arrey[tempi+1][tempj-1]!=User2){
			temp_arrey[tempi+1][tempj-1]=User2;
		return control_moves_o(board_size,size,tempi+1,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(tempi+1==size){
		*lastp_x=tempi+1;//to end the game we save the last point and in upwords function we will use it
		*lastp_y=tempj+1;
		return true;
	}
	return false;
}
void up_words_x(char board_size[12][12],const int& size,const int& lastp_x,const int& lastp_y){
	if(board_size[lastp_x-1][lastp_y]==User1){//kuzey
		if(board_size[lastp_x-1][lastp_y]!=User1-32){//to avoid the going back and to avoid infinite loop
			board_size[lastp_x-1][lastp_y]=User1-32; //up all connected words
			up_words_x(board_size,size,lastp_x-1,lastp_y);//recursive to around existing x values
		}												//this function will end if the all connected x values are up
	}
	if(board_size[lastp_x-1][lastp_y+1]==User1){//kuzeydoğu
		if(board_size[lastp_x-1][lastp_y+1]!=User1-32){
			board_size[lastp_x-1][lastp_y+1]=User1-32;
			 up_words_x(board_size,size,lastp_x-1,lastp_y+1);
		}
	}
	if(board_size[lastp_x][lastp_y-1]==User1){//batı
		if(board_size[lastp_x][lastp_y-1]!=User1-32){
			board_size[lastp_x][lastp_y-1]=User1-32;
			 up_words_x(board_size,size,lastp_x,lastp_y-1);
		}
	}
	if(board_size[lastp_x][lastp_y+1]==User1){//doğu
		if(board_size[lastp_x][lastp_y+1]!=User1-32){
			board_size[lastp_x][lastp_y+1]=User1-32;
			 up_words_x(board_size,size,lastp_x,lastp_y+1);
		}
	}
	if(board_size[lastp_x+1][lastp_y]==User1){//güney
		if(board_size[lastp_x+1][lastp_y]!=User1-32){
			board_size[lastp_x+1][lastp_y]=User1-32;
			 up_words_x(board_size,size,lastp_x+1,lastp_y);
		}
	}
	if(board_size[lastp_x+1][lastp_y-1]==User1){//güneybatı
		if(board_size[lastp_x+1][lastp_y-1]!=User1-32){
			board_size[lastp_x+1][lastp_y-1]=User1-32;
			 up_words_x(board_size,size,lastp_x+1,lastp_y-1);
		}
	}
	if(board_size[lastp_x-1][lastp_y-1]==User1){//kuzeybatı
		if(board_size[lastp_x-1][lastp_y-1]!=User1-32){
			board_size[lastp_x-1][lastp_y-1]=User1-32;
			 up_words_x(board_size,size,lastp_x-1,lastp_y-1);
		}
	}
	if(board_size[lastp_x+1][lastp_y+1]==User1){//güneydoğu
		if(board_size[lastp_x+1][lastp_y+1]!=User1-32){
			board_size[lastp_x+1][lastp_y+1]=User1-32;
			 up_words_x(board_size,size,lastp_x+1,lastp_y+1);
		}
	}
}
void up_words_o(char board_size[12][12],const int& size,const int& lastp_x,const int& lastp_y){
	if(board_size[lastp_x-1][lastp_y]==User2){//kuzey
		if(board_size[lastp_x-1][lastp_y]!=User2-32){
			board_size[lastp_x-1][lastp_y]=User2-32;
			up_words_o(board_size,size,lastp_x-1,lastp_y);
		}
	}
	if(board_size[lastp_x-1][lastp_y+1]==User2){//kuzeydoğu
		if(board_size[lastp_x-1][lastp_y+1]!=User2-32){
			board_size[lastp_x-1][lastp_y+1]=User2-32;
			 up_words_o(board_size,size,lastp_x-1,lastp_y+1);
		}
	}
	if(board_size[lastp_x][lastp_y-1]==User2){//batı
		if(board_size[lastp_x][lastp_y-1]!=User2-32){
			board_size[lastp_x][lastp_y-1]=User2-32;
			 up_words_o(board_size,size,lastp_x,lastp_y-1);
		}
	}
	if(board_size[lastp_x][lastp_y+1]==User2){//doğu
		if(board_size[lastp_x][lastp_y+1]!=User2-32){
			board_size[lastp_x][lastp_y+1]=User2-32;
			 up_words_o(board_size,size,lastp_x,lastp_y+1);
		}
	}
	if(board_size[lastp_x+1][lastp_y]==User2){//güney
		if(board_size[lastp_x+1][lastp_y]!=User2-32){
			board_size[lastp_x+1][lastp_y]=User2-32;
			 up_words_o(board_size,size,lastp_x+1,lastp_y);
		}
	}
	if(board_size[lastp_x+1][lastp_y-1]==User2){//güneybatı
		if(board_size[lastp_x+1][lastp_y-1]!=User2-32){
			board_size[lastp_x+1][lastp_y-1]=User2-32;
			 up_words_o(board_size,size,lastp_x+1,lastp_y-1);
		}
	}
	if(board_size[lastp_x-1][lastp_y-1]==User2){//kuzeybatı
		if(board_size[lastp_x-1][lastp_y-1]!=User2-32){
			board_size[lastp_x-1][lastp_y-1]=User2-32;
			 up_words_o(board_size,size,lastp_x-1,lastp_y-1);
		}
	}
	if(board_size[lastp_x+1][lastp_y+1]==User2){//güneydoğu
		if(board_size[lastp_x+1][lastp_y+1]!=User2-32){
			board_size[lastp_x+1][lastp_y+1]=User2-32;
			 up_words_o(board_size,size,lastp_x+1,lastp_y+1);
		}
	}
}
void move_inboard_computer(char board_size[12][12],int size,int lastp_x,int lastp_y,int counter,char bridge[20][20]){
	int charcoordinate_temp2,coordinate2;
	char charcoordinate2;
	bool control=false,control1=false,control2=false,control3=false,control4=false,control5=false;
	int computerp_x,computerp_y,i,j;
	int middle,firstp_x,firstp_y;
	middle=(size+1)/2-1;//we find the middle of board
	for (int k = 0; k < size; ++k)
	{
		if(board_size[0][k]==computer && board_size[size][k]){//when bridge is done and starting combine them we check this there if combining is started we pass the make bridge
			control5=true;
			break;
		}
	}
	if(counter==0){
		board_size[middle][middle]=computer;//computer attend the middle of board always please let it do :)
	}
	else if(counter>=1 && bridge[lastp_y][lastp_x]=='a'){//if user threaten the foot of bridges computer defence this
		bridge_protect(board_size,size,lastp_x,lastp_y,bridge);
	}
	else if(counter>=1 && control5==false){//if there is nothing to prevent we keep making the bridge
		if(lastp_y>=middle){
			for(i=0;i<size;i++){
				for(j=0;j<size;j++){
					if(board_size[i][j]==computer){//we find last o point in board then make bridge
						computerp_x=i;
						computerp_y=j;
					}
				}
			}
			control=make_bridge(board_size,size,lastp_x,lastp_y,bridge,computerp_x,computerp_y);
			if(control==true){
				lastp_x=middle-2;//i did this because bridge can be done other diemension there is no bridge make in this diemension
				lastp_y=middle-2;
				for(i=0;i<size;i++){
					for(j=0;j<size;j++){
						if(board_size[i][j]==computer){//we find the first o point in board to make bridge
							computerp_x=i;
							computerp_y=j;
							control2=true;
							break;
						}
					}
					if(control2==true){//stop the for loop
						break;
					}
				}
			}
			control4=make_bridge(board_size,size,lastp_x,lastp_y,bridge,computerp_x,computerp_y);
		}
		else if(lastp_y<middle){
			for(i=0;i<size;i++){
				for(j=0;j<size;j++){
					if(board_size[i][j]==computer){
						computerp_x=i;
						computerp_y=j;
						control=make_bridge(board_size,size,lastp_x,lastp_y,bridge,computerp_x,computerp_y);
						if(control==true){
							lastp_x=middle+1;
							lastp_y=middle+1;
							for(i=0;i<size;i++){
								for(j=0;j<size;j++){
									if(board_size[i][j]==computer){
										computerp_x=i;
										computerp_y=j;
									}
								}
							}
							control3=make_bridge(board_size,size,lastp_x,lastp_y,bridge,computerp_x,computerp_y);
							break;
						}
					}
				}
			}
		}
	}
	else if(control5==true){//if there is no bridge to make the fill blanks function will start to connect bridges 
		fill_blanks(board_size,size,lastp_x,lastp_y,bridge);
	}
}
void fill_blanks(char board_size[12][12],const int size,const int lastp_x,const int lastp_y,char bridge[20][20]){
	int counter=0;
	bool control=false;//exit the for loop
	for (int k = 0; k < size; ++k)
	{
		for (int l = 0; l < size; ++l)
		{
			cout<<bridge[k][l];/* code */
		}
		cout<<endl;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; ++j)
		{
			if(bridge[i][j]==computer){//it is enough to have one o point in one line but this points have to be connected
				break;
			}	
			if(bridge[i][j]=='a'){//fill the points between bridge
				if(board_size[i][j]!=User1){					
					board_size[i][j]=computer;
				}
				bridge[i][j]=computer;//we attend this because next foor loop we avoid the enter this line
				control=true;
				break;
			}
		}
		if(control==true) break;
	}
}
void bridge_protect(char board_size[12][12],const int& size,const int& lastp_x,const int& lastp_y,char bridge[20][20]){
	if(bridge[lastp_y+1][lastp_x-1]=='a'){//the foots of bridge
		if(board_size[lastp_y+1][lastp_x-1]!=User1){ 
			board_size[lastp_y+1][lastp_x-1]=computer;//the one of the foot of bridges was filled we fill the another foot to make connect 
			bridge[lastp_y+1][lastp_x-1]=computer;
		}
	}																				//and we avoid passing x this bridge
	else if(bridge[lastp_y-1][lastp_x+1]=='a'){
		if(board_size[lastp_y-1][lastp_x+1]!=User1){
			board_size[lastp_y-1][lastp_x+1]=computer;
			bridge[lastp_y-1][lastp_x+1]=computer;
		}
	}
}
bool make_bridge(char board_size[12][12],const int& size,const int& lastp_x,const int& lastp_y,char bridge[20][20],const int& computerp_x,const int& computerp_y){
	int smallp_x,smallp_y,smalldistance;
	int middle=(size+1)/2-1;//first of all the computer-user game is working with 7*7 and 11*11 board_size
							//because i try to make bridge because of this the end of the bridge is confused some board size
	if(lastp_y>middle){//aşa sağ
										  //when user enter the x bottom right computer make bridge to bottom right to prevent the him to end the game 
		if(computerp_x!=size){
			if(board_size[computerp_x+1][computerp_y+1]==empty) board_size[computerp_x+1][computerp_y+1]=computer;//if bottom right bridges is done we continue with upper right or upper left
			//bridge[computerp_x+1][computerp_y+1]=computer;//we save the haeds of bridge bridge arrey to control the bridges 
			//bridge[computerp_x][computerp_y]=computer;
			bridge[computerp_x+1][computerp_y]='a';//we save the bridge foot to control the bridges
			bridge[computerp_x][computerp_y+1]='a';
		}
		else if(computerp_x==size){
			bridge[computerp_x-1][computerp_y]='a';
		}
		if(computerp_x+1==size){//when the maximum bridge can be done is finished one dimension we return the other diemonsion to connect bridge and end game
			return true;
		}
	return false;
	}
	else if(lastp_y<=middle){//yukarı sol
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				cout<<bridge[i][j];/* code */
			}
			cout<<endl;
		}
		if(computerp_x!=0){
			if(board_size[computerp_x-1][computerp_y-1]==empty) board_size[computerp_x-1][computerp_y-1]=computer;
			//bridge[computerp_x-1][computerp_y-1]=computer;
			//bridge[computerp_x][computerp_y]=computer;
			bridge[computerp_x][computerp_y-1]='a';
			bridge[computerp_x-1][computerp_y]='a';
		}
		else if(computerp_x==0){
			bridge[computerp_x+1][computerp_y]='a';
		}
		if(computerp_x-1==0){
			return true;
		}
	}
	return false;//maximum bridge can be done is not done we keep making bridge
}	
void play_computer(char board_size[12][12],const int& size){
	bool finish=false;
	bool end_game1,end_game2;
	int lastp_x,lastp_y;
	int counter=0;
	char bridge[20][20];
	iterate_func2(bridge,size);
	while(finish==false){
		move_inboard_user(board_size,size,&lastp_x,&lastp_y);
		print_function(board_size,size);
		end_game1=end_game_user1(board_size,size);
		if(end_game1==true){
			print_function(board_size,size);
			cout<<"User 1 is win !"<<endl;
			finish=true;
			break;
		}
		move_inboard_computer(board_size,size,lastp_y,lastp_x,counter,bridge);
		counter++;
		print_function(board_size,size);
		end_game2=end_game_computer(board_size,size);
		if(end_game2==true){
			print_function(board_size,size);
			cout<<"Computer Win!"<<endl;
			finish=true;
			break;
		}
	}
}
void move_inboard_user(char board_size[12][12],const int& size,int *lastp_x,int *lastp_y){
	int charcoordinate_temp1,coordinate1;
	char charcoordinate1;
	string command1,command2;
	char control2='c';
	bool control=false,control1=false;
	while(control==false && control1==false){
		cout<<"Please enter a coordinate which you want make a move like Q 7 or if you want to save and load please enter SAVE or LOAD for user 1"<<endl;
		cin>>command1>>command2;
		if(command1!="SAVE" && command1!="LOAD"){
			charcoordinate1=command1[0];
			coordinate1=stoi(command2);
		}
		else if(command1=="SAVE"){
			save_file(board_size,size,command2,control2);
		}
		else if(command1=="LOAD"){
			load_file(board_size,size,command2);
		}
		if(command1!="SAVE" && command1!="LOAD"){
			if(coordinate1<=size && coordinate1>0){
				control=true;
				charcoordinate1-=17;
				charcoordinate_temp1=charcoordinate1-'0';
				coordinate1--;
			}
			else{cout<<"invalid input try again!"<<endl;}
			if(board_size[coordinate1][charcoordinate_temp1]==empty){
				board_size[coordinate1][charcoordinate_temp1]=User1;
				control1=true;
			}
			else{
				cout<<"this place is not empty.Try again!"<<endl;
				}
		}
	}
	*lastp_x=coordinate1;//we keep last point because computer make move by looking this point
	*lastp_y=charcoordinate_temp1;
}
void save_file(char board_size[12][12],const int& size,const string& file_name,char control){
	int i,j;
	ofstream save_load_file;
	save_load_file.open(file_name);
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			save_load_file<<board_size[i][j];
		}
		save_load_file<<endl;
	}
	if(control=='u'){
		save_load_file<<"USER VS USER"<<" "<<"SIZE="<<size;
	}
	else if(control=='c'){
		save_load_file<<"USER VS COMPUTER"<<" "<<"SIZE="<<size;
	}
	save_load_file.close();
}
void load_file(char board_size[12][12],const int& size,const string& file_name){
	char data;
	int control=0;
	int i=0 , j=0;
	string line;
	ifstream save_load_file;
	save_load_file.open(file_name);
	if(!save_load_file.fail()){
		while(!save_load_file.eof()){
			save_load_file.get(data);
			board_size[i][j]=data;
			if(j==size-1 && i==size-1){
				print_function(board_size,size);
				save_load_file.close();
				break;
			}
			else if(j==size-1){
				getline(save_load_file,line);
				i++;
				j=0;
			}
			else{
				j++;
			}
		}
		control=1;
	}
	if(control==0) cout<<"İnvalid File! Please enter a file name which has been created before"<<endl<<endl;
}
