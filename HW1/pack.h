#ifndef PACK_H_
#define PACK_H_
int is_valid();//This function is controlling the size of board is valid or not 
			   //if size iz valid funcion return if not user will enter new size 

void iterate_func(char board_size[12][12],int size);//This function attend '*' char to a board_size arrey 
													//The aim is to control arrey easily 
	
void iterate_func1(char temp_arrey[12][12],int size);//This function attend '*' char to a temp_arrey 
													//The aim is to control temp_arrey easily and to be able to control moving of x and o in control fuctions
													//We save the last our point to this arrey preventing going back and not entering the infinite loop

void iterate_func2(char bridge[20][20],int size);//This function attend '*' char to a bridge arrey 
												//To control the bridge situations 
void print_function(char board_size[12][12],int size);//This function is printing the current board_size arrey to see current situation


void play_user2(char board_size[12][12],int size);//This function control the ending situation and make move for both of user1 and user2
void move_inboard_user1(char board_size[12][12],int size);//This function control the moving of user 1 is valid or not if moving is valid we save it to the boardsize arrey
void move_inboard_user2(char board_size[12][12],int size);//This function control the moving of user 2 is valid or not if moving is valid we save it to the boardsize arrey
bool end_game_user1(char board_size[12][12],int size);//In this function we are controlling the game is end or not for user 1
													  //if last point is filled the control moves x function return true and up_words_x function will up x words
													  //but the x words have to connected each other 

bool end_game_user2(char board_size[12][12],int size);//In this function we are controlling the game is end or not for user 2
													  //if last point is filled the control moves o function return true and up_words_o function will up o words
													  //but the o words have to connected each other 

bool control_moves_x(char board_size[12][12],int size,int tempi,int tempj,char temp_arrey[12][12],int *lastp_x,int *lastp_y);
													  //In this function we start the first point and we check all directions if there is a 'x' we will recursive that point
													  //This situation is to be continued all horizontal points are filled and return last point to call up_words funcion
													  //of course this points have to be connected to each other

bool control_moves_o(char board_size[12][12],int size,int tempi,int tempj,char temp_arrey[12][12],int *lastp_x,int *lastp_y);
													  //In this function we start the first point and we check all directions if there is a 'o' we will recursive that point
													  //This situation is to be continued all vertical points are filled and return last point to call up_words funcion
													  //of course this points have to be connected to each other

void up_words_x(char board_size[12][12],int size,int lastp_x,int lastp_y);
													  //in this function we are starting the last point of board_size of x words
													  //we check all connected points and we recursive function that points by one by
													  //All connected words is up the function will end 

void up_words_o(char board_size[12][12],int size,int lastp_x,int lastp_y);
													   //in this function we are starting the last point of board_size of o words
													  //we check all connected points and we recursive function that points by one by
													  //All connected words is up the function will end 

void play_computer(char board_size[12][12],int size);
													  //This function control the ending situation and make move for both of user1 and computer

bool end_game_computer(char board_size[12][12],int size);
													  //In this function we are controlling the game is end or not for computer
													  //if last point is filled the control moves o function return true and up_words_o function will up o words
													  //but the o words have to connected each other 

void move_inboard_computer(char board_size[12][12],int size,int lastp_x,int lastp_y,int counter,char bridge[20][20]);
													  //This function control the moving of computer is valid or not if moving is valid we save it to the boardsize arrey
													  //and we make bridge in this function
													  //computer game is working with 7*7 size and 11*11 size because of the making bridge

void move_inboard_user(char board_size[12][12],int size,int *lastp_x,int *lastp_y);
													  //In this function we control the moving is valid for user or not
													  //and we return this function because computer moves by looking this point

bool make_bridge(char board_size[12][12],int size,int lastp_x,int lastp_y,char bridge[20][20],int computerp_x,int computerp_y);
													  //In thıs function computer make bridge if user moves computer check it and make bridge by looking this point 

void bridge_protect(char board_size[12][12],int size,int lastp_x,int lastp_y,char bridge[20][20]);
													  //This function protect the bridge points if user moves between bridges points one computer will fill the other point

void fill_blanks(char board_size[12][12],int size,int lastp_x,int lastp_y,char bridge[20][20]);
													  //Lastly we fill the between bridge points and the game end
#endif