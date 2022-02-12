#include<iostream>
using namespace std;
#include"pack.h"
int main(){
	int size,choose=2;
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
	bool valid=false;
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
void iterate_func(char board_size[12][12],int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			board_size[i][j]='*';
		}
	}
}
void iterate_func1(char temp_arrey[12][12],int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			temp_arrey[i][j]='*';
		}
	}
}
void iterate_func2(char bridge[20][20],int size){
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			bridge[i][j]='*';
		}
	}
}
void print_function(char board_size[12][12],int size){//Print BOARD
	int i,j;
	char firstc='A';
	char firsti='1';
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
void play_user2(char board_size[12][12],int size){
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
void move_inboard_user1(char board_size[12][12],int size){
	int charcoordinate_temp1,coordinate1;
	char charcoordinate1;
	bool control=false,control1=false;
	while(control==false && control1==false){
		cout<<"Please enter a coordinate which you want make a move like Q 7 for user 1"<<endl;
		cin>>charcoordinate1>>coordinate1;
		if(coordinate1<=size && coordinate1>0) control=true; // control the x axis
		else{cout<<"invalid input try again!"<<endl;}
		charcoordinate1-=17;
		charcoordinate_temp1=charcoordinate1-'0';
		coordinate1--;
		if(board_size[coordinate1][charcoordinate_temp1]=='*'){
			board_size[coordinate1][charcoordinate_temp1]='x';
			control1=true;//control the point is filled or not 
		}
		else{
			cout<<"this place is not empty.Try again!"<<endl;
		}
	}
}
void move_inboard_user2(char board_size[12][12],int size){
	int charcoordinate_temp2,coordinate2;
	char charcoordinate2;
	bool control=false,control1=false;
	while(control1==false && control==false){
		cout<<"Please enter a coordinate which you want make a move like Q 7 for user 2"<<endl;
		cin>>charcoordinate2>>coordinate2;
		if(coordinate2<=size && coordinate2>0) control=true;
		else{cout<<"invalid input try again!"<<endl;}
		charcoordinate2-=17;
		charcoordinate_temp2=charcoordinate2-'0';
		coordinate2--;
		if(board_size[coordinate2][charcoordinate_temp2]=='*'){
			board_size[coordinate2][charcoordinate_temp2]='o';
			control1=true;
		}
		else{
			cout<<"this place is not empty.Try again!"<<endl;
		}
	}
}
bool end_game_user1(char board_size[12][12],int size){
	int i,tempi,j=0;
	int lastp_x,lastp_y;
	bool control;
	char temp_arrey[12][12];
	iterate_func1(temp_arrey,size);// temp_arrey is create for control the not returning to passing point with recursion 
	for(i=0;i<size;i++){
		if(board_size[i][j]=='x'){//we find first point and starting the recursion with finding x words
			tempi=i;
			control=control_moves_x(board_size,size,tempi,j,temp_arrey,&lastp_x,&lastp_y);//lastp_x and lastp_y created for computer game
			if(control==true){//if game end the connected words is up
				up_words_x(board_size,size,lastp_x,lastp_y);
				return true;// to end the game
			}
		}
	}
	return false;
}
bool end_game_user2(char board_size[12][12],int size){
	int i=0,tempi,j=0;
	bool control=false;
	int lastp_x,lastp_y;
	char temp_arrey[12][12];
	iterate_func1(temp_arrey,size);
	for(j=0;j<size;j++){
		if(board_size[i][j]=='o'){//we find first point and starting the recursion with finding o words
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
bool end_game_computer(char board_size[12][12],int size){
	int i=0,tempi,j=0;
	bool control=false;
	int lastp_x,lastp_y;
	char temp_arrey[12][12];
	iterate_func1(temp_arrey,size);
	for(j=0;j<size;j++){
		if(board_size[i][j]=='o'){
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
bool control_moves_x(char board_size[12][12],int size,int tempi,int tempj,char temp_arrey[12][12],int *lastp_x,int *lastp_y){
	int i=0;
	if(tempj+1==size){
		*lastp_x=tempi+1;//we keep the last x point to end game
		*lastp_y=tempj+1;
		return true;
	}
	if(board_size[tempi-1][tempj]=='x'){//kuzey
		if(temp_arrey[tempi-1][tempj]!='x'){//to avoid of going back to and avoid infinite loop
			temp_arrey[tempi-1][tempj]='x';
			return control_moves_x(board_size,size,tempi-1,tempj,temp_arrey,lastp_x,lastp_y); //recursive to around existing x values
		}
	}
	if(board_size[tempi+1][tempj]=='x'){//güney
		if(temp_arrey[tempi+1][tempj]!='x'){
			temp_arrey[tempi+1][tempj]='x';
			return control_moves_x(board_size,size,tempi+1,tempj,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi-1][tempj+1]=='x'){//kuzeydoğu
		if(temp_arrey[tempi-1][tempj+1]!='x'){
			temp_arrey[tempi-1][tempj+1]='x';
			return control_moves_x(board_size,size,tempi-1,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi+1][tempj+1]=='x'){//güneydoğu
		if(temp_arrey[tempi+1][tempj+1]!='x'){
			temp_arrey[tempi+1][tempj+1]='x';
			return control_moves_x(board_size,size,tempi+1,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi][tempj+1]=='x'){//doğu
		if(temp_arrey[tempi][tempj+1]!='x'){
			temp_arrey[tempi][tempj+1]='x';
			return control_moves_x(board_size,size,tempi,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi][tempj-1]=='x'){//batı
		if(temp_arrey[tempi][tempj-1]!='x'){
			temp_arrey[tempi][tempj-1]='x';
			return control_moves_x(board_size,size,tempi,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi-1][tempj-1]=='x'){//kuzeybatı
		if(temp_arrey[tempi-1][tempj-1]!='x'){
			temp_arrey[tempi-1][tempj-1]='x';
			return control_moves_x(board_size,size,tempi-1,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi+1][tempj-1]=='x'){//güneybatı
		if(temp_arrey[tempi+1][tempj-1]!='x'){
			temp_arrey[tempi+1][tempj-1]='x';
			return control_moves_x(board_size,size,tempi+1,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	return false;
}
bool control_moves_o(char board_size[12][12],int size,int tempi,int tempj,char temp_arrey[12][12],int *lastp_x,int *lastp_y){
	int i=0;
	if(board_size[tempi-1][tempj]=='o'){//kuzey
		if(temp_arrey[tempi-1][tempj]!='o'){
			temp_arrey[tempi-1][tempj]='o';
		return control_moves_o(board_size,size,tempi-1,tempj,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi+1][tempj]=='o'){//güney
		if(temp_arrey[tempi+1][tempj]!='o'){
			temp_arrey[tempi+1][tempj]='o';
		return control_moves_o(board_size,size,tempi+1,tempj,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi-1][tempj+1]=='o'){//kuzeydoğu
		if(temp_arrey[tempi-1][tempj+1]!='o'){
			temp_arrey[tempi-1][tempj+1]='o';
		return control_moves_o(board_size,size,tempi-1,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi+1][tempj+1]=='o'){//güneydoğu
		if(temp_arrey[tempi+1][tempj+1]!='o'){
			temp_arrey[tempi+1][tempj+1]='o';
		return control_moves_o(board_size,size,tempi+1,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi][tempj+1]=='o'){//doğu
		if(temp_arrey[tempi][tempj+1]!='o'){
			temp_arrey[tempi][tempj+1]='o';
			return control_moves_o(board_size,size,tempi,tempj+1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi][tempj-1]=='o'){//batı
		if(temp_arrey[tempi][tempj-1]!='o'){
			temp_arrey[tempi][tempj-1]='o';
		return control_moves_o(board_size,size,tempi,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi-1][tempj-1]=='o'){//kuzeybatı
		if(temp_arrey[tempi-1][tempj-1]!='o'){
			temp_arrey[tempi-1][tempj-1]='o';
		return control_moves_o(board_size,size,tempi-1,tempj-1,temp_arrey,lastp_x,lastp_y);
		}
	}
	if(board_size[tempi+1][tempj-1]=='o'){//güneybatı
		if(temp_arrey[tempi+1][tempj-1]!='o'){
			temp_arrey[tempi+1][tempj-1]='o';
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
void up_words_x(char board_size[12][12],int size,int lastp_x,int lastp_y){
	if(board_size[lastp_x-1][lastp_y]=='x'){//kuzey
		if(board_size[lastp_x-1][lastp_y]!='X'){//to avoid the going back and to avoid infinite loop
			board_size[lastp_x-1][lastp_y]='X'; //up all connected words
			up_words_x(board_size,size,lastp_x-1,lastp_y);//recursive to around existing x values
		}												//this function will end if the all connected x values are up
	}
	if(board_size[lastp_x-1][lastp_y+1]=='x'){//kuzeydoğu
		if(board_size[lastp_x-1][lastp_y+1]!='X'){
			board_size[lastp_x-1][lastp_y+1]='X';
			 up_words_x(board_size,size,lastp_x-1,lastp_y+1);
		}
	}
	if(board_size[lastp_x+1][lastp_y+1]=='x'){//güneydoğu
		if(board_size[lastp_x+1][lastp_y+1]!='X'){
			board_size[lastp_x+1][lastp_y+1]='X';
			 up_words_x(board_size,size,lastp_x+1,lastp_y+1);
		}
	}
	if(board_size[lastp_x][lastp_y-1]=='x'){//batı
		if(board_size[lastp_x][lastp_y-1]!='X'){
			board_size[lastp_x][lastp_y-1]='X';
			 up_words_x(board_size,size,lastp_x,lastp_y-1);
		}
	}
	if(board_size[lastp_x][lastp_y+1]=='x'){//doğu
		if(board_size[lastp_x][lastp_y+1]!='X'){
			board_size[lastp_x][lastp_y+1]='X';
			 up_words_x(board_size,size,lastp_x,lastp_y+1);
		}
	}
	if(board_size[lastp_x+1][lastp_y]=='x'){//güney
		perror("b");
		if(board_size[lastp_x+1][lastp_y]!='X'){
			board_size[lastp_x+1][lastp_y]='X';
			 up_words_x(board_size,size,lastp_x+1,lastp_y);
		}
	}
	if(board_size[lastp_x-1][lastp_y-1]=='x'){//kuzeybatı
		if(board_size[lastp_x-1][lastp_y-1]!='X'){
			board_size[lastp_x-1][lastp_y-1]='X';
			 up_words_x(board_size,size,lastp_x-1,lastp_y-1);
		}
	}
	if(board_size[lastp_x+1][lastp_y-1]=='x'){//güneybatı
		if(board_size[lastp_x+1][lastp_y-1]!='X'){
			board_size[lastp_x+1][lastp_y-1]='X';
			 up_words_x(board_size,size,lastp_x+1,lastp_y-1);
		}
	}
}
void up_words_o(char board_size[12][12],int size,int lastp_x,int lastp_y){
	if(board_size[lastp_x-1][lastp_y]=='o'){//kuzey
		if(board_size[lastp_x-1][lastp_y]!='O'){
			board_size[lastp_x-1][lastp_y]='O';
			up_words_o(board_size,size,lastp_x-1,lastp_y);
		}
	}
	if(board_size[lastp_x-1][lastp_y+1]=='o'){//kuzeydoğu
		if(board_size[lastp_x-1][lastp_y+1]!='O'){
			board_size[lastp_x-1][lastp_y+1]='O';
			 up_words_o(board_size,size,lastp_x-1,lastp_y+1);
		}
	}
	if(board_size[lastp_x+1][lastp_y+1]=='o'){//güneydoğu
		if(board_size[lastp_x+1][lastp_y+1]!='O'){
			board_size[lastp_x+1][lastp_y+1]='O';
			 up_words_o(board_size,size,lastp_x+1,lastp_y+1);
		}
	}
	if(board_size[lastp_x][lastp_y-1]=='o'){//batı
		if(board_size[lastp_x][lastp_y-1]!='O'){
			board_size[lastp_x][lastp_y-1]='O';
			 up_words_o(board_size,size,lastp_x,lastp_y-1);
		}
	}
	if(board_size[lastp_x][lastp_y+1]=='o'){//doğu
		if(board_size[lastp_x][lastp_y+1]!='O'){
			board_size[lastp_x][lastp_y+1]='O';
			 up_words_o(board_size,size,lastp_x,lastp_y+1);
		}
	}
	if(board_size[lastp_x+1][lastp_y]=='o'){//güney
		if(board_size[lastp_x+1][lastp_y]!='O'){
			board_size[lastp_x+1][lastp_y]='O';
			 up_words_o(board_size,size,lastp_x+1,lastp_y);
		}
	}
	if(board_size[lastp_x-1][lastp_y-1]=='o'){//kuzeybatı
		if(board_size[lastp_x-1][lastp_y-1]!='O'){
			board_size[lastp_x-1][lastp_y-1]='O';
			 up_words_o(board_size,size,lastp_x-1,lastp_y-1);
		}
	}
	if(board_size[lastp_x+1][lastp_y-1]=='o'){//güneybatı
		if(board_size[lastp_x+1][lastp_y-1]!='O'){
			board_size[lastp_x+1][lastp_y-1]='O';
			 up_words_o(board_size,size,lastp_x+1,lastp_y-1);
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
		if(board_size[0][k]=='o'){//when bridge is done and starting combine them we check this there if combining is started we pass the make bridge
			control5=true;
			break;
		}
	}
	if(counter==0){
		board_size[middle][middle]='o';//computer attend the middle of board always please let it do :)
	}
	else if(counter>=1 && bridge[lastp_y][lastp_x]=='a'){//if user threaten the foot of bridges computer defence this
		bridge_protect(board_size,size,lastp_x,lastp_y,bridge);
	}
	else if(counter>=1&&control5==false){//if there is nothing to prevent we keep making the bridge
		if(lastp_y>middle){
			for(i=0;i<size;i++){
				for(j=0;j<size;j++){
					if(board_size[i][j]=='o'){//we find last o point in board then make bridge
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
						if(board_size[i][j]=='o'){//we find the first o point in board to make bridge
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
			if(control4==true){//when bridge can be done is end we starting the fill bridge foot 
								//i did this there one time because i tried the prevent the losing step
				fill_blanks(board_size,size,lastp_x,lastp_y,bridge);
			}
		}
		else if(lastp_y<middle){
			for(i=0;i<size;i++){
				for(j=0;j<size;j++){
					if(board_size[i][j]=='o'){
						computerp_x=i;
						computerp_y=j;
						control=make_bridge(board_size,size,lastp_x,lastp_y,bridge,computerp_x,computerp_y);
						if(control==true){
							lastp_x=middle+1;
							lastp_y=middle+1;
							for(i=0;i<size;i++){
								for(j=0;j<size;j++){
									if(board_size[i][j]=='o'){
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
			if(control3==true){
				fill_blanks(board_size,size,lastp_x,lastp_y,bridge);
			}
		}
	}
	else if(control5==true){//if there is no bridge to make the fill blanks function will start to connect bridges 
		fill_blanks(board_size,size,lastp_x,lastp_y,bridge);
	}
}
void fill_blanks(char board_size[12][12],int size,int lastp_x,int lastp_y,char bridge[20][20]){
	int counter=0;
	bool control=false;//exit the for loop
	for (int i = 0; i < size; i+=2)
	{
		for (int j = 0; j < size; ++j)
		{
			if(bridge[i][j]=='o'){//it is enough to have one o point in one line but this points have to be connected
				break;
			}	
			if(bridge[i][j]=='a'){//fill the points between bridge
				if(board_size[i][j]!='x'){					
					board_size[i][j]='o';
				}
				bridge[i][j]='o';//we attend this because next foor loop we avoid the enter this line
				control=true;
				break;
			}
		}
		if(control==true) break;
	}
}
void bridge_protect(char board_size[12][12],int size,int lastp_x,int lastp_y,char bridge[20][20]){
	if(bridge[lastp_y][lastp_x-1]=='a'){//the foots of bridge
		if(board_size[lastp_y][lastp_x-1]!='x') board_size[lastp_y][lastp_x-1]='o';//the one of the foot of bridges was filled we fill the another foot to make connect 
	}																				//and we avoid passing x this bridge
	else if(bridge[lastp_y][lastp_x+1]=='a'){
		if(board_size[lastp_y][lastp_x+1]!='x') board_size[lastp_y][lastp_x+1]='o';
	}
}
bool make_bridge(char board_size[12][12],int size,int lastp_x,int lastp_y,char bridge[20][20],int computerp_x,int computerp_y){
	int smallp_x,smallp_y,smalldistance;
	int middle=(size+1)/2-1;//first of all the computer-user game is working with 7*7 and 11*11 board_size
							//because i try to make bridge because of this the end of the bridge is confused some board size
	if(lastp_x>middle && lastp_y>=middle){//aşa sağ
										  //when user enter the x bottom right computer make bridge to bottom right to prevent the him to end the game 
		if(board_size[computerp_x+2][computerp_y+1]=='*' && computerp_x+2!=size) board_size[computerp_x+2][computerp_y+1]='o';//if bottom right bridges is done we continue with upper right or upper left
		bridge[computerp_x+2][computerp_y+1]='o';//we save the haeds of bridge bridge arrey to control the bridges 
		bridge[computerp_x][computerp_y]='o';
		bridge[computerp_x+1][computerp_y]='a';//we save the bridge foot to control the bridges
		bridge[computerp_x+1][computerp_y+1]='a';
		if(computerp_x+2==size){
			bridge[computerp_x+1][computerp_y-1]='a';//for preventing the passing of user through the upper and bottom of board we make tree foot to control easily
		}
		if(computerp_x+2==size){//when the maximum bridge can be done is finished one dimension we return the other diemonsion to connect bridge and end game
			return true;
		}
	return false;
	}
	else if(lastp_x<middle && lastp_y>middle){//aşa sol
		if(board_size[computerp_x+2][computerp_y-1]=='*' && computerp_x+2!=size)board_size[computerp_x+2][computerp_y-1]='o';
		bridge[computerp_x+2][computerp_y-1]='o';
		bridge[computerp_x][computerp_y]='o';
		bridge[computerp_x+1][computerp_y-1]='a';
		bridge[computerp_x+1][computerp_y]='a';
		if(computerp_x+2==size){
			bridge[computerp_x+1][computerp_y+1]='a';
		}
		if(computerp_x+2==size){
			return true;
		}
		return false;
	}
	else if(lastp_x>middle && lastp_y<middle){//yukarı sağ
		if(board_size[computerp_x-2][computerp_y+1]=='*' && computerp_x-1!=0 ) board_size[computerp_x-2][computerp_y+1]='o';
		if(computerp_x-1!=0)bridge[computerp_x-2][computerp_y+1]='o';
		if(computerp_x-1!=0)bridge[computerp_x][computerp_y]='o';
		bridge[computerp_x-1][computerp_y+1]='a';
		bridge[computerp_x-1][computerp_y]='a';
		if(computerp_x-1==0){
			bridge[computerp_x+1][computerp_y-1]='a';
		}
		if(computerp_x-1==0){
			return true;
		}
		return false;
	}	
	else if(lastp_x<middle && lastp_y<middle){//yukarı sol
		if(board_size[computerp_x-2][computerp_y-1]=='*' && computerp_x-1!=0){
			board_size[computerp_x-2][computerp_y-1]='o';
		} 
		if(computerp_x-1!=0) bridge[computerp_x-2][computerp_y-1]='o';
		if(computerp_x-1!=0) bridge[computerp_x][computerp_y]='o';
		bridge[computerp_x-1][computerp_y-1]='a';
		bridge[computerp_x-1][computerp_y]='a';
		if(computerp_x-1==0){
			bridge[computerp_x-1][computerp_y+1]='a';
		}
		if(computerp_x-1==0){
			return true;
		}
	}
	return false;//maximum bridge can be done is not done we keep making bridge
}	
void play_computer(char board_size[12][12],int size){
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
void move_inboard_user(char board_size[12][12],int size,int *lastp_x,int *lastp_y){
	int charcoordinate_temp1,coordinate1;
	char charcoordinate1;
	bool control=false,control1=false;
	while(control==false && control1==false){
		cout<<"Please enter a coordinate which you want make a move like Q 7 for user 1"<<endl;
		cin>>charcoordinate1>>coordinate1;
		if(coordinate1<=size && coordinate1>0) control=true;
		else{cout<<"invalid input try again!"<<endl;}
		charcoordinate1-=17;
		charcoordinate_temp1=charcoordinate1-'0';
		coordinate1--;
		if(board_size[coordinate1][charcoordinate_temp1]=='*'){
			board_size[coordinate1][charcoordinate_temp1]='x';
			control1=true;
		}
		else{
			cout<<"this place is not empty.Try again!"<<endl;
		}
	}
	*lastp_x=coordinate1;//we keep last point because computer make move by looking this point
	*lastp_y=charcoordinate_temp1;
}