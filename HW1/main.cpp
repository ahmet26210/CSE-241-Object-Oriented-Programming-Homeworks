#include "pack.h"
int main(){
	int size,choose=2;
	size=is_valid();
	char board_size[size][20];
	iterate_func(board_size,size);
	print_function(board_size,size);
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