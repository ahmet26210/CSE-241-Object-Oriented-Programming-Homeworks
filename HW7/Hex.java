public interface Hex{
	public void start_gui();
	public void iterate_func1();
	public void reset_game();
	public void save_file();
	public void load_file();
	public void undo_game();
	public void up_words_o();
	public void up_words_x();
	public boolean control_moves_o();
	public boolean control_moves_x();
	public void play(int number1,int number2);
	public void is_valid();
	public boolean end_game_computer();
	public boolean end_game_User1();
	public boolean end_game_User2();
	public void print_function();
	public Cell play();
}
