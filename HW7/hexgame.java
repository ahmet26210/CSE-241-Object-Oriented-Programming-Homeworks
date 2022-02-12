import java.util.Scanner;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.FileWriter;
import java.io.File;
import java.io.IOException;
public class hexgame implements ActionListener,Hex,Cloneable
{
	private String file_name;
	private char control,control1;
	private int lastp_x,lastp_y;
	private int lastpoint;
	private int tempi,tempj;
	private int counter;
	private char currentPlayer;
	private int counter1;
	private boolean endgame;
	private int fullcell;//RETURN FILLED CELL SAVED MARKEDCOUNT
	private int Score;
	private int count;
	private Cell[][] temp_arrey;//2D dynamic array
	private Cell[][] hexcells;//2D dynamic array
	private int size;//SIZE OF THE GAME
	private void setSize(int _size)				{size=_size;}
	private void setControl(char _control)		{control=_control;}
	private void setControl1(char _control1)	{control1=_control1;}
	private void setFilename(String _file_name){file_name=_file_name;}
	private void setLastp_x(int _lastp_x)		{lastp_x=_lastp_x;}
	private void setLastp_y(int _lastp_y)		{lastp_y=_lastp_y;}
	private void setTempi(int _tempi)			{tempi=_tempi;}
	private void setTempj(int _tempj)			{tempj=_tempj;}
	private void setCounter(int _counter)		{counter=_counter;}
	private void setCounter1(int _counter1)		{counter1=_counter1;}
	private void setCurrentPlayer(char _currentPLayer)	{currentPlayer=_currentPLayer;}
	private int[][] moves;

