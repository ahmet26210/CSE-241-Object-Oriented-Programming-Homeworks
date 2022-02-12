JFLAGS = -g
JC = javac
.SUFFIXES: .java .class

	
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
    Collection.java \
    iterator.java \
    Set.java \
    List.java \
    Queue.java \
    HashSet.java \
    ArrayList.java \
    LinkedList.java \
    main.java \

default: classes

run: classes
	java Main

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
