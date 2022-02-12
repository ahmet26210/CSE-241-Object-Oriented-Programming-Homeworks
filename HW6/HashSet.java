public class HashSet<E> implements Set<E>
{
	private E[] HashSetArray;
	private int size;
	public HashSet(){
		size=0;
	}
	private void setSize(int _size){
		size=_size;
	}
	public int size_function(){
		return size;
	}
	public iterator<E> iterator(){
		iterator<E> iterator1=new iterator<E>(HashSetArray);//create new iterator same referance array with hashset array
		return iterator1;
	}
	public void add(E e){
		int k=0;
		if(isEmpty()){
			setSize(size+1);
			E[] temp=(E[])new Object[size];
			temp[0]=e;
			HashSetArray=temp;
		}
		else if(contains(e)==false){//to avoid add same number or string more than one 
			setSize(size+1);
			E[] temp=(E[])new Object[size];
			for(int i=0;i<HashSetArray.length;i++){
				temp[k]=HashSetArray[i];
				k++;
			}
			temp[size-1]=e;
			HashSetArray=temp;
		}
	}
	public void adall(Collection<E> c){
		iterator<E> begin=c.iterator();//to reach c array easily using iterator
		while(begin.hasNext()){
			add(begin.next());
		}
	}
	public void clear(){
		HashSetArray=null;
		setSize(0);
	}
	public boolean contains(E e){
		boolean control=false;
		if(isEmpty()){
			return control;
		}
		else{
			for (int i=0;i<size;i++){
				if(HashSetArray[i]==e){
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
				setSize(size-1);
				E[] temp=(E[])new Object[size];
				for(int i=0;i<HashSetArray.length;i++){
					if(HashSetArray[i]!=e){
						temp[k]=HashSetArray[i];
						k++;
					}
				}
				HashSetArray=temp;
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