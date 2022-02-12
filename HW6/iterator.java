public class iterator<E>
{
	private E array[];
	private E element;
	private int i;
	public iterator(E[] arr){
		array=arr;
		i=0;
	}
	public boolean hasNext(){
		return i<array.length;
	}
	public E next(){
		element=array[i];
		i++;
		return element;
	}
	public void remove(){//remove one by one
		int k=0;
		E[] newarray=(E[])new Object[array.length-1];//upcasting
		for (int l=0;l<newarray.length;l++){
			if(array[l]!=element){
				newarray[k]=array[l];
				k++;
			}
		}
		array=newarray;
	}
}
