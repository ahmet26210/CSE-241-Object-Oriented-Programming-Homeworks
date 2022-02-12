public class ArrayList<E> implements List<E>
{
	private E[] ArrayListArray;
	private int size;
	public ArrayList(){
		size=0;
	}
	private void setSize(int _size){
		size=_size;
	}
	public int size_function(){
		return size;
	}
	public iterator<E> iterator(){
		iterator<E> iterator1=new iterator<E>(ArrayListArray);//create new iterator same referance array with arraylist array
		return iterator1;
	}
	public void add(E e){
		int k=0;
		if(isEmpty()){
			setSize(size+1);
			E[] temp=(E[])new Object[size];
			temp[0]=e;
			ArrayListArray=temp;
		}
		else{
			setSize(size+1);
			E[] temp=(E[])new Object[size];
			for(int i=0;i<ArrayListArray.length;i++){
				temp[k]=ArrayListArray[i];
				k++;
			}
			temp[size-1]=e;
			ArrayListArray=temp;
		}
	}
	public void adall(Collection<E> c){
		iterator<E> begin=c.iterator();//to reach c array easily using iterator
		while(begin.hasNext()){
			add(begin.next());
		}
	}
	public void clear(){
		ArrayListArray=null;
		setSize(0);
	}
	public boolean contains(E e){
		boolean control=false;
		if(isEmpty()){
			return control;
		}
		else{
			for (int i=0;i<size;i++){
				if(ArrayListArray[i]==e){
					control=true;
					break;
				}
			}
		}
		return control;
	}
	public boolean containsAll(Collection<E> c){
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
		while(contains(e)){
			if(contains(e)==true){
				setSize(size_function()-1);
				E[] temp=(E[])new Object[size];
				for(int i=0;i<ArrayListArray.length;i++){
					if(ArrayListArray[i]!=e){
						temp[k]=ArrayListArray[i];
						k++;
					}
				}
				ArrayListArray=temp;
			}
		}
	}
	public void removeAll(Collection<E> c){
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
}