public class LinkedList<E> implements List<E>,Queue<E>
{
	private E[] LinkedListArray;
	private int size;
	public LinkedList(){
		size=0;
	}
	private void setSize(int _size){
		size=_size;
	}
	public int size_function(){//size function
		return size;
	}
	public iterator<E> iterator(){
		iterator<E> iterator1=new iterator<E>(LinkedListArray);//create new iterator same referance array with linkedlist array
		return iterator1;
	}
	public void add(E e){
		int k=0;
		if(isEmpty()){
			setSize(size+1);
			E[] temp=(E[])new Object[size];
			temp[0]=e;
			LinkedListArray=temp;//same referance
		}
		else{
			setSize(size+1);
			E[] temp=(E[])new Object[size];
			for(int i=0;i<LinkedListArray.length;i++){
				temp[k]=LinkedListArray[i];
				k++;
			}
			temp[size-1]=e;
			LinkedListArray=temp;
		}
	}
	public void adall(Collection<E> c){
		iterator<E> begin=c.iterator();//to reach c array easily using iterator
		while(begin.hasNext()){
			add(begin.next());
		}
	}
	public void clear(){
		LinkedListArray=null;
		setSize(0);
	}
	public boolean contains(E e){//check contains or not 
		boolean control=false;
		if(isEmpty()){
			return control;
		}
		else{
			for (int i=0;i<size;i++){
				if(LinkedListArray[i]==e){
					control=true;
					break;
				}
			}
		}
		return control;
	}
	public boolean containsAll(Collection<E> c){//check contains or not whole c array
		boolean control=true,control1=true;
		iterator<E> begin=c.iterator();
		while(begin.hasNext()){
			control=contains(begin.next());
			if(control==false) control1=false;
		}
		return control1;
	}
	public boolean isEmpty(){
		if(size==0) return true;
		else{return false;}
	}
	public void remove(E e){
		int k=0;
		while(contains(e)){//it can be more than one with same number or string
			if(contains(e)==true){
				setSize(size-1);
				E[] temp=(E[])new Object[size];
				for(int i=0;i<LinkedListArray.length;i++){
					if(LinkedListArray[i]!=e){
						temp[k]=LinkedListArray[i];
						k++;
					}
				}
				LinkedListArray=temp;
			}
		}
	}
	public void removeAll(Collection<E> c){//remove all c array from arraylist
		iterator<E> begin=c.iterator();
		while(begin.hasNext()){
			remove(begin.next());
		}
	}
	public void retainAll(Collection<E> c){
		iterator<E> begin=c.iterator();
		while(begin.hasNext()){
			if(!contains(begin.next())) c.remove(begin.next());
		}
	}
	public E element() throws empty_queue//return head of linkedlist
	{
		if(isEmpty()) throw new empty_queue();
		return LinkedListArray[0];
	}
	public void offer(E e){
		add(e);
	}
	public E poll()throws empty_queue//return head of linkedlist and remove it
	{
		if(isEmpty()) throw new empty_queue();
		E head=LinkedListArray[0];
		remove(LinkedListArray[0]);
		return head;
	}
}
