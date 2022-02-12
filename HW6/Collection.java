public interface Collection<E>
{
	public iterator<E> iterator();
	public void add(E e);
	public void adall(Collection<E> c);
	public void clear();
	public boolean contains(E e);
	public boolean containsAll(Collection<E> c);
	public boolean isEmpty();
	public void remove(E e);
	public void removeAll(Collection<E> c);
	public void retainAll(Collection<E> c);
	public int size_function();
}