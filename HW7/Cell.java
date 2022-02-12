
public class Cell//INNER CLASS
	{
		private char charcell;//WHİCH ENUM HAS THIS CELL
		private int column;
		private int row;
		public Cell(){
			setcell('*');
		}//UCTER
		public int getColumn() 						{return column;}
		public int  getRow() 						{return row;}
		public char getCell() 						{return charcell;}
		public void setcell(char _charcell) 		{charcell=_charcell;}//ENUM
		public void setRow(int _row) 				{row=_row;}//ENUM
		public void setColumn(int _column) 			{column=_column;}//ENUM
	};