#include"pack.h"
int main()
{
	bool control=false;
	int lastfullcell=0;
	HEX h1(11),h4(8),h5(14);//CREAT OBJECT
	control=false;
	//HEX h6=11;
	lastfullcell=0;//LAST FILLED CELL OF ALL GAME
	h1.playGame();//START GAME
	h1.findMarked();//FIND HOW MANY   CELL HAS FILLED
	h1.setfullcell(h1.getCount());//FILLED CELL OF THIS GAME
	h1.setCount(0);//TO MAKE STATIC MEMBER ZERO FOR THE OTHER GAME STARTING WITH ZERO FILLED CELL TO CALCULATED TRUE 
	cout<<"---------------	NEXT GAME ------------------"<<endl;
	HEX h2(h1);//Copy Constructer
	h2.playGame();
	h2.findMarked();
	h2.setfullcell(h2.getCount());
	h2.setCount(0);
	cout<<"--------------	NEXT GAME -------------------"<<endl;
	control=h1==h2;//COMPARE TWO GAME AND IF FİRST GAME HAS FILLED CELL MORE THEN SECOND GAME IT RETURNS TRUE OTHERWISE IT RETURNS FALSE
	if(control==false){
		cout<<"h2 has more marked cell only user "<<endl;
	}
	else if(control==true){
		cout<<"h1 has more marked cell only user "<<endl;
	}
	control=false;
	HEX h3(11);
	h3=h1;//assignment operator
	h3.playGame();
	h3.findMarked();
	h3.setfullcell(h3.getCount());
	h3.setCount(0);
	cout<<"---------------- NEXT GAME --------------"<<endl;
	h4.playGame();
	h4.findMarked();
	h4.setfullcell(h4.getCount());
	control=h3==h4;//== OPERATOR 
	h4.setCount(0);
	if(control==true){
		cout<<"h3 has more marked cell only user "<<endl;
	}
	else if(control==false){
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