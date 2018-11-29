CC			= gcc
CFLAGS		= -Wall
LDFALGS		=
OBJFILES	= server.o
TARGET		= server

all:	$(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFALGS)

clean:
	rm -f $(OBJFILES) $(TARGET)