	public hexgame(int _size){
		control=' ';control1=' ';
		lastp_x=0;lastp_y=0;
		tempi=0;tempj=0;
		counter=0;
		currentPlayer=' ';
		counter1=0;
		fullcell=0;
		lastpoint=0;
		endgame=false;
		Score=0;
		count=0;
		setSize(_size);
		start_gui();
	} 
	public hexgame(){
		control=' ';control1=' ';
		lastp_x=0;lastp_y=0;
		tempi=0;tempj=0;
		counter=0;
		currentPlayer=' ';
		counter1=0;
		fullcell=0;
		lastpoint=0;
		endgame=false;
		Score=0;
		count=0;
		size=15;
		start_gui();
	}
	private JFrame f1,f2,f3;  
	private JButton btn;
	private JButton button1,button2,button3,button4,button5;
	private JFrame f;
	private JRadioButton r1;
	private JRadioButton r2;
	private JButton[][] buttons;
	private JTextField t1;
	public void start_gui(){
		boolean control=false;
		String size5;
		int size1;
		f2=new JFrame("Enter File Name");
		f2.setSize(500,500);
		t1=new JTextField();
		t1.setBounds(100,100,100,100);
		button5=new JButton("OKEY");
		button5.setBounds(300,300,100,100);
		f2.add(t1);
		f2.add(button5);
		f2.setLayout(null);
		f2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f2.setVisible(false);
		f=new JFrame("Welcome to Hexgame :)");
		size5=JOptionPane.showInputDialog("Enter Number of size");
		size1=Integer.parseInt(size5);
		setSize(size1);
		JOptionPane.showMessageDialog(null,"The size is "+ size1," ",JOptionPane.PLAIN_MESSAGE);
		hexcells=new Cell[getSize()][getSize()];
		for (int i=0;i<getSize();i++){
			for (int j=0;j<getSize();j++){
				hexcells[i][j]=new Cell();
			}
		}
		temp_arrey=new Cell[getSize()][getSize()];
		for (int i=0;i<getSize();i++){
			for (int j=0;j<getSize();j++){
				temp_arrey[i][j]=new Cell();
			}
		}
		iterate_func1();
		moves=new int[getSize()][2];
		f1=new JFrame();
		btn=new JButton("OKEY");      
		r1=new JRadioButton("UservsUser");    
		r2=new JRadioButton("ComputervsUser");    
		r1.setBounds(75,50,100,30);    
		r2.setBounds(75,100,100,30);
		btn.setBounds(75,150,100,30);    
		ButtonGroup bg=new ButtonGroup();    
		bg.add(r1);bg.add(r2);    
		f1.add(r1);f1.add(r2);
		f1.add(btn);      
		f1.setSize(300,300);    
		f1.setLayout(new GridLayout(3,1));    
		f1.setVisible(true);    
		btn.addActionListener(this);

		button1=new JButton("LOAD");
		button1.setText("LOAD");
		button2=new JButton("SAVE");
		button2.setText("SAVE");
		button3=new JButton("RESET");
		button3.setText("RESET");
		button4=new JButton("UNDO");
		button4.setText("UNDO");
		button1.setBounds(420,25,100,70);
		button2.setBounds(520,25,100,70);
		button3.setBounds(620,25,100,70);
		button4.setBounds(720,25,100,70);
		f.add(button1);
		f.add(button2);
		f.add(button3);
		f.add(button4);
		button1.addActionListener(this);
		button2.addActionListener(this);
		button3.addActionListener(this);
		button4.addActionListener(this);
		f.setSize(500,500);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		buttons=new JButton[getSize()][getSize()];
		int temp,width=100,length=100;
		f.setLayout(null);
		for (int i=0;i<getSize();i++){
			temp=width;
			for (int j=0;j<getSize();j++){
				JButton b=new JButton();
				b.setBounds(width,length,50,50);
				b.setText("*");
				b.setBackground(Color.WHITE);
				f.add(b);
				b.addActionListener(this);
				buttons[i][j]=b;
				width+=50;
			}
			length+=50;
			width=temp+25;
		}
		//f.setVisible(true);
	}
	public void iterate_func1(){
		int i,j;
		for(i=0;i<getSize();i++){
			for(j=0;j<getSize();j++){
				temp_arrey[i][j].setcell('*');//TO CONTROL IN CHECK FUNCTION NOT GO BACK WAS FILLED  BEFORE
			}
		}
	}//FOR TEMP_ARREY VECTOR
	private int getSize()					{return size;}//THIS RETURNS THE SIZE OF BOARD
	private char getControl()				{return control;}
	private char getControl1()				{return control1;}
	private String getFilename()				{return file_name;}
	private int getLastp_x()					{return lastp_x;}//FOR CONTROLLİNG THE COMPUTER MOVE AND CHECK END GAME FUNCTİON
	private int getLastp_y()					{return lastp_y;}//FOR CONTROLLİNG THE COMPUTER MOVE AND CHECK END GAME FUNCTİON
	private int getlastpoint()				{return lastpoint;}//FOR CONTROLLİNG THE COMPUTER MOVE AND CHECK END GAME FUNCTİON
	private int getTempi()					{return tempi;}//I FIND FİRST X OR FİRST O ON BOARD TO CHECK END GAME FUNCTİON
	private int getTempj()					{return tempj;}
	private int getCounter()					{return counter;}//TO CONTROL COMPUTER GAME WHİCH MOVE IT WILL MAKE
	private int getfullcell()				{return fullcell;}//WE SAVE THE FİLLED CELL OF ALL GAME
	private void setfullcell(int _fullcell)	{fullcell=_fullcell;}
	private boolean getEndgame()				{return endgame;}		
	private int getCounter1()				{return counter1;}
	private char getCurrentPlayer()			{return currentPlayer;}//WE GET THE CURRENT PLAYER TO CHECK PLAY FUNCTİON WHİCH ONE MAKE MOVE
	private int getCountUser()				{return count;}
	private int getScore()					{return Score;}
	private boolean check=false;
	private boolean check1=false;
	public void actionPerformed(ActionEvent e){
		boolean end_game1=false,end_game2=false;
		if(e.getSource()==btn){
			if(r1.isSelected()){
				setControl1('u');
			}
			else{
				setControl1('c');
			}
			f1.setVisible(false);
			f.setVisible(true);
		}
		else if(e.getSource()==button1){
			String size3=JOptionPane.showInputDialog("Enter Fılename");
			setFilename(size3);
			f.dispose();
			f=new JFrame("Welcome to Hexgame :)");
			f.add(button1);
			f.add(button2);
			f.add(button3);
			f.add(button4);
			button1.addActionListener(this);
			button2.addActionListener(this);
			button3.addActionListener(this);
			button4.addActionListener(this);
			f.setSize(500,500);
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			buttons=new JButton[getSize()][getSize()];
			int temp,width=100,length=100;
			f.setLayout(null);
			for (int i=0;i<getSize();i++){
				temp=width;
				for (int j=0;j<getSize();j++){
				JButton b=new JButton();
				b.setBounds(width,length,50,50);
				b.setText("*");
				b.setBackground(Color.WHITE);
				f.add(b);
				b.addActionListener(this);
				buttons[i][j]=b;
				width+=50;
			}
			length+=50;
			width=temp+25;
			}
			f.setVisible(true);
			load_file();
		}
		else if(e.getSource()==button2){
			String size3=JOptionPane.showInputDialog("Enter Fılename");
			setFilename(size3);
			save_file();
		}
		else if(e.getSource()==button3){
			reset_game();
		}
		else if(e.getSource()==button4){
			undo_game();
		}
		else{
			if(getControl1()=='u'){
				if(check==false){
					setCurrentPlayer('x');
					for (int i=0;i<getSize();i++) {
						for (int j=0;j<getSize();j++) {
							if(e.getSource()==buttons[i][j]){
								play(i,j);
								buttons[i][j].setText("x");
								buttons[i][j].setBackground(Color.GREEN);
							}
						}
					}
					end_game1=end_game_User1();
					if(end_game1==true){
						String size3=JOptionPane.showInputDialog("Game Was ended winner is turned on RED GoodBy");
						setFilename(size3); 
						f.setVisible(false);
						System.exit(0);
					}
					check=true;
					check1=false;
				}
				else if(check1==false){
					setCurrentPlayer('o');
					for (int i=0;i<getSize();i++) {
						for (int j=0;j<getSize();j++) {
							if(e.getSource()==buttons[i][j]){
								play(i,j);
								buttons[i][j].setText("o");
								buttons[i][j].setBackground(Color.BLUE);
							}
						}
					}
					end_game2=end_game_User2();
					if(end_game2==true){
						String size3=JOptionPane.showInputDialog("Game Was ended winner is turned on RED GoodBy");
						setFilename(size3); 
						f.setVisible(false);
						System.exit(0);
					}
					check1=true;
					check=false;
				}
			}
			else if(getControl1()=='c'){
				for (int i=0;i<getSize();i++) {
					for (int j=0;j<getSize();j++) {
						if(e.getSource()==buttons[i][j]){
							setCurrentPlayer('x');
							play(j,i);
							setLastp_x(j);
							setLastp_y(i);
							buttons[i][j].setText("x");
							buttons[i][j].setBackground(Color.GREEN);
						}
					}
					end_game1=end_game_User1();
					if(end_game1==true){
						String size3=JOptionPane.showInputDialog("Game Was ended winner is turned on RED GoodBy");
						setFilename(size3); 
						f.setVisible(false);
						System.exit(0);
					}
				}
				Cell a=play();
				setCounter(1);
				buttons[a.getRow()][a.getColumn()].setText("o");
				buttons[a.getRow()][a.getColumn()].setBackground(Color.BLUE);
				end_game2=end_game_User2();
				if(end_game2==true){ 
					//f.setVisible(false);
				}
			}
		}
	}
	public void reset_game(){
		lastp_x=0;lastp_y=0;
		tempi=0;tempj=0;
		counter=0;
		currentPlayer='x';
		counter1=0;
		fullcell=0;
		lastpoint=0;
		Score=0;
		count=0;
		for (int i = 0; i < getlastpoint(); i++)
		{
				moves[i][0]=0;
				moves[i][1]=0;
		}
		for (int i = 0; i < getSize(); ++i)
		{
			for (int j = 0; j < getSize(); ++j)
			{
				hexcells[i][j].setcell('*');
				buttons[i][j].setText("*");
				buttons[i][j].setBackground(Color.WHITE);
			}
		}
		for (int i = 0; i < getSize(); ++i)
		{
			for (int j = 0; j < getSize(); ++j)
			{
				temp_arrey[i][j].setcell('*');
			}
		}
	}
	public void save_file(){
		int i,j;
		try{
			FileWriter save_load_file=new FileWriter(getFilename());
			save_load_file.write(getSize()+"\n");
			for(i=0;i<getSize();i++){
				for (j=0;j<getSize();j++) {
					save_load_file.write(hexcells[i][j].getCell()+"\n");
				}
				save_load_file.write("\n");
			}
			if(getControl()=='u'){
				save_load_file.write("USERVSUSER\n");
			}
			else if(getControl()=='c'){
				save_load_file.write("USERVSCOMPUTER\n");
			}
			save_load_file.write(getCurrentPlayer()+"\n");
			save_load_file.write("---------------MOVES----------------\n");
			save_load_file.write(lastpoint+"\n");
			for (int k = 0; k < getlastpoint(); ++k)
			{
				save_load_file.write("(");
				save_load_file.write(moves[k][0]+"");
				save_load_file.write(",");
				save_load_file.write(moves[k][1]+"");
				save_load_file.write(")");
				save_load_file.write("\n");
			}
			save_load_file.close();
		}
		catch(IOException e){
			System.out.println("An error Occured");
		}
	}
	public void load_file(){
		Scanner myReader=null;
		try{
			myReader=new Scanner(new File(getFilename()));
		}
		catch(Exception e){
			System.out.println("could not find file");
		}
		char data=' ';
		char free;
		int control=0,control1=0,lastp;
		int num1,num2;
		int i=0,j=0;
		int size2;
		char currentplayer=' ';
		int lastpoint;
		String line,str=" ",size1; 
			while(myReader.hasNext()){//to reach end of file
				if(control1==0){
					size1=myReader.nextLine();
					size2=Integer.parseInt(size1);
					setSize(size2);
					hexcells=new Cell[getSize()][getSize()];
					for (int k=0;k<getSize();k++){
						for (int l=0;l<getSize();l++){
							hexcells[k][l]=new Cell();
						}
					}
					temp_arrey=new Cell[getSize()][getSize()];
					for (int k=0;k<getSize();k++){
						for (int l=0;l<getSize();l++){
							temp_arrey[i][j]=new Cell();
						}
					}
					control1++;
				}
				line=myReader.nextLine();//we are reading the data from file
				//for(int k=0;k<getSize();k++){
					data=line.charAt(0);
					hexcells[i][j].setcell(data);//then we send board size
					buttons[i][j].setText(String.valueOf(data));
				//}
				//i=i+getSize();	
				if(data=='x'){
					buttons[i][j].setBackground(Color.GREEN);
				}
				else if(data=='o'){
					buttons[i][j].setBackground(Color.BLUE);
				}
				if(j==getSize()-1 && i==getSize()-1){ //if we reach end of board size file will end
					int[][] moves=new int[getSize()][2];
					line=myReader.nextLine();
					str=myReader.nextLine();
					line=myReader.nextLine();
					currentplayer=str.charAt(0);
					line=myReader.nextLine();
					//line=myReader.nextLine();
					line=myReader.nextLine();
					lastp=Integer.parseInt(line);
					lastpoint=lastp;
					for (int m = 0; m < lastpoint; ++m)
					{
						line=myReader.nextLine();
						num1=line.charAt(1);
						num2=line.charAt(3);
						moves[m][0]=num1;
						moves[m][1]=num2;
					}
					break;
				}
				else if(j==getSize()-1){
					line=myReader.nextLine();
					i++;
					j=0;
				}
				else{
					j++;
				}
			}
			control=1;
			if(str.equals("USERVSUSER")){
				setControl1('u');
				setCurrentPlayer(currentplayer);
			}
			else if(str.equals("USERVSCOMPUTER")){
				setControl1('c');
			}
		myReader.close();
	}
	public void undo_game(){
		hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell('*');
		buttons[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setText("*");
		buttons[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setBackground(Color.WHITE);
		lastpoint--;
		hexcells[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setcell('*');
		buttons[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setText("*");
		buttons[moves[lastpoint-1][0]][moves[lastpoint-1][1]].setBackground(Color.WHITE);
		lastpoint--;
	}
	public void up_words_o(){
		if(getLastp_x()!=0){
			if(hexcells[getLastp_x()-1][getLastp_y()].getCell()=='o'){//kuzey
				if(hexcells[getLastp_x()-1][getLastp_y()].getCell()!='O'){//to avoid the going back and to avoid infinite loop
					hexcells[getLastp_x()-1][getLastp_y()].setcell('O');//up all connected words
					buttons[getLastp_x()-1][getLastp_y()].setText("O");
					buttons[getLastp_x()-1][getLastp_y()].setBackground(Color.RED);
					setLastp_x(getLastp_x()-1);
					up_words_o();//recursive to around existing x values
				}												//this function will end if the all connected x values are up
			}
		}
		if(getLastp_x()!=0 && getLastp_y()!=size-1){
			if(hexcells[getLastp_x()-1][getLastp_y()+1].getCell()=='o'){//kuzeydoğu
				if(hexcells[getLastp_x()-1][getLastp_y()+1].getCell()!='O'){
					hexcells[getLastp_x()-1][getLastp_y()+1].setcell('O');
					buttons[getLastp_x()-1][getLastp_y()+1].setText("O");
					buttons[getLastp_x()-1][getLastp_y()+1].setBackground(Color.RED);
					setLastp_x(getLastp_x()-1);
					setLastp_y(getLastp_y()+1);
					up_words_o();
				}
			}
		}
		if(getLastp_y()!=0){
			if(hexcells[getLastp_x()][getLastp_y()-1].getCell()=='o'){//batı
				if(hexcells[getLastp_x()][getLastp_y()-1].getCell()!='O'){
					hexcells[getLastp_x()][getLastp_y()-1].setcell('O');
					buttons[getLastp_x()][getLastp_y()-1].setText("O");
					buttons[getLastp_x()][getLastp_y()-1].setBackground(Color.RED);
					setLastp_y(getLastp_y()-1);
					up_words_o();
				}
			}
		}
		if(getLastp_y()!=size-1){
			if(hexcells[getLastp_x()][getLastp_y()+1].getCell()=='o'){//doğu
				if(hexcells[getLastp_x()][getLastp_y()+1].getCell()!='O'){
					hexcells[getLastp_x()][getLastp_y()+1].setcell('O');
					buttons[getLastp_x()][getLastp_y()+1].setText("O");
					buttons[getLastp_x()][getLastp_y()+1].setBackground(Color.RED);
					setLastp_y(getLastp_y()+1);
					up_words_o();
				}
			}
		}
		if(getLastp_x()!=size){
			if(hexcells[getLastp_x()+1][getLastp_y()].getCell()=='o'){//güney
				if(hexcells[getLastp_x()+1][getLastp_y()].getCell()!='O'){
					hexcells[getLastp_x()+1][getLastp_y()].setcell('O');
					buttons[getLastp_x()+1][getLastp_y()].setText("O");
					buttons[getLastp_x()+1][getLastp_y()].setBackground(Color.RED);
					setLastp_x(getLastp_x()+1);
					up_words_o();
				}
			}
		}
		if(getLastp_x()!=size && getLastp_y()!=0){
			if(hexcells[getLastp_x()+1][getLastp_y()-1].getCell()=='o'){//güneybatı
				if(hexcells[getLastp_x()+1][getLastp_y()-1].getCell()!='O'){
					hexcells[getLastp_x()+1][getLastp_y()-1].setcell('O');
					buttons[getLastp_x()+1][getLastp_y()-1].setText("O");
					buttons[getLastp_x()+1][getLastp_y()-1].setBackground(Color.RED);
					setLastp_x(getLastp_x()+1);
					setLastp_y(getLastp_y()-1);
					up_words_o();
				}
			}
		}
		if(getLastp_x()!=0 && getLastp_y()!=0){
			if(hexcells[getLastp_x()-1][getLastp_y()-1].getCell()=='o'){//kuzeybatı
				if(hexcells[getLastp_x()-1][getLastp_y()-1].getCell()!='O'){
					hexcells[getLastp_x()-1][getLastp_y()-1].setcell('O');
					buttons[getLastp_x()-1][getLastp_y()-1].setText("O");
					buttons[getLastp_x()-1][getLastp_y()-1].setBackground(Color.RED);
					setLastp_x(getLastp_x()-1);
					setLastp_y(getLastp_y()-1);
					up_words_o();
				}
			}
		}
		if(getLastp_x()!=size && getLastp_y()!=size-1){
			if(hexcells[getLastp_x()+1][getLastp_y()+1].getCell()=='o'){//güneydoğu
				if(hexcells[getLastp_x()+1][getLastp_y()+1].getCell()!='O'){
					hexcells[getLastp_x()+1][getLastp_y()+1].setcell('O');
					buttons[getLastp_x()+1][getLastp_y()+1].setText("O");
					buttons[getLastp_x()+1][getLastp_y()+1].setBackground(Color.RED);
					setLastp_x(getLastp_x()+1);
					setLastp_y(getLastp_y()+1);
					up_words_o();
				}
			}
		}
	}
	public void up_words_x(){
		if(getLastp_x()!=0){
			if(hexcells[getLastp_x()-1][getLastp_y()].getCell()=='x'){//kuzey
				if(hexcells[getLastp_x()-1][getLastp_y()].getCell()!='X'){//to avoid the going back and to avoid infinite loop
					hexcells[getLastp_x()-1][getLastp_y()].setcell('X');//up all connected words
					buttons[getLastp_x()-1][getLastp_y()].setText("X");
					buttons[getLastp_x()-1][getLastp_y()].setBackground(Color.RED);
					setLastp_x(getLastp_x()-1);
					up_words_x();//recursive to around existing x values
				}												//this function will end if the all connected x values are up
			}
		}
		if(getLastp_x()!=0 && getLastp_y()!=size-1){
			if(hexcells[getLastp_x()-1][getLastp_y()+1].getCell()=='x'){//kuzeydoğu
				if(hexcells[getLastp_x()-1][getLastp_y()+1].getCell()!='X'){
					hexcells[getLastp_x()-1][getLastp_y()+1].setcell('X');
					buttons[getLastp_x()-1][getLastp_y()+1].setText("X");
					buttons[getLastp_x()-1][getLastp_y()+1].setBackground(Color.RED);
					setLastp_x(getLastp_x()-1);
					setLastp_y(getLastp_y()+1);
					up_words_x();
				}
			}
		}
		if(getLastp_y()!=0){
			if(hexcells[getLastp_x()][getLastp_y()-1].getCell()=='x'){//batı
				if(hexcells[getLastp_x()][getLastp_y()-1].getCell()!='X'){
					hexcells[getLastp_x()][getLastp_y()-1].setcell('X');
					buttons[getLastp_x()][getLastp_y()-1].setText("X");
					buttons[getLastp_x()][getLastp_y()-1].setBackground(Color.RED);
					setLastp_y(getLastp_y()-1);
					up_words_x();
				}
			}
		}
		if(getLastp_y()!=size-1){
			if(hexcells[getLastp_x()][getLastp_y()+1].getCell()=='x'){//doğu
				if(hexcells[getLastp_x()][getLastp_y()+1].getCell()!='X'){
					hexcells[getLastp_x()][getLastp_y()+1].setcell('X');
					buttons[getLastp_x()][getLastp_y()+1].setText("X");
					buttons[getLastp_x()][getLastp_y()+1].setBackground(Color.RED);
					setLastp_y(getLastp_y()+1);
					up_words_x();
				}
			}
		}
		if(getLastp_x()!=size-1){
			if(hexcells[getLastp_x()+1][getLastp_y()].getCell()=='x'){//güney
				if(hexcells[getLastp_x()+1][getLastp_y()].getCell()!='X'){
					hexcells[getLastp_x()+1][getLastp_y()].setcell('X');
					buttons[getLastp_x()+1][getLastp_y()].setText("X");
					buttons[getLastp_x()+1][getLastp_y()].setBackground(Color.RED);
					setLastp_x(getLastp_x()+1);
					up_words_x();
				}
			}
		}
		if(getLastp_x()!=size-1 && getLastp_y()!=0){
			if(hexcells[getLastp_x()+1][getLastp_y()-1].getCell()=='x'){//güneybatı
				if(hexcells[getLastp_x()+1][getLastp_y()-1].getCell()!='X'){
					hexcells[getLastp_x()+1][getLastp_y()-1].setcell('X');
					buttons[getLastp_x()+1][getLastp_y()-1].setText("X");
					buttons[getLastp_x()+1][getLastp_y()-1].setBackground(Color.RED);
					setLastp_x(getLastp_x()+1);
					setLastp_y(getLastp_y()-1);
					up_words_x();
				}
			}
		}
		if(getLastp_x()!=0 && getLastp_y()!=0){
			if(hexcells[getLastp_x()-1][getLastp_y()-1].getCell()=='x'){//kuzeybatı
				if(hexcells[getLastp_x()-1][getLastp_y()-1].getCell()!='X'){
					hexcells[getLastp_x()-1][getLastp_y()-1].setcell('X');
					buttons[getLastp_x()-1][getLastp_y()-1].setText("X");
					buttons[getLastp_x()-1][getLastp_y()-1].setBackground(Color.RED);
					setLastp_x(getLastp_x()-1);
					setLastp_y(getLastp_y()-1);
					up_words_x();
				}
			}
		}
		if(getLastp_x()!=size-1 && getLastp_y()!=size-1){
			if(hexcells[getLastp_x()+1][getLastp_y()+1].getCell()=='x'){//güneydoğu
				if(hexcells[getLastp_x()+1][getLastp_y()+1].getCell()!='X'){
					hexcells[getLastp_x()+1][getLastp_y()+1].setcell('X');
					buttons[getLastp_x()+1][getLastp_y()+1].setText("X");
					buttons[getLastp_x()+1][getLastp_y()+1].setBackground(Color.RED);
					setLastp_x(getLastp_x()+1);
					setLastp_y(getLastp_y()+1);
					up_words_x();
				}
			}
		}
	} //in this function we are starting the last point of board_size of x words
						//we check all connected points and we recursive function that points by one by
					   //All connected words is up the function will end 
	public boolean control_moves_o(){
		if(getTempi()+1==size){
			setLastp_x(getTempi()+1);//we keep the last O point to end game
			setLastp_y(getTempj());
			return true;
		}
		if(getTempi()!=0){
			if(hexcells[getTempi()-1][getTempj()].getCell()=='o'){//kuzey
				if(temp_arrey[getTempi()-1][getTempj()].getCell()!='o'){//to avoid of going back to and avoid infinite loop
					temp_arrey[getTempi()-1][getTempj()].setcell('o');
					setTempi(getTempi()-1);
					return control_moves_o(); //recursive to around existing x values
				}
			}
		}
		if(getTempi()!=size-1){
			if(hexcells[getTempi()+1][getTempj()].getCell()=='o'){//güney
				setTempi(getTempi()+1);
				return control_moves_o();
			}
		}
		if(getTempi()!=0 && getTempj()!=size-1){
			if(hexcells[getTempi()-1][getTempj()+1].getCell()=='o'){//kuzeydoğu
				if(temp_arrey[getTempi()-1][getTempj()+1].getCell()!='o'){
					temp_arrey[getTempi()-1][getTempj()+1].setcell('o');
					setTempi(getTempi()-1);
					setTempj(getTempj()+1);
					return control_moves_o();
				}
			}
		}
		if(getTempj()!=size-1){
			if(hexcells[getTempi()][getTempj()+1].getCell()=='o'){//doğu
				if(temp_arrey[getTempi()][getTempj()+1].getCell()!='o'){
					temp_arrey[getTempi()][getTempj()+1].setcell('o');
					setTempj(getTempj()+1);
					return control_moves_o();
				}
			}
		}
		if(getTempj()!=0){
			if(hexcells[getTempi()][getTempj()-1].getCell()=='o'){//batı
				if(temp_arrey[getTempi()][getTempj()-1].getCell()!='o'){
					temp_arrey[getTempi()][getTempj()-1].setcell('o');
					setTempj(getTempj()-1);
					return control_moves_o();
				}
			}
		}
		if(getTempi()!=size-1 && getTempj()!=0){
			if(hexcells[getTempi()+1][getTempj()-1].getCell()=='o'){//güneybatı
				if(temp_arrey[getTempi()+1][getTempj()-1].getCell()!='o'){
					temp_arrey[getTempi()+1][getTempj()-1].setcell('o');
					setTempi(getTempi()+1);
					setTempj(getTempj()-1);
					return control_moves_o();
				}
			}
		}
		return false;
	}
	public boolean control_moves_x(){
		if(getTempj()+1==size){
			setLastp_x(getTempi()+1);//we keep the last x point to end game
			setLastp_y(getTempj()+1);
			return true;
		}
		if(getTempi()!=0){
			if(hexcells[getTempi()-1][getTempj()].getCell()=='x'){//kuzey
				if(temp_arrey[getTempi()-1][getTempj()].getCell()!='x'){//to avoid of going back to and avoid infinite loop
					temp_arrey[getTempi()-1][getTempj()].setcell('x');
					setTempi(getTempi()-1);
					return control_moves_x(); //recursive to around existing x values
				}
			}
		}
		if(getTempi()!=size-1){
			if(hexcells[getTempi()+1][getTempj()].getCell()=='x'){//güney
				if(temp_arrey[getTempi()+1][getTempj()].getCell()!='x'){
					temp_arrey[getTempi()+1][getTempj()].setcell('x');
					setTempi(getTempi()+1);
					return control_moves_x();
				}
			}
		}
		if(getTempi()!=0 && getTempj()!=size-1){
			if(hexcells[getTempi()-1][getTempj()+1].getCell()=='x'){//kuzeydoğu
				if(temp_arrey[getTempi()-1][getTempj()+1].getCell()!='x'){
					temp_arrey[getTempi()-1][getTempj()+1].setcell('x');
					setTempi(getTempi()-1);
					setTempj(getTempj()+1);
					return control_moves_x();
				}
			}
		}
		if(getTempj()!=size-1){
			if(hexcells[getTempi()][getTempj()+1].getCell()=='x'){//doğu
				if(temp_arrey[getTempi()][getTempj()+1].getCell()!='x'){
					temp_arrey[getTempi()][getTempj()+1].setcell('x');
					setTempj(getTempj()+1);
					return control_moves_x();
				}
			}
		}
		if(getTempj()!=0){
			if(hexcells[getTempi()][getTempj()-1].getCell()=='x'){//batı
				if(temp_arrey[getTempi()][getTempj()-1].getCell()!='x'){
					temp_arrey[getTempi()][getTempj()-1].setcell('x');
					setTempj(getTempj()-1);
					return control_moves_x();
				}
			}
		}
		if(getTempi()!=size-1 && getTempj()!=0){
			if(hexcells[getTempi()+1][getTempj()-1].getCell()=='x'){//güneybatı
				if(temp_arrey[getTempi()+1][getTempj()-1].getCell()!='x'){
					temp_arrey[getTempi()+1][getTempj()-1].setcell('x');
					setTempi(getTempi()+1);
					setTempj(getTempj()-1);
					return control_moves_x();
				}
			}
		}
		return false;
	}
	public void play(int number1,int number2){
		if(getCurrentPlayer()=='x'){//'x'
			hexcells[number2][number1].setcell('x');
			moves[getlastpoint()][0]=number2;
			moves[getlastpoint()][1]=number1;
			lastpoint++;//counter for moves 
		}
		else if(getCurrentPlayer()=='o'){//'o'
			hexcells[number2][number1].setcell('o');
			moves[getlastpoint()][0]=number2;
			moves[getlastpoint()][1]=number1;
			lastpoint++;
		}
	}//This function make move for both of 'x' and 'o'
	public void is_valid(){
		boolean valid=false;
		while(valid==false){
			if(getSize()<6){
				System.out.println("Please enter the board size ,the size can be bigger than 5*5 ");
				setSize(size);
			}
			valid=true;
		}
	}
	public boolean end_game_computer(){
		int i=0,j=0;
		boolean control=false;
		boolean control1=false;
		for(j=0;j<getSize();j++){
			if(hexcells[i][j].getCell()=='o'){
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
	public boolean end_game_User1(){
		int i=0,j=0;
		boolean control=false;
		for(j=0;j<getSize();j++){
			if(hexcells[i][j].getCell()=='o'){//we find first point and starting the recursion with finding o words
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
	public boolean end_game_User2(){
		int i,j=0;
		boolean control=false;
		for(i=0;i<getSize();i++){
			if(hexcells[i][j].getCell()=='x'){//we find first point and starting the recursion with finding x words
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
	public void print_function(){
		for (int i=0;i<getSize();i++){
			for (int j=0;j<getSize();j++) {
				if(hexcells[i][j].getCell()=='x'){
					buttons[i][j].setText("x");
				}
				if(hexcells[i][j].getCell()=='o'){
					buttons[i][j].setText("o");
				}			
			}
		}
	}
	public Cell play(){
		int charcoordinate_temp2,coordinate2;
		char charcoordinate2;
		boolean control=false;
		int computerp_x=0;
		int computerp_y=0;
		int i;
		int j;
		int middle;
		Cell tempCell=new Cell();
		middle=(getSize()+1)/2-1;//we find the middle of board
		if(getCounter()==0){
			if(hexcells[middle][middle].getCell()=='x' || hexcells[middle][middle].getCell()=='o'){
				hexcells[middle][middle+1].setcell('o');
				computerp_x=middle+1;
				computerp_y=middle+1;
				moves[getlastpoint()][0]=middle;//WE SAVE THE MOVES
				moves[getlastpoint()][1]=middle+1;
				lastpoint++;
				tempCell.setcell('o');
				tempCell.setRow(middle);
				tempCell.setColumn(middle+1);
				return (tempCell);
			}
			else{
				hexcells[middle][middle].setcell('o');//computer attend the middle of board always please let it do :)
				computerp_x=middle;
				computerp_y=middle;
				moves[getlastpoint()][0]=middle;
				moves[getlastpoint()][1]=middle;
				lastpoint++;
				tempCell.setcell('o');
				tempCell.setRow(middle);
				tempCell.setColumn(middle);
				return (tempCell);
			}
		}
		if(getLastp_x()>middle && getCounter()>=1){	//LASTPX CHECK USER 1 POİNTS IF BIGGER THEN MIDDLE COMPUTER MAKE MOVE TO BOTTOM OTHERWISE MAKE MOVE TO TOP
			for(i=0;i<getSize();i++){
				for(j=0;j<getSize();j++){
					if(hexcells[i][j].getCell()=='o'){//we find last o point in board 
						computerp_x=i;
						computerp_y=j;
					}
				}
			}
			if(computerp_x!=getSize()-1){
				if(hexcells[computerp_x+1][computerp_y].getCell()=='x' && hexcells[computerp_x+1][computerp_y-1].getCell()!='x'){
					hexcells[computerp_x+1][computerp_y-1].setcell('o');
					moves[getlastpoint()][0]=computerp_x+1;
					moves[getlastpoint()][1]=computerp_y-1;
					lastpoint++;
					tempCell.setcell('o');
					tempCell.setRow(computerp_x+1);
					tempCell.setColumn(computerp_y-1);
					return (tempCell);
				}
				else if(hexcells[computerp_x+1][computerp_y].getCell()!='x'){
					hexcells[computerp_x+1][computerp_y].setcell('o');
					moves[getlastpoint()][0]=computerp_x+1;
					moves[getlastpoint()][1]=computerp_y;
					lastpoint++;
					tempCell.setcell('o');
					tempCell.setRow(computerp_x+1);
					tempCell.setColumn(computerp_y);
					return (tempCell);
				}
			}
			else if(computerp_x==getSize()-1){
				for(i=0;i<getSize();i++){
					for(j=0;j<getSize();j++){
						if(hexcells[i][j].getCell()=='o'){
							computerp_x=i;
							computerp_y=j;
							control=true;
							break;
						}
					}
					if(control==true) break;
				}
				if(hexcells[computerp_x-1][computerp_y].getCell()=='x' && hexcells[computerp_x-1][computerp_y+1].getCell()!='x'){
					hexcells[computerp_x-1][computerp_y+1].setcell('o');
					moves[getlastpoint()][0]=computerp_x-1;
					moves[getlastpoint()][1]=computerp_y+1;
					lastpoint++;
					tempCell.setcell('o');
					tempCell.setRow(computerp_x-1);
					tempCell.setColumn(computerp_y+1);
					return (tempCell);	
				}
				else if(hexcells[computerp_x-1][computerp_y].getCell()!='x'){
					hexcells[computerp_x-1][computerp_y].setcell('o');
					moves[getlastpoint()][0]=computerp_x-1;
					moves[getlastpoint()][1]=computerp_y;
					lastpoint++;
					tempCell.setcell('o');
					tempCell.setRow(computerp_x-1);
					tempCell.setColumn(computerp_y);
					return (tempCell);
				}
			}
		}
		else if(getLastp_x()<=middle && getCounter()>=1){
			for(i=0;i<getSize();i++){
				for(j=0;j<getSize();j++){
					if(hexcells[i][j].getCell()=='o'){
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
						if(hexcells[i][j].getCell()=='o'){
							computerp_x=i;
							computerp_y=j;
							control=true;
							break;
						}
					}
					if(control==true) break;
				}
				if(hexcells[computerp_x-1][computerp_y].getCell()=='x' && hexcells[computerp_x-1][computerp_y+1].getCell()!='x'){
					hexcells[computerp_x-1][computerp_y+1].setcell('o');
					moves[getlastpoint()][0]=computerp_x-1;
					moves[getlastpoint()][1]=computerp_y+1;
					lastpoint++;
					tempCell.setcell('o');
					tempCell.setRow(computerp_x-1);
					tempCell.setColumn(computerp_y+1);
					return (tempCell);
				}
				else if(hexcells[computerp_x-1][computerp_y].getCell()!='x') {
					hexcells[computerp_x-1][computerp_y].setcell('o');
					moves[getlastpoint()][0]=computerp_x-1;
					moves[getlastpoint()][1]=computerp_y;
					lastpoint++;
					tempCell.setcell('o');
					tempCell.setRow(computerp_x-1);
					tempCell.setColumn(computerp_y);
					return (tempCell);
				}
			}
			else if(computerp_x==0){
				for(i=0;i<getSize();i++){
					for(j=0;j<getSize();j++){
						if(hexcells[i][j].getCell()=='o'){//we find last o point in board 
							computerp_x=i;
							computerp_y=j;
						}
					}
				}
				if(hexcells[computerp_x+1][computerp_y].getCell()=='x' && hexcells[computerp_x+1][computerp_y-1].getCell()!='x'){
					hexcells[computerp_x+1][computerp_y-1].setcell('o');
					moves[getlastpoint()][0]=computerp_x+1;
					moves[getlastpoint()][1]=computerp_y-1;
					lastpoint++;
					tempCell.setcell('o');
					tempCell.setRow(computerp_x+1);
					tempCell.setColumn(computerp_y-1);
					return (tempCell);
				}
				else if(hexcells[computerp_x+1][computerp_y].getCell()!='x') {
					hexcells[computerp_x+1][computerp_y].setcell('o');
					moves[getlastpoint()][0]=computerp_x+1;
					moves[getlastpoint()][1]=computerp_y;
					lastpoint++;
					tempCell.setcell('o');
					tempCell.setRow(computerp_x+1);
					tempCell.setColumn(computerp_y);
					return (tempCell);
				}
			}
		}
		return (tempCell);
	}
}