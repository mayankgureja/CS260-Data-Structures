CC = g++
CFLAGS = 

Q4_Child_Siblings : Test_Tree.o Tree_Left_Child_Right_Siblings.o
	$(CC) $(CFLAGS) -o $@ -DChild_Siblings $^
	
Q4_List_Of_Children : Test_Tree.o Tree_List_Of_Children.o
	$(CC) $(CFLAGS) -o $@ -DList_Children $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<
