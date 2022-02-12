public class main{
	public static void main(String[] args){
		boolean control;
		String check;
		HashSet<Integer> hashset_int=new HashSet<Integer>();
		ArrayList<Integer> arraylist_int=new ArrayList<Integer>();
		LinkedList<Integer> linkedlist_int=new LinkedList<Integer>();
		HashSet<String> hashset_string=new HashSet<String>();
		ArrayList<String> arraylist_string=new ArrayList<String>();
		LinkedList<String> linkedlist_string=new LinkedList<String>();
		iterator<Integer> begin_int=arraylist_int.iterator();
		iterator<String> begin_string=arraylist_string.iterator();
		hashset_int.add(3);
		hashset_int.add(5);
		hashset_int.add(7);
		hashset_int.add(3);
		hashset_int.add(5);
		hashset_int.add(11);
		arraylist_int.add(9);
		arraylist_int.add(11);
		arraylist_int.add(13);
		arraylist_int.add(12);
		arraylist_int.add(15);
		linkedlist_int.add(16);
		linkedlist_int.add(17);
		linkedlist_int.add(19);
		linkedlist_int.add(17);
		linkedlist_int.add(18);
		linkedlist_int.offer(32);
		linkedlist_int.offer(51);
		System.out.println("\nArrayList_int contains these elements");
		begin_int=arraylist_int.iterator();
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}
		control=arraylist_int.contains(11);
		if(control==true) System.out.println("\narraylist_int contains 11 ");
		arraylist_int.remove(11);
		control=arraylist_int.contains(11);
		if(control==true) System.out.println("\narraylist_int contains 11 ");

		begin_int=arraylist_int.iterator();
		System.out.println("\nArrayList_int contains these elements after removes");
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}

		System.out.println("\n----------------------------------------------------\n");

		System.out.println("\nHashSet_int contains these elements");
		begin_int=hashset_int.iterator();
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}
		hashset_int.adall(arraylist_int);

		System.out.println("\nHashSet_int contains these elements after add arraylist_int");
		begin_int=hashset_int.iterator();
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}
		control=hashset_int.containsAll(arraylist_int);
		if(control==true) System.out.println("\nhashset_int contains all arraylist_int elements ");
		hashset_int.add(18);
		hashset_int.add(19);
		begin_int=hashset_int.iterator();
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}
		hashset_int.retainAll(arraylist_int);
		System.out.println("\narraylist_int retained from hashset_int ");
		begin_int=hashset_int.iterator();
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}

		hashset_int.removeAll(hashset_int);
		hashset_int.clear();
		control=hashset_int.isEmpty();
		if(control==true) System.out.println("\nhashset_int is empty ");

		System.out.println("----------------------------------------------------\n");
		begin_int=linkedlist_int.iterator();
		System.out.println("\nlinkedlist_int contains these elements");
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}
		linkedlist_int.adall(arraylist_int);
		System.out.println("\nlinkedlist_int contains these elements after arraylist_int elements added");
		begin_int=linkedlist_int.iterator();
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}

		control=linkedlist_int.contains(19);
		if(control==true) System.out.println("\nlinkedlist_int contains 19 ");
		control=linkedlist_int.containsAll(arraylist_int);
		if(control==true) System.out.println("\nlinkedlist_int contains arraylist_int elements ");
		linkedlist_int.removeAll(arraylist_int);
		System.out.println("\nlinkedlist_int contains these elements after removeAll arraylist_int elements");
		begin_int=linkedlist_int.iterator();
		while(begin_int.hasNext()){
			System.out.printf("%s ",begin_int.next());
		}

		System.out.println("\n----------------------------------------------------\n");
		hashset_string.add("C++");
		hashset_string.add("JAVA");
		hashset_string.add("RUBY");
		arraylist_string.add("JAVASCRIPT");
		arraylist_string.add("CSS");
		arraylist_string.add("HTML");
		linkedlist_string.add("C");
		linkedlist_string.add("C#");
		linkedlist_string.add("PYTHON");
		System.out.println("\narraylist_string elements ");
		begin_string=arraylist_string.iterator();
		while(begin_string.hasNext()){
			System.out.printf("%s ",begin_string.next());
		}
		arraylist_string.adall(hashset_string);
		System.out.println("\narraylist_string contains these elements after add all hashset_string elements");
		begin_string=arraylist_string.iterator();
		while(begin_string.hasNext()){
			System.out.printf("%s ",begin_string.next());
		}
		control=arraylist_string.contains("CSS");
		if(control==true) System.out.println("\narraylist_string contains 'CSS' ");
		control=arraylist_string.containsAll(hashset_string);
		if(control==true) System.out.println("\narraylist_string contains all hashset_string elements ");
	
		arraylist_string.remove("CSS");
		System.out.println("\narraylist_string contains these elements after remove CSS element");

		begin_string=arraylist_string.iterator();
		while(begin_string.hasNext()){
			System.out.printf("%s ",begin_string.next());
		}

		System.out.println("\narraylist_string not contains 'CSS' ");
		arraylist_string.removeAll(hashset_string);
		begin_string=arraylist_string.iterator();
		System.out.println("\narraylist_string contains these elements after remove all hashset_string elements");
		while(begin_string.hasNext()){
			System.out.printf("%s ",begin_string.next());
		}
		arraylist_string.clear();
		control=arraylist_string.isEmpty();
		if(control==true) System.out.println("\narraylist_string is empty ");
		System.out.println("\n----------------------------------------------------\n");
		System.out.println("\nhashset_string elements' ");
		begin_string=hashset_string.iterator();
		while(begin_string.hasNext()){
			System.out.printf("%s ",begin_string.next());
		}
		control=hashset_string.contains("JAVA");
		if(control==true) System.out.println("\nhashset_string contains 'JAVA' ");
		System.out.println("\n----------------------------------------------------");
		System.out.println("\nlinkedlist_string elements ");
		begin_string=linkedlist_string.iterator();
		while(begin_string.hasNext()){
			System.out.printf("%s ",begin_string.next());
		}
		try{
			check=linkedlist_string.element();
			System.out.printf("\nlinkedlist_string head element is %s \n",check);

		}
		catch(Exception e){
			System.out.println("Queue is empty!");
		}
		try{
			check=linkedlist_string.poll();
		}
		catch(Exception e){
			System.out.println("Queue is empty!");
		}
		begin_string=linkedlist_string.iterator();
		while(begin_string.hasNext()){
			System.out.printf("%s ",begin_string.next());
		}
		System.out.println("linkedlist_string after delete head of linkedlist_string");
		linkedlist_string.clear();
		control=linkedlist_string.isEmpty();
		if(control==true) System.out.println("\nlinkedlist_string is empty ");
	}
